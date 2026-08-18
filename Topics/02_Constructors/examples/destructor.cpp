#include <iostream>

class Student {
private:
    int roll;
    int* marks;

public:
    Student(int roll, int marks)
        : roll(roll), marks(new int(marks)) 
    {
        std::cout << "Constructor\n";
    }

    ~Student() {
        std::cout << "Destructor\n";
        delete marks;
    }

    void display() const {
        std::cout << "Roll  : " << roll << '\n';
        std::cout << "Marks : " << *marks << '\n';
    }
};

int main() {
    Student s1(101, 92);

    s1.display();

    return 0;
}