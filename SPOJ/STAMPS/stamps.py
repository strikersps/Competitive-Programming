'''
Problem Statement: https://www.spoj.com/problems/STAMPS/
Author: striker
'''

def main():
    for scenario in range(1, 1 + int(input().rstrip())):
        stamps_required, tot_friends = tuple(map(int, input().rstrip().split()))
        stamp_offered = list(map(int, input().rstrip().split()))
        stamp_offered.sort(reverse = True)
        if sum(stamp_offered) < stamps_required:
            print("Scenario #{0}:\n{1}".format(scenario, "impossible"))
            continue
        tot_stamp_offered = 0
        min_stamps_required = 0
        for stamp_count in stamp_offered:
            tot_stamp_offered += stamp_count
            min_stamps_required += 1
            if tot_stamp_offered >= stamps_required:
                break
        print("Scenario #{0}:\n{1}".format(scenario, min_stamps_required))

if __name__ == "__main__":
    main()
