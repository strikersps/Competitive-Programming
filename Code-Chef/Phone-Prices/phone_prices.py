'''
Problem Statement: https://www.codechef.com/problems/S10E
Author: striker
'''

def compute_number_of_days(n, phone_price):
    day_count = 0
    for i in range(n):
        is_price_good = True
        start_range = i - 5 if i > 5 else 0
        for j in range(start_range, i):
            if phone_price[j] <= phone_price[i]:
                is_price_good = False
                break
        if is_price_good:
            day_count += 1
    return day_count

def main():
    for test in range(int(input().strip())):
        print("{0}".format(compute_number_of_days(int(input().strip()), list(map(int, input().strip().split())))))

if __name__ == "__main__":
    main()
