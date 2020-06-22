"""
Problem Statement: Refer to readme.md file.
Author: striker
"""

from collections import Counter

def check_anagram(string1, string2):
    return Counter(string1) == Counter(string2)

def main():
    for test in range(int(input().strip())):
        print("YES" if check_anagram(input().strip(), input().strip()) else "NO")

if __name__ == "__main__":
    main()
