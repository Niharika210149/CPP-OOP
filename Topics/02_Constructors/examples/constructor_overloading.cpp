#include <iostream>

class Student
{
private:
    int roll;
    float marks;

public:

    Student()
        : roll(0), marks(0.0f)
    {
        std::cout << "Student()\n";
    }

    Student(int roll)
        : roll(roll), marks(0.0f)
    {
        std::cout << "Student(int)\n";
    }

    Student(int roll, float marks)
        : roll(roll), marks(marks)
    {
        std::cout << "Student(int, float)\n";
    }

    void display() const
    {
        std::cout << "Roll  : " << roll << '\n';
        std::cout << "Marks : " << marks << '\n';
    }
};

int main()
{
    Student s1;
    Student s2(101);
    Student s3(102, 92.5f);

    std::cout << "\n";

    s1.display();
    s2.display();
    s3.display();

    return 0;
}