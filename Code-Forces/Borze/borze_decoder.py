"""
Problem Statement: https://codeforces.com/problemset/problem/32/B
Author: striker
"""

def borze_code_decoder(borze_code: list)-> str:
    decoded_string = list()
    index = 0
    while index < len(borze_code):
        if borze_code[index] == '.':
            decoded_string.extend('0')
        elif index < len(borze_code) - 1 and borze_code[index] == '-':
            if borze_code[index + 1] == '.':
                decoded_string.extend('1')
            else:
                decoded_string.extend('2')
            index += 1
        index += 1
    return ''.join(decoded_string)

def main():
    borze_code = input().strip()
    print(borze_code_decoder(list(borze_code)))

if __name__ == "__main__":
    main()
