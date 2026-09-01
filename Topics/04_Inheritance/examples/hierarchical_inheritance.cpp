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

class Cat : public Animal
{
public:
    void meow()
    {
        std::cout << "Cat is meowing\n";
    }
};

int main()
{
    Dog dog;
    Cat cat;

    // Dog inherits from Animal
    dog.eat();
    dog.sleep();
    dog.bark();

    std::cout << '\n';

    // Cat inherits from Animal
    cat.eat();
    cat.sleep();
    cat.meow();

    return 0;
}