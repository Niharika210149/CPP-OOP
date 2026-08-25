# Inheritance

## Definition

In C++, **inheritance** is a fundamental concept of object-oriented programming (OOP) that allows a new class (called the **derived or child class**) to inherit the properties, behaviors, and data members of an existing class (called the **base or parent class**).

- Base Class &rarr; parent class / superclass
- Derived Class &rarr; child class / subclass

Basic syntax or general form:

```cpp
class Derived : access-specifier Base
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




