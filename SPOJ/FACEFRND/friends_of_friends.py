'''
Problem Statement: https://www.spoj.com/problems/FACEFRND/
Author: striker
'''

def main():
    bob_friend = set()
    bob_friend_of_friend = set()
    for line in range(int(input().rstrip())):
        read_data = list(map(int, input().rstrip().split()))
        bob_friend.add(read_data[0])
        for person_id in read_data[2: :]:
            bob_friend_of_friend.add(person_id)

    print("{}".format(len(bob_friend_of_friend - bob_friend)))

if __name__ == "__main__":
    main()
