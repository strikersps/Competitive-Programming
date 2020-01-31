'''
Problem Statement: https://www.hackerrank.com/challenges/strong-password/problem
Author: striker
'''

NUMBERS = "0123456789"
LOWER_CASE = "abcdefghijklmnopqrstuvwxyz"
UPPER_CASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
SPECIAL_CHARACTERS = "!@#$%^&*()-+"
TOTAL_STRONG_PASSWORD_CONDITIONS = 4

def main():
    n = int(input().rstrip())
    user_password = input().rstrip()
    user_password_len = len(user_password)
    existence = [False] * TOTAL_STRONG_PASSWORD_CONDITIONS
    for letter in user_password:
        if letter in NUMBERS:
            existence[0] = True
            continue
        if letter in LOWER_CASE:
            existence[1] = True
            continue
        if letter in UPPER_CASE:
            existence[2] = True
            continue
        if letter in SPECIAL_CHARACTERS:
            existence[3] = True
    min_char_addition = 0
    for data in existence:
        if not data:
            min_char_addition += 1
    if user_password_len + min_char_addition < 6:
        min_char_addition += (6 - (user_password_len + min_char_addition))
    print("{}".format(min_char_addition))

if __name__ == "__main__":
    main()
