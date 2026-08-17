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

For pointer data members, the **pointer value (address)** is copied rather than the dynamically allocated object being copied.

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







