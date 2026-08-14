#include <iostream>

// class Student
// {
// public:
//     int roll;
//     float marks;
// };

// int main()
// {
//     Student s1; // default initializing the object

//     std::cout << "Roll  : " << s1.roll << '\n';
//     std::cout << "Marks : " << s1.marks << '\n';

//     Student s2{}; // value initializing the object

//     std::cout << "Roll  : " << s2.roll << '\n';
//     std::cout << "Marks : " << s2.marks << '\n';    

//     return 0;
// }

/*------------------------------------------------------------*/

// class Student {
// public:
//     int roll;
//     float marks;

//     Student() { // this function is a constructor
//         roll = 0;
//         marks = 0.0f;
//     }
// };

// int main() {
//     Student s1;

//     std::cout << "Roll  : " << s1.roll << '\n';
//     std::cout << "Marks : " << s1.marks << '\n';
// }

/*------------------------------------------------------------*/

// class Student {
// private:
//     int roll;
//     float marks;

// public:
//     Student(int r, float m) { // constructor with parameters
//         roll = r;
//         marks = m;
//     }

//     void display() const { // member functions
//         std::cout << "Roll  : " << roll << '\n';
//         std::cout << "Marks : " << marks << '\n';
//     }
// };

// int main() {
//     Student s1(101, 92.5f); // initialization of objects with different parameters
//     Student s2(102, 85.0f);

//     s1.display();
//     s2.display();
// }

/*------------------------------------------------------------*/

class Student {
private:
    int roll;
    float marks;

public:

    Student() {
        std::cout << "Default constructor\n";
        roll = 0;
        marks = 0.0f;
    }

    Student(int roll, float marks)
        : roll(roll), marks(marks)
    {
        std::cout << "Parameterized constructor\n";
    }

    void display() const {
        std::cout << "Roll  : " << roll << '\n';
        std::cout << "Marks : " << marks << '\n';
    }
};

int main() {
    Student s1;
    Student s2(101, 92.5f);

    s1.display();
    s2.display();

    return 0;
}