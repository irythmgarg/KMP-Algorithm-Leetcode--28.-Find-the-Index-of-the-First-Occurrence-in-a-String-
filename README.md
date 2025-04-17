# KMP-Algorithm-Leetcode--28.-Find-the-Index-of-the-First-Occurrence-in-a-String-
# KMP String Matching - `strStr()` Implementation

## 📜 Problem Statement

Implement the `strStr()` function that searches for the first occurrence of a **pattern string** (`small`) in a **text string** (`large`). Return the starting index of the first occurrence. If not found, return -1.

---

## 💡 Approach

We use the **KMP (Knuth-Morris-Pratt)** algorithm, which avoids unnecessary comparisons by preprocessing the pattern using a **prefix (LPS)** table.

### Steps:

1. **Build LPS (Longest Prefix Suffix) Array**:
   - For the pattern, this tells us the next position to jump to when a mismatch occurs.
2. **Pattern Search**:
   - While matching characters, use the LPS table to avoid rechecking characters.

---

## 🧠 KMP Example

### Input:
```cpp
large = "abxabcabcaby"
small = "abcaby"
Output:
6
Explanation:
The pattern "abcaby" starts at index 6 in "abxabcabcaby".

---
🔁 Time and Space Complexity
Time Complexity: O(N + M)
where N = length of large, M = length of small

Space Complexity: O(M) for the prefix table

✅ Topics Covered
String matching
KMP algorithm
Prefix function (LPS array)


📌 Tags
#string-matching #kmp-algorithm #prefix-table #pattern-searching
