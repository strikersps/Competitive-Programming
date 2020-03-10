'''
Problem Statement: https://www.hackerrank.com/challenges/python-mutations/problem
Author: striker
'''

def mutate_string(string, position, replacement_char):
    return string[: position] + replacement_char + string[position + 1: ]

def main():
    string = input().rstrip()
    position, replacement_char = input().rstrip().split()
    print("{0}".format(mutate_string(string, int(position), replacement_char)))

if __name__ == "__main__":
    main()
