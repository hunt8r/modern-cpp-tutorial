//
// 2.3.if.switch.cpp
// chapter 2 language usability
// modern cpp tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    // after c++17, can be simplefied by using `auto`
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }
/*
t shows how a conditional expression can be used with an initialization statement. 
In the second if statement, we initialize the itr variable inside the condition by calling std::find to search for the value 3 in the vec vector. 
If std::find returns an iterator that is not equal to vec.end(), the if block is executed, and we change the value pointed to 
by the iterator from 3 to 4
*/
    if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3);
        itr != vec.end()) {
        *itr = 4;
    }

    // should output: 1, 4, 3, 4. can be simplefied using `auto`
    for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
        std::cout << *element << std::endl;
}
