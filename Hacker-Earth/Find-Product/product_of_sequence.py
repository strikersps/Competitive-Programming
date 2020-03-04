'''
Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/find-product/
Author: striker
'''

MOD = 10**9 + 7

def main():
    n = int(input().rstrip())
    sequence = list(map(int, input().rstrip().split()))
    product = 1
    for value in sequence:
        product = (product * value) % MOD
    print("{}".format(product))

if __name__ == "__main__":
    main()
