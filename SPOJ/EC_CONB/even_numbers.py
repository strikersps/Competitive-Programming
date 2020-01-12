'''
Problem Statement: https://www.spoj.com/problems/EC_CONB/
Author: striker
'''
def update_number(n):
    reverse_number = 0
    while n:
        reverse_number = (reverse_number << 1) | (n & 1)
        n >>= 1
    return reverse_number

def main():
    for _ in range(int(input())):
        number = int(input())
        if not number % 2:
            print("{}".format(update_number(number)))
            continue
        print("{}".format(number))

if __name__ == "__main__":
    main()
