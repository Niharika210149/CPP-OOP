#include <iostream>

class Animal {
public:
    Animal() {
        std::cout << "Animal constructed\n";
    }

    virtual ~Animal() {
        std::cout << "Animal destroyed\n";
    }
};

class Dog : public Animal {
public:
    Dog() {
        std::cout << "Dog constructed\n";
    }

    ~Dog() override {
        std::cout << "Dog destroyed\n";
    }
};

int main() {
    Animal* animal = new Dog();

    delete animal;

    return 0;
}