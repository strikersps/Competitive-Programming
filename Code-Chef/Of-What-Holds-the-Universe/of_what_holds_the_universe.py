'''
Problem Statement: https://www.codechef.com/SAPC2019/problems/SOPC010
Author: striker
'''

def conversion_to_base_3(n):
    n_base_3 = list()
    while n:
        n_base_3.append(n % 3)
        n = int(n / 3)
    return n_base_3[::-1]

def compute_total_numbers(n):
    n_base_3 = conversion_to_base_3(n)
    first_occurrence = False
    for index, data in enumerate(n_base_3):
        if not first_occurrence and n_base_3[index] == 2:
            first_occurrence = True
            n_base_3[index] = 1
        elif first_occurrence:
            n_base_3[index] = 1
    return int("".join(map(str, n_base_3)), 2)

def main():
    for test in range(int(input())):
        n = int(input())
        print(compute_total_numbers(n))

if __name__ == "__main__":
    main()
