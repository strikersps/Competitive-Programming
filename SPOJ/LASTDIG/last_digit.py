"""
Problem Statement: https://www.spoj.com/problems/LASTDIG/
Author: striker
"""

def compute_last_digit(a, b, modulus):
	if a == 1:
		return a
	if b == 1:
		return a % modulus
	result = 1
	while b:
		if b & 1:
			result = (result * a) % modulus
		a = (a * a) % modulus
		b >>= 1
	return result

def main():
	for test in range(int(input().strip())):
		a, b = tuple(map(int, input().strip().split()))
		print(f"{compute_last_digit(a, b, 10)}")

if __name__ == "__main__":
	main()