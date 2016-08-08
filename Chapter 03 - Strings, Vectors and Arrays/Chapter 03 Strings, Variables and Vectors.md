# 3. Chapter 03 - Strings, Variables and Vectors

In this chapter we introduce the following data types:

- The `string`, variable length sequences of characters, defined in the standard libraries.
- The `vector`, variable length sequences of an object of a given type, defined in the standard libraries.
- The array type, built-in type in C++ and less convenient to use than `string` or `vector`, represents a sequence of objects.

## 3.1 They keyword `using`

So far we have used the **scope operator**, `::` to use names defined in name spaces, one of example of this is the following:

```cpp
std::cin;
```

This statement indicates that we want to use the name `cin` from the namespace `std`.

There are more convenient ways of doing this, the safest approach is using an **`using` declaration**, this keyword is used as alternative form of using the names in a namespace.

A `using` declaration has the following form:

```cpp
using namespace::name;
```

Once this declaration has been made, we can use the `name` defined in `namespace` directly.

Following from our example, we would use the using keyword like this:

```cpp
#include <iostream>

using std::cin

int main (void)
{
	int i = 0;
	
	cin >> i;  // This is valid because we have a `using` declaration for this name.
	std::cin >> i; // This is also valid.
	cout << i; // This is not valid, because we don't have a using declaration for this name.
	std::cout << i; // This is a valid.
}
```

There must be a `using` declaration for each name we want to use as each declaration introduces a single namespace member, following from our previous example:

```cpp
#include <iostream>

using std::cin;
using std::cout;

int main (void)
{
	int i = 0;
	
	// Now, all of these are valid.
	cin >> i;
	std::cin >> i;
	cout << i;
	std::cout << i;
}
```

It is recommended not to include `using` declarations in header files, the reason is that every program that includes that header gets that name in the `using` declaration, and programs that did not intend to use that library might find issues with conflicting names.

## 3.2 The `string` type

A **string** is a variable length sequence of characters. This string is defined in the `string` library and because it's part of the standard library it is defined in the `std` namespace.

### 3.2.1 Defining and initializing objects of type `string`

The following table represents the most common ways of initializing strings:

|Ways to initialize a string|Description|
|:----------:|:-------------|
|`string s1`|Default initialization, `s1` is the empty string.|
|`string s2(s1)`|`s2` is a copy of `s1`.|
|`string s2 = s1`|Equivalent to `s2(s1)`, `s2` is a copy of `s1`.|
|`string s3("value")`|`s3` is a copy of the string literal, not including the `null`.|
|`string s3 = "value"`|Equivalent to `s3("value")`, `s3` is a copy of the string literal.|
|`string s4(n, 'c')`|Initialize `s4` with `n` copies of the character `'c'`.|

And the following code shows a few strings being initialized:

```cpp
string s1;
string s2 = s1;
string s3 = "hello";
string s4 = (2, 'c');
```
#### 3.2.1.1 Direct and copy initialization with strings

The following is an example of a **copy initialization**, in this case, the value of a literal string is copied into an object:

```cpp
string s1 = "Hey";
```

And, the following case is a case of **direct initialization**, equivalent to the previous one. In this case we are using one of the constructors in the `string` class to initialize the object:

```cpp
string s1("Hey");
```

There is a way to use **copy initialization** when initializing from multiple values, this is by using **direct initialization** and then the `=` as usual:

```cpp
string s1 = string(2, 'a');
```

Which is something similar to the following code:

```cpp
string temp(2, 'a');
string s1 = temp;
```

There are usually no benefits to this approach over using either copy initialization or direct initialization, but it is mentioned for the purpose that both can be used together.

### 3.2.2 Operations with objects of type `string`

The following table depicts some of the most common string operations:

|Functions|Description|
|:---:|:------|
|`os << s`|Writes `s` onto output stream `os`, returns `os`.|
|`is >> s`|Reads a whitespace-separated string from `is` into `s`, returns `is`.|
|`getline(is, s)`|Reads a line of input from `is` into `s`, returns `is`.|
|`s.empty()`|Returns `true` if `s` is empty, otherwise returns `false`.|
|`s.size()`|Returns the number of characters in `s`.|
|`s[n]`|Returns a reference to the `char` at position `n` in `s`, positions start at 0.|
|`s1 + s2`|Returns a string that is the concatenation of `s1` and `s2`.|
|`s1 = s2`|Replaces characters in `s1` with a copy of `s2`.|
|`s1 == s2`|The strings `s1` and `s2` are equal if they contain the same characters, equality is case-sensitive.|
|`!=, <, <=, >, >=`|Comparisons are case-sensitive and use dictionary ordering.|

These are, as expected, in the `string` class.

#### 3.2.2.1 Reading and writing strings

We use the same Input/Output operators to read from and write to strings as with the built-in types, for example the following code reads data from the input stream and stores it in an object of type `string` using its **input operator**, `>>`:

```cpp
int main(void)
{
	string s;
	cin >> s;
	
	return 0;
}
```

Similarly to built-in types, we use the **output operator**, `<<`, to write data to an string object. We can also chain multiple output operators together.

The way the input operator of the `string` class behaves is the following: first it removes any leading whitespaces, spaces, newlines, tabs... then it reads characters until the next whitespace character is encountered. As with built-in types, it is possible to chain together multiple input operators, as the result of input operand is it's left hand side expression.

The following code is an example of all the things mentioned so far:

```cpp
int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2 << endl;
}
```

Let's assume that the input for this program is `"Hey You"`, then the output will be `"HeyYou\n"`, because of the behaviour of the input operator.

Sometimes we want to read an entire line, including the white spaces, for this purpose we use the `getline` function, which takes an input stream and a string object as an input. It reads data from the input stream until a new line character has been found `\n` and stores that data in the string provided as an argument, not including the new line character. The `getline` function returns the input stream.

This is an example of how to use the `getline` function:

```cpp
int main()
{
	string line;
	while (getline(cin, line)) // Read until end of file or invalid output.
	{
		cout << line << endl;
	}
	
	return 0;
}
```

#### 3.2.2.2 Comparing strings

The `string` class defines several operators to compare strings, they compare the characters of the strings and they are case case-sensitive.

The following are **compare operators**:

1. The equal `==` operator and unequal `!=` operator.
2. The less than `<` operator and the less than or equal `<=` operator.
3. The greater than `>` operator and the greater than or equal `>=` operator.

The way comparisons are performed is by following this set of rules:

1. If two strings have the same length and the same characters, they are equal.
2. If two strings have different lengths and if every character in the shorter string is equal to the corresponding character of the longer string, then the shorter string is less than the longer one.
3. If any characters at corresponding positions in the two strings are different, then the result of the string comparison is the result of comparing the first character at which those strings differ.

#### 3.2.2.3 Assignment and concatenation of strings

By using the **assignment operator**, `=`, we can assign a `string` object to another `string` object, this is an example of the former:

```cpp
string s1 = "Hello", s2;
s2 = s1; // Assignment operator in action, now s2 is a copy of s1.
```

In order to concatenate strings we use the **addition operator**, `+`, with two or more strings. The result is an object of type `string` containing the characters from the left-hand side string followed by the characters from the right-hand side string. Keep in mind using the assignment operator in conjunction with the addition operator like this `+=`, is also possible.

The following is an example of concatenating two objects of type string:

```cpp
string s1 = "Hello", s2 = "You", s3;
s3 = s1 + s2; // Concatenation of strings, s3 will be HelloYou.
s3 += s2; // Equal to s3 = s3 + s2, s3 will be HelloYouYou.
```

It is important to note that **string literals** are not of type `std::string`, we can use string literals in assignments, initializations and concatenations of `string` objects because the `string` class can convert character literals and character string literals to `string` objects.

The restriction mentioned above means that we can't concatenate two string literals, at least one of the operands must be of type `string` and the other operand will be converted to `string` if necessary. Therefore, we can create the following program:

```cpp
string s1, s2 = "hi";

s1 = "hi" + "you"; // This won't work.
s1 = s2 + s1; // This will work
s1 = "hi" + "you" + s2; // This won't work.
s1 = "hi" + ("you" + s2); // This will work because the addition operator result is an object of type string.
```

#### 3.2.2.4 Other operations on strings

We can use the `empty` member function to determine if an object of type `string` is the empty string, the `empty` function returns a value of type `bool`. Because it is a member function of the `string` class, we use the dot operator to specify on which object we want to run the function, like in the following example:

```cpp
string line;
if (line.empty())
{
	// String is empty
}
```

To obtain the length of a `string` we use the member function `size`, this function returns the number of characters in the `string`. 

Size return an object of type `string::size_type` with the amount of characters, the reason for this is that this is one of those library types that allows the library to be more machine-independent. Any object used to store the size of a string should be of this type, for this purpose, it is useful to use the `auto` or `decltype` keywords.

The following is an example:

```cpp
string line;
auto a = line.size(); // a will be of type string::size_type.
```

### 3.2.3 Operations with the characters in the strings

There are two parts of processing the characters in a `string`:

1. The first part is how to access these characters, sometimes we need to process every character, sometimes we need to process just a few in the middle of the string, sometimes we need to access just the last two characters and sometimes we have to process every character until a condition is met.
2. The second part is how to change or modify these characters, for this purpose we can use the `cctype` header, a C++ version of the C `ctype.h` header. The main functions are the following:

|Function|Description|
|:--------:|:-----------|
|`isalnum(c)`|`true` if `c` is a letter or a digit.|
|`isalpha(c)`|`true` if `c` is a letter.|
|`iscntrl(c)`|`true` if `c` is a control character.|
|`isdigit(c)`|`true` if `c` is a digit.|
|`isgraph(c)`|`true` if `c` is not a space but is printable.|
|`islower(c)`|`true` if `c` is a lowercase letter.|
|`isprint(c)`|`true` if `c` is a printable character.|
|`ispunct(c)`|`true` if `c` is a punctuation character.|
|`isspace(c)`|`true` if `c` is whitespace.|
|`isupper(c)`|`true` if `c` is an uppercase letter.|
|`isxdigit(c)`|`true` if `c` is a hexadecimal digit.|
|`tolower(c)`|If `c` is an uppercase letter, returns its lowercase equivalent, otherwise returns `c` unchanged.|
|`toupper(c)`|If `c` is a lowercase letter, returns its uppercase equivalent; otherwise returns `c` unchanged.|

#### 3.2.3.1 The range `for` loop to process every character

The best approach to process *every* character in a `string` is, by far, using a **range `for`** loop. The syntax for this kind of loop is the following:

```cpp
for (declaration : expression)
	statements
```

Where `expression` is an object that represents a sequence, for example, a `string` is a sequence of characters. The term `declaration` is the declaration of the variable that will be used to iterate through the sequence and must be of the same type as the objects in the sequence.

The following is an example of a **range `for`** loop:

```cpp
string s1 = "Hello";

// This loop will print "Hello".
for (auto c : s1)
{
	cout << c << endl;
}
```

Notice that `c` will be of type `char`, because that is the type of the objects in the `string` sequence. We can read this kind of loop as "For every `char` `c` in the `string` `s1` do the statements in the `for` loop".

If we want to modify the objects in the sequence, in this case, the characters in the string, our iterating variable must be a reference, like this:

```cpp
string s1 = "Hello";

// This loop will make each of the characters change by one.
for (auto &c : s1)
{
	c +=1;
}
```

#### 3.2.3.2 Subscripts or indexes to process specific characters

There are two ways to access individual characters in a `string`, **subscripts** and **iterators**. In this section, we will define the use of subscripts, also known as indexes.

The **subscript operator**, `[]`, takes a subscript that denotes the position of the string we want to access, this operator returns a reference to the character at the given position. The possible values for subscripts must be greater or equal to zero and lesser than the length of the `string`. If the subscript is not within this range, the behaviour of the subscript operator is undefined.

The subscript can be any expression that generates an integral value, signed types are converted to unsigned types.

These are examples of using subscripts:

```cpp
string s1 = "Hey";

s1[0]; // This will be "H"
s1[1] = 'a'; // Changing 'e' for 'a'.
```

We can use a normal `for` loop and subscripts to iterate through the values of the string, like in this example:

```cpp
string s2 = "Hey";

for (decltype(s2.size()) i = 0; i < s2.size(); i++)
{
    s2[i] = '\0';
}
```

It's important to notice that there is no need to access the values in sequence using subscripts, random access it's also possible, as long as the subscript has a valid value.

## 3.3 Vector type

A **`vector`** is a sequence of objects of the same type, every object in this sequence has an index, which provides access to that object in the sequence.

To use vectors we must include the appropiate header, in this case, the `vector` header file. It is also useful to declare the vector using a `using` declaration to avoid writing the scope operator and the namespace `std` all the time.

```cpp
#include <vector>
using std::vector;
```

It is important to note that a vector is a *class template*, for more information regarding this concept, please refer to *Other concepts and notes* section of this chapter.

Because it is a template, we must supply the information needed between angle brackets, in the case of a `vector`, the information provided must be the type of the objects the `vector` will hold:

```cpp
vector<int> int_vec; // Vectors whose elements are integers.
vector<string> string_vectors; // Vectors whose elements are strings.
vector<vector<string>> file; // Vectors whose elements are vectors whose elements are strings.
```

Vectors can contain most of the built-in types and most of the class types, provided these types are associated with objects, it is important to know that because references are not objects, it is not possible to have references of vectors.

### 3.3.1 Defining and Initializing `vector`

The `vector` template controls how we define and initialize objects of type `vector`, in the following section some of the most common form of initializations for vectors are discussed.

Although an empty `vector` might seem not very useful at first, it is very commonly used and that is because usually values are added to vectors as they become known during run time.

```cpp
vector<string> v1; // This is an empty vector.
```

Another way to initialize a vector is by copying the elements from another vector, for this to work, both vectors must be on the same type. We can use direct or copy initialization, the result is the same:

```cpp
vector<string> v1;

vector<string> v2 = v1; // Copy initialization, elements of v1 are copied onto v2.
vector<string> v3(v1); // Direct initialization, elements of v3 are copied onto v1.
```

We can also use **list initialization** to initialize a vector, this can be done in two different ways:

```cpp
vector<string> v1 = {"1", "2", "3"};
vector<string> v2{"1", "2", "3"};
```

It is also possible to initialize a vector from a specified number of elements. For this, two parameters are given, `init_value`, which specifies the value that will be contained in the vector, and then `count`, which is the number of copies of `init_value` that the vector will have.

```cpp
vector<int> ivec(count, init_value);
```

For example, the following vector will contain ten elements, each initialized to `25`:

```cpp
vector<int> ivec(10, 25);
```

It it also possible to omit the `init_value` member in the initialization, this way we will define a vector with `count` number of elements, all of them default initialized:

```cpp
vector<int> ivec(10); // Ten elements, each of them default initialized (in the case of int, 0).
vector<string> svec(10); // Ten elements, each of them default initialized (in the case of string, the empty string).
```

If the class used to construct the vector is requires an explicit initializer or it cannot be default initialized, this form of creating a vector will not be possible with that class. It's important to note that when not supplying an initialized, the direct form of initialization must be used.

#### 3.3.1.1 The use of curly braces and parentheses for initialization

When we use **parentheses** for initialization, we are saying that the values supplied should be used to build the object.

```cpp
vector<int> v1(25); // 25 values default initialized to 0.
vector<int> v2(10, 25); // 10 values initialized to 25.
vector<string> v3("hello"); // ERROR: Can't build vector from literal string.
```

When we use **curly braces**, we are saying, that if possible, the values supplied should be used to list-initialize the object. If list-initialization is not possible then the compiler will look into alternative ways of initializing the object from the given values.

```cpp
vector<int> v1{10}; // 1 element with value 10.
vector<int> v2{10, 1}; // 2 elements with value 10 and 1.
vector<string> v3{"hello"}; // 1 element with value "hello".
vector<string> v4{10, "hello"}; // String can't be initialized from int, so the compiler looks into alternative ways to initialize this, the result will be 10 elements initialized to "hello", similar to v4(10, "hello");
```

### 3.3.2 Operations with vectors

Most of the operations on `vector` objects are similar to those in the `string` class, these are some of the most important ones:

|Operation|Description|
|:-----|:--------|
|`v.empty()`|Returns `true` if `v` is empty, otherwise returns `false`.|
|`v.size()`|Returns the number of elements in `v`.|
|`v.push_back(a)`|Adds an element with value `a` to end of `v`.|
|`v[n]`|Returns a reference to the element at position `n` in `v`.|
|`v1 = v2`|Replaces the elements in `v1` wth a copy of the elements in `v2`.|
|`v1 = {a, b, c...}`|Replaces the elements in `v1` with a copy of the elements in the comma-separated list.
|`v1 == v2`, `v1 != v2`, `<, <=, >, >=`|`v1` and `v2` are equal if they have the same number of elements and each element in `v1` is equal to the corresponding element in `v2`.|

#### 3.3.2.1 Adding elements to a vector

The vector member called `push_back` allows us to add new elements at run time to a vector, it takes a value as an argument it makes it the new last element of the vector.

```cpp
vector<int> v2;
int i;

for (i = 0; i < 100; i++)
{
  v2.push_back(i);
}
// When the loop ends, v2 will have values 0, 1, 2, 3, 4... 99
```

It's important to remember that **vectors grow efficiently**, starting with an empty vector and adding elements at runtime is usually more efficient than creating a vector of it's expected size and then modifying the elements, this is not usually the case in different languages like C or Java.

#### 3.3.2.2 Accessing vector elements

Elements in a vector are accessed the same way they are accessed in a string, through **subscripts** and **iterators**.

The following code is an example of accessing vector elements using indexes:

```cpp
vector<int> v{1, 2, 3, 4, 5, 6, 7};
for (auto &i : v)
{
  i = i + 1;
}
```

The type of a subscript is the corresponding `size_type` type for that vector, and using an index of zero will fetch the first element of the vector. It's important to remember not to access elements that do not exist (**buffer-overflow**) as the compiler in most cases won't be able to detect this and the value we get at run time is undefined.

#### 3.3.2.3 Obtaining the number of elements in a vector

To obtain the number of elements in a `vector` object the `size` method is used. This method returns an object of type `size_type` defined by the corresponding vector type.

A vector always includes such kind of type, and we can access it as follows:

```cpp
vector<int>::size_type;
vector<string>::size_type;
```
#### 3.3.2.3 Equality and relational operators

Two vectors are equal if they have the same number of elements and if the corresponding elements all have the same value.

If the vectors have different sizes, but the elements that are in common are equal, then the vector with fewer elements is less than the one with more elements.

If the elements have differing values, then the relationship between the vector is determined by the relationship between the first elements that differ.

Two vectors can be compared only if the elements in those vectors can be compared, those whose operations include the equality and relational operators.

## 3.4 Iterators

There is a more general mechanism of accessing members of container, such as a `vector`, and this mechanism is the use of **iterators**. 

Iterators give us **indirect access** to an object, just like pointers, they have operations to move from one element to another and as with pointers, an iterator may be valid or invalid:

- A valid iterator denotes an element or a position one past the last element in a container.
- All other iterators are invalid.

### 3.4.1 Fetching iterators to the first and last elements

Types that have iterators have methods that return iterators, for example the **`begin`** method and the **`end`** method.

The `begin` method returns an iterator to the first element of the vector. 

The `end` method returns an iterator positioned one past the last element, which is a non existent element usually used as a marker indicating that we have processed all the elements of the container, this element is usually known as the **off-the-end iterator** or **the end iterator**.

```cpp
vector<int> v{1, 2, 3, 4};
auto iter1 = v.begin();
auto iter2 = v.end();
```

If the container is empty, the iterator returned by both `begin` and `end` is the off-the-end operator. In general we don't care about the type an iterator has, reason why it's usually used in combination with `auto` or `decltype`.

The type returned by `begin()` and `end()` depends on whether the object is `const` or not, if the object is `const` then these functions will return a `const_iterator` iterator, and if it's not `const` it will return an `iterator` iterator. 

```cpp
vector<int> v1;
const vector<int> v2;
auto v1_it = v.begin(); // Will return iterator.
auto v2_it = v.begin(); // Will return const_iterator.
```

If we want to explicitly request a `const_iterator` we can use the `cbegin` and `cend` functions, these functions work the same way as `begin` and `end` but they return a `const_iterator` instead.

```cpp
vector<int> v1;
auto v1_it = v.cbegin(); // Will return constant iterator.
```

### 3.4.2 Iterator types

The types that have iterators usually define two types of iterator:

- The `iterator` type, which can be used to read and write and can be accessed in the following way:

```cpp
vector<int>::iterator it; // it can read and write integers in the vector.
string::iterator it2; // it2 can read and write characters in the string.

```

- The `const_iterator` type, behaves like a `const` pointer, it can be used to read but it can't be used write.

```cpp
vector<int>::const_iterator it3; // It can read integers in the vector.
string::const_iterator it4; // It can read characters in the string.
```

It's obvious that with a `const` object we can only use the `const_iterator` iterator type.

### 3.4.3 Operations on iterators

Iterators support only a few operations, described in the following table:

|Operation|Description|
|:-------|:---------|
|`*iter`|Returns a reference to the element denoted by the iterator `iter`.|
|`iter->mem`|Dereferences `iter` and fetches the member named `mem` from the underlying element. This is equivalent to `(*iter).mem`.|
|`++iter`, `iter++`|Increments `iter` to refer to the next element in the container.|
|`--iter`, `iter--`|Decrements `iter` to refer to the previous element in the container.|
|`iter1 == iter2`|Compares two iterators for equality.|
|`iter1 != iter2`|Compares two iterators for inequality.|

#### 3.4.3.1 Dereferencing an iterator

We can only dereference iterators that denote an element, dereferencing off-the-end iterators or invalid iterators has undefined behaviour.

```cpp
string s = "Hello";
auto iter = s.begin();
*iter = *iter + 1; // The string will now be "Iello".
```

Similar to pointers, we can combine dereference operator with member access like this:

```cpp
vector<string> s;
s->empty();
```

Which is the equivalent to this:

```cpp
vector<string> s;
(*s).empty();
```

However, using the member access operator, `->`, is more convenient.

In this case, we are dereferencing the iterator to access the object and then accessing the method `empty` of the `string` class to check whether the `string` `s` is empty or not.

#### 3.4.3.2 Going forwards and backwards with an iterator

We can advance or retreat from one element to another using the increment and decrement operators. An example of this is the following code:

```cpp
string s = "Hello";
decltype(s.begin()) iter;
for (iter = s.begin(); iter != s.end(); iter++)
{
  *it = '0';
}
```

Notice that we use the inequality operator `!=` to check when we reach the end of the container, this is because is more common for classes to have this operator implemented than the `<` operator.

#### 3.4.3.3 Inequality and equality of iterators

Two operators are equal if they denote the same element or if they both are the off-the-end iterator of the same container, otherwise they are not equal.

### 3.4.4 Iterators can be invalidated

It's important to know that loops that use iterators should not add elements to the container to which the iterators where retrieved from, because these will become invalidated.

An example of this is using the `push_back` with `vector` objects inside a loop that uses iterators.

### 3.4.5 Iterator arithmetic

There are other operations on iterators that are supported by some containers, such as `vector` or `string`. This support for operations that allow us to iterate multiple elements at a time and support for all the relational operators is known as **iterator arithmetic**.

|Operation|Description|
|:------|:-------|
|`iter + n`|Adding an integral value `n` to an iterator creates an iterator that many elements forward within the container.
|`iter - n`|Subtracting an integral value `n` from an iterator creates an iterator that many backwards within the container.
|`iter += n`|Compound-assignment for iterator addition.|
|`iter -= n`|Compound-assignment for iteration subtraction.|
|`iter1 - iter2`|Subtracting two operators returns the distance between both operators. Valid iterators must be used and both must refer to the same container.|
|`>, >=, <, <=`|Relational operators on iterators. Valid iterators must be used and both must refer to the same container.|

#### 3.4.5.1 Relational operators

One iterator is less than the other if it refers to an element that appears in the container before the one referred to by the other iterator, otherwise the iterator is greater.

#### 3.4.5.2 Type returned when subtracting operators

The result type when subtracting two operators is a *signed integral* type called `difference_type`, the result value is the amount of which we need to change the right iterator to get the left iterator. It is signed, because subtraction might have a negative result. 

## 3.5 Arrays

An **array** is a compound type and they are basically a container of objects of a single type, which we can access by position. Arrays have fixed size so it's not possible to add elements to an array, because of this fixed size some times they offer better run-time performance at the cost of lost of flexibility.

### 3.5.1 Defining and initializing built-in arrays

To initialize an array two parameters must be provided the name, `a`, and a dimension `d`. The array declarator has the followint form

```cpp
a[d];
```

The number of element's in the array is part of the arrays type and therefore it must be known at compile time, which means that `d` it must be a constant expression. The following are examples:

```cpp
unsigned int not_c = 30;
constexpr unsigned int c = 30;

int arr[10]; // Valid, array of ten ints and a dimension is provided.
int *parr[c]; // Array of `c` pointers to int, and valid because c is a constant expression.
string bad[not_c]; // ERROR: not_c is not a constant expression.
string strs[get_size()]; // If get_size is a constant expression it will be succesful, and it will be an error otherwise.
```

By default arrays are default initialized and just like built-in types, when an array of built-in type is defined inside a function it will have undefined values. Arrays contain objects, so it's not possible to have an array of references. It's not possible to use the `auto` keyword with an array.

It's possible to omit the dimension if an initializer is provided, the compiler will determine the dimension from the initializer. It's also possible to provide a dimension and a initializer but the initializer must not be greater in length than the dimension. If the initializer has less elements than the value of the dimension, the elements not explicitly initialized will be default initialized.

The following are examples of this kind of initialization.

```cpp
int a1[3] = {1, 2, 3}; // Array of three ints, 1, 2, 3.
int a2[] = {1, 2, 3}; // Array of three ints, the compiler determines the dimension from the initializer, 1, 2, 3.
int a3[5] = {1, 2, 3}; // Array of five ints, the last two are default initialized to zero.
int a4[2] = {1, 2, 3}; // ERROR: Too many initializers.
```

#### 3.5.1.1 Character arrays

Character arrays need some special mention. It's possible to initialize character arrays from a string literal but it's also important to remember that string literals end with a `NULL` character, and this `NULL` character is copied into the array along with all the characters in the literal.

```cpp
char a1[] = {'C', '+', '+'}; // List initialization, no null.
char a2[] = {'C', '+', '+', '\0'}; // List initialization, explicit null.
char a3[] = "C++"; // Length 4, 3 characters and the null terminator
char a4[3] = "C++"; // ERROR: No space for the null terminator.
```

#### 3.5.1.2 No copy initialization is allowed with arrays or assignment

It's not possible to do copy initialization with arrays, like this:

```cpp
int a[] = {1, 2};
int a2[] = a; // ERROR
```

And it's also not possible to assign one array to another, like this:

```cpp
int a[] = {1, 2};
int a1[] = {2, 1};
a = a1; // ERROR
```

#### 3.5.1.3 Pointer and references to arrays

Because an array is an object, we can have pointers and references to arrays, defining pointer or references to arrays can be complicated, for this we use parentheses like this:

```cpp
int *ptrs[10]; // Array of ten pointers.
int &refs[10]; // ERROR: Not possible to have arrays of references.
int (*arrPtr)[10] = &arr; // Pointer to array of ten ints.
int (&arrRef)[10] = arr; // Reference to array of ten ints.
int *(&arrPtrRef)[10] = ptrs; // Reference to array of ten pointers to int.
```

As you might have figured out, it's easier to understand these declarations by reading from the inside out rather than from right to left, which is the way type modifiers bind.

### 3.5.2 Accessing the elements of an array

We can use a **range for** or **subscripts** to access elements in an array, as usual, the indices is zero based, the first element is at index zero.

The following is an example of accessing all the elements in an array using a **range for**:

```cpp
unsigned int scores[] = {0, 1, 2, 3, 4, 5};
for (auto &i : scores)
  cout << i << " ";
cout << endl;
```

When using a variable as an index in an array, it's recommended to define this variable with the type `size_t`, which is a specific unsigned type that is guaranteed to be large enough to hold the size of any object in memory. The `size_t` type is defined in the `cstddef` header, which is the C++ version of the `stddef.h` header from the C library.

The following is an example of using subscripts and the type `size_t`:

```cpp
unsigned int scores[] = {0, 0, 0, 0, 0};
size_t idx = 0;

for (idx = 0; idx < 4; idx++)
{
  scores[idx] = idx;
}
```

As is the case with other kind of containers, it's up to the programmer to ensure that valid values are being accessed, those that are in range, that is, that the index value is equal to or greater than zero and less than the size of the array.

# Other terms and concepts

**Direct initialization form**: A direct initialization omits the `=` character in the declaration, we use direct initialization when we initialize a variable from more than one value. See 3.2.1.1 for more information.

**Copy initialization form**: A copy initialization uses the `=` character in the declaration, we are asking the compiler to copy the initializer, the expression on the right hand side of the declaration, into the object being created. A copy initializer is possible only when we have only one single initializer.

**String literals**: For compatibility with C, it is important to know that string literals are not of type `std::string`, it is important to remember this when using string literals and objects of type `std::string`.

The following is a string literal: `"Hello, I am a string literal."`.

**C++ versions of the C libraries headers**: Headers in the C language are named like this: `name.h`, a few examples of C library headers are the following: `string.h`, `stdio.h`, `stdlib.h`, `stdint.h`.

The C++ versions of these headers remove the `.h` suffix and precede the name with the character `'c'`, the `'c'` indicates that the header is part of the C library. For example the C++ versions of the headers we mentioned above are the following: `cstring`, `cstdio`, `cstdlib`, `cstdint`.

The names defined in the C++ headers are defined in the `std` namespace, whereas those defined in the `.h` versions are not, so the use of the C++ headers is recommended when there is a need to use functionality defined in the C libraries.

**Class template**: Templates are instructions given to the compiler to generate classes and functions, the process that the compiler uses to create classes or functions from templates is called *instantiation*.

In the specific case of a class template, we must specify the class to instantiate and another data that depends on the template we are working with. How we specify the information is always the same, we supply it inside a pair of angle brackets following the template's name. For example, to define a `vector` we would do the following:

```cpp
vector<int> ivec;
```

It is not required to know how to create templates to use them, creating templates is something complex.

**Using vectors or arrays**: In general, if you don't know how many elements you will need, it's better to use a `vector`.
