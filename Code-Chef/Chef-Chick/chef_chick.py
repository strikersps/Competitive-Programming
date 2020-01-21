'''
Problem Statement: https://www.codechef.com/problems/CHFCHK
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input())
        print("{}".format(min(list(map(int, input().rstrip().split())))))

if __name__ == "__main__":
    main()
