'''
Problem Statement: https://www.hackerrank.com/challenges/30-bitwise-and/problem
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n, k = tuple(map(int, input().rstrip().split()))
        print("{}".format(k - 2 if k | (k - 1) > n else k - 1))

if __name__ == "__main__":
    main()
