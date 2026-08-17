#include<iostream>

class Student
{
private:
    int roll;
    int* marks;

public:
    Student(int roll, int marks)
        : roll(roll),
          marks(new int(marks))
    {
    }

    Student(const Student& other)
        : roll(other.roll),
          marks(new int(*other.marks))
    {
    }

    void display() const
    {
        std::cout << "Roll  : " << roll << '\n';
        std::cout << "Marks : " << *marks << '\n';
    }

    void changeMarks(int marks)
    {
        *this->marks = marks;
    }
};

int main()
{
    Student s1(101, 92);

    Student s2 = s1;

    std::cout << "Before changing s1:\n";

    s1.display();
    s2.display();

    std::cout << "\nAfter changing s1:\n";

    s1.changeMarks(50);

    s1.display();
    s2.display();

    return 0;
}