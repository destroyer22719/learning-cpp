adding the `static` keyword to a local variable gives it the same behaviour as a global variable in that it went from an automatic duration (created at point of definition, destroyed when block is exited) to static duration (the variable is created at the start of the program and lasts throughout the entire program life cycle). Static variables can retain its value, even outside of its scope.

```cpp
#include <iostream>

void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}
```

### Best Practice
Avoid static local variables unless if you need it so they don't reset in value.

