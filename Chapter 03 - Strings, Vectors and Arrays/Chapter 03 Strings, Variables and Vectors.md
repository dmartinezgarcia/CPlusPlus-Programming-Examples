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




