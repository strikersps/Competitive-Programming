'''
Problem Statement: https://practice.geeksforgeeks.org/problems/parity-of-unsigned-integer/0
Author: striker
'''

def compute_parity(n):
    parity = False
    while n:
        parity = not parity
        n &= (n - 1)
    return parity

def main():
    for test in range(int(input().rstrip())):
        print("{0}".format("odd" if compute_parity(int(input().rstrip())) else "even"))

if __name__ == "__main__":
    main()
