# Editorial of the problem [Easy Fibonacci](https://www.codechef.com/problems/FIBEASY) of Code-Chef

*   **Problem Statement:** You are given a Fibonacci Sequence, and you need to find the member of the sequence which will be preserved when the following operation is executed on the sequence:  
    - Delete the data which is stored at the odd location of the sequence.  
    - Do this operation until only one member of the sequence is left.  
    After doing the above operation, print the left member.

*   The problem is straight forward, but as the constraints is large, you need to think of an algorithm which will solve the problem in the given time-constraint.  
Given Constraints are:  
```
    1 <= T <= 100000
    1 <= n <= 10^18
    Time Limit: 1 sec
```

So, first we will see is there any pattern when I remove only the odd location elements from the array until the size of the array is 1.  
It turns out that, the index value which will be left after the operation can be as follows:  
```
if(n bitwise AND (n - 1)) {
    Find out the greatest-value of 2^n < n.
} else {
    The value at location n will be preserved after the operation.
}
- (n bitwise AND (n - 1)) -> True means n cannot be expressed as 2^`n`.
- (n bitwise AND (n - 1)) -> False means n can be expressed in the form of 2^n.
```

Now, as the value of `n` can be as large as `10^18`, so obviously you cannot use a `O(n)` time algorithm to compute every Fibonacci Number.  
To solve this, in the problem it is given that the set  **D consits only the last digit's of the first n Fibonacci sequence**  
```
E.g Fibonacci Sequence = {0,1,1,2,3,5,8,13,21, ....}  
D = {0,1,1,2,3,5,8,3,1,...}  
i.e D = {x belongs to Z : x % 10 where x is a Fibonacci number}.
```
Now to proceed further, we need to use a well known fact, which states that the [Fibonacci Numbers are Periodic](https://en.wikipedia.org/wiki/Pisano_period) modulo any given number, and **in the case of the number 10, the period is 60.**  

Now, instead of generating the Fibonacci numbers till `n`, you can build an array of length 60 and store the first 60 Fibonacci numbers modulo 10 in it.  

Now you can calculate the answer in constant time as follows:  
``` 
    if(index_val > 60) {
        index = index % 60
    }
    print the value stored at the (index - 1) location in the array of Fibonacci numbers, and that will be the answer.
```

## NOTE
The bottleneck of the above algotithm is to calculate the value of log2(`n`) correctly.  
I have developed the solution in C-programming, and if you are also using the same, then use the `log2l()` function rather than `log2()` function because the signature is `long double log2l(long double)` means it can calculate the `log2` value of large numbers in the range of `[1,10^18]` which `log2()` will not be able to.  

If you use `log2()` for calculation, you code will only pass the first sub-task of the problemm.  
I won't be able to pass the second sub-task because of the precision error arising due to use of the `log2()` function.  
```
E.g `n` = 4503599627370496 (2 ^ 52) => log2(`n`) = 52, but when `n` = 4503599627370496 ((2 ^ 52) - 1) => log2(`n`) = 52, which is wrong rather the right answer is 51.  
```
So to remove this error, you can use the `log2l()` function defined in `math.h` library of C/C++.  
```
Time-Complexity: O(T * (log2(`n`))) + O(Z), where Z = 60.  
Space-Complexity: O(60) where Z = 60.  
```