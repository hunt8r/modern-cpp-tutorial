//
// 2.8.tail.return.type.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <type_traits>

// before c++11
template<typename R, typename T, typename U>
R add(T x, U y) {
    return x + y;
}
// after c++11
template<typename T, typename U>
auto add2(T x, U y) -> decltype(x+y){
    return x + y;
}
// after c++14
template<typename T, typename U>
auto add3(T x, U y){
    return x + y;
}

int main() {

    // before c++11
    int z = add<int, int, int>(1, 2);
    std::cout << z << std::endl;

    // after c++11
    auto w = add2<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value) {
        std::cout << "w is double: ";
    }
    std::cout << w << std::endl;

    // after c++14
    auto q = add3<double, int>(1.0, 2);
    std::cout << "q: " << q << std::endl;

    return 0;
}

/*
Before C++11, template type deduction required the programmer to specify all the template parameters, 
which could be cumbersome and error-prone. The add function in the code uses this syntax to specify the return type R 
and the types of the two function arguments T and U. The function simply returns the sum of the two arguments.

In C++11, template type deduction was improved with the introduction of auto and the decltype specifier. 
The add2 function in the code uses these features to deduce the return type of the function based on the types of its arguments. 
The decltype specifier is used to determine the type of the expression x + y, and this type is used as the return type of the function. 
The auto keyword is used to specify that the return type should be deduced automatically. 
This reduces the verbosity of the code and makes it easier to read.

In C++14, the auto keyword was further enhanced to allow deduction of function return types without using decltype. 
The add3 function in the code uses this feature to automatically deduce the return type of the function based on the types of its arguments. 
This is done by simply returning the sum of the two arguments using the + operator, 
and allowing the compiler to deduce the return type based on the types of the arguments. 
This further simplifies the code and makes it even easier to read.
*/
