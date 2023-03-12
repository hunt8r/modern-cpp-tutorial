//
// 2.7.decltype.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <type_traits>

int main() {
    auto x = 1;
    auto y = 2;
    decltype(x+y) z = 3;
    if (std::is_same<decltype(x), int>::value)
        std::cout << "type x == int" << std::endl;
    if (std::is_same<decltype(x), float>::value)
        std::cout << "type z == float" << std::endl;
    if (std::is_same<decltype(x), decltype(z)>::value)
        std::cout << "type z == type x" << std::endl;
    return 0;
}

/*
what is the difference between value type and decl type

In C++, value_type and decltype are two different concepts, but they are related to each other.

value_type is a member type of a container class, such as std::vector, that specifies the type of the 
elements stored in the container. For example, std::vector<int>::value_type is int, 
and std::vector<std::string>::value_type is std::string. The value_type is used to declare variables that 
can hold individual elements of the container.

decltype is a C++ keyword that determines the type of an expression at compile time. 
It is useful when we want to declare a variable that has the same type as some other expression. 
For example, if we have a variable x of type int, we can declare another variable y of the same 
type using decltype(x) y;. The type of y will be int.

The difference between value_type and decltype is that value_type is a member type of a container class, 
and specifies the type of the elements stored in the container, whereas decltype determines 
the type of an expression at compile time, which could be any type, not necessarily the same as the element type of a container.
*/
