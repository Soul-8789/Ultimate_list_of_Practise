# 🎯 Core Idea
Prefix sums and difference arrays are powerful techniques for efficiently handling range queries and range updates. They can be extended from 1D to 2D to solve many matrix-related problems.

## ✅ Prefix Sum Problem Types

**1D Range Sum Query**
**2D Range Sum Query (Matrix)**
**Subarray Sum Equals K (Exact Sum Match)**
**Maximum Subarray Sum (Kadane’s Algorithm)**
**Count of Subarrays with Given Sum**
**Difference Array (for range update queries)**


## 🟩 1D Prefix Sum
**Formula:**



S[i] = a[1] + a[2] + ... + a[i]  
sum(l, r) = S[r] - S[l - 1]  

```cpp
   class PrefixSum1D {
    int n;
    vector<int> prefix;

    public:
        // Constructor: build prefix sum from input array
        PrefixSum1D(const vector<int>& nums) {
            n = nums.size();
            prefix.assign(n + 1, 0); // prefix[0] = 0

            for (int i = 0; i < n; ++i) {
                prefix[i + 1] = prefix[i] + nums[i];
            }
        }

        // Query sum of range [l, r] inclusive
        int query(int l, int r) {
            return prefix[r + 1] - prefix[l];
        }
    };


```

| ID  | Problem                                             | Technique                          |
|-----|-----------------------------------------------------|------------------------------------|
| 1480 | Running Sum of 1D Array                             | Basic prefix sum                   |
| 1413 | Minimum Value to Get Positive Step by Step Sum     | Minimum prefix sum                  |
| 1732 | Find the Highest Altitude                            | Max prefix sum                     |
| 2090 | K Radius Subarray Averages                           | Sliding window + prefix sum       |
| 2270 | Number of Ways to Split Array                       | Partition using prefix sum         |
| 724  | Find Pivot Index                                    | Left-right prefix sum              |
| 303  | Range Sum Query - Immutable                          | Query with prefix sum              |
| 560  | Subarray Sum Equals K                                | Hashmap + prefix sum               |
| 523  | Continuous Subarray Sum                              | Mod k + hashmap                    |
| 974  | Subarray Sums Divisible by K                         | Mod k classification               |
| 930  | Binary Subarrays With Sum                            | Fixed-sum subarrays                |
| 325  | Maximum Size Subarray Sum Equals k                    | Hashmap storing prefix index       |
| 238  | Product of Array Except Self                         | Prefix product variant             |

## 🟨 1D Difference Array
**Formula:**  
Update [l, r] by c:  
B[l] += c  
B[r + 1] -= c  

```cpp


    class Diff1D {
        int n;
        vector<int> diff;

    public:
        // Constructor: Initialize a difference array of size n
        Diff1D(int n) : n(n) {
            diff.assign(n + 1, 0);  // one extra space for easier range handling
        }

        // Add 'val' to the range [l, r] (inclusive)
        void update(int l, int r, int val) {
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }

        // Apply updates and return the final array
        vector<int> apply() {
            vector<int> result(n, 0);
            result[0] = diff[0];
            for (int i = 1; i < n; ++i) {
                result[i] = result[i - 1] + diff[i];
            }
            return result;
        }
    };


```

| ID   | Problem                                             | Technique                          |
|------|-----------------------------------------------------|-------------------------------------|
| 370  | Range Addition                                     | Basic difference array              |
| 1094 | Car Pooling                                       | Interval passenger changes         |
| 1109 | Corporate Flight Bookings                          | Range addition optimization         |
| 1589 | Maximum Sum Obtained of Any Permutation            | Contribution counting with difference array |
| 598  | Range Addition II                                  | Simulate 2D difference              |
| 731  | My Calendar II                                    | Overlap counting with difference    |
| 732  | My Calendar III                                   | Maximum overlaps                     |
| 798  | Smallest Rotation with Highest Score              | Circular difference counting         |

## 🟦 2D Prefix Sum
**With padding at the top and left:**
```cpp


    class PrefixSum2D {
        int m, n;
        vector<vector<int>> prefix;

    public:
        // Constructor: Build prefix sum matrix
        PrefixSum2D(const vector<vector<int>>& matrix) {
            m = matrix.size();
            n = matrix[0].size();
            prefix.assign(m + 1, vector<int>(n + 1, 0));

            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    prefix[i][j] = prefix[i - 1][j] 
                                + prefix[i][j - 1]
                                - prefix[i - 1][j - 1]
                                + matrix[i - 1][j - 1];
                }
            }
        }

        // Query sum of submatrix [(r1, c1), (r2, c2)]
        int query(int r1, int c1, int r2, int c2) {
            return prefix[r2 + 1][c2 + 1]
                - prefix[r1][c2 + 1]
                - prefix[r2 + 1][c1]
                + prefix[r1][c1];
        }
    };

```

| ID   | Problem                                             | Technique                          |
|------|-----------------------------------------------------|-------------------------------------|
| 304  | Range Sum Query 2D - Immutable                      | 2D prefix sum template              |
| 1314 | Matrix Block Sum                                   | Querying block sums                |
| 1277 | Count Square Submatrices with All Ones             | Prefix sum + DP                    |

## 🟧 2D Difference Array
**With padding at the end (index not affected):**
```cpp


    class Diff2D {
        int m, n;
        vector<vector<int>> diff;

    public:
        // Constructor to initialize the diff matrix
        Diff2D(int m, int n) : m(m), n(n) {
            diff.assign(m + 1, vector<int>(n + 1, 0));
        }

        // Apply 'val' to submatrix [(r1, c1), (r2, c2)]
        void update(int r1, int c1, int r2, int c2, int val) {
            diff[r1][c1] += val;
            if (r2 + 1 < m + 1) diff[r2 + 1][c1] -= val;
            if (c2 + 1 < n + 1) diff[r1][c2 + 1] -= val;
            if (r2 + 1 < m + 1 && c2 + 1 < n + 1) diff[r2 + 1][c2 + 1] += val;
        }

        // Apply the difference matrix to generate the final result
        vector<vector<int>> apply() {
            vector<vector<int>> res(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    res[i][j] = diff[i][j];
                    if (i > 0) res[i][j] += res[i - 1][j];
                    if (j > 0) res[i][j] += res[i][j - 1];
                    if (i > 0 && j > 0) res[i][j] -= res[i - 1][j - 1];
                }
            }
            return res;
        }
    };

```
# Prefix Sum + Hashmap Approach

We apply this approach in problems related to Subarrays, problems where we are asked to:

- Count the subarrays with some condition
- Find Maximum Length Subarray with some condition
- Check if subarray exists with some given condition

Mainly the problems dealing with Subarray sum.

## Approach

This approach works on the following principle:

If the prefix sum up to `i`th index is `X`, and the prefix sum up to `j`th index is `Y` and it is found that `Y = X + k`, then the required subarray is found with `i` as start index and `j` as end index.

To store the index value and the sum of elements up to that index, a hashmap can be used.

### Why we need this approach of Hashmap + Prefix Sum?

So basically for subarray related problems, the Brute Force method takes `O(n^2)` time to process each subarray + extra time in processing. But with this approach, only `O(n)` time is taken.

Now you might wonder what is stopping you from using Sliding window approach for such problems. 

Sliding window is only applicable when we know for sure if the prefix sum is an increasing or decreasing function (i.e., monotonous in nature).

So for problems where negative input is given, this approach of Prefix Sum + Hashmap is the best way to solve such problems.

## Problems to Solve Using Prefix Sum + Hashmap Pattern

1. **Count Subarrays with some given condition**

   **Data Structures needed:**

   - Integer Variable for cumulative sum
   - Unordered Map
   - Map Initialisation: `mp[0] = 1`

   Let's solve 3 problems using Prefix Sum + Hashmap pattern.

   ✏️ **Problem 1.1** --> 560. Count Subarray sum equals `k`

   **Condition:** Sum of subarray equals `k`

   **Negative values ALLOWED in Input**
   # Code

```cpp
/*Given an array of integers arr and an integer k,
return the total number of subarrays whose sum equals to k.*/
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int it : arr) {
            sum += it;
            count += mp[sum - k];
            mp[sum]++; 
        }
        return count;
    }
};
```

## Problem 1.2 --> 974. Count Subarray Sums Divisible by K

**Condition**: Subarrays that have a sum divisible by k.  
**Negative values ALLOWED in Input**

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i : nums) {
            sum = (sum + i) % k;
            if (sum < 0)
                sum = sum + k; // ADD k if sum negative to make it positive
            count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};
```

## Problem 1.3 --> 930. Count Binary Subarrays with given SUM

**Condition**: (Binary) Subarrays with given Sum  

Negative values are not allowed in input. Because of this reason, we can also solve this problem using Sliding window too.  

Sliding window is only applicable when we know for sure if the prefix sum is an increasing or decreasing function (i.e. Monotonous in nature)

```cpp
/*Given a binary array nums and an integer goal, 
return the number of non-empty subarrays with a sum goal.*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int it : nums) {
            sum += it; 
            count += mp[sum - goal];
            mp[sum]++; 
        }
        return count;
    }
};
```

## 2. Maximum length Subarray with given condition

**Data Structures needed**:
- Integer Variable for cumulative sum
- Unordered Map  
- Map Initialisation: `mp[0] = -1` Here we are dealing with index that's why we initialize it to -1

### Problem 2.1 --> 525. Contiguous Array

**Condition**: Binary Subarray with an equal number of 0 and 1  

```cpp
/*Given a binary array nums, return the maximum length
of a subarray with an equal number of 0 and 1*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int one = 0, zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zero++;
            else one++;
            int diff = zero - one;
            if (mp.count(diff))
                ans = max(ans, i - mp[diff]);
            else
                mp[diff] = i;
        } 
        return ans;
    }
};
```

### Problem 2.2 --> 325. Maximum Size Subarray Sum Equals k (Premium)

**Problem Statement**: Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

**Condition**: subarray that sums to k  

Negative values ALLOWED in Input.
# Code

```cpp
// arguments of this code might differ
// from leetcode version of this problem but
// the idea remains same
int lenOfLongSubarr(int A[], int N, int K) { 
    int pre_sum = 0; // prefix sum
    int res = 0;
    unordered_map<int, int> mp; {pref sum, index}
    mp[0] = -1; 
    for(int i = 0; i < N; i++) {
        pre_sum += A[i];
        if(mp.find(pre_sum - K) != mp.end()) // pre_sum - K found in hash
            res = max(res, i - mp[pre_sum - K]);
        if(mp.find(pre_sum) == mp.end()) // Check if prefix_sum exists in hash
            mp[pre_sum] = i;
    }
    return res;
}
```

✏️ **Problem 2.3** --> **1658. Minimum Operations to Reduce X to Zero**  
**Problem Reduced to Above problem of Maximum size subarray sum**

# Code

```cpp
/* given an integer array nums and an integer x.
In one operation, you can either remove the leftmost
or the rightmost element from the array nums
and subtract its value from x.
Return the minimum number of operations
to reduce x to exactly 0 if it is possible, otherwise, return -1. */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {// start 
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int rem = total - x;
        if (rem == 0)
            return nums.size();

        int length = maxSubArrayLen(rem, nums);

        if (length == 0)
            return -1;
        return n - length;
    }

    int maxSubArrayLen(int k, vector<int>& A) {// Code for Maximum size subarray given sum
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp; 
        mp[0] = -1;

        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (mp.find(sum - k) != mp.end())
                res = max(res, i - mp[sum - k]);

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return res;
    }
};
```

3. Check if a subarray exists with given condition  
✏️ **Problem 3.1** : **523. Continuous Subarray Sum**  
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

**Conditions:**  
- Length of subarray is at least two  
- The sum of the elements of the subarray is a multiple of k  

# Code

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        // sum of the elements of the subarray is a multiple of k
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end()){
                if(i-mp[sum%k]>=2)
                    return true;
            }
            else
                mp[sum%k]=i;
        }
        return false;
    }
};
```



# 1D Prefix Sums

## Warm-up:
- [Running Sum of 1D Array](https://leetcode.com/problems/running-sum-of-1d-array/)
- [Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)
- [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/)
- [Codeforces Problem A](https://codeforces.com/contest/327/problem/A)

## Practice Questions:
- [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
- [Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array/)
- [Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
- [Number of Sub-arrays with Odd Sum](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)
- [Contiguous Array](https://leetcode.com/problems/contiguous-array/)

## Extra Practice Questions: [Not mandatory]
- [Static Range Sum](https://judge.yosupo.jp/problem/static_range_sum)
- [USACO Problem 572](http://www.usaco.org/index.php?page=viewproblem2&cpid=572)
- [USACO Problem 595](http://usaco.org/index.php?page=viewproblem2&cpid=595)
- [SPOJ Problem RANGESUM](https://www.spoj.com/problems/RANGESUM/en/)

## Prefix Sum + Hashmap
- [CSES Problem Task 1660](https://cses.fi/problemset/task/1660/)
- [CSES Problem Task 1661](https://cses.fi/problemset/task/1661/)
- [Codeforces Problem C (Extension of Subarray sum=0)](https://codeforces.com/contest/1398/problem/C)
- [Find the Longest Substring Containing Vowels in Even Counts](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)

## 🧠 Key Takeaways
- Prefix sums simplify range-sum queries to O(1) after O(n) preprocessing.
- Difference arrays make range updates efficient with O(1) per update.
- 2D extensions follow the same logic but require careful handling of padding.
- [text](https://leetcode.com/discuss/post/2719912/prefix-sum-study-summary-by-sunyingbao-jozu/)