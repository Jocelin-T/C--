# Object Oriented Programming (OOP)
## OOP Principles
### Encapsulation
- It's the principle of create a container (the Class) around functions and variable. 
### Abstraction
- It's the principle to show/hide members of a Class to the User, using keyword like: private, public, protected.
### Inheritance
- It's the principle of creating a Derived Class of a Base Class. All public and protected members will be accessible in a Derived Class
### Polymorphism
- Its' the principle of overriding a method in a Derived Class, comming from a Base Class (the method)
### Coupling
- It's the principle of how much are 2 Classes "connected".
  - High coupling mean that the Classes are not really flexible and work a lot together
  - Low coupling mean that the Classes are more flexible
### Composition
- It's the principle of using multiple little Object to construct a larger structures. Each one of this little Object manage just a part. Use "has-a" if you don't know when to use it example: 
  - A car has-a engine. Not: A car is-a engine.

## SOLID Principles
### S -> Single Responsability Principle (SRP) 
- A Class who focus on a **Single** responsability or purpose.
### O -> Open/Close Principle (OCP)
- A Class should be **Open** for extension but **Close** for modification
### L -> Liskov Substitution Principle (LSP)
- The Objects of a Base Class should be **Replacerable** with Objects of it's Derived Class, without affecting the correctness of a program.
### I -> Interface Segregation Principle (ISP)
- Clients should **Not be forced** to depend on interfaces they do not use.
### D -> Dependency Inversion Principle (DIP)
- High-level modules should not depend on low-level modules. Both should **Depend** on abstraction