#include <iostream>

class Test{
    private:
        int a;
        int b;

    public:
        Test()
            : Test(10, 20)
        {
            std::cout << "Test()\n";
        }

        Test(int x)
            : Test(x, 20)
        {
            std::cout << "Test(int)\n";
        }

        Test(int x, int y)
            : a(x), b(y)
        {
            std::cout << "Test(int, int)\n";
        }

        void display(){
            std::cout << "a : " << this->a << '\n';
            std::cout << "b : " << this->b << '\n';
        }
};

int main(){
    Test t(5);

    t.display();

    return 0;
}