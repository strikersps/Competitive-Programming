"""
Problem Statement: https://codeforces.com/problemset/problem/69/A
Author: striker
"""

def main():
    x_coordinate = 0; y_coordinate = 0; z_coordinate = 0
    for coordinate in range(int(input().strip())):
        x, y, z = tuple(map(int, input().strip().split()))
        x_coordinate += x; y_coordinate += y; z_coordinate += z
    print("YES" if not x_coordinate and not y_coordinate and not z_coordinate else "NO")

if __name__ == "__main__":
    main()
