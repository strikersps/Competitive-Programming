'''
Problem Statement: https://codeforces.com/contest/1249/problem/A
Author: striker
'''

def main():
    queries = int(input())
    for _ in range(queries):
        total_students = int(input())
        students = list(map(int,input().split()))
        if total_students == 1:
            print("1")
        else:
            students.sort()
            if total_students == 2:
                if students[1] - students[0] == 1:
                    print("2")
                else:
                    print("1")
            else:
                is_pair_exist = False
                for i in range(len(students) - 1):
                    if students[i + 1] - students[i] == 1:
                        is_pair_exist = True
                        break
                if is_pair_exist:
                    print("2")
                else:
                    print("1")

if __name__ == "__main__":
    main()