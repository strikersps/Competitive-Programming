"""
Problem Statement: Refer to the readme.md file.
Author: striker
"""

def summer_69(sequence: list) -> int:
    sequence_sum = 0
    six_found = False
    for number in sequence:
        if number == 6:
            six_found = True
            continue
        if number == 9:
            six_found = False
            continue
        if not six_found:
            sequence_sum += number
    return sequence_sum

def main():
    for _ in range(int(input().strip())):
        print(summer_69(list(map(int, input().strip().split()))))

if __name__ == "__main__":
    main()