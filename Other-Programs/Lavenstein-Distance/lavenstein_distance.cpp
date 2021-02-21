/* * Problem Statement: Implementation of Lavenstein Edit Distance Algorithm using Dynamic Programming.
	* Cost of Operation: Insertion = 1, Deletion = 1, Subtitution = 2
	* Author: striker
*/

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>

#define FAST_IO(return_val) std :: ios :: sync_with_stdio(return_val)
#define NEW_LINE '\n'

static size_t compute_edit_distance(const std :: string &, const std :: string &);
static void to_uppercase(std :: string &);

int main(void) {
	FAST_IO(0);
	int test;
	std :: cin >> test;
	while(test--) {
		std :: string source, target;
		std :: cin >> source >> target;
		to_uppercase(source); to_uppercase(target);
		std :: cout << "Source String: " << source << NEW_LINE << "Target String: " << target << NEW_LINE;
		std :: cout << "Edit Distance: " << compute_edit_distance(source, target) << NEW_LINE;
	}
	return EXIT_SUCCESS;
}

static void to_uppercase(std :: string & string_data) {
	for(auto & curr_char: string_data) {
		curr_char = (char) toupper(curr_char);
	}
}

static size_t compute_edit_distance(const std :: string & source, const std :: string & target) {
	size_t source_size = source.size(), target_size = target.size();
	std :: map <std :: string, size_t> operation_cost;
	operation_cost["Insertion"] = 1; operation_cost["Deletion"] = 1; operation_cost["Subtitution"] = 2;
	std :: vector <std :: vector <size_t>> edit_distance(source_size + 1, std :: vector <size_t> (target_size + 1, 0UL));
	for(size_t i = 0; i <= source_size; ++i) {
		for(size_t j = 0; j <= target_size; ++j) {
			if(!i || !j) {
				edit_distance[i][j] = std :: max(i, j);
				continue;
			}
			edit_distance[i][j] = std :: min(std :: min(edit_distance[i - 1][j] + operation_cost["Insertion"], 
											 edit_distance[i][j - 1] + operation_cost["Deletion"]), 
											 edit_distance[i - 1][j - 1] + (source[i - 1] != target[j - 1] ? operation_cost["Subtitution"] : 0UL));
		}
	}
	return edit_distance[source_size][target_size];
}