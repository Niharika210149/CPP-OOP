#include <iostream>

class Animal
{
public:
    void eat()
    {
        std::cout << "Animal is eating\n";
    }
};

class Mammal : public Animal
{
public:
    void walk()
    {
        std::cout << "Mammal is walking\n";
    }
};

class Dog : public Mammal
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

    // Inherited from Animal
    d.eat();

    // Inherited from Mammal
    d.walk();

    // Dog's own member
    d.bark();

    return 0;
}