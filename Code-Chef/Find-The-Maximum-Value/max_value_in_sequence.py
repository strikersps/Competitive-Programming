"""
Problem Statement: https://www.codechef.com/problems/LOSTMAX
Author: striker
"""

def main():
    for test in range(int(input().strip())):
        sequence = list(map(int, input().strip().split()))
        sequence.remove(len(sequence) - 1)
        print(max(sequence))

if __name__ == "__main__":
    main()
