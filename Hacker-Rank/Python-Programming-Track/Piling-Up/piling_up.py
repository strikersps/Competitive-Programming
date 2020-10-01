"""
Problem Statement: https://www.hackerrank.com/challenges/piling-up/problem
Author: striker
"""

def is_decreasing_order(sequence: list) -> bool:
    return all(sequence[index] >= sequence[index + 1] for index in range(len(sequence) - 1))

def check_stack_possible(cube_side_lengths: list) -> bool:
    stacked_cubes = list()
    start = 0; end = len(cube_side_lengths) - 1
    while(start <= end):
        if cube_side_lengths[start] > cube_side_lengths[end]:
            stacked_cubes.append(cube_side_lengths[start])
            start += 1
            continue
        stacked_cubes.append(cube_side_lengths[end])
        end -= 1
    return is_decreasing_order(stacked_cubes)

def main():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        print("Yes" if check_stack_possible(list(map(int, input().strip().split()))) else "No")

if __name__ == "__main__":
    main()