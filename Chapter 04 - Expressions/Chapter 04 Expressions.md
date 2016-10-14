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

With parentheses, it's possible to override the default precedence and associativity, as an example the expression below where parentheses are used to modify the default grouping in diferent ways:

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

The order of evaluation is independent of procedence and associativity, for example in the following code:

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
- The **logical OR operator**, `||`, TODO.
- The **ternary conditional operator**, `?:`, TODO.
- The **comma operator**, `,`, TODO.

#### 4.1.2.2 Operand conversions

TODO

#### 4.1.2.3 Overloaded operators

We can define the behaviour of most operators when applied to class types, when such definitions give an alternative meaning to an existing operator, we refer them as **overloaded operators**. An example of overloaded operators are the input operator `<<` and the output operator `>>` that we use with `string` or `vector`.

When using overloaded operators, the meaning of the operator, the type of the operand and the result depend on how the operator is implemented butt he number of operands and the precedence and associativity of the operator cannot be changed.

#### 4.1.2.4 Lvalues and Rvalues

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
|fds|
|Left|`<`|less than (relational)|`expr < expr`|
|Left|`<=`|less than or equal (relational)|`expr <= expr`|
|Left|`>`|greater than (relational)|`expr > expr`|
|Left|`>=`|greater than or equal (relational)|`expr >= expr`|
|||||
|Left|`==`|equality (relational)|`expr < expr`|
|Left|`!=`|inequality (relational)|`expr < expr`|
|||||
|Left|`&&`|AND (logical)|`expr && expr`|
|Left|`||`|OR (logical)|`expr || expr`|

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

```cpp
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
|`|`|bitwise OR|`expr1 | expr2|
```

It's strongly advised to use 

# Other terms and concepts

**Rules of thumb when managing compound expressions**: There are two rules of thumb which can be quite useful when dealing with compound expressions:

1. When in doubt, use parentheses to force the grouping of expressions.
2. If an operand is changed at some point in an expression, don't use that operand somewhere else in the same expression.

There is an exception to the second rule however, and that is when the expression that changes the operand is itself the operand of another subexpression, like in the following case:

```cpp
*++iter;
```

In this case, the increment changes the value of `iter`, and the now changed value of `iter` is the operand of the dereference operator.


**Table of operators**: The following table is a list of all the operators in the C++ language, notice that the table is split in groups, operators in each group have the same predecence and also higher precedence that the operators in groups below that group.

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
|L|`|`|bitwise OR|`expr | expr`|
|||||
|L|`&&`|logical AND|`expr && expr`|
|||||
|L|`||`|logical OR|`expr || expr`|
|||||
|R|`?:`|conditional|`expr ? expr : expr`|
|||||
|R|`=`|assignment|`lvalue = expr`|
|R|`*=, /=, %=`|compound assignment|`lvalue += expr, etc...`|
|R|`+=, -=`|||
|R|`<<=, >>=`|||
|R|`&=, |=, ^=`|||
|||||
|R|`throw`|throw exception|`throw expr`|
|||||
|L|`,`|comma|`expr, expr`|
