# Problem Description
Given a list of pairs where each pair contains a food item and its price, 
For Ex: `(apple, 120), (banana,200) . . .` and so on.
Specific food item may occur multiple times, For Ex: `(apple,200), (apple,280) . . .` so on.
For each food item output the lowest, highest and average price(rounded down to nearest integer) for that item. The output list should be lexicographically (alphabetically) sorted by name of food.

**Input:**
First line contains one integer `T` i.e. no of test cases.
Second line contains one integer `N` i.e. no of pair of fruits
Next N line contains pair of fruits.

**Output:**
Output of result should be in following format:  
`case #i:` where `i` is the index of text case, starting from `1`. Then for each test case output is one line format: food item, its lowest price, its highest price, its average price and output list of food items must be sorted item name in lexicographically order.

```
Sample Input:
3
3
banana 90
apple 100
apple 260
5
grapefruit 120
grape 200
grapefruit 150
grapefruit 150
grape 180
2
apple 100
apple 101
Sample Output

Case #1:
apple 100 260 180
banana 90 90 90
Case #2:
grape 180 200 190
grapefruit 120 150 140
Case #3:
apple 100 101 100
