# Ultimate_list_of_Practise
best way to practise the dsa with problems 


# Tackling any 'SUBARRAY' related problems in Array

## Array
- Two Pointers
- Recursion
- Sliding Window
- Interview

Do you ever feel like array-related problems, especially involving subarrays, can feel like they have many solutions, and it’s tough to know where to start. The key is to recognize certain patterns and then identify which principle or algorithm fits best. Here’s how to approach such problems more systematically:

## Understand the Problem Clearly:

- Carefully read the problem and break it down.
- Are you asked to find a subarray with certain properties (e.g., smallest, largest sum, divisible sum)?
- Are you asked to maximize, minimize, or check for existence of some condition?
- Does the problem allow for negative numbers or only positive ones?

## Analyze the Subarray Nature:

Subarrays are contiguous parts of an array, and there are different common categories of subarray-related problems. Each category has patterns and hints towards a particular type of solution.

## Look for Common Patterns:

### a) Sliding Window (or Two Pointers) Technique:
- **When to use**: If the problem involves:
  - Finding a subarray with a fixed sum or length.
  - Finding a subarray with some condition that can be checked as you move from one end of the array to another.
- **Why it works**: This technique is efficient because it processes the array in linear time, expanding and contracting the window as needed.
- **Common in problems like**: Finding the smallest subarray with a sum greater than x, longest subarray with distinct elements, or fixed length subarrays.
- **Example**: If you’re asked to find the longest subarray with sum ≤ k, sliding window is often the way to go.

### b) Kadane’s Algorithm (Dynamic Programming):
- **When to use**: When you’re asked to find the maximum subarray sum.
- **Why it works**: It efficiently keeps track of the maximum subarray sum ending at each index. It’s optimal because you build solutions to subproblems (maximum sums ending at earlier indices) and extend them.
- **Common in problems like**: Finding the maximum subarray sum, especially when there are no specific constraints on subarray length or the values can be negative.
- **Example**: Given an array, find the maximum sum of any subarray.

### c) Prefix Sum & HashMap:
- **When to use**: If the problem involves:
  - Modulo arithmetic (as in the last problem).
  - Checking sums over subarrays (especially when the subarray can be of any size).
  - Finding subarrays with certain constraints, like sums equal to a specific value or divisible by a number.
- **Why it works**: The prefix sum allows you to break down a subarray sum into differences between two prefix sums. HashMaps are used for fast lookups of previously seen sums (helpful for problems with conditions like “sum divisible by k”).
- **Common in problems like**: Finding subarrays that sum to k, or removing a subarray to make a sum divisible by a given value.
- **Example**: “Find the smallest subarray whose sum is divisible by p” (the problem we just solved).
## d) Divide and Conquer

- **When to use:** When asked to compute maximum/minimum subarrays but over overlapping regions, or when recursion naturally divides the problem.
- **Why it works:** Divides the problem into subproblems, solving them independently, and combining results.
- **Common in problems like:** Finding the maximum sum of a subarray (can be solved using divide and conquer as well).
- **Example:** Mergesort-based solutions to find the maximum sum of a subarray, or problems like finding the number of inversions.

## e) Recursion with Memoization

- **When to use:** When the problem has overlapping subproblems, and dynamic programming can be applied.
- **Why it works:** This approach reduces redundant calculations by storing the results of subproblems in memory.
- **Common in problems like:** Maximum sum subsequence, or longest increasing subsequence.

## f) Greedy Algorithms

- **When to use:** When local optimal choices lead to a global optimal solution (this isn’t always clear upfront).
- **Why it works:** Sometimes a problem can be solved by making greedy choices, like choosing the maximum element in a subarray, removing smaller elements, etc.
- **Common in problems like:** Maximum sum subarrays with specific constraints.
- **Example:** If you’re allowed to skip certain elements, greedy algorithms might help optimize the choice.

## 4. Key Steps in Your Approach

### a) Break Down the Problem

Start by understanding what’s being asked:

- **Is it about subarray sum?** Then you may need `Kadane’s Algorithm` or prefix sum.
- **Is it about conditions on subarray lengths or specific conditions (e.g., divisibility, exact sums)?** Then sliding window or HashMaps could be the way to go.

### b) Try Brute Force First

Always try to think of the simplest possible solution first (even if it’s slow). This helps you understand the mechanics of the problem. For example:

- **Brute Force Subarray Sum:** For each element, try every possible subarray sum by iterating through the array.

### c) Think of Optimizations

After trying brute force, think:

- **Can I reduce the time complexity by avoiding redundant work?**
- **Could dynamic programming help break the problem into smaller, manageable parts?**
- **Could prefix sums or HashMaps reduce my lookup times?**

### d) Recognize Problem Similarities

Many problems have hidden similarities. For example:

- **Kadane’s Algorithm** is basically dynamic programming applied to subarray sums.
- Problems involving conditions like divisibility by k often hint at prefix sums with modulo arithmetic.

## 5. Practical Steps When Stuck

1. **Revisit Similar Problems:**  
   Practice helps you build intuition. Try solving simpler problems from the same category (like `Kadane’s` before attempting more complex maximum sum problems).

2. **Ask the Right Questions:**  
   Ask yourself:
   - What am I looking for (max/min subarray, specific conditions)?
   - Is there a sliding window pattern?
   - Can I reduce the problem to a sum of subarrays?

3. **Practice Prefix Sum & Hashing:**  
   Many subarray problems involve sums and conditions, so getting comfortable with prefix sums and hashing (like in the problem we just solved) will give you a good foundation.
# Example Problem & Thought Process:

## Problem: Find the smallest subarray with a sum greater than S.

- **Step 1:** What is the problem asking? You’re asked to find a subarray with a sum greater than S.
- **Step 2:** Can brute force work? You could try every subarray, but that’s `O(n^2)`.
- **Step 3:** What’s a more efficient way? We need to keep track of a running sum as we move through the array.
- **Step 4:** Recognize the sliding window pattern. Start with a window of size 1 and expand it until the sum exceeds S. Then shrink the window from the left to find the smallest subarray.

This problem is naturally solved by the sliding window technique because you can adjust the subarray size dynamically.

## Summary:

- Understand the problem’s core requirement: subarray sum, divisibility, etc.
- Identify common patterns:
  - Kadane’s Algorithm for max subarrays.
  - Sliding Window for fixed-size or growing/shrinking subarrays.
  - Prefix Sum + HashMap for modulo or sum-based conditions.