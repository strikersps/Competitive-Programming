"""
Problem Statement: Compute the gcd of two integers a and b.
Author: striker
"""

def compute_gcd(a: int, b: int) -> int:
    return a if not b else compute_gcd(b, a % b)

def main():
    for _ in range(int(input().strip())):
        print(compute_gcd(*map(int, input().strip().split())))

if __name__ == "__main__":
    main()
        
