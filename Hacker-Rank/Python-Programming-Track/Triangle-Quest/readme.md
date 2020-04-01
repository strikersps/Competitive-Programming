# Editorial for [Triangle Quest](https://www.hackerrank.com/challenges/python-quest-1/problem)  

The solution for the problem is based on the fact that:  
10 / 9 = 1  
100 / 9 = 11  
1000 / 9 = 111  
10000 / 9 = 1111  
100000 / 9 = 11111  
1000000 / 9 = 111111  
10000000 / 9 = 1111111  
100000000 / 9 = 11111111  
1000000000 / 9 = 111111111  
10000000000 / 9 = 1111111111  

Using the loop, we iterate over line number from [1, n - 1], and for every line we print `line * ((10 ^ line) / 9)`.  
