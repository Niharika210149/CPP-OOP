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
```cpp
    class ClassName
    {
        // members
    };
```

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

```
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
```

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

The dot operator **`.`** is used to access members of an object.

A member function can also be called using the dot operator.

---

## 8. Access Specifiers

### Public :

Members declared under **`public:`** can be accessed from outside the class, subject to the usual language rules.

### Private :

Members declared under **`private:`** cannot be directly accessed from outside the class.

### Protected :

allows class members (variables and functions) to be accessed within the defining class and its derived (child) classes, while blocking direct access from outside the class hierarchy. It acts as a middle ground between public (accessible anywhere) and private (accessible only within the exact same class).

basic syntax :
```cpp
    //keyword followed by a colon (:)
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
```

Members of a class are private by default.

---

## 9. Simplified representation of object and memory storage 

Each object has its own non-static data, while ordinary non-static member-function code is generally shared rather than duplicated inside each object.

simplified conceptual representation :

```
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
```

## 10. Class Vs Struct

**`class` and `struct` have essentially the same capabilities; their important default differences are member access and base-class access.**

**Default Member Access :** class members are private by default; struct members are public by default.

**Default Inheritance :** class inherits privately by default; struct inherits publicly by default.

---

## 11. Object size

- Represents the total size of an object in bytes.
- Always measured using the `sizeof` operator.
- Includes the sizes of all non-static data members plus any hidden padding bytes.

syntax : 
```cpp 
sizeof()
```

---

## 12. Memory layout 

memory layout defines exactly how data members, padding, and hidden pointers are arranged within those bytes.

---

## 13. Alignment 

Alignment is a requirement concerning the addresses at which objects of a particular type can be stored.

For example, if a type requires 4-byte alignment, suitable addresses may be:
    ```1000
       1004
       1008
       1012```

The compiler can insert padding so that a member begins at an appropriately aligned address.

Alignment requirements are implementation-dependent.

---

## 14. Padding

Padding is unused space inserted by the implementation between or after data members to satisfy alignment requirements.

A typical layout on a system where ```int``` requires 4-byte alignment is:
```
Offset
0       +---------+
        | char a  | 1 byte
        +---------+
1       | padding | 1 byte
2       | padding | 1 byte
3       | padding | 1 byte
        +---------+
4       |         |
        |  int x  | 4 bytes
        |         |
        +---------+
8       | char b  | 1 byte
        +---------+
9       | padding | 1 byte
10      | padding | 1 byte
11      | padding | 1 byte
        +---------+

Total = 12 bytes
```

---

## 15. Tail Padding

Padding can also occur at the end of an object. This is called tail padding.

layout :
```
Offset
0       +---------+
        |         |
        |  int x  | 4 bytes
        |         |
        +---------+
4       | char a  | 1 byte
        +---------+
5       | char b  | 1 byte
        +---------+
6       | padding | 1 byte
7       | padding | 1 byte
        +---------+

Total = 8 bytes
```
Tail padding helps ensure that objects placed consecutively, such as elements of an array, satisfy the appropriate alignment requirements.

The ordering of data members can affect the amount of padding and consequently the size of an object.

---

- Ordinary non-static member-function code is generally shared rather than duplicated in each object.
- An empty class typically has a size of 1 byte.
- A static data member belongs to the class, not to each individual object.
- Static data-member storage is not included in the storage of each object.

---

## 16. This Pointer 

The **`this`** pointer is a special pointer available inside a non-static member function.

It points to the object for which the member function was invoked.

Since `this` is a pointer to the current object, the `->` operator is used to access the object's members.

syntax :
```cpp
this->roll
```
### `.` vs `->`

The dot operator (`.`) is used with an object.

The arrow operator (`->`) is used with a pointer to an object.

```cpp
Student s1;
Student *ptr = &s1;

s1.roll;       // object → .
ptr->roll;     // pointer → ->
```
The expression:

```cpp
ptr->roll
```

is equivalent to:

```cpp
(*ptr).roll
```

Similarly:

```cpp
this->roll
```

is equivalent to:

```cpp
(*this).roll
```

because `this` is a pointer.

A common use of `this` is resolving a conflict between a data member and a function parameter having the same name.

A member function can return a reference to the current object.

function calls can be chained :
```cpp
Student s1;

s1.setRoll(101).setMarks(92.5f);
```

---

## 17. `const` Member Functions

A member function can be declared with `const` after its parameter list:

```cpp
void display() const
{
    std::cout << roll;
}
```

The `const` qualifier means that the function promises not to modify the object's ordinary non-static state through the function.

A `const` member function can be called on both:

- non-const objects
- const objects

A const object cannot normally call a non-const member function because that function may modify the object.

---

## 17.1 `this` in a `const` Member Function

Inside an ordinary non-const member function, the conceptual type of `this` is:

```text
Student*
```

Inside a `const` member function, the conceptual type is:

```text
const Student*
```
```text
Student*
    ↓
pointer to a non-const Student

const Student*
    ↓
pointer to a const Student
```

---

## 17.2 `const Student*` vs `Student* const`

These declarations are different:

```cpp
const Student* ptr;
```

means:

> `ptr` is a pointer to a const `Student`.

The object cannot be modified through `ptr`.

Whereas:

```cpp
Student* const ptr = ...;
```

means:

> `ptr` itself is a const pointer to a `Student`.

The pointer cannot be changed to point somewhere else.

---

## 18. Const Member Function Access Rules

The following combinations are possible:

| Object | `display() const` | `setRoll()` |
|---|---|---|
| `Student` | Valid | Valid |
| `const Student` | Valid | Invalid |

Therefore:

> A `const` member function can be called by both const and non-const objects, while a non-const member function cannot normally be called on a const object.

---

## 19. Key Takeaways

### `this` Pointer

1. `this` is a special pointer available inside a non-static member function.
2. `this` points to the object for which the member function was invoked.
3. `this` allows a member function to access the current object's members.
4. `this->member` accesses a member through the current-object pointer.
5. `this->member` is equivalent to `(*this).member`.
6. The `.` operator is used with objects.
7. The `->` operator is used with pointers to objects.
8. `this` can resolve naming conflicts between data members and parameters.
9. `*this` represents the current object.
10. `return *this` can return a reference to the current object.
11. Returning `*this` can enable member-function chaining.
12. `return this` returns a pointer, while `return *this` can return the current object by the appropriate return type.

### `const` Member Functions

13. A member function can be declared `const` by placing `const` after its parameter list.
14. A `const` member function promises not to modify the object's ordinary non-static state through the function.
15. A `const` member function can be called on both const and non-const objects.
16. A non-const member function cannot normally be called on a const object.
17. Inside a `const` member function, the conceptual type of `this` is `const ClassName*`.
18. A `const` member function can read ordinary data members but cannot normally modify them.
19. `const Student*` means a pointer to a const `Student`; it is different from `Student* const`.
20. `const` member functions are useful for functions that only observe the object's state.

---

