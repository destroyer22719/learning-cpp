`add.h`
```cpp
int add(int x, int y);
```
`main.cpp`
```cpp
#include "add.h"
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
```
`add.cpp`
```cpp
#include "add.h"

int add(int x, int y) {
	return x + y;
}
```

## `<>` vs `""` for importing header files
When we use angle brackets, we're telling the preprocessor that this is the header file that we didn't write ourselves.

Therefore: Use double quotes to include header files you've written or are expected to be found in the current directory. Use angle brackets to include headers that come with your compiler, OS, or 3rd party libraries

## Header files from other directories
It's possible to use relative paths, but there's a better way. Use the `-I` option for `g++`. 
```bash
g++ -o main -I/source/includes main.cpp
```

## Header file best practices

Here are a few more recommendations for creating and using header files.

- Always include header guards (we’ll cover these next lesson).
- Do not define variables and functions in header files.
- Give a header file the same name as the source file it’s associated with (e.g. _grades.h_ is paired with _grades.cpp_).
- Each header file should have a specific job, and be as independent as possible. For example, you might put all your declarations related to functionality A in A.h and all your declarations related to functionality B in B.h. That way if you only care about A later, you can just include A.h and not get any of the stuff related to B.
- Be mindful of which headers you need to explicitly include for the functionality that you are using in your code files.
- Every header you write should compile on its own (it should #include every dependency it needs).
- Only #include what you need (don’t include everything just because you can).
- Do not #include .cpp files.
- Prefer putting documentation on what something does or how to use it in the header. It’s more likely to be seen there. Documentation describing how something works should remain in the source files.