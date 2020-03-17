'''
Problem Statement: https://practice.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers/0
Author: striker
'''

def modular_exponentiation(base, exponent, modular):
    if modular == 1:
        return 0
    result = 1
    while exponent:
        if exponent & 1:
            result = (result * base) % modular
        base = (base * base) % modular
        exponent >>= 1
    return result

def main():
    for test in range(int(input().rstrip())):
        base, exponent, modular = tuple(map(int, input().rstrip().split()))
        print("{}".format(modular_exponentiation(base, exponent, modular)))

if __name__ == "__main__":
    main()
