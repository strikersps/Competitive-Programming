'''
Problem Statement: https://leetcode.com/problems/defanging-an-ip-address/
Author: striker
'''

def defangIPaddr(address):
    return "".join(['[.]' if data == '.' else data for data in address])

def main():
    print(defangIPaddr(list(input().rstrip())))

if __name__ == "__main__":
    main()
