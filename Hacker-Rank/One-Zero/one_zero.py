'''
Problem Statement: https://www.hackerrank.com/contests/mnnit-opc-2k20-2-0/challenges/one-zero-2/problem
Author: striker
'''

MOD = 10**9 + 7

def compute_max_binary_number(binary_string, n):
    updated_binary_string = 2 * binary_string[0: ]
    i = n - 1
    pos = n
    while i >= 0:
        if updated_binary_string[i: i + n] > updated_binary_string[pos: pos + n]:
            pos = i
        i -= 1

    # Compute the decimal equivalent of the binary_string[pos: pos + n]
    decimal_equivalent = 0
    for bit in updated_binary_string[pos: pos + n]:
        decimal_equivalent = ((decimal_equivalent << 1) + (ord(bit) - ord('0'))) % MOD
    return decimal_equivalent

def main():
    n = int(input().strip())
    binary_string = input().strip()
    print(f"{compute_max_binary_number(binary_string, n)}")

if __name__ == "__main__":
    main()
