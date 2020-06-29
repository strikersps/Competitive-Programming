# Problem Description
You are given a 2-D matrix where each cell represents number of coins in that cell. Assuming we start at cell `matrix[0][0]`, and can only move right or down, find the maximum number of coins you can collect when you reach the botton right corner.

**For Example:**  
Given matrix:
```
0 3 1 1
2 0 0 4
1 5 3 1
```

The maximum coins we can collect is `0 + 2 + 1 + 5 + 3 + 1 = 12` coins.

**Input Format:**  
The first line consists of a single integer `T`, the number of test cases. In each of the test cases, the first line has two integers. The first integer `n` is the number of rows and second integer `m` is the number of columns. Next, there are `n` lines of inputs. The `i-th` line of these, specifies the number of coins in each cell of the `i-th` row. Each line has `m` integers, where each integer `m` is the number of coins in that cell. The integers are separated by a space character.  

**Output Format:**  
The output should consist of `T` lines, one for each test case. Each line consists of a single integer, which is the maximum possible number of coins you can collect in one single trip from the `matrix[0][0]` to the bottom right-corner cell of the given matrix in the testcase.  

**Example:**  
**Input**  
```
3
3 3
9 1 8
4 2 3
5 6 7
3 3
2 6 4
3 1 5
8 7 9
3 3
7 8 9
3 5 1
2 4 6
```
**Output**  
```
31
29
31
```  
