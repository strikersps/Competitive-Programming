'''
Problem Statement: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3671
Author: striker
'''

def compute_modular_exponentiation(base, exponent, modulus):
    if modulus == 1:
        return 0
    result = 1
    while exponent:
        if exponent & 1:
            result = (result * base) % modulus
        base = (base * base) % modulus
        exponent >>= 1
    return result

def main():
    for test in range(int(input().rstrip())):
        base, exponent, modulus = tuple(map(int, input().rstrip().split()))
        if not base:
            break
        print("{}".format(compute_modular_exponentiation(base, exponent, modulus)))

if __name__ == "__main__":
    main()
