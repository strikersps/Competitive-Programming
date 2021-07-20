# Problem Statement: https://www.hackerrank.com/challenges/pairs/problem
# Author: striker

def binary_search(sequence: list, start: int, end: int, search_data) -> int:
    found_data = False
    while start <= end:
        mid = (end - start) // 2 + start
        if sequence[mid] == search_data:
            found_data = True
            break
        elif sequence[mid] > search_data:
            end = mid - 1
        else:
            start = mid + 1
    return found_data

def count_pairs(sequence: list, n: int, k: int) -> int:
    pair_count = 0
    for curr_index in range(n - 1):
        if binary_search(sequence, curr_index + 1, n - 1, sequence[curr_index] + k):
            pair_count += 1
    return pair_count

def main():
    n, k = map(int, input().strip().split())
    sequence = map(int, input().strip().split())
    print(count_pairs(sorted(sequence), n, k))

if __name__ == "__main__":
    main()
