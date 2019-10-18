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
        n,q = tuple(input().split())
        data = list()
        for i in (input().split()):
            data.append(int(i))
        query = list()
        for i in (input().split()):
            query.append(int(i))
        product = compute_product(data)
        for i in range(int(q)):
            if query[i] < product:
                print(0, end = ' ')
            else:
                print(int(query[i]/product), end = ' ')
        print()

if __name__ == "__main__":
    main()