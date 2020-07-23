"""
Problem Statement: https://www.spoj.com/problems/CSUMQ/
Author: striker
"""

def execute_queuries(sequence: list, n: int):
    prefix_sum = [0] * n
    prefix_sum[0] = sequence[0]
    for index in range(1, n):
        prefix_sum[index] = prefix_sum[index - 1] + sequence[index]
    for _ in range(int(input().strip())):
        start_range, end_range = map(int, input().strip().split())
        print(prefix_sum[end_range] if not start_range else prefix_sum[end_range] - prefix_sum[start_range - 1])

def main():
    n = int(input().strip())
    sequence = list(map(int, input().strip().split()))
    execute_queuries(sequence, n)

if __name__ == "__main__":
    main()
