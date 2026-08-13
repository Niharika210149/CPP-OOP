#include<iostream>

// class Student {
//     private:
//         int roll = 101;

//     public:
//         void display() const {
//             std::cout << "roll: " << roll << '\n';
//         }
// };

// int main() {
//     const Student s1;

//     s1.display();

//     return 0;
// }

class Student
{
private:
    int roll = 101;
    float marks = 92.5f;

public:

    void display() const
    {
        std::cout << roll << " " << marks;
    }

    void setRoll(int roll)
    {
        this->roll = roll;
    }
};

int main() {
    Student s1;
    const Student s2;

    s1.display();
    s1.setRoll(10);
    s1.display();
    return 0;
}