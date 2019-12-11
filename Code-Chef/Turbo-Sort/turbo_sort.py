'''
Problem Statement: Problem Statement: https://www.codechef.com/problems/TSORT
Author: striker
'''

def main():
    print("\n".join(map(str,sorted([int(input()) for i in range(int(input()))]))))


if __name__ == "__main__":
    main()