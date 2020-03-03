'''
Problem Statement: https://www.codechef.com/problems/POPGATES
Author: striker
'''

def compute_total_heads(coin_config, k):
    for operation in range(k):
        if coin_config[-1] == 'H':
            for index in range(len(coin_config) - 1):
                if coin_config[index] == 'H':
                    coin_config[index] = 'T'
                else:
                    coin_config[index] = 'H'
        coin_config.pop()
    return coin_config.count('H')

def main():
    for test in range(int(input().rstrip())):
        n, k = tuple(map(int, input().rstrip().split()))
        print("{}".format(compute_total_heads(input().rstrip().split(), k)))

if __name__ == "__main__":
    main()
