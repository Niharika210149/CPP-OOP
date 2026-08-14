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

A class can have multiple constructors.

C++ chooses the appropriate constructor based on the arguments.

This is constructor overloading.

- There are members that must be initialized, rather than assigned after the object has already been constructed.

- two important cases are :
> `const` data members :
>> A `const` data member must have a value established during object initialization because, after initialization, its value cannot be modified.

> Reference data members :
>> A reference data member must be bound to an existing object during initialization. A reference cannot first be created without referring to an object and then be made to refer to another object through assignment.






