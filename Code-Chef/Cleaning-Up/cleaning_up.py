'''
Problem Statement: https://www.codechef.com/problems/CLEANUP/
Author: striker
'''

def compute_the_assigned_jobs(jobs_set,jobs_completed_set):
    jobs_uncompleted_set = jobs_set - jobs_completed_set
    jobs_uncompleted_set = sorted(list(jobs_uncompleted_set))
    print(' '.join(map(str,jobs_uncompleted_set[0::2])))
    print(' '.join(map(str,jobs_uncompleted_set[1::2])))

def main():
    for t in range(int(input().rstrip())):
        n, m = tuple(map(int,input().rstrip().split()))
        jobs_completed_set = set(map(int,input().rstrip().split()))
        jobs_set = set([i for i in range(1,n + 1)])
        compute_the_assigned_jobs(jobs_set,jobs_completed_set)

if __name__ == "__main__":
    main()

