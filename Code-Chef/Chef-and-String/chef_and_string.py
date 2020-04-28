"""
Problem Statement: https://www.codechef.com/problems/RECNDSTR
Author: striker
"""

def check_string_exist(data_string):
    string_len = len(data_string)
    if string_len == 1 or string_len == 2 or all(data_string[0] == c for c in data_string):
        return True
    is_exist = False
    if not string_len % 2:
        if all(data_string[0] == c for c in data_string[: : 2]) and all(data_string[1] == c for c in data_string[1: : 2]):
            is_exist = True
    return is_exist

def main():
    for test in range(int(input().strip())):
        print(f'{"YES" if check_string_exist(input().strip()) else "NO"}')

if __name__ == "__main__":
    main()
