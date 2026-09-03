#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal sound\n";
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof\n";
    }
};

int main() {
    Animal* animal = new Dog();

    animal->speak();

    delete animal;

    return 0;
}