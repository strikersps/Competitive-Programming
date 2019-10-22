'''
Problem Statement: https://www.codechef.com/problems/AMR15A
Author: striker
'''

def main():
    n = int(input())
    total_soldiers = list(map(int,input().split()))
    even_count = odd_count = 0
    for _ in range(n):
        if total_soldiers[_] & 1:
            odd_count += 1
        else:
            even_count += 1
    if even_count > odd_count:
        print("READY FOR BATTLE")
    else:
        print("NOT READY")

if __name__ == "__main__":
    main()