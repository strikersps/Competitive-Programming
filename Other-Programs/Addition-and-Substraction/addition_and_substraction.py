'''
Problem Description: Refer to the readme.md.
Author: striker
'''

def main():
    x, y, z = tuple(map(int, input().rstrip().split()))
    found_index = -1
    if not z:
        found_index = 0
    else:
        if x == y:
            if x == z or y == z:
                found_index = 1
            else:
                found_index = -1
        else:
            i = 1
            prev_val = 0
            while True:
                if not i % 2:
                    prev_val -= y
                else:
                    prev_val += x
                if prev_val == z:
                    found_index = i
                    break
                elif prev_val > z and prev_val - y > z:
                    found_index = -1
                    break
                i += 1
    print("{}".format(found_index))

if __name__ == "__main__":
    main()
