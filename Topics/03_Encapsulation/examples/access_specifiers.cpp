#include <iostream>

class Base{
    private:
        int a;

    protected:
        int b;

    public:
        int c;

        void test(){
            a = 1;  // ✅
            b = 2;  // ✅
            c = 3;  // ✅
        }

        void displayBase() const{
            std::cout << "a = " << a << '\n';
            std::cout << "b = " << b << '\n';
            std::cout << "c = " << c << '\n';
        }
};

class Derived : public Base{
    public:
        void testDerived(){
            // a = 10; // ❌ private in Base

            b = 20;    // ✅ protected
            c = 30;    // ✅ public
        }
};

int main(){
    Derived d;

    d.test();          // Base initializes a, b, c
    d.displayBase();   // Display all values
    
    d.testDerived();   // Derived modifies b and c

    d.displayBase();   // Display all values

    return 0;
}