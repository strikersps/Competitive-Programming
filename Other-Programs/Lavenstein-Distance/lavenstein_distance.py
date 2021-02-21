"""
Problem Statement: Implementation of Levenstein Edit Distance algorithm for the calculation of edit distance between two strings.
Cost associated with each operation:
Inserion: 1
Deletion: 1
Subsituition: 2
Author: striker
"""

def compute_edit_distance(source: str, target: str) -> int:
	print(f'Source String: {source}\nTarget String: {target}')
	n, m = len(source), len(target)
	operation_cost = {'Insertion': 1, 'Deletion': 1, 'Substitution': 2}
	edit_distance_matrix = [[0] * (m + 1) for _ in range(n + 1)]
	for row_index in range(n + 1):
		for col_index in range(m + 1):
			if not row_index or not col_index:
				edit_distance_matrix[row_index][col_index] = max(row_index, col_index)
				continue
			edit_distance_matrix[row_index][col_index] = min(edit_distance_matrix[row_index - 1][col_index] + operation_cost['Insertion'],
									   edit_distance_matrix[row_index][col_index - 1] + operation_cost['Deletion'],
									   edit_distance_matrix[row_index - 1][col_index - 1] + (operation_cost['Substitution'] if source[row_index - 1] != target[col_index - 1] else 0)
									  )
	return edit_distance_matrix[n][m]

def main():
	for _ in range(int(input().strip())):
		print(f'Edit Distance: {compute_edit_distance(input().strip().upper(), input().strip().upper())}')

if __name__ == "__main__":
	main()