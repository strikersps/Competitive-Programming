'''
Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler021/problem
Author: striker
'''

MAX_LIMIT = 10**5 + 1

def check_prime(number):
    if number == 2 or number == 3:
        return True
    if not number % 2 or not number % 3:
        return False
    itr = 5
    while itr * itr <= number:
        if not number % itr:
            return False
        itr += 1
    return True

def compute_divisor_sum(number):
    divisor_sum = 1
    itr = 2
    while itr * itr <= number:
        if not number % itr:
            divisor_sum += itr;
            if not int(number / itr) == itr:
                divisor_sum += int (number / itr)
        itr += 1
    return divisor_sum

def generate_amicable_number():
    amicable_number = set()
    for number in range(4, MAX_LIMIT):
        if check_prime(number) or number in amicable_number:
            continue
        d1 = compute_divisor_sum(number)
        if d1 <= number:
            continue
        if compute_divisor_sum(d1) == number:
            amicable_number.add(number)
            amicable_number.add(d1)
    return sorted(list(amicable_number))

def main():
    amicable_number = generate_amicable_number()
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        amicable_sum = 0
        for index, number in enumerate(amicable_number):
            if number > n:
                continue
            amicable_sum += number
        print("{}".format(amicable_sum))

if __name__ == "__main__":
    main()
