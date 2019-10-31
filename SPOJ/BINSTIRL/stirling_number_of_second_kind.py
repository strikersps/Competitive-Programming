'''
Problem Statement: https://www.spoj.com/problems/BINSTIRL/
Author: striker
'''

def main():
    test = int(input())
    for _ in range(test):
        n,m = tuple(map(int,input().split()))
        if n >= m:
            if not ((n - m) & ((m - 1) >> 1)):
                print("1")
            else:
                print("0")
        else:
            print("0")

if __name__ == "__main__":
    main()