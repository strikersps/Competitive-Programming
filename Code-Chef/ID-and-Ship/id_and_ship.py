'''
Problem Statement: https://www.codechef.com/problems/FLOW010
Author: striker
'''

def main():
    data = {'B': 'BattleShip','C': 'Cruiser','D': 'Destroyer','F': 'Frigate'}
    for _ in range(int(input().strip())):
        data_id = input().strip().upper()
        if not data.get(data_id, ""):
            continue
        print(data[data_id])

if __name__ == "__main__":
    main()
