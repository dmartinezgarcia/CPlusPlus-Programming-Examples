# 6. Chapter 06 - Functions

In this chapter the definition and declaration of function is described, from arguments passed to functions and values returned by functions to overloading of functions. The chapter finishes by describing pointers to functions.

## 6.1 Function basics

A **function** is a block of code with a name, it usually consists of:

- A **return type**, part of the function declaration that specifies the type of the value that the function returns.
- A **name**, associated to the function.
- A list of zero or more **parameters**, separated by commas and enclosed in parentheses.
- A **function body**, which is a statement block with the actions that will be executed when the function is called.

Below find an example of a function with two parameters:

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

### 6.1.1 Calling a function

A function is called using the **call operator**, defined by a pair of parentheses. The call operator takes an expression which evaluates to a function or points to a function, inside the parentheses is a comma-separated list of arguments to initialize the parameters or no list at all if the function doesn't expect any parameters. The type returned by the call operator is the type of the function it's calling.

Below an example of a call operator is shown:

```cpp
int result = sum(10, 20);
```

When a function is called control is transferred from the *calling* function to the *called* function and the initialization of the *parameters* from the *arguments* also occurs at this stage.

Initialization of the parameters from the arguments happens implicitly, this is the same as if a variable was created with the name of the parameter and the value of the argument.

The execution of the function *called* ends when a `return` statement is encountered, which returns a value (if any is expected) and also transfer control out of the *called* function back to the *calling* function. 

At this point, the value returned by the *calling* function is yielded as the result of the call operator, and finally execution continues in the next statements.

### 6.1.2 Parameters and arguments

As seen in previous sections, **arguments** are no more than initializers for the a function **parameters**, the first argument in the list initializes the first parameter and so on, the order in which the parameters are initialized is not guaranteed however.

The type of each argument must match the type or be able to be converted to the type of the parameter it initializes and exactly the same number of arguments as the function has parameters has to be passed, this means implicitly that all parameters are always initialized.

### 6.1.3 Parameter list

A function's parameter can never be omitted, typically a function with no parameters is given an empty parameter list, either by using the `void` keyword or by using nothing at all:

```cpp
int sum(void);
int sum();
```

A parameter list with one or more parameters has to be specified with a type followed by a different name for each parameter, like in the example below:

```cpp
int sum(int a, int b); // OK.
int sum(int a, b); // ERROR: b doesn't have any type defined.
```

Because parameters are initialized in a similar way to a variable initialized in the outermost scope of the function, a variable defined in this way and a parameter can't share the same name.

Parameter names are optional, however is rare to find unnamed parameters in the function definition as if a parameter is unnamed it can't be used in the function.

### 6.1.4 Return type

The return can be of type `void` which means that the function doesn't return a value or it can be any other type except for an array type or a function type.

### 6.1.5 Function declaration (function prototype)

The name of a function has to be declared before it can be used, in a similar fashion to variables, we do this by writing the **function declaration** or **function prototype**.

A **function declaration** is just like the function definition with the function body replaced by a null statement (`;`), and because of this parameter names are no needed, although it's recommended for readability to include them.

An example of a function declaration can be found below:

```cpp
int sum(int, int);
```

Notice that it's just three elements the information that needs to be provided to define a function, and that is the **return type**, the **function name** and the **parameter type**.

With few exceptions, usually a function can be declared and not defined as long as it is not used, also, a function can be defined once but it can be declared multiple times.

Function declarations should go into header files, and the file that contains the definition of the function should include the header file with the declaration, this way the compiler will verify consistency.

## 6.2 Local variables

The body of a function is nothing more than a statement block, which creates a new scope in which variables can be created, in the case of a function, these variables are known as **local variables**, as they are local to the function and hide other variables of the same name in the outer scope.

### 6.2.1 Lifetime and scope of local variables

The lifetime of a **local variable** depends on how it is defined, in this regard it's important to differentiate between **scope** and **lifetimes**:

- The **scope** is the part of the program in which the object is visible.
- The **lifetime** is the part of the program in which that variable exists.

### 6.2.2 Automatic objects

These objects only exist while a block is executing and destroyed after execution exits that block, leaving the values of these objects undefined afterwards.

An example of automatic objects are the function parameters, defined in the scope of the function body and with a lifetime limited to the function body.

### 6.2.3 Local `static` objects

A local variable defined as `static` is one whose lifetime continues across calls to the function. The variable is initialized before the first execution and destroyed when the program ends.

An example of a local static variable could be the following:

```cpp
int sum(int a, int b)
{
    static int a = 0;
    
    std::cout << "Static variable value: " << a << std::endl;
    a++;
}
```

## 6.3 Argument Passing

The type of a parameter determines the interaction between the parameter and its argument, in this section we will see the two different types of argument passing: **argument passing by value** or **argument passing by reference**.

### 6.3.1 Passing arguments by value

When the **parameter and argument are independent objects** we say that we are passing arguments by value, being the parameter a copy of the argument. Nothing the function does to the parameter can affect the argument, the following is an example of a function called with argument passing by value:

```cpp
int sum(int a, int b);

int main()
{
    int a = 5, b = 10;  

    sum(a, b);
}
```

It's possible pass the copy of a pointer by value to modify the object it points to, as the parameter and argument are still independent copies of the same object but the object they point to is the same. In fact, this is the way of passing a "value by reference" in C.

### 6.3.2 Passing arguments by reference

When the **parameter is a reference** se say that we pass arguments by reference, in this case the parameter is just an alias for the corresponding argument.

```cpp
void sum(int a, int b, int &res)
{
    res = a + b;
}
```

This way of argument passing is often used to modify the values of the arguments passed and in other cases it is used because passing by value a large container is inefficient and some objects can't be copied, so a reference must be provided instead, in the latter case the reference should be a reference to a `const` object as we don't intend to modify it.

```cpp
// In this case copying the string is inefficient specially if it is very large... so we provide a reference instead.
bool is_equal(const string &s1, const string &s2)
{
    return (s1 == s2);
}
```

Passing arguments by reference is often used to give the possibility to a function to return multiple results as by default they can only return one result, we have seen this in the first example in this section.

### 6.3.3 Constant parameters and arguments

#### 6.3.3.1 Top-level const type qualifiers

As a reminder, top-level type qualifier is the one that applies to the object itself, for parameters it works in a similar way to how it works for other type of variables.

Top-level `const` type qualifiers on parameters are ignored, just like in any other initialization, it's possible to pass either a `const` or a non-`const` argument to a parameter with a top-level `const`:

```cpp
int sum(const int a, const int b);

int main(void)
{
    const int a = 0;
    int b = 0;

    sum(a, b);
}
```

As expected, it's not possible to modify a parameter with a top-level `const` qualifier.

#### 6.3.3.2 Low level const type qualifiers

Exactly the same initialization rules apply to parameter passing as for variables, find below some examples:

```cpp
void initializePtr(int *p);
void initializeRef(int &p);

int a = 0;
const int b = 0;

initializePtr(&a); // OK.
initializePtr(&b); // ERROR: Can't pass a pointer to const int to a parameter that is a plain pointer to int.

initializeRef(a); // OK.
initializeRef(b); // ERROR: Can't pass a reference to const int when a reference to plain int is expected.
initializeRef(42); // ERROR: Can't pass an int literal when a reference to plain int is expected.
```

Notice that is not possible to pass a reference to `const` or literal when a plain reference is expected nor a pointer to `const` can be passed when a plain pointer is expected... it's a common mistake that should be avoided.

### 6.3.4 Array parameters

When passing arrays to a function we have to take two things into consideration:

- Arrays can't be copied, so it's not possible to pass an array by value.
- Arrays are passed as a pointer to the first element, this means that the function is not aware just by this argument of the size of the array.

The following three function declarations are actually the same:

```cpp
void example(int *a);
void example(int a[]);
void example(int a[10]); // The size of the array is irrelevant for the function as a pointer to the first element is passed.
```

The second consideration creates an issue, the functions needs additional information to determine the length of the array, there are three common techniques to do this:

- **Using a marker to signal where the array ends**, an example of this is a C-style character string that uses the `/0` character to signal the end of the string.

```cpp
void find_char(const char *str)
{
    // Do until end of the string.
    while (*str != `/0`)
        ...
}
```

- **Providing an additional pointer to position in memory where the array ends**, which is something similar to what the standard library does, the array gives us the starting position in memory and the additional pointer tells us where the array ends, something that can be done with the `begin` and `end` functions.

```cpp
void find_char(const char *str_s, const char *str_e)
{
    // Do until end of the string.
    while (str_s != str_e)
        ...
}
```

- **Providing an additional parameter that explicitly tells the size of the array**, which is an older way of doing it usually found in old C++ programs and C programs.

```cpp
void find_char(const char *str, size_t size)
{
    int index = 0;
    // Do until we have parsed every character.
    while (index < size)
        ...
}
```

Same as in previous sections, if the function won't modify the array elements it should use a low-level `const` type qualifier.

#### 6.3.4.1 References to arrays

It's possible to pass a reference to an array and in this case the dimension specified will be taken into account by the function, in the sense that if an array of a different dimension is provided it won't work, see an example below:

```cpp
void sum(int (&arr)[2]);

int i = 0;
int j[2] = {1, 2};
int k[5] = {1, 2, 3, 4, 5};

sum(&i); // ERROR: The argument is not an array of two ints.
sum(j); // OK: Argument is an array of two ints.
sum(k); // ERROR: Argument is an array of five ints.
```

Notice that the parentheses in the function declaration are necessary, without them we would be defining an array of length two of references to `int`.

#### 6.3.4.2 Arrays of arrays

Commonly known as multidimensional arrays, when passing an array of arrays to a function a pointer to its first element is passed, it can be passed using pointer syntax or array syntax:

- As a **pointer to array**, the first dimension is ignored so it must be specified with another parameter but the second, third and so on are part of the element type the pointer points to and must be specified as part of the element.

```cpp
void sum(int (*matrix)[10][20], int xSize);
```

Notice the parentheses, they are necessary as otherwise it would be a pointer

- Using **array syntax**, being the same as above.

```cpp
void sum(int matrix[][20], int xSize);
```

### 6.3.5 Variadic functions

A **variadic functions** is one that takes a variable number of arguments, there are three ways to do this:

- If the arguments have all the same type, a library type called `initializer_list` can be passed.
- If the argument types vary, a **variadic template** can be used to create a special kind of function.
- If the argument types vary, ellipsis can be used, however this is an old method of doing variadic functions and should only be used for compatibility with C programs.

#### 6.3.5.1 Initializer list parameter

Useful when a function that takes a variable number of arguments of the same type is required. Using a parameter of this type doesn't limit the number of parameters the function can use.

The `initializer_list` type is a template library type that represents an array of values of the same type. It's defined in the `initializer_list` header and the operations it includes are the following:

|Operation|Description|
|:-----:|:------|
|`initializer_list<T> list`|Initializer list `list` default initialization (empty).|
|`initializer_list<T> list{a, b, c...}`|Initializer list `list` initialized with the a `const` copy of the objects `a`, `b` and `c`.|
|`list(list2)`|Copying an `initializer_list`, elements are shared between `list` and `list2`, they are not copied.
|`list = list2`|Assigning an `initializer_list`, elements are shared between `list` and `list2`, they are not copied.
|`list.size()`|Number  of elements in the `list`.|
|`list.begin()`|Return a pointer to the first element in `list`.|
|`list.end()`|Return a pointer to position in memory one past the last element of `list`.|

The elements in an initializer list are always `const` values, there is no way to change the value of an element.

#### 6.3.5.2 Ellipis parameters

An ellipsis parameter exists in C++ for compatibility with a library in C called *varargs*, and generally it shouldn't be used for any other reason than for compatibility with C as most class types are not copied properly when passed to an ellipsis parameter.

This type of parameter may only appear as the last element in a parameter list and no type checking is done to the arguments passed:

```cpp
void foo(int a, ...);
```

This won't be covered in detail as this is something C specific, for more details, check your compiler documentation.

## 6.4 Return types and `return` statement

In this section we will define the `return` statement and also the return types.

### 6.4.1 Return statement

The `return` statement terminates the function that is executing and makes the flow of execution go back to the point where it was called. Depending on whether there the function returns a value or not there are two types of `return` statements.

### 6.4.2 Functions with no return value

A function that doesn't return a value has its return type specified to `void`, these are not required to contain a `return`, an implicit `return` takes place before the function ends.

```cpp
return;
```

In this case, the `return` statement is usually used as a way to end the function at an intermediate point, analogous to a `break` statement in a loop, although this is not good practice.

```cpp
void sum(int a, int b, int &c)
{
    if ((a < 0) || (b < 0))
    {
        return;
    }
    else
    {
        c = a + b;
    }
}
```

Although it's hard to find written anywhere, it's possible for a `return` statement of this kind to actually return a value, however that value can only be the value returned by a function whose return type `void`.

### 6.4.3 Functions with a return value

A function that returns a value has its return type specified to other than `void`. The `return` statement in this function must return a value whose type is the same as the return type specified in the function declaration or one that can be implicitly converted.

```cpp
return value;
```

Sometimes a function of this kind might not return a value under a certain scenario, like in the example below:

```cpp
int match(const int &a)
{
    if (a == 0)
    {
        return 1;
    }
    else if (a == 2)
    {
        return 2;
    }
    // ERROR: No return statement, behaviour undefined...
}
```

The compiler might detect such scenarios or it might not, it must be avoided however as what happens in these scenarios case is undefined.

#### 6.4.3.1 How return values are returned

The value returned initializes a temporary at the call site, which stores the result of the function call. This temporary can be assigned or used to initialized other variables or objects, in this regard, it behaves like a variable or parameter initialization or assignment.

It's important to remember to use references to avoid inefficiencies when returning large objects, for an explanation see example below:

```cpp
// The following function copies the string to the destination.
const string stringOp(const string &s1, const string &s2)
{
    return s1;
}
// The following function doesn't copy the string because it returns a reference.
const string& stringOp(const string &s1, const string &s2)
{
    return s1;
}
```

#### 6.4.3.2 rvalue or lvalue return type

Calls to functions that return references are *lvalues*, and other types are *rvalues*, as such, returned values can be used in the same manner, for example:

```cpp
char& set_val(string &str, size_t index)
{
    return str[index];
}

int main()
{
    string stringExample = "Hello";

    // We are changing the first character of the string, as we are returninga reference to that object.
    set_val(stringExample, 0) = 'R';

    return 0;
}
```

#### 6.4.3.3 Local object as return value

Simply put, never return a reference or pointer to a local object in the function, as when the function completes execution the local objects are freed, meaning that a reference or pointer to the local object would no longer be valid, see example below:

```cpp
string& get_val(int i)
{
    string s = "Hi";
    
    if (i == 0)
    {
        return s; // ERROR: Returns a reference to a local object.
    }
    else
    {
        return "Hello!!"; // ERROR: Returns a reference to a local object.
    }
}
```

This considerations do not apply if the object is `static`.

#### 6.4.3.4 Returning classes

The call operator, `()`, used to execute a function, is left associative and has the same precedence as the operators used to access a member of a class, either by deferencing the pointer that points to the class, using `->`, or by using directly the class object, using `.`. This leads to an interesting scenario:

```cpp
const string& retString(const string &s1, const string &s2);

auto string_len = retString(s1, s2).size();
```

As we can see in the example, if the function executed by the call operator returns a class type, we can access its members from the temporary created during the return procedure.

#### 6.4.3.5 List initializing the return value

It's possible to return a braced list of values, which initializes the temporary that represents the returned value by the function, if the list is empty then this temporary is value initialized, see example below:

```cpp
vector<string> doSomething(int i)
{
    if (i == 0)
    {
        return {};  // Returns an empty list.
    }
    else if (i == 1)
    {
        return {"Hi ", "Jack."}; // Returns a list with two elements.
    }
}
```

Something to note is that if the return type is a built-in type, then the braced list may only contain one element at most, and an element that doesn't require a narrowing conversion. If the function returns a class type, then it's the class itself that defines how initializers are used.

#### 6.4.3.6 Returning from main

The only function that can avoid returning a value even if its return type is specified to other than `void` is the `main` function, as the compiler implicitly introduces a `return 0;` statement before the function ends, signalling success, any other non-zero value is machine dependent. In this regard, the `cstdlib` library defines two preprocessor variables that can be used to indicate success or failure, like in the example below:

```cpp
#include <cstdlib>

int main()
{
    if (some_failure)
    {
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}
```


#### 6.4.3.7 Recursion

We say that a function is **recursive** when it calls itself, either indirectly or directly. Such functions must avoid what is called as a **recursion loop**, which is a recursive function that makes all paths recursive, thus making it recurse forever until the stack is exhausted. See below for an example of a recursive function:

```cpp
int factorial(int val)
{
    if (val > 1)
    {
        return factorial (val - 1) * val; // This path is recursive.
    }
    else
    {
        return 1; // This path is not recursive, so the function will eventually end.
    }
}
```

The only function that can't be recursive is main.

#### 6.4.3.8 Returning pointer or references to arrays

Remember that it's not possible to copy an array, so a pointer or reference has to be returned instead. The syntax for this can be quite intimidating, in this section we shall define four ways of doing this.

The first way is the most straightforward one and consists in **defining a type alias for the return type**, see example below:

```cpp
typedef int arrTenInts[10]; // This would be the same as: using arrTenInts = int[10];
arrTenInts retArray(void); // This function will return a pointer to an array of ten ints.
```

The second way consists in **declaring the function as is**, with no type alias for the return type, in this regard the following syntax must be used:

> *type* (**function_name*(*parameter_list*))[*dimension*]

Following the example above, we would define the same function as:

```cpp
int (*retArray(void))[10];
```

Which is overcomplicated, reason why this way of defining the function should be avoided.

The third way consists in using a **trailing return type**, which is basically specifying the return type after the parameter list. This can be used for any function but is mostly useful for returning pointers or references to arrays.

A **trailing return type** follows the parameters list and is preceded by an arrow, the return type is specified as `auto`, see example below for more details:

```cpp
auto retArray(void) -> int(*)[10];
```

This makes it clear which return type the function returns.

The fourth way is more limited than the others in the way that we need to know the possible arrays that are returned by the function, and it consists in using a `decltype` to declare the return type, following from the examples above:

```cpp
decltype(int a[10])* retArray(void); // Returns a pointer to an array of ten ints.
```

## 6.5 Overloaded functions

We say that functions are **overloaded** when they have the same name and appear in the same scope but they expect different parameter lists. When executed, the compiler will deduce which function to the programmer intends to execute from the arguments passed, for example:

```cpp
int sum(int a, int b);
int sum(int a, int b, int c);
int sum(int a, int b, int c, int d);
```

All these functions will perform a similar functionality but they expect different arguments. Function overloading eliminates the need for the programmer to think about new names for functions that perform the same functionality but for different parameter lists.

It's important to note that the `main` function can't be overloaded.

### 6.5.1 Defining overloading functions

Overloaded functions **must differ in the number or the type(s) of their parameters**, if the parameter lists match and the return types differ, then the declarations after the first one are an error, see below for examples:

```cpp
int sum(int a, int b);
int sum(int a, int b, int c); // Overloaded function, parameter list is different.
int sum(float a, float b); // Overloaded function, parameter list is different.

float sum(float a, float b); // ERROR: Return types differ, but there is already a declaration with the same name and same parameter list.
```

Parameter lists that don't look the same might be identical, changing the parameter names in two functions with the same name and same parameter list is one of these cases, another scenario is using type aliases intending to change the parameter types, both declaration will be the same because in the end is the same type in both parameter lists, see below for examples:

```cpp
typedef int intAlias;
int sum(int a, int b);

int sum(int aa, int b); // ERROR: Same parameter list, same types, names don't matter.
int sum(intAlias a, intAlias b); // ERROR: Same parameter types but with an alias, in the end is an int.
```

When a parameter has a top-level `const` is indistinguishable from another without it, this means that in this scenario two declarations are the same:

```cpp
int sum(const int a, const int b);
int sum(int a, int b); // The same as above.
```

However when using pointers or references pointing to `const` or not `const` objects, this is low-level `const`, each declaration refers to a different version of the function:

```cpp
// Each of these functions is a different version of the function.

int sum(const int a, const int b); // Pass by value.
int sum(const int &a, const int &b); // Reference to const int, different declaration.
int sum(int &a, int &b); // Plain reference to int, different declaration.
```

In these cases the constness of argument is used to distinguish which function to call, there is no conversion from pointer or reference to `const` so when passing a reference or pointer to `const` argument the compiler will know which function to call. On the other hand, when passing a plain pointer or reference the compiler can use either the function expecting plain references or pointers or the one that expects pointers or references to `const`, as there is a conversion from plain reference or pointers to references or pointers to `const`, however the compiler will prefer the one that expects plain references or pointers in this scenario.

In regards to scope, there are no special rules for overloading, if a name is declared in the inner scope, that name hides declarations of the same name in the outer scope, as usual. See example below:

```cpp
void example_a(void);

void example_b(void)
{
    // This is bad practice...
    void example_a(int);
    
    example_a();
}
```

In the example above the compiler would raise an error because the declaration of `example_a` inside the body of `example_b` expects an `int`, `example_a` is not an overloaded function of the one in the outer scope, but an independent declaration that hides that one. All of this is because the compiler first attempts to find an name for the function being called and then it does the type checking.

### 6.5.2 Using const_cast in overloaded functions

The `const_cast` is mostly useful with overloaded functions, for example given the function below:

```cpp
const string& chooseString(int i, const string &a, const string &b)
{
    if (i == 0)
    {
        return a;
    }
    else
    {
        return b;
    }
}
```

If we called this function with plain `string` objects, we would get a reference to constant `string` in return which might not be what we were expecting, we could create another function like this, that takes as arguments plain references to `string`, does the same functionality and returns a plain reference to `string`, all by using `const_cast`:

```cpp
string& chooseString(int i, string &a, string &b)
{
    auto &retVal = chooseString(i, const_cast<const string&>(a), const_cast<const string&>(b)
    return const_cast<string&>(retVal);
}
```

### 6.5.3 Overload resolution

Once a set of overloaded functions have been defined the compiler knows which one to call by comparing the arguments in the call against the parameter that each overloaded function expects, this is part of a process that is commonly known as **function matching** or **overload resolution**, which consists in associating a function call to a specific function from a set of overloaded functions.

For any given call to an overloaded function, there are three possible outcomes:

- The compiler determines the best match for the arguments provided and generates code to execute that function.
- If no match was found at all because the arguments in the call don't match any of the expected parameter lists, then the compiler raises an error saying that there is no match for the call.
- If there is more that one function that matches and it's not clear for the compiler which one is the best match, then it will raise an error saying that it is an ambiguous call.

## 6.6 Default arguments in functions

A **default argument** is one that can be specified to be used when an argument is omitted in a call to the function, these are specified as a initializer value for a parameter in a parameter list, default parameters can be defined for one or more parameters, however if a parameter has a default argument all parameters that follow must also have a default argument:

```cpp
int fn(int a, int b = 4, int c = 5, int d = 6);
```

In order to call a function with **default arguments**, we omit those arguments in the function call, like in the example below:

```cpp
fn(5); // b takes default argument 4, c takes default argument 5, d takes default argument 6.
fn(5, 1); // c takes default argument 5, d takes default argument 6.
fn(5, 1, 1); // d takes default argument 6.
fn(5, 1, 1, 1); // No default arguments used.
```

Since **default arguments** apply for the right most parameter in the call, in order to, for example, override the default argument of `d` parameter it's also needed to override `c` and `b` parameters.  Part of the work designing a function with default arguments is ordering the parameters so the ones that are more likely to use a default argument appear last.

A **default argument** can be any expression that has a type that is convertible to the type of the parameter, except local variables, names used as default arguments are resolved in the scope of the function declaration and evaluated at the time of the call. For example:

```cpp
int a_def = 0;
int b_def = 1;

int example();
int fn(int a = a_def, int b = b_def, int c = example(), int d = 1);
```

## 6.7 Using `inline` in function declarations

On most machines, a function call involves saving the registers before the call and restoring them after the return, arguments may be copied and the program flow jumps to a new location. When using the `inline` keyword in a function declaration usually means that the function will be expanded "in line" at each call, for example:

```cpp
inline sum(int a, int b)
{
    return a + b;
}

c = sum(5, 4); // Would be replaced by the compiler to c = 5 + 4, removing some rum-time overhead.
```

The `inline` keyword is mostly meant to optimized small, recurrent functions that are called frequently, for complex functions the `inline` keyword will be ignored by the compiler, after all this keyword is just a request to the compiler and it's up to it to ignore it or not.

Because the compiler needs the definition rather than the declaration to expand the code, functions that use the `inline` keyword are usually defined in header files, as they can be defined multiple times with the same and exact definition.

## 6.8 Using `constexpr` in function declarations

A function that uses the `constexpr` keyword is one that can be used as a constant expression, it is defined in the same way as any other function but it must meet the following criteria:

- The `return` type and the type of each parameter must be a literal type.
- The function body must contain one `return` statement.

Functions that use this keyword also use implicitly the keyword `inline` in order to be able to expand immediately. as the compiler verifies that the function returns a constant expression and in that case expands the function to the resulting value, for example:

```cpp
constexpr int result() { return 10; };
constexpr int var = result();
```

The body of this kind of function can have statements that do not imply actions at run time, such as type aliases or null statements.

A `constexpr` function doesn't have to return a value that is constant, in this case when used in a context where a constant expression is detected the compiler will raise an error.

Because the compiler needs the definition rather than the declaration to expand the code, functions that use the `constexpr` keyword are usually defined in header files, as they can be defined multiple times with the same and exact definition.

## 6.9 Aids for debugging

The idea in this section is to have code that executes only while the program is being developed, when the application is complete and ready to ship, this code won't be executed, for this, we can use two preprocessor facilities:

- The **assert** preprocessor macro defined in the `cassert` header, takes a single expression that it uses as a condition, if it evaluates to false then a message is printed and program is terminated, if the expression is true then the assert does nothing.

```cpp
assert(5 > 4); // Will do nothing.
assert(4 > 5); // Will print a message and terminate the program.
```

- The **NDEBUG** preprocessor macro, this macro enables debugging when not defined, including the `assert` macro, and disables it when defined. This macro allows us to define our own conditional debugging code, for example:

```cpp
#ifndef NDEBUG
// Debugging code goes here.
#endif
```
There are also other useful macros such as:

- **__FUNC__**: String literal containing the name of the function.
- **__FILE__**: String literal containing the name of the file.
- **__LINE__**: Integer literal containing the current line number.
- **__TIME__**: String literal containing the time the file was compiled.
- **__DATE__**: String literal containing the date the file was compiled.

We can use these constants like this:

```cpp
int sum(int a, int b)
{
    ...
    cerr << "Function name: " << __FUNC__ << endl;
    ...
}
```

## 6.10 Function Matching

The **function matching** procedure is one where the compiler determines which overloaded function of a set of functions matches a given function call. We will explain this process with an example, given the following function declarations:

```cpp
// Function declarations.
void fn();
void fn(int);
void fn(int, int);
void fn(double, double = 3.14);
```

The **first step** in function matching finds the set of overloaded functions for the call, known as **candidate functions**, these are functions with the same name as the function being called and whose declaration is visible at the point of the call.

The **second step** selects functions from the set of candidate functions that can be called with the arguments given in the function call, these are the **viable functions**. To be viable a function must have the same number of parameters as arguments in the call and the type of each argument must match or be convertible to the type of the corresponding parameter.

The **third step** determines which viable function is the best match for the call, the closer the types of the argument and parameter are to each other the better the match, and an exact match is better than a match that requires a conversion. There can only be one function suitable for best match, and this one must fullfill the following criteria:

- The match for each argument is no worse than the match required by any other viable function.
- There is at least one argument for which the match is better than the match provided by any other viable function.

If there is not one single function that is preferable after following all these steps, then the call results in an ambiguous call error from the compiler.

For the following function call:

```cpp
fn(2.1);
```

The compiler would determine that the best match is `void fn(double, double = 3.14)`, because the argument is a double literal which matches the expected parameter type of this function, all the other functions differ in function type or in number of parameters and therefore they are less preferable.

For the following function call:

```cpp
fn(2.1, 1);
```

There is no preferable function between `void fn(double, double 3.14)` and `void fn(int, int)`, as both of them require a conversion for in one of the arguments provided in the function call, this call would result in a compiler error. An explicit cast is not recommended as this would imply that the parameter sets are designed poorly.

### 6.10.11 Argument type conversions

In order to determine the best match, conversions are ranked as follows:

1. An **exact match**, following this criteria:
1.1. Argument and parameter type are the same.
1.2. Argument is converted from an array or function type to a pointer to array or pointer to function.
1.3 A top-level `const` is added or discarded from the argument.
2. Match through a **`const` conversion**.

When calling an overloaded function with a reference or pointer parameter that refers or points to `const`, the compiler uses the existence or not of a `const` type qualifier in the argument to determine which function to call, let the following code serve as an example:

```cpp
void fn(const int &);
void fn(int &);

const int a;
int b;

// Calls the const version, as it is the only viable function.
fn(a);
// Calls the non-const version, both are viable functions but the non-const doesn't require a conversion so it's a best match.
fn(b);
```

3. Match through a **promotion**.

Even though smaller integral types might appear to be a closer match to, for example, `short` type, they are promoted to `int`, which means that calling the `short` version of the function would require a conversion, which has less rank, see below for an example:

```cpp
int fn(short a);
int fn(int a);

fn('c'); // Will call the int version because it's promoted to int.
```

4. Match through an **arithmetic conversion** or **pointer conversion**.

All arithmetic conversions are equivalent to each other and have the same rank, as an example consider the following:

```cpp
void fn(long a);
void fn(float a);
fn(3.14);
```

This would result in an ambiguous call, as the literal `3.14` is a double that can be promoted to `long` or to `float`.

5. Match through a **class-type conversion**.

## 6.11 Pointers to functions

A **pointer to function** is one that points to a function instead of an object, like any other pointer it has to point to a particular type.

The type of a pointer to function is determined by the return type and the type of the parameters of the function it points to, the following is an example of a function declaration:

```cpp
bool (*fn)(bool &ref);
```

The type of the pointer is the following: `bool (bool &)`. Notice that in the declaration the parentheses around `*fn` are necessary, as otherwise we would be declaring a function that returns a pointer to `bool`.

When using the name of a function it is automatically converted to a pointer, this means that we can assign a value to a pointer to function without the address-of operator and also call the function without need of dereferencing the pointer. Like many other pointers, the value of a pointer to function could be `nullptr`, which would indicate that the pointer doesn't point to any function, examples of all of ths below.

```cp
bool fnExample(bool &boolExample)
{
    if (boolExample == true)
    {
        boolExample = false;
    }
    else
    {
        boolExample = true;
    }
}

int main()
{
    using fnPointer = bool (*)(bool &);
    fnPointer f = nullptr;
    bool value = false;

    f = fnExample;          // OK.
    f = &fnExample;         // OK, and same as above.
    
    f(value);               // Function call using the pointer.
}
```

There is no conversion possible between a pointer to function of one type to another, return type and parameter types must match exactly when assigning a value to a pointer to function. In regards to overloaded functions, the pointer to function declaration must make clear for the compiler the expected types:

```cpp
void sum(int a, int b);
void sum(int *a, int *b);

void (*fn0)(int, int) = sum;    // Will take the first version of sum.
void (*fn1)(int*, int*) = sum;  // Will take the second version of sum.
void (*fn2)(int&, int*) = sum;  // ERROR: Parameter type doesn't match.
```

It's possible to have pointer to functions as parameters, in fact, when using a function type as a parameter it's treated as a pointer, in a similar fashion to arrays.

```cpp
// Both these declarations are equal.
void example(bool pf(int));
void example(bool (*pf)(int));
```

As we mentioned earlier, when a function name is used it is automatically converted to a pointer, this means that an argument of this type can be passed without need of the address-of operator.

It's recommended to use type alias along with `decltype` to simplify declarations that use function pointers, like in the examples below:

```cpp
bool fnExample();

// Equal function types.
typedef bool Func();
typedef decltype(fnExample) Func2;

// Pointer to function of the same type.
typedef bool (*fn)();
typedef decltype(fnExample) *fn;
```

It's important to note that `decltype` returns the function type without any conversion to pointer, which means that if we want the pointer we have to explicitely declare it, like in the example above.

It's also possible to have functions return pointer to functions, but in this case the return type is not automatically converted to a pointer type, it must be specified explicitly as it is not converted automatically to pointer.

```cpp
using F = int(int*);        // Function type.
using PF = int(*)(int*);    // Pointer to function.

F f1(); // ERROR: F1 returns a function type.
F *f1(); // OK: F1 returns a pointer to function, declared explicitly.
PF f1(); // OK: F1 returns a pointer to function.
int (*f1(int))(int*); // OK: Declared directly, without aliases.
auto f1(int) -> int (*)(int*); // OK: Declared used trailing return type.
```

# Other terms and concepts

**Handling command-line options**: It's possible to pass arguments to a program from the command line by defining the `main` function as follows:

```cpp
int main(int argc, char *argv[]);
int main(int argc, char **argv);
```

The first parameter being the number of command-line arguments passed to the function, included the name, and the second parameter is the actual arguments passed as an array of C-style strings, the first one being the actual name of the program.

**When not to overload functions**: Only functions that do similar things should be overloaded, sometimes names contain inherent information to what the function does that should not be deleted.