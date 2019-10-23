'''
Problem Statement: https://www.hackerrank.com/challenges/strange-advertising/problem
Author: striker
'''

def main():
    no_of_days = int(input())
    recipient = 5
    no_of_people_liked = 0
    for _ in range(no_of_days):
        no_of_people_liked += (recipient >> 1)
        recipient = (recipient >> 1) * 3
    print(no_of_people_liked)

if __name__ == "__main__":
    main()