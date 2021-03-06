# 4. Chapter 04 - Expressions

An **expression** is composed of one or more operands and it returns a result when evaluated. The simplest form of an expression could be a literal of a variable, that, once evaluated, returns the value of that literal or that variable. To create more complex variables operators and more operands are used.

In this chapter we will see the operators defined by the language applied to built-in types and also some of the operators defined by the libraries.

## 4.1 Fundamentals

There are a few fundamental concepts that we should keep in mind before introducing the operators, these concepts explained in this section apply to most of the expressions.

### 4.1.1 Types of operators

There are different types of operators:

- **Unary operators**, that take one operand, for example the address-of operator, `&a`.
- **Binary operators**, that take two operands, for example the multiplication operator, `a * b`.
- **If ternary operator**, which takes three operands, `(a) ? b : c`.
- **Function call operator**, that takes an unlimited number of operands, `a(b, c, d, e)`.

Notice that the same symbol can represent different operators, the context in which a symbol is used determines if the symbol represents one operator or another operator.

### 4.1.2 Compound expressions

An expression with two or more operators is a **compound expression**, to understand these kind of expressions we need to be aware of the concepts of **precedence** and **associativity** and the **order of evaluation** of the operands.

#### 4.1.2.1 Precedence and associativity

**Precedence** and **associativity** determine which parts of the expression are the operands for each of the operators in the expression.

Operands of operators with higher precedence more tightly than operands of operators at lower precedence, and associativity determines how to group the operators with the same precedence.

The parentheses in the following expression indicate the default precedence and associativity:

```cpp
// Evaluates to 14.
((6 + ((3 * 4) / 2)) + 2);
```

With parentheses, it's possible to override the default precedence and associativity, as an example the expression below where parentheses are used to modify the default grouping in different ways:

```cpp
(6 + 3) * (4 / 2 + 2); // Evaluates to 36.
((6 + 3) * 4) / 2 + 2; // Evaluates to 20.
```

There are special cases when precedence is specially important, for example in the following scenario:

```cpp
int a[] = {10, 20, 30, 40, 50};
int element = *(a + 4); // The value in element will be 50.
element = *a + 4; // The value in element will be 10 + 4 = 14.
```

And there are also special cases where associativity matters, for example with the left associative Input (>>) and Output (<<) operators, we can combine multiple of these operators in a single expression because they are associate, like in the examples below.

```cpp
// Read into a1 and a2.
cin >> a1 >> a2;
// Output a1 and a2.
cout << a1 << a2;
```

For more information, there is a table at the end of this section where all the C++ operators are included, including their precedence.

#### 4.1.2.2 Order of evaluation

In most cases the order how expressions are evaluated is unspecified, for example in the following expression:

```cpp
int i = f1() * f2();
```

It's not possible to know which function call is executed first, we just know that both function calls will occur before the multiplication can be done.

For operations that do not specify the evaluation order, it's an error for an expression to *refer to* and *change* the same object, expressions that do so have undefined behaviour, for example the input operator `<<` makes no guarantees about when or how its operands will be evaluated. As a result, the following expression is undefined:

```cpp
int i = 0;
cout << i << " " << ++i << endl; // undefined
```

The order of evaluation is independent of precedence and associativity, for example in the following code:

```cpp
f() + g() * h() + j();
```

We can say that:

* **Precedence** guarantees that the return values of `g()` and `h()` are multiplied.
* **Associativity** guarantees that the result of `f()` is added to the product of `g()` and `h()`, and that the result of the addition is added to the value of `j()`.
* In regards of **order of evaluation**, there is no way to guarantee which one of these functions will be called first.

If any of these functions affect the same object, then these functions are in error, as it has undefined behaviour.

There are however four operators that do guarantee the order in which operands are evaluated:

- The **logical AND operator**, `&&`, guarantees that its left-hand operator is evaluated first, and it also guarantees that the right-hand operator will only be evaluated if the left-hand operator is `true`.
- The **logical OR operator**, `||`, the left hand operand is evaluated first, and the right hand operator is evaluated only and only if the left hand operand is false.
- The **ternary conditional operator**, `?:`, first the condition is evaluated and afterwards the first expression or the second expression is evaluated depending on whether the condition is evaluated as `true` or `false` respectively.
- The **comma operator**, `,`, evaluates the left hand operand first, then discards the result, and then it evaluates the right hand operand, whose result is the value yielded by the operator.

#### 4.1.2.3 Operand conversions

An operand of one type can be used when an operand of another type is expected if both types are related, two types are related if there is a conversion between them. A **conversion** is defined as the process where a value of one type is converted to a value of another type, C++ defines conversions between the built-in types although conversion for class types are also possible.

##### 4.1.2.3.1 Implicit conversions

An **implicit conversion** is one that is carried out by the compiler without programmer intervention.

##### 4.1.2.3.1.1 Circumstances under which an implicit conversion occurs

Implicit conversions occur under the following circumstances:

- In **most expressions**, values of integral types smaller than `int` are promoted to an appropriate larger integral type.
- In **conditions**, expressions which are not of `bool` type are converted to `bool`.
- In **initializations**, the initializer is converted to the type of the variable.
- In **assignments**, the right hand operand is converted to the type of the left-hand operand.
- In **arithmetic expressions** with operands of mixed types, all the types are converted to a common type.
- In **relational expressions** with operands of mixed types, all the types are converted to a common type.
- In **function calls**, as we will see in later sections, type conversions also occur.

##### 4.1.2.3.1.2 Types of implicit conversions

There are several types of **implicit conversions**, some of them are explained below:

- Arithmetic conversions.
- Array to pointer conversions.
- Pointer conversions.
- Conversion to `bool`.
- Conversion to `const`.
- Conversion defined by class types.

The **arithmetic conversions** define a set of conversions in which operands are converted to a widest type.

When a small integral type is converted to a larger one an **integral promotion** occurs. The target type depends on many factors, see below:

- The types `bool`, `char`, `signed char`, `unsigned char`, `short` and `unsigned short` are promoted to `int` if all possible values of the source type fit in an `int`. Otherwise the value is promoted to `unsigned int`.

- In the specific case of a `bool` type, `false` promotes to `0` while `true` promotes to `1`.

- The `char` types `wchar_t`, `char16_t` and `char32_t` are promoted to the smallest type of `int`, `unsigned int`, `long`, `unsigned long`, `long long` or `unsigned long long` in which all possible values of the source type fit.

If operands of an operator have different types they are converted to a common type, regarding **signedness**, the following rules apply:

- If both operands have the **same signedness**, then the operand of smaller type is converted to the larger one.
- If the operands have **different signedness and the type of `unsigned` operand is the same as or larger than the `signed` operand**, then the `signed` operand is converted to `unsigned`.
- If the operands have **different signedness and the type of the `unsigned` operand is smaller than the `signed` operand**, the result is machine dependent... if all the values in the `unsigned` type fit in the type of the `signed` operand then the `unsigned` type is promoted to that type, otherwise the type of the `signed` operand is converted to the type of the `unsigned` operand.

The following are examples of **arithmetic conversions**:

```cpp
/// Define the types.
bool    boolVal;            char                charVal;
short   shortVal;           unsigned short      unsignedShortVal;
int     integerVal;         unsigned int        unsignedIntegerVal;
long    longVal;            unsigned long       unsignedLongVal;
float   floatVal;           double              doubleVal;

/// Examples.
3.14159L + 'a';                     // 'a' promoted to 'int', then to 'long double'.
doubleVal + integerVal;             // integerVal converted to 'double'.
doubleVal + floatVal;               // floatVal converted to 'double'.
integerVal = doubleVal;             // doubleVal converted to 'int'.
boolVal = doubleVal;                // If doubleVal is zero, then the boolean value is 'false', otherwise 'true'.
charVal + floatVal;                 // charVal promoted to 'int', then converted to 'float'.
shortVal + charVal;                 // shortVal and charVal promoted to 'int'.
charVal + longVal;                  // charVal converted to 'long'.
integerVal + unsignedLongVal;       // integerVal converted to 'unsigned long'.
unsignedShortVal + integerVal;      // Promotion depends on the size of 'unsigned short' and 'int'.
unsignedIntegerVal + longVal;       // Conversion depends on the size of 'unsigned int' and 'long'.
```

The **array to pointer conversion** occurs when we use an array in an expression, it's automatically converted to a pointer to the first element of the array:

```cpp
char charArray[10];                 // Array of ten 'chars'.
char *charArrayPt = charArray;      // Same as &charArray[0].
```

This conversion doesn't occur in the following scenarios:

- When used with `decltype`, as an operand of the **address-of** operator, `sizeof` operator or `typeid` operator.
- When used to initialize a reference to an array.

The **pointer conversions** include the following:

- A constant integer value of `0` and `nullptr` can be converted to any pointer type.
- A pointer to any non `const` type can be converted to `void*`.
- A pointer to any type can be converted to `const void*`.
- Additional pointer conversion occurs to types related by inheritance,

The **conversion to `bool`** which occurs with arithmetic or pointer types, if the pointer or arithmetic value yields zero, the conversion yields `false` and any other value yields `true`.

The **conversion to `const`** which occurs when converting a pointer to a non `const` type to a pointer to a `const` type and similarly for references.

```cpp
char a;
const char &refA = a; // Conversion of non 'const' char to reference to 'const char'.
const char *ptrA = &a; // Conversion of pointer to non 'const char' to pointer to 'const char'.
```
It's not possible to do the reverse conversion, that is removing a low level `const`.

The **class defined conversions** are the ones defined by class types and applied by the compiler automatically.

```cpp
// A class defined conversion occurs when initializing a 'string' with a C-style string.
string a = "I'm a C-style string";
// A class defined conversion occurs when evaluating an 'istream' in a condition.
if (cin) ... // cin is converted to bool.
```

##### 4.1.2.3.2 Explicit conversions (casts)

Used when the programmer wants to explicitly convert an object to a different type. In order to do this different kinds of **casts** (short for explicit conversion) can be used:

- **Named casts**, which are **static_cast**, **dynamic_cast**, **const_cast** and **reinterpret_cast**.
- **Old-style casts**.

##### 4.1.2.3.2.1 Named casts

A **named cast** has the following form:

```cpp
cast-name<type>(expression);
```

Where:

- **type** is the target type.
- **expression** is the value that will be casted.
- **cast-name** is one of the following: `static_cast`, `dynamic_cast`, `const_cast` and `reinterpret_cast`.

A **static_cast** can be used for any well-defined type conversion, excluding those that involve the low-level `const`type qualifier.

```cpp
// In this example, we cast an integer to double to force floating point division.
int a = 1, b = 2;
double divResult = static_cast<double>(a) / i;
```

Another uses of **static_cast** include casting a large arithmetic type to a smaller type, which will turn the potential compiler warnings off and also inform the reader that we are aware of the loss of precision.

Another useful use of **static_cast** is converting a pointer to `void` back to its original pointer type, however in this case the user must ensure that the target type is the correct one as otherwise the behaviour is undefined.

We will see the **dynamic_cast** in detail in later chapters, however this only performs the conversion to the target type only and only if the results is a valid complete object.

A **const_cast** changes the low-level `const` in its operand, like below:

```cpp
const char *ptrToConst;
char *p = const_cast<char*>(ptrToConst);
```

This type of cast is the only cast that can "cast away the `const`", however it should be noted that if attempting to write to a `const` object after casting away the `const` using this cast will result in undefined behaviour, if the object was originally not a `const` then there is no problem.

A **const_cast** is the only type of cast that can be used to change the low level `const` of an expression, other named casts will result in compile-time errors, as proved by the examples below:

```cpp
const char *ptrToChar;

char *chr = static_cast<char*>(ptrToChar); // Compile-time error, this type of cast won't cast away the const.
static_cast<string>(ptrToChar); // OK: Will cast the string literal to a string. 
const_cast<string>(ptrToChar);  // Compile-time error, a const_cast can only cast away the const.
```

A **reinterpret_cast** performs a low level reinterpretation of the bit pattern of its operands, and because of this, it's a dangerous cast and it should be avoided as it requires completely understanding of the types involved as well as the details of how the compiler implements the cast.

```cp
int *intPtr;
// The following is valid... and dangerous.
char *charPtr = reinterpret_cast<char*>(intPtr);
```

##### 4.1.2.3.2.2 Old-style casts

In early versions of C++, an **explicit cast** took the following form:

```cpp
type(expr); // Function cast notation.
(type)expr; // C-language style cast notation.
```

Depending on the types involved in the cast, it has the same behaviour as one of the named casts, that's why they should be avoided as they are less visible than the named casts. Generally, an old-style cast used where a `static_cast` or `const_cast` would be valid, the old-style cast will perform the conversion the same way as the respective named cast. If not valid, it will do the same conversion as a `reinterpret_cast`.

##### 4.1.2.3.2.3 To cast or not to cast

It's recommended to avoid explicit casting as it interferes with normal type checking. Every time a cast is required the user should think hard about whether the same goal can by accomplished by different means.

### 4.1.3 Overloaded operators

We can define the behaviour of most operators when applied to class types, when such definitions give an alternative meaning to an existing operator, we refer them as **overloaded operators**. An example of overloaded operators are the input operator `<<` and the output operator `>>` that we use with `string` or `vector`.

When using overloaded operators, the meaning of the operator, the type of the operand and the result depend on how the operator is implemented butt he number of operands and the precedence and associativity of the operator cannot be changed.

### 4.1.4 Lvalues and Rvalues

Expressions in C++ can be of two possible types:

- **rvalue expression**: Represents an object which doesn't occupy an identifiable location in memory, for example an object that resides in a temporary register for the duration of the computation..
- **lvalue expression**: Represents an object which occupies an identifiable location in memory, for example an object with an address.

It usually works by exclusion, if an expression is not a `lvalue` then it is a `rvalue`, for example the following code:

```cpp
int var; // Var is an lvalue expression with an identifiable location in memory.
var = 4; // var is an lvalue.
4 = var; // The constant 4 is not an lvalue, it's an rvalue, there is no identifiable location in memory where to store it.
(var + 5) = 4; // Same as before for (var + 5), it's an rvalue, so it's not possible to assign anything to it, there is no identifiable location in memory where to store it.
```

Operators differ as to whether they need `lvalue` or `rvalue` operands. Except for a few particular cases, it's possible to use a `lvalue` expression where a `rvalue` expression is required and in this case the contents of the `lvalue` are used, but it's not possible to use an `rvalue` where a `lvalue` is required.

## 4.2 Arithmetic operators

**Arithmetic operators** are left associative, the table below shows the different arithmetic operators, grouped by precedence, those in the same group have the same precedence.

|**Operator**|**Function**|**Use**|
|:---:|:---|:---|
|`+`|Unary plus|`+expr`|
|`-`|Unary minus|`-expr`|
||||
|`*`|Multiplication|`expr * expr`|
|`/`|Division|`expr / expr`|
|`%`|Remainder|`expr % expr`|
||||
|`+`|Addition|`expr + expr`|
|`-`|Subtraction|`expr - expr`|

The arithmetic operators can be applied to any of the arithmetic types or any other type that can be promoted to an arithmetic type, and the results of these operands are always `rvalues`.

The **unary plus**, **addition** and **subtraction** operators can also be applied to pointers.

The **division operator**, if the result is a fractional part, it is truncated towards zero, below find some examples of this behaviour:

> 21 / 6 -> Result is 3.
> 21 / 7 -> Result is 3.
> -21 / -8 -> Result is 2.
> 21 / -5 -> Result is -4.

The **modulo operator** might require additional explanation, it only works with integers and it's defined so that:

> `m` and `n` are integers
> `n` is non-zero value
> then: `(m/n)*n + m%n` is equal to `m`
> By implication: if `m%n` is nonzero, then it has the same sign as `m`.

Below find some examples of the **modulo operator**:

> 21 % 6 -> Result is 3.
> 21 % 7 -> Result is 0.
> -21 % -8 -> Result is -5.
> 21 % -5 -> Result is 1.

## 4.3 Logical and relational operators

The table below shows all the **logical operators** and **relational operators** sorted by precedence, those in the same group have the same precedence:

|**Associativity**|**Operator**|**Function**|**Use**|
|:----:|:----:|:----|:----|
|Right|`!`|NOT (logical)|`!expr`|
|Left|`<`|less than (relational)|`expr < expr`|
|Left|`<=`|less than or equal (relational)|`expr <= expr`|
|Left|`>`|greater than (relational)|`expr > expr`|
|Left|`>=`|greater than or equal (relational)|`expr >= expr`|
|||||
|Left|`==`|equality (relational)|`expr < expr`|
|Left|`!=`|inequality (relational)|`expr < expr`|
|||||
|Left|`&&`|AND (logical)|`expr && expr`|
|Left|`\|\|`|OR (logical)|`expr \|\| expr`|

The **relational operators** take `rvalue` operands of arithmetic or pointer type, they return `rvalue` values of type `bool`.

The **logical operators** take `rvalue` operands of any type that can be converted to `bool`, they return `rvalue` values of type `bool`.

Arithmetic and pointer values with a value of zero are all promoted to `false`, and `true` if otherwise.

### 4.3.1 Short-circuit evaluation of logical OR and AND operators

The **logical AND** and **logical OR** evaluation follows a procedure described as **short-circuit evaluation**, if the first operand to these operators is enough to calculate the overall result, then the evaluation stops. For the case of the **logical AND** operator, the right hand operand is evaluated only if the left hand operator is `true`. For the case of the **logical OR** operator, the right hand operand is evaluated only if the right hand operator is `false`.

### 4.3.2 Equality tests and the boolean literals

When we want to evaluate the truth value of arithmetic or pointer object, the best way to do it is to use the same object as a condition:

```cpp
if (val)
  // Value is non-zero
if (!val)
  // Value is zero
```

This might seem more reasonable:

```cpp
if (val == true)
  // Value is non-zero
else if (val == false)
  // Value is zero
```

However it's not advisable to do it like that, first because it's longer code and second because when the type of `val` is not `bool` the comparison won't work as expected, this is because `bool` is promoted to `int`, and specifically `1`. So if the type of `val` is not `bool`, the comparisons above would be the same as if we had written:

```cpp
if (val == 1)
  // Value is non-zero
if (val == 0)
  // Value is zero
```

## 4.4 Assignment operators

The **assignment operators** include the **assignment operator**, `=`, and also the **arithmetic compound assignment operators**, `+=`, `-=`, `*=`, `/=` and `%=` and also the **bitwise compound assignment operators**, `<<=`, `>>=`, `&=`, `^=` and `|=`. Each compound operator is basically equivalent to `a = a op b`, the only difference is that when using the compound assignment the left-hand operand is evaluated once, and if an ordinary operand is used, it is evaluated twice.

The left-hand operand of an assignment operator must be a `lvalue` that can be modified, if the types of the left and right operands differ, then the right-hand operand is converted to the type of the left. It's important to know that an initialization is not assignment. The following are examples of these concepts:

```cpp
char i = 0; // Initialization
const char b = 0; // Initialization

4 = i; // Won't compile, left-hand operand is a rvalue.
(i + b) = 4; // Won't compile, left-hand operand is a rvalue.
b = 0; // Won't compile, left-hand operand is not a modifiable lvalue

i = 3.5; // 3.5 is converted to the type of the left operand, and then the assignment occurs.
```

It's also possible to use braced initializer lists with the assignment operator as a right-hand side operand, in case of a built-in type, a maximum of one value can be in the list, and it must not require a conversion that implies losing data in some form, when used with classes, it mostly depends on how the class implements this behaviour.

```cpp
i = {3.5}; // Won't compile because information is lost when doing the conversion.
vector<int> vi;
vi = {0, 1, 2, 3, 4}; // vi will have five elements.
```

Assignment operators are **right associative**, this means that in the following construct:

```cpp
int i, a, b, *c;
i = a = b = 0;
i = c = 0; // Won't compile.
```

First, `b = 0` is executed, then `a = b`, and finally `i = a`, thus all the variables having a value of zero in the end. In the second case, `c = 0` is valid and it returns it's left-hand operand, `c`, which is a pointer to `int`, the next expression `i = c` is therefore not valid as `c` can't be promoted to a type that can be stored in `i`, which is an `int`.

Assignments are often used within conditions, it's important to remember that **assignment operators** have low precedence and therefore we usually must use parentheses, like in the following construct:

```cpp
if ((i = get_val()) == 2)
  // Do whatever.
```

In this construct, first we store the value returned by the function `get_val` in `i`, the left-hand operand, `i`, is returned and then it is compared against `2` for equality.

## 4.5 Increment and decrement operators

The **increment operator**, `++`, and the **decrement operator**, `--`, are used to add or substract 1 from an object, both require a `lvalue` operand. Many iterators do not support arithmetic operators but support these operators, so it's not just a matter of convenience. There are two forms of these operators:

- The **prefix form**, `++i`, increments or decrements the operand and returns the changed object as a result as a `lvalue`.
- The **postfix form**, `i++`, increments or decrements the operand and returns an orignal copy of the original value as a `rvalue`.

The **prefix form** increments the value and returns the unchanged object, while the **postfix form** needs to store the original value to return it later, it is advised to use the prefix form unless the postfix form is necessary because it requires less work.

One common use of the **postfix form** is the dereference and increment a pointer in a single compound expression, like in the following example:

```cpp
*ptr++; // This translates to *(ptr++)
```

In this example, `ptr` is incremented by one and returns the original value as the result, which is then dereferenced with the dereference operator.

## 4.6 Member access operator

There are two operators to access members, one is the **dot operator**, `.`, and the other is the **arrow operator**, `->`. Both operators return members, the dot operator returns a member from an object and the arrow operator requires a pointer to the object whose member we want to access. In fact, the arrow operator is just a convenient form of the following expression: `(*ptr).member.`

The following are examples of the following:

```cpp
string s1 = "str", *s1_p = &s1;
s1.size(); // Using the dot operator to access a method.
s1_p->size(); // Using the arrow operator to access a method.
(*s1_p).size(); // Using the dot operator in conjunction with the dereference operator, equal to the arrow operator.
```

The **arrow operator** returns a `lvalue`, the **dot operator** returns a `lvalue` if the parent object is a `lvalue` and an `rvalue` if otherwise.

## 4.7 The conditional operator

The **conditional operator**, `?:`, allows to include simple conditions inside a expression. It has the following form:

```cpp
cond ? expr_if_true : expr_if_false;
```

Where `cond` represents the condition to evaluate for `true` or `false`, if `cond` is `true` then `expr_if_true` is evaluated, otherwise `expr_if_false` is evaluated. It's important to note that `expr_if_true` and `expr_if_false` must be of the same type, or a type that can be promoted so both expressions have a common type.

The result of a conditional operator is a `lvalue` if both expressions are `lvalues` or if they convert to a common `lvalue` type, otherwise the result is an `rvalue`. This type of conditionals can be nested and they are **right associative**, for example:

```cpp
(i > 10) ? "Yes" : ((i < 5) ? "No" : "Whatever");
cout << (i > 10) ? "Yes" : "No" << endl;
```

It's a good idea to use parentheses with conditional operators as they have low precedence, like in the examples above.

## 4.8 The Bitwise operators

The **bitwise operators** take integral operands and use them in term of bits, it's also possible to use the library type `bitset` however this is not explained in this section.

All the **bitwise operators** are **left associative**, and they are included in the table below, sorted in groups with the same level of precedence:

|**Operator**|**Function**|**Use**|
|:---:|:---:|:---:|
|`~`|bitwise NOT|`~expr`|
||||
|`<<`|left shift|`expr1 << expr2`|
|`>>`|right shift|`expr1 >> expr2`|
||||
|`&`|bitwise AND|`expr1 & expr2`|
||||
|`^`|bitwise XOR|`expr1 ^ expr2`|
||||
|`\|`|bitwise OR|`expr1 \| expr2`|

It's strongly advised to use bitwise operators with `unsigned` types rather than `signed` ones, because as we will see later, if the operand is negative its type is **signed** the way that the **sign bit** is handled is machine dependent.

### 4.8.1 Bitwise shift operator

The bitwise **shift operators**, `<<` and `>>`, yield a value that is a copy of the left-hand operand with its bits shifted an amount equal to the right hand operand. The right-operand can't be less than the number of bits in the result and it can't be negative, otherwise the behaviour is undefined. Bits that are shifted off the end are discarded.

The **left-shift** operator inserts 0 valued bits on the right.

```cpp
char a = 0;
a = 0x0F << 4;
```

The behaviour of the **right-shift** operator depends on the type of the left-hand operand, if it is `unsigned`, then it 0 valued bits are inserted on the left, otherwise it is implementation defined: either sign bit valued bits are added or 0 valued bits are added to the left.

```cpp
char a = 0;
a = 0xF0 >> 4;
```

### 4.8.2 Bitwise not operator

The bitwise **not operator**, `~`, generates a new value with the bits of its operand inverted, 1 valued bits are set to 0, and 0 valued bits are set to 1.

### 4.8.3 Bitwise and, or and xor operators

The **AND**, `&`, **OR**, `|`, and **XOR**, `^`, operators generate new values with the bit pattern composed from its two operands.

For the **AND** operator, the bit is 1 if both operands contain 1, otherwise it's 0.

For the **OR** operator, the bit is 1 if either or both operands contain 1, otherwise it's 0.

For the **XOR** operator, the bit is 1 if either but not both operands contain 1, otherwise the result is 0.

## 4.9 The `sizeof` operator

The `sizeof` operator returns the size in bytes of an expression or a type name. The operator is right associative and the result is a constant expression of size `size_t`. The form this operator takes is as follows:

```cpp
sizeof(type or expression)
```

The `sizeof` operator is unusual in the way that it does not evaluate the operand, this means for example that `null` pointers can be dereferenced as they are not evaluated.

The result of the `sizeof` operator depends on the following factors:

- When used with the `char` type or an expression of type `char`, it will return 1.
- When used with a reference, it will return the size of the referenced object.
- When used with a pointer, it will return the size needed to store a pointer.
- When used with dereferenced pointer, it returns the size of the object the pointer points to.
- When used with an array, returns the size of the entire array, the size of an array can be obtained by dividing the size of the array by the size of the first element. Notice that the array is not converted to pointer of the first element in this scenario.
- When used with a `string` or `vector`, it will return the size of the fixed part of these types.

The following are examples of the `sizeof` operator:

```cpp
char data;
char *p;
classType cls;

sizeof(char); // Returns the size of the char type in bytes as a 'size_t' variable.
sizeof(data); // Returns the size of the type of data in bytes as a 'size_t' variable.
sizeof(p);    // Returns the size of pointer to char.
sizeof(*p);   // Returns the size of char.
sizeof(cls.member); // Returns the size in bytes of the member.
sizeof(classType::member); // Returns the size in bytes of the member.
```

## 4.10 Comma operator

The **comma operator** takes two operands and evaluates them from left to right, therefore it guarantees the order in which its operands are evaluated.

The left-hand expression is evaluated and its result discarded, the result of the comma operator is the evaluation of the right hand expression. One common use of comma operators is a `for` loop:

```cpp
for (int i = 0, a = 1; i < a; i++, a++)
    ...
```

# Other terms and concepts

**Rules of thumb when managing compound expressions**: There are two rules of thumb which can be quite useful when dealing with compound expressions:

1. When in doubt, use parentheses to force the grouping of expressions.
2. If an operand is changed at some point in an expression, don't use that operand somewhere else in the same expression.

There is an exception to the second rule however, and that is when the expression that changes the operand is itself the operand of another sub-expression, like in the following case:

```cpp
*++iter;
```

In this case, the increment changes the value of `iter`, and the now changed value of `iter` is the operand of the dereference operator.

**Table of operators**: The following table is a list of all the operators in the C++ language, notice that the table is split in groups, operators in each group have the same precedence and also higher precedence than the operators in groups below that group.

|**Associativity**|**Operator**|**Description**|**Use**|
|:--------:|:--------:|:--------|:-------|
|L|`::`|global scope|`::name`|
|L|`::`|class scope|`class::name`|
|L|`::`|namespace scope|`namespace::name`|
|||||
|L|`.`|member selector|`object.member`|
|L|`->`|member selector|`pointer->member`|
|L|`[]`|subscript|`expr[expr]`|
|L|`()`|function call|`name(expr_list)`|
|L|`()`|type construction|`type(expr_list)`|
|||||
|R|`++`|postfix increment|`lvalue++`|
|R|`--`|postfix decrement|`lvalue--`|
|R|`typeid`|type ID|`typeid(type)`|
|R|`typeid`|run-time type ID|`typeid(expr)`|
|R|`explicit cast`|type conversion|`cast_name<type>(expr)`|
|||||
|R|`++`|prefix increment|`++lvalue`|
|R|`--`|prefix decrement|`--lvalue`|
|R|`~`|bitwise NOT|`~expr`|
|R|`!`|logical NOT|`!expr`|
|R|`-`|unary minus|`-expr`|
|R|`+`|unary plus|`+expr`|
|R|`*`|dereference|`*expr`|
|R|`&`|address-of|`&lvalue`|
|R|`()`|type conversion|`(type)expr`|
|R|`sizeof`|size of object|`sizeof(expr)`|
|R|`sizeof`|size of type|`sizeof(type)`|
|R|`sizeof...`|size of parameter pack|`sizeof(name)`|
|R|`new`|allocate object|`new type`|
|R|`new[]`|allocate array|`new type[size]`|
|R|`delete`|deallocate object|`delete expr`|
|R|`delete[]`|deallocate array|`delete[] expr`|
|R|`noexcept`|can expr throw?|`noexcept(expr)`|
|||||
|L|`->*`|ptr to member select|`pointer->*ptr_to_member`|
|L|`.*`|ptr to member select|`object.*ptr_to_member`|
|||||
|L|`*`|multiply|`expr * expr`|
|L|`/`|divide|`expr / expr`|
|L|`%`|modulo (remainder)|`expr % expr`|
|||||
|L|`+`|add|`expr + expr`|
|L|`-`|subtract|`expr - expr`|
|||||
|L|`<<`|bitwise shift left|`expr << expr`|
|L|`>>`|bitwise shift right|`expr >> expr`|
|||||
|L|`<`|less than|`expr < expr`|
|L|`<=`|less than or equal|`expr <= expr`|
|L|`>`|greater than|`expr > expr`|
|L|`>=`|greater than or equal|`expr >= expr`|
|||||
|L|`==`|equality|`expr == expr`|
|L|`!=`|inequality|`expr != expr`|
|||||
|L|`&`|bitwise AND|`expr & expr`|
|||||
|L|`^`|bitwise XOR|`expr ^ expr`|
|||||
|L|`\|`|bitwise OR|`expr \| expr`|
|||||
|L|`&&`|logical AND|`expr && expr`|
|||||
|L|`\|\|`|logical OR|`expr \|\| expr`|
|||||
|R|`?:`|conditional|`expr ? expr : expr`|
|||||
|R|`=`|assignment|`lvalue = expr`|
|R|`*=, /=, %=`|compound assignment|`lvalue += expr, etc...`|
|R|`+=, -=`|||
|R|`<<=, >>=`|||
|R|`&=, \|=, ^=`|||
|||||
|R|`throw`|throw exception|`throw expr`|
|||||
|L|`,`|comma|`expr, expr`|
