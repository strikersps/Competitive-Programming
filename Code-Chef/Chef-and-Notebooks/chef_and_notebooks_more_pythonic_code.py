'''
Problem Statement: https://www.codechef.com/problems/CNOTE
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        required_page, have_page, chef_budget, tot_book_in_shop = tuple(map(int, input().rstrip().split()))
        print(["UnluckyChef","LuckyChef"][any(price <= chef_budget and page >= required_page - have_page for page, price in [map(int, input().rstrip().split()) for _ in range(tot_book_in_shop)])])

if __name__ == "__main__":
    main()
