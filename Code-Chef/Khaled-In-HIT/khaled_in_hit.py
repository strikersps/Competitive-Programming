'''
Problem Statement: https://www.codechef.com/problems/HIT
Author: striker
'''

def find_score_boundaries(scores):
    grp_tot = int(len(scores) / 4)
    scores = sorted(scores)
    if scores[grp_tot] == scores[grp_tot - 1] or scores[grp_tot << 1] == scores[(grp_tot << 1) - 1] or scores[3 * grp_tot] == scores[3 * grp_tot - 1]:
        print("-1")
    else:
        x = scores[grp_tot]
        y = scores[grp_tot << 1]
        z = scores[3 * grp_tot]
        print(x,y,z)

def main():
    test = int(input())
    for _ in range(test):
        tot_stu = int(input())
        scores = list(map(int,input().split()))
        find_score_boundaries(scores)

if __name__ == "__main__":
    main()