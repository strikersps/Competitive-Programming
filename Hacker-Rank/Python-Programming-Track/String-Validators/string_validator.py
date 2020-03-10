'''
Problem Statement: https://www.hackerrank.com/challenges/string-validators/problem
Author: striker
'''

def string_validator(string):
    print("True" if any(letter.isalnum() for letter in string) else "False")
    print("True" if any(letter.isalpha() for letter in string) else "False")
    print("True" if any(letter.isdigit() for letter in string) else "False")
    print("True" if any(letter.islower() for letter in string) else "False")
    print("True" if any(letter.isupper() for letter in string) else "False")

def main():
    string_validator(input().rstrip())

if __name__ == "__main__":
    main()
