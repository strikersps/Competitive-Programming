# Editorial [Jumbling Nuisance](https://www.codechef.com/ICHN2019/problems/ICHN03) on Code-Chef.  

#### Problem Statement:  
Given a word of length `n`, in how many ways you can arrange the letters of the word so that no letter should end up at it's actual position.  

#### Solution:  
To solve this problem first analyse what will be the answer for smaller cases.

For `n = 1`: ans = 0.  
For `n = 2`: ans = 1.  
For `n = 3`: ans = 2.  
For `n = 4`: ans = 9.  
For `n = 5`: ans = 44.  
... So on.  

If you observe carefully, you will see that you have sequence of numbers for each `n` value i.e.  
| n-values | No. of Ways |
| ---      | ---       |
| 1 | 1 |
| 2 | 1 |
| 3 | 2 |
| 4 | 9 |
| 5 | 44 |
| . | . |
| . | . |
| . | . |
| n | x |  

If you look at the **No.of Ways** column you will see a pattern i.e.  

```
    if (n & 1):
        ans = (ans[n - 1] * n) - 1 // If n is even
    else:
        ans = (ans[n - 1] * n) + 1 // If n is odd
```

Use the above recursive relation to arrive at the answer for any `n` which lies between `1 < n < 101`

# NOTE
As the answer can be large `(For E.g. n = 17, ans = 130850092279664)` for smaller values of `n` do use `unsigned long long` data-type in C/C++ programming.  

