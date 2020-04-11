"""
Problem Statement: Refer to the readme.md file
Author: striker
"""

def rearrange_zeroes(sequence):
    """
    The function appends all the zeros present in the sequence at the end.
    """
    zero_count = 0
    while True:
        try:
            sequence.remove(0)
            zero_count += 1
        except ValueError:
            break
    sequence.extend([0] * zero_count)
    return " ".join(map(str, sequence))

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print(f"{rearrange_zeroes(list(map(int, input().strip().split())))}")

if __name__ == "__main__":
    main()
