// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 13;

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
void ExerciseNum36 (void);
void ExerciseNum37 (void);
void ExerciseNum38 (void);

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
    ExerciseNum38
};

#include <stdio.h>
#include <iostream>

/********************************************//**
 *  Exercise 4.1
 *    std::cout << "(a) " << -30 * 3 + 21 / 5 << std::endl;
    std::cout << "(b) " << -30 + 3 * 21 / 5 << std::endl;
 *  What is the value returned by 5 + 10 * 20 / 2?.
 ***********************************************/
void ExerciseNum1 (void)
{
    // The result is 105.
    std::cout << 5 + 10 * 20 / 2 << std::endl;
}

/********************************************//**
 *  Exercise 4.2
 *
 *  Parenthesize the following expressions to indicate the order in which the operands are grouped.
 *      (a) vec.begin()
 *      (b) vec.begin() + 1
 ***********************************************/
void ExerciseNum2 (void)
{
    // (a) ((vec.begin)()).
    // (b) (((vec.begin)()) + 1)
}

/********************************************//**
 *  Exercise 4.3
 *
 *  Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?
 ***********************************************/
void ExerciseNum3 (void)
{
    // Yes, I consider it an acceptable trade-off as otherwise it will be up to the programmer the task of optimizing.
}

/********************************************//**
 *  Exercise 4.4
 *
 *  Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
 *    12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
 ***********************************************/
void ExerciseNum4 (void)
{
    std::cout << "Without parentheses: " << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << std::endl;
    std::cout << "With parentheses: " << ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2) << std::endl;
}

/********************************************//**
 *  Exercise 4.5
 *
 *  Determine the result of the following expressions.
 *    (a) -30 * 3 + 21 / 5
 *    (b) -30 + 3 * 21 / 5
 *    (c) 30 / 3 * 21 % 5
 *    (d) -30 / 3 * 21 % 4
 ***********************************************/
void ExerciseNum5 (void)
{
    std::cout << "(a) " << -30 * 3 + 21 / 5 << std::endl;
    std::cout << "(b) " << -30 + 3 * 21 / 5 << std::endl;
    std::cout << "(c) " << 30 * 3 * 21 % 5 << std::endl;
    std::cout << "(d) " << -30 / 3 * 21 % 5 << std::endl;
}

/********************************************//**
 *  Exercise 4.6
 *
 *  Write an expression to determine whether an int value is even or odd.
 ************************i = d = 3.5;***********************/
void ExerciseNum6 (void)
{
    int a = 0x01;
    std::cout << ((a & 1) ? ("ODD") : ("EVEN")) << std::endl;
}

/********************************************//**
 *  Exercise 4.7
 *
 *  What does overflow mean? Show three expressions that will overflow.
 ***********************************************/
void ExerciseNum7 (void)
{
    // An overflow occurs when the maximum value that a certain type of variable can hold is surpassed, like in the examples below:
    //char a = 852;
    //char b = 255+1;
    //char c = 255;
    //c = c + 1;
}

/********************************************//**
 *  Exercise 4.8
 *
 *  Explain when operands are evaluated in the logical AND, logical OR and equality operators.
 ***********************************************/
void ExerciseNum8 (void)
{
    // In the logical AND, the operand on the left is evaluated first and afterwards the operand on the right if and only if.
    // In the logical OR, the operand on the left is evaluated first and afterwards the operand on the right if and only if the result of the evaluation of the left hand operand is false.
    // Equality operators evaluate first the left-hand operand and afterwards the right-hand operand.
}

/********************************************//**
 *  Exercise 4.9
 *
 *  Explain the behaviour of the condition in the following if:
 *    const char *cp = "Hello world";
 *    if (cp && *cp)
 ***********************************************/
void ExerciseNum9 (void)
{
    // It basically checks that the it's not a pointer to NULL and that it's not an empty string.
}

/********************************************//**
 *  Exercise 4.10
 *
 *  Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.
 ***********************************************/
void ExerciseNum10 (void)
{
    int a = 0;
    std::cout << "Reading values until the input is 42..." << std::endl;

    while ((a != 42) && (std::cin >> a))
    {
        std::cout << "Value read " << a << std::endl;
    }
}

/********************************************//**
 *  Exercise 4.11
 *
 *  Write an expression that tests four values, a, b, c and d, and ensures that a is greater than b, which is greater than c, which is greater than d.
 ***********************************************/
void ExerciseNum11 (void)
{
    char a = 4, b = 3, c = 2, d = 1;

    std::cout << ( (a > b) ? ( (b > c) ? ( (c > d) ? ("YEP") : ("YES BUT NO") ) : ("ALMOST THERE") ) : ("NOPE") ) << std::endl;
}

/********************************************//**
 *  Exercise 4.12
 *
 *  Assuming i, j and k are all ints, explain what i != j < k means.
 ***********************************************/
void ExerciseNum12 (void)
{
    // It's basically the same as this: i != (j < k), which is not good practice.
}

/********************************************//**
 *  Exercise 4.13
 *
 *  What are the values of i and d after each assignment?
 *    int i; double d;
 *    (a) d = i = 3.5;
 *    (b) i = d = 3.5;
 ***********************************************/
void ExerciseNum13 (void)
{
    // (a) d = 3.0, i = 3
    // (b) i = 3, d = 3.5
    int i = 0;
    double d = .0;
    d = i = 3.5;
    std::cout << "d " << d << " i " << i << std::endl;
    i = d = 3.5;
    std::cout << "d " << d << " i " << i << std::endl;
}

/********************************************//**
 *  Exercise 4.14
 *
 *  Explain what happens in each of the if tests:
 *    if (42 = i)   // ...
 *    if (i = 42)   // ...
 ***********************************************/
void ExerciseNum14 (void)
{
    // The first statement is illegal, as it tries to assign a value to a constant.
    // The second value assigns the value 42 to the variable i and then it executes.
}

/********************************************//**
 *  Exercise 4.15
 *
 *  The following assignment is illegal. Why? How would you correct it?
 *    double dval; int ival; int *pi;
 *    dval = ival = pi = 0;
 ***********************************************/
void ExerciseNum15 (void)
{
    double dval; int ival; int *pi;
    // A correct way of doing it  would be as follows.
    pi = 0, ival = 0, dval = 0;
}

/********************************************//**
 *  Exercise 4.16
 *
 *  Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
 *    (a) if (p = getPtr() != 0)
 *    (b) if (i = 1024)
 ***********************************************/
void ExerciseNum16 (void)
{
    // In (a) this is actually what happens if (p = (getPtr() != 0)), this would be the correct way of writing it: if ((p = getPtr()) != 0).
    // In (b) this is probably what the programmer intended if (i == 1024).
}

/********************************************//**
 *  Exercise 4.17
 *
 *  Explain the difference between prefix and postfix increment.
 ***********************************************/
void ExerciseNum17 (void)
{
    // A prefix increment increments the variable and then evaluates it.
    // A postfix increment evaluates the variable and then increments it.
}

/********************************************//**
 *  Exercise 4.18
 *
 *  What would happen in the following loop:
 *
 *    auto pbeg = v.begin();
 *    while (pbeg != v.end() && *beg >= 0)
 *        cout << *pbeg++ << endl;
 *
 *  If the while loop that prints the elements from a vector used the prefix increment operator?
 ***********************************************/
void ExerciseNum18 (void)
{
    // That the first element wouldn't be written to the output and on the last iteration it would access an element out of bounds.
}

/********************************************//**
 *  Exercise 4.19
 *
 *  Given that ptr points to an int, that vec is a vector<int>, and that ival is an int, explain the behaviour of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
 *    (a) ptr != 0 && *ptr++
 *    (b) ival++ && ival
 *    (c) vec[ival++] <= vec[ival]
 ***********************************************/
void ExerciseNum19 (void)
{
    // (a) First it evaluates that the pointer is not null, afterwards it evaluates the pointer value and later it increments it, afterwards the result of the postfix is incremented and checked against true or false.
    // (b) First ival is evaluated and incremented, afterwards the incremented value is evaluated again.
    // (c) It evaluates ival and increments it, afterwards it checks whether the element indexed at actual value of ival is
    // Most of these are dangerous, but too long to explain.
}

/********************************************//**
 *  Exercise 4.20
 *
 *  Assuming that iter is a vector<string>::iterator, indicate which, if any, of the following expressions are legal. Explain the behaviour of the legal expressions and why those that aren't legal are in error.
 *    (a) *iter++;
 *    (b) (*iter)++;
 *    (c) *iter.empty()
 *    (d) iter->empty();
 *    (e) ++*iter;
 *    (f) iter++->empty();
 ***********************************************/
void ExerciseNum20 (void)
{
}

/********************************************//**
 *  Exercise 4.21
 *
 *  Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.
 ***********************************************/
void ExerciseNum21 (void)
{
}

/********************************************//**
 *  Exercise 4.22
 *
 *  Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions:
 *    One version that uses only conditional operators.
 *    Another version that should use one or more if statements.
 *  Which version do you think is easier to understand and why?
 ***********************************************/
void ExerciseNum22 (void)
{
}

/********************************************//**
 *  Exercise 4.23
 *
 *  The following expression fails to compile due to operator precedence. Explain why it fails and how you would fix it.
 *    string s = "word";
 *    string pl = s + s[s.size() - 1] == 's' ? "" : "s";
 ***********************************************/
void ExerciseNum23 (void)
{
}

/********************************************//**
 *  Exercise 4.24
 *
 *  Our program that distinguished between high pass, pass and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.
 ***********************************************/
void ExerciseNum24 (void)
{
}

/********************************************//**
 *  Exercise 4.25
 *
 *  What is the value of ~'q' << 6 on a machine with 32 bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?
 ***********************************************/
void ExerciseNum25 (void)
{
}

/********************************************//**
 *  Exercise 4.26
 *
 *  In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?
 ***********************************************/
void ExerciseNum26 (void)
{
}

/********************************************//**
 *  Exercise 4.27
 *
 *  What is the result of each of these expressions?
 *    unsigned long ul1 = 3, ul2 = 7;
 *    (a) ul1 & ul2
 *    (b) ul1 | ul2
 *    (c) ul1 && ul2
 *    (d) ul1 || ul2
 ***********************************************/
void ExerciseNum27 (void)
{
}

/********************************************//**
 *  Exercise 4.28
 *
 *  Write a program to print the size of each of the built-in types.
 ***********************************************/
void ExerciseNum28 (void)
{
}

/********************************************//**
 *  Exercise 4.29
 *
 *  Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
 *    int x[10]; int *p = x;
 *    cout << sizeof(x) / sizeof(*x) << endl;
 *    cout << sizeof(p) / sizeof(*p) << endl;
 ***********************************************/
void ExerciseNum29 (void)
{
}

/********************************************//**
 *  Exercise 4.30
 *
 *  Parenthesize the following expressions to match the default evaluation.
 *    (a) sizeof(x + y)
 *    (b) sizeof(p->mem[i])
 *    (c) sizeof(a < b)
 *    (d) sizeof(f())
 ***********************************************/
void ExerciseNum30 (void)
{
}

/********************************************//**
 *  Exercise 4.31
 *
 *  The program in this section used the prefix increment and decrement operators. Explain why we used the prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.
 ***********************************************/
void ExerciseNum31 (void)
{
}

/********************************************//**
 *  Exercise 4.32
 *
 *  Explain the following loop.
 *    constexpr int size = 5;
 *    int ia[size] = {1, 2, 3, 4, 5};
 *    for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr)
 *      ...
 ***********************************************/
void ExerciseNum32 (void)
{
}

/********************************************//**
 *  Exercise 4.33
 *
 *  Explain what the following expression does:
 *    someValue ? ++x, ++y : --x, --y
 ***********************************************/
void ExerciseNum33 (void)
{
}

/********************************************//**
 *  Exercise 4.34
 *
 *  Given the variable definitions in this section, explain what conversions take place in the following expressions:
 *    (a) if (fval)
 *    (b) dval = fval + ival;
 *    (c) dval + ival * cval;
 ***********************************************/
void ExerciseNum34 (void)
{
}

/********************************************//**
 *  Exercise 4.35
 *
 *  Given the following definitions:
 *    char cval; int ival; unsigned int ui; float fval; double dval;
 *
 *  Identify the implicit type conversions, if any, taking place:
 *    (a) cval = 'a' + 3;
 *    (b) fval = ui - ival * 1.0;
 *    (c) dval = ui * fval;
 *    (d) cval = ival + fval + dval;
 ***********************************************/
void ExerciseNum35 (void)
{
}

/********************************************//**
 *  Exercise 4.36
 *
 *  Assuming i is an int and d is a double write the expression i *= d so that it does integral, rather than floating point, multiplication.
 ***********************************************/
void ExerciseNum36 (void)
{
}

/********************************************//**
 *  Exercise 4.37
 *
 *  Rewrite each of the following old-style casts to use a named cast:
 *    int i; double d; const string *ps; char *pc; void *pv;
 *    (a) pv = (void*)ps;
 *    (b) i = int(*pc);
 *    (c) pv = &d;
 *    (d) pc = (char*)pv;
 ***********************************************/
void ExerciseNum37 (void)
{
}

/********************************************//**
 *  Exercise 4.38
 *
 *  Explain the following expression:
 *    double slope = static_cast<double>(j / i);
 ***********************************************/
void ExerciseNum38 (void)
{
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

