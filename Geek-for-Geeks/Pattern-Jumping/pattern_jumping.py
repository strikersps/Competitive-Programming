'''
Problem Statement: https://practice.geeksforgeeks.org/problems/pattern-jumping/0
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{0}".format("True" if n and not (n & (n - 1)) else "False"))

if __name__ == "__main__":
    main()
