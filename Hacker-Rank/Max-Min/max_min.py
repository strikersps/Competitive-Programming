# Problem Statement: https://www.hackerrank.com/challenges/angry-children/problem
# Author: striker

def compute_min_fairness(sequence: list, k: int) -> int:
    return min([sequence[curr_index + k - 1] - sequence[curr_index] for curr_index in range(len(sequence) - k + 1)])

def main():
    n, k = int(input().strip()), int(input().strip())
    sequence = [int(input().strip()) for _ in range(n)]
    print(compute_min_fairness(sorted(sequence), k))

if __name__ == "__main__":
    main()
