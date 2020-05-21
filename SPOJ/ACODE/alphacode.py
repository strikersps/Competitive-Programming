"""
Problem Statement: https://www.spoj.com/problems/ACODE/
Author: striker
"""

def compute_number_of_ways(encoded_msg : str) -> int:
    encoded_msg_len = len(encoded_msg)
    if encoded_msg_len == 1:
        return 1
    is_possible = True
    number_of_ways = [0] * encoded_msg_len
    number_of_ways[0] = 1
    for index in range(1, encoded_msg_len):
        digit = 10 * int(encoded_msg[index - 1]) + int(encoded_msg[index])
        if encoded_msg[index] == '0':
            if not digit or digit > 26:
                is_possible = False
                break
        if encoded_msg[index - 1] == '0' or digit > 26:
            number_of_ways[index] = number_of_ways[index - 1]
        elif digit == 10 or digit == 20:
            number_of_ways[index] = number_of_ways[index - 2] if index > 1 else number_of_ways[index - 1]
        else:
            number_of_ways[index] = number_of_ways[index - 1] + (number_of_ways[index - 2] if index > 2 else 1)
    if not is_possible:
        return 0
    return number_of_ways[encoded_msg_len - 1]

def main():
    while True:
        encoded_msg = input().strip()
        if encoded_msg == "0":
            break
        print(compute_number_of_ways(encoded_msg))

if __name__ == "__main__":
    main()
