'''
Problem Statement: https://www.codechef.com/problems/GCD2
Author: striker
'''

def compute_gcd(a, b):
    if not b:
        return a
    return compute_gcd(b, a % b)

def main():
    for test in range(int(input().rstrip())):
        a, b = tuple(map(int, input().rstrip().split()))
        if a > b:
            b, a = a, b
        print("{}".format(compute_gcd(b, a))) # As b >= a

if __name__ == "__main__":
    main()
