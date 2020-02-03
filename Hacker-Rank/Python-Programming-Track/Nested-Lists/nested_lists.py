'''
Problem Statement: https://www.hackerrank.com/challenges/nested-list/problem
Author: striker
'''

def main():
    student_record = [[input().rstrip(), float(input().rstrip())] for _ in range(int(input().rstrip()))]
    second_min_marks = sorted(list(set([student_marks for student_name, student_marks in student_record])))[1]
    print("{}".format("\n".join(sorted([student_name for student_name, student_marks in student_record if student_marks == second_min_marks]))))

if __name__ == "__main__":
    main()
