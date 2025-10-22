# 🪟Sliding Window🪟 Summary

Sliding window technique is useful for solving problems involving subarray or substring.

These problems might involve finding the maximum/minimum sum, count of elements satisfying certain conditions, or finding subarrays with specific properties.

Generally, enumerating all substrings/subarrays takes O(n^2) time, but with the sliding window algorithm we can reduce that to O(n) time.


1. **Running Average**: Use a sliding window to efficiently calculate the average of a fixed-size window as new elements arrive in a stream of data.
2. **Formulating Adjacent Pairs**: Sliding windows are useful when you need to process adjacent pairs of elements in an ordered data structure, allowing you to easily access and operate on neighboring elements.
3. **Target Value Identification**: When you want to find a specific target value or combination of values in an array, a sliding window can help by adjusting the window size and efficiently searching for the desired value or subarrays that meet specific criteria.
4. **Longest/Shortest/Most Optimal Sequence**: Sliding windows are handy when you need to find the longest, shortest, or most optimal sequence that satisfies a given condition in a collection. By sliding a window through the collection and tracking relevant information within it, you can identify the desired sequence more efficiently than scanning the entire collection.

The main idea behind the sliding window technique is to convert two nested loops into a single loop. Usually, the technique helps us to reduce the time complexity from O(n²) or O(n³) to O(n). This is done by maintaining a sliding window, which is a subarray of the original array that is of a fixed size. The algorithm then iterates over the original array, updating the sliding window as it goes. This allows the algorithm to keep track of a contiguous sequence of elements in the original array, without having to iterate over the entire array multiple times.

Both fixed and variable window sliding window problems can use the techniques of hashing, two pointers, and sliding window optimization.

- **Hashing** is a common technique for tracking the elements in a sliding window. This is because a hash table can quickly and efficiently look up the presence of an element in the window.
- **Two pointers** is another common technique for tracking the elements in a sliding window. This is because two pointers can easily track the start and end of the window.
- **Sliding window optimization** is a technique that combines hashing and two pointers to improve the performance of the sliding window algorithm. This is done by using hashing to quickly look up the presence of an element in the window and using two pointers to track the start and end of the window.

The choice of technique for solving a sliding window problem depends on the specific problem and the constraints of the problem. For example, if the sliding window is small, then hashing may be a good choice. However, if the sliding window is large, then two pointers may be a better choice.

## How to Identify Fixed and Variable Size Window




## Two types Sliding Window:

- Fixed size
- Variable size

1. **Fixed Window**:
   - In a fixed window problem, we have a predefined window size that remains constant throughout the problem-solving process.
   - The template for solving a fixed window problem involves maintaining two pointers, low and high, that represent the indices of the current window.
   - The process involves iterating over the array or sequence, adjusting the window as necessary, and performing computations or operations on the elements within the window.

Here's the template:

#### How to implement the window in code?

Two pointers: start and end that represent start and end of window.

#### When to think of sliding window FIXED SIZE?

When we need to process adjacent elements, something like `abs(i - j) <= k` is mentioned in problem. Or when we need to process k previous/next elements.

> Note: The purpose of the following template is not to remember it for solving each question, but to get familiar with the topic, and once you are confident enough with the pattern you can solve it whichever way you want.

#### Template

`////credits for template @imanishkumar7545`
```javascript
fixed_Size_window()
{
    int low = 0, high = 0, windowsize = k;
    while (i < sizeofarray)
    {
        // Step 1: Create a window that is one element smaller than the desired window size
        if (high - low + 1 < windowsize)
        {
            // Generate the window by increasing the high index
            high++;
        }
        // Step 2: Process the window
        else
        {
            // Window size is now equal to the desired window size
            // Step 2a: Calculate the answer based on the elements in the window
            // Step 2b: Remove the oldest element (at low index) from the window for the next window

            // Proceed to the next window by incrementing the low and high indices
        }
    }
}
```

#### Basic Sliding Window Fixed Size

- [https://leetcode.com/problems/contains-duplicate-ii](https://leetcode.com/problems/contains-duplicate-ii) (E) Adjacent k Neighbours process
- [https://leetcode.com/problems/maximum-average-subarray-i/](https://leetcode.com/problems/maximum-average-subarray-i/)
- [https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)
- [https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
- [https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/) (M) Convert to sliding window
- [https://leetcode.com/problems/defuse-the-bomb/](https://leetcode.com/problems/defuse-the-bomb/) E
- [https://leetcode.com/problems/substring-with-concatenation-of-all-words](https://leetcode.com/problems/substring-with-concatenation-of-all-words) H
- [https://leetcode.com/problems/repeated-dna-sequences/](https://leetcode.com/problems/repeated-dna-sequences/) Map of strings fixed window [Best approach Bit manipulation] ✏️

#### Deque

- [https://leetcode.com/problems/sliding-window-maximum](https://leetcode.com/problems/sliding-window-maximum) ✏️
- First negative integer in every window of size k [G]

### 2. 🔥Variable size


In a variable window problem, the window size is not fixed and can change dynamically based on certain conditions or criteria. The template for solving a variable window problem involves maintaining two pointers, `start` and `end`, which represent the indices of the current window.

### Steps to Solve a Variable Window Problem

1. **Initialize the window indices:** Start by initializing the `start` and `end` pointers to the first element of the sequence or array.

2. **Expand the window:** Check a condition to determine whether to expand the window. If the condition is satisfied, increment the `end` pointer to expand the window size.

3. **Process the window:** Once the window size meets the desired criteria or condition, perform the required computations or operations on the elements within the window.

4. **Adjust the window size:** If the window size exceeds the desired criteria, adjust the window by moving the `start` pointer. Iterate or loop until the window size matches the desired criteria, and update the window accordingly.

```javascript
variable_window()
{
    int start = 0, end = 0;
    while (end < n)
    {
        // Perform calculations or operations within the window

        /* Case 1: Expand the window
           If the window size is less than the desired value (k), increase the end index
        */
        if (end - start + 1 < k)
        {
            end++;
        }

        /* Case 2: Window of desired size
           If the window size is equal to the desired value (k), process the window and calculate the answer
        */
        else if (end - start + 1 == k)
        {
            // Perform the required calculations or operations to obtain the answer
            // Store the answer in a variable (ans)

            end++;
        }

        /* Case 3: Reduce the window size
           If the window size is greater than the desired value (k), adjust the window by moving the start index
        */
        else if (end - start + 1 > k)
        {
            while (end - start + 1 > k)
            {
                // Remove calculations or operations involving the element at the start index

                start++;
            }

            // Check if the window size becomes equal to the desired value (k) after adjustment
            if (end - start + 1 == k)
            {
                // Perform calculations or operations and store the answer if necessary
            }

            end++;
        }
    }

    // Return the final answer (ans)
}
```

#### 2a. Standard Sliding Window

# Sliding Window Techniques Overview

Standard SW uses a variable `INTEGER` that represents the window.

## Problems

- **209.** Minimum Size Subarray Sum
- **713.** Subarray Product Less Than K
- **930.** Binary Subarrays With Sum
- **1248.** Count Number of Nice Subarrays ✏️
- **1658.** Minimum Operations to Reduce X to Zero (Reducible to standard SW)
- **1004.** Max Consecutive Ones III ✏️
- **2024.** Maximize the Confusion of an Exam (Two Pass SW | One Pass SW)
- **2962.** Count Subarrays Where Max Element Appears at Least K Times 
  - 1. At least k = Total subArray - At most k-1
- **1208.** Get Equal Substrings Within Budget

### Hashmap + Sliding Window

This type of problems require a hashmap or a frequency array to represent a Window.

## Problems

- **3.** Longest Substring Without Repeating Characters
- **159.** Longest Substring with At Most Two Distinct Characters [Premium/CN]
- **340.** Longest Substring with At Most K Distinct Characters [Premium/CN]
- **3090.** Maximum Length Substring With Two Occurrences
- **76.** Minimum Window Substring (HARD)
- **424.** Longest Repeating Character Replacement (Similar concept as LC 1004)
- **438.** Find All Anagrams in a String
- **567.** Permutation in String
- **904.** Fruit Into Baskets
- **1695.** Maximum Erasure Value 🔁
- **2958.** Length of Longest Subarray With at Most K Frequency
- **992.** Subarrays with K Different Integers (At most concept)
- **395.** Longest Substring with At Least K Repeating Characters ⚠️☠️🚨

### Prefix Sum + HashMap + Sliding Window

[Maximum Erasure Value Problem](https://leetcode.com/problems/maximum-erasure-value/) 🔁

### Bit Manipulation

- **2401.** Longest Nice Subarray (BITMASKING + SW) ✏️

### Greedy

- **1838.** Frequency of the Most Frequent Element (SW + Greedy | Can also be solved using Bin Search + Prefix sum)

## Extras

### Rough Work 
- *Dont look here* ⋆༺𓆩☠︎︎𓆪༻⋆

### Uncategorized

- [Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)
- [Minimum Size Subarray in Infinite Array](https://leetcode.com/problems/minimum-size-subarray-in-infinite-array)
- [Longest Subarray of 1s After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)

### Problem Where It's Hard to Identify SW Is Applicable

- [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)

### Other Templates Posts Regarding Sliding Window

- [Minimum Window Substring Template](https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/)
- [Find All Anagrams in a String Sliding Window Algorithm Template](https://leetcode.com/problems/find-all-anagrams-in-a-string/solutions/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem/)

> Kadane's algorithm and sliding window algorithms are related but not exactly the same. They both deal with contiguous subarrays, but they solve different types of problems and use different strategies. While Kadane's algorithm can be seen as a specific type of sliding window algorithm tailored for finding the maximum sum subarray, not all sliding window algorithms are implementations of Kadane's algorithm. They serve different problem-solving purposes within the domain of contiguous subarrays.

- [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) (Sliding one array over another | DP)



# Sliding Window Question Bank

## Fixed Sized Window
- [30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)
- [187. Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/)
- [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
- [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)
- [643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)
- [995. Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)
- [1100. Find K-Length Substrings With No Repeated Characters](https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/)
- [1151. Minimum Swaps to Group All 1's Together](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/)
- [1176. Diet Plan Performance](https://leetcode.com/problems/diet-plan-performance/)
- [1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)
- [1423. Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
- [1456. Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
- [1652. Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/)
- [1876. Substrings of Size Three with Distinct Characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)
- [2090. K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/)
- [2134. Minimum Swaps to Group All 1's Together II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)
- [2269. Find the K-Beauty of a Number](https://leetcode.com/problems/find-the-k-beauty-of-a-number/)
- [2379. Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/)
- [2461. Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)
- [3191. Minimum Operations to Make Binary Array Elements Equal to One I](https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/)
- [3206. Alternating Groups I](https://leetcode.com/problems/alternating-groups-i/)
- [3208. Alternating Groups II](https://leetcode.com/problems/alternating-groups-ii/)
- [3254. Find the Power of K-Size Subarrays I](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/)
- [3439. Reschedule Meetings for Maximum Free Time I](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/)

## Variable Sized Window
- [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [159. Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
- [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)
- [340. Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
- [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
- [487. Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii/)
- [795. Number of Subarrays with Bounded Maximum](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/)
- [862. Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)
- [904. Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)
- [992. Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)
- [1004. Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)
- [1208. Get Equal Substrings Within Budget](https://leetcode.com/problems/get-equal-substrings-within-budget/)
- [1297. Maximum Number of Occurrences of a Substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/)
- [1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)
- [1358. Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)
- [1574. Shortest Subarray to be Removed to Make Array Sorted](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)
- [1493. Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)
- [1695. Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value/)
- [1838. Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)
- [1852. Distinct Numbers in Each Subarray](https://leetcode.com/problems/distinct-numbers-in-each-subarray/)
- [2024. Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)
- [2062. Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string/)
- [2302. Count Subarrays With Score Less Than K](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/)
- [2444. Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)
- [2516. Take K of Each Character From Left and Right](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/)
- [2537. Count the Number of Good Subarrays](https://leetcode.com/problems/count-the-number-of-good-subarrays/)
- [2799. Count Complete Subarrays in an Array](https://leetcode.com/problems/count-complete-subarrays-in-an-array/)
- [2962. Count Subarrays Where Max Element Appears at Least K Times](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/)
- [3095. Shortest Subarray With OR at Least K I](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/)
- [3097. Shortest Subarray With OR at Least K II](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/)
- [3305. Count of Substrings Containing Every Vowel and K Consonants I](https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/)
- [3306. Count of Substrings Containing Every Vowel and K Consonants II](https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/)
