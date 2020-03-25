'''
Problem Statement: https://code.google.com/codejam/contest/32013/dashboard#s=p0&a=0
Author: striker
'''

def main():
    for test in range(1, 1 + int(input().rstrip())):
        tot_se = int(input().rstrip())
        search_engine = [input().rstrip() for _ in range(tot_se)]
        tot_query = int(input().rstrip())
        search_batch = set()
        switch_count = 0
        for _ in range(tot_query):
            search_query = input().rstrip()
            search_batch.add(search_query)
            if len(search_batch) == tot_se:
                switch_count += 1
                search_batch.clear()
                search_batch.add(search_query)
                continue
        print("Case #{0}: {1}".format(test, switch_count))

if __name__ == "__main__":
    main()
