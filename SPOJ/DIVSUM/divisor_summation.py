'''
Problem Statement: https://www.spoj.com/problems/DIVSUM/
Author: striker
'''

def compute_sum_of_proper_divisors(n):
    divisor_sum = 1
    i = 2
    while i <= (n // i):
        if not n % i:
            if (n // i) == i:
                divisor_sum += i
            else:
                divisor_sum += (i + (n // i))
        i += 1
    return divisor_sum

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print(f"{0 if n == 1 else compute_sum_of_proper_divisors(n)}")

if __name__ == "__main__":
    main()
