'''
Problem Statement: https://www.codechef.com/problems/LEDIV
Author: striker
'''

def compute_gcd(a, b):
    if not b:
        return a
    elif not a:
        return b
    return compute_gcd(b, a % b)

def compute_min_divisor(sequence):
    seq_gcd = 0
    for value in sequence:
        seq_gcd = compute_gcd(seq_gcd, value)
    if seq_gcd == 1:
        return -1
    min_divisor = seq_gcd
    i = 2
    while i * i <= seq_gcd:
        if not seq_gcd % i:
            min_divisor = i
            break;
        i += 1
    return min_divisor

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{}".format(compute_min_divisor(list(map(int, input().rstrip().split())))))

if __name__ == "__main__":
    main()
