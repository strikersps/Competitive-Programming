'''
Problem Statement: https://www.codechef.com/problems/SLAB
Author: striker
'''

tax_slab = [[250000, 0, 0],
           [500000, 5, 12500],
           [750000, 10, 25000],
           [1000000, 15, 37500],
           [1250000, 20, 50000],
           [1500000, 25, 62500],
           [1500001, 30, 0]]

def compute_net_income(tot_income):
    tax_amt = 0
    for index, tax_info in enumerate(tax_slab):
        if tax_info[0] <= tot_income:
            tax_amt += tax_info[2]
            continue
        break
    tax_amt += ((tot_income - tax_slab[index - 1][0]) * (tax_slab[index][1] / 100))
    return int(tot_income - tax_amt)

def main():
    for test in range(int(input().rstrip())):
        print("{}".format(compute_net_income(int(input().rstrip()))))

if __name__ == "__main__":
    main()
