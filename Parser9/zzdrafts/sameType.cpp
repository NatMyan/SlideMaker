#include <iostream>


class A {

};

class B : A {

};

class C : A {

};


int main () {
    std::cout << std::is_same_v<C, B> << std::endl;
}