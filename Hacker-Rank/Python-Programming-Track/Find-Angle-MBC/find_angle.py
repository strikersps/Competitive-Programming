'''
Problem Statement: https://www.hackerrank.com/challenges/find-angle/problem
Author: striker
'''

import math

def main():
    side_ab = int(input().strip())
    side_bc = int(input().strip())
    print("{0}{1}".format(round(math.degrees(math.atan2(side_ab, side_bc))), chr(176)))

if __name__ == "__main__":
    main()