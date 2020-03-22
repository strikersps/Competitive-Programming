'''
Problem Statement: https://www.codechef.com/problems/CSUB
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        string_len = int(input().rstrip())
        binary_string = input()
        ones_count = list(binary_string).count('1')
        print("{0}".format((ones_count * (1 + ones_count)) >> 1))

if __name__ == "__main__":
    main()
