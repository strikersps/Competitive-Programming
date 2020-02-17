'''
Problem Statement: https://www.codechef.com/problems/CASH
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n, k = tuple(map(int, input().rstrip().split()))
        print("{}".format(sum(list(map(int, input().rstrip().split()))) % k))

if __name__ == "__main__":
    main()
