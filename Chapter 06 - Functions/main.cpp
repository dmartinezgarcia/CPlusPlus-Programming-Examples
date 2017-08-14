// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 51;

// Add function prototypes as you add them.
void ExerciseNum1 (void);
void ExerciseNum2 (void);
void ExerciseNum3 (void);
void ExerciseNum4 (void);
void ExerciseNum5 (void);
void ExerciseNum6 (void);
void ExerciseNum7 (void);
void ExerciseNum8 (void);
void ExerciseNum9 (void);
void ExerciseNum10 (void);
void ExerciseNum11 (void);
void ExerciseNum12 (void);
void ExerciseNum13 (void);
void ExerciseNum14 (void);
void ExerciseNum15 (void);
void ExerciseNum16 (void);
void ExerciseNum17 (void);
void ExerciseNum18 (void);
void ExerciseNum19 (void);
void ExerciseNum20 (void);
void ExerciseNum21 (void);
void ExerciseNum22 (void);
void ExerciseNum23 (void);
void ExerciseNum24 (void);
void ExerciseNum25 (void);
void ExerciseNum26 (void);
void ExerciseNum27 (void);
void ExerciseNum28 (void);
void ExerciseNum29 (void);
void ExerciseNum30 (void);
void ExerciseNum31 (void);
void ExerciseNum32 (void);
void ExerciseNum33 (void);
void ExerciseNum34 (void);
void ExerciseNum35 (void);
void ExerciseNum36 (void);
void ExerciseNum37 (void);
void ExerciseNum38 (void);
void ExerciseNum39 (void);
void ExerciseNum40 (void);
void ExerciseNum41 (void);
void ExerciseNum42 (void);
void ExerciseNum43 (void);
void ExerciseNum44 (void);
void ExerciseNum45 (void);
void ExerciseNum46 (void);
void ExerciseNum47 (void);
void ExerciseNum48 (void);
void ExerciseNum49 (void);
void ExerciseNum50 (void);
void ExerciseNum51 (void);
void ExerciseNum52 (void);
void ExerciseNum53 (void);
void ExerciseNum54 (void);
void ExerciseNum55 (void);
void ExerciseNum56 (void);

typedef void (*Exercise) (void);
// Fill the array as you add exercises.
Exercise Exercises[] =
{
    ExerciseNum1,
    ExerciseNum2,
    ExerciseNum3,
    ExerciseNum4,
    ExerciseNum5,
    ExerciseNum6,
    ExerciseNum7,
    ExerciseNum8,
    ExerciseNum9,
    ExerciseNum10,
    ExerciseNum11,
    ExerciseNum12,
    ExerciseNum13,
    ExerciseNum14,
    ExerciseNum15,
    ExerciseNum16,
    ExerciseNum17,
    ExerciseNum18,
    ExerciseNum19,
    ExerciseNum20,
    ExerciseNum21,
    ExerciseNum22,
    ExerciseNum23,
    ExerciseNum24,
    ExerciseNum25,
    ExerciseNum26,
    ExerciseNum27,
    ExerciseNum28,
    ExerciseNum29,
    ExerciseNum30,
    ExerciseNum31,
    ExerciseNum32,
    ExerciseNum33,
    ExerciseNum34,
    ExerciseNum35,
    ExerciseNum36,
    ExerciseNum37,
    ExerciseNum38,
    ExerciseNum39,
    ExerciseNum40,
    ExerciseNum41,
    ExerciseNum42,
    ExerciseNum43,
    ExerciseNum44,
    ExerciseNum45,
    ExerciseNum46,
    ExerciseNum47,
    ExerciseNum48,
    ExerciseNum49,
    ExerciseNum50,
    ExerciseNum51,
    ExerciseNum52,
    ExerciseNum53,
    ExerciseNum54,
    ExerciseNum55,
    ExerciseNum56
};

#include <stdio.h>
#include <iostream>
#include <initializer_list>
#include <vector>
#include <iterator>
#include <cassert>

using namespace std;

/********************************************//**
 *  Exercise 6.1
 *
 *  What is the difference between a parameter and an argument?
 ***********************************************/
void ExerciseNum1 (void)
{
    // An argument is the value that initializes the parameter.
}

/********************************************//**
 *  Exercise 6.2
 *
 *  Indicate which of the following functions are in error and why.
 *  Suggest how you might correct the problems.
 *  a) int f()
 *     {
 *       string s;
 *       // ...
 *       return s;
 *     }
 *  b) f2(int i) { ... }
 *  c) int calc(int v1, int v1) ... }
 *  d) double square(double x) return x * x;
 ***********************************************/
void ExerciseNum2 (void)
{
    // a) string f() { string s; return s; }.
    // b) int f2(int i) { ... }
    // c) int calc(int v1, int v2) { ... }
    // d) double square(double x) { return x * x }
}

/********************************************//**
 *  Exercise 6.3
 *
 *  Write and test your own version of fact.
 ***********************************************/
int e63_fact(int x);
int e63_fact(int x)
{
    int fact = 1, tmp = 1;

    if (x > 1)
    {
        do
        {
            fact *= (tmp++);
        }
        while (tmp <= x);
    }

    return fact;
}

void ExerciseNum3 (void)
{
    for (auto &val :
            {
                0, 1, 2, 3, 4
            })
    {
        cout << "Factorial number of " << val << " is " << e63_fact(val) << "." << endl;
    }
}

/********************************************//**
 *  Exercise 6.4
 *
 *  Write a function that interacts with the user, asking for a number and generating the factorial of that number.
 *  Call this function from main.
 ***********************************************/
int e64_fact(void);
int e64_fact(void)
{
    int fact = 1, tmp = 1, x = 0;

    cout << "Please input a number to calculate its factorial: ";
    if (cin >> x)
    {
        cout << endl;
        if (x > 1)
        {
            do
            {
                fact *= (tmp++);
            }
            while (tmp <= x);
        }

        cout << "Factorial number of " << x << " is " << fact << "." << endl;
    }

    return fact;
}

void ExerciseNum4 (void)
{
    e64_fact();
}

/********************************************//**
 *  Exercise 6.5
 *
 *  Write a function to return the absolute value of its argument.
 ***********************************************/
int e65_abs(int x);
int e65_abs(int x)
{
    return (x < 0) ? (-x) : (x);
}

void ExerciseNum5 (void)
{
    for (auto &val :
            {
                -4, -2, 0, 2, 4
            })
    {
        cout << "Absolute value of number of " << val << " is " << e65_abs(val) << "." << endl;
    }
}

/********************************************//**
 *  Exercise 6.6
 *
 *  Explain the differences between a parameter, a local variable and a local static variable. Give an example of a function in which each might be useful.
 ***********************************************/
void ExerciseNum6 (void)
{
    // A parameter is a local automatic variable that is initialize by the corresponding argument.
    // A local variable is a local automatic variable that is initialized by the programmer or default initialized.
    // A local static variable is one that is persistent and retains its value across function calls.
}

/********************************************//**
 *  Exercise 6.7
 *
 *  Write a function that retuns zero when it is first called and then generates numbers in sequence each time it is called again.
 ***********************************************/
void e67_counter(void)
{
    static int a = 0;
    cout << "This is the time " << a << " this function has been called." << endl;
    a++;
}

void ExerciseNum7 (void)
{
    e67_counter(), e67_counter(), e67_counter(), e67_counter();
}

/********************************************//**
 *  Exercise 6.8
 *
 *  Write a header file named Chapter6.h that contains declarations for the functions you wrote for the previous exercises.
 ***********************************************/
void ExerciseNum8 (void)
{
    // Not gonna do this as I rather keep everything in this one small file...
}

/********************************************//**
 *  Exercise 6.9
 *
 *  Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous sections.
 *  Use these files to understand how your compiles supports separate compilation.
 ***********************************************/
void ExerciseNum9 (void)
{
    // Not gonna do this...
}

/********************************************//**
 *  Exercise 6.10
 *
 *  Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.
 ***********************************************/
void e610_swap(int *a, int *b);
void e610_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ExerciseNum10 (void)
{
    int a = 5, b = 10;

    cout << "Values before swap: a is " << a << ", b is " << b << "." << endl;
    e610_swap(&a, &b);
    cout << "Values after swap: a is " << a << ", b is " << b << "." << endl;
}

/********************************************//**
 *  Exercise 6.11
 *
 *  Write and test your own version of reset that takes a reference.
 ***********************************************/
void e611_reset(bool &resetVal);
void e611_reset(bool &resetVal)
{
    resetVal = false;
}

void ExerciseNum11 (void)
{
    bool resetVal = true;

    cout << "Value before reset: resetVal is " << resetVal << "." << endl;
    e611_reset(resetVal);
    cout << "Value before reset: resetVal is " << resetVal << "." << endl;
}

/********************************************//**
 *  Exercise 6.12
 *
 *  Rewrite the program from exercise 6.10 to use references instead of pointers.
 *  Which version do you think it would be easier to use and why?
 ***********************************************/
void e612_swap(int &a, int &b);
void e612_swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void ExerciseNum12 (void)
{
    int a = 5, b = 10;

    cout << "Values before swap: a is " << a << ", b is " << b << "." << endl;
    e612_swap(a, b);
    cout << "Values after swap: a is " << a << ", b is " << b << "." << endl;
}

/********************************************//**
 *  Exercise 6.13
 *
 *  Assuming T is the name of a type, explain the difference between a function declared as void f(T) and void f(T&).
 ***********************************************/
void ExerciseNum13 (void)
{
    // f(T) initializes the parameter to be a copy of the argument provided.
    // f(T&) initializes the parameter to be a reference to the argument provided, thus changes in the function to the parameter also affect the argument.
}

/********************************************//**
 *  Exercise 6.14
 *
 *  Give an example of when a parameter should be a reference type and when a parameter should not be a reference.
 ***********************************************/
void ExerciseNum14 (void)
{
    // An example of when a parameter should not be a reference could be the sum function
    // An example of when a parameter should be a reference is the reset by reference in an exercise above.
}

/********************************************//**
 *  Exercise 6.15
 *
 *  Explain the rationale for the type of each of find_char's parameter. In particular, why is s a reference to const but occurs is a plain reference?
 *  Why are these parameters references, but the char parameter c is not? What would happen if we made s a plain reference? What if we made occurs a reference to const?
 ***********************************************/
void ExerciseNum15 (void)
{
    // s is a reference to avoid copying the entire string and const because the string is not meant to be modified inside the string.
    // occurs is a plain reference because it's used to return the number of occurrences in the string.
    // It could be a reference to const char too, we just need a copy of this value... we already know that the size of char is not too large so it can'be inneficient compared to a string.
    // If we made s a plain reference we could change it from inside the function and that is not what we intend to do.
    // If occurs was a reference to const, we wouldn't be able to modify it.
}

/********************************************//**
 *  Exercise 6.16
 *
 *  The following function, although legal, is less useful that it might be. Identify and correct the limitation on this function:
 *
 *  bool is_empty(string &s) { return s.empty(); }
 ***********************************************/
void ExerciseNum16 (void)
{
    // The limitation is that the function expects a reference to string, but it should be a reference to const string, as otherwise for example we can't pass literals and the function could be modified inside the function.
    // bool is_empty(const string &s) { return s.empty(); }
}

/********************************************//**
 *  Exercise 6.17
 *
 *  Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase.
 *  Do the parameters you used in these function have the same type? If so, why? If not, why not?
 ***********************************************/
void e617_getUpperCaseOcurrences(const string &s, int &ocurrences);
void e617_getUpperCaseOcurrences(const string &s, int &ocurrences)
{
    ocurrences = 0;
    for (auto &c : s)
    {
        if (isupper(c) == true)
        {
            ocurrences++;
        }
    }
}

void e617_upperToLower(string &s);
void e617_upperToLower(string &s)
{
    for (auto &c : s)
    {
        if (isupper(c) == true)
        {
            c = tolower(c);
        }
    }
}

void ExerciseNum17 (void)
{
    string input;
    int ocurrences = 0;

    // The parameters don't have the same
    while (cin >> input)
    {
        cout << "String written by user: " << input << endl;
        e617_getUpperCaseOcurrences(input, ocurrences);
        cout << "Number of uppercase characters in the string: " << ocurrences << endl;
        e617_upperToLower(input);
        cout << "String converted to lowercase: " << input << endl;
    }
}

/********************************************//**
 *  Exercise 6.18
 *
 *  Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.
 *  a) A function named compare that return a bool and has two parameters that are references to a class named matrix.
 *  b) A function named change_val that returns a vector<int> iterator and takes two parameters: one is an int and the other is an iterator for a vector<int>.
 ***********************************************/
void ExerciseNum18 (void)
{
    // bool compare(const matrix &a, const matrix &b);
    // vector<int>::iterator change_val(const int count, const vector<int>::iterator iter);
}

/********************************************//**
 *  Exercise 6.19
 *
 *  Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.
 *
 *  double calc(double);
 *  int count(const string &, char);
 *  int sum(vector<int>::iterator, vector<int>::iterator, int);
 *  vector<int> vec(10);
 *
 *  a) calc(23.4, 55.1);
 *  b) count("abcda", 'a');
 *  c) calc(66);
 *  d) sum(vec.begin(), vec.end(), 3.8);
 ***********************************************/
void ExerciseNum19 (void)
{
    // a) illegal because two parameters are passed.
    // b) legal.
    // c) legal.
    // d) legal.
}

/********************************************//**
 *  Exercise 6.20
 *
 *  When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?
 ***********************************************/
void ExerciseNum20 (void)
{
    // They should be references to const when we don't modify the parameter inside the function and passing by value is inefficient.
    // The arguments we could pass would be limited, for example no literals, and the argument could be modified inside the function when we don't expect that.
}

/********************************************//**
 *  Exercise 6.21
 *
 *  Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points.
 *  What type should you use for the pointer?
 ***********************************************/
int e621_compare(int a, const int *b)
{
    return (a > *b) ? (a) : (*b);
}

void ExerciseNum21 (void)
{
    int a, b;
    // It should be a pointer to const as we don't intend to modify the value.
    while (cin >> a >> b)
    {
        cout << "The biggest value of the two introduced is " << e621_compare(a, &b) << "." << endl;
    }
}

/********************************************//**
 *  Exercise 6.22
 *
 *  Write a function to swap two int pointers.
 ***********************************************/
void e622_swapPointers(int *&ptrA, int *&ptrB);
void e622_swapPointers(int *&ptrA, int *&ptrB)
{
    int *ptrC = ptrA;

    ptrA = ptrB;
    ptrB = ptrC;
}

void ExerciseNum22 (void)
{
    int a = 0, b = 1;
    int *ptrA = &a, *ptrB = &b;

    cout << "Value in ptrA " << *ptrA << ", value in ptrB " << *ptrB << "." << endl;
    e622_swapPointers(ptrA, ptrB);
    cout << "Value in ptrA " << *ptrA << ", value in ptrB " << *ptrB << "." << endl;
}

/********************************************//**
 *  Exercise 6.23
 *
 *  Write your own versions of each of the print functions presented in this section. Call each of these functions to print i and j defined as follows:
 *
 *    int i = 0, j[2] = {0, 1}
 ***********************************************/
void e623_print(const int *param, const int length)
{
    int i = 0;

    for (; i < length; i++)
    {
        cout << param[i] << endl;
    }
}

void ExerciseNum23 (void)
{
    int i = 0, j[2] = {0, 1};

    e623_print(&i, 1);
    e623_print(j, 2);
}

/********************************************//**
 *  Exercise 6.24
 *
 *  Explain the behaviour of the following function. If there are problems in the code, explain what they are and how you might fix them.
 *
 *  void print(const int ia[10])
 *  {
 *    for (size_t i = 0; i != 10; ++i)
 *      cout << ia[i] << endl;
 *  }
 ***********************************************/
void ExerciseNum24 (void)
{
    // There are problems in the code, in the sense that the first dimension of the array is ignored, this would be a more appropriate declaration.
    // void print(const int ia[], size_t length);
}

/********************************************//**
 *  Exercise 6.25
 *
 *  Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.
 ***********************************************/
void e625_main(int cnt, const char *argv[])
{
    string res = "error...";

    if (cnt == 2)
    {
        res = argv[0];
        res += argv[1];
    }

    cout << res << endl;
}

void ExerciseNum25 (void)
{
    const char *args[2] = {"Hi my name is", " John Wayne."};

    e625_main(2, args);
}

/********************************************//**
 *  Exercise 6.26
 *
 *  Write a program that accepts the options presented below. Print the values of the arguments passed to main.
 *      -d -o
 *
 ***********************************************/
void ExerciseNum26 (void)
{
    // Similar to the one above...
}

/********************************************//**
 *  Exercise 6.27
 *
 *  Write a function that takes an initializer_list<int> and produces the sum of the elements in the list.
 ***********************************************/
int e627_ExerciseNum(initializer_list<int> lst)
{
    int sum = 0;

    for (auto &c : lst)
    {
        sum += c;
    }

    return sum;
}

void ExerciseNum27 (void)
{
    cout << "The sum of 1, 2, 3, 4, 5 is: " << e627_ExerciseNum({1, 2, 3, 4, 5}) << "." << endl;
}

/********************************************//**
 *  Exercise 6.28
 *
 *  In the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?
 *
 *  void error_msg(ErrCode e, initializer_list<string> il)
 *  {
 *    cout << e.msg() << ": ";
 *    for (const auto &elem : il)
 *      cout << elem << " ";
 *    cout << endl;
 *  }
 ***********************************************/
void ExerciseNum28 (void)
{
    // It's a reference to constant string.
}

/********************************************//**
 *  Exercise 6.29
 *
 *  When you use an initializer_list in a range for would you ever use a reference as the loop control variable?
 *  If so, why? If not, why not?
 ***********************************************/
void ExerciseNum29 (void)
{
    // An initializer list is constant, so a reference to const could be used, otherwise it could be done by copy.
}

/********************************************//**
 *  Exercise 6.30
 *
 *  Compile the following program to check what the compiler says about the indicated errors:
 *    bool str_subrange(const string &str1, const string &str2)
 *    {
 *         if (str1.size() == str2.size())
 *             return str1 == str2;
 *
 *         auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
 *
 *         for (decltype(size) i = 0; i != size; ++i)
 *         {
 *             if (str1[i] != str2[i])
 *             {
 *                 return;
 *             }
 *         }
 *    }
 ***********************************************/
void ExerciseNum30 (void)
{
//    bool e630_str_subrange(const string &str1, const string &str2)
//    {
//        if (str1.size() == str2.size())
//            return str1 == str2;
//
//        auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
//
//        for (decltype(size) i = 0; i != size; ++i)
//        {
//            if (str1[i] != str2[i])
//            {
//                return true; // No return value here.
//            }
//        }
//        // No return path here, however compiler doesn't say anything.
//    }
}

/********************************************//**
 *  Exercise 6.31
 *
 *  When is valid to return a reference? A reference to const?
 ***********************************************/
void ExerciseNum31 (void)
{
    // In both cases, when the object is not a local object, as that object doesn't exist anymore after the function ends.
    // In the case of reference to const, when the object only requires read access.
}

/********************************************//**
 *  Exercise 6.32
 *
 *  Indicate whether the following function is legal. If so, explain what it does, if not, correct any errors and then explain it.
 *    int &get(int *arry, int index) { return arry[index]; }
 *    int main()
 *    {
 *        int ia[10];
 *
 *        for (int i = 0; i != 10; ++i)
 *        {
 *            get(ia, i) = i;
 *        }
 *    }
 ***********************************************/
int &e632_get(int *arry, int index)
{
    return arry[index];
}
int e632_main()
{
    int ia[10];

    for (int i = 0; i != 10; ++i)
    {
        e632_get(ia, i) = i;
    }
}

void ExerciseNum32 (void)
{
    // It's a valid functon, what the get function does is return a reference to the value at position index of the specified array, afterwards in main that value is replaced with the loop variable.
}

/********************************************//**
 *  Exercise 6.33
 *
 *  Write a recursive function to print the contents of a vector.
 ***********************************************/
void e633_print_vector(vector<string>::const_iterator vcbegin, vector<string>::const_iterator vcend)
{
    if (vcbegin != vcend)
    {
        cout << *vcbegin << endl;

        if (++vcbegin != vcend)
        {
            e633_print_vector(vcbegin, vcend);
        }
    }
}

void ExerciseNum33 (void)
{
    vector<string> example = {"Hello", "My", "Name", "Is", "Diego"};

    e633_print_vector(example.cbegin(), example.cend());
}

/********************************************//**
 *  Exercise 6.34
 *
 *  What would happen if the stopping condition in a factorial were:
 *    if (val != 0)
 ***********************************************/
void ExerciseNum34 (void)
{
    // It would call itself indefinitely when calculating the factorial of a non-zero value, as no number has the factorial zero.
}

/********************************************//**
 *  Exercise 6.35
 *
 *  In the function below, why did we pass val - 1 rather than val--?
 *    int factorial(int val)
 *    {
 *        if (val > 1)
 *            return factorial(val - 1) * val;
 *        return 1;
 *    }
 ***********************************************/
void ExerciseNum35 (void)
{
    // If we pass val--, we would be passing the current value of val to the function, and we would be multiplying by val - 1, and all of that is wrong.
}

/********************************************//**
 *  Exercise 6.36
 *
 *  Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype or a type alias.
 ***********************************************/
void ExerciseNum36 (void)
{
    string (&e63_retReference())[10];
}

/********************************************//**
 *  Exercise 6.37
 *
 *  Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype.
 *  Which form do you prefer and why?
 ***********************************************/
using e637_arrayTenStrings = string (&)[10];
string e637_a[10];

e637_arrayTenStrings e637_retReference();
auto e637_retReference() -> string (&)[10];
decltype(e637_a) &e637_retReference();

void ExerciseNum37 (void)
{
    // I prefer the type alias, for consistency with the rest of the functions and for clarity.
}

/********************************************//**
 *  Exercise 6.38
 *
 *  Revise the arrPtr function on to return a reference to the array.
 *    int odd[] = {1, 3, 5, 7, 9};
 *
 *    decltype(odd) *arrPtr(int i)
 *    {
 *        return (i % 2) ? &odd : &even:
 *    }
 ***********************************************/
void ExerciseNum38 (void)
{
    // Changing the star character to an ampersand will do.
}

/********************************************//**
 *  Exercise 6.39
 *
 *  Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
 *    a) int calc(int, int);
 *       int calc(const int, const int);
 *    b) int get();
 *       double get();
 *    c) int *reset(int *);
 *       double *reset(double *);
 ***********************************************/
void ExerciseNum39 (void)
{
    // a) It's legal but it's the same declaration, they const is ignored as passing the parameter by value.
    // b) Not legal as parameter lists match in types and number.
    // c) Overloaded function, legal as the parameter lists differ in type..
}

/********************************************//**
 *  Exercise 6.40
 *
 *  Which, if either, of the following declarations are errors? Why?
 *    a) int ff(int a, int b = 0, int c = 0);
 *    c) char *init(int ht = 24, int wd, char bckgrnd);
 ***********************************************/
void ExerciseNum40 (void)
{
    // a) Not an error.
    // b) Error because a default argument has to be specified for the first parameter that expects it and also the parameters that follow.
}

/********************************************//**
 *  Exercise 6.41
 *
 *  Which, if any, of the following calls are illegal? Why? Which if any, are legal but unlikely to match the programmer's intent? Why?
 *    char *init(int ht, int wd = 80, char bckgrnd = ' ');
 *    a) init();
 *    b) init(24, 10);
 *    c) init(14, '*');
 ***********************************************/
void ExerciseNum41 (void)
{
    // a) Illegal because no argument was specified for ht.
    // b) Legal, and likely to match the parameter intent.
    // c) Legal, but unlikely to match the programmer's intent, because he/she probably meant the star argument to be assigned to bckgrnd parameter.
}

/********************************************//**
 *  Exercise 6.42
 *
 *  Give the second parameter of make_plural a default argument of 's'. Test your program by printing singular and plural versions of the words success and failure.
 *    string make_plural(size_t ctr, const string &word, const string &ending)
 *    {
 *        return (ctr > 1) ? word + ending : word;
 *    }
 ***********************************************/
string e642_make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

void ExerciseNum42 (void)
{
    cout << "This will print a singular word: " << e642_make_plural(1, "count") << "." << endl;
    cout << "This will print a plural word: " << e642_make_plural(2, "count") << "." << endl;
}

/********************************************//**
 *  Exercise 6.43
 *
 *  Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.
 *    a) inline bool eq(const BigInt&, const BigInt&) {...}
 *    b) void putValues(int *arr, int size);
 ***********************************************/
void ExerciseNum43 (void)
{
    // a) I would just define the function in a header file, because the compiler just needs to see the body of the function and not the declaration,
    // b) I would put the declaration in a header file and the definition in a source file, because the compiler doesn't need to see the function body to make the call.
}

/********************************************//**
 *  Exercise 6.44
 *
 *  Rewrite the isShorter function to be inline.
 *    bool isShorter(const string &s1, const string &s2)
 *    {
 *        return s1.size() < s2.size();
 *    }
 ***********************************************/
inline bool e644_isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void ExerciseNum44 (void)
{
    string s1 = "Hi!";
    string s2 = "Hello!";

    if (e644_isShorter(s1, s2))
    {
        cout << s1 << " is shorter than " << s2 << "." << endl;
    }
    else
    {
        cout << s2 << " is shorter than " << s1 << "." << endl;
    }
}

/********************************************//**
 *  Exercise 6.45
 *
 *  Review the programs you've written for the earlier exercises and decide whether they should be defined as inline. If so, do so, If not explain why they should not be inline.
 ***********************************************/
void ExerciseNum45 (void)
{
    // Not going to do this, if the exercises are not complex they should be inlined for performance and to void the function call overhead.
}

/********************************************//**
 *  Exercise 6.46
 *
 *  Would it be possible to define isShorter as a constexpr? If so, do so, if not, explain why not.
 *    bool isShorter(const string &s1, const string &s2)
 *    {
 *        return s1.size() < s2.size();
 *    }
 ***********************************************/
void ExerciseNum46 (void)
{
    // It's not possible because the body implies run-time operations.
}

/********************************************//**
 *  Exercise 6.47
 *
 *  Revise the program you wrote in the exercise 6.33 that used recursion to print the contents of a vector to conditionally print information about its execution.
 *  For example, you might print the size of the vector on each call. Compile and run the program with debugging turned ON and again with it turned OFF.
 ***********************************************/
void e647_print_vector(vector<string>::const_iterator vcbegin, vector<string>::const_iterator vcend)
{
    if (vcbegin != vcend)
    {
        #ifndef NDEBUG
        cerr << "Function: " << __FUNCTION__ << ", Elements to print remaining: " << vcend - vcbegin << endl;
        #endif // NDEBUG
        cout << *vcbegin << endl;
        e647_print_vector(++vcbegin, vcend);
    }
    else
    {
        #ifndef NDEBUG
        cerr << "Function: " << __FUNCTION__ << ", Elements to print remaining: " << vcend - vcbegin << endl;
        #endif // NDEBUG
    }
}

void ExerciseNum47 (void)
{
    vector<string> example = {"Hello", "My", "Name", "Is", "Diego"};

    e647_print_vector(example.cbegin(), example.cend());
}

/********************************************//**
 *  Exercise 6.48
 *
 *  Explain what this loop does and whether it is a good use of assert:
 *    string s;
 *    while (cin >> s && s != sought) {}
 *    assert(cin);
 ***********************************************/
void ExerciseNum48 (void)
{
    // What it basically does is stop the program if the string sought was not received over the standard input.
    string s;
    while (cin >> s && s != "Hello");
    assert(cin);
}

/********************************************//**
 *  Exercise 6.49
 *
 *  What is a candidate function? What is a viable function?
 ***********************************************/
void ExerciseNum49 (void)
{
    // A candidate function is one in a set of overloaded functions.
    // A viable function is a candidate function and potential match for a given function call.
}

/********************************************//**
 *  Exercise 6.50
 *
 *  Given the following declarations:
 *    void f();
 *    void f(int);
 *    void f(int, int);
 *    void f(double, double = 3.14);
 *  List the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.
 *    a) f(2.56, 42)
 *    b) f(42)
 *    c) f(42, 0)
 *    d) f(2.56, 3.14)
 ***********************************************/
void ExerciseNum50 (void)
{
    // a) void f(int, int) and void f(double, double = 3.14) are viable functions, but none is a best match, so it will be an ambiguous function call.
    // b) void f(int) and void f(double, double = 3.14) are viable functions, but the first one is the best match as no conversion is required.
    // c) void f(int, int) and void f(double, double = 3.14) are viable function, but the first one is the best match as no conversion is required.
    // d) void f(int, int) and void f(double, double = 3.14) are viable functions, but the second one is the best match as no conversion is required.
}

/********************************************//**
 *  Exercise 6.51
 *
 *  Write all four version of f in the previous exercise. Each function should print a distinguishing message.
 *  Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.
 ***********************************************/
void e651_f() { cout << "First function called." << endl; }
void e651_f(int) { cout << "Second function called." << endl; }
void e651_f(int, int) { cout << "Third function called." << endl; }
void e651_f(double, double = 3.14) { cout << "Fourth function called." << endl; }

void ExerciseNum51 (void)
{
    //e651_f(2.56, 42);
    e651_f(42);
    e651_f(42, 0);
    e651_f(2.56, 3.14);
}

/********************************************//**
 *  Exercise 6.52
 *
 *  Given the following declarations:
 *    void manip(int, int);
 *    double dobj;
 *  What is the rank of each conversion in the following calls:
 *    a) manip('a', 'z');
 *    b) manip(55.4, dobj);
 ***********************************************/
void ExerciseNum52 (void)
{
    // a) 'a' and 'z' are promoted from char to int, therefore is rank 3.
    // b) 55.4 is converted from double to int and same for dobj, so they are rank 4.
}

/********************************************//**
 *  Exercise 6.53
 *
 *  Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
 *    a) int calc(int&, int&);
 *       int calc(const int&, const int&);
 *    b) int calc(char*, char*);
 *       int calc(const char*, const char*);
 *    c) int calc(char*, char*);
 *       int calc(char* const, char* const);
 ***********************************************/
void ExerciseNum53 (void)
{
    // Overloaded functions, plain references and references to const.
    // Overloaded functions, plain pointer and pointer to const.
    // No effect, because is a top-level const that affects the pointer and not the object where it points.
}

/********************************************//**
 *  Exercise 6.54
 *
 *  Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.
 ***********************************************/
using e654_fnPtr = int (*)(int, int);
vector<e654_fnPtr> e654_fnPtrVector;

void ExerciseNum54 (void)
{

}

/********************************************//**
 *  Exercise 6.55
 *
 *  Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these values in your vector from the previous exercise.
 ***********************************************/
using e655_fnPtr = int (*)(int, int);
int e655_add(int a, int b) {return a + b;};
int e655_subtract(int a, int b) {return a - b;};
int e655_multiply(int a, int b) {return a * b;};
int e655_divide(int a, int b) {return a / b;};
vector<e655_fnPtr> e655_fnPtrVector = {e655_add, e655_subtract, e655_multiply, e655_divide};

void ExerciseNum55 (void)
{

}

/********************************************//**
 *  Exercise 6.56
 *
 *  Call each element in the vector and print their result.
 ***********************************************/
using e656_fnPtr = int (*)(int, int);
int e656_add(int a, int b) {return a + b;};
int e656_subtract(int a, int b) {return a - b;};
int e656_multiply(int a, int b) {return a * b;};
int e656_divide(int a, int b) {return a / b;};
vector<e656_fnPtr> e656_fnPtrVector = {e656_add, e656_subtract, e656_multiply, e656_divide};

void ExerciseNum56 (void)
{
    int a = 4, b = 4;

    for (const auto &fn : e656_fnPtrVector)
    {
        cout << fn(a, b) << endl;
    }
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

