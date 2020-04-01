'''
Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-array/problem
Author: striker
'''

def balanced_sums(sequence):
    is_balanced = False
    right_sum = sum(sequence)
    left_sum = 0
    for term in sequence:
        if left_sum == (right_sum - term):
            is_balanced = True
            break
        left_sum += term
        right_sum -= term
    return is_balanced

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print("{0}".format("YES" if balanced_sums(list(map(int, input().strip().split()))) else "NO"))

if __name__ == "__main__":
    main()