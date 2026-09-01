#include <iostream>

class Animal
{
public:
    void eat()
    {
        std::cout << "Animal is eating\n";
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

class Cat : public Animal
{
public:
    void meow()
    {
        std::cout << "Cat is meowing\n";
    }
};

class Hybrid : public Dog, public Cat
{
public:
    void useAnimalFunctions()
    {
        // Hybrid has two paths to Animal:
        //
        // Hybrid → Dog → Animal
        // Hybrid → Cat → Animal
        //
        // Therefore this is ambiguous:
        //
        // eat();   // ❌

        Dog::eat();
        Cat::eat();

        bark();
        meow();
    }
};

int main()
{
    Hybrid h;

    h.bark();
    h.meow();

    // Ambiguous because Hybrid has
    // two Animal base subobjects.
    //
    // h.eat();   // ❌

    h.Dog::eat();
    h.Cat::eat();

    return 0;
}