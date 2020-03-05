'''
Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/count-divisors/description/
Author: striker
'''

start, end, n = tuple(map(int, input().rstrip().split()))
print("{}".format((end // n) - ((start - 1) // n)))
