'''
Problem Statement: https://www.codechef.com/problems/HS08TEST
Author: striker
'''

BANK_CHARGES = 0.50

def main():
    withdrawl_amt, curr_balance = tuple(map(float, input().rstrip().split()))
    if not (int(withdrawl_amt) % 5) and curr_balance >= (withdrawl_amt + BANK_CHARGES):
        print("%0.2f"%(curr_balance - (withdrawl_amt + BANK_CHARGES)))
    else:
        print("%0.2f"%curr_balance)

if __name__ == "__main__":
    main()
