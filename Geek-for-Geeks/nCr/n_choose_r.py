'''
Problem Statement: https://practice.geeksforgeeks.org/problems/ncr/0/
Author: striker
'''

MOD = 10**9 + 7

def compute_n_choose_r(n, r):
    if n < r:
        return 0
    if n == r:
        return 1
    combination = [0] * (n + 1)
    combination[0] = 1
    for row in range(n + 1):
        for col in range(row, 0, -1):
            if row == col:
                combination[row] = 1
                continue
            combination[col] = (combination[col] + combination[col - 1]) % MOD
    return combination[r]

def main():
    for test in range(int(input().rstrip())):
        n, r = tuple(map(int, input().rstrip().split()))
        print("{}".format(compute_n_choose_r(n, r)))

if __name__ == "__main__":
    main()
