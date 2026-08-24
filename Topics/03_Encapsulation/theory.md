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

# Encapsulation — Advanced Concepts

## Encapsulation + Inheritance

Encapsulation also affects how a base class exposes its internal state to derived classes.

A base class can keep its data private while providing controlled access to derived classes through protected member functions.

### Private Data in a Base Class

A private member of a base class cannot be directly accessed by a derived class.

However, the derived class can interact with the private state through accessible member functions provided by the base class.

This allows the base class to keep control over its internal representation while still allowing derived classes to use the functionality they need.

### Protected Members and Derived Classes

A protected member can be accessed directly within the class that declares it and within appropriate derived classes.

It cannot be directly accessed by ordinary outside code.

`protected` therefore provides a level of access between `private` and `public`.

Its main purpose in inheritance is to allow derived classes to access parts of a base class that should remain inaccessible to ordinary outside code.

### Protected Data vs Controlled Protected Interface

Making data `protected` allows derived classes to directly depend on the internal representation of the base class.

This can increase coupling between the base class and its derived classes because derived classes become dependent on how the base class stores its data.

A stronger encapsulation design is often to keep the data `private` and provide controlled `protected` member functions.

This allows derived classes to interact with the state without directly depending on its storage.

### Key Principle

> Derived classes should depend on the base class's interface rather than unnecessarily depending on its internal representation.

Keeping data private gives the base class greater control over:

- validation
- invariants
- internal representation
- state modification
- future implementation changes

### Public Read Access and Protected Modification

A class can deliberately provide different access levels for reading and modifying its internal state.

For example, a class may allow outside code to read a value through a public interface while restricting modification to the class and its derived classes through a protected interface.

This demonstrates that encapsulation is not simply about whether data is accessible or inaccessible.

It is also about controlling:

- who can access the state
- what kind of access is allowed
- how the state can be modified

### Encapsulation and Inheritance

Inheritance does not remove the need for encapsulation.

Instead, the base class must decide what parts of its interface should be available to:

- the base class itself
- derived classes
- ordinary outside code

A well-designed inheritance hierarchy keeps implementation details hidden while exposing only the functionality required by derived classes.

### Protected Is Not Inherently Bad

`protected` is not inherently a poor design choice.

It exists specifically to allow derived classes access to members that should remain inaccessible to ordinary outside code.

The important design question is whether derived classes should:

- access internal data directly, or
- interact with the base class through a controlled interface.

Using private data with protected member functions generally provides stronger encapsulation than exposing the data itself as protected.

### Encapsulation and Coupling

Direct access to protected data can create stronger coupling between a base class and its derived classes.

When derived classes depend directly on internal data, changes to the base class's internal representation may require changes to derived classes.

When derived classes depend on a controlled interface instead, the base class has greater freedom to change its internal implementation without affecting derived classes.

Therefore:

> Encapsulation reduces unnecessary coupling between a base class and its derived classes by hiding internal representation behind controlled interfaces.

### Core Mental Model

```text
Base Class
    ↓
Private internal state
    ↓
Controlled interface
    ↓
Derived Class
    ↓
Uses required functionality
without directly depending on internal representation
```

---

## Encapsulation + Construction

Encapsulation is not only about protecting an object's state after it has been created. It also involves ensuring that the object is created in a valid state.

### Constructor and Invariant

An **invariant** is a condition that should remain true for a valid object throughout its lifetime.

The constructor is responsible for **establishing the invariant during object creation**.

For example, if a class requires a value to remain within a certain valid range, the constructor should validate the initial value before allowing the object to exist in an invalid state.

The invariant itself is a design condition. It is not a special C++ keyword.

```text
Invariant
    ↓
Rule defining valid object state

Constructor
    ↓
Establishes the invariant

Member functions
    ↓
Preserve the invariant
```

Validating only through a setter is not sufficient when an invalid object can already be created through the constructor.

A well-encapsulated class should prevent invalid state from being established during construction.

After construction, member functions that modify the object's state should continue to preserve the invariant.

---

## `class` vs `struct` in Encapsulation

Both `class` and `struct` support encapsulation.

They can both contain:

- private members
- protected members
- public members
- member functions
- constructors
- destructors
- inherited members

The main difference is their **default access level**.

### `class`

Members of a `class` are `private` by default.

Therefore, if no access specifier is written, the members cannot be accessed directly from outside the class.

### `struct`

Members of a `struct` are `public` by default.

Therefore, if no access specifier is written, the members can be accessed directly from outside the struct.

`class` and `struct` have essentially the same capabilities. Their important differences are their default member access and default inheritance access.

---

## Encapsulation + Resource Ownership

Encapsulation can protect not only ordinary data but also **resources owned by an object**.

A resource may include dynamically allocated memory, file handles, locks, sockets, or other resources that require proper management.

### Resource Ownership

When a class owns a resource, the class is responsible for managing that resource throughout its lifetime.

This commonly involves:

```text
Acquire resource
      ↓
Use resource
      ↓
Release resource
```

Keeping the resource private prevents outside code from directly interfering with the resource or its ownership.

- **Constructor and Resource Acquisition**

A resource can be acquired during object construction.
The object then becomes responsible for that resource.

```text
Object construction
        ↓
Resource acquired
        ↓
Object owns resource
```

- **Destructor and Resource Release**

When the object's lifetime ends, its destructor can release the resource it owns.

```text
Object lifetime ends
        ↓
Destructor
        ↓
Resource released
```

This connects resource ownership with the lifetime of the object.

### RAII

**RAII** stands for **Resource Acquisition Is Initialization**.

The basic RAII principle is:

A resource is acquired during object initialization and automatically released when the object's lifetime ends.

This ties the lifetime of a resource to the lifetime of the object that owns it.

```text
Constructor
    ↓
Acquire resource
    ↓
Object lifetime
    ↓
Destructor
    ↓
Release resource
```




