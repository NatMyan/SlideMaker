#include <iostream>

class I {
    public:
        virtual void test() const = 0;
};  

class B : public I {
    public:
        void test() const final {
            std::cout << "test from base" << std::endl;
        }
};

class D : public B {
    public:
        void derivedTest() const {
            std::cout << "test from derived" << std::endl;
        }
};

int main () {
    D d;
    d.test();
    d.derivedTest();

    std::shared_ptr<B> bptr = std::make_shared<D>();
    bptr->test(); 
}