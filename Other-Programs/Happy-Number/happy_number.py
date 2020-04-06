'''
Problem Statement: Refer to the readme.md file.
Author: striker
'''

def compute_digit_square_sum(n):
    digit_square_sum = 0
    while n:
        last_digit = n % 10
        digit_square_sum += (last_digit * last_digit)
        n //= 10
    return digit_square_sum

def check_happy_number(n):
    visited_numbers = set()
    is_happy = True
    while True:
        n = compute_digit_square_sum(n)
        if n == 1:
            break
        if n in visited_numbers:
            is_happy = False
            break
        visited_numbers.add(n)
    return is_happy

def main():
    for test in range(int(input().strip())):
        print(f"{'YES' if check_happy_number(int(input().strip())) else 'NO'}")

if __name__ == "__main__":
    main()
