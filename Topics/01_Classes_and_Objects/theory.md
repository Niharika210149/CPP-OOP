# Classes and Objects

## 1. Introduction

Object-Oriented Programming (OOP) is a programming paradigm in which programs are designed around **objects** that contain data and operations associated with that data.

C++ supports OOP through features such as:

- Classes
- Objects
- Encapsulation
- Inheritance
- Polymorphism
- Abstraction

The foundation of C++ OOP is the relationship between **classes and objects**.

---

## 2. What is a Class?

A class is a **user-defined type** that describes the data and operations associated with objects of that type. (or) A class defines a user-defined type from which objects can be created.

basic syntax:
    class ClassName
    {
        // members
    };

For example, a student can be represented using:
- Roll number
- Name
- Marks

and operations such as:
- Display student information
- Change marks
- Calculate percentage

A C++ class can represent these properties and operations together.

---

## 3. Object

An object is an instance of a type that has identity, state, and behavior. For a class type, an object is an instance of that class. An object generally occupies storage for its non-static data members.

basic syntax for creating an object :
    ClassName objectName;

A class can be used to create any number of objects.
Each object has its own non-static data members.

Conceptually :

s1
+----------------+
| roll = 101     |
| name           |
| marks          |
+----------------+

s2
+----------------+
| roll = 102     |
| name           |
| marks          |
+----------------+

s3
+----------------+
| roll = 103     |
| name           |
| marks          |
+----------------+

---

## 4. Data Members

Variables declared inside a class are called data members or non-static data members when they belong to individual objects.

---

## 5. Member Functions

Functions declared inside a class are called member functions.
A member function can operate on the object's data members.

---

## 6. State and Behaviour

State : State represents the data associated with an object.

Behaviour : Behavior represents operations that can be performed by the object.

This combination of state and behavior is one of the fundamental ideas behind object-oriented programming.

## 7. Accessing Members

The dot operator **(.)** is used to access members of an object.
A member function can also be called using the dot operator.

---

## 8. Access Specifiers

### Public :

Members declared under **public:** can be accessed from outside the class, subject to the usual language rules.

### Private :

Members declared under **private:** cannot be directly accessed from outside the class.

### Protected :

allows class members (variables and functions) to be accessed within the defining class and its derived (child) classes, while blocking direct access from outside the class hierarchy. It acts as a middle ground between public (accessible anywhere) and private (accessible only within the exact same class).

basic syntax :
    keyword followed by a colon (:)
    class class_name {
    public:
        //members
    }
    class class_name{
    private:
        //members
    }
    class class_name{
    protected:
        //members
    }

Members of a class are private by default.

---

## 9. This Pointer 

The **this** pointer identifies the current object inside a non-static member function.

---

## 10. Simplified representation of object and memory storage 

Each object has its own non-static data, while ordinary non-static member-function code is generally shared rather than duplicated inside each object.

simplified conceptual representation :

              OBJECT STORAGE

        s1                         s2
+----------------+        +----------------+
| roll = 101     |        | roll = 102     |
| marks = 92.5   |        | marks = 85.0   |
+----------------+        +----------------+
        │                         │
        │ this                    │ this
        │                         │
        └──────────┐   ┌──────────┘
                   ↓   ↓

             MEMBER FUNCTION CODE

        +---------------------------+
        | Student::display()        |
        |                           |
        | Machine instructions      |
        +---------------------------+

## 11. Class Vs Struct

**`class` and `struct` have essentially the same capabilities; their important default differences are member access and base-class access.**

Default Member Access: class members are private by default; struct members are public by default.

Default Inheritance: class inherits privately by default; struct inherits publicly by default.