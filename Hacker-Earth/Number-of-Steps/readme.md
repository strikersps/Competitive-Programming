# Editorial of [Number of Steps](https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/make-all-equal-90a21ab2/description/?layout=old)

First of all you need to find what will be your target value to which every element of sequence `A` will reduce to.  
With an observation, it turns out that the target value to which you should first try to reduce all the elements of sequence `A` is the minimum element of `A` beacause that is going to give you the minimum number of operations as asked in the problem.  
But there would be cases in which you cannot reduce every element in sequence `A` to `min(A)`. So in those cases you are going to check whether you can reduce it to `min(A) - 1` or `min(A) - 2` or `min(A) - 3 ... min(A) - i` where `i <= min(A)`.  
We try every target value in descending order as it is clear that the highest valid one will take fewer operations.  

Now, after choosing the target we need to check whether it is possible to make all the elements of sequence `A` equal to each other and to do that, we use the follwing equations.  

Let's assume the elements of sequence `A` are denoted by `A[i]`, elements of sequence `B` are denoted by `B[i]`, choosen target by `t`, and minimum operations count or the answer which we are computing by `min_operations`.

For every element in sequence `A` we are going to check the following conditions:  

```C++
if(B[i] > 0 && (A[i] - t) % B[i] == 0) {
    min_operations = min_operations + (A[i] - t) / B[i];
}
```

Let's understand the above equations first:  
`(A[i] - t) % B[i]` is actually checking whether `A[i] - t` is divisible by `B[i]` or not. The significance of this, if `A[i] - t` is not divisible by `B[i]` then we cannot reduce `A[i]` to `t`.  

If the condition becomes `true`, then the total operations as defined in the problem (`A[i] = A[i] - B[i]`) needed to reduce `A[i]` to `t` is: `(A[i] - t) / B[i]`.  

Do note that the value of `B[i]` cannot be `0` otherwise it will lead to different errors in different progamming languages like in `C and C++` divison by zero leads to `SIGFPE` error whereas in `python` division by zero leads to `ZeroDivisionError`.  

**Example**  
```
A = {5, 7, 10, 5, 15}
B = {2, 2, 1, 3, 5}

min(A) = 5
target value = 5.
For every element in A we check the condition and accordingly update the value of min_operations variable:
 5: 5 == 5; min_operations = 0.
 7: (7 - 5) mod 2 == 0; min_operations = 1.
10: (10 - 5) mod 1 == 0; min_operations = 6.
 5: 5 == 5; min_operations = 6.
15: (15 - 5) mod 5 == 0; min_operations = 8.
```

You can check source-code (`C++`) for the implementation of above explained logic in `number_of_steps.cpp` file.
