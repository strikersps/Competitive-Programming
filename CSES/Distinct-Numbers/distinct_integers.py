"""
Problem Statement: https://cses.fi/problemset/task/1621/
Author: striker
"""

def main():
    n = int(input().strip())
    print(len(set(map(int, input().strip().split()))))

if __name__ == "__main__":
    main()
