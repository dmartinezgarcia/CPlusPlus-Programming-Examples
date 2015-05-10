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

The errors a compiler most commonly can find are the following:

1. Syntax Errors: The programmer has made a grammatical mistake. Overlooking a semicolon at the end of a programming statement is an example of a syntax error.
2. Type errors: Each object has an associated type. One example of a type error is passing a string literal to a function that expects an integer as a parameter.
3. Declaration error: All names must be declared before they are used. A common error is to misspell the name of a declared variable.

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

When an stream is tested, like for example in these statements:

```cpp
int v1;
if (std::cin << v1)
{
	...
}
```
The effect in this case is to test the status of the stream, if the stream hasn't encountered an error it will return `true` and `false` otherwise. In particular, a `istream` object returns `false` when an EOF (end of file) is detected or when reading a value that is of different type than the type of the variable where the value will be stored.


## 1.3 Comments

Comments help readers understand our code. They are ignored by the compiler and as such have no effect on the program behaviour or performance.

Programmers tend to trust comments even if the system documentation is out of date and this is the reason why an incorrect comment is worse that no comment as it might mislead the reader.

### 1.3.1 Single-line comments

A **single-line comment** starts with a double slash (`//`) and ends with a newline. Everything on the right-hand side of the double slash including the double slash is ignored by the compiler. This kind of comment can contain any text inside it including double slashes. An example could be the following:

```cpp
int main (void)
{
	return 0; // This statement returns zero.
}
```

Single-line comments tend to be used for half-line and single-line remarks.

### 1.3.2 Paired comments

**Paired comments** use two delimiters: `/*` to start the comment and `*/` to end the comment. Paired comments can include anything inside that is not a `*/`, when it includes multiple lines, its usually a good idea to mark the beginning of the new lines with an asterisk to indicate that line is a comment. An example could be the following:

```cpp
/*
 *	This is a multiline comment explaining how a function works.
 *
 *	Perhaps more details could be given here about how a function works, for example explaining parameters or the return value of the function.
 *	
 */

int main (void)
{
	int v1, v2;
	return 0;
}
```

Comment pairs are used for multiline explanations. It is important to note that paired comments do not nest, a comment that begins with `/*` ends in the next `*/`.

## 1.4 Flow of the program

Programming statements execute sequentially and C++ offers various methods to change the flow of the program.

### 1.4.1 The while statement

The `while` statement is an iterative form of flow control. Its syntax is as follows:

```cpp
while (condition)
	statements;
```

The `while` loop executes as follows:

1. The `condition` is evaluated.
  1.1. If `condition` evaluates to `true`, the `statements` is executed and `condition` is evaluated again.
  1.2. If `condition` evaluates to `false`, the `statements` is not executed and the flow of operation continues with the programming statements that follow the `while` loop.

### 1.4.2 The for statement

The `for` statement is another form of iterative loop and the syntax is as follows:

```cpp
for (init-statement; condition; expression)
	statements;
```

The execution of the `for` loop is as follows:

1. The `init-statement` is executed.
2. The `condition` is executed.
  2.1. If `condition` evaluates to `true` the `statements` are executed, then `expression` is executed. After that, the flow returns to 2. 
  2.2. If `condition` evaluates to `false` the `statements` nor `expression` is executed, the flow continues with the programming statements that follow the `for` loop.

### 1.4.3 The if statement

The `if` statement is used for conditional execution of statements. Its complete syntax is as follows:

```cpp
if (condition1)
	statements1;
else if (condition2)
	statements2;
else if (condition3)
	statements3;
...
else
	statements4;
```

The `if` statement above would execute as follows:

1.1. If `condition1` evaluates to `true`, then `statements1` is executed and the flow continues with the statements that follos the `if` statement.
1.2. If `condition2` evaluates to `true`, then `statements2` is executed and the flow continues with the statements that follow the `if` statement.
1.3. if `condition3` evaluates to `true`, then `statements3` is executed and the flow continues with the statements that follow the `if` statement.
1.4. If all the conditions evaluate to `false`, then `statements4` is executed and the flow continues with the statements that follow the `if` statement.

## 1.5. Classes

Classes are used in C++ to define data structures. In particular, a `class` defines a type along with a collection of operations that are related to that type. To use a `class`, these three things need to be known first:

* Its name.
* The place where it is defined.
* The operations it supports.

### 1.5.1 Using classes

The programmer doesn't need to know how classes are implemented, they need to know what operations it can perform and what type it defines. Every class defines a type, for example a class named `myclass` defines the type `myclass`, and it can be used to declare variables of that type:

```cpp
myclass var;
```

Its important to note that the header associated with the class must be included in the program to be able to use the class, so for example we would need to add the following statement to our previous statements:

```cpp
#include "myclass"
```

### 1.5.2 Member functions

A member function is a `function` that is defined as part of a class, they are also often referred to as `methods`. Following from our previous example, we could call the method `mymethod` which belongs to the `myclass` class as follows:

```cpp
myclass var;
var.mymethod();
```

In the previous example, we introduce two new operators: the dot `.` operator and the call `()` operator. 

The dot operator is only used with variables that have type class. The left-hand operand is the object of type class and the right-hand operand is a member of that type, the result is the member named by the right-hand operand.

The call operator is used to call a function, the parentheses enclose the list of parameters to pass to that function.

# Other Concepts and Notes

**File redirection**: Most operating systems support file redirection, which lets the user associate a file with the standard input, `std::cin`, and the standard output, `std::cout`.

**Entering an End-Of-File from the keyboard**: On Windows systems we enter an end-of-file by tiping a Control-z.

**Standard library and namespaces**: The prefix `std::` in `std::cout` refers to the name `cout` inside the `std` namespace, which is the namespace of the standard library. The scope operator `::` used in this statements means that we wish to refer to the name `cout` in the namespace `std`. Namespaces prevent confusion between the names we define and the names inside a library. 

**Including libraries**: The `include` directive is used to include headers, every program that uses a library must include its header. In general the `include` directive is writting at the beginning of the source file. For example, if we wish to include the `iostream` library:

```cpp
#include <iostream>
```

Where `iostream` is the header of the `iostream` library. Headers from the standard library are enclosed within `<>` and those that are not are enclosed within `""`.

**Source files**: Files that contain programs are usually called source files. On most systems, the name of a source file ends with a suffix. Different compilers might use different naming conventions, but the most common suffixes are the following: .cc, .cxx, .cpp, .cp and .c.

**Header files**: Files that are associated to source files, these must be included to use libraries and classes. Usually, header file names are derived from the name of a class defined in that header. They usually have a suffix of .h, .hpp or .hxx.

**Type**: A type defines the contents of a data element and the operations that are allowed on that data. The data programs manipulate is stored in variables and every variable has a type. When the type of a variable called `var` is `Type`, then we say `var` has type `Type` or `var` is a `Type`.

**Semicolons**: Semicolons mark the end of most statements in C++, if overlooked, the compiler might give mysterious error messages.