"""
	Problem Statement: https://www.hackerrank.com/challenges/ctci-big-o/problem
	Author: striker
"""

import math

def check_prime(number: int) -> bool:
	if number == 2 or number == 3:
		return True
	if number == 1 or not number % 2 or not number % 3:
		return False
	return not any(not number % d for d in range(2, 1 + int(math.sqrt(number))))

def main():
	for _ in range(int(input().strip())):
		print("Prime" if check_prime(int(input().strip())) else "Not prime")

if __name__ == "__main__":
	main()