'''
Problem Statement: https://www.hackerrank.com/challenges/lonely-integer/problem
Author: striker
'''

def main():
    n = int(input().rstrip())
    sequence = list(map(int, input().rstrip().split()))
    unique_integer = 0
    for integer in sequence:
        unique_integer ^= integer
    print("{}".format(unique_integer))

if __name__ == "__main__":
    main()
