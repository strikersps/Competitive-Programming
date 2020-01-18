'''
Problem Statement: https://www.codechef.com/problems/CGPOWN
Author: striker
'''

def modular_exponentiation(base, exponent, mod):
    if 1 == mod:
        return 0
    result = 1
    print("base: {}\texponent: {}".format(base, exponent))
    while(exponent):
        if(exponent & 1):
            result = (result * base) % mod
            print("result: {}".format(result))
        base = (base * base) % mod
        exponent >>= 1
        print("base: {}\texponent: {}".format(base, exponent))
    return result

def main():
    for test in range(int(input().rstrip())):
        base, exponent, mod = tuple(map(int, input().rstrip().split()))
        print("{}".format(modular_exponentiation(base, exponent, mod)))

if __name__ == "__main__":
    main()
