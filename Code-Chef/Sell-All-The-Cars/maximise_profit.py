'''
Problem Statement: https://www.codechef.com/APRIL20B/problems/CARSELL
Author: striker
'''

MOD = 10**9 + 7

def compute_maximum_profit(car_price):
    """
    Function computes maximum profit Chef can make if he sells his cars in an optimal way.
    """
    max_profit = 0
    for index, price in enumerate(car_price):
        if price - index > 0:
            price -= index
            max_profit = (max_profit + price) % MOD
            continue
    return max_profit

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print(f"{compute_maximum_profit(sorted(list(map(int, input().strip().split())), reverse = True))}")

if __name__ == "__main__":
    main()
