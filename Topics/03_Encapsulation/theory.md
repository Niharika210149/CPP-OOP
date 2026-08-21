# Encapsulation

## What is Encapsulation ?

**Encapsulation** in object-oriented programming is the practice of wrapping data (variables) and behavior (methods) together inside a single unit, like a class. It hides the internal state of an object from the outside world and blocks direct changes, requiring code to interact through safe, public methods instead.

```text
Encapsulation
      │
      ├── Bundle data + operations
      │
      └── Control access to representation
```

---

## Data Hiding

Data hiding means restricting direct access to an object's internal data.

---

## Getter 

A getter is a public member function used to read or retrieve the value of a private/protected data member.

Example:

```cpp
class Student {
private:
    int marks;

public:
    int getMarks() const {
        return marks;
    }
};
```

---

## Setter

A setter is a public member function used to modify the value of a private/protected data member.

Example:

```cpp
void setMarks(int m) {
    if (m >= 0 && m <= 100) {
        marks = m;
    }
}
```

---

## Setter + Getter Together

```cpp
class Student {
private:
    int marks;

public:
    void setMarks(int m) {
        marks = m;
    }

    int getMarks() const {
        return marks;
    }
};
```

---

## Invariants

An invariant is a condition that should remain true for a valid object throughout its lifetime.

```text 0 ≤ marks ≤ 100```

The condition is an invariant of the class.

---

## Controlled Interface

The collection of public members through which outside code interacts with an object is often called its interface.

- Interface Vs Implementation

> The **interface** describes what operations are available.
> The **implementation** describes how those operations work internally.

---

## Access Specifiers

C++ provides three access specifiers for controlling access to class members:

- `private`
- `protected`
- `public`

Access specifiers are an important part of **encapsulation** because they control which parts of a class can be accessed or modified from different contexts.

They also become important in **inheritance** because they determine which members can be accessed directly by derived classes.

---

### 1. `private`

A `private` member can be accessed directly only from within the class that declares it.

It cannot be directly accessed by:

- ordinary outside code
- derived classes

Example:

```cpp
class Student {
private:
    int marks;

public:
    void setMarks(int m) {
        marks = m;       // valid
    }

    int getMarks() const {
        return marks;    // valid
    }
};
```

---

### 2. `protected`

A `protected` member can be accessed directly:

- within the class that declares it
- within derived classes

It cannot be directly accessed by ordinary outside code.

Example:

```cpp
class Student {
protected:
    int marks;
};

class GraduateStudent : public Student {
public:
    void changeMarks()
    {
        marks = 95;       // valid
    }
};
```

---

### 3. `public`

A `public` member can be accessed from outside the class through an object, subject to the usual language rules.

It can also be accessed from within the class and by derived classes.

Example:

```cpp
class Student {
public:
    void display() {
        // ...
    }
};

Student s;

s.display();       // valid
```

---

