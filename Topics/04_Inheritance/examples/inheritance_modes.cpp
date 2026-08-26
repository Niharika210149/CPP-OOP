#include <iostream>

class Base
{
private:
    int a;

protected:
    int b;

public:
    int c;

    Base()
        : a(10), b(20), c(30)
    {
    }

    void displayBase() const
    {
        std::cout << "Base::a = " << a << '\n';
        std::cout << "Base::b = " << b << '\n';
        std::cout << "Base::c = " << c << '\n';
    }
};


// ============================================================
// 1. PUBLIC INHERITANCE
// ============================================================

class PublicDerived : public Base
{
public:
    void display()
    {
        // a = 100;   // ❌ private in Base

        b = 200;      // ✅ protected in Base
        c = 300;      // ✅ public in Base

        std::cout << "\n--- PublicDerived ---\n";
        std::cout << "b = " << b << '\n';
        std::cout << "c = " << c << '\n';
    }
};


// ============================================================
// 2. PROTECTED INHERITANCE
// ============================================================

class ProtectedDerived : protected Base
{
public:
    void display()
    {
        // a = 100;   // ❌ private in Base

        b = 200;      // ✅ protected in ProtectedDerived
        c = 300;      // ✅ protected in ProtectedDerived

        std::cout << "\n--- ProtectedDerived ---\n";
        std::cout << "b = " << b << '\n';
        std::cout << "c = " << c << '\n';
    }
};


// ============================================================
// 3. PRIVATE INHERITANCE
// ============================================================

class PrivateDerived : private Base
{
public:
    void display()
    {
        // a = 100;   // ❌ private in Base

        b = 200;      // ✅ private in PrivateDerived
        c = 300;      // ✅ private in PrivateDerived

        std::cout << "\n--- PrivateDerived ---\n";
        std::cout << "b = " << b << '\n';
        std::cout << "c = " << c << '\n';
    }
};


// ============================================================
// MAIN
// ============================================================

int main()
{
    // --------------------------------------------------------
    // Base
    // --------------------------------------------------------

    Base base;

    std::cout << "--- Base ---\n";

    // base.a = 1;   // ❌ private
    // base.b = 2;   // ❌ protected

    base.c = 3;      // ✅ public

    base.displayBase();


    // --------------------------------------------------------
    // Public inheritance
    // --------------------------------------------------------

    PublicDerived publicObj;

    publicObj.display();

    // Public inheritance:
    //
    // Base public    → PublicDerived public
    // Base protected → PublicDerived protected
    // Base private   → inaccessible


    publicObj.c = 500;      // ✅ still public

    // publicObj.b = 600;   // ❌ protected
    // publicObj.a = 700;   // ❌ private


    // --------------------------------------------------------
    // Protected inheritance
    // --------------------------------------------------------

    ProtectedDerived protectedObj;

    protectedObj.display();

    // Protected inheritance:
    //
    // Base public    → ProtectedDerived protected
    // Base protected → ProtectedDerived protected
    // Base private   → inaccessible


    // protectedObj.c = 500;   // ❌ protected
    // protectedObj.b = 600;   // ❌ protected
    // protectedObj.a = 700;   // ❌ private


    // --------------------------------------------------------
    // Private inheritance
    // --------------------------------------------------------

    PrivateDerived privateObj;

    privateObj.display();

    // Private inheritance:
    //
    // Base public    → PrivateDerived private
    // Base protected → PrivateDerived private
    // Base private   → inaccessible


    // privateObj.c = 500;   // ❌ private
    // privateObj.b = 600;   // ❌ private
    // privateObj.a = 700;   // ❌ private


    return 0;
}