"""
Problem Statement: https://codeforces.com/contest/266/problem/B
Author: striker
"""

def transform_queue(initial_queue: list, t: int) -> str:
    for time in range(t):
        index = 1
        while index < len(initial_queue):
            if initial_queue[index] == 'G' and initial_queue[index - 1] == 'B':
                initial_queue[index], initial_queue[index - 1] = initial_queue[index - 1], initial_queue[index]
                index += 1
            index += 1
    return "".join(initial_queue)

def main():
    n, t = map(int, input().strip().split())
    initial_queue = input().strip()
    print(transform_queue(list(initial_queue), t))

if __name__ == "__main__":
    main()
