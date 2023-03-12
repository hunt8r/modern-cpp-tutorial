//
// 2.1.nullptr.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <type_traits>

void foo(char *);
void foo(int);

int main() {
    if (std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl;
    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == (void *)0" << std::endl;
    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
        std::cout << "NULL == nullptr" << std::endl;

    foo(0);          // will call foo(int)
    // foo(NULL);    // doesn't compile
    foo(nullptr);    // will call foo(char*)
    return 0;
}

void foo(char *) {
    std::cout << "foo(char*) is called" << std::endl;
}
void foo(int i) {
    std::cout << "foo(int) is called" << std::endl;
}

/*
This code demonstrates the differences between NULL, 0, and nullptr in C++.

NULL, 0, and nullptr are all used to represent a null pointer. However, they have different types and behaviors.

In the code, the std::is_same function is used to compare the types of NULL, 0, and nullptr. The output of each comparison is printed to the console.

The first comparison checks whether the type of NULL is the same as the type of 0. In C++, 0 is an integer literal, so its type is int. The type of NULL is implementation-defined, but it is often defined as a null pointer constant with the value 0. Therefore, the first comparison will print "NULL == 0" to the console.

The second comparison checks whether the type of NULL is the same as the type of (void*)0. This is because in some implementations, NULL is defined as (void*)0. The type of (void*)0 is a pointer to void, which is a different type than int. Therefore, the second comparison will print "NULL == (void *)0" to the console.

The third comparison checks whether the type of NULL is the same as the type of std::nullptr_t. std::nullptr_t is a type introduced in C++11 that represents a null pointer. Therefore, the third comparison will print "NULL == nullptr" to the console.

After the comparisons, the code calls the foo function with different arguments. When foo is called with 0, it will call the foo(int) overload. When foo is called with nullptr, it will call the foo(char*) overload.

Note that when foo is called with NULL, the code will not compile because NULL does not have a unique type. This is why nullptr was introduced in C++11, to provide a type-safe and unambiguous way to represent a null pointer.
*/
