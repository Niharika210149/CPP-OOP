#include<iostream>
#include<string>

class Student
{
public:
    int roll;

    void display()
    {
        std::cout << "Roll     : " << roll << '\n';    // roll vs this-
        std::cout << "this     : " << this << '\n';
        std::cout << "&roll    : " << &roll << '\n';
    }
};

int main()
{
    Student s1;
    Student s2;

    s1.roll = 101;
    s2.roll = 202;

    s1.display();
    s2.display();

    return 0;
}