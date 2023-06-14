If we want to print booleans as `true` or `false` we have to use `std::boolalpha`
```cpp
#include <iostream>

int main() {
	std::cout << true << "\n";
	std::cout << false << "\n";
	//outputs 1 and 0
	std::cout <, std::boolalpha;
	std::cout << true << "\n";
	std::cout < false << "\n"
	//outputs true and false
	return 0;
}
```

`std::cin` only accepts 2 inputs for boolean variables, 0 and 1. Anything else will be `false`.

```cpp
#include <iostream>

int main()
{
	bool b{}; // default initialize to false
	std::cout << "Enter a boolean value: ";
	std::cin >> b;
	std::cout << "You entered: " << b << '\n';

	return 0;
}
```
If you want to allow `std::cin` you have to use `std::boolalpha`
```cpp
#include <iostream>

int main()
{
	bool b{};
	std::cout << "Enter a boolean value: ";

	// Allow the user to enter 'true' or 'false' for boolean values
	// This is case-sensitive, so True or TRUE will not work
	std::cin >> std::boolalpha;
	std::cin >> b;

	std::cout << "You entered: " << b << '\n';

	return 0;
}
```
