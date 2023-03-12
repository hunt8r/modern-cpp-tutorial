//
// 2.12.external.template.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <vector>

/*
In the first line, we explicitly instantiate the std::vector class for the bool data type. 
This means that we force the compiler to generate the code for the std::vector class with bool as its template argument. 
This can be useful when we want to reduce the compilation time or when we need to ensure that the code is generated for a specific type.
*/
template class std::vector<bool>;           // forcely instantiation

/*
In the second line, we declare an external template instantiation for the std::vector class with double as its template argument. 
This means that we tell the compiler that the code for this class is defined somewhere else, 
and the compiler should not try to generate it in the current file. 
This can be useful when we want to reduce the binary size or when we want to prevent duplicate symbol errors during the linking process.
*/
extern template class std::vector<double>;  // external template for avoiding instantiation in this file

template<bool T> class MagicType {
    bool magic = T;
};

int main() {
    // the >> in template
    std::vector<std::vector<int>> matrix;
    std::vector<MagicType<(1>2)>> magic; /* Note that this usage is legal, but not recommended, 
    because the boolean expression is evaluated at runtime, not at compile-time, which can lead to unexpected behavior. 
    It is generally better to use a constexpr boolean expression for the template parameter.*/
}
