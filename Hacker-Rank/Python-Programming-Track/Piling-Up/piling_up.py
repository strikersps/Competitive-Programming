"""
Problem Statement: https://www.hackerrank.com/challenges/piling-up/problem
Author: striker
"""

from collections import deque

def check_decreasing_order(positions: list) -> bool:
    return all(positions[index] >= positions[index + 1] for index in range(len(positions) - 1))

def play_game(cube_lengths: deque) -> list:
    positions = list()
    while cube_lengths:
        if len(cube_lengths) > 1:
            right_data, left_data = cube_lengths.pop(), cube_lengths.popleft()
            if left_data >= right_data:
                positions.append(left_data)
            else:
                positions.append(right_data)
        else:
            positions.append(cube_lengths.pop())
    return positions

def main():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        print("Yes" if check_decreasing_order(play_game(deque(map(int, input().strip().split())))) else "No")

if __name__ == "__main__":
    main()