'''
Problem Statement: https://www.codechef.com/problems/WALKFAST
Author: striker
'''

MAX_LIMIT = 10**6

def main():
    for test in range(int(input().rstrip())):
        n, a, b, c, d, p, q, y = tuple(map(int, input().rstrip().split()))
        city_coordinate = list(map(int, input().rstrip().split()))
        walk_time = abs(city_coordinate[b - 1] - city_coordinate[a - 1]) * p
        train_time = MAX_LIMIT
        if abs(city_coordinate[c - 1] - city_coordinate[a - 1]) * p <= y:
            train_time = y + abs(city_coordinate[d - 1] - city_coordinate[c - 1]) * q + abs(city_coordinate[d - 1] - city_coordinate[b - 1]) * p
        print("{}".format(min(walk_time, train_time)))

if __name__ == "__main__":
    main()
