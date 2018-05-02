# std::unique_ptr

## Description:

**Unique_ptr** is one of types of smart pointers, which was made cause of problem with tenures.

### Problem statement:

While using **auto_ptr**, object of this class lose tenure of resource, while copying. For example, in this program:

```C++
#include <iostream>
#include <memory>

int main() {
    std::auto_ptr<int> x_ptr(new int(42));
    std::auto_ptr<int> y_ptr;
    y_ptr = x_ptr; // <- here is the main problem
    std::cout << *x_ptr << "\n";
    return 0;
}
```

We get  *Segmentation fault*.

### How std::unique_ptr solve that problem?

**Unique_ptr** just forbid copying pointers this way..

> And actually that programm upwards will get Compilation error, while compiling that with unique_ptr inspire of auto_ptr

And changing tenure(as a part of copying) is going with using spectial function - **std::move**

Also, it have such functions as **reset** (that resets tenure) and **get** (that returns pointer).

### Comments and other stuff

Actually there are 3 types of smart pointers: **unique_ptr**, **shared_ptr** и **weak_ptr** and all of them comtains in <memory> library.

**original unique_ptr realization:** [function in C++](http://ru.cppreference.com/w/cpp/memory/unique_ptr)
