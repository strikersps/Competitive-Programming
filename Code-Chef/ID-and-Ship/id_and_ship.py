'''
Problem Statement: https://www.codechef.com/problems/FLOW010
Author: striker
'''

def main():
    test = int(input())
    data = {'B': 'BattleShip','C':'Cruiser','D':'Destroyer','F':'Frigate'}
    for i in range(test):
        id = input().upper()
        if data.get(id) == None:
            continue
        else:
            print(data[id])

if __name__ == "__main__":
    main()
