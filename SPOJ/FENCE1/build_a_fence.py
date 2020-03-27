'''
Problem Statement: https://www.spoj.com/problems/FENCE1/
Author: striker
'''

PI = 3.141592653589793 # Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.

def main():
    while True:
        l = int(input().rstrip())
        if not l:
            break
        print("{0:0.2f}".format((l * l) / (2 * PI)))

if __name__ == "__main__":
    main()
