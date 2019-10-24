def average(array):
    set_of_plant_heights = set(arr)
    return sum(set_of_plant_heights)/len(set_of_plant_heights)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)