'''
Problem Statement: https://www.codechef.com/problems/FLOW005
Author: striker
'''

def total_number_of_notes(money_rs):
    number_of_notes = 0
    while money_rs != 0:
        if money_rs >= 100:
            number_of_notes += int(money_rs / 100)
            money_rs %= 100
        elif money_rs >= 50:
            number_of_notes += int(money_rs / 50)
            money_rs %= 50
        elif money_rs >= 10:
            number_of_notes += int(money_rs / 10)
            money_rs %= 10
        elif money_rs >= 5:
            number_of_notes += int(money_rs / 5)
            money_rs %= 5
        elif money_rs >= 2:
            number_of_notes += int(money_rs / 2)
            money_rs %= 2
        else:
            number_of_notes += money_rs
            money_rs = 0
    return number_of_notes

def main():
    test = int(input())
    for _ in range(test):
        money_rs = int(input())
        print(str(total_number_of_notes(money_rs)))

if __name__ == "__main__":
    main()