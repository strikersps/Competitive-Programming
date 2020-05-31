"""
Problem Statement: https://www.codechef.com/problems/LOSTWKND
Author: striker
"""

TOTAL_WEEKDAYS_HRS = 24 * 5

def main():
    for test in range(int(input().strip())):
        read_data = list(map(int, input().strip().split()))
        print("No" if sum([read_data[-1] * work_hr for work_hr in read_data[: len(read_data) - 1:]]) <= TOTAL_WEEKDAYS_HRS else "Yes")

if __name__ == "__main__":
    main()
