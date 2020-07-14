"""
Problem Statement: https://codeforces.com/contest/268/problem/A
Author: striker
"""

from collections import defaultdict

def compute_color_conflicts(n: int) -> int:
    freq_map_home = defaultdict(int)
    freq_map_away = defaultdict(int)
    for _ in range(n):
        home_color, away_color = map(int, input().strip().split())
        freq_map_home[home_color] += 1
        freq_map_away[away_color] += 1
    conflict_count = 0
    for key, value in freq_map_home.items():
        conflict_count += (value * freq_map_away[key])
    return conflict_count

def main():
    print(compute_color_conflicts(int(input().strip())))

if __name__ == "__main__":
    main()
