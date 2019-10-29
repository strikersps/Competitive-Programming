'''
Problem Statement: https://leetcode.com/problems/defanging-an-ip-address/
Author: striker
'''

def defangIPaddr(address):
    defang_address = ['[.]' if data == '.' else data for data in address]
    return "".join(defang_address)

def main():
    address = list(input())
    print(defangIPaddr(address))

if __name__ == "__main__":
    main()