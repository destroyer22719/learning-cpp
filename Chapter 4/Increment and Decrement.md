`x++` and `++x` actually have different behaviour.

![[Screenshot from 2023-06-11 13-20-06.png]]

We can see an example here with the following 2 programs
```cpp
#include <iostream>

int main()
{
    int x { 5 };
    int y = ++x; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

    std::cout << x << ' ' << y << '\n';
    return 0;
}
```
it outputs
```
6 6
```
Whereas using `x++`
```cpp
#include <iostream>

int main()
{
    int x { 5 };
    int y = x++; // x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y

    std::cout << x << ' ' << y << '\n';
    return 0;
}
```
Which results in the following outputs:
```
6 5
```
