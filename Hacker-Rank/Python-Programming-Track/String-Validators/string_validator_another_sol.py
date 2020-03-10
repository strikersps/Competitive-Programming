'''
Problem Statement: https://www.hackerrank.com/challenges/string-validators/problem
Author: striker
'''

def string_validator(string):
    ans = ["False"] * 5
    for letter in string:
        if letter.islower():
            ans[0] = ans[1] = ans[3] = "True"
        elif letter.isupper():
            ans[0] = ans[1] = ans[4] = "True"
        elif letter.isdigit():
            ans[0] = ans[2] = "True"
    if string.isalnum():
        ans[0] = "True"
    return "\n".join(ans)

def main():
    print(string_validator(input().rstrip()))

if __name__ == "__main__":
    main()
