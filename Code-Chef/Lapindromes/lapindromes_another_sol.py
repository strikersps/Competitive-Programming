'''
Problem Statement: https://www.codechef.com/problems/LAPIN
Author: striker
'''

from collections import Counter

def check_lapindrome(string):
    """
    Function returns True if the string is lapindrome else it returns False.
    """
    string_len = len(string)
    return Counter(string[: string_len >> 1]) == (Counter(string[1 + (string_len >> 1): ]) if string_len % 2 else Counter(string[string_len >> 1: ]))

def main():
    for test in range(int(input().strip())):
        string = input().strip()
        print("{0}".format("YES" if check_lapindrome(string) else "NO"))

if __name__ == "__main__":
    main()
