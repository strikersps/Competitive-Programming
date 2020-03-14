'''
Problem Statement: https://www.codechef.com/problems/CNOTE
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        required_page, have_page, chef_budget, tot_book_in_shop = tuple(map(int, input().rstrip().split()))
        found_book = False
        for book in range(tot_book_in_shop):
            tot_pages_in_book, cost_of_book = tuple(map(int, input().rstrip().split()))
            if cost_of_book <= chef_budget and tot_pages_in_book >= required_page - have_page:
                found_book = True
                continue
        print("{0}".format("LuckyChef" if found_book else "UnluckyChef"))

if __name__ == "__main__":
    main()
