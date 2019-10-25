'''
Problem Statement: https://www.codechef.com/problems/ICPC16A
Author: striker
'''

def main():
    test = int(input())
    for _ in range(test):
        src_x,src_y,dst_x,dst_y = tuple(map(int,input().split()))
        if src_x == dst_x:
            if dst_y > src_y:
                print("up")
            else:
                print("down")
        elif src_y == dst_y:
            if dst_x > src_x:
                print("right")
            else:
                print("left")
        else:
            print("sad")

if __name__ == "__main__":
    main()