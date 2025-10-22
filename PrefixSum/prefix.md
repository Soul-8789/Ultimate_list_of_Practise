# 🎯 Core Idea
Prefix sums and difference arrays are powerful techniques for efficiently handling range queries and range updates. They can be extended from 1D to 2D to solve many matrix-related problems.

## 🟩 1D Prefix Sum
**Formula:**

S[i] = a[1] + a[2] + ... + a[i]  
sum(l, r) = S[r] - S[l - 1]  

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
```python
class PrefixSum2D:
    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), len(matrix[0])
        self.prefix = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                self.prefix[i][j] = (
                    self.prefix[i - 1][j]
                    + self.prefix[i][j - 1]
                    - self.prefix[i - 1][j - 1]
                    + matrix[i - 1][j - 1]
                )
    def query(self, r1, c1, r2, c2):
        return (
            self.prefix[r2 + 1][c2 + 1]
            - self.prefix[r1][c2 + 1]
            - self.prefix[r2 + 1][c1]
            + self.prefix[r1][c1]
        )
```

| ID   | Problem                                             | Technique                          |
|------|-----------------------------------------------------|-------------------------------------|
| 304  | Range Sum Query 2D - Immutable                      | 2D prefix sum template              |
| 1314 | Matrix Block Sum                                   | Querying block sums                |
| 1277 | Count Square Submatrices with All Ones             | Prefix sum + DP                    |

## 🟧 2D Difference Array
**With padding at the end (index not affected):**
```python
class Diff2D:
    def __init__(self, m, n):
        self.m, self.n = m, n
        self.diff = [[0] * (n + 1) for _ in range(m + 1)]

    def update(self, r1, c1, r2, c2, val):
        self.diff[r1][c1] += val
        self.diff[r2 + 1][c1] -= val
        self.diff[r1][c2 + 1] -= val
        self.diff[r2 + 1][c2 + 1] += val
    
    def apply(self):
        res = [[0] * self.n for _ in range(self.m)]
        for i in range(self.m):
            for j in range(self.n):
                res[i][j] = self.diff[i][j]
                if i > 0: res[i][j] += self.diff[i - 1][j]
                if j > 0: res[i][j] += self.diff[i][j - 1]
                if i > 0 and j > 0: res[i][j] -= self.diff[i - 1][j - 1]
        return res
```

## 🧠 Key Takeaways
- Prefix sums simplify range-sum queries to O(1) after O(n) preprocessing.
- Difference arrays make range updates efficient with O(1) per update.
- 2D extensions follow the same logic but require careful handling of padding.