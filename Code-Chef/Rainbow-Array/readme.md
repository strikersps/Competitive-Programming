*   This is the editorial of the problem [Rainbow Array](https://www.codechef.com/problems/RAINBOWA).
*   You are given an array and you need to tell       whether the array is a rainbow array or not.
*   The definition/structure of the rainbow array is defined        in the problem statement as:  
```
    First a1 elements equal to 1.  
    Next a2 elements equal to 2.  
    Next a3 elements equal to 3.  
    Next a4 elements equal to 4.  
    Next a5 elements equal to 5.  
    Next a6 elements equal to 6.  
    Next a7 elements equal to 7.  
    Next a6 elements equal to 6.  
    Next a5 elements equal to 5.  
    Next a4 elements equal to 4.  
    Next a3 elements equal to 3.  
    Next a2 elements equal to 2.  
    Next a1 elements equal to 1.  
    ai can be any non-zero positive integer i.e any 
    number between [1,7] can be repeated any number of 
    times.  
    There are no other elements in array.
```

*   From the above definition we can conclude that the array is said to be a rainbow array if it satifies the following conditions:  
    1.  The array should be palindrome.  
    2.  The array will only consist of the numbers between [1,7]. If the array contains a number greater than 7, then the array is not a rainbow array.  
    3.  With respect to the middle element, the left-subarray should consist of sequence of numbers starting from 1 and can be repeated **ai** number of times & right-subarray should be the mirror image of the left-subarray.
    4.  As per the definition, the minimum length of the array can be calculated by using the formula:  
        `2 * (a1 + a2 + a3 + a4 + a5 + a6) + a7 = n.`   
        Now in the problem statement it is given that, **ai** should be a non-zero value, implies minimum length of the array should be 13. i.e. If you want to check whether the given array is rainbow or not, it's length must be greater than 12.

**Pseudocode:**  
```
bool is_rainbow = true
if(length of the array < 13) {
    is_rainbow = false
} else if(there exists an number > 7) {
    is_rainbow = false
} else if(there exists a missing number between [1,7]) { // You can check it by creating a separate array which store the frequency of numbers in the range [1,7].
    is_rainbow = false
} else {
    // Place two pointers at the start and end of the array.
    start = 0, end = n - 1
    for i in length(1,7) {
        while((start <= end) and (array[start] == i && array[end] == i)) {
            ++start;
            --end;
        }
        /* If the while() loop breaks on the basis of second condition, then you will check for the following scenarios:
        (i) Value at both the locations are same or not.
        (ii) Value at start location or end location is not in consecutive with its previous value.
        (iii) Value at start location or end location is less than the current value of 'i'
        If any of the above condition becomes true means array is not a rainbow array.
        */ 
        if((start <= end) && ((array[start] != array[end]) || (array[start] > (i + 1)) || (array[end] > (i + 1)) || (array[start] < i) || array[end] < i)) {
            is_rainbow = false
        }
    }
}
if(is_rainbow) {
    print yes
} else {
    printf no
}
```

