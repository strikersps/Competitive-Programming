'''
Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/palindrome-check-2/description/
Author: striker
'''

word = input().rstrip()
print("{}".format("YES" if word == word[: : - 1] else "NO"))
