Header files can include other header files. However, you can't include a header file more than once. The following code will cause a compile error:

`square.h`
```cpp
int getSquareSides()
{
    return 4;
}
```
`wave.h`
```cpp
#include "square.h"
```
`main.cpp`
```cpp
```cpp
#include "square.h"
#include "wave.h" // wave.h also includes square.h! We've included square.h twice!

int main()
{
    return 0;
}
```
This is where header guards come in to play.
```cpp
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations (and certain types of definitions) here

#endif
```
If this is the first time we're including the header file, it won't be defined, thus we will define `SOME_UNIQUE_NAME_HERE` and all of the all the contents of the file. But if it already is, it won't do anything because of the `#ifndef`

The unique name by convention would be file file name in all caps with `_` replacing spaces and punctuation

`square.h`
```cpp
#ifndef SQUARE_H
#define SQUARE_H

int getSquareSides()
{
    return 4;
}

#endif
```