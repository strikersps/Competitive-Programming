"""
Problem Statement: https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/modify-sequence/
Author: striker
"""

def check_is_possible(sequence: list, n: int) -> bool:
    if all(x == 0 for x in sequence):
        return True
    for index in range(n - 1):
        if sequence[index] == 0 or sequence[index] > sequence[index + 1]:
            break
        sequence[index + 1] -= sequence[index]
        sequence[index] = 0
    return all(x == 0 for x in sequence)

def main():
    n = int(input().strip())
    print("YES" if check_is_possible(list(map(int, input().strip().split())), n) else "NO")

if __name__ == "__main__":
    main()
