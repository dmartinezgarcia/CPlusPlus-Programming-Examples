// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 45;

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
    ExerciseNum45
};

#include <stdio.h>

#include <cstring>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

/********************************************//**
 *  Exercise 3.1
 *
 *  Rewrite the exercises 1.9, 1.10, 1.11 with appropriate using declarations.
 ***********************************************/
void ExerciseNum1 (void)
{
    using std::cout;
    using std::endl;
    using std::cin;
    int sum, i, a;

    // Exercise 1.9
    sum = 0, i = 50;
    while (i <= 100)
    {
        sum += i++;
    }
    cout << "Total sum: " << sum << endl;

    // Exercise 1.10
    i = 10;
    while (i != 0)
    {
        cout << i-- << "\r";
    }
    cout << endl;

    // Exercise 1.11
    cin >> i >> a;
    while (++i < a)
    {
        cout << i << " ";
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.2
 *
 *  Write a program to read the standard input a line at a time. Modify your program to read a word at a time.
 ***********************************************/
void ExerciseNum2 (void)
{
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::getline;

    string s0;

    // Read by word.
    cout << "Whatever you type, the words will be read and printed back, type \"continue\" to exit" << endl;
    while ((cin >> s0) && (s0 != "continue"))
    {
        cout << s0 << endl;
    }

    // Read by line.
    cout << "Now whatever you type, lines will be read and printed back." << endl;
    while (getline(cin, s0))
    {
        cout << s0 << endl;
    }
}

/********************************************//**
 *  Exercise 3.3
 *
 *  Explain how whitespace characters are handled in the string input operator and in the getline function.
 ***********************************************/
void ExerciseNum3 (void)
{
    // Please check the previous exercise to find out.
}

/********************************************//**
 *  Exercise 3.4
 *
 *  Write a program to read two strings and report whether the strings are equal.
 *  If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.
 ***********************************************/
void ExerciseNum4 (void)
{
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::getline;

    string s0, s1;

    cout << "Please type the first string." << endl;
    getline(cin, s0);
    cout << "Please type the second string." << endl;
    getline(cin, s1);

    if (s0 == s1)
    {
        cout << "Both strings are equal.";
    }
    else if (s0 < s1)
    {
        cout << "The second string is larger than the first one.";
    }
    else
    {
        cout << "The first string is larger that the second one.";
    }
    cout << endl;

    if (s0.size() == s1.size())
    {
        cout << "Both strings have the same length.";
    }
    else if (s0.size() < s1.size())
    {
        cout << "The second string is longer than the first one.";
    }
    else
    {
        cout << "The first string is longer than the second one.";
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.5
 *
 *  Write a program to read strings from the standard input, concatenating what is read into one large string.
 *  Print the concatenated string. Next, change the program to separate adjacent input strings by a space.
 ***********************************************/
void ExerciseNum5 (void)
{
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::getline;

    string s0, s1;

    cout << "Type strings, they will be concatenated (separated by spaces) and then printed back to you." << endl;
    while (getline(cin, s0))
    {
        if (!s1.empty())
        {
            s1 += " ";
        }
        s1 += s0;
    }
    cout << endl << "The concatenated string is the following: " << endl;
    cout << s1 << endl;
}

/********************************************//**
 *  Exercise 3.6
 *
 *  Use a range for to change all the characters in a string to X.
 ***********************************************/
void ExerciseNum6 (void)
{
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::getline;

    string s0;

    cout << "Type a string, all its characters will be replaced by \'X\'." << endl;
    getline(cin, s0);

    for (auto &chr : s0)
    {
        chr = 'X';
    }
    cout << "This is your string now: " << s0 << endl;
}

/********************************************//**
 *  Exercise 3.7
 *
 *  What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.
 ***********************************************/
void ExerciseNum7 (void)
{
    // It will happen the same, however it's not the correct type to access this string.
    // The correct type is the return type of size().
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::getline;

    string s0;

    cout << "Type a string, all its characters will be replaced by \'X\'." << endl;
    getline(cin, s0);

    for (char &chr : s0)
    {
        chr = 'X';
    }
    cout << "This is your string now: " << s0 << endl;
}

/********************************************//**
 *  Exercise 3.8
 *
 *  Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?
 ***********************************************/
void ExerciseNum8 (void)
{
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::getline;

    string s0, s1;
    decltype(s0.size()) i = 0;

    cout << "Type a string, all its characters will be replaced by \'X\'." << endl;
    getline(cin, s0);
    s1 = s0;

    while (i < s0.size())
    {
        s0[i++] = 'X';
    }

    cout << "This is your string now (while loop): " << s0 << endl;
    s0 = s1;

    for (i = 0; i < s0.size(); i++)
    {
        s0[i] = 'X';
    }

    cout << "This is your string now (for loop): " << s0 << endl;
}

/********************************************//**
 *  Exercise 3.9
 *
 *  What does the following program do? Is it valid? If not, why not?
 *
 *  string s;
 *  cout << s[0] << endl;
 ***********************************************/
void ExerciseNum9 (void)
{
    // It is not valid, because it's trying to access members of an empty sequence, and therefore behaviour is undefined.
}

/********************************************//**
 *  Exercise 3.10
 *
 *  Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.
 ***********************************************/
void ExerciseNum10 (void)
{
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    string s0;

    cout << "Write a string with punctuation, a new string with the punctuation removed will be printed." << endl;
    getline(cin, s0);
    for (auto &i : s0)
    {
        if (!ispunct(i))
        {
            cout << i;
        }
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.11
 *
 *  Is the following range for legal? If so, what is the type of c?
 *
 *  const string c = "Keep out!";
 *  for (auto &c : s) {  }
 ***********************************************/
void ExerciseNum11 (void)
{
    // It is valid, and the type of &c is reference to const char. (const char &).
    using std::string;
    using std::endl;
    using std::cout;

    const string s = "Keep out!";

    for (auto &c : s)
    {
        cout << c;
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.12
 *
 *  Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
 *
 *  a) vector<vector<int>> ivec;
 *  b) vector<string> svec = ivec;
 *  c) vector<string> svec(10, "null");
 ***********************************************/
void ExerciseNum12 (void)
{
    using std::vector;
    using std::string;

    // Legal, vector of vector of integers.
    vector<vector<int>> ivec;
    // Not legal, vector of strings initialized from vector of integers.
    //vector<string> svec = ivec;
    // Legal, vector of ten "null" elements.
    vector<string> svec(10, "null");
}

/********************************************//**
 *  Exercise 3.13
 *
 *  How many elements are there in each of the following vectors? What are the values of the elements?
 *
 *  a) vector<int> v1;
 *  b) vector<int> v2(10);
 *  c) vector<int> v3(10, 42);
 *  d) vector<int> v4{10};
 *  e) vector<int> v5{10, 42};
 *  f) vector<string> v6{10};
 *  g) vector<string> v7{10, "hi"};
 ***********************************************/
void ExerciseNum13 (void)
{
    using std::vector;
    using std::string;
    using std::cout;
    using std::endl;

    // No elements.
    vector<int> v1;

    cout << "This are the elements in v1: " << endl;
    cout << "Elements: " << v1.size() << endl;
    for (auto &c : v1)
        cout << c << ' ';
    cout << endl;

    // Ten elements initialized to zero.
    vector<int> v2(10);

    cout << "This are the elements in v2: " << endl;
    cout << "Elements: " << v2.size() << endl;
    for (auto &c : v2)
        cout << c << ' ';
    cout << endl;

    // Ten elements initialized to 42.
    vector<int> v3(10, 42);

    cout << "This are the elements in v3: " << endl;
    cout << "Elements: " << v3.size() << endl;
    for (auto &c : v3)
        cout << c << ' ';
    cout << endl;

    // One element initialized to 10.
    vector<int> v4 {10};

    cout << "This are the elements in v4: " << endl;
    cout << "Elements: " << v4.size() << endl;
    for (auto &c : v4)
        cout << c << ' ';
    cout << endl;

    // Two elements initialized to 10 and 42.
    vector<int> v5 {10, 42};

    cout << "This are the elements in v5: " << endl;
    cout << "Elements: " << v5.size() << endl;
    for (auto &c : v5)
        cout << c << ' ';
    cout << endl;

    // Wrong initialization, will compile same as v6(10).
    vector<string> v6 {10};

    cout << "This are the elements in v6: " << endl;
    cout << "Elements: " << v6.size() << endl;
    for (auto &c : v6)
        cout << c << ' ';
    cout << endl;

    // Wrong initialization, will compile same as v7(10, "hi").
    vector<string> v7 {10, "hi"};

    cout << "This are the elements in v7: " << endl;
    cout << "Elements: " << v7.size() << endl;
    for (auto &c : v7)
        cout << c << ' ';
    cout << endl;
}

/********************************************//**
 *  Exercise 3.14
 *
 *  Write a program to read a sequence of ints from cin and store those values in a vector.
 ***********************************************/
void ExerciseNum14 (void)
{
    using std::vector;
    using std::endl;
    using std::cout;
    using std::cin;

    vector<int> v1;
    int a;

    cout << "Please type integer values to add to the vector." << endl;
    while (cin >> a)
    {
        v1.push_back(a);
    }

    for (auto &i : v1)
    {
        cout << i << ' ';
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.15
 *
 *  Repeat the previous program but read strings this time.
 ***********************************************/
void ExerciseNum15 (void)
{
    using std::vector;
    using std::string;
    using std::endl;
    using std::cout;
    using std::cin;

    vector<string> v1;
    string a;

    cout << "Please type strings to add to the vector." << endl;
    while (getline(cin, a))
    {
        v1.push_back(a);
    }

    for (auto &i : v1)
    {
        cout << i << ' ';
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.16
 *
 *  Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct.
 ***********************************************/
void ExerciseNum16 (void)
{
    // Already done this in exercise 3.13 itself.
}

/********************************************//**
 *  Exercise 3.17
 *
 *  Read a sequence of words from cin and store the values a vector. After you've read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.
 ***********************************************/
void ExerciseNum17 (void)
{
    using std::string;
    using std::vector;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<string> v1;
    unsigned char i = 0;

    cout << "Please type as many words as you wish, they will be converted to uppercase and printed back." << endl;
    for (string a; cin >> a; )
    {
        v1.push_back(a);
    }

    for (auto &a : v1)
    {
        for (auto &c : a)
        {
            if (!isupper(c))
            {
                c = toupper(c);
            }
        }

        cout << a << ' ';
        if (++i == 8)
        {
            cout << endl;
            i = 0;
        }
    }
}

/********************************************//**
 *  Exercise 3.18
 *
 *  Is the following program legal? If not, how might you fix it?
 *
 *  vector<int> ivec;
 *  ivec[0] = 42;
 ***********************************************/
void ExerciseNum18 (void)
{
    // ivec is empty, and the behaviour of subscripting it will be undefined, however it is compile-able.
    using std::vector;

    vector<int> ivec;
    ivec[0] = 42;
}

/********************************************//**
 *  Exercise 3.19
 *
 *  List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.
 ***********************************************/
void ExerciseNum19 (void)
{
    // This three ways are possible.
    using std::vector;

    vector<int> v1(10, 42); // This is the preferred one, which is obvious why.
    vector<int> v2 {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> v3 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
}

/********************************************//**
 *  Exercise 3.20
 *
 *  Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
 ***********************************************/
void ExerciseNum20 (void)
{
    using std::vector;
    using std::cout;
    using std::cin;
    using std::endl;

    vector<int> v1;

    cout << "Please type integers." << endl;
    for (int a; cin >> a; )
    {
        v1.push_back(a);
    }

    cout << "There are in total " << v1.size() << endl;

    // First part.
    cout << "The sum of each pair of adjacent elements is displayed." << endl;
    for (vector<int>::size_type a = 0; (a + 1) < v1.size(); a += 2)
    {
        cout << "The sum of pair n" << ((a > 0) ? a - 1 : a) << " is : ";
        cout << v1[a] + v1[a + 1] << ".";
        cout << endl;
    }
    cout << endl;

    // Second part.
    cout << "The first and last numbers sum, the second-first and second-last numbers sum, and so on..." << endl;
    for (vector<int>::size_type a = 0; a < (v1.size() / 2); a++)
    {
        cout << "The sum of pair n" << a << " is : ";
        cout << v1[a] + v1[v1.size() - 1 - a] << ".";
        cout << endl;
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.21
 *
 *  Redo exercise 3.16 with iterators.
 ***********************************************/
void ExerciseNum21 (void)
{
    using std::vector;
    using std::string;
    using std::cout;
    using std::endl;

    vector<int>::iterator b_i, e_i;
    vector<string>::iterator b_s, e_s;

    // No elements.
    vector<int> v1;

    cout << "This are the elements in v1: " << endl;
    cout << "Elements: " << v1.size() << endl;
    for (b_i = v1.begin(), e_i = v1.end(); b_i != e_i; b_i++)
        cout << *b_i << ' ';
    cout << endl;

    // Ten elements initialized to zero.
    vector<int> v2(10);

    cout << "This are the elements in v2: " << endl;
    cout << "Elements: " << v2.size() << endl;
    for (b_i = v2.begin(), e_i = v2.end(); b_i != e_i; b_i++)
        cout << *b_i << ' ';
    cout << endl;

    // Ten elements initialized to 42.
    vector<int> v3(10, 42);

    cout << "This are the elements in v3: " << endl;
    cout << "Elements: " << v3.size() << endl;
    for (b_i = v3.begin(), e_i = v3.end(); b_i != e_i; b_i++)
        cout << *b_i << ' ';
    cout << endl;

    // One element initialized to 10.
    vector<int> v4 {10};

    cout << "This are the elements in v4: " << endl;
    cout << "Elements: " << v4.size() << endl;
    for (b_i = v4.begin(), e_i = v4.end(); b_i != e_i; b_i++)
        cout << *b_i << ' ';
    cout << endl;

    // Two elements initialized to 10 and 42.
    vector<int> v5 {10, 42};

    cout << "This are the elements in v5: " << endl;
    cout << "Elements: " << v5.size() << endl;
    for (b_i = v5.begin(), e_i = v5.end(); b_i != e_i; b_i++)
        cout << *b_i << ' ';
    cout << endl;

    // Wrong initialization, will compile same as v6(10).
    vector<string> v6 {10};

    cout << "This are the elements in v6: " << endl;
    cout << "Elements: " << v6.size() << endl;
    for (b_s = v6.begin(), e_s = v6.end(); b_s != e_s; b_s++)
        cout << *b_s << ' ';
    cout << endl;

    // Wrong initialization, will compile same as v7(10, "hi").
    vector<string> v7 {10, "hi"};

    cout << "This are the elements in v7: " << endl;
    cout << "Elements: " << v7.size() << endl;
    for (b_s = v7.begin(), e_s = v7.end(); b_s != e_s; b_s++)
        cout << *b_s << ' ';
    cout << endl;
}

/********************************************//**
 *  Exercise 3.22
 *
 *  Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you've updated text, print its contents.
 *
 *  // Print each line in text up to the first blank line.
 *  for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
 *      cout << *it << endl;
 ***********************************************/
void ExerciseNum22 (void)
{
    using std::cout;
    using std::string;
    using std::endl;
    using std::vector;

    vector<string> txt = {"\n", "This is the first paragraph.", "\n", "This is the second paragraph", "\n", "This is the third paragraph"};

    for (auto it = txt.begin(); it != txt.end() && !it->empty(); ++it)
    {
        if (*it != "\n")
        {
            for (auto &c : *it)
            {
                c = toupper(c);
            }
            break;
        }
    }

    for (auto &a : txt)
    {
        cout << a << endl;
    }
}

/********************************************//**
 *  Exercise 3.23
 *
 *  Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice the current value. Test your program by printing the vector.
 ***********************************************/
void ExerciseNum23 (void)
{
    using std::vector;
    using std::cout;
    using std::endl;

    vector<int> data {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "These are the original elements: " << endl;
    for (auto db = data.begin(), de = data.end(); db != de; db++)
    {
        cout << *db << ' ';
        *db *= 2;
    }
    cout << endl;

    cout << "These are the updated elements: " << endl;
    for (auto dbc = data.cbegin(), dec = data.cend(); dbc != dec; dbc++)
    {
        cout << *dbc << ' ';
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.24
 *
 *  Redo exercise 3.20 using iterators.
 ***********************************************/
void ExerciseNum24 (void)
{
    using std::vector;
    using std::cout;
    using std::cin;
    using std::endl;

    vector<int> v1;

    cout << "Please type integers." << endl;
    for (int a; cin >> a; )
    {
        v1.push_back(a);
    }

    cout << "There are in total " << v1.size() << endl;

    // First part.
    cout << "The sum of each pair of adjacent elements is displayed." << endl;
    for (auto b = v1.cbegin(), e = v1.cend(), bc = v1.cbegin(); (b + 1) < e; b += 2)
    {
        cout << "The sum of pair n" << (((b - bc) > 0) ? ((b - bc) / 2) : 0) << " is : ";
        cout << *b + *(b + 1) << ".";
        cout << endl;
    }
    cout << endl;

    // Second part.
    cout << "The first and last numbers sum, the second-first and second-last numbers sum, and so on..." << endl;
    for (auto b = v1.cbegin(), e = v1.cend(), bc = v1.cbegin(); b != (bc + (v1.size() / 2)); b++, e--)
    {
        cout << "The sum of pair n" << (b - bc) << " is : ";
        cout << *b + *(e - 1) << ".";
        cout << endl;
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.25
 *
 *  Rewrite the following program using iterators instead of subscripts.
 *
 *      vector<unsigned> scores(11, 0);
 *      unsigned grade;
 *      while (cin >> grade)
 *      {
 *          if (grade <= 100)
 *          {
 *              ++scores[grade/10];
 *          }
 *      }
 ***********************************************/
void ExerciseNum25 (void)
{
    using std::vector;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<int> scores(11, 0);
    int grade = 0;

    while (cin >> grade)
    {
        if (grade <= 100)
        {
            (*(scores.begin() + (grade / 10)))++;
        }
    }

    cout << "This are then number of grades (0 to 100) in units of 10: " << endl;
    for (auto &val : scores)
    {
        cout << "Score: " << val << endl;
    }
}

/********************************************//**
 *  Exercise 3.26
 *
 *  In the binary search program below, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) / 2;`.
 *
 *      auto beg = text.begin(), end = text.end();
 *      auto mid = text.begin() + (end - beg) / 2;
 *      while (mid != end && *mid != sought)
 *      {
 *          if (sought < *mid)
 *          {
 *              end = mid;
 *          }
 *          else
 *          {
 *              beg = mid + 1;
 *          }
 *          mid = beg + (end - beg) / 2;
 *      }
 ***********************************************/
void ExerciseNum26 (void)
{
    // Because the addition of two iterators is undefined, (I guess it can create a very large value that can overflow).
    // What the first operation really does is add an integer to an iterator.
}

/********************************************//**
 *  Exercise 3.27
 *
 *  Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.
 *
 *      unsigned buf_size = 1024;
 *      a) int ia[buf_size];
 *      b) int ia[4 * 7 - 14];
 *      c) int ia[txt_size()];
 *      d) char st[11] = "fundamental";
 ***********************************************/
int txt_size(void)
{
    return 20;
}
void ExerciseNum27 (void)
{
    unsigned int buf_size = 1024;

    // Invalid, because buf_size is not a constant expression, however it seems to pass for some reason, probably compiler extension or something.
    //int ia[buf_size];
    // Valid, because it is a constant expression.
    int ia_1[4 * 7 - 14];
    // Invalid, because the function doesn't return a constant expression, it seems to pass though but it shouldn't, maybe compiler extension or something.
    //int ia_2[txt_size()];
    // Invalid, not enough space for the NULL terminator, should be 12 instead of 11.
    //char st[11] = "fundamental";
}

/********************************************//**
 *  Exercise 3.28
 *
 *  What are the values in the following arrays?
 *
 *      string sa[10];
 *      int ia[10];
 *      int main()
 *      {
 *          string sa2[10];
 *          int ia2[10];
 *      }
 ***********************************************/
std::string sa[10];
int ia[10];
void ExerciseNum28 (void)
{
    using std::cout;
    using std::endl;
    using std::string;

    string sa2[10];
    int ia2[10];

    // ia will be all zeros.
    // ia2 will be garbage.
    // sa will be the empty string ten times.
    // sa2 will be the empty string ten times.
    cout << "Values in sa: " << endl;
    for (auto &a : sa)
    {
        cout << a << ' ';
    }
    cout << endl;

    cout << "Values in ia: " << endl;
    for (auto &a : ia)
    {
        cout << a << ' ';
    }
    cout << endl;

    cout << "Values in sa2: " << endl;
    for (auto &a : sa2)
    {
        cout << a << ' ';
    }
    cout << endl;

    cout << "Values in ia2: " << endl;
    for (auto &a : ia2)
    {
        cout << a << ' ';
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.29
 *
 *  List some of the drawbacks of using an array instead of a vector.
 ***********************************************/
void ExerciseNum29 (void)
{
    // Arrays are error prone, must have fixed sizes, should only be used when we know the amount of data we are going to handle.
    // Arrays are inherited from C.
}

/********************************************//**
 *  Exercise 3.30
 *
 *  Identify the indexing errors in the following code:
 *
 *      constexpr size_t array_size = 10;
 *      int ia[array_size];
 *      for (size_t ix = 1; ix <= array_size; ++ix)
 *      {
 *          ia[ix] = ix;
 *      }
 ***********************************************/
void ExerciseNum30 (void)
{
    constexpr size_t array_size = 10;
    int ia[array_size];

    for (size_t ix = 1; ix <= array_size; ++ix)
    {
        ia[ix - 1] = ix;
    }
}

/********************************************//**
 *  Exercise 3.31
 *
 *  Write a program to define an array of ten ints. Give each element the same value as its position in the array.
 ***********************************************/
void ExerciseNum31 (void)
{
    int my_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
}

/********************************************//**
 *  Exercise 3.32
 *
 *  Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.
 ***********************************************/
void ExerciseNum32 (void)
{
    using std::vector;

    int my_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int my_array_2[10];

    // Could also use memcpy, but whatever.
    for (char a = 0; a < (sizeof(my_array) / sizeof(*my_array)); a++)
    {
        my_array_2[a] = my_array[a];
    }

    // Rewrite with vectors.
    vector<int> v1 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2 = v1;
}

/********************************************//**
 *  Exercise 3.33
 *
 *  What would happen if we did not initialize the scores array in this program:
 *
 *      unsigned int scores[11] = {};
 *      unsigned grade;
 *      while (cin >> grade)
 *      {
 *          if (grade <= 100)
 *          {
 *              ++scores[grade/10];
 *          }
 *      }
 ***********************************************/
void ExerciseNum33 (void)
{
    // Scores would be filled with garbage, as most likely  this code would go inside a function, it needs to be initialized to zero.
}

/********************************************//**
 *  Exercise 3.34
 *
 *  Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?
 *
 *      p1 += p2 - p1;
 ***********************************************/
void ExerciseNum34 (void)
{
    // The following array advances / retreats a position equal to the distance between p2 and p1. Yes there are values that could make this illegal, those values are the ones that would make p1 an out of bounds value, when it points to non existent elements.
}

/********************************************//**
 *  Exercise 3.35
 *
 *  Using pointers, write a program to set the elements in an array to zero.
 ***********************************************/
void ExerciseNum35 (void)
{
    using std::begin;
    using std::end;

    int array_0[5] = {1, 1, 1, 1, 1};
    int *ptr_b = begin(array_0);
    int *ptr_e = end(array_0);

    while (ptr_b != ptr_e)
    {
        *ptr_b = 0;
        ptr_b++;
    }
}

/********************************************//**
 *  Exercise 3.36
 *
 *  Write a program to compare two arrays for equality. Write a similar program to compare two vectors.
 ***********************************************/
void ExerciseNum36 (void)
{
    using std::vector;
    using std::cin;
    using std::cout;
    using std::endl;

    // Compare two arrays.
    int my_array[5] = {0, 1, 2, 3, 4};
    int my_array_0[6] = {0, 1, 2, 3, 4, 5};
    bool res = true;

    if (sizeof(my_array) == sizeof(my_array_0))
    {
        for (size_t a = 0; a < (sizeof(my_array) / sizeof(*my_array)); a++)
        {
            if (my_array[a] != my_array_0[a])
            {
                res = false;
                break;
            }
        }
    }
    else
    {
        res = false;
    }

    if (res)
    {
        cout << "The arrays are equal." << endl;
    }
    else
    {
        cout << "The arrays are not equal." << endl;
    }

    // Compare two vectors.
    vector<int> my_vector {0, 1, 2, 3, 4};
    vector<int> my_vector_0 {0, 1, 2, 3, 4, 5};

    if (my_vector == my_vector_0)
    {
        cout << "The vectors are equal." << endl;
    }
    else
    {
        cout << "The vectors are not equal." << endl;
    }
}

/********************************************//**
 *  Exercise 3.37
 *
 *  What does the following program do?
 *
 *      const char ca[] = {'h', 'e', 'l', 'l', 'o'};
 *      const char *cp = ca;
 *      while (*cp)
 *      {
 *          cout << *cp << endl;
 *          ++cp;
 *      }
 ***********************************************/
void ExerciseNum37 (void)
{
    using std::cout;
    using std::endl;

    // It prints all the characters in ca, a line for each character, and then continues until it finds a \0, which basically means that it will go out of bounds.
    const char ca[] = {'h', 'e', 'l', 'l', 'o'/*FIX: , '\0'*/};
    const char *cp = ca;

    while (*cp)
    {
        cout << *cp << endl;
        ++cp;
    }
}

/********************************************//**
 *  Exercise 3.38
 *
 *  In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?
 ***********************************************/
void ExerciseNum38 (void)
{
    // Because pointers are addresses to objects, why would you add addresses? In most scenarios, it makes no sense.
}

/********************************************//**
 *  Exercise 3.39
 *
 *  Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.
 ***********************************************/
void ExerciseNum39 (void)
{
    using std::string;
    using std::cout;
    using std::endl;

    // First part.
    const char *str_0 = "This is a C-Style string.";
    const char *str_1 = "This is a C-Style string...";

    if (strcmp(str_0, str_1) == 0)
    {
        cout << "The C-Style strings are equal." << endl;
    }
    else
    {
        cout << "The C-Style strings are not equal." << endl;
    }

    // Second part.
    string s0 = "This is a C-Style string.";
    string s1 = "This is a C-Style string...";

    if (s0 == s1)
    {
        cout << "The C++-Style strings are equal." << endl;
    }
    else
    {
        cout << "The C++-Style strings are not equal." << endl;
    }
}

/********************************************//**
 *  Exercise 3.40
 *
 *  Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use strcpy and strcat to copy the two arrays into the third.
 ***********************************************/
void ExerciseNum40 (void)
{
    using std::cout;
    using std::endl;

    const char *array_0 = "01234";
    const char *array_1 = "56789";
    char array_2[11];

    strcpy(array_2, array_0);
    strcat(array_2, array_1);

    cout << array_2 << endl;
}

/********************************************//**
 *  Exercise 3.41
 *
 *  Write a program to initialize a vector from an array of ints.
 ***********************************************/
void ExerciseNum41 (void)
{
    using std::vector;
    using std::cout;
    using std::endl;
    using std::begin;
    using std::end;

    int my_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> my_vector(begin(my_array), end(my_array));

    cout << "This are the values in the vector: " << endl;
    for (auto &c : my_vector)
    {
        cout << c << ' ';
    }
    cout << endl;
}

/********************************************//**
 *  Exercise 3.42
 *
 *  Write a program to copy a vector of ints into an array of ints.
 ***********************************************/
void ExerciseNum42 (void)
{
    using std::vector;
    using std::cout;
    using std::endl;

    vector<int> my_vector {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int my_array[10];

    if ( (sizeof(my_array) / sizeof(*my_array)) == my_vector.size() )
    {
        cout << "This are the values in the array: " << endl;
        for (size_t a = 0; a < ((sizeof(my_array) / sizeof(*my_array))); a++)
        {
            my_array[a] = my_vector[a];
            cout << my_array[a] << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << "Sizes do not match, so nothing copied." << endl;
    }
}

/********************************************//**
 *  Exercise 3.43
 *
 *  Write three different versions of a program to print the elements of ia.
 *  One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers.
 *  In all three programs write all the types directly. That is, do not use a type alias, auto, or decltype to simplify the code.
 ***********************************************/
void ExerciseNum43 (void)
{
    using std::cout;
    using std::endl;
    using std::begin;
    using std::end;

    int ia[3][4] =
    {
        {0, 1, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Using a range for.
    cout << "Printing the elements using \"range for\": " << endl;
    for (int (&a)[4] : ia)
    {
        for (int &b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }

    // Using a conventional for loop with subscripts.
    cout << "Printing the elements using \"conventional for loop with subscripts\": " << endl;
    for (size_t a = 0; a < 3; a++)
    {
        for (size_t b = 0; b < 4; b++)
        {
            cout << ia[a][b] << ' ';
        }
        cout << endl;
    }

    // Using a conventional for loop with pointers.
    cout << "Printing the elements using \"conventional for loop with pointers\": " << endl;
    for (int (*a)[4] = begin(ia); a < end(ia); a++)
    {
        for (int *b = begin(*a); b < end(*a); b++)
        {
            cout << *b << ' ';
        }
        cout << endl;
    }
}

/********************************************//**
 *  Exercise 3.44
 *
 *  Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.
 ***********************************************/
void ExerciseNum44 (void)
{
    using std::cout;
    using std::endl;
    using std::begin;
    using std::end;

    using ref_to_arr4 = int (&)[4];
    using ref_to_int = int &;
    using s_op = size_t;
    using ptr_to_arr4 = int (*)[4];
    using ptr_to_int = int *;

    int ia[3][4] =
    {
        {0, 1, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Using a range for.
    cout << "Printing the elements using \"range for\": " << endl;
    for (ref_to_arr4 a : ia)
    {
        for (ref_to_int b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }

    // Using a conventional for loop with subscripts.
    cout << "Printing the elements using \"conventional for loop with subscripts\": " << endl;
    for (s_op a = 0; a < 3; a++)
    {
        for (s_op b = 0; b < 4; b++)
        {
            cout << ia[a][b] << ' ';
        }
        cout << endl;
    }

    // Using a conventional for loop with pointers.
    cout << "Printing the elements using \"conventional for loop with pointers\": " << endl;
    for (ptr_to_arr4 a = begin(ia); a < end(ia); a++)
    {
        for (ptr_to_int b = begin(*a); b < end(*a); b++)
        {
            cout << *b << ' ';
        }
        cout << endl;
    }
}

/********************************************//**
 *  Exercise 3.45
 *
 *  Rewrite the programs again, this time using auto.
 ***********************************************/
void ExerciseNum45 (void)
{
    using std::cout;
    using std::endl;
    using std::begin;
    using std::end;

    int ia[3][4] =
    {
        {0, 1, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Using a range for.
    cout << "Printing the elements using \"range for\": " << endl;
    for (auto &a : ia)
    {
        for (auto &b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }

    // Using a conventional for loop with subscripts.
    cout << "Printing the elements using \"conventional for loop with subscripts\": " << endl;
    for (auto a = 0; a < 3; a++)
    {
        for (auto b = 0; b < 4; b++)
        {
            cout << ia[a][b] << ' ';
        }
        cout << endl;
    }

    // Using a conventional for loop with pointers.
    cout << "Printing the elements using \"conventional for loop with pointers\": " << endl;
    for (auto a = begin(ia); a < end(ia); a++)
    {
        for (auto b = begin(*a); b < end(*a); b++)
        {
            cout << *b << ' ';
        }
        cout << endl;
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

