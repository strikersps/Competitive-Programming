'''
Problem Statement: https://www.codechef.com/problems/CHN15A
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n, k = tuple(map(int, input().rstrip().split()))
        print("{0}".format([not (val + k) % 7 for val in list(map(int, input().rstrip().split()))].count(True)))

if __name__ == "__main__":
    main()
