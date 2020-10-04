'''
Problem Statement: https://www.hackerrank.com/challenges/python-string-formatting/problem
Author: striker
'''

def main():
    limit = int(input().strip())
    for number in range(limit + 1):
        print("{0:{width}d} {0:{width}o} {0:{width}X} {0:{width}b}".format(number, width = width))

if __name__ == "__main__":
    main()
