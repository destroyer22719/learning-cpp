Using strings with `std::cin` can have surprises

```cpp
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your age: ";
    std::string age{};
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age << '\n';

    return 0;
}
```

`>>` only gets the first characters up until a white space. Any others are left inside `std::cin` waiting for the next extraction.

To fix this you have to use `std::getline`

```cpp
#include <string> // For std::string and std::getline
#include <iostream>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    std::string age{};
    std::getline(std::cin >> std::ws, age); // read a full line of text into age

    std::cout << "Your name is " << name << " and your age is " << age << '\n';

    return 0;
}
```

You can use `std::ws` to ignore leading whitespace characters (including spaces, tabs, newlines). That newlines part is important, because when working with mutliple user inputs, whenever the user hits enter, there will be a leading `\n` character. `std::ws` tells the input manipulator to ignore leading whitespaces.
