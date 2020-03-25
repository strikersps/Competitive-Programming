'''
Problem Statement: https://www.spoj.com/problems/TRICOUNT/
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{0}".format((n * (n + 2) * (2 * n + 1)) // 8))

if __name__ == "__main__":
    main()
