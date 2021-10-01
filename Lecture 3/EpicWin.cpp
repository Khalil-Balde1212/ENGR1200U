#include <iostream>

class Base
{
protected:
    std::string m_name;
public:
    Base(std::string name)
        : m_name(name)
    {
    }

    void sayHello() {std::cout << "\nHello World!" << std::endl;}
};

class Derived : public Base
{
public:
    Derived(std::string name)
        : Base(name)
    {
    }

    void greetings()
    {
        Base::sayHello();
        std::cout << "\nMy name is " << Base::m_name << std::endl;
    }
};


int main()
{
    Base base {"Khalil"};
    base.sayHello();

    Derived derived{"Brandon"};
    derived.sayHello();
    derived.greetings();
    return 0;
}