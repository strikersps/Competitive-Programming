# Editorial for [Triangle Quest 2](https://www.hackerrank.com/challenges/triangle-quest-2/problem)

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

and  

1 * 1 = 1  
11 * 11 = 121  
111 * 111 = 12321  
1111 * 1111 = 1234321  
11111 * 111111 = 123454321  
111111 * 111111 = 12345654321  
1111111 * 1111111 = 1234567654321  
11111111 * 11111111 = 123456787654321  
111111111 * 111111111 = 12345678987654321  
1111111111 * 1111111111 = 12345678910987654321  

Thats why the following code will generate the pattern asked in the problem statement.  
```python
for line in range(1, 1 + int(input())):
    print((10**line // 9)**2)
```