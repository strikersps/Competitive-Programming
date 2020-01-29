'''
Problem Statement: https://www.hackerrank.com/challenges/between-two-sets/problem
Author: striker
'''

def compute_gcd(a, b):
    if not b:
        return a
    elif not a:
        return b
    return compute_gcd(b, a % b)

def compute_lcm(a, b):
    return a * b / compute_gcd(a, b)

def compute_seq_lcm(data):
    lcm = 1
    for val in data:
        lcm = compute_lcm(val, lcm)
    return lcm

def compute_seq_gcd(data):
    gcd = 0
    for val in data:
        gcd = compute_gcd(val, gcd)
    return gcd

def main():
    n, m = tuple(map(int, input().rstrip().split()))
    lcm = compute_seq_lcm(list(map(int, input().rstrip().split())))
    gcd = compute_seq_gcd(list(map(int, input().rstrip().split())))
    tot_numbers = 0
    i = 1
    while i * i <= gcd:
        if not gcd % i:
            if not i % lcm:
                tot_numbers += 1
            if not ((gcd / i) == i):
                if not (gcd / i) % lcm:
                    tot_numbers += 1
        i += 1
    print("{}".format(tot_numbers))

if __name__ == "__main__":
    main()
