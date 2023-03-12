//
// 2.10.if.constexpr.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>

template<typename T>
auto print_type_info(const T& t) {
    if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}

// at compiling time
// int print_type_info(const int& t) {
//     return t + 1;
// }
// double print_type_info(const double& t) {
//     return t + 0.001;
// }

int main() {
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}

/*
why is constexpr useful in this case ? Anyways template functions are created per basic datatype basis

constexpr is useful in this case because it allows the function to be evaluated at compile time, instead of run time.

Yes, it's true that template functions are created per basic datatype basis, but in this case, 
constexpr allows the compiler to optimize the code better. When print_type_info is called with an integral type as an argument, 
it will return t + 1, and when it's called with a non-integral type, it will return t + 0.001. 
Since the return type of the function depends on the type of the argument, the compiler will generate different code for different types.

By using constexpr, the compiler can perform the type check at compile time, and generate code that is specific to the input type. 
This can lead to faster and more efficient code, especially when the function is called multiple times with the same type.
*/
