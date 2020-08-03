"""
Problem Statement: https://cses.fi/problemset/task/1070
Author: striker
"""

def main():
    n = int(input().strip())
    if n == 2 or n == 3:
        print("NO SOLUTION")
    else:
        for i in range(1, n + 1):
            if not i % 2:
                print(i, end = ' ')
        for i in range(1, n + 1):
            if i % 2:
                print(i, end = ' ')
        print()

if __name__ == "__main__":
    main()
