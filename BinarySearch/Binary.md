# 🚀 Master Binary Search with ONE Template (and Zero Headaches)

## 🎯 The Core Idea: Boolean Monotonicity
Binary Search is everywhere on LeetCode — but many people still get stuck in its variations: lower bound, upper bound, search on arrays, search on solution space…

The truth is, almost every binary search problem can be reduced to one universal pattern.

Forget about “sorted arrays” — what binary search truly needs is boolean monotonicity:

```
[False, False, ..., False, False | True, True, ..., True]
```
In this boolean sequence, all False values lie to the left, and all True values lie to the right.

Our goal: Find the first index where the condition becomes True.

## 📝 Universal Binary Search Template
```cpp
#include <vector>
#include <algorithm>
using namespace std;

// Universal binary‐search: returns the first value in [left, right) for which check(mid) == true.
// Requires that check(mid) is monotonic: false, false, …, true, true, …
template<typename F>
long long binarySearch(long long left, long long right, F check) {
    // note: search space is [left, right), i.e., right is exclusive
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

```

## Key idea
Binary search always returns the position of the first True.  
Only two things matter:
- What makes `check(mid)` return True
- How you choose left and right initially

## Right Boundary Explanation
🧐 When to add +1 to the right boundary?
- Most of the time, don’t.
- Add +1 only when:
  1. The search might end up with an all-False result (e.g., searchInsert, candies).
  2. You invert `check` (so True becomes False), to avoid missing the last valid element.

## “All False” Handling
If there’s no True at all:
- For array problems → post-check left after the loop:
  
  ```python
  return left if left < n and nums[left] == target else -1
  ```
- For solution-space problems → usually handle at the start:

  ```python
  if impossible_condition: return -1
  ```

## ✅ Example Problems with the Universal Template
🔹 1. LC704 - Binary Search  
Pattern: `[F...F | T...]` where F means `nums[i] < target`, and T means `nums[i] >= target`.  
Goal: Find the first index where `nums[i] >= target`. If that index actually equals target, return it; otherwise return -1.  
Why `right = n`? Because target might be larger than every element, making the entire check array False.

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        auto check = [&](long long i) {
            return nums[i] >= target;
        };
        long long left = 0, right = n;  // right = n (exclusive)
        long long ans = binarySearch(left, right, check);
        if (ans < n && nums[ans] == target) return (int)ans;
        return -1;
    }
};

```

## LC35 – Search Insert Position
**Pattern:** Exactly the same as LC704.  
**Goal:** The index where target should be inserted to keep the array sorted.  
**Why right = n?** The insert position could be at the end of the array when target is larger than all elements.

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        auto check = [&](long long i) {
            return nums[i] >= target;
        };
        long long ans = binarySearch(0, n, check);
        return (int)ans;
    }
};

```

## LC74 – Search a 2D Matrix
**Pattern:** Flatten the matrix into a sorted 1D array, then apply the same binary search as LC704.  
**Goal:** Find the first element >= target and check if it equals target.  
**Why right = m * n?** Because the virtual flattened array has m * n elements, and the search may move just past the last index when all values are smaller than target.

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        auto val = [&](long long idx) {
            return matrix[idx / n][idx % n];
        };
        auto check = [&](long long i) {
            return val(i) >= target;
        };
        long long left = 0, right = (long long)m * n;  // virtual flattening
        long long ans = binarySearch(left, right, check);
        if (ans < (long long)m * n && val(ans) == target) return true;
        return false;
    }
};

```

## LC374 – Guess Number Higher or Lower
**Pattern:** [F...F | T...] where check(mid) is `guess(mid) <= 0` (True means mid is at or above the target).  
**Why no +1?** The problem guarantees the picked number exists, so the array cannot be “all False”.

```cpp
// Forward declaration of the guess API.
// int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (guess(mid) <= 0) {  // means mid is >= target
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

```

## LC875 – Koko Eating Bananas
**Pattern:** [F...F | T...] where F means speed k is too slow, and T means speed k can finish on time.  
**Goal:** Find the smallest k that works.  
**Why right = max(piles)?** Koko can always finish if she eats at the max pile size per hour, so the solution is guaranteed in [1, max(piles)].

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, long long h) {
        auto check = [&](long long k) {
            long long hours = 0;
            for (int p : piles) {
                hours += (p + k - 1) / k;  // equivalent to ceil(p / k)
                if (hours > h) return false;
            }
            return hours <= h;
        };
        long long left = 1;
        long long right = *max_element(piles.begin(), piles.end());
        long long ans = binarySearch(left, right + 1, [&](long long k) {
            return check(k);
        });
        return (int)ans;
    }
};

```

## LC2300 – Successful Pairs of Spells and Potions
**Pattern:** For each spell, search in potions [F...F | T...] where F means spell * potion < success and T means it’s enough.  
**Goal:** Find the first potion that meets the success threshold.
# Why right = n?

If no potion meets the threshold, the search moves to `n` (past the last index), and we return 0 pairs.

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();

        auto binary_search = [&](long long x) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                // Use long long to avoid overflow
                if ((long long)potions[mid] * x >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        vector<int> result;
        result.reserve(spells.size());
        for (int x : spells) {
            result.push_back(n - binary_search(x));
        }
        return result;
    }
};

```

## 🔹 7. LC1870 – Minimum Speed to Arrive on Time

**Pattern:** `[F...F | T...]` where **F** means the train cannot arrive on time with the given speed, and **T** means it can.

**Special Handling:** If the number of trips exceeds `ceil(hour)`, arrival is impossible, so return `-1` early.

**Search Space:** `[1, 10^7]` because the max possible speed is capped.
# Solution Code Examples

```cpp
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        // If the number of segments is more than the ceiling of hour, it's impossible
        if (n > ceil(hour)) return -1;

        auto check = [&](int speed) {
            double time = 0.0;
            for (int i = 0; i < n - 1; ++i) {
                // time for all but the last segment rounded up
                time += ceil((double)dist[i] / speed);
            }
            // last segment time without rounding up
            time += (double)dist[n - 1] / speed;
            return time <= hour;
        };

        int left = 1, right = 10000000;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


```

## LC1283 – Find the Smallest Divisor Given a Threshold

Pattern: `F...F | T...` where F means the sum exceeds the threshold, and T means it is within limits.  
Search Space: `[1, max(nums)]` because dividing by a value larger than `max(nums)` is unnecessary.

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto check = [&](long long x) {
            long long sum = 0;
            for (int num : nums) {
                sum += (num + x - 1) / x;
                if (sum > threshold) return false;
            }
            return sum <= threshold;
        };
        long long left = 1;
        long long right = *max_element(nums.begin(), nums.end());
        long long ans = binarySearch(left, right + 1, [&](long long x) {
            return check(x);
        });
        return (int)ans;
    }
};

```

## LC2251 – Number of Flowers in Full Bloom

Pattern: For each person at time `p`, we need `flowers blooming = flowers started ≤ p − flowers ended ≤ p`.  
Key:
- Sort all start times.
- Sort all end times as `end + 1` so a flower ending on day `e` stops contributing after `e`.
- Use binary search to count how many starts/ends are ≤ `p`.
- `active = started − ended` for each `p`.

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int binarySearch(const vector<int>& arr, int t) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > t) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for (const auto& f : flowers) {
            start.push_back(f[0]);
            end.push_back(f[1] + 1);  // shift end by +1 for exclusive range
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> res;
        for (int p : people) {
            int bloomed = binarySearch(start, p);
            int ended = binarySearch(end, p);
            res.push_back(bloomed - ended);
        }

        return res;
    }
};


```

## LC1231 – Divide Chocolate

We want to split the chocolate into `k + 1` pieces so that the minimum sweetness is as large as possible.  
This is a binary search over possible sweetness values.
- If `x` is small, it’s easy to cut enough pieces.
- If `x` is large, it might be impossible to make enough pieces.  
Thus, the pattern is naturally `[achievable, achievable, ..., unachievable]`.

Instead of writing `check(x)` to return whether `x` is achievable, this solution defines it in the opposite way:

`check(x) → True` means `x` is NOT achievable.  
Because the boolean is inverted, binary search finds the first failing `x`, so the final answer must be `left - 1` (the last successful value).
# Class Definitions for Solutions


```cpp
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(int x, const vector<int>& sweetness, int k) {
        int curr = 0, count = 0;
        for (int s : sweetness) {
            curr += s;
            if (curr >= x) {
                count++;
                curr = 0;
            }
        }
        return count < k + 1;  // True means x is too large (not enough pieces)
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0) / (k + 1) + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, sweetness, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left - 1;  // Last successful (valid) value
    }
};

```

## LC410 - Split Array Largest Sum


> Pattern: [F...F | T...] where F means x is too small to split into k subarrays, and T means it’s feasible.

### Check Function
- `check(x)`: Greedy accumulate:
  - Add numbers until exceeding x, then start a new subarray.
  - Count how many subarrays are formed.
  - Return True if count <= k.

### Search Space
- [max(nums), sum(nums)] because the largest subarray must at least contain the max element.

```cpp
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(int x, const vector<int>& nums, int k) {
        int count = 0, curr = 0;
        for (int num : nums) {
            if (curr + num > x) {
                count++;
                curr = 0;
            }
            curr += num;
        }
        return count + 1 <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, nums, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

```

## LC2187 - Minimum Time to Complete Trips

> Pattern: [F…F | T…] where F means x is too small to finish totalTrips, and T means it’s feasible.

### Check Function
- `check(x)`:
  - For each bus with time t, add x // t trips.
  - Return True if total trips ≥ totalTrips.

### Search Space
- [min(time), totalTrips * min(time)] because the minimum time is at least the fastest bus time, and at most all trips done by the fastest bus.

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(long long x, const vector<int>& time, int totalTrips) {
        long long trips = 0;
        for (int t : time) {
            trips += x / t;
            if (trips >= totalTrips)  // early stop if possible
                return true;
        }
        return trips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int minTime = *min_element(time.begin(), time.end());
        long long left = minTime, right = (long long)totalTrips * minTime;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid, time, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

```

## LC2226 - Maximum Candies Allocated to K Children

> Pattern: The original feasibility works like this:
- If each child needs fewer candies (x small), it’s easy to satisfy → feasible.
- If each child needs more candies (x large), it may fail → not feasible.
- Thus, the natural boolean array is [T...T | F...F].  
To fit our universal binary search (which searches for the first True), we invert the logic:

- Let `check(x)` return True when x is not feasible.
- Now the array looks like [F...F | T...T], and the binary search returns the first non-feasible value.

**Note:**

- We search in [1, max_possible + 1) so that even if all values are feasible, the algorithm terminates correctly.
- After finding the first non-feasible value, the largest feasible value is left - 1.

```cpp
#include <vector>
#include <numeric>  // for accumulate

using namespace std;

class Solution {
public:
    bool check(const vector<int>& candies, int k, int x) {
        long long count = 0;
        for (int candy : candies) {
            count += candy / x;
            if (count >= k)  // early stop
                return false;
        }
        return count < k;
    }

    int maximumCandies(vector<int>& candies, int k) {
        long long total = accumulate(candies.begin(), candies.end(), 0LL);
        if (total < k) return 0;

        int left = 1;
        int right = (int)(total / k) + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(candies, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};

```

🔹 14. LC1482 – Minimum Number of Days to Make m Bouquets  
**Pattern:** [F...F | T...T] where  
- F means on day x we cannot make m bouquets,  
- T means on day x we can make at least m bouquets.  

`check(x):`  
For a given day x, iterate through the flowers:  
- If a flower hasn’t bloomed (bloomDay > x), reset the current streak.  
- Otherwise, count consecutive bloomed flowers; whenever we collect k, we form one bouquet and reset the streak.  
- Return True if the total bouquets formed ≥ m.  

```cpp

#include <vector>
#include <algorithm>  // for min_element, max_element

using namespace std;

class Solution {
public:
    bool check(const vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, curr = 0;
        for (int num : bloomDay) {
            if (num > day) {
                curr = 0;
            } else {
                curr++;
                if (curr == k) {
                    count++;
                    curr = 0;
                }
            }
        }
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((int)bloomDay.size() < m * k) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

```

🎉 **Conclusion**  
Binary Search is not about arrays being “sorted” — it’s about finding the first True in a boolean monotonic sequence.

Once you:  
1. Define a search space [min_val, max_val (+1)],  
2. Design a `check(mid)` that produces [False...False | True...True], and  
3. Apply the universal template to locate the first True,  

you can solve almost every binary search problem on LeetCode — from the simplest array lookup to the hardest “search on solution space” challenges.

✨ Next time you face a binary search question, just ask yourself:  

What is my `check(mid)` and how do I make the problem look like [F...F | T...T]?  

Master this pattern, and every binary search problem becomes just another plug-and-play puzzle. 🚀