'''
Problem Statement: https://www.spoj.com/problems/FCTRL2/
Author: striker
'''

def compute_factorial(n):
    if n == 1:
        return 1
    return n * compute_factorial(n - 1)

def main():
    for test in range(int(input().rstrip())):
        print("{0}".format(compute_factorial(int(input().rstrip()))))

if __name__ == "__main__":
    main()
