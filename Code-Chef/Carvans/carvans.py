'''
Problem Statement: https://www.codechef.com/LRNDSA01/problems/CARVANS
Author: striker
'''

def compute_total_cars(car_speed):
    """
    Function calculates how many cars are running at maximum speed.
    """
    car_count = 1
    for i in range(1, len(car_speed)):
        if car_speed[i] > car_speed[i - 1]:
            car_speed[i] = car_speed[i - 1]
            continue
        car_count += 1
    return car_count

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print("{0}".format(compute_total_cars(list(map(int, input().strip().split())))))

if __name__ == "__main__":
    main()
