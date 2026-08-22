#include <iostream>

class Animal
{
private:
    int age;

protected:
    void setAge(int value)
    {
        if (value >= 0)
        {
            age = value;
        }
    }

public:
    int getAge() const
    {
        return age;
    }
};

class Dog : public Animal
{
public:
    void birthday()
    {
        int currentAge = getAge();
        setAge(currentAge + 1);
    }

    void setDogAge(int value)
    {
        setAge(value);
    }
};

int main()
{
    Dog d;

    // d.age = 5;       // ❌ private member
    // d.setAge(5);    // ❌ protected member

    d.setDogAge(5);    // ✅ public function of Dog
    std::cout << "Age : " << d.getAge() << '\n';

    d.birthday();

    std::cout << "Age after birthday : "
              << d.getAge() << '\n';

    return 0;
}