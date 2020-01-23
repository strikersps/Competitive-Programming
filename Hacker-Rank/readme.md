*   This repository consists of solutions to problems from [Hacker-Rank](https://www.hackerrank.com/) online programming competitions website in C/C++ and Python.
*   If you are using `C/C++` for submitting the solutions on Hacker-Rank, do note that Hacker-Rank judge doesn't has `ONLINE_JUDGE` macro defined i.e.
If you include the following source-code in your `C/C++` program, it will give you wrong answers.
    ```C
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ```
