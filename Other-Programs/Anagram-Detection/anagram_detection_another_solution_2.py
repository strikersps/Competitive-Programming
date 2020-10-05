"""
Problem Statement: Refer to readme.md file.
Author: striker
"""

from functools import reduce
from operator import mul

def check_anagram(string1, string2):
    """
    NOTE: The following solution only works if the given two strings are made of valid lowercase english alphabets.
    """
    prime_numbers = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
    get_prime_product = lambda string: reduce(mul, [prime_numbers[ord(character) - 97] for character in string], 1)
    return get_prime_product(string1) == get_prime_product(string2)

def main():
    for _ in range(int(input().strip())):
        print("YES" if check_anagram(input().strip().replace(" ", "").lower(), input().strip().replace(" ", "").lower()) else "NO")

if __name__ == "__main__":
    main()
