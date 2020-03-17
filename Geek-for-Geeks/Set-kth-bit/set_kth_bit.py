'''
Problem Statement: https://practice.geeksforgeeks.org/problems/set-kth-bit/0
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n, k = tuple(map(int, input().rstrip().split()))
        print("{}".format(n | 1 << k))

if __name__ == "__main__":
    main()
