#include <iostream>

class Animal
{
public:
    void eat()
    {
        std::cout << "Animal is eating\n";
    }

    void sleep()
    {
        std::cout << "Animal is sleeping\n";
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        std::cout << "Dog is barking\n";
    }
};

int main()
{
    Dog d;

    // Inherited members
    d.eat();
    d.sleep();

    // Dog's own member
    d.bark();

    return 0;
}