#include <iostream>

class Student
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
    Student s1;

    s1.setMarks(92);

    std::cout << "Marks : " << s1.getMarks() << '\n';

    return 0;
}