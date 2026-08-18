#include <iostream>

class Student
{
private:
    int roll;
    int* marks;

public:
    // Constructor
    Student(int roll, int marks)
        : roll(roll),
          marks(new int(marks))
    {
    }

    // Copy constructor
    Student(const Student& other)
        : roll(other.roll),
          marks(new int(*other.marks))
    {
    }

    // Copy assignment operator
    Student& operator=(const Student& other)
    {
        if (this != &other)
        {
            roll = other.roll;

            delete marks;
            marks = new int(*other.marks);
        }

        return *this;
    }

    // Destructor
    ~Student()
    {
        delete marks;
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

int main() {
    Student s1(101, 86);
    Student s2(102, 98);
    Student s3 = s1;

    s1.display();
    s2.display();
    s3.display();

    s2 = s1;
    s3 = s3;

    s1.display();
    s2.display();
    s3.display();

    return 0;
}