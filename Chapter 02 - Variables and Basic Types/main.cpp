// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 37;

// Add function prototypes as you add them.
void ExerciseNum1 (void); void ExerciseNum2 (void); void ExerciseNum3 (void); void ExerciseNum4 (void);
void ExerciseNum5 (void); void ExerciseNum6 (void); void ExerciseNum7 (void); void ExerciseNum8 (void);
void ExerciseNum9 (void); void ExerciseNum10 (void); void ExerciseNum11 (void); void ExerciseNum12 (void);
void ExerciseNum13 (void); void ExerciseNum14 (void); void ExerciseNum15 (void); void ExerciseNum16 (void);
void ExerciseNum17 (void); void ExerciseNum18 (void); void ExerciseNum19 (void); void ExerciseNum20 (void);
void ExerciseNum21 (void); void ExerciseNum22 (void); void ExerciseNum23 (void); void ExerciseNum24 (void);
void ExerciseNum25 (void); void ExerciseNum26 (void); void ExerciseNum27 (void); void ExerciseNum28 (void);
void ExerciseNum29 (void); void ExerciseNum30 (void); void ExerciseNum31 (void); void ExerciseNum32 (void);
void ExerciseNum33 (void); void ExerciseNum34 (void); void ExerciseNum35 (void); void ExerciseNum36 (void);
void ExerciseNum37 (void); void ExerciseNum38 (void); void ExerciseNum39 (void); void ExerciseNum40 (void);
void ExerciseNum41 (void); void ExerciseNum42 (void);

typedef void (*Exercise) (void);
// Fill the array as you add exercises.
Exercise Exercises[] =
{
    ExerciseNum1, ExerciseNum2, ExerciseNum3, ExerciseNum4, ExerciseNum5,
    ExerciseNum6, ExerciseNum7, ExerciseNum8, ExerciseNum9, ExerciseNum10,
    ExerciseNum11, ExerciseNum12, ExerciseNum13, ExerciseNum14, ExerciseNum15,
    ExerciseNum16, ExerciseNum17, ExerciseNum18, ExerciseNum19, ExerciseNum20,
    ExerciseNum21, ExerciseNum22, ExerciseNum23, ExerciseNum24, ExerciseNum25,
    ExerciseNum26, ExerciseNum27, ExerciseNum28, ExerciseNum29, ExerciseNum30,
    ExerciseNum31, ExerciseNum32, ExerciseNum33, ExerciseNum34, ExerciseNum35,
    ExerciseNum36, ExerciseNum37, ExerciseNum38, ExerciseNum39, ExerciseNum40,
    ExerciseNum41, ExerciseNum42
};

#include <iostream>

#include <stdio.h>

/********************************************//**
 *  Exercise 2.1
 *
 *  What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?
 ***********************************************/
void ExerciseNum1 (void)
{
    /*
    The differences between short, int, long and long long is the amount of bits each of these arithmetic types occupy in memory, and the advantages and disadvantages derived from it.
    An unsigned type can't represent negative values, a signed type can.
    A float represents a floating arithmetic type number with less significant digits than a double.

    These are only some differences.
    */
}

/********************************************//**
 *  Exercise 2.2
 *
 *  To calculate a mortgage payment, what types would you use for the rate, principal and payment? Explain why you selected each type.
 ***********************************************/
void ExerciseNum2 (void)
{
    /* TODO: Have a mortgage, then come back an finish this exercise. */
}

/********************************************//**
 *  Exercise 2.3
 *
 *  What output will the following code produce?
 *
 *  unsigned u = 10, u2 = 42;
 *  std::cout << u2 - u << std::endl;
 *  std::cout << u - u2 << std::endl;
 *
 *  int i = 10, i2 = 42;
 *  std::cout << i2 - i << std::endl;
 *  std::cout << i - i2 << std::endl;
 *
 *  std::cout << i - u << std::endl;
 *  std::cout << u - i << std::endl;
 ***********************************************/
void ExerciseNum3 (void)
{
    /*
    For simplicity, we will assume that the integer is 32 bits long.

    32
    4294967264
    32
    -32
    0
    0
    */
}

/********************************************//**
 *  Exercise 2.4
 *
 *  What output will the following code produce?
 *
 *  unsigned u = 10, u2 = 42;
 *  std::cout << u2 - u << std::endl;
 *  std::cout << u - u2 << std::endl;
 *
 *  int i = 10, i2 = 42;
 *  std::cout << i2 - i << std::endl;
 *  std::cout << i - i2 << std::endl;
 *
 *  std::cout << i - u << std::endl;
 *  std::cout << u - i << std::endl;
 ***********************************************/
void ExerciseNum4 (void)
{
    unsigned u = 10, u2 = 42;
    int i = 10, i2 = 42;

    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
}

/********************************************//**
 *  Exercise 2.5
 *
 *  Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
 *
 *  (a) 'a', L'a', "a", L"a"
 *  (b) 10, 10u, 10L, 10uL, 012, 0xC
 *  (c) 3.14, 3.14f, 3.14L
 *  (d) 10, 10u, 10., 10e-2
 ***********************************************/
void ExerciseNum5 (void)
{
    /*
    'a' - char (signed or unsigned depends on the compiler)
    L'a' - wchar_t (signed or unsigned depends on the compiler)
    "a" - char[] (signed or unsigned depends on the compiler)
    L"a" - wchar_t[] (signed or unsigned depends on the compiler)

    10 - signed int
    10u - unsigned int
    10L - signed long
    10uL - unsigned long
    012 - signed int (in octal notation)
    0xC - signed int (in hex notation)

    3.14 - double
    3.14f - float
    3.14L - long double

    10 - signed int
    10 - unsigned int
    10. - double
    10e-2 - double
    */
}

/********************************************//**
 *  Exercise 2.6
 *
 *  What, if any, are the differences between the following definitions:
 *
 *      int month = 9, day = 7;
 *      int month = 09, day = 07;
 ***********************************************/
void ExerciseNum6 (void)
{
    /*
    The first definitions initializes month to 9 and day to 7.
    The second statement will fail because 09 is not a valid octal value.
    */
}

/********************************************//**
 *  Exercise 2.7
 *
 *  What values do these literals represent? What type does each have?
 *
 *      "Who goes with F\145rgus?\012"
 *      3.14e1L
 *      1024f
 *      3.14L
 ***********************************************/
void ExerciseNum7 (void)
{
    /*
    "Who goes with Fergus?\n" - char[]
    3.14e1L - Long double
    1024f - Float
    3.14L - Long double
    */
}

/********************************************//**
 *  Exercise 2.8
 *
 *  Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.
 *
 ***********************************************/
void ExerciseNum8 (void)
{
    std::cout << "\x32\x4D\n" << std::endl;
    std::cout << "\x32\t\x4D\n" << std::endl;
}

/********************************************//**
 *  Exercise 2.9
 *
 *  Explain the following definitions. For those that are illegal, explain what's wrong and how to correct it.
 *
 *    std::cin >> int input_value;
 *    int i = { 3.14 };
 *    double salary = wage = 9999.99;
 *    int i = 3.14;
 ***********************************************/
void ExerciseNum9 (void)
{
    /* First definition. */
    /* Needs to be fixed like this. */
    int input_value;
    std::cin >> input_value;

    /* Second definition. */
    /* List initialization, will not work because we lose data, gives a warning or error depending on the compiler configuration. */
    int i = {3.14};

    /* Third definition. */
    /* Will work if wage is defined before. */
    double wage;
    double salary = wage = 9999.99;

    /* Fourth definition. */
    /* Direct initialization, will work no matter what. */
    int i_0 = 3.14;
}

/********************************************//**
 *  Exercise 2.10
 *
 *  What are the initial values, if any, of each of the following variables?
 *
 *    std::string global_str;
 *    int global_int;
 *    int main()
 *    {
 *      int local_int;
 *      std::string local_str;
 *    }
 ***********************************************/
void ExerciseNum10 (void)
{
    /*
    global_str: Class defined.
    global_int: Zero.
    local_int: Garbage.
    local_str: Class defined.
    */
}

/********************************************//**
 *  Exercise 2.11
 *
 *  Explain whether each of the following is a declaration or a definition:
 *
 *      extern int ix = 1024;
 *      int iy;
 *      extern int iz;
 ***********************************************/
void ExerciseNum11 (void)
{
    /*
    Definition - Initialization overrides the extern.
    Definition - To zero or garbage value.
    Declaration - Because of the extern keyword.
    */
}

/********************************************//**
 *  Exercise 2.12
 *
 *  Which, if any, of the following names are invalid?
 *
 *      int double = 3.14;
 *      int _;
 *      int catch-22;
 *      int 1_or_2 = 1;
 *      double Double = 3.14;
 ***********************************************/
void ExerciseNum12 (void)
{
    /*
    Invalid - Reserved keyword for variable identifier.
    Valid
    Invalid - Dash is not a valid character.
    Invalid - Can't start with a number.
    Valid
    */
}

/********************************************//**
 *  Exercise 2.13
 *
 *  What is the value of j in the following program?
 *
 *      int i = 42;
 *      int main()
 *      {
 *          int i = 100;
 *          int j = i;
 *      }
 ***********************************************/
int i_ej13 = 42;
void ExerciseNum13 (void)
{
    /*
    The value of j is 100, because the global variable is shadowed by the local variable with the same name.
    */
    int i_ej13 = 100;
    int j = i_ej13;

    std::cout << j << std::endl;
}

/********************************************//**
 *  Exercise 2.14
 *
 *  Is the following program legal? If so, what values are printed?
 *
 *      int i = 100, sum = 0;
 *      for (int i = 0; i != 10; ++i)
 *          sum += i;
 *      std::cout << i << " " << sum << std::endl;
 ***********************************************/
void ExerciseNum14 (void)
{
    /*
    The values printed will be the following:
        i = 100
        sum = 45
    Because i in the for loop shadows the i in the outer scope.
    */
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
}

/********************************************//**
 *  Exercise 2.15
 *
 *  Which of the following definitions, if any, are invalid? Why?
 *
 *      int ival = 1.01;
 *      int &rval1 = 1.01;
 *      int &rval2 = ival;
 *      int &rval3;
 ***********************************************/
void ExerciseNum15 (void)
{
    /*
    Correct, although there is lose of information (.01).
    Not a valid reference, because it would be bounded to a constant value.
    A valid reference.
    Not a valid reference, because it is not initialized.
    */
    int ival = 1.01;
    int &rval2 = ival;

    std::cout << ival << std::endl;
    std::cout << rval2 << std::endl;
}

/********************************************//**
 *  Exercise 2.16
 *
 *  Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
 *
 *      int i = 0, &r1 = i; double d = 0, &r2 = d;
 *
 *      (a) r2 = 3.14159;
 *      (b) r2 = r1;
 *      (c) i = r2;
 *      (d) r1 = d;
 ***********************************************/
void ExerciseNum16 (void)
{
    /*
    Assigns to d value 3.14159 through the reference.
    Assigns the value of i to d through the use of r2 and r1 references.
    Assigns the value of i the value of r2
    Assigns to i the value of d.
    */
}

/********************************************//**
 *  Exercise 2.17
 *
 *  What does the following code print?
 *
 *      int i, &ri = i;
 *      i = 5; ri = 10;
 *      std::cout << i << " " << ri << std::endl;
 ***********************************************/
void ExerciseNum17 (void)
{
    /* It prints the following: "10 10\n". */
    int i, &ri = i;
    i = 5; ri = 10;
    std::cout << i << " " << ri << std::endl;
}

/********************************************//**
 *  Exercise 2.18
 *
 *  Write code to change the value of a pointer. Write code to change the value to which the pointer points.
 ***********************************************/
void ExerciseNum18 (void)
{
    int *p, i = 0;
    p = nullptr;
    p = &i;
    *p = 5;
}

/********************************************//**
 *  Exercise 2.19
 *
 *  Explain the key differences between pointers and references.
 ***********************************************/
void ExerciseNum19 (void)
{
    /* The main difference is that a reference is not an object, and a pointer is an object, with all of which this implies. */
}

/********************************************//**
 *  Exercise 2.20
 *
 *  What does the following program do?
 *
 *      int i = 42;
 *      int *p1 = &i;
 *      *p1 = *p1 * *p1;
 ***********************************************/
void ExerciseNum20 (void)
{
    /* i will be 1764. */
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    std::cout << *p1 << std::endl;
}

/********************************************//**
 *  Exercise 2.21
 *
 *  Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
 *
 *      int i = 0;
 *      (a) double* dp = &i;
 *      (b) int *ip = i;
 *      (c) int *p = &i;
 ***********************************************/
void ExerciseNum21 (void)
{
    /* a is not legal because types mismatch, b is not legal because a pointer can't be initialized with an integer, c is legal. */
}

/********************************************//**
 *  Exercise 2.22
 *
 *  Assuming p is a pointer to int, explain the following code:
 *
 *      if (p) // ...
 *      if (*p) // ...
 ***********************************************/
void ExerciseNum22 (void)
{
    /* First it test that the pointer is not nullptr or zero.
    Second it tests that the object the pointer points to is not zero. */
}

/********************************************//**
 *  Exercise 2.23
 *
 *  Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?
 ***********************************************/
void ExerciseNum23 (void)
{
    /* If it's nullptr it won't point to a valid object, other than that, it is not possible if the pointer is pointing to a valid object. */
}

/********************************************//**
 *  Exercise 2.24
 *
 *  Why is the initialization of p legal but that of lp illegal?
 *
 *      int i = 42;    void *p = &i;     long *lp = &i;
 ***********************************************/
void ExerciseNum24 (void)
{
    /* The initialization of p is legal because it is a void pointer that can hold the address of any type, the initialization of lp is wrong because types mistmatch. */
}

/********************************************//**
 *  Exercise 2.25
 *
 *  Determine the types and values of each of the following variables.
 *
 *      (a) int* ip, &r = ip;
 *      (b) int i, *ip = 0;
 *      (c) int* ip, ip2;
 ***********************************************/
void ExerciseNum25 (void)
{
    /*
      ip, pointer to integer.
      r, A reference to pointer to int.
      i, integer.
      ip, pointer to integer.
      ip, pointer to integer.
      ip2, integer.
    */
}

/********************************************//**
 *  Exercise 2.26
 *
 *  Which of the following are legal? For those that are illegal, explain why.
 *
 *      (a) const int buf;
 *      (b) int cnt = 0;
 *      (c) const int sz = cnt;
 *      (d) ++cnt; ++sz;
 ***********************************************/
void ExerciseNum26 (void)
{
    /*
    Illegal because it is a constant integer which has not been initialized.
    Valid.
    Valid, initialized to the value of cnt.
    ++cnt is valid, but ++sz is not valid because sz is a constant.
    */
}

/********************************************//**
 *  Exercise 2.27
 *
 *  Which of the following initializations are legal? Explain why.
 *
 *      (a) int i = -1, &r = 0;
 *      (b) int *const p2 = &i2;
 *      (c) const int i = -1, &r = 0;
 *      (d) const int *const p3 = &i2;
 *      (e) const int *p1 = &i2;
 *      (f) const int &const r2;
 *      (g) const int i2 = i, &r = i;
 ***********************************************/
void ExerciseNum27 (void)
{
    /*
    i = -1 is valid, but &r is not valid because it is a reference to a literal.
    Is valid because is a constant pointer to int, initialized to the address of i2.
    const int i = -1 is valid, but &r is not valid because it is a reference to a literal.
    p3 is a constant pointer to constant integer, and it is initialized to the address of i2, so it's valid, i2 doesn't need to be const.
    p1 is a pointer to integer constant, initialized to the address of i2, which is correct, i2 doesn't need to be const.
    Invalid reference, can't have top level const because it is already top-level const implicitly, also, the reference is not initialized.
    Both are valid, i2 is initialized to a value and reference r is initialized to a i. i doesn't have to be const.
    */
}

/********************************************//**
 *  Exercise 2.28
 *
 *  Explain the following definitions. Identify any that are illegal.
 *
 *      (a) int i, *const cp;
 *      (b) int *p1, *const p2;
 *      (c) const int ic, &r = ic;
 *      (d) const int *const p3;
 *      (e) const int *p;
 ***********************************************/
void ExerciseNum28 (void)
{
    /*
    i is an integer, cp is a constant pointer to integer, which is not initialized, so not valid.
    p1 is a pointer to int, and p2 is a constant pointer to int, which is not initialized, so not valid.
    ic is a constant integer, which is not initialized, so invalid. r is a constant reference to an integer, which is fine but ic declaration is not valid.
    p3 is a constant pointer to integer constant, but not initialized, so not valid.
    p is a pointer to integer constant.
    */
}

/********************************************//**
 *  Exercise 2.29
 *
 *  Using the variables in the previous exercise, which of the following assignments are legal? Explain why.
 *
 *      (a) i = ic;
 *      (b) p1 = p3;
 *      (c) p1 = &ic;
 *      (d) p3 = &ic;
 *      (e) p2 = p1;
 *      (f) ic = *p3;
 ***********************************************/
void ExerciseNum29 (void)
{
    /*
    Valid, because i is an integer and ic is a constant integer.
    p1 is pointer to integer and p3 is a constant pointer to integer constant, so it's not valid because of the low level const.
    p1 is pointer to integer and ic is constant integer, so it is not valid.
    p3 is constant pointer to integer constant and ic is a constant integer, so it is valid.
    p2 is a constant pointer to integer, and it's value can't be modified.
    ic is a constant integer so its value can't be modified.
    */
}

/********************************************//**
 *  Exercise 2.30
 *
 *  For each of the following declarations indicate whether the object being declared has top-level or low-level const.
 *
 *      const int v2 = 0;    int v1 = v2;
 *      int *p1 = &v1, &r1 = v1;
 *      const int *p2 = &v2, *const p3 = &i, &r2 = v2;
 ***********************************************/
void ExerciseNum30 (void)
{
    /*
    v2 has top level const,
    v1 doesn't have any const.
    p1 has doesn't have any const.
    r1 doesn't have any const.
    p2 has low level const.
    p3 has low level and top level const.
    r2 has low level const.
    */
}

/********************************************//**
 *  Exercise 2.31
 *
 *  Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.
 *
 *      int &r1;
 *      const int v2;
 *      int *p1;
 *      const int *p2;
 *      const int *const p3;
 *
 *      r1 = v2;
 *      p1 = p2;    p2 = p1;
 *      p1 = p3;    p2 = p3;
 ***********************************************/
void ExerciseNum31 (void)
{
    /*
    r1 = v2 -> valid, the value of v2 will be assigned to r1.
    p1 = p2 -> invalid, because p1 has no low level or top level const, p2 has low level const.
    p2 = p1 -> valid, because p2, p2 has low level const and p1 doesnt, this only limits the kind of operations we will be able to do with the pointer.
    p1 = p3 -> invalid, because p1 has no const and p3 has low level const.
    p2 = p3 -> valid, because p2 has low level const and p3 has low level and top level const.
    */
}

/********************************************//**
 *  Exercise 2.32
 *
 *  Is the following code legal or not? If not, how might you make it legal?
 *
 *      int null = 0, *p = null;
 ***********************************************/
void ExerciseNum32 (void)
{
    /*
    It is not valid because attempts to initialize a pointer with the value of an int.

    A possible solution would be to initialize the pointer with the literal value zero.
    */
    int null = 0, *p = 0;
}

/********************************************//**
 *  Exercise 2.33
 *
 *  Using the variable definitions from this section, determine what happens in each of these assignments:
 *
 *      auto a = r;         // a is an int (r is an alias for i, which has type int)
 *      auto b = ci;        // b is an int (top-level const in ci is dropped)
 *      auto c = cr;        // c is an int (cr is an alias for ci whose const is top-level)
 *      auto d = &i;        // d is an int*(& of an int object is int*)
 *      auto e = &ci;       // e is const int*(& of a const object is low-level const)
 *      auto &g = ci;       // g is a const int& that is bound to ci
 *
 *      a = 42;   b = 42;   c = 42;
 *      d = 42;   e = 42;   g = 42;
 ***********************************************/
void ExerciseNum33 (void)
{
    /*
    a = 42 -> It's valid, because a is an int.
    b = 42 -> It's valid, because b is an int.
    c = 42 -> It's valid, because c is an int.
    d = 42 -> This is not valid, because attempts to assign a literal to a pointer.
    e = 42 -> This is not valid, because attempts to assign a literal to a pointer.
    g = 42 -> Not valid, because it's a reference to const.
    */
}

/********************************************//**
 *  Exercise 2.34
 *
 *  Write a program containing the variables and assignments from the previous exercise.
 *  Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct.
 *  If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.
 ***********************************************/
void ExerciseNum34 (void)
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    auto a = r;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    std::cout << "Previous values: " << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
    std::cout << "D: " << d << std::endl;
    std::cout << "E: " << e << std::endl;
    std::cout << "G: " << g << std::endl;

    a = 42;
    b = 42;
    c = 42;
    //d = 42;
    //e = 42;
    //g = 42;

    std::cout << "Values after: " << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
    std::cout << "D: " << d << std::endl;
    std::cout << "E: " << e << std::endl;
    std::cout << "G: " << g << std::endl;
}

/********************************************//**
 *  Exercise 2.35
 *
 *  Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.
 *
 *      const int i = 42;
 *      auto j = i; const auto &k = i; auto *p = &i;
 *      const auto j2 = i, &k2 = i;
 ***********************************************/
void ExerciseNum35 (void)
{
    /*
    Deductions:
    i, const int, obviously
    j, int
    k, reference to const int
    p, pointer to int
    j2, constant int
    k2, constant reference to int
    */
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i;
    const auto &k2 = i;

    j = 10;
    // k = 10; // Will fail
    p = nullptr;
    // j2 = 10; // Will fail
    // k2 = 10; // Will fail
}

/********************************************//**
 *  Exercise 2.36
 *
 *  In the following code, determine the type of each variable and the value each variable has when the code finishes:
 *
 *      int a = 3, b = 4;
 *      decltype(a) c = a;
 *      decltype((b)) d = a;
 *      ++c;
 *      ++d;
 ***********************************************/
void ExerciseNum36 (void)
{
    /*
    c is an int with an initialization value of 3.
    b us a reference to int bounded to a.
    The final value of a is 4.
    The final value of b is 4.
    The final value of c is 4.
    d is a reference bounded to a.
    */
    int a = 3;
    int b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}

/********************************************//**
 *  Exercise 2.37
 *
 *  Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression i = x is int&. Using that knowledge, determine the type and value of each variable in this code:
 *
 *      int a = 3, b = 4;
 *      decltype(a) c = a;
 *      decltype(a = b) d = a;
 ***********************************************/
void ExerciseNum37 (void)
{
    /*
    The type of c is int.
    The type of d is reference to int, initialized to a.
    The final value of a is 3.
    The final value of b is 4.
    The final value of c is 3.
    The final value of d is 3.
    */
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}

/********************************************//**
 *  Exercise 2.38
 *
 *  Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.
 ***********************************************/
void ExerciseNum38 (void)
{
    /*
    You need to explicitly declare references with the auto type qualifier, something that you don't have to do with decltype.
    */
    int i = 0, &ri = i;

    // A will be an int, aa will be a reference.
    auto a = ri;
    decltype(ri) aa = i;

    // b will be an int, bb will be a reference to int.
    auto &b = ri;
    decltype(ri) bb = i;
}

/********************************************//**
 *  Exercise 2.39
 *
 *  Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.
 *
 *  struct Foo { } // Note: no semicolon
 *  int main()
 *  {
 *    return 0;
 *  }
 ***********************************************/
//struct Foo { }
void ExerciseNum39 (void)
{
    /*
    It will say something about a missing semicolon.
    */
}

/********************************************//**
 *  Exercise 2.40
 *
 *  Write your own version of the Sales_data class.
 ***********************************************/
void ExerciseNum40 (void)
{
    struct sales_data_t
    {
        std::string book_no;
        unsigned int units_sold = 0;
        double revenue = 0;
    };
}

/********************************************//**
 *  Exercise 2.41
 *
 *  Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in the same file as your main function.
 ***********************************************/
void ExerciseNum41 (void)
{
    /* No purpose, no new concepts introduced. */
}

/********************************************//**
 *  Exercise 2.42
 *
 *  Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2 (p. 76).
 ***********************************************/
void ExerciseNum42 (void)
{
    /* No purpose, no new concepts introduced. */
}

/********************************************//**
 *  Main function do not modify.
 ***********************************************/
int main (void)
{
    int TotalNumberOfExercises = sizeof(Exercises) / sizeof (Exercise);

    if (ExerciseNum >= 1 && ExerciseNum <= TotalNumberOfExercises)
    {
        printf("Exercise Number %02d\n === S T A R T ===\n\n", ExerciseNum);
        Exercises[ExerciseNum - 1]();
        printf("\n\n ===== E N D =====\nExercise Number %02d\n", ExerciseNum);
    }
    else
    {
        printf("No exercise executed. ExerciseNum is not a valid value.\n");
    }
    return 0;
}

