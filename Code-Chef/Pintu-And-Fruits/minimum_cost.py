'''
Problem Statement: https://www.codechef.com/MARCH20B/problems/CHPINTU
Author: striker
'''

TOTAL_FRUIT_TYPE = 50

def main():
    for test in range(int(input().rstrip())):
        n, m = tuple(map(int, input().rstrip().split()))
        basket_config = list(map(int, input().rstrip().split()))
        basket_price = list(map(int, input().rstrip().split()))
        basket_type_tot_price = [-1] * TOTAL_FRUIT_TYPE
        for index, fruit_type in enumerate(basket_config):
            if -1 == basket_type_tot_price[fruit_type - 1]:
                basket_type_tot_price[fruit_type - 1] = 0
            basket_type_tot_price[fruit_type - 1] += basket_price[index]
        min_value = 10**2
        for index in range(TOTAL_FRUIT_TYPE):
            if -1 != basket_type_tot_price[index] and basket_type_tot_price[index] < min_value:
                min_value = basket_type_tot_price[index]
                continue
        print("{}".format(min_value))

if __name__ == "__main__":
    main()
