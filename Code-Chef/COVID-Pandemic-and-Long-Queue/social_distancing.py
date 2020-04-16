"""
Problem Statement: https://www.codechef.com/problems/COVIDLQ
Author: striker
"""

def check_rules_followed(people_line):
    is_rules_followed = True
    last_person_index = -1
    for position, person in enumerate(people_line):
        if last_person_index == -1 and person == 1:
            last_person_index = position
            continue
        if last_person_index > -1 and person == 1:
            if position - last_person_index >= 6:
                last_person_index = position
            else:
                is_rules_followed = False
                break
    return is_rules_followed

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print("YES" if check_rules_followed(list(map(int, input().strip().split()))) else "NO")

if __name__ == "__main__":
    main()
