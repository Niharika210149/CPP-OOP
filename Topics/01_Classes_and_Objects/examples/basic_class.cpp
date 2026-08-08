#include <iostream>
#include <string>

class Student
{
public:
    int roll;
    std::string name;
    float marks;

    void display()
    {
        std::cout << "Roll   : " << roll << '\n';
        std::cout << "Name   : " << name << '\n';
        std::cout << "Marks  : " << marks << '\n';
    }
};

int main()
{
    Student s1;

    s1.roll = 101;
    s1.name = "Rahul";
    s1.marks = 92.5f;

    s1.display();

    return 0;
}