"""
Problem Statement: Refer to the readme.md file.
Author: striker
"""

MAX_LIMIT = 10**6 + 1

from collections import defaultdict

def compute_smallest_prime_factors()->list:
	prime_numbers = [True] * MAX_LIMIT
	smallest_prime_factors = [0] * MAX_LIMIT
	prime_numbers[0] = prime_numbers[1] = False
	for i in range(2, MAX_LIMIT):
		if prime_numbers[i]:
			smallest_prime_factors[i] = i
			for j in range(i*i, MAX_LIMIT, i):
				prime_numbers[j] = False
				smallest_prime_factors[j] = i
	return smallest_prime_factors

def compute_prime_factors(number: int, smallest_prime_factors: list) -> defaultdict:
	prime_factorisation = defaultdict(int)
	while smallest_prime_factors[number]:
		prime_factorisation[smallest_prime_factors[number]] += 1
		number //= smallest_prime_factors[number]
	return prime_factorisation

def main():
	smallest_prime_factors = compute_smallest_prime_factors()
	for test in range(int(input().strip())):
		prime_factorisation = compute_prime_factors(int(input().strip()), smallest_prime_factors)
		"""
		By default dictionaries in python are unordered.
		"""
		for key, value in prime_factorisation.items():
			print("{}^{}".format(key, value), end = ' ')
		print()

if __name__ == "__main__":
	main()
