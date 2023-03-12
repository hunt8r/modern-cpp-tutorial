//
// 2.9.decltype.auto.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

template<int i>
/ Define a struct that acts as a tag for an integer value
struct Int {};

// Declare a constexpr function that returns an Int<0> when given an Int<0>
constexpr auto iter(Int<0>) -> Int<0>;

// Declare a recursive constexpr function that takes an Int<i> as its argument,
// creates an Int<i-1>, and calls itself with the newly created tag type
template<int i>
constexpr auto iter(Int<i>) {
    return iter(Int<i-1>{});
}

int main() {
// Call iter with Int<10> to create a new tag type Int<0>
// and store it in a variable a using decltype to deduce the type
    decltype(iter(Int<10>{})) a;
}
