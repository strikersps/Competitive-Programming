'''
Problem Statement: https://www.codechef.com/ZCOPRAC/problems/ZCO14001
Author: striker
'''

def main():
    number_of_boxes, max_height = tuple(map(int, input().rstrip().split()))
    box_config = list(map(int, input().rstrip().split()))
    crane_commands = list(map(int, input().rstrip().split()))
    crane_position = 0
    is_crane_empty = True
    for curr_crane_command in crane_commands:
        if curr_crane_command == 1:
            if not crane_position:
                continue
            else:
                crane_position -= 1
        elif curr_crane_command == 2:
            if crane_position == number_of_boxes - 1:
                continue
            else:
                crane_position += 1
        elif curr_crane_command == 3:
            if is_crane_empty and box_config[crane_position]:
                is_crane_empty = False
                box_config[crane_position] = box_config[crane_position] - 1
        elif curr_crane_command == 4:
            if not is_crane_empty and box_config[crane_position] < max_height:
                is_crane_empty = True
                box_config[crane_position] = box_config[crane_position] + 1
        else:
            break
    print(' '.join(map(str, box_config)))


if __name__ == "__main__":
    main()
