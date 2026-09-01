#include <iostream>

class Animal
{
public:
    Animal()
    {
        std::cout << "Animal constructor\n";
    }

    ~Animal()
    {
        std::cout << "Animal destructor\n";
    }
};

class Dog : public Animal
{
public:
    Dog()
    {
        std::cout << "Dog constructor\n";
    }

    ~Dog()
    {
        std::cout << "Dog destructor\n";
    }
};

int main()
{
    Dog d;

    return 0;
}