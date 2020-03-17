'''
Problem Statement: https://practice.geeksforgeeks.org/problems/reverse-an-array/0
Author: striker
'''

for test in range(int(input().rstrip())):
    n = int(input().rstrip())
    print("{}".format(" ".join(map(str, list(map(int, input().rstrip().split()))[: : -1]))))
