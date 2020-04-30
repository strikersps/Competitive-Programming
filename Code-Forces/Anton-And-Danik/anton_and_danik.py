"""
Problem Statement: https://codeforces.com/problemset/problem/734/A
Author: striker
"""

def main():
    n = int(input().strip())
    game_result = input().strip()
    count_A = game_result.count('A')
    count_B = game_result.count('D')
    print("Friendship" if count_A == count_B else "Anton" if count_A > count_B else "Danik")

if __name__ == "__main__":
    main()
