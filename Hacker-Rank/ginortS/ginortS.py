'''
Problem Statement: https://www.hackerrank.com/challenges/ginorts/problem
Author: striker
'''

TOTAL_ALPHABETS = 26
TOTAL_DIGITS_DECIMAL = 10
upper_case_freq = [0] * TOTAL_ALPHABETS
lower_case_freq = [0] * TOTAL_ALPHABETS
digit_freq = [0] * TOTAL_DIGITS_DECIMAL

def ginorts(string_list):
    for character in string_list:
        if character.isupper():
            upper_case_freq[ord(character) - ord('A')] += 1
            continue
        if character.islower():
            lower_case_freq[ord(character) - ord('a')] += 1
            continue
        digit_freq[int(character)] += 1
    updated_list = list()
    for index in range(TOTAL_ALPHABETS):
        if lower_case_freq[index]:
            for _ in range(lower_case_freq[index]):
                updated_list.append(chr(index + ord('a')))
            continue
    for index in range(TOTAL_ALPHABETS):
        if upper_case_freq[index]:
            for _ in range(upper_case_freq[index]):
                updated_list.append(chr(index + ord('A')))
    even_list = list()
    for index in range(TOTAL_DIGITS_DECIMAL):
        if digit_freq[index]:
            if index % 2:
                for _ in range(digit_freq[index]):
                    updated_list.append(str(index))
                continue
            for _ in range(digit_freq[index]):
                even_list.append(index)
    for even in even_list:
        updated_list.append(str(even))
    return "".join(updated_list)

def main():
    print("{0}".format(ginorts(list(input().rstrip()))))

if __name__ == "__main__":
    main()
