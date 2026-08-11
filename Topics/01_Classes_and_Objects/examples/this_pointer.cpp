#include <iostream>

// class Student {
// public:
//     int roll;

//     void display() {
//         std::cout << "Roll: " << roll << '\n';
//         std::cout << "Roll: " << this << '\n';
//     }
// };

// int main() {
//     Student s1;
//     Student s2;

//     s1.roll = 101;
//     s2.roll = 202;

//     std::cout << "&s1: " << &s1 << '\n';
//     std::cout << "&s2: " << &s2 << '\n';
    
//     s1.display();
//     s2.display();

//     return 0;
// }

/*------------------------------------------------------------*/

// class Student {
// private:
//     int roll;

// public:
//     void setRoll(int roll) {
//         this->roll = roll;
//     }

//     void display() {
//         std::cout << "Roll: " << this->roll << '\n';
//     }
// };

// int main() {
//     Student s1;
//     Student s2;

//     s1.setRoll(101);
//     s2.setRoll(202);

//     s1.display();
//     s2.display();

//     return 0;
// }

/*------------------------------------------------------------*/

// class Student {
// private:
//     int roll;

// public:
//     void setRoll(int roll) {
//         std::cout << "Object address : " << this << '\n';
//         std::cout << "Member address : " << &this->roll << '\n';
//         std::cout << "Parameter addr : " << &roll << '\n';

//         // this->roll = roll;
//     }
// };

// int main() {
//     Student s1;
//     Student s2;

//     std::cout << "&s1 : " << &s1 << '\n';
//     s1.setRoll(101);

//     std::cout << "\n&s2 : " << &s2 << '\n';
//     s2.setRoll(202);

//     return 0;
// }

/*------------------------------------------------------------*/

class Student {
private:
    int roll;
    float marks;

public:
    Student& setRoll(int roll) {
        this->roll = roll;
        return *this;
    }

    Student& setMarks(float marks) {
        this->marks = marks;
        return *this;
    }

    void display() {
        std::cout << "Roll: " << roll << '\n';
        std::cout << "Marks: " << marks << '\n';
    }
};

int main() {
    Student s1;

    // s1.setRoll(101);
    // s1.setMarks(92.5f);

    s1.setRoll(101).setMarks(92.5f);

    s1.display();

    return 0;
}