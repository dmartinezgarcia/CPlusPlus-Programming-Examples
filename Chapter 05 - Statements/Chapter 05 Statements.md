# 5. Chapter 05 - Statements

In this chapter we will look in detail at the statements that the C++ language offers for conditional execution, loops that repeat other statements and jump statements that interrupt the flow control.

## 5.1 Expression statement

An **expression statement** is an expression followed by a semicolon, `;`, the expression is evaluated and the result discarded, like in the examples below:

```cpp
count + 1;          // An expression statement, but rather useless.
std::cout << 5;     // An expression statement, much more useful than the one above.
```

## 5.2 Null statement

The **null statement**, also known as the **empty statement**, is just a semicolon, `;`, like in the example below:

```cpp
count + 1;          // An expression statement.
;                   // A null statement.
```

These kind of statements are useful when the language requires a statement but the program logic does not, for example when the program logic related to a loop can be done within its conditions and the loop's body is empty, see below:

```cpp
int i = get_element_count();
for (int a = 0; a < i; do_something_with_element(a), a++)
    ;   // Body of the loop is a null statement, required by the language but not by the program logic.
```

Sometimes you can find unintended **null statements** that can be harmless, like in the example below:

```cpp
i = a + 5;; // The second semicolon is a redundant empty statement, harmless however.
```

Or that can completely change the logic in a program, like in the example below:

```cpp
while (a < 5);  // The semicolon here will make the program loop forever, as it makes body of the loop be the null statement rather than the variable increment.
    a++;
```

Harmless or not, both scenarios should be avoided, as extraneous semicolons are a potential source of bugs that can alter the program flow and can be very hard to find.

## 5.3 Compound statements

A **compound statements**, also known as **blocks**, are a sequence of statements and declarations within curly braces, `{` and `}`. These kind of statements are not terminated by a semicolon.

A **compound statement** has its own scope and declarations made inside them are only visible to that compound statement and to the compound statements nested inside that compound statement. They are useful when the language requires a single statement but the logic of the program demands multiple statements, thus, by using the a compound statement the language will see our sequence of statements as a single statement, like in the example below:

```cpp
int a = 0, i = 2, c = 3;
while (a < 5)
{   // Beginning of a compound statement.
    a++;    // First statement of the sequence inside the compound statement.
    i++;    // Second statement of the sequence inside the compound statement.
    c++;    // Third statement of the sequence inside the compound statement.
}   // Ending of a compound statement.
```

It's also possible to create a **compound statement** with no statements in it, which would be equivalent to a **null statement**.

## 5.4 Conditional statements

There are two different types of statements for conditional execution in C++, these are:

- The **if statement**, changes the flow control based on a condition.
- The **switch statement**, evaluates an integral expression and changes the flow control based on its value.

### 5.4.1 The `if` statement

An **if statement** changes the flow control based on the evaluation of a condition.

This statement can be written in two different forms, the first form is the simpler form and what is usually called an **if statement**, made just of an `if` clause, see below its syntactic form:

```cpp
if (condition)
  statements_0
```

The *condition* must be enclosed in parentheses and it can be an expression or initialized variable declaration, in either case its type must be convertible to `bool` type.

If *condition* evaluates to `false`, then the flow of execution continues with the code after the `if` statement, otherwise *statements_0* is executed.

The second form is known as **if else statement** and it includes an `else` clause along with an initial `if` clause, see below its syntactic form:

```cpp
if (condition)
  statements_0
else
  statements_1
```

The same mentioned before for *condition* can be said here, although if *condition* evaluates to `false` then `statements_1` is executed.

In both scenarios, *statements_0* and *statements_1* can be a **single statement** or a **compound statement**.

It's possible to nest `if` statements, obtaining a construct similar to the one below:

```cpp
if (condition_0)
  statements_0
else if (condition_1)
  statements_1
else if (condition_2)
  statements_2
else if (condition_3)
  statements_3
else
  statements_4
```

The way this construct should be straight-forward for the reader. It's recommended to always use curly braces to delimit the body of the `if` statements, this way the coder will avoid potential issues with dangling `else` clauses and code executing when it shouldn't.

The following example depicts a dangling `else` clause:

```cpp
if (a)
  if (b)
    ;
else            // Indentation suggests that the coder intended for this else clause to match with the first if, however it will match with the second if.
    ;
```

And the following is an example that alters the program logic because curly braces were not used.

```cpp
if (a)
  a++;
else
  // Missing beginning curly brace here.
  b++; // This statement will execute based on the condition.
  c++; // Indentation suggests that this statement should only be executed in the else clause, however it will be executed unconditionally.
  // Missing ending curly brace here.
```

### 5.4.2 The `switch` statement

A **switch statement** selects an execution path depending on the evaluation of an `integer` expression. Usually, its syntactic form is as follows:

```cpp
switch (condition)
{
    case_label_0:
        statements_0
        break;

    case_label_1:
        statements_1
        break;

    case_label_2:
        statements_2
        break;

    ...

    default:
        default_statements
        break;
}
```

A `switch` statement first evaluates the *condition*, which is can be expression or an initialized variable declaration that can be converted to an `integer` type, afterwards the result of the evaluation is compared against each `case` label, (*case_label_0*, *case_label_1*, *case_label_2*...) and the flow of execution jumps to the body of the `case` label that matches (*statements_0*, *statements_1*, *statements_2*...), if no match is found, then the flow of execution jumps to the `default` label and *default_statements* is executed instead. Execution continues normally until the end of the `switch` is reached or a `break` statement is found, this means that if no `break` statement is found, the body of subsequent `case` labels to the one that matched will be executed.

As the reader might have assumed by now, it's not possible to have two `case` labels with the same value, although it's possible to stack `case` labels to the same block of statements, like in the example below:

```cpp
switch (value)
{
    // First form.
    case 0:
    case 1:
    case 2:
        value++;
        break;

    // Second form.
    case 3: case 4: case 5:
        value += 2;
        break;

    default:
        value--;
        break;
}
```

It is illegal to jump from a place where a variable with an initializer is out of scope to a place where it is in scope, for example see below:

```cpp
case true:
    int a = 5;
    int b;
    break;

case false:
    std::cout << a << std::endl; // Not a valid statement, in scope but initialization skipped.
    std::cout << b << std::endl; // Valid statement, in scope and initialization not skipped as there was no initialization.
    break;
```

In case the `switch` condition evaluates to `false`, the initializations are skipped however the variables are still in scope and used in the body of the `case` label `false`, the language won't allow us to do this. It's possible to define and initialize a variable for a particular case by using a **compound statement** as follows:

```cpp
case true:
    {
        int a = 5;
        int b = 2;
        std::cout << a << std::endl;
    }
    break;

case false:
    {
        int a = 10;
        std::cout << a << std::endl;
        std::cout << b << std::endl; // Error as b is not in scope.
    }
    break;
```

By defining the variable inside curly braces we ensure that the scope of the variable is limited to where the curly braces open and close.

## 5.5 Iterative statements

Also known as **loops**, they repeat a single statement or a compound statement while a condition is `true`.

There are four different kind of loops:

- The `while` statement.
- The traditional `for` statement.
- The range `for` statement.
- The `do while` statement.

Which we will explain this sectors.

### 5.5.1 The `while` statement

A **while** statement is written as follows:

```cpp
while (condition)
    statement
```

The *statement* is executed as long as the *condition* is evaluated as `true`. The *condition* can't be an empty field.

Variables defined in a **while** loop, either in the *condition* or the *statement* fields, are created and destroyed in each iteration.

### 5.5.2 The traditional `for` statement

The **traditional for** statement is written as follows:

```cpp
for (initializer; condition; expression) // Also referred as for header.
    statement
```

The *initializer* is only executed on the first iteration of the loop, and it's usually used to initialize the variables that will be used in the loop. The *condition* is used as a loop controller, as long as it evaluates to `true` its body will be executed. The *statement* and *expression* fields are executed if the *condition* evaluates to `true` and in this order, first the *statement* and afterwards the *expression*.

As usual, variables defined in the *initializer*, *condition*, *statement* and *expression* fields are only visible within the `for` loop.

It's possible to define multiple variables in the *initializer* field, like in the following example:

```cpp
for (int a = 0, int b = 1, int c = 2; a < c; a++;
    ...
```

It's also possible to omit one or all the fields in the `for` header, in particular if the *condition* field is omitted it is the same as replacing it by `true`.

### 5.5.3 The range `for` statement

The syntactic form of the **range for** statement is the following:

```cpp
for (declaration : expression)
    statement
```

This statement can be used to iterate through elements of a container or a sequence. Because of this the field *expression* must represent a sequence such as:

- Braced initializer list.
- An array.
- An object with `begin` and `end` members that return iterators, such as `vector` or `string`.

The *declaration* defines a variable with a type that has a conversion from each element of the *expression* sequence or container to its type, usually, the `auto` type qualifier is useful in this regard.

In case we want to write to the elements of the sequence or container in *expression* the *declaration* must be a `reference`.

On each iteration, the variable defined in *declaration* is defined and initialized with the next value in the sequence, afterwards the *statement* is executed, this can be a single *statement* block or a compound *statement. Once all elements have been processed, the loop terminates.

An example of a **range for** statement is as follows:

```cpp
vector<int> v = {1, 2, 3, 4};
for (auto &element : v)
    element = element + 1;
```

It's not possible to use a **range for** to add or remove elements to the sequence or container in the *expression* field, reason being that the end value is cached and if the number of elements is modified it the cached value will be invalidated.

### 5.5.4 The `do while` statement

The **do while statement** is similar to a `while` statement but the *condition* is executed after the *statement*, this means that the loop executes at least once. Its syntactic form is the following:

```cpp
do
    statement
while (condition);
```

In this loop and as mentioned before, first *statement* is executed and afterwards *condition* is evaluated, if it evaluates as `true` then *statement* is executed again and so on. 

Variables used in the *condition* field of the loop can't be defined in the *statement* field. It's also not possible to define variables in the *condition* field.

## 5.6 Jump statements

A **jump statement** provides a way to interrupt the normal flow of execution, there are four different kinds of jumps in C++:

- The `break` statement.
- The `continue` statement.
- The `goto` statement.
- The `return` statement.

### 5.6.1 The `break` statement

A **break statement** terminates the iterative statement (`while`, `do while`, `for`) or switch statement where it is enclosed. Execution resumes at the statement immediately after the terminated statement.

An example is given below:

```cpp
switch (a)
{
    case 0:
    a++;
    break;

    default:
    break;
}
```

### 5.6.2 The `continue` statement

A **continue statement** appears inside a iterative statement (`while`, `do while`, `for`) and it ends the current iteration of the iterative statement where it is enclosed and afterwards starts the next iteration.

Depending which iterative statement includes the **continue statement** its behaviour is different, below is an explanation of all possible behaviours for this statement

- In the case of a `while` or `do while` loop, execution continues by evaluating the *condition*.
- In the case of a traditional `for`, execution continues by evaluating the expression.
- In the case of a range `for`, execution continues by initializing the variable in *declaration* with the next element in the sequence.

### 5.6.3 The `goto` statement

A **goto statement** provides the mean to do an unconditional jump from one statement to another statement in the same function. Its syntactic form is:

```cpp
goto label;
```

where label is an identifier to a **labeled statement**. The **goto statement** and the labeled statement it points to must be in the same function.

## 5.7 Exception handling

An **exception** is a run-time anomaly that might exist outside the normal functioning of a program. There are two parts that we can distinguish in the handling of exceptions:

- The **detecting part**, a piece of code that detects a problem that it can't handle and the issue is such that the piece of code is unable to continue processing. The detecting part needs a way to signal outside about the problem that occurred, for this purpose, C++ implements the `throw` statement which is used to raise exceptions. After an exception has been raised, the piece of code that raised it stops execution.

- The **handling part**, the piece of code that is used to handle the exception raised, for this purpose C++ implements the `try` statement which can also include one ore more `catch` statements. If the code executed inside a `try` statement raises an exception, the `catch` statements can handle those exceptions, reason why a `catch` statement is also known as an **exception handler**.

C++ also implements a **exception classes** which are used to pass information between the `throw` that raises an exception and the `catch` statement that handles it.

This is a brief overview of exception handling, we will see each of these concepts it in detail in the following sections.

### 5.7.1 The `throw` statement

To raise an exception we can use the **throw statement** followed by an expression, the type of this expression determines the type of exception the statement raises. The complete syntactic form is shown below:

```cpp
throw exception;
```

An example could be the following:

```cpp
throw runtime_error("This is an example of an exception.");
```

In the example we have used the `runtime_error` exception type which we will see in detail in the next sections, for now it suffices to say that it needs a `string` or a C-style string as an argument and that the `stdexcept` header needs to be included to make use of it.

### 5.7.2 The `try` statement

The syntactic for of the **try statement** is as follows:

```cpp
try
{
    detection_statements;
}
catch (exception_declaration_0)
{
    handler_statements_0;
}
catch (exception_declaration_1)
{
    handler_statements_1;
}
catch (exception_declaration_2)
{
    handler_statements_2;
}
```

The *detection_statements* of the block are executed first and constitute the normal logic of the program, should an exception be raised while executing that piece of code then the **search for an exception handler** starts, explained in the next paragraphs.

The search for an exception handler means looking for the nearest `catch` block in the call chain whose exception declaration type matches the exception raised type. Excepted declaration doesn't necessarily need a name and it can be unnamed.

In complicated systems, the execution flow of a program can pass through multiple nested `try` statements, in this case, the search for a handler reverses the call chain, first it looks in the function that threw the exception, if not found, then the execution of that function terminates, and so on until a handler is found.

If no appropriate handler is found, then the execution terminates via the `terminate` library function, which is system dependant but guaranteed to end the program.

It's possible to throw exceptions without `try` blocks, and in this case as there are now `try` blocks and therefore no `catch` statements it means that the execution flow will go directly to the `terminate` library function.

If the exception raised matches one of the `catch` statements then it means that an exception handler was found, and then the associated block of statements is executed, in our example *handler_statements_0*, *handler_statements_1* or *handler_statements_2*. Following the execution of the exception handler, execution continues with the code following the last `catch` statement.

An example of the `try` block:

```cpp
int a = 0;

try
{
    if (a == 0)
    {
        throw runtime_error("This is an exception.");
    }
}
catch (runtime_error error)
{
    std::cout << error.what() << std::endl;
}
```

Exceptions interrupt the normal flow of a program, which means that when an exception is raised objects might be invalidated or resources not freed... this requires proper "clean up" in the exception handler, a program that does this is said to be **exception safe**.

### 5.7.3 Standard exceptions

There are four headers that define **standard exceptions**:

1. The **exception header** defines the most general kind of exception, named `exception`, this kind of exception just tells that an exception occurred but gives no more information.

2. The **stdexcept header** defines many general-purpose exceptions, described below:

|Exception Name|Description|
|:---:|:---:|
|`exception`|General type of exception.|
|`runtime_error`|Exception that is raised when a problem is encountered at run time.|
|`range_error`|Run time problem, result generated outside of the valid range of values.|
|`overflow_error`|Run time problem, a computation overflowed.|
|`underflow_error`|Run-time problem, a computation underflowed.|
|`logic_error`|Error in the logic of the program.|
|`domain_error`|Logic error: argument for which no result exists.|
|`invalid_argument`|Logic error: inappropriate argument.|
|`length_error`|Logic error: attempt to create an object larger than the maximum size for that type.|
|`out_of_range`|Logic error: used a value outside the valid range.|

3. The **new header** defines the `bad_alloc` exception type.
4. The **type_info header** defines the `bad_cast` exception type.

Some of these exceptions are default initialized (in particular, `exception`, `bad_alloc` and `bad_cast`) and the others can be initialized with a `string` or a C-style string, which is used to provide textual information about the error.

They just have a few operations, creation, copy assignment and another kind of operation known as `what`, which usually returns a textual description of the error raised.

# Other terms and concepts

**Statement scope**: It's possible to define variables inside `if`, `switch`, `while` and `for` statements. They are only visible within that statement and out of scope when that statement ends, if access to those variables is needed outside these statements, they need to be defined outside the statements.

```cpp
for (int i = 0; i < 5; i++);
i++; // Variable i is not longer accessible outside the for loop.
```

**Labeled statement**: An statement that is preceded by a label identifier with a semicolon, like in the example below:

```cpp
end: return;
```

Label identifiers are independent of other names used for variables, classes, functions... this means that a label can have the same name as another entity without issue.
