'''
Problem Statement: https://www.codechef.com/problems/FLOW010
Author: striker
'''

def main():
    data = {'B': 'BattleShip','C': 'Cruiser','D': 'Destroyer','F': 'Frigate'}
    for i in range(int(input())):
        data_id = input().upper()
        if data.get(data_id) == None:
            continue
        else:
            print(data[data_id])

if __name__ == "__main__":
    main()
