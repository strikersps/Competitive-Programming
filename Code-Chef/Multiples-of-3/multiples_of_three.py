'''
Problem Statement: https://www.codechef.com/problems/MULTHREE
Author: striker
'''

def check_multiple_of_three(k, d0, d1):
    if k == 2:
        return not ((d0 + d1) % 3)
    sum_of_digits = d0 + d1 + ((d0 + d1) % 10)
    if k > 3:
        a = ((d0 + d1) << 1) % 10
        b = ((d0 + d1) << 2) % 10
        c = ((d0 + d1) << 3) % 10
        d = (6 * (d0 + d1)) % 10
        sum_of_digits += ((a + b + c + d) * ((k - 3) >> 2))
        if(k - 3) % 4 == 1:
            sum_of_digits += a
        elif (k - 3) % 4 == 2:
            sum_of_digits += (a + b)
        elif (k - 3) % 4 == 3:
            sum_of_digits += (a + b + c)
    return not sum_of_digits % 3

def main():
    for test in range(int(input().strip())):
        k, d0, d1 = tuple(map(int, input().strip().split()))
        print("{0}".format("YES" if check_multiple_of_three(k, d0, d1) else "NO"))

if __name__ == "__main__":
    main()
