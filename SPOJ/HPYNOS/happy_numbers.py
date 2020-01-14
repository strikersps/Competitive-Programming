'''
Problem Statement: https://www.spoj.com/problems/HPYNOS/
Author: striker
'''

encountered_numbers = set()

def compute_digit_square_sum(number):
    return sum([int(digit)**2 for digit in number])

def check_happy_number(number):
    number_of_steps = 1
    digit_square_sum = compute_digit_square_sum(str(number))
    encountered_numbers.add(digit_square_sum)
    while 1 != digit_square_sum:
        number_of_steps += 1
        digit_square_sum = compute_digit_square_sum(str(digit_square_sum))
        if digit_square_sum in encountered_numbers:
            number_of_steps = -1
            break
        encountered_numbers.add(digit_square_sum)
    return number_of_steps

def main():
    n = input().rstrip()
    print("{}".format(check_happy_number(n)))

if __name__ == "__main__":
    main()
