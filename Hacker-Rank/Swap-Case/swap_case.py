'''
Problem Statement: https://www.hackerrank.com/challenges/swap-case/problem
Author: striker
'''

def main():
    print("{0}".format("".join([letter.upper() if letter.islower() else letter.lower() for letter in input().rstrip()])))

if __name__ == "__main__":
    main()
