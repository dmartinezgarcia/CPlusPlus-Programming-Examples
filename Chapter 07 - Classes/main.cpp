// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 32;

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
void ExerciseNum57 (void);
void ExerciseNum58 (void);

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
    ExerciseNum56,
    ExerciseNum57,
    ExerciseNum58
};

#include <stdio.h>
#include "Sales_data.h"
#include "Screen.h"
#include "Window_mgr.h"
#include "XY.h"
#include <istream>

/********************************************//**
 *  Exercise 7.1
 *
 *  Write your own version of the transacion-processing program below using you own Sales_data class.
 *
 *  #include <iostream>
 *  #include "Sales_item.h"
 *
 *  int main()
 *  {
 *    Sales_item total;
 *    if (std::cin >> total)
 *    {
 *      Sales_item trans;
 *      while (std::cin >> trans)
 *      {
 *        if (total.isbn() == trans.isbn())
 *        {
 *          total += trans;
 *        }
 *        else
 *        {
 *          std::cout << total << std::endl;
 *          total = trans;
 *        }
 *      }
 *      std::cout << total < std::endl;
 *    }
 *    else
 *    {
 *      std::cerr << "No data?!" << std::endl;
 *      return -1;
 *    }
 *    return 0;
 *  }
 *
 ***********************************************/
void ExerciseNum1 (void)
{
    Sales_data total = Sales_data(), tmp = Sales_data();

    std::cout << "Enter transactions in the following format: ISBN, units sold and price." << std::endl;

    if (total.fillFromStream(std::cin))
    {
        while (tmp.fillFromStream(std::cin))
        {
            if (total.isSameBook(tmp))
            {
                total.combine(tmp);
            }
            else
            {
                print(std::cout, total);
                total = Sales_data(tmp);
                std::cout << "************************" << std::endl;
            }
        }
        print(std::cout, total);
    }
    else
    {
        std::cout << "No data?!" << std::endl;
    }
}

/********************************************//**
 *  Exercise 7.2
 *
 *  Add the combine and isbn function members to your Sales_data class.
 ***********************************************/
void ExerciseNum2 (void)
{
    // Check Sales_data.h
}

/********************************************//**
 *  Exercise 7.3
 *
 *  Revise your program from exercise 7.1 to use these members.
 ***********************************************/
void ExerciseNum3 (void)
{
    Sales_data total = Sales_data(), tmp = Sales_data();

    std::cout << "Enter transactions in the following format: ISBN, units sold and price." << std::endl;

    if (total.fillFromStream(std::cin))
    {
        while (tmp.fillFromStream(std::cin))
        {
            if (total.isbn() == tmp.isbn())
            {
                total.combine(tmp);
            }
            else
            {
                print(std::cout, total);
                total = Sales_data(tmp);
                std::cout << "************************" << std::endl;
            }
        }
        print(std::cout, total);
    }
    else
    {
        std::cout << "No data?!" << std::endl;
    }
}

/********************************************//**
 *  Exercise 7.4
 *
 *  Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements.
 *  Subsequent exercises will incrementally add features to this class.
 ***********************************************/
void ExerciseNum4 (void)
{
    // Check Person.h
}

/********************************************//**
 *  Exercise 7.5
 *
 *  Provide operations in your Person class to return the name and address.
 *  Should these functions be const? Explain you choice.
 ***********************************************/
void ExerciseNum5 (void)
{
    // They return a reference to constant string, these functions are also const because the object on which they are called should not be modified.
}

/********************************************//**
 *  Exercise 7.6
 *
 *  Define your own versions of the add, read, and print functions for your Sales_data class.
 ***********************************************/
void ExerciseNum6 (void)
{
    // Check Sales_data.h
}

/********************************************//**
 *  Exercise 7.7
 *
 *  Rewrite the transaction-processing program you wrote for the exercise 7.3 to use the new add, read and print functionality.
 ***********************************************/
void ExerciseNum7 (void)
{
    Sales_data total = Sales_data(), tmp = Sales_data();

    std::cout << "Enter transactions in the following format: ISBN, units sold and price." << std::endl;

    if (read(std::cin, total))
    {
        while (read(std::cin, tmp))
        {
            if (total.isbn() == tmp.isbn())
            {
                total = add(total, tmp);
            }
            else
            {
                print(std::cout, total);
                total = Sales_data(tmp);
                std::cout << "************************" << std::endl;
            }
        }
        print(std::cout, total);
    }
    else
    {
        std::cout << "No data?!" << std::endl;
    }
}

/********************************************//**
 *  Exercise 7.8
 *
 *  Why does read define its Sales_data parameter as a plain reference and print define its parameter as a reference to const?
 ***********************************************/
void ExerciseNum8 (void)
{
    // Because in read we will modify the object supplied with data read from the input and in print will just print the data in the object through the standard output without modifying it.
}

/********************************************//**
 *  Exercise 7.9
 *
 *  Add operations to read and print Person objects to your Person class.
 ***********************************************/
void ExerciseNum9 (void)
{
    // Check Sales_data.h
}

/********************************************//**
 *  Exercise 7.10
 *
 *  What does the condition in the following if statement do?
 *
 *  if (read(read(cin, data1), data2))
 ***********************************************/
void ExerciseNum10 (void)
{
    // It reads data from the standard input into data1, and then it does the same with data2.
    // The if condition checks that the operation with data2 went well, there are better ways to do this, I would check each individually for example with a logical AND operator.
}

/********************************************//**
 *  Exercise 7.11
 *
 *  Add constructors to your Sales_data class and write a program to use each of the constructors.
 ***********************************************/
void ExerciseNum11 (void)
{
    // We have already done this in the first exercise.
}

/********************************************//**
 *  Exercise 7.12
 *
 *  Move the definition of the Sales_data constructor that takes an istream into the body of the Sales_data class.
 ***********************************************/
void ExerciseNum12 (void)
{
    // This is basically making the function implicitly inline with no other changes, which I am not going to do.
}

/********************************************//**
 *  Exercise 7.13
 *
 *  Rewrite the program from Exercise 7.1 using the constructor from 7.12.
 ***********************************************/
void ExerciseNum13 (void)
{
    // I've already coded this program in four different ways by now, I am getting sick of book transactions :D.
}

/********************************************//**
 *  Exercise 7.14
 *
 *  Rewrite the program from Exercise 7.1 using the constructor from 7.12.
 ***********************************************/
void ExerciseNum14 (void)
{
    // Check Sales_data.h
}

/********************************************//**
 *  Exercise 7.15
 *
 *  Add appropriate constructors to your Person class.
 ***********************************************/
void ExerciseNum15 (void)
{
    // Check Person.h
}

/********************************************//**
 *  Exercise 7.16
 *
 *  What, if any, are the constraints on where and how often an access specifier may appear inside a class definition?
 *  What kinds of members should be defined after a public specifier?
 *  What kinds should be private?
 ***********************************************/
void ExerciseNum16 (void)
{
    // An access specifier can appear anywhere in the class definition and as many times as the programmer wants.
    // Members that should be defined with a public specifier are those part of the interface of the class, usually function members.
    // Members that should be defined with a private specifier are those part of the implementation of the class, usually data members.
}

/********************************************//**
 *  Exercise 7.17
 *
 *  What, if any, are the differences between using class or struct?
 ***********************************************/
void ExerciseNum17 (void)
{
    // The only difference is the default access specifier, members defined in a class are by default private and when they are defined in a struct they are by default public.
}

/********************************************//**
 *  Exercise 7.18
 *
 *  What is encapsulation? Why is it useful?
 ***********************************************/
void ExerciseNum18 (void)
{
    // Encapsulation consists in hiding the implementation of a class from its interface, it is useful because it allows to have both things separated.
}

/********************************************//**
 *  Exercise 7.19
 *
 *  Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.
 ***********************************************/
void ExerciseNum19 (void)
{
    // See Person.h
}

/********************************************//**
 *  Exercise 7.20
 *
 *  When are friends useful? Discuss the pros and cons of using friends.
 ***********************************************/
void ExerciseNum20 (void)
{
    // Friends are useful when creating nonmember functions that need access to the private members of a class.
    // They provide flexibility in the interface design of a class but they might expose private members outside making the class worse in terms of encapsulation.
}

/********************************************//**
 *  Exercise 7.21
 *
 *  Update your Sales_data class to hide its implementation. The programs you've written to use Sales_data operations should still continue to work, recompile the programs with the new class definition to verify that they still work.
 ***********************************************/
void ExerciseNum21 (void)
{
    // Check Sales_data class.h
}

/********************************************//**
 *  Exercise 7.22
 *
 *  Update your Person class to hide its implementation.
 ***********************************************/
void ExerciseNum22 (void)
{
    // Check Person.h
}

/********************************************//**
 *  Exercise 7.23
 *
 *  Write your own version of the Screen class.
 ***********************************************/
void ExerciseNum23 (void)
{
    // Check Screen.h
}

/********************************************//**
 *  Exercise 7.24
 *
 *  Give your Screen class these constructors: a default constructor, a constructor that takes values for height and width and initializes the contents to hold the given number of blanks and a constructor that takes values for height, width and a character to use as the contents of the screen.
 ***********************************************/
void ExerciseNum24 (void)
{
    // Check Screen.h
}

/********************************************//**
 *  Exercise 7.25
 *
 *  Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?
 ***********************************************/
void ExerciseNum25 (void)
{
    // In our case it will because we used vectors for dynamic memory allocation and management, so the vector template will handle that.
}

/********************************************//**
 *  Exercise 7.26
 *
 *  Define Sales_data::avg_price as an inline function.
 ***********************************************/
void ExerciseNum26 (void)
{
    // Check Sales_data.h.
}

/********************************************//**
 *  Exercise 7.27
 *
 *  Add the move, set, and display operations to your version of Screen. Test your class by executing the following code:
 *    Screen myScreen(5, 5, 'X');
 *    myScreen.move(4, 0).set('#').display(cout);
 *    cout << "\n";
 *    myScreen.display(cout);
 *    cout << "\n";
 ***********************************************/
void ExerciseNum27 (void)
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
}

/********************************************//**
 *  Exercise 7.28
 *
 *  What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?
 ***********************************************/
void ExerciseNum28 (void)
{
    // That we would be returning a temporary copy of the object instead of a reference to the object, which means that changes won't be reflected in the original object but in the temporary copy.
    // Basically the results of display will be different.
}

/********************************************//**
 *  Exercise 7.29
 *
 *  Revise your Screen class so that move, set, and display return Screen and check your prediction from the previous exercise.
 ***********************************************/
void ExerciseNum29 (void)
{
    // Replacing it shows that the conclusion in exercise 7.28 is correct.
}

/********************************************//**
 *  Exercise 7.30
 *
 *  It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.
 ***********************************************/
void ExerciseNum30 (void)
{
    // I find it better to explicitly use this as it is more clear for a potential maintainer what that variable is referring to, on the other hand it is redundant and can be omitted.
}

/********************************************//**
 *  Exercise 7.31
 *
 *  Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.
 ***********************************************/
void ExerciseNum31 (void)
{
    // Check XY.h
}

/********************************************//**
 *  Exercise 7.32
 *
 *  Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen.
 ***********************************************/
void ExerciseNum32 (void)
{
    // I find easier to make the whole class a friend and then use what is necessary, because I need the full definition of screen in window manager class.
    // Making a member function a friend requires too many interdependencies for my liking.
    Window_mgr manager(2);

    manager.display(std::cout);
    manager.clear();
    manager.display(std::cout);
}

/********************************************//**
 *  Exercise 7.33
 *
 *  Given the following class:
 *    class Screen
 *    {
 *        public:
 *            typedef std::string::size_type pos;
 *            pos Screen::size() const;
 *        private:
 *            pos height = 0, width = 0;
 *    };
 *  What would happen if we gave Screen a size member defined as follows? Fix any problems you identify:
 *    pos Screen::size() const
 *    {
 *        return height * width;
 *    }
 ***********************************************/
class e33_Screen
{
public:
    typedef std::string::size_type pos;

    pos size() const;
private:
    pos height = 0, width = 0;
};
// This is the proper definition.
e33_Screen::pos e33_Screen::size() const
{
    return height * width;
}

void ExerciseNum33 (void)
{
    // See above.
}

/********************************************//**
 *  Exercise 7.34
 *
 *  What would happen if we put the typedef of pos in the Screen class definition below at the last line in the class?
 *
 *  class Screen
 *  {
 *     public:
 *       typedef std::string::size_type pos;
 *       void dummy_fcn(pos height) { cursor = width * height; }
 *     private:
 *       pos cursor = 0;
 *       pos height = 0, width = 0;
 *  };
 ***********************************************/
void ExerciseNum34 (void)
{
    // What would happen is that the compiler would not see the definition of pos when it is used in dummy_fcn, and it will fail to compile.
}

/********************************************//**
 *  Exercise 7.35
 *
 *  Explain the following code, indicating which definition of Type or initVal is used for each use of these names. Say how you would fix any errors.
 *
 *  typedef string Type;
 *  Type initVal();
 *  class Exercise
 *  {
 *    public:
 *      typedef double Type;
 *      Type setVal(Type);
 *      Type initVal();
 *    private:
 *      int val;
 *  };
 *
 *  Type Exercise::setVal(Type parm)
 *  {
 *    val = parm + initVal();
 *    return val;
 *  }
 ***********************************************/
void ExerciseNum35 (void)
{
    // Type initVal(): string type.
    // Type setVal(Type): double type.
    // Type initVal(): double type.
    // Type Exercise::setVal(Type parm): return type is string, parameter type is double.
    // val = parm + initVal(): Member function, data member.

    // This is the fixed version:
//    class Exercise
//    {
//        public:
//            typedef double Type;
//            Type setVal(Type);
//            // This needs to be defined...
//            Type initVal();
//        private:
//            Type val;
//    };
//
//    Exercise::Type Exercise::setVal(Type parm)
//    {
//        val = parm + initVal();
//        return val;
//    }
}

/********************************************//**
 *  Exercise 7.36
 *
 *  The following initializer is in error. Identify and fix the problem.
 *    struct X
 *    {
 *        X(int i, int j) : base(i), rem(base % j) { }
 *        int rem, base;
 *    }
 ***********************************************/
void ExerciseNum36 (void)
{
    // This is the fix, do not initialize parameters from other parameters.
    // X(int i, int j) : base(i), rem(i % j) { }
}

/********************************************//**
 *  Exercise 7.37
 *
 *  Using the version of Sales_data below:
 *    class Sales_data
 *    {
 *        public:
 *            Sales_data(void) = default;
 *            Sales_data(std::string s = "") : bookNo(s) { }
 *            Sales_data(std::string s, unsigned cnt, double rev) : bookNo(s), units_sold(cnt), revenue(rev * cnt) { }
 *            Sales_data(std::istream &is) { read(is, *this); }
 *        private:
 *            std::string bookNo;
 *            unsigned cnt;
 *            double revenue;
 *    };
 *  Determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:
 *    Sales_data first_item(cin);
 *    int main()
 *    {
 *        Sales_data next;
 *        Sales_data last("9-999-99999-9");
 *    }
 ***********************************************/
void ExerciseNum37()
{
    // Sales_data first_item(cin) = Fourth constructor.
    // Sales_data next = Default constructor, first constructor.
    // Sales_data last("9-999-99999-9") = Second constructor.
}

/********************************************//**
 *  Exercise 7.38
 *
 *  We might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.
 ***********************************************/
class e38_Sales_data
{
    public:
        e38_Sales_data(void) = default;
        e38_Sales_data(std::string s = "") : bookNo(s) { }
        e38_Sales_data(std::string s, unsigned cnt, double rev) : bookNo(s), units_sold(cnt), revenue(rev * cnt) { }
        e38_Sales_data(std::istream &is = std::cin) { }
    private:
        std::string bookNo;
        unsigned units_sold;
        double revenue;
};

void ExerciseNum38()
{
    // See above.
}

/********************************************//**
 *  Exercise 7.39
 *
 *  Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?
 ***********************************************/
void ExerciseNum39()
{
    // As we have seen in the previous example, yes it is possible.
}

/********************************************//**
 *  Exercise 7.40
 *
 *  Determine what data is needed for the following class: Vehicle, provide an appropiate set of constructors.
 ***********************************************/
class e40_Vehicle
{
public:
    using vehicleType = enum { car = 0, bike, truck, bus };
    using tiresSize = enum { two = 0, four = 1, eight = 2};

    e40_Vehicle(const vehicleType vht, const tiresSize trs) : vehicle(vht), tiresCount(trs), acceleration(5), decceleration(10) { currentSpeed = 0; }
    e40_Vehicle(const vehicleType vht, const tiresSize trs, const unsigned int accel, const unsigned int deccel) : vehicle(vht), tiresCount(trs), acceleration(accel), decceleration(deccel) { currentSpeed = 0; }

    inline e40_Vehicle &accelerate(void) { currentSpeed = currentSpeed + acceleration; }
    inline e40_Vehicle &deccelrate(void) { currentSpeed = currentSpeed - decceleration; }
    inline unsigned int getSpeed(void) { return currentSpeed; }
private:
    const vehicleType vehicle;
    const tiresSize tiresCount;
    unsigned int currentSpeed;
    const unsigned int acceleration;
    const unsigned int decceleration;
};

void ExerciseNum40()
{
    // The class above is a simple example.
}

/********************************************//**
 *  Exercise 7.41
 *
 *  Write a class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed.
 *  Write declarations to construct an instance of your class object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.
 ***********************************************/
void ExerciseNum41()
{

}

/********************************************//**
 *  Exercise 7.42
 *
 *  For the class you wrote for Exercise 7.40, decide whether any of the constructors might use delegation.
 *  If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor.
 *  Write the class definition for that abstraction.
 ***********************************************/
void ExerciseNum42()
{

}

/********************************************//**
 *  Exercise 7.43
 *
 *  Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor.
 *  Define a class C that has a member of type NoDefault. Define the default constructor for C.
 ***********************************************/
void ExerciseNum43()
{

}

/********************************************//**
 *  Exercise 7.44
 *
 *  Is the following declaration legal? If not, why not?
 *    vector<NoDefault> vec(10);
 ***********************************************/
void ExerciseNum44()
{

}

/********************************************//**
 *  Exercise 7.45
 *
 *  What if we defined the vector in the previous exercise to hold objects of type C?
 ***********************************************/
void ExerciseNum45()
{

}

/********************************************//**
 *  Exercise 7.46
 *
 *  Which, if any, of the following statements are untrue? Why?
 *    a) A class must provide at least one constructor.
 *    b) A default constructor is a constructor with an empty parameter list.
 *    c) If there are no meaningful default values for a class, the class should not provide a default constructor.
 *    d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.
 ***********************************************/
void ExerciseNum46()
{

}

/********************************************//**
 *  Exercise 7.47
 *
 *  Explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?
 ***********************************************/
void ExerciseNum47()
{

}

/********************************************//**
 *  Exercise 7.48
 *
 *  Considering the following Sales_data class:
 *    class Sales_data
 *    {
 *        public:
 *            Sales_data() = default;
 *            Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { }
 *            explicit Sales_data(const std::string &s) : bookNo(s) { }
 *            explicit Sales_data(std::istream&);
 *        private:
 *            ...
 *    };
 *  Assuming that the constructors are not explicit, what operations happen during the following definitions:
 *    string null_isbn("0-000-00000-0");
 *
 *    Sales_data item1(null_isbn);
 *    Sales_data item2("0-000-00000-0");
 *  What happens if the Sales_data constructors are explicit?
 ***********************************************/
void ExerciseNum48()
{

}

/********************************************//**
 *  Exercise 7.49
 *
 *  For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a Sales_data and s is a string:
 *    a) Sales_data &combine(Sales_data);
 *    b) Sales_data &combine(Sales_data&);
 *    c) Sales_data &combine(const Sales_data&) const;
 ***********************************************/
void ExerciseNum49()
{

}

/********************************************//**
 *  Exercise 7.50
 *
 *  Determine whether any of your Person class constructors should be explicit.
 ***********************************************/
void ExerciseNum50()
{

}

/********************************************//**
 *  Exercise 7.51
 *
 *  Why do you think vector defines its single-argument constructor as explicit but string does not?
 ***********************************************/
void ExerciseNum51()
{

}

/********************************************//**
 *  Exercise 7.52
 *
 *  Using the following Sales_data class:
 *    struct Sales_data
 *    {
 *        std::string bookNo;
 *        unsigned int units_sold = 0;
 *        double revenue = 0.0;
 *    };
 *  Explain the following initialization. Identify and fix any problems.
 *    Sales_data item = {"978-0000000000", 25, 15.99};
 ***********************************************/
void ExerciseNum52()
{

}

/********************************************//**
 *  Exercise 7.53
 *
 *  Define your own version of Debug.
 ***********************************************/
void ExerciseNum53()
{

}

/********************************************//**
 *  Exercise 7.54
 *
 *  Should the members of Debug that begin with set_ be declared as constexpr? If not, why not? See the debug class below:
 *    class Debug
 *    {
 *        public:
 *            constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
 *            constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
 *            constexpr bool any() { return hw || io || other; }
 *            void set_io(bool b) { io = b; }
 *            void set_hw(bool b) { hw = b; }
 *            void set_other(bool b) { hw = b; }
 *        private:
 *            bool hw, io, other;
 *    };
 ***********************************************/
void ExerciseNum54()
{
    // There is an assignment and therefore they can't be constexpr functions.
}

/********************************************//**
 *  Exercise 7.55
 *
 *  Is the Data class below a literal class?
 *    struct Data
 *    {
 *        int ival;
 *        string s;
 *    };
 *  If not, why not? If so, explain why it is literal.
 ***********************************************/
void ExerciseNum55()
{
    // It is not of literal type as its data members are not of literal type.
}

/********************************************//**
 *  Exercise 7.56
 *
 *  What is a static class member? What are the advantages of static members? How do they differ from ordinary members.
 ***********************************************/
void ExerciseNum56()
{
    // Static members are associated to the class and it is shared among all the instances of that class.
    // Static members can have the same type as the class or any other incomplete type among other things.
}

/********************************************//**
 *  Exercise 7.57
 *
 *  Write your own version of the Account class.
 ***********************************************/
class e757_Account
{
public:
    e757_Account(void) = default;
    e757_Account(std::string oName, double initAm, double initInterestRate) : owner_name(oName), ammount(initAm) { setInterestRate(initInterestRate); }

    e757_Account &calculate(void) { ammount += ammount * interestRate; }
    double getAmmount() { return ammount; }
    static void setInterestRate(double nr);

private:
    std::string owner_name;
    double ammount = 0;
    static double interestRate;
    static double getInterestRate(void);
};

double e757_Account::interestRate = 0;
double e757_Account::getInterestRate(void)
{
    return interestRate;
}

void e757_Account::setInterestRate(double nr)
{
    interestRate = nr;
}

void ExerciseNum57()
{
    // See above.
}

/********************************************//**
 *  Exercise 7.58
 *
 *  Which, if any, of the following static data member declarations and definitions are errors? Explain why.
 *
 *  // example.h
 *  class Example
 *  {
 *    public:
 *      static double rate = 6.5;
 *      static const int vecSize = 20;
 *      static vector<double> vec(vecSize);
 *  };
 *  // example.c
 *  #include "example.h"
 *  double Example::rate;
 *  vector<double> Example::vec;
 ***********************************************/
// example.h
class e758_Example
{
    public:
        static double rate;
        static const int vecSize = 20;
        static std::vector<double> vec;
};
// example.c
double e758_Example::rate = 6.5;
std::vector<double> e758_Example::vec(e758_Example::vecSize);

void ExerciseNum58()
{
    // rate has to be initialized outside the class body, fixes above.
    // vec has to be initialized outside the class body, fixes above.
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

