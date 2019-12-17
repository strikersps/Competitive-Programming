# Rearrange Odd and Even values in Alternate Fashion in Ascending Order

**Problem Statment:** Given an array of integers (both `odd` and `even`),the task is to arrange them in such a way that `odd` and `even` values come in alternate fashion in non-decreasing order(ascending) respectively.

If the smallest value is `Even` then we have to print `Even-Odd` pattern.
If the smallest value is `Odd` then we have to print `Odd-Even` pattern.

**Note: Number of `Odd` elements must be equal to Number of `Even` elements in the input array.**

**Examples**
```
Input: arr[] = {1, 3, 2, 5, 4, 7, 10}
Output: 1, 2, 3, 4, 5, 10, 7
Smallest value is 1 is Odd so output will be Odd-Even pattern.

Input: arr[] = {9, 8, 13, 2, 19, 14}
Output: 2, 9, 8, 13, 14, 19
Smallest value is 2 is Even so output will be Even-Odd pattern.
```