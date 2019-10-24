'''
Problem Statement: https://www.hackerrank.com/challenges/python-print/problem?h_r=next-challenge&h_v=zen
Author: striker
'''

def print_data(n):
    for i in range(n):
        print((i+1), end = "")
    print()

def main():
    print_data(int(input()))

if __name__ == "__main__":
    main()