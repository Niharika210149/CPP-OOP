#include <iostream>

class Printer
{
public:
    void print()
    {
        std::cout << "Printer is printing\n";
    }

    void start()
    {
        std::cout << "Printer started\n";
    }
};

class Scanner
{
public:
    void scan()
    {
        std::cout << "Scanner is scanning\n";
    }

    void start()
    {
        std::cout << "Scanner started\n";
    }
};

class AllInOne : public Printer, public Scanner
{
public:
    void useMachine()
    {
        print();
        scan();

        // Both Printer and Scanner have start(),
        // so we must specify which one we want.

        Printer::start();
        Scanner::start();
    }
};

int main()
{
    AllInOne machine;

    machine.print();
    machine.scan();

    // Ambiguous:
    // machine.start();   // ❌

    // Resolve ambiguity using scope resolution
    machine.Printer::start();
    machine.Scanner::start();

    machine.useMachine();

    return 0;
}