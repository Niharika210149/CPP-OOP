#include <iostream>

class Resource
{
private:
    int* data;

public:
    Resource(int value)
    {
        data = new int(value);
    }

    void display() const
    {
        std::cout << "Data : " << *data << '\n';
    }

    ~Resource()
    {
        delete data;
        std::cout << "Resource released\n";
    }
};

int main()
{
    {
        Resource r(100);

        r.display();
    }

    std::cout << "Object lifetime ended\n";

    return 0;
}