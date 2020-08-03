"""
Problem Statement: https://cses.fi/problemset/task/1072
Author: striker
"""

def main():
    for dimension in range(1, int(input().strip()) + 1):
        print(((dimension - 1) * (dimension + 4) * ((dimension * dimension) - (3 * dimension) + 4)) // 2)

if __name__ == "__main__":
    main()
