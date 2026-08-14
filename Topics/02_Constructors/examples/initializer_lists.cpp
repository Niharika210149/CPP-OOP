// Initializer lists for const data member and reference data member

#include <iostream>

class Student
{
private:
    const int roll;
    int& ref;

public:
    Student(int r, int& x)
        : roll(r), ref(x)
    {
    }

    void display()
    {
        std::cout << "Roll : " << roll << '\n';
        std::cout << "Ref  : " << ref << '\n';
    }
};

int main()
{
    int x = 102;

    Student s1(101, x);

    s1.display();

    return 0;
}