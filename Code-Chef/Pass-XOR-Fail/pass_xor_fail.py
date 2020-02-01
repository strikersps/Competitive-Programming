'''
Problem Statement: https://www.codechef.com/HOCO2020/problems/HCODE01
Author: striker
'''

def main():
    number_base_10 = input().rstrip()
    remainder = int(number_base_10[-2:]) % 4
    if not remainder:
        print("{}".format(number_base_10))
    elif remainder == 1:
        print("{}".format("1"))
    elif remainder == 2:
        print("{}".format(1 + int(number_base_10)))
    else:
        print("{}".format("0"))

if __name__ == "__main__":
    main()
