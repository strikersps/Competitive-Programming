'''
Problem Statement: https://www.codechef.com/LRNDSA01/problems/LADDU
Author: striker
'''

def main():
    for test in range(int(input().strip())):
        tot_activities, origin = input().strip().split()
        tot_laddus = 0
        for activity in range(int(tot_activities)):
            read_data = input().strip().split()
            if read_data[0] == "CONTEST_WON":
                tot_laddus += 300
                if int(read_data[1]) <= 20:
                    tot_laddus += (20 - int(read_data[1]))
                continue
            if read_data[0] == "TOP_CONTRIBUTOR":
                tot_laddus += 300
                continue
            if read_data[0] == "BUG_FOUND":
                tot_laddus += int(read_data[1])
                continue
            if read_data[0] == "CONTEST_HOSTED":
                tot_laddus += 50
                continue
        print("{0}".format(tot_laddus // 200 if origin == "INDIAN" else tot_laddus // 400))

if __name__ == "__main__":
    main()
