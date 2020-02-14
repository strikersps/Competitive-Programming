'''
Problem Statement:  (i)  https://www.hackerrank.com/contests/projecteuler/challenges/euler006/problem
                    (ii) https://projecteuler.net/problem=6
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        n_squared = n * n
        print("{}".format((n_squared - 1) * ((3 * n_squared) + (n << 1)) // 12))

if __name__ == "__main__":
    main()
