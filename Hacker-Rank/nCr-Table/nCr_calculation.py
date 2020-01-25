'''
Problem Statement: https://www.hackerrank.com/challenges/ncr-table/problem
Author: striker
'''

MODULUS = 1000000000

def compute_ncr_table(n):
    ncr_table = [0] * (n + 1)
    ncr_table[0] = 1
    for i in range(1, n + 1):
        for j in range(i, 0, -1):
            if i == j:
                ncr_table[j] = 1
                continue
            ncr_table[j] = (ncr_table[j - 1] + ncr_table[j]) % MODULUS
    return " ".join(list(map(str, ncr_table)))

def main():
    for test in range(int(input().rstrip())):
        n = int(input())
        print("{}".format(compute_ncr_table(n)))

if __name__ == "__main__":
    main()
