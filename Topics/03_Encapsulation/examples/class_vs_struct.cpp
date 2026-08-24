#include <iostream>

class Student
{
    int marks;  // private by default

public:
    void setMarks(int m)
    {
        if (m >= 0 && m <= 100)
        {
            marks = m;
        }
    }

    int getMarks() const
    {
        return marks;
    }
};

struct Point
{
    int x;  // public by default
    int y;  // public by default
};

struct PrivateStudent
{
private:
    int marks;

public:
    void setMarks(int m)
    {
        if (m >= 0 && m <= 100)
        {
            marks = m;
        }
    }

    int getMarks() const
    {
        return marks;
    }
};

int main()
{
    Student s;

    s.setMarks(90);
    std::cout << "Student marks : "
              << s.getMarks() << '\n';


    Point p;

    p.x = 10;
    p.y = 20;

    std::cout << "Point : "
              << p.x << ", "
              << p.y << '\n';


    PrivateStudent ps;

    ps.setMarks(95);
    std::cout << "PrivateStudent marks : "
              << ps.getMarks() << '\n';

    return 0;
}