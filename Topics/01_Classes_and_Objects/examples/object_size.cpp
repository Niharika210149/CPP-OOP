#include<iostream>
#include<string>

class Student {
    public:
        int roll;
        float marks;

        // void display(){
        //     std::cout << roll << " " << marks << '\n';
        // }
};

class comparison { // comparison of sizes of different classes
    public:
        // char a;
        // int b;
        // char c;

        int d;
        char a;
        char b;
        int c;
};

int main(){
    Student s1;
    Student s2;

    std::cout << "Size of Student " << sizeof(Student) << '\n';
    std::cout << "Size of s1 " << sizeof(s1) << '\n';
    std::cout << "Size of s2 " << sizeof(s2) << '\n';

    std::cout << "Address of s1 " << &s1 << '\n';
    std::cout << "Address of s2 " << &s2 << '\n';

    std::cout << "Address of s1.roll " << &s1.roll << '\n';
    std::cout << "Address of s1.marks " << &s1.marks << '\n';

    std::cout << "Size of comparison " << sizeof(comparison) << '\n';
    
    return 0;
}