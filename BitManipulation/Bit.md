# ⚡ Bit Manipulation Patterns for Coding Interviews

## 🎯 Core Idea
Bit manipulation is an elegant and efficient technique to solve many algorithmic problems by directly operating on binary bits.

With only a few operators—`&`, `|`, `^`, `~`, `<<`, `>>`—you can achieve complex logic like clearing bits, toggling bits, compressing states, or even implementing fast algorithms like modular exponentiation.

## 🧩 Key Formulas & Tricks
| Operation                | Code           | Use Case                             |
|--------------------------|----------------|--------------------------------------|
| Get k-th bit            | `(n >> k) & 1` | Check if bit k is set                |
| Get lowest set bit       | `x & -x`       | Lowbit (Fenwick Tree, counting bits) |
| Remove lowest set bit    | `n & (n - 1)`  | Brian Kernighan’s trick              |
| Set bit i to 1          | `x |= (1 << i)`| Force bit i to 1                     |
| Set bit i to 0          | `x &= ~(1 << i)`| Clear bit i                          |
| Flip bit i              | `x ^= (1 << i)`| Toggle bit i                         |
| Swap two numbers         | `a ^= b; b ^= a; a ^= b` | Swap without a temporary variable |
| Check odd/even           | `x & 1`        | 1 → odd, 0 → even                    |

## 🔥 Operators Cheat Sheet
- `&` AND → 1 only if both bits are 1
- `|` OR → 1 if at least one bit is 1
- `^` XOR → 1 if bits differ → find unique numbers, toggle states
- `~` NOT → flips bits (`~a = -a-1`)
- `<<` Left Shift → multiply by 2^n
- `>>` Right Shift → divide by 2^n (implementation varies for negatives)

## ✅ Classic Techniques

### 1️⃣ XOR Magic
> Find the single number where others appear twice

```cpp
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int x : nums) {
        res ^= x;
    }
    return res;
}

```
✔️ `x ^ x = 0`, `x ^ 0 = x`  
✔️ Commutative & associative  
✔️ Applications: unique element, toggling, swapping without extra space  

### 2️⃣ Counting Bits (Brian Kernighan)
```cpp
int countBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // remove lowest set bit
        count++;
    }
    return count;
}

```
✔️ Efficient for counting 1s in binary representation.  

### 3️⃣ Bitmask for State Compression
Use an integer to represent multiple states.

```cpp
void generateSubsets(vector<int>& nums) {
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                subset.push_back(nums[i]);
            }
        }
        // Do something with subset
    }
}

```
✔️ Applications: subset enumeration, DP optimization, graph states.
# Fast Exponentiation

```cpp
long long fastPow(long long x, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}
```

✔️ Reduces complexity from O(n) to O(log n).

# LeetCode Must-Do Bit Manipulation Problems

## Basic Bit Tricks

| ID  | Problem                     | Technique                                        |
|-----|-----------------------------|--------------------------------------------------|
| 136 | Single Number               | XOR for unique number                            |
| 137 | Single Number II            | Count bits per position                          |
| 260 | Single Number III           | XOR + partition by lowest set bit                |
| 231 | Power of Two                | n & (n - 1) == 0                                 |
| 342 | Power of Four               | Check bit position + mod                          |
| 191 | Number of 1 Bits            | Count bits                                      |
| 190 | Reverse Bits                | Bit shifts + masks                               |
| 268 | Missing Number              | XOR with index                                   |
| 693 | Binary Number with Alternating Bits | (n ^ (n >> 1)) & ((n ^ (n >> 1)) + 1) == 0 |
| 389 | Find the Difference         | XOR                                              |
| 461 | Hamming Distance            | XOR then count 1’s                               |
| 1342| Number of Steps to Reduce a Number to Zero | Odd/even + bit shift                |
| 201 | Bitwise AND of Numbers Range| Common prefix                                    |
| 371 | Sum of Two Integers        | Binary addition with XOR & AND                   |
| 477 | Total Hamming Distance      | Count 1’s and 0’s per bit                        |

## String/Array + Bitmask

| ID  | Problem                     | Technique                                        |
|-----|-----------------------------|--------------------------------------------------|
| 187 | Repeated DNA Sequences      | Rolling hash + bit encoding                       |
| 318 | Maximum Product of Word Lengths | Bitmask to check character overlap |

## DP + Bitmask

| ID  | Problem                     | Technique                                        |
|-----|-----------------------------|--------------------------------------------------|
| 338 | Counting Bits               | DP with dp[i] = dp[i >> 1] + (i & 1)            |
| 78  | Subsets                     | Bitmask to generate subsets                       |

## Trie + Bitwise (Advanced)

| ID  | Problem                     | Technique                                        |
|-----|-----------------------------|--------------------------------------------------|
| 421 | Maximum XOR of Two Numbers in an Array | Trie + greedy XOR                    |

## Fast Exponentiation

| ID  | Problem                     | Technique                                        |
|-----|-----------------------------|--------------------------------------------------|
| 50  | Pow(x, n)                  | Binary exponentiation                             |
| 372 | Super Pow                   | Modular fast power                               |
| 1922| Count Good Numbers          | Modular fast power with even/odd digit handling  |

## Key Takeaways

- XOR is your go-to trick for finding unique elements and toggling bits.
- n & (n-1) is a must-know for counting bits and checking power of two.
- Bitmask makes subset enumeration and DP elegant and efficient.
- Fast exponentiation with bitwise checks reduces complexity to O(log n).