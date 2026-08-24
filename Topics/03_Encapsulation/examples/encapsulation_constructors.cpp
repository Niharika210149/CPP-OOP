#include <iostream>
#include <stdexcept>

class Student
{
private:
    int marks;

public:
    Student(int m)
        : marks(m)
    {
        if (m < 0 || m > 100)
        {
            throw std::invalid_argument("Invalid marks");
        }
    }

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
    Student s1(90);

    std::cout << "Marks : " << s1.getMarks() << '\n';

    s1.setMarks(95);

    std::cout << "Marks : " << s1.getMarks() << '\n';

    // Student s2(-50);   // ❌ construction fails

    return 0;
}