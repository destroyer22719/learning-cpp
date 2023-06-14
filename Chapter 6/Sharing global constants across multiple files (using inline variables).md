Prior to C++17 this was the standard:
1. Create a header file to hold these constants
2. Inside this header file, define a namespace (discussed in lesson [6.2 -- User-defined namespaces and the scope resolution operator](https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/))
3. Add all your constants inside the namespace (make sure they’re `constexpr`)
4. `#include` the header file wherever you need it

The problem is, because `constexpr` can't be forward declared, we have to use `const`. The other problem is every time the header is imported the values get copied. We can give the definitions in a seperate file but the `constexpr` lack-thereof would mean less compiler optimization.

C++17 introduced a new concept called `inline variables`. In C++, the term `inline` has evolved to mean “multiple definitions are allowed”. Thus, an inline variable is one that is allowed to be defined in multiple files without violating the one definition rule. Inline global variables have external linkage by default.

Example:
`constants.h`
```cpp
#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants
{
    inline constexpr double pi { 3.14159 }; // note: now inline constexpr
    inline constexpr double avogadro { 6.0221413e23 };
    inline constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif
```
`main.cpp`
```cpp
#include "constants.h"

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}
```
