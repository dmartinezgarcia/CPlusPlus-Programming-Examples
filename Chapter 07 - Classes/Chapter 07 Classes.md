# 7. Chapter 07 - Classes

In this chapter we will focus on the importance of data abstraction.

In later chapters (Chapters 13 and 14) we will see our to control what happens when an objects instantiated from a class are copied, moved, assigned or destroyed and how to define our own operators.

## 7.1 Classes and abstract data types

A **class** allows us to define our own data types, which we can use to mirror concepts in real problems we are trying to solve. They define a new type and a new scope in which we can create class data, function and type members.

In order to give a proper definition of classes the concepts of **interface** and **implementation** must be defined first:

- We understand **implementation** as the collection of members of a class that define data and any other operations not intended to be used by the code that uses the type defined by the class. For this reason, these members are usually *private*.
- We understand **interface** as the operations that the type defined by the class supports, usually the interface does not include data members. For this reason, these operations are usually *public*.

Having the concepts above defined, now we can speak about the *fundamental ideas* behind a class, **data abstraction** and **encapsulation**. 

- The concept **data abstraction** refers to a programming and design technique that focuses on the interface to a type defined by a class, programmers can ignore the details of how a type is represented and think instead about the operations that the type can perform. It relies on the separation of the **interface** and the **implementation**. 

- The concept **encapsulation**, enforces the separation of a class **interface** and **implementation**, and by doing so hides the implementation details of the type defined by the class.

A properly designed class, one that implements the concepts of **data abstraction** and **encapsulation** described above, is an **abstract data type**. The class designer worries about how the class is implemented while the programmer that uses it only cares about the operations it can do with it.

### 7.1.1 Member functions

A **class** has members, those that are functions are known as **member functions**, in this section we will look at how to declare and define these members. They must be declared inside its class, and they may be defined inside the class itself or outside the class body.

Functions that are defined inside the class are implicitly `inline`, the example below shows an example of a function declared and defined inside the class, the `getVitality` function:

```cpp
class Animal
{
    // Member function declared and defined inside the class and therefore inline.
    int getVitality() const { return vitality; }
    // Member function declared inside the class and defined outside the class.
    int& addVitality(int vitalityToAdd);
    
    // Data member.
    int vitality = 0;
};

// Non member function.
std::ostream &print(std::ostream& output_stream, const Animal& animal);
```

The function `addVitality` is declared inside the class but defined outside it, as with any other function the declaration must match the definition, that is the return type, the parameter list, the name and also, if it is a constant member function, the `const` qualifier for `this`, we will see constant member functions in the next section.

When defined outside the class, the member function must include the name of the class of which it is a member. The following is an example of the definition of the `addVitality` function member:

```cpp
int Animal::addVitality(int vitalityToAdd)
{
    this->vitality = vitalityToAdd;
    return this->vitality;
}

```

In order to call a member function the dot operator, `.`, is used, like in the following example:

```cpp
Animal cow;

cow.getVitality();
```

Member functions access the object on which they were called through an extra implicit parameter known as `this`, which is a `const` pointer containing the address of the object which called the member function. Keeping this mind, the previous example would be equivalent to this one:

```cpp
Animal cow;

// Passing `this` explicitly.
Animal::getVitality(&cow);
```

In a member function, is not necessary to deference the `this` pointer, any use of a member of the class is assumed to be dereferenced from this pointer, this means that the member function `getVitality` could be written in the two following ways:

```cpp
int getVitality() const { return this->vitality; }
int getVitality() const { return vitality; }
```

#### 7.1.1.1 Constant member functions

As you might have noticed in the previous section, the function `getVitality` contains a `const` qualifier after the parameter list, the purpose of this `const` is to modify the type of the implicit `this` pointer. Member functions of this kind are known as **constant member functions**.

```cpp
class Animal
{
    // Constant member function because of the const qualifier after the parameter list.
    int getVitality() const { return vitality; }
    // Ordinary member function with no const qualifier after the parameter list.
    int& addVitality(int vitalityToAdd);
    
    // Data member.
    int vitality = 0;
};
```

By default `this` is constant pointer to non-constant object, with this extra qualifier, it would be a constant pointer to constant object, is as if the compiler rewrote the member function to look like this:

```cpp
int getVitality(const Animal * const this);
```

Constant member functions in regards to `this` follow the same initialization rules as a constant pointer to non-constant object, which means that `this` can't be bonded to an object which is not constant. This means that an ordinary member function can't be called with a constant object or references or pointers that point to a constant object.

With this mind, it is important to note that a member function can be overloaded based on the `const` type qualifier applied to `this`, for the same reasons that we can overload a function based on whether a pointer parameter points to `const` or not `const`: a member function will be viable for `const` objects although a **constant member function** will be a better match if it exists, while the **constant member function** will only be possible with `const` objects. For example the class below:

```cpp
class Animal
{
    // Constant member function because of the const qualifier after the parameter list.
    const Animal &combineVitality() const { /* do something */ return *this; }
    Animal &combineVitality() { /* do something */ return *this; }
};
```

When calling the `combineVitality` function, the `const` of the object on which is called determines which member function is executed.

#### 7.1.1.2 Class and scope of member functions

The class itself defines a scope with its own functions and data members which are contained inside this scope. This means that in the example below, the variable `vitality` used in `getVitality` member function is resolved to the `vitality` data member of the class:

```cpp
class Animal
{
    // This function accesses the variable vitality, which is resolved to the data member declared below.
    int getVitality() const { return vitality; }
    int vitality = 0;
};
```

As we will see in the next sections, the compiler compiles the member declarations first and afterwards the member function bodies. This means that a member function body can use other members of the class regardless of where in the class those members appear.

#### 7.1.1.3 Defining a function to return `this`

This kind of member functions are useful when the behavior of a built-in operator is intended, consider the following example:

```cpp
Animal& Animal::combineVitality(const Animal& vitalityAnimal)
{
    this->vitality += vitalityAnimal.vitality;
    return *this;
}
```

Notice that the example above returns a reference to the object on which it was called, this allows us to concatenate a sequence of these actions into a single expression:

```cpp
Animal animalOne, animalTwo, animalThree;

AnimalOne.combineVitality(animalTwo).combineVitality(animalThree);
```

The above expression is equivalent to:

```cpp
AnimalOne.combineVitality(animalTwo);
AnimalOne.combineVitality(animalThree);
```

**Constant member functions** that return `this` as a reference should return it as reference to `const`,

### 7.1.2 Nonmember class-related functions

Functions that define operations that are conceptually part of the interface of a class but not part of the class itself are known as **nonmember class-related functions**. 

Nonmember functions can are defined as any other function but they should be declared in the same header file as the class itself, this way the users only need to include one file to use any part of the interface, an example of a nonmember class-related function is the following:

```cpp
ostream &print(ostream &os, const Animal &item)
{
    os << "The vitality of the animal is: " << item.vitality;
    return os;
}
```

### 7.1.3 Constructors

Each class defines how instances of it can be initialized using **constructors**, a constructor is a member function whose job is to initialize the **data members** of a class object, it is executed whenever an object of the class is created.

A constructor must have the same name as the class, they have a parameter list and a function body but no return type. Constructors can be overloaded in the same way as normal functions, differing in the number or types of its parameters, this means that a class can have multiple constructors.

Unlike other member functions a constructor can't declare the `this` parameter as `const`, there is no such thing as constant constructors. When creating a `const` object it doesn't assume the `const` status until it is initialized, this means that a constructor can write to the object on which is called during the construction phase.

#### 7.1.3.1 Synthesized default constructor and default constructor

In the following piece of code:

```cpp
Animal cow;
```

We do not supply an initializer for the object instance from the class `Animal`, it is default initialized by the **synthesized default constructor**, one generated by the compiler implicitly that takes no arguments. This constructor initializes each data member as follows:

- If there is an **in-class initializer**, use it to initialize the data member.
- If there is no **in-class initializer**, the data member is default initialized.

The following is an example of two data members with an in-class initializer and no in-class initializer each:

```cpp
class Animal
{
    // This data member has an in-class initializer so it is initialized to that value in the constructor.
    int vitality = 0;
    // This data member has no in-class initializer so it is default initialized to the empty string.
    string name;
};
```

The compiler only generates a **synthesized default constructor** if a class declares no constructors, however usually a class must define its own **default constructor**, there are many reasons for this:

1. If a constructor is defined for a particular scenario, most likely the remaining scenarios will require extra control than the one the synthesized constructor provides.
2. Some objects, such as those of built-in type or compound types, defined inside a block have an undefined value when they are default initialized, this applies for data members of these types as well. This scenario can be solved by providing **in-class initializers** for those members or by defining a **default constructor**.
3. Sometimes the compiler is unable to to generate a **synthesized default constructor**, for example when a class declares a member that is a class type with no default constructor.

Just like the **synthesized default constructor**, a **default constructor** doesn't take any arguments.

#### 7.1.3.2 Defining a default constructor

The following is an example of a class with multiple constructors:

```cpp
class Animal
{
    // Constructors.
    Animal() = default;
    Animal(int str, int dex) : strength(str), dexterity(dex), vitality(str*10), stamina(dex*) {}
    Animal(const string &n, int str, int dex) : strength(str), dexterity(dex), vitality(str*10), stamina(dex*), name(n) {}
    Animal(const string &n);

    // Data members.
    int vitality = 10;
    int strength = 10;
    int dexterity = 10;
    int stamina = 10;
    string name;
};
```

The first constructor uses the `= default` keyword:

```cpp
Animal() = default;
```

By declaring it in that way, we are telling the compiler that this is the default constructor of this class and that it should behave the same way as the synthesized default constructor that the compiler generates. The `default` keyword can appear in the declaration inside the class or in the definition outside the class body, in which case the default constructor will be inlined.

The second and third constructors use **constructor initializer lists**:

```cpp
Animal(int str, int dex) : strength(str), dexterity(dex), vitality(str*10), stamina(dex*) {}
Animal(const string &n, int str, int dex) : strength(str), dexterity(dex), vitality(str*10), stamina(dex*), name(n) {}
```

The part in between the colon and the curly braces enclosing the function body is known as **constructor initializer lists**, these specify initial values for one or more data members of the object being created in a comma separated list and the initializer value enclosed in parentheses or curly braces.

When a data member is not included in the **constructor initializer list** it is default initialized using the same process as the **synthetized default constructor**, in this regard, **constructor initializer lists** should not override in-class initializers except to use a different value.

The fourth constructor is one that only includes the declaration:

```cpp
Animal(const string &n);
```

This is one that has to be defined outside the class body, a possible definition could be the following:

```cpp
Animal::Animal(const string &n)
{
    this->name = n;
}
```

Because constructors have no return type, notice that the definition starts with the name of the function, which is the same as the class because it is a constructor. It also includes the name of the class to indicate that it is the constructor of that class. When the body of the function starts executing, the data members are initialized to their **in-class initializers**, to the **construction list initializer** values or **default initialized**.

#### 7.1.3.3 More about constructor initializer lists

In the previous section we defined **constructor initializer lists**, it is important to notice the difference between these two types of constructors:

```cpp
class AnimalExample0
{
    public:
    AnimalExample0(int vit) : vitality(vit) {}

    private:
    int vitality = 0;
};

class AnimalExample1
{
    public:
    AnimalExample1(int vit) : { this->vitality = vit; }

    private:
    int vitality = 0;
};
```

In the first case we are *initializing* the data members, while in the second we are *assigning a value* to the data member in the constructor, this difference is significant depending on the type of the data member and often the difference can be ignored, however there are some data members that must be initialized:

1. Constant data members.
2. References.
3. Class types that do not have a default constructor.

For these data members, a **constructor initializer must be provided** as it is not possible to assign a value to them, an example shown below:

```cpp
class AnimalExample2
{
    public:
    AnimalExample2 (int vit) : vitality(vit), vitalityRef(vitality) {}

    private:
    const int vitality;
    const int &vitalityRef;
};
```

A **constructor initializer list** specifies the values used to initialize the members but not the order in which those members are initialized. Members are initialized in the order in which they appear in the class definition, the first member is initialized first and then the second and so on. This is a good reason why to write constructor initializers that do not create interdependency between members, for example:

```cpp
class Animal
{
    public:
    // This should be avoided.
    // Animal (int vit) : vitality_zero(vit), vitality_one(vitality_zero) {}
    // This is a much better option.
    Animal (int vit) : vitality_zero(vit), vitality_one(vit) {}

    private:
    int vitality_zero;
    int vitality_one;
}
```

Some compilers warn about these situations.

It is also possible to provide a default argument to a parameter in the constructor and then use it in the **constructor initializer list**, as shown below:

```cpp
class Animal
{
    public:
    Animal(int vit = 0) : vitality(vit) {}

    private:
    int vitality;
};
```

By doing this we define the default constructor that can be called without taking any argument as well as another constructor that takes an integer argument.

#### 7.1.3.4 Delegating constructors

A **delegating constructor** is a constructor that includes a constructor initializer list that has one entry that designates another constructor of the same class to perform the initialization, they delegate all or some of its work to another constructor. An example is shown below:

```cpp
class Animal
{
    public:
    // A non delegating constructor.
    Animal(string &s, int vit, int str) : name(s), vitality(vit), strength(str) {}
    // A delegating constructor.
    Animal() : Animal("", 0, 0) {}
    // A delegating constructor.
    Animal(string &s) : Animal(s, 0, 0) {}
    // A delegating constructor delegating to a delegating constructor.
    Animal(string &s, int vit) : Animal(s, vit, 0) { this->strength = 10; }
    
    private:
    string name;
    int vitality;
    int strength;
};
```

When a constructor delegates to another constructor, the constructor initializer list and function body of the delegated-to constructor are executed.

#### 7.1.3.5 The role of the default constructor

The default constructor is used automatically whenever an object is **default initialized** or **value initialized**. Default initialization occurs in the following scenarios:

- When defining non-static variables or arrays at block scope with no initializers.
- When a class containes class type members that use the synthesized default constructor.
- When class type members are not initialized in a constructor initializer list.

While value initialization occurs in the following scenarios:

- During array initialization when fewer initializers than the size of the array are provided.
- When defining an static object without an initializer.
- When value initialization is explicitly used.

#### 7.1.3.6 Converting constructors

A **converting constructor** is a non explicit constructor that can be called with a single argument. Such constructors implicitly convert from the argument's type to the class type. Every of these constructors define an implicit conversion to a class type.

The following is an example of a function using a **converting constructor**:

```cpp
class Animal
{
    public:
    // This is a converting constructor.
    Animal(string n) : name(n) {}
    inline Animal &combine(Animal elem) { this->name += elem.name; return *this; }

    private:
    string name;
};

int main(void)
{
    Animal elem0 = Animal("Cow");
    string elem1 = "bell";

    elem0.combine(elem1); // Same as elem0.combine(Animal(elem1)).
    
    return 0;
}
```

The compiler will only apply one class-type conversion, in the case above it converts from `int` to `Animal`, however in the example below:

```cpp
elem0.combine("Hello"); // Will not compile.
```

The compiler will raise an error because it would need to perform an implicit class conversion from C-style string to `string` and then another implicit class conversion to `Animal`.

It is possible to supress this behaviour from constructors with one single argument by using the keyword `explicit` in the constructor declaration, like this:

```cpp
explicit Animal(string n) : name(n) {}
```

With the declaration above, none of the examples above will compile, compiler will raise an error stating that the constructor has been declared `explicit`. This keyword only makes sense for constructors that are imply an implicit conversion, and those are the ones that take a single argument.

It is possible to use `explicit` conversions to force an explicit conversion like in the examples below:

```cpp
string name = "Cow";
elem0.combine(Animal(name));
elem0.combine(static_cast<Animal>(name));
```

A constructor with an `explicit` keyword can only perform implicit conversions when using direct initialization, for example:

```cpp
string name = "Cow";
Animal elem(name); // Valid as using the direct form of initialization.
Animal elem1 = name; // Not valid as using the copy form of initialization.
```

### 7.1.4 Copy, assignment and destruction

In addition to initialization, classes also control what occurs when we copy, assign and destroy objects instanced from the class type. If these operations are not defined then the compiler will synthesize them for us, in a similar way to the synthesized default constructor. Some scenarios where this operations occur are the following:

- When initializing an object or when passing an object by value, the copy operation is performed.
- When using the assignment operator, the assign operation is performed.
- When a local object of the class is destroyed after the body of a function finishes, the destroy operation is performed.

In some cases, such as those where the class allocates resources outside the class memory, the synthesized operations are unlikely to work correctly. We will look at how to define our own operations for copying, assigning and destroying in later chapters.

## 7.2 Access control and encapsulation

Encapsulation provides two important advantages:

1. User is unable to corrupt the state of an object instance from a class that is encapsulated properly.
2. The implementation of a properly encapsulated class can change overtime without requiring changes in the code that uses that class, unless the interface changes.

### 7.2.1 Access specifiers

To enforce encapsulation **access specifiers** are used, these define whether members of a class are accessible to users of the class or only to friends and members of the class. They may appear multiple times within a class, each specifier sets the access of the following members up to the next specifier. The two possible access specifiers are `public`and `private`:

- Members defined after a `public` access specifier are accessible to all parts of the program and define the interface of the class.
- Members defined after a `private` access specifier are accessible to the member functions of the class but not to the users of the class, these members hide the implementation.

The following is an example of a class defined using access specifiers:

```cpp
class Animal
{
    public:
        Animal() = default;
        Animal(int str, int dex) : strength(str), dexterity(dex), vitality(str*10), stamina(dex*) {}
        Animal(const string &n, int str, int dex) : strength(str), dexterity(dex), vitality(str*10), stamina(dex*), name(n) {}
        Animal(const string &n);

    private:
        int vitality = 10;
        int strength = 10;
        int dexterity = 10;
        int stamina = 10;
        string name;
};
```

A class can contain from zero to multiple access specifiers without restrictions on how many times the same specifier can appear.

### 7.2.2 Friend functions and classes

The **friend** mechanism is one that allows other functions and classes to access the non-`public` members of the objects instanced from a class. This access has the same privileges as the members of the class.

A class makes another function its friend by including a declaration for that function preceeded by the keyword `friend`, see below for an example:

```cpp
class Animal
{
    // Declaration of a nonmember function as a friend, the one that specifies access of this function to the class members.
    friend Animal combine(const Animal &animalOne, const Animal &animalTwo);

    public:
        Animal() = default;
        Animal(int str, int dex) : strength(str), dexterity(dex), vitality(str*10), stamina(dex*) {}
        Animal(const string &n, int str, int dex) : strength(str), dexterity(dex), vitality(str*10), stamina(dex*), name(n) {}
        Animal(const string &n);

    private:
        int vitality = 10;
        int strength = 10;
        int dexterity = 10;
        int stamina = 10;
        string name;
};

// Declaration of a nonmember function, the one that allows users of the class to call the function.
Animal combine(const Animal &animalOne, const Animal &animalTwo);
```

It is also possible to define a friend function inside the class body, making it implicitly `inline`.

Friend declaration can only appear in the class definition, anywhere in it. It is important to note that friends are not members of the class and are not affected by **access specifiers**. It is a good idea to group friend declarations together at the beginning or at the end of the class.

As you might have noticed in the example, there are two declarations for the function `combine`, this is because the one with the `friend` just specifies access while the other one allows for users of the class to call the function, some compilers just require the one with the `friend` keyword but it is recommended to declare both.

In regards to overloading, overloaded functions share a name but they are still different functions. A class must declare as a friend each function in a set of overloaded functions that it wishes to make a friend.

#### 7.2.2.1 Friendship between classes

A class can make another class its friend or specific member functions of that class its friends. This will allow the class to access all the members, including the nonpublic members of the friend class, see example below:

```cpp
class Animal
{
    friend class AnimalMaster;

    public:
    inline Animal(void) = default;

    private:
    int data = 0;
};

class AnimalMaster
{
    public:
    inline AnimalMaster(void) = default;
    void testClass(void) const { Animal testAnimal; testAnimal.data = 1; }

    private:
};
```

It is important to remember that it is a class that controls which classes or functions are its friends, friendship is not transitive, in the example above `Animal` is not a friend of `AnimalMaster`.

#### 7.2.2.2 Friend member functions

It is possible to declare a member function of a class a friend by specifying the class of which that function is a member, it is not advisable to use friend member functions as they require careful structuring of the program to accomodate the interdependencies among the declarations and definitions, in this example:

1. Define the class that declares, but not defines, the friend member function, if necessary, make a forward declaration of the class which will include the friend member function declaration.
2. Define the class that includes the friend member declaration.
3. Define the friend member function.

When reaching point three, the friend member function already has the definition of the class it intends to access and therefore it can be defined. An example is shown below:

```cpp
// Declaration (forward declaration) of Animal so AnimalMaster knows that it is a class.
class Animal;

// Declaration and definition of AnimalMaster class, including the declaration of the friend function member. 
class AnimalMaster
{
    public:
    
    private:
    void damageAnimal(int damage, Animal &elem);
};

// Declaration and definition of Animal with the friend function declaration.
class Animal
{
    friend void damageAnimal(int damage, Animal &elem);

    public:

    private:
    int vitality = 100;
};

// Definition of the friend function member.
void AnimalMaster::damageAnimal(int damage, Animal &elem);
{
    elem.vitality -= damage;
};
```

#### 7.2.2.3 Friend declarations and scope

It is important to remember that a friend declaration affects access but it is not a traditional declaration, a traditional declaration of the friend function must exist even if it is only called from the members of the class that grants the friendship:

```cpp
class example
{
    // Friend declared and defined inside the function body.
    friend void exampleFriendFunction() { }

    // Constructor.
    inline example(void) { exampleFriendFunction(); } // Error, no declaration for exampleFriendFunction.
    
    // Member functions.
    void exampleA(void);
    void exampleB(void);
};

void example::exampleA(void) { return exampleFriendFunction(); } // Error, no declaration for exampleFriendFunction.
void exampleFriendFunction();
void example::exampleB(void) { return exampleFriendFunction(); } // OK, declaration found for exampleFriendFunction.
```

Some compilers automatically declare the friend function, however some do not, so it is important to remember this when using friendship.

## 7.3 Type members

In addition to **data members** and **function members**, a class can also contain its own types by declaring **type members**. The access specifiers are also applicable to **type members**. Unlike other class members, **type members** must appear before they are used, reason why they are usually grouped at the beginning of the class.

There are two possible ways to declare **type members**, with `typedef` or with `using`:

```cpp
class Example
{
    public:
      typedef b = int;
    private:
      using a = string;
};
```

## 7.4 Inlining member functions

As we've seen in a previous section, member functions defined inside a class are automatically and implicitly `inline`, like in the example below:

```cpp
class Example
{
    int a(int b, int c) { return b*c; }
};
```

It is possible to declare a function as `inline` explicitly as part of its declaration inside the class body, it is also possible to specify the function as `inline` in the definition, in fact, it is possible, although not necessary, to specify the function as `inline` in both places, see example below:

```cpp
class Example
{
    // Although implicitly inline, we make it explicit with the inline specifier.
   inline int sum(int b, int c) { return b+c; }
    // Inline function defined ouside of the class.
    inline int multiply(int b, int c);
};

inline int Example::multiply(int b, int c)
{
    return b * c;
}
```

Member functions qualified as `inline` should be defined in the same header file as the corresponding class definition.

## 7.5 Overloading member functions

Member functions may be overloaded in the same way as normal functions, the same function-matching procedure is used to find the best match for member functions and non-member functions, see an example below:

```cpp
class Example
{
    int get();
    int get(int a, int b);  
};
```

## 7.6 Mutable data members

A data member that is never `const` even when a member of a `const` object is called a **mutable data member**, this means that even a member function that takes a `const` pointer to the object on which it is called, this is a `const` member function, may change a mutable data member.

This kind of member is specified with the keyword `mutable` in its declaration inside the class definition as follows:

```cpp
class Example
{
    public:
        void fn() const { this->data = 5 };
    private:
        mutable int data = 0;
};
```

## 7.7 In-class initializers for class type members

It is possible to initialize a class type data member inside a class by providing the necessary information that matches a constructor of that class, just like any other in-class initializer, these must be supplied using the initialization form using `=` or the initialization form using curly braces, `{}`. The example below shows the two forms of initialization:

```cpp
class ExampleOne
{
    ExampleOne() = default;
    ExampleOne(int a, int b);
};

class ExampleTwo
{
    vector<ExampleOne> exampleOneA = {ExampleOne(), ExampleOne(1, 2)};
    vector<ExampleOne> exampleOneB{ExampleOne(), ExampleOne(1, 2)};
};
```

## 7.8 Class types and declarations

Every class defines a unique type, even if their members are exactly the same. This makes it possible to refer to a class type by using its type name or its type name followed by the `class` or `struct` keywords:

```cpp
Animal cat;
class Animal cat;
```

The second method is actually inherited from C and supported in C++.

### 7.8.1 Forward declaration and incomplete types

A declaration of an as of yet undefined name is a **forward declaration**, and it is most used to refer to a declaration of a class that appears prior to the definition of a class. An **incomplete type** is one that is declared but not defined, it is possible to use these kind of types to define references or pointers to incomplete types while it is not possible to use them to define variables or class members.

The following is a **forward declaration** of the **incomplete type** `Animal`

```cpp
class Animal;
```

And these are some of the uses:

```cpp
// Pointer to incomplete type.
Animal *ptrAnimal = &refdAnimal;
// Reference to incomplete type.
Animal &refAnimal = refdAnimal;
// Function that takes an incomplete type parameter.
void parameterAnimal(Animal param);
// Function that returns an incomplete type.
Animal returnAnimal(void);
```

Before creating objects of a class type it must be defined because otherwise the compiler does not know how much storage that object needs, and similarly a class must be defined before accessing an instance from it as the compiler does not know its members.

Data members of a class can be defined of class type only if their class has been defined, however because of the rules described above we can declare, for example, references and pointers like in the example below:

```cpp
class AnimalList 
{
    int vitality;
    AnimalList &refAnimal;
    AnimalList *prevAnimal;
};
```

## 7.9 Class scope

Every class defined its own new scope, outside this scope data members, function members and type members may only be accessed through an instance of the class, a reference, a pointer or using the scope operator depending on the member.

### 7.9.1 Scope and function members defined outside the class

Because a class defines its own scope we must provide the class name as well as the function name when defining a member function outside the definition of the class, like in the example below:

```cpp
class Animal
{
    public:
    typedef int vit_type;

    private:
    vit_type vitality = 0;
    void addVitality(vit_type vitality);
    vit_type getVitality(void);
};

void Animal::addVitality(vit_type vitality)
{
    this->vitality += vitality;
}

Animal::vit_type Animal::getVitality(void)
{
    return this->vitality;
}
```

In the first function defined, the compiler sees the name of the class in before the parameter list so it is not necessary to use it when defining the parameter, unlike the second function where the return type appears before the name of the name is seen and therefore it is necessary to use the scope operator with the return type.

### 7.9.2 Name lookup

As we've seen in previous chapters, **name lookup** is the process of finding which declarations match the use of a name, it consists in the following:

- First, look for a declaration of the name used in the block in which the name is used, only declarations before preceeding the use of the name are considered.
- Second, if no declaration is found, look in the scope or scopes that encloses the block in which the name is used.
- Third, if no declaration is found after the last two steps, then the compiler will raise an error.

For classes there are some details to consider, as we will see in this section.

#### 7.9.2.1 Name lookup for class member declarations

Names used in declarations, including those used for return types and types of the parameter list, must be seen by the compiler before they are used, if a member declaration uses a name that is not yet declared in the class the compiler will look for a declaration in the scope or scopes that enclose the class definition.

An example of this can be found below:

```cpp
typedef int vit_type;

class Animal
{
    public:
    vit_type getVitality() { return vitality; }
    private:
    vit_type vitality;
};
```

In the example, when the compiler sees the `getVitality` declaration it looks for matching names for the return type `vit_type`, first it attempts to find them inside the class and only declarations found before the use of the name is found, it will find none. After this it attempts to find it in its enclosing scope, point at which a declaration is found.

#### 7.9.2.2 Name lookup for type names

Ordinarily, an inner scope can redefine a name already defined in an outer scope, however if a class uses a name that is a type already defined in an outer scope the class should not redefine that name, continuing from previous example:

```cpp
typedef int vit_type;

class Animal
{
    public:
    vit_type getVitality() { return vitality; }
    private:
    typedef int vit_type; // Can't do this...
    vit_type vitality;
};
```

Some compilers will ignore this error, but still it is an error.

This is a reason why is advisable to define type names at the beginning of the class, that way any member that uses the type will be seen after the type name has been defined.

#### 7.9.2.3 Name lookup inside member definitions

A name used in the body of a member function is resolved following the next procedure:

- First, the compiler looks for a declaration inside the member function, only declarations that precede the use of the name are considered.
- Second, if the declaration is not inside the member function, the compiler looks for a declaration inside the class. All the members of the class are considered.
- Third, if the name is not found inside the class or inside the member function, then it looks for a declaration that is in scope before the member function definition.

It is recommended not to hide names that are needed from surrounding scopes in the member functions.

## 7.10 Aggregate classes

An **aggregate class** is a class with just public data members and no in-class initializers or constructors, members of such classes can be initialized by a brace enclosed list of initializers. Basically an aggregate class implies the following:

- All its data members are public.
- It does not define any constructors.
- It has no in-class initializers.
- It has no base classes or `virtual` functions.

An example of a class aggregate:

```cpp
struct Animal
{
    int vitality;
    int strength;
};
```

And the way to initialize this structure is as follows:

```cpp
Animal animal = {10, 20};
```

As with initialization of array elements, the members that are not explicitly initialized are value initialized, as you might have noticed, an aggregate class is similar to a structure in C.

## 7.11 Literal classes

An **aggregate class** whose data members are all of literal type is a **literal class**, and a class that is not an aggregate class that meets this criteria is also a **literal class**:

- The data members are all of literal type.
- The class must have at least one `constexpr` constructor.
- In-class initializers for a member of built-in type must be a constant expression, if the member is a class type then the initializer must use a `constexpr` constructor.
- The class must use the default definition for its destructor.

### 7.11.1 constexpr constructors

Constructors in a literal class can be `constexpr`, and implicitly also `const`, they can be declared as the default constructor and they must initialize every data member in the class with a `constexpr` or a constant expression. Because it is a `constexpr` function that can't return any values, its function body is tipically empty. The following is an example.

```cpp
class Animal
{
    constexpr Animal(int str = 10) : strength(str), vitality(15) {}
    constexpr Animal(int str, int vit) : strength(str), vitality(vit) {}

    private:
    int strength;
    int vitality;
};
```

A `constexpr` constructor is used to generate objects that are `constexpr` and for parameters or return types in `constexpr` functions.

## 7.12 Static class members

A **static class member** is one that is associated with the class, rather that with objects instanced from it. In order to declare one of these members we use the `static` keyword like this:

```cpp
class Animal
{
    public:
    inline Animal(int vit) { this->vitality = getVitality(vir); }

    private:
    double vitality;
    static double vitalityModifier;
    static double getVitality(int vit);
};
```

A static class member exists outside of any object, it is shared among all instances of the class. This means that in our example an instance of `Animal` does not contain the `vitalityModifier` variable or the `getVitality` function.

In the particular case of static function members, they do not have a `this` pointer and as such there is no such thing as static `const` member functions.

Static data members can be used as default arguments for functions, they can have an incomplete type and in particular the same type as the class type if which it is a member.

### 7.12.1 Accessing a class static member

It is possible to access a static member using the scope operator, like in the example below:

```cpp
Animal elem;
Animal &elemRef = elem;
Animal *elemPtr = &elem;

// Accessing using the class type.
Animal::getVitality(5);
// Accessing using an object.
elem.getVitality(5);
// Accessing using a reference.
elemRef.getVitality(10);
// Accessing using a pointer.
elemPtr->getVitality(10);
```

Member functions can use the `static` member directly without the scope operator.

### 7.12.2 Defining static members

Static members can be defined inside or outside the class definition, although when defining it outside the `static` keyword must not be repeated, it only appears in the declaration in the function body.

Static data members are not part of the objects instanced from the class and as such they are not initialized by the class constructors, each static data member must be defined and initialized outside the class body or any other function.

The example below covers both paragraphs above:

```cpp
class Animal
{
    public:
    inline Animal(int vit) { this->vitality = getVitality(vir); }

    private:
    double vitality;
    static double vitalityModifier;
    static double getVitality(int vit);
};

double Animal::vitalityModifier = 0.9;
double Animal::getVitality(int vit)
{
    return vitalityModifer * vit;
}
```

Like global objects, static data members, once defined, exist until the program completes. The definition of static members usually goes inside the file that contains the definitions of the class noninline member functions, to ensure that they are only defined once.

In case the static data member is a `constexpr` of literal type, then it must be initialized inside the class definition with a constant expression, in this case if defined outside it must not include an initialization value as it is already specified in the class body. 

```cpp
// Inside the class body.
static constexpr int minVitality = 0;
// Definition outside the class body without an initializer.
constexpr int Animal::minVitality;
```

Usually this also applies for members that are used in contexts where the compiler can just substitute the member's value and the member is of `const` or `constexpr` type, in other cases there must be a definition outside the class definition for that member. It is advisable to always define it outside the class body.

# Other terms and concepts

**class or struct keyword**: The difference is strictly stylistic, a class can be defined using either keyword, the only difference is that when using `struct` to define a class the members before the first **access specifier** are `public`, while if `class` is used those members are `private`.