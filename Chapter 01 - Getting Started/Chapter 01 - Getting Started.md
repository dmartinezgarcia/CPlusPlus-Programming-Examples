# 1. Chapter 01 - Getting Started

This chapter introduces some of the basis concepts of C++, including types, variables, expressions, statements and functions. After finishing this chapter, the reader should be able to write, compile and execute simple programs.

The features introduced in this chapter will be explained in more detail in later chapters.

## 1.1 Programs in C++

### 1.1.1 The main function

One of the functions in a C++ program must be called `main`, this is the function the operation system uses to execute a C++ program. A simple `main` function could be as follows:

```cpp
int main (void) {
	return 0;
}
```

A function definition has the following elements:

1. A return type, in our example: `int`.
2. A function name, in our example: `main`.
3. A parameter list, in our example: `void`, which means that the function accepts no parameters.
4. The function body, which contains a block of statements within curly braces `{}`, in our example: `return 0`.

On most systems, the value returned from `main` shows if the program executed succesfully or not. Usually, a return value of zero means that the program executed without errors and a nonzero value indicates the kind of error that occurred.

### 1.1.2 Compiling the program

Once written, the program needs to be compiled. Most compilers can be used with a command-line interface, but many Computer-based compilers run from an IDE (Integrated Development Environment) which takes care of everything and also lets the user configure the compiler from a user-friendly interface.

## 1.2 Input and Output

### 1.2.1 Streams

C++ includes an standard library that provides Input and Output (IO), in particular, the `iostream` library is commonly used in this regard. TO understand better the input and output capabilities of the library, the term **stream** should be defined: a stream is a sequence of characters read from or written to an IO device

This library defines a type called `istream` to represent an input stream, the term stream applied to an input suggests that the characters are sequentially consumed over time. It also defines a type called `ostream` to represent an output stream, in this regard, the term stream means that the characters are generated sequentially over time.

### 1.2.2 Objects

The library defines four IO objects:

1. `cin`: `istream`, used to handle input and is also referred to as the standard input.
2. `cout`: `ostream`, used to handle output and is also referred to as the standard output.
3. `cerr`: `ostream`, used to handle warning and error messages and is also referred as the standard error.
4. `clog`: `ostream`, used to handle general information about the execution of the program.

Usually, when we read from `cin` we read from the window in which the program is executing, and when we write to `cout`, `cerr` or `clog` we write to the same window.

### 1.2.3 Writing to a stream

The **output operator** (`<<` operator) can be used to print a message on an output stream. The output operator takes two operands, the left-hand operand must be an `ostream` object, and the right-hand operand is the value to print. The result of the output operator is the left-hand operand, the `ostream` object. This allows to concatenate output operators like this:

```cpp
std::cout << "Message 1" << "Message 2" << std::endl;
```

Which would be equivalent to:

```cpp
std::cout << "Message 1";
std::cout << "Message 2";
std::cout << std::endl;
```

The statemnent `std::endl` is an special value called **manipulator**. Writing this manipulator in an output stream ends the current line and flushes out the contents in the buffer of the `ostream`.

### 1.2.4 Reading from a stream

Analogously to the output operator, the **input operator** (`>>`) is used to read the data from a given input stream and store it in a given object. It takes an stream as its left-hand operand and an object as its right-hand operand and returns the left-hand operand as its result. This allows to concatenate many input operators, for example:

```cpp
int v1, v2;
std::cin >> v1 >> v2;
```
Is equal to:

```cpp
int v1, v2;
std::cin >> v1;
std::cin >> v2;
```

# Other Concepts and Notes

**Standard library and namespaces**: The prefix `std::` in `std::cout` refers to the name `cout` inside the `std` namespace, which is the namespace of the standard library. The scope operator `::` used in this statements means that we wish to refer to the name `cout` in the namespace `std`. Namespaces prevent confusion between the names we define and the names inside a library. 

**Including libraries**: The `include` directive is used to include headers, every program that uses a library must include its header. In general the `include` directive is writting at the beginning of the source file. For example, if we wish to include the `iostream` library:

```cpp
#include <iostream>
```

Where `iostream` is the header of the `iostream` library.

**Source files**: Files that contain programs are usually called source files. On most systems, the name of a source file ends with a suffix. Different compilers might use different naming conventions, but the most common suffixes are the following: .cc, .cxx, .cpp, .cp and .c.

**Type**: A type defines the contents of a data element and the operations that are allowed on that data. The data programs manipulate is stored in variables and every variable has a type. When the type of a variable called `var` is `Type`, then we say `var` has type `Type` or `var` is a `Type`.

**Semicolons**: Semicolons mark the end of most statements in C++, if overlooked, the compiler might give mysterious error messages.