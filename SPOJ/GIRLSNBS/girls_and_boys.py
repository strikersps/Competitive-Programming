'''
Problem Statement: https://www.spoj.com/problems/GIRLSNBS/
Author: striker
'''

def main():
    while True:
        tot_boys, tot_girls = tuple(map(int, input().rstrip().split()))
        if tot_boys == -1 and tot_girls == -1:
            break
        if not tot_boys or not tot_girls:
            print("{0}".format(max(tot_boys, tot_girls)))
            continue
        if tot_boys == tot_girls:
            print("{0}".format("1"))
            continue
        print("{0}".format((tot_boys + tot_girls) // (min(tot_boys, tot_girls) + 1)))

if __name__ == "__main__":
    main()

