# Editorial of GCD2
* To solve this problem first you should give attention to constraints i.e. `0 <= a <= 40,000 and a <= b <= 10^250`.

* You can observe that the value of `b >= a` and `b` has maximium of `250` digits.

* As `b` can have a maximum of 250 digits, and in C/C++ programming, there is no data-type to store such a huge number which is even greate than `10^100` i.e. googol.

* Its better to use `string` or `char array` to store the value of `b`, now if you analyse the **Euclid Algorithm** for the calculation of GCD of `a` and `b`, you will see that, when the value of `b != 0`, you call the same function but previously whatever was `b` now becomes `a` and `b` becomes `a % b`.

* Recursive Equation for the calculation of `gcd(a, b)` when `a >= b`:
![alt text](https://github.com/strikersps/Competitive-Programming/blob/master/Code-Chef/GCD2/gcd-calculation-recursive-equation.png)

* So instead of calling `compute_gcd(a, b)` directly, why not compute `b % a` first as the result can then be stored in an `int` datatype as the value of `a` then gets reduced i.e. `a belong to [0, a - 1]`, and then call `compute_gcd(a, b)` to compute the GCD of `a, b` as then `a >= b`.
