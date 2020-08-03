"""
Problem Statement: https://cses.fi/problemset/task/1092
Author: striker
"""

def divide_into_two_sets(n: int, set_sum: int):
    s1 = set(); s2 = set()
    for number in range(n, 0, -1):
        if set_sum <= n and set_sum not in s1:
            s1.add(set_sum)
            break
        else:
            s1.add(number)
            set_sum -= number
    for number in range(1, n + 1):
        if number not in s1:
            s2.add(number)
    print(f'YES\n{len(s1)}\n{" ".join(map(str, s1))}\n{len(s2)}\n{" ".join(map(str, s2))}')

def main():
    n = int(input().strip())
    if ((n * (n + 1)) // 2) % 2:
        print("NO")
    else:
        divide_into_two_sets(n, (n * (n + 1)) // 4)

if __name__ == "__main__":
    main()
