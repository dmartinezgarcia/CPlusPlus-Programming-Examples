# 2. Chapter 02 - Variables and Basic Types

**Types** tell the programmer what data means and the operations that can be performed on that data. For example in the following statement:

```cpp
a = a + b;
```

The result of these statement depends on the types of `a` and `b`. This chapter covers the primitive types such as characters, integers, floats and other built-in types and how these can be used to support more complicated types.

## 2.1 Primitive Built-in Types

The **primitive built-in types** include the following:

- **Arithmetic types**: Used to represent characters, integers, booleans, floating point values. They are divided into two categories: **Integral types** and ** Floating-point types**.
- **void type**: A type that has not associated values.

### 2.1.1 Arithmetic types

The size, the number of bits, of **arithmetic types** varies accross machines, and the standard only guarantees minimum sizes as listed in the following table:

![Arithmetic Types Sizes](z01IMAGE.png)

The **integral types** include the following:

- **bool**: Represents `true` or `false` values.
- **char**: The `char` type is the same size as a single machine byte.
- **wchar_t**: Used for extended character sets. Guaranteed to be big enough to hold any character in the machine's largest extended character set.
- **char16_t** and **char32_t**: Used for extended character sets. Intended for Unicode characters.
- **short**, **int**, **long** and **long long**: Used to represent integer values of different sizes.

The **floating-point types** include the following:

- **float**: Single precision values, they usually take 32 bits.
- **double**: Double precision values, they usually take 64 bits.
- **long double**: Extended precision values, they usually take from 96 to 128 bits.

### 2.1.2 Unsigned and signed types

The **integral types char, short, int, long** and **long long** can be:

- **Signed**: Represents negative or positive numbers, including zero. For signed types, the standard says that the range of values for positive and negative values should be evenly divided.
- **Unsigned**: Represents positive values and zero. For unsigned types, all the bits represents the value.

By default, the types **short**, **int** and **long** are all signed, but one can add the unsigned keyword to obtain the corresponding unsigned type, for example:

```cpp
unsigned int a;
unsigned short b;
```

By default, the type **char** signedness depends on the compiler, one can explicitely declare the signedness of a **char** type using one of the keywords mentioned in this section.

### 2.1.3 Type conversions

Types support the ability to **convert** objects of a given type to another.

Type conversions happen implicitly when an object of one type is used where an object of a different type is expected. In particular, for arithmetic values, what happens in a type conversion depends mostly on the range of values that the types permit:

1. When we assign a non bool arithmetic type to a `bool` object, the result is false if the value is zero and tru otherwise.
2. When we assign a `bool` to one of the other arithmetic types, the resulting value is one if the bool is `true` and zero if the bool is `false`.
3. When we assign an integral value to an object of floating-point type, the fractional part is zero.
4. When we assign a floating-point type to an integral value, the value is truncated.
5. When we assign an out-of-range value to an object of unsigned type, the result is the remainder of the value modulo the number of values that the target type can hold. This can be better understood with an example: An `unsigned char` can hold values from 0 to 255, that is 256 values, if we assign the value 256 to an `unsigned char` the compiler will assign the value 0.
6. If we assign an out-of-range value to an object of signed type, the result is undefined. The program might appear to work, it might crash or it will produce garbage values.

This behaviour doesn't limit to assignments, it also applies when testing conditions and the like.

### 2.1.4 Literals

Every **literal** has a type, determined by its form and value.

#### 2.1.4.1 Integer and floating-point literals

We can write **integer literals** in decimal format, in hexadecimal format and in octal format as follows:

```cpp
20;	// Decimal
020; // Octal, begins with a zero.
0x20; // Hexadecimal, begins with a 0x or a 0X.
``` 

The type of integer literals depends on its value and notation, by default, decimal literals are signed and have the smallest type `int`, `long` or `long long` in which the literal's value fits. Octal and hexadecimal can be either signed or unsigned and have the smallest type of `int`, `unsigned int`, `long`, `unsigned long`, `long long` or `unsigned long long` in which the value of the literal can fit. There are no literals of type `short`. You can override these defaults by using any of the suffixes in this table:

![Integer and Floating point suffix](z03IMAGE.png)

**Floating-point** literals include either a decimal point, ., or an exponent, e or E, specified using scientific notation. Some examples could be the following:

```cpp
3.14159;
0.;
0e0;
.001;
3.14159E0;
```
By default, floating-point literals have type `double`, but you can override it using any suffixes in the table above.

You can combine suffixes to define the type and signedness of the literal, for example:

```cpp
L'a';		// Wide character literal, type is wchar_t
u8"hi";		// utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)
42ULL;		// unsigned integer literal, type is unsigned long long
1E-3F;		// single-precision floating-point literal, type is float
3.14159L;	// extended-precision floating-point literal, type is long double
```

#### 2.1.4.2 Character and character strings literals

A character enclosed within single quotes, `''`, is a literal of type `char`. Zero or more characters enclosed in double quotation marks, `""` is a string literal.

```cpp
'a';
"String"; 
```

A string is an **array** of constant characters, the compiler appends appends a `'\0'` to every string literal, to indicate where it ends, so the actual size of a string is the amount of characters enclosed in the double quotes plus one. Two string literals that are only separated by spaces, tabs or newlines are concatenated together into a single string literal, for example:

```cpp
"hello" "hello";
"hello"
"hello";
```

In order to use non-printable characters one would use what is called as **escape sequences**, which are summarized in the following table:

![Escape sequences](z04IMAGE.png)

These are used as any normal character.

#### 2.1.4.3 Boolean and pointer literals

The words `true` and `false` are literals of type `bool`.

The word `nullptr` is a pointer literal. Pointers will be expanded in the following chapters.

## 2.2 Variables

A **variable** provides the programmer with named storage that the programs can manipulate. Each variable has an associated type which determines:

- The size.
- The layout of the memory of the variable.
- The range of values that can be stored within the variable.
- The set of operations that can be applied to the variable.

C++ programmers tend to refer to **variables** as **variables** or **objects**.

### 2.2.1 Variable definitions

A simple **variable definition** consists of a type specified (the name of the type), followed by a list of one or more variable names separated by commas, optional initialization for each of those variables and ends with a semicolon. Variable definition examples are shown in the following example:

```cpp
int sum, value = 0,
	units_sold = 10;
```

### 2.2.2 Variable initialization

An object which is initialized gets the specified initialization value at the moment the object is created, this makes it possible to initialize a variable to the value of one defined earlier in the same definition. Examples are shown below:

```cpp
int a = 10, b = 10 * a;
```cpp

It is important to remember that an initialization is not an assignment, an initialization happens when a variable is given a value at the moment it is created, assignment obliterates the current value of an object and replaces its value with a new one. 

Another way to initialize variables is by using parentheses:

```cpp
int a(10), b(10*a);
```

#### 2.2.2.1 List initialization

C++ defines several forms of initialization, one form of initialization which includes a generalized use of curly braces is usually referred to as **list initialization**:

```cpp 
int units_sold = {0};
int units_sold{0};
```

Both statements above define an `int` variable named `units_sold` and initialize it to `0`. This form of initialization has one important property: The compiler willl not let us unitialize variables of built-in type if the initialization might lead to loss of information:

```cpp
long double ld = 3.14159;
int a{ld}, b = {ld}; // The compiler will give an error.
int a(ld), b = ld; // This is OK, the value will be truncated and both variables will have a value of three.
```

#### 2.2.2.2 Default initialization

When a value is defined and there is no initialization, we say the variable is **default initialized**, these variables are given a default value which depends on the type of the variable and where the variable is defined.

The value of an object of built-in type that is default initialized depends on where the variable is defined, if the variable is defined inside a function the value of the variable is undefined and this might cause problems, if the variable is defined outside any function the variable is initialized to zero (except for some exceptions which shall be covered in the next chapters).

For objects that belong to a class, it is up to the class how default initialized objects of that class are handled, it is the class that defines the default initialization value. For example, the `string` class says that if we do not supply an initializer, the resulting `string` is the empty string `""`.

### 2.2.3 Variable declarations and definitions

C++ supports programs to be written in logical parts by using what is commonly known as separate **compilation**, separate compilation allows programs to be split into several files that can be compiled independently. This creates a new issue, we need a way to share code accross those files, code defined in one place might need to be used in another file.

For this reason, C++ distinguishes between declarations and definitions:

- A **declaration** makes a name known to the program, a file that wants to use a name defined elsewhere includes a declaration of that name. In the case of variables, a variable declaration includes the type and name of the variable. A variable can be declared as many times as the user wants.
- A **definition** creates an entity, it is a declaration, in addition to specifying the name and type, it also allocates storage and may provide the variable with an initial value. A variable can be defined only once.

To obtain a declaration one can use the `extern` keyword, without providing an initialization value, as follows:

```cpp
extern int j;	// Declares but does not define j
int j;	// Declares and defines j.
```

Its usually a good practice to define objects near the point where the object is first used, doing this improves readability and makes it easier to find the definition of variables. Some standards do not support these though.

### 2.2.4 Identifiers

**Identifiers** are sequence of characters that make up a name, they are case sensitive and can be composed of letters, digits and the underscore character. They have no limits in name length and they must begin with either a letter or an underscore. The C++ language reserves a group of names for its own use that can't be used as identifiers. These names can be found in the tables below.

These are the C++ keywords:

![C++ language keywods](z05IMAGE.png)

There are the C++ alternative operator names:

![C++ alternative operator names](z06IMAGE.png)

The standard library also reserves a group of names. Some other rules related to identifiers are that they can't contain two consecutive underscores, they can't begin with an underscored followed immediately by an uppercase letter and identifiers defined outside a function can't begin with an underscore.

### 2.2.5 Scope of a name

A given name can be reused to refer to different entities at different points in a program. A **scope** is a part of the program in which a name has a particular meaning. Most scopes in C++ are delimited by curly braces. Names are visible from the point where they are declared until the end of the scope in which the declaration appears.

In the following example:

```cpp
int main ()
{
	int sum = 0;
	for (int val = 0; val <= 5; val++)
		sum += val;
	return 0
}
```

The name `main` has a global scope, it can be accesible from anywhere in the program. The name `sum` can only be used within the body of main, and the name `val` can only be used within the body of the for loop in the function `main`.

Scopes can be nested, the contained scope is referred to as **inner scope** and the containing scope is **outer scope**. In the following example:

```cpp
int global;			// Global has global scope.
int main () {
	int unique = 0; // Scope is limited to the function body of main.
	int global;		// Hides global variable, creates local variable named global. Scope is limited to the function body of main.
	::global;		// Using the scope operator to refer to the variable named global with global scope.
}
```

While it is usually a very bad practice to define local variables with the same name as global variables, this program serves to explain inner and outer scopes.

# Other Concepts and Notes

**Unicode**: A standard for representing characters used in essentially any natural language.

**Machine level representation of types**: Computers store data as a sequence of bits, which can take the value of zero or one. The smallest chunk of addressable memory is referred to as a **byte** and the basic unit of storage as a **word**. Computers associate an **address** with byte in memory. The following is a possible representation of a word in a machine with 8-bit bytes and 32-bit words:

![Machine representation of bytes](z02IMAGE.png)

The address of the byte is shown on the left, and the bytes on the right. A type determines how these bits are used and how to interpret them.

**Undefined behaviour**: Results from errors that the compiler is not required, or not able, to detect. A program that executes undefined behaviour is an error. Undefined behaviour can appear to execute properly in some circumstances, there are no guarantees that under another circumstances it will execute correctly. Implementing undefined behaviour should be avoided.

**Implementation-defined behaviour**: One example of implementation-defined behaviour is as assuming that the size of an integer is a fixed and known value. Programs that implement this kind of behaviour tend to be not portable, code that is based on implementation-defined behaviour moved to another platform may fail. Implementing this kind of behaviour should be avoided.

**Mixing signed and unsigned types**: When we use both unsigned and signed values in an expression, the signed values are converted to unsigned just like if we tried to assign a negative value to an unsigned objects. This can yield unexpected results and should be avoided. For example in the following expression:

```cpp
int a = -1, b = 1;
a * b;
```

Both variables are signed and the result of the expression is -1, however:

```cpp
int a = - 1;
unsigned int b = 1;
a * b;
```

The result of the expression above depends on the number of bits that an int has on the platform where this program is being executed. Mixing signed and unsigned types should be avoided.

**Negative literals**: There are no negative literals, a negative literal such as:

```cpp
-30;
```

is technically speaking the literal 30 and the minus operand, which negates the value (the literal).

**Object**: Most generally, an object is a region of memory that can contain data and has a type. There are different usages for the term object depending on the programmer but this is the most commonly used acception. In this text we will use the term object regardless of whether the object has a built-in or class type, is named or unnamed, or can be read or written.

**Static typing**: C++ is a statically typed language, which means that types are checked at compile time, this process is known as type checking. The compiler checks whether the operations we write are supported by the types we use, and if not supported it generates an error message. A consequence of static typing is that every entity we use must be known to the compiler.

**Conventions for variable names**: Following these conventions can improve the readability of a program, and they are most useful when followed consistently:

- An identifier should give some indication of its meaning.
- Variable names normally are lowercase.
- Classes we define usually begin with an uppercase letter.
- Identifiers with multiple words should visually distinguish each word.