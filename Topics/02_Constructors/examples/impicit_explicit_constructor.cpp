#include<iostream>

class Student {
    public:
        Student(int roll)
        {
            std::cout << "Student created: " << roll << '\n';
        }

        // explicit Student(int roll)
        // {
        //     std::cout << "Student created: " << roll << '\n';
        // }
};

int main() {
    Student s1(101);
    Student s2 = 202;

    return 0;
}