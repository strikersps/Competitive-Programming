'''
Problem Statement: https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard/0
Author: striker
'''

for test in range(int(input().rstrip())):
    n = int(input().rstrip())
    print("{0}".format((n * (n + 1) * ((n << 1) + 1)) // 6))
