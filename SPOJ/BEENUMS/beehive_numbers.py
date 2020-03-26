'''
Problem Statement: https://www.spoj.com/problems/BEENUMS/
Author: striker
'''

def check_beehive_number(n):
    if (n - 1) % 3:
        return "N"
    is_beehive = False
    quotient = (n - 1) // 3
    number = 1
    while number * number <= quotient:
        if not quotient % number:
            d1 = number
            d2 = quotient // number
            if d2 - d1 == 1:
                is_beehive = True
                break
        number += 1
    return "Y" if is_beehive else "N"

def main():
    while True:
        n = int(input().rstrip())
        if n == -1:
            break
        print("{0}".format("Y" if n == 1 else check_beehive_number(n)))

if __name__ == "__main__":
    main()
