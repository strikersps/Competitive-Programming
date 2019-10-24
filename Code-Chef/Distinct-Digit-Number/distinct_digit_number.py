'''
Problem Statement: https://www.codechef.com/HCS12019/problems/SETH0006
Author: striker
'''

def is_distinct_digits(number):
    freq_digits = [False] * 10
    while number:
        if freq_digits[number % 10]:
            return False
        freq_digits[number % 10] = True
        number = int(number / 10)
    return True

def main():
    start,end = tuple(map(int,input().split()))
    assert(start <= end)
    while start <= end:
        if is_distinct_digits(start):
            print(start)
            break
        start += 1
    if start > end:
        print("-1")

if __name__ == "__main__":
    main()