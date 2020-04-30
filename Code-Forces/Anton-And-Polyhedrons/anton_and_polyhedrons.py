"""
Problem Statement: https://codeforces.com/problemset/problem/785/A
Author: striker
"""

polyhedron_face_data = {"Tetrahedron": 4, "Cube": 6, "Octahedron": 8, "Dodecahedron": 12, "Icosahedron": 20}

def main():
    sum_of_faces = 0
    for _ in range(int(input().strip())):
        polyhedron_name = input().strip()
        sum_of_faces += polyhedron_face_data[polyhedron_name]
    print(sum_of_faces)

if __name__ == "__main__":
    main()
