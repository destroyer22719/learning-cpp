Initializing or copying a string in C++ is slow. So the in C++17, `std::string_view` existed which provides read-only access to an *existing* string without making a copy. It's faster.

```cpp
#include <iostream>
#include <string_view>

void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    printSV(s);

    return 0;
}
```
No copies of "Hello, world!" were made.

### Best Practice
Prefer `std::string_view` over `std::string` when you need a read-only string, especially for function parameters.

You can also use `std::string_view` as a `constexpr` unlike `std::string`!

## Converting a `std::string` to a `std::string_view`
A `std::string_view` can be created using a `std::string` initializer, and a `std::string` will implicitly convert to a `std::string_view`:
```cpp
#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world" };
    std::string_view sv{ s }; // Initialize a std::string_view from a std::string
    std::cout << sv << '\n';

    printSV(s); // implicitly convert a std::string to std::string_view

    return 0;
}
```

## Converting a `std::string_view` to a `std::string`
C++ won't allow implicit conversion of a `std::string_view` to a `std::string`. However, we can explicitly create a `std::string` with a `std::string_view` initializer, or use `static_cast`

```cpp
#include <iostream>
#include <string>
#include <string_view>

void printString(std::string str)
{
    std::cout << str << '\n';
}

int main()
{
  std::string_view sv{ "balloon" };

  std::string str{ sv }; // okay, we can create std::string using std::string_view initializer

  // printString(sv);   // compile error: won't implicitly convert std::string_view to a std::string

  printString(static_cast<std::string>(sv)); // okay, we can explicitly cast a std::string_view to a std::string

  return 0;
}
```