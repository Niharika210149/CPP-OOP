#include<iostream>

class Vehicle {
    public:
        void honk() {
            std::cout << "Beep Beep!!" << '\n';
        }
};                         

class Car : public Vehicle 
{                                                           
};

int main() {
    Car c;
    c.honk();
}