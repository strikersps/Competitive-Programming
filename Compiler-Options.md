# Compiler Flags for Compiling `C/C++` programs.

* For Compiling a C++ Program:  
```bash
g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result name_of_program.cpp -o name_of_output_file  
```

* For Building a C++ Program:
```bash
g++ -Wall -Wextra -pedantic -std=c++14 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector name_of_program.cpp -o name_of_output_file  
```

**NOTE:** For `C` Programs, replace the `g++` with `gcc` and replace `-std=c++14` with `-std=c11`.  

* References:
1. https://codeforces.com/blog/entry/15547
2. https://github.com/Errichto/youtube/wiki/Linux-setup
