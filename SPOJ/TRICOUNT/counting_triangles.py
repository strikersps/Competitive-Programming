'''
Problem Statement: https://www.spoj.com/problems/TRICOUNT/
Author: striker
'''

def main():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        print(n * (n + 2) * ((n << 1) + 1) // 8)

if __name__ == "__main__":
    main()
