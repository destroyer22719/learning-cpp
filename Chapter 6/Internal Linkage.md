
Local variables have no linkage. Linkage determines whether other declarations of that name refer to the same object or not.

Non-constant global variables have external linkage by default, but can be given internal linkage by adding the `static` keyword
```cpp
static int myVar{0}
```

`const` and `constexpr` have internal linkage by default.

`add.cpp`
```cpp
constexpr int g_x {2}
```
`main.cpp`
```cpp
#include <iostream>

static int g_x { 3 }; // this separate internal g_x is only accessible within main.cpp

int main()
{
    std::cout << g_x << '\n'; // uses main.cpp's g_x, prints 3

    return 0;
}
```
The program outputs 3. `g_x` is internal to each file, both files don't know about each others' `g_x`.
