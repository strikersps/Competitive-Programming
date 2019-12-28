'''
Problem Statement: https://codeforces.com/problemset/problem/1279/A
Author: striker
'''

def is_garland_possible(red_count, green_count, blue_count):
    if red_count - (green_count + blue_count) > 1 or green_count - (red_count + blue_count) > 1 or blue_count - (red_count + green_count) > 1:
        return False
    return True

def main():
    for test in range(int(input())):
        red_count, green_count, blue_count = tuple(map(int, input().rstrip().split()))
        if is_garland_possible(red_count, green_count, blue_count):
            print("Yes")
        else:
            print("No")

if __name__ == "__main__":
    main()
