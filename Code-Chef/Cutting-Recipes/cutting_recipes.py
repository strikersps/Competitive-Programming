'''
Problem Statement: https://www.codechef.com/problems/RECIPE
Author: striker
'''

def compute_gcd(a,b):
    if b == 0:
        return a
    else:
        return compute_gcd(b,(a % b))

def main():
    test = int(input())
    for _ in range(test):
        ingredient_qty = list(map(int,input().split()))
        ingredient_qty.pop(0)
        for index in range(len(ingredient_qty)):
            if index == 0:
                gcd_val = ingredient_qty[index]
            else:
                gcd_val = compute_gcd(gcd_val,ingredient_qty[index])
        for index in range(len(ingredient_qty)):
            ingredient_qty[index] = int(ingredient_qty[index] / gcd_val)
        print(" ".join(list(map(str,ingredient_qty))))

if __name__ == "__main__":
    main()