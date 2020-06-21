"""
Problem Statement: https://codeforces.com/problemset/problem/282/A
Author: striker
"""

def main():
    x = 0
    for _ in range(int(input().strip())):
        instruction = input().strip()
        if instruction[1] == '+':
            x += 1
        else:
            x -= 1
    print(x)

if __name__ == "__main__":
    main()
