'''
Problem Statement: Refer the readme.md file.
Author: striker
'''

def tranformed_list(data):
    left_list = list()
    right_list = list()
    product = 1
    for d in data:
        product *= d
        left_list.append(product)
    product = 1
    for d in data[::-1]:
        product *= d
        right_list.append(product)
    right_list.reverse()
    result_list = list()
    for i in range(len(data)):
        if not i:
            result_list.append(right_list[i + 1])
        elif i == len(data) - 1:
            result_list.append(left_list[i - 1])
        else:
            result_list.append(left_list[i - 1] * right_list[i + 1])
    return result_list

def main():
    print(tranformed_list(list(map(int,input().split()))))

if __name__ == "__main__":
    main()