#include <iostream>

class Base
{
public:
    void func_a()
    {
        std::cout << "call Base::func_a" << std::endl;
    }

    virtual void func_b()
    {
        std::cout << "call Base::func_b" << std::endl;
    }
};

class Derived : public Base
{
public:
    void func_a()
    {
        std::cout << "call Derived::func_a" << std::endl;
    }

    virtual void func_b()
    {
        std::cout << "call Derived::func_b" << std::endl;
    }
};

int main()
{
    Derived derived;
    Base base = derived;

    std::cout << "把派生类对象转为基类对象，并调用同名函数： " << std::endl;
    base.func_a();

    std::cout << "把派生类对象转为基类对象，并调用虚函数： " << std::endl;
    base.func_b();

    Base &base_reference = derived;

    std::cout << "用一个基类对象的引用指向派生类对象，并调用同名函数： " << std::endl;
    base_reference.func_a();

    std::cout << "用一个基类对象的引用指向派生类对象，并调用虚函数： " << std::endl;
    base_reference.func_b();

    Base *base_pointer = &derived;

    std::cout << "用一个基类对象的指针指向派生类对象，并调用同名函数： " << std::endl;
    base_pointer->func_a();

    std::cout << "用一个基类对象的指针指向派生类对象，并调用虚函数： " << std::endl;
    base_pointer->func_b();

    return 0;
}