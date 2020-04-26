"""
Problem Statement: https://www.codechef.com/ENCD2020/problems/ECAPR203
Author: striker
"""

import math

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        tinv = (1 + int(math.sqrt(1 + 8 * n))) // 2
        print(n - ((tinv * (tinv - 1)) // 2))

if __name__ == "__main__":
    main()
