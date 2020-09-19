"""
Problem Statement: Refer to the readme.md file.
Author: striker
"""

def summer_69(sequence: list) -> int:
    six_index = [index for index, num in enumerate(sequence) if num == 6]
    nine_index = [index for index, num in enumerate(sequence) if num == 9]
    sequence_sum = sum(sequence)
    for id1, id2 in zip(six_index, nine_index):
        sequence_sum -= sum(sequence[id1: id2 + 1])
    return sequence_sum

def main():
    for _ in range(int(input().strip())):
        print(summer_69(list(map(int, input().strip().split()))))

if __name__ == "__main__":
    main()