"""
Problem Statement: https://www.codechef.com/ENCD2020/problems/ECAPR204
Author: striker
"""

from collections import Counter

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        frequency_distribution = Counter(sorted(list(map(int, input().strip().split()))))
        for key in frequency_distribution:
            print(f"{key}:{frequency_distribution[key]}")

if __name__ == "__main__":
    main()
