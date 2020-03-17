'''
Problem Statement: https://practice.geeksforgeeks.org/problems/power-of-2/0/
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{0}".format("YES" if n and not (n & n - 1) else "NO"))

if __name__ == "__main__":
    main()
