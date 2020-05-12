"""
Problem Statement: https://www.codechef.com/problems/ZCOSCH
Author: striker
"""

def main():
    rank = int(input().strip())
    print(100 if rank >= 1 and rank <= 50 else 50 if rank >= 51 and rank <= 100 else 0)

if __name__ == "__main__":
    main()
