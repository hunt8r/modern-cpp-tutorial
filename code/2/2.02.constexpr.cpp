//
// 2.2.constexpr.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#define LEN 10

int len_foo() {
    int i = 2;
    return i;
}
constexpr int len_foo_constexpr() {
    return 5;
}

// error in c++11
// constexpr int fibonacci(const int n) {
//     if(n == 1) return 1;
//     if(n == 2) return 1;
//     return fibonacci(n-1) + fibonacci(n-2);
// }

// ok
constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}


int main() {
    char arr_1[10];                      // legal
    char arr_2[LEN];                     // legal

    int len = 10;
    // char arr_3[len];                  // illegal

    const int len_2 = len + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;
    // char arr_4[len_2];                // illegal, but ok for most of the compilers
    char arr_4[len_2_constexpr];         // legal

    // char arr_5[len_foo()+5];          // illegal
    char arr_6[len_foo_constexpr() + 1]; // legal
    
    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    std::cout << fibonacci(10) << std::endl;

    return 0;
}

/*
This code demonstrates the usage of different ways to declare arrays in C++.

The code first defines a macro constant LEN with the value 10. It then defines a function len_foo() which returns an integer value of 2. Another function len_foo_constexpr() is defined with the constexpr specifier, which means that it can be evaluated at compile-time. This function returns an integer value of 5.

Next, the code demonstrates the different ways to declare arrays. The first two declarations char arr_1[10] and char arr_2[LEN] are legal and equivalent. However, the third declaration char arr_3[len] is illegal because len is not a constant expression, and array size must be known at compile-time.

The code then shows that it is possible to declare an array with a constant expression len_2_constexpr computed at compile-time, but len_2 computed at runtime cannot be used for array declaration. The declaration char arr_4[len_2_constexpr] is legal, but char arr_4[len_2] is illegal.

The code also demonstrates that len_foo() cannot be used to declare an array size, but len_foo_constexpr() can be used. The declaration char arr_6[len_foo_constexpr() + 1] is legal.
*/
