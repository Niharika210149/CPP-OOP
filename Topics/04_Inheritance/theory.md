# Inheritance

## Definition

In C++, **inheritance** is a fundamental concept of object-oriented programming (OOP) that allows a new class (called the **derived or child class**) to inherit the properties, behaviors, and data members of an existing class (called the **base or parent class**).

- Base Class &rarr; parent class / superclass
- Derived Class &rarr; child class / subclass

Basic syntax or general form:

```cpp
class Derived : <access-specifier> Base
{
};
```

---

## Why do we use inheritance?

The main idea is reuse + specialization.

Suppose several classes share common behavior:

```text
Animal
 ├── Dog
 ├── Cat
 └── Horse
```

They may all have common characteristics:

```text
eat()
sleep()
```

Instead of repeating those functions in every class, we can place the common functionality in `Animal`.

Then specialized classes can add their own behavior.

So inheritance allows us to express:

An `Dog` is an `Animal`.

inheritance allows a derived class to specialize a more general base class.

---

## `public`, `protected`, and `private` Inheritance

The keyword after : determines the **inheritance mode**.

It controls how the **base class's accessible members are exposed through the derived class**.

It does not change the access level of the base class's original members themselves.

### Public inheritance

```cpp
class Dog : public Animal
{
};
```
The access mapping is:

| Base member | In `Dog` |
| :----: | :----: |
| public | public |
| protected | protected |
| private | inaccessible directly |

Public inheritance represents an is-a relationship.

```Dog is an Animal```

Anything that is publicly available from `Animal` remains publicly available through `Dog`.

For example, if `Animal` has a public `eat()` function, users of `Dog` can use the inherited `eat()` function.

This preserves the public interface of the base class.

### Protected inheritance

```cpp
class Dog : protected Animal
{
};
```

The access mapping is:

| Base member | In `Dog` |
| :----: | :----: |
| public | protected |
| protected | protected |
| private | inaccessible directly |

The important consequence is that **outside code cannot access the inherited public members through a `Dog` object**.

For example, if `Animal::eat()` is public:

```
Dog d;

// d.eat();    // ❌
```

because `eat()` became protected as a result of protected inheritance.

However, Dog itself can use the inherited functionality.

And classes derived from Dog can also access those protected members.

### Private inheritance

```cpp
class Dog : private Animal
{
};
```

The access mapping is:

| Base member | In `Dog` |
| :----: | :----: |
| public | private |
| protected | private |
| private | inaccessible directly |

This means even a class derived from `Dog` cannot directly access those inherited members through `Dog`.

For example:

```
Animal
   ↓ private inheritance
Dog
   ↓
Puppy
```

A public member inherited from `Animal` becomes private inside `Dog`, so `Puppy` cannot directly access it.

> Inheritance mode determines how the `public` and `protected` members of the base class are exposed through the derived class. Base-class `private` members remain inaccessible directly to the derived class.

---

## Single Inheritance

Single inheritance occurs when one derived class inherits from one base class.

Example 1:

```text
 Animal
   ↓
  Dog
```

Example 2:

```cpp
class Parent { };
class Child : public Parent { };
```

---

## Multilevel Inheritance

Multilevel inheritance occurs when a derived class becomes the base class for another derived class.

we have a chain:

```text
   Base
     ↓
  Derived
     ↓
More Derived
```

Example 1:

```text
 Animal
   ↓
 Mammal
   ↓
  Dog
```

- `Animal` is the base class of `Mammal`.

- `Mammal` is the derived class of `Animal`.

- `Mammal` is also the base class of `Dog`.

- `Dog` is the derived class of `Mammal`.

Example 2:

```cpp
class Grandparent { };
class Parent : public Grandparent { };
class Child : public Parent { };
```

---

## Multiple Inheritance

A single derived class inherits from two or more base classes simultaneously. 

This allows the child class to combine features from multiple distinct sources.

For example:

```cpp
class Mother { };
class Father { };
class Child : public Mother, public Father { };
```

### Ambiguity in Multiple Inheritance

Ambiguity can occur in multiple inheritance when two or more base classes provide members with the same name.

For example, if a derived class inherits from two base classes and both base classes contain a member function with the same name, a call to that function through the derived-class object may become ambiguous.

The compiler cannot determine which base-class member should be used.

> **Cause of Ambiguity**
```text
Base A
   │
   ├── start()
   │
   ↓
Derived
   ↑
   │
Base B
   │
   └── start()
```
The derived class has access to two different `start()` functions.

> **Resolving Ambiguity**

The ambiguity can be resolved by explicitly specifying the base class whose member should be used.

The **scope resolution operator** `::` is used together with the base-class name to identify the required member.

```text
Derived object
      ↓
BaseA::member()
      or
BaseB::member()
```

> In multiple inheritance, if multiple base classes provide members with the same name, an unqualified reference to that member can be ambiguous. The ambiguity can be resolved by explicitly qualifying the member with the appropriate base-class name.

---

## Hierarchical Inheritance

Multiple derived classes inherit from a single, shared base class. 

This creates a tree-like structure where one general class splits into several specialized classes.

Example 1:

```text
        Animal
       /      \
      ↓        ↓
     Dog       Cat
```

Here:

- `Animal` is the common base class.

- `Dog` derives from `Animal`.

- `Cat` derives from `Animal`.

Both derived classes can use the appropriate accessible members inherited from `Animal`.

---

## Hybrid Inheritance

Hybrid inheritance is a combination of two or more of the inheritance types listed above. 

For instance, combining Hierarchical and Multiple inheritance creates a diamond shape.

For example:

```cpp
class SharedBase { };
class ParentA : public SharedBase { };
class ParentB : public SharedBase { };
class Child : public ParentA, public ParentB { }; 
```

### The Diamond Structure

A particularly important form of hybrid inheritance is the **diamond-shaped inheritance** hierarchy.

Consider:

```text
          A
         / \
        B   C
         \ /
          D
```

Here:

- `A` is the common base class.

- `B` derives from `A`.

- `C` derives from `A`.

- `D` derives from both `B` and `C`.

> **diamond problem**

The problem is that the same base class appears through multiple inheritance paths.

There are two paths:

```text
D → B → A
D → C → A
```

That shared base can create:

- ambiguity

- duplicate base-class state

This is the key idea behind the diamond problem.

> **How C++ solves the Diamond Problem**

C++ provides **virtual inheritance** for this situation.

The idea is to make `B` and `C` share a single common `A` base subobject rather than each having their own separate `A` subobject.

`D` contains: one shared `A`

---

