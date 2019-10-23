'''
Problem Statement: https://www.codechef.com/LTIME54/problems/SMRSTR/
Author: striker
'''

def compute_product(data):
    product = 1
    for i in range(len(data)):
        product *= data[i]
    return product

def main():
    test = int(input())
    for _ in range(test):
        n,q = tuple(map(int,input().split()))
        data = list(map(int,input().split()))
        query = list(map(int,input().split()))
        product = compute_product(data)
        for i in range(q):
            if query[i] < product:
                print(0, end = ' ')
            else:
                print(int(query[i]/product), end = ' ')
        print()

if __name__ == "__main__":
    main()