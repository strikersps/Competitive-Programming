"""
	Problem Statement: https://www.hackerrank.com/challenges/ctci-big-o/problem
	Author: striker
	NOTE: One line solution to check whether the given number is prime or not using lambda functions.
"""

import math

def main():
	check_prime = lambda number: False if number == 1 else not any(not number % d for d in range(2, 1 + int(math.sqrt(number))))
	for _ in range(int(input().strip())):
		print("Prime" if check_prime(int(input().strip())) else "Not prime")

if __name__ == "__main__":
	main()