'''
Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler019/problem
Author: striker
'''

months = {1 : "JAN", 2: "FEB", 3 : "MARCH", 4 : "APRIL", 5 : "MAY", 6 : "JUNE", 7 : "JULY", 8 : "AUG", 9 : "SEPT", 10 : "OCT", 11 : "NOV", 12 : "DEC"}
week_days = {"Saturday" : 0, "Sunday" : 1, "Monday" : 2, "Tuesday" : 3, "Wednesday" : 4, "Thursday" : 5, "Friday" : 6}
month_codes = {"JAN" : 13, "FEB" : 14, "MARCH" : 3, "APRIL" : 4, "MAY" : 5, "JUNE" : 6, "JULY" : 7, "AUG" : 8, "SEPT" : 9, "OCT" : 10, "NOV" : 11, "DEC" : 12}

def compute_day_of_week(year, month, day):
    if month == 1 or month == 2:
        year -= 1
    year_code = year % 100
    century_code = year // 100
    month_code = month_codes[months[month]]
    day_of_week = (day + ((13 * (month_code + 1)) // 5) + year_code + (year_code >> 2) + (century_code >> 2) + (5 * century_code)) % 7
    return day_of_week

def compute_number_of_sundays(start_date, end_date):
    count_sunday = 0
    if start_date[0] == end_date[0]:
        for month in range(start_date[1], end_date[1] + 1):
            if compute_day_of_week(start_date[0], month, 1) == week_days["Sunday"]:
                count_sunday += 1
    else:
        if start_date[2] == 1 and compute_day_of_week(start_date[0], start_date[1], 1) == week_days["Sunday"]:
            count_sunday += 1
        for month in range(start_date[1] + 1, 13):
            if compute_day_of_week(start_date[0], month, 1) == week_days["Sunday"]:
                count_sunday += 1
        for month in range(1, end_date[1] + 1):
            if compute_day_of_week(end_date[0], month, 1) == week_days["Sunday"]:
                count_sunday += 1
        for year in range(start_date[0] + 1, end_date[0]):
            for month in range(1, 13):
                if compute_day_of_week(year, month, 1) == week_days["Sunday"]:
                    count_sunday += 1
    return count_sunday

def main():
    for test in range(int(input().rstrip())):
        start_date = list(map(int, input().rstrip().split()))
        end_date = list(map(int, input().rstrip().split()))
        if start_date[0] > end_date[0] or start_date[0] == end_date[0] and start_date[1] > end_date[1] or start_date[0] == end_date[0] and start_date[1] == end_date[1] and start_date[2] > end_date[2]:
            print("{}".format("0"))
            continue
        print("{}".format(compute_number_of_sundays(start_date, end_date)))

if __name__ == "__main__":
    main()
