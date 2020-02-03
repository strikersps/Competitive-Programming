'''
Problem Statement: https://www.hackerrank.com/challenges/maximizing-xor/problem
Author: striker
'''

def main():
    start = int(input().rstrip())
    end = int(input().rstrip())
    max_xor = 0
    for i in range(start, end + 1):
        for j in range(i + 1, end + 1):
            max_xor = max(max_xor, i ^ j)
    print("{}".format(max_xor))

if __name__ == "__main__":
    main()
