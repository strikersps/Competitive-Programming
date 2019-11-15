'''
Problem Statement: https://www.spoj.com/problems/AE1B/
Author: striker
'''

def compute_minimum_boxes(boxes,screws_needed):
    min_boxes = 0
    tot_screws = 0
    for screws in boxes:
        tot_screws += screws
        min_boxes += 1
        if tot_screws >= screws_needed:
            break

    if tot_screws >= screws_needed:
        return min_boxes
    else:
        return 0

def main():
    n,k,s = tuple(map(int,input().split()))
    boxes = list(map(int,input().split()))
    print(compute_minimum_boxes(sorted(boxes,reverse = True),(k * s)))


if __name__ == "__main__":
    main()