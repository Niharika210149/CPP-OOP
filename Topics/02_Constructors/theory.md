# Constructors

## Constructors

A constructor is a special member function that is invoked during the initialization of an object and is primarily used to establish its initial state.

A constructor has the same name as the class.

Constructor has no return type.

syntax :

```cpp
class <class_name>
{
public:

    <class_name>()
    {
        // constructor
    }
};
```

when you write `<class_name> object;`, C++ automatically invokes the constructors for object.

Constructors are invoked as part of object initialization.

A constructor is primarily used to initialize an object into a valid starting state.

Default Constructor :
> A constructor that can be called with no arguments.

example :
```cpp
Student()
{
}
```

---

## Constructor initializer list

 A constructor initializer list in C++ directly initializes class member variables before the constructor body executes.

directly initializes class member variables before the constructor body executes. 

It starts with a colon `:` after the constructor's parameter list, followed by a comma-separated list of variable initializations.

syntax :

```cpp
<constructor_name>(int a, float b)
    : a(a), b(b)
{
}
```

`(a)` and `(b)` are parameters.

this initializes the members directly.

Non-static data members are initialized in the order of their declaration in the class, regardless of the order in the constructor's member initializer list.

A class can have multiple constructors as long as their parameter lists differ.

C++ chooses the appropriate constructor based on the arguments.

This is constructor overloading.

- There are members that must be initialized, rather than assigned after the object has already been constructed.

- two important cases are :
> `const` data members :
>> A `const` data member must have a value established during object initialization because, after initialization, its value cannot be modified.

> Reference data members :
>> A reference data member must be bound to an existing object during initialization. A reference cannot first be created without referring to an object and then be made to refer to another object through assignment.

---

## Copy Constructor

A copy constructor is a constructor that initializes an object from another object of the same class.

When appropriate, C++ provides an implicitly-declared copy constructor.

If a copy constructor is not user-declared, C++ may implicitly declare one, subject to the language's special-member-function rules.

A typical form is:
```cpp
Student(const Student& other)
{
    // copy from other
}
```

```
Student s2 = s1;
       ↓
copy constructor

Student s2;
s2 = s1;
       ↓
copy assignment operator
```

---

## Shallow Copy Vs Deep Copy

### Shallow Copy

A **shallow copy** is a copy in which each data member is copied as-is from the source object to the destination object.

For pointer data members that point to owned dynamically allocated resources, shallow copying copies the pointer value rather than creating an independent copy of the resource.

Example :

```cpp
class Student {
private:
    int roll;
    int* marks;

public:
    Student(const Student& other)
        : roll(other.roll), marks(other.marks)
    {
    }
};
```

### Deep Copy

A deep copy creates an independent copy of dynamically allocated or otherwise owned data instead of merely copying the pointer or resource handle.

For a pointer data member, a deep copy creates new memory and copies the value stored in the source object's memory into the newly allocated memory.

Example :
```cpp
class Student {
private:
    int roll;
    int* marks;

public:
    Student(const Student& other)
        : roll(other.roll), marks(new int(*other.marks))
    {
    }
};
```

### The key distinction to remember

```text
Shallow copy
    ↓
copy the address

Deep copy
    ↓
copy the data
    ↓
into NEW memory
```

---

## Destructor

A destructor is a special member function that is automatically invoked when an object is destroyed.

A destructor is commonly used to release resources owned by an object when the object's lifetime ends.

Its syntax is:
```cpp
~Student()
{
}
```

- has the same name as the class preceded by ~
- has no return type
- takes no parameters
- cannot be overloaded
- is automatically called when the object is destroyed

Example:
```cpp
class Student
{
public:
    ~Student()
    {
        std::cout << "Destructor called\n";
    }
};
```

---

## Copy Assignment

a special member function used to copy the contents from one already existing object to another already existing object of the same class type.

By default, the compiler provides an implicit copy assignment operator that performs a shallow copy. However, if your class manages resources dynamically (like raw pointers or file handles), you must write a custom copy assignment operator to achieve a deep copy and prevent issues like memory leaks or double-free errors.

A typical copy assignment operator has the form:

```cpp
Student& operator=(const Student& other)
{
    if (this != &other)
    {
        // release current resource
        // copy resource from other
    }

    return *this;
}
```

---

## Rule of Three

The **Rule of Three** is a C++ guideline stating that if a class requires a user-defined destructor, copy constructor, or copy assignment operator to correctly manage a resource, it will generally require all three.

The three special member functions are:

1. Destructor
2. Copy constructor
3. Copy assignment operator

The rule is particularly relevant to classes that manually manage resources such as dynamically allocated memory through raw pointers.

These three operations correspond to three important situations:

- **Destructor** → releases the resource when the object is destroyed.
- **Copy constructor** → creates a new object with an independent copy of the resource.
- **Copy assignment operator** → replaces the resource of an already existing object with an independent copy.

Without appropriate implementations, copying a resource-owning class can result in problems such as:

- shared ownership when independent ownership is intended
- memory leaks
- dangling pointers
- double deletion

The Rule of Three is a consequence of the relationship between resource ownership and the three operations above.

example:
```cpp
class Student
{
private:
    int* marks;

public:

    // Constructor
    Student(int marks);

    // Copy constructor
    Student(const Student& other);

    // Destructor
    ~Student();
};
```
```text
           Student owns dynamic memory
                       │
          ┌────────────┼────────────┐
          ↓            ↓            ↓
     Constructor    Copy          Destructor
                    Constructor
          │            │            │
       acquire      duplicate     release
       resource      resource      resource
                       │
                       ↓
                Copy Assignment
                       │
                       ↓
                 replace resource
```

---

## Delegating Constructors

A **delegating constructor** is a constructor that delegates the initialization of an object to another constructor of the same class.

A delegating constructor uses another constructor's name in its member initializer list:

```cpp
Student()
    : Student(0, 0.0f)
{
}
```

The target constructor performs the member initialization and its constructor body executes first. After the target constructor completes, the body of the delegating constructor executes.

A constructor that delegates to another constructor cannot also initialize individual data members or base classes in the same initializer list.

Delegating constructors help avoid duplicated initialization logic by allowing one constructor to serve as the central initialization point.

A constructor delegation cycle is not allowed. If constructors delegate to each other in a cycle, the program is ill-formed and the compiler diagnoses the cycle.

---

## Key Takeaways

- A **constructor** is a special member function that is invoked during object initialization and is primarily used to establish the object's initial state.

- A constructor has the **same name as the class** and has **no return type**.

- Constructors are invoked automatically as part of **object initialization**.

- A **default constructor** is a constructor that can be called with no arguments.

- A class can have **multiple constructors** as long as their parameter lists differ. This is called **constructor overloading**.

- C++ selects an appropriate overloaded constructor based on the arguments used during initialization.

- A **constructor initializer list** directly initializes non-static data members and base-class subobjects before the constructor body executes.

- Non-static data members are initialized in the **order of their declaration in the class**, regardless of the order written in the constructor initializer list.

- `const` data members must be initialized during object initialization because they cannot be assigned a value after initialization.

- Reference data members must be initialized because a reference must be **bound to an object during initialization**.

- A **copy constructor** initializes an object from another object of the same class.

- A typical copy constructor has the form:

```cpp 
Student(const Student& other);
```

- `Student s2 = s1;` performs copy initialization and can invoke the copy constructor when a new object is being initialized.

- Copy construction is different from copy assignment:

```cpp
Student s2 = s1;   // copy constructor

Student s2;
s2 = s1;           // copy assignment
```

- A shallow copy copies data members as-is. For pointer members, this means the pointer value (address) is copied rather than the dynamically allocated object.

- A deep copy creates an independent copy of dynamically allocated or otherwise owned data.

- A destructor is a special member function that is automatically invoked when an object is destroyed.

- A destructor has the same name as the class preceded by ~, has no return type, takes no parameters, and cannot be overloaded.

- A copy assignment operator copies the state from one already-existing object to another already-existing object.

- Self-assignment must be considered when implementing a custom copy assignment operator.

- The Rule of Three states that if a class explicitly defines a destructor, copy constructor, or copy assignment operator, it will generally need all three when manually managing resources.

- Delegating constructors allow one constructor to delegate initialization to another constructor of the same class.

- In a delegating constructor, the target constructor performs the member initialization first, followed by the body of the delegating constructor.

- A constructor cannot both delegate to another constructor and initialize individual members/base classes in the same initializer list.

- Constructor delegation cycles are not allowed.

- explicit constructors prevent certain implicit conversions from being performed through the constructor.

```cpp
explicit Student(int roll);
```

- Direct initialization uses parentheses:

```cpp
Student s(101);
```

- Copy initialization uses the = form:

```cpp
Student s = Student(101);
```

- List initialization uses braces:

```cpp
Student s{101};
```

- List initialization helps prevent narrowing conversions.

For example:

```cpp
int x{3.14};      // ❌ narrowing conversion
int y = 3.14;     // allowed
```

- A constructor taking `std::initializer_list` receives special treatment during list initialization.

- A member initializer list and `std::initializer_list` are different concepts.

```text
Member initializer list
    ↓
: roll(roll), marks(marks)

std::initializer_list
    ↓
std::initializer_list<int>
```

- Constructors are primarily responsible for establishing a valid initial state, while destructors are responsible for cleanup when an object's lifetime ends.

- When a class manages resources manually, copying, assignment, and destruction must be designed consistently to avoid problems such as shallow-copy resource sharing, dangling pointers, memory leaks, and double deletion.










