#include <iostream>

class A {
    public:
        A(int q) {}

        A* f() {
            std::cout << "hi" << std::endl;
            A b = A(2);
            return ptr_;
        }
    
    private:
        int q_;
        A* ptr_;
};

int main() {
    A* a;
    a = a->f();
    // std::cout << a << std::endl;
}