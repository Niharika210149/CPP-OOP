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

```text
 Animal
   ↓
  Dog
```

Each individual relationship is still a single-inheritance relationship:

```text
Animal → Dog
Animal → Cat
```

---

## Multiple Inheritance

Multilevel inheritance occurs when a derived class becomes the base class for another derived class.

we have a chain:

```text
   Base
     ↓
  Derived
     ↓
More Derived
```

For example:

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

---