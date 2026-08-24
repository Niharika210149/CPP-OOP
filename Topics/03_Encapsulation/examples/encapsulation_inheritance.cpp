#include <iostream>

class Animal{
private:
    int age;

protected:
    void setAge(int value){
        if (value >= 0){
            age = value;
        }
    }

    int getAge() const{
        return age;
    }

public:
    Animal(int initialAge)
        : age(0){
        if (initialAge >= 0){
            age = initialAge;
        }
    }
};

class Dog : public Animal
{
public:
    Dog(int initialAge)
        : Animal(initialAge){
    }

    void birthday(){
        int currentAge = getAge();
        setAge(currentAge + 1);
    }

    void setDogAge(int value){
        setAge(value);
    }

    void displayAge() const{
        std::cout << "Age : " << getAge() << '\n';
    }
};

int main(){
    Dog d(5);

    d.displayAge();

    d.birthday();

    d.displayAge();

    d.setDogAge(10);

    d.displayAge();

    // d.age = 10;       // ❌ private member
    // d.setAge(10);    // ❌ protected member

    return 0;
}