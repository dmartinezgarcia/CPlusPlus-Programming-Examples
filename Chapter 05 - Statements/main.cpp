// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 25;

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
    ExerciseNum25
};

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <stdexcept>

/********************************************//**
 *  Exercise 5.1
 *
 *  What is a null statement? When might you use a null statement?
 ***********************************************/
void ExerciseNum1 (void)
{
    // A null statement is an statement that does nothing.
    // A null statement is useful when the language requires a statement but the program logic does not.
}

/********************************************//**
 *  Exercise 5.2
 *
 *  What is a block? When might you might use a block?
 ***********************************************/
void ExerciseNum2 (void)
{
    // A block, also known as compound statement, is a series of statements inside curly braces.
    // A block is useful when the language expects a single statement and the program flow requires a sequence of statements.
}

/********************************************//**
 *  Exercise 5.3
 *
 *  Using the comma operator to rewrite the following loop so that it no longer requires a block.
 *    while (val <= 10)
 *    {
 *      sum += val;
 *      ++val;
 *    }
 *  Explain whether this rewrite improves or diminishes the readability of this code.
 ***********************************************/
void ExerciseNum3 (void)
{
    int sum = 0, val = 0;
    while (val <= 10)
    {
        sum += val;
        ++val;
    }
    std::cout << "Final sum value (original): " << sum << std::endl;
    // This makes the code worse..., it's better to use a compound statement.
    sum = val = 0;
    while (val <= 10)
        sum += val, val++;
    std::cout << "Final sum value (rewritten): " << sum << std::endl;
}

/********************************************//**
 *  Exercise 5.4
 *
 *  Explain each of the following examples, and correct any problems you detect.
 *    (a) while (string::iterator iter != s.end()) { ... }
 *    (b) while (bool status = find(word)) { ... }
 *        if (!status) { ... }
 ***********************************************/
void ExerciseNum4 (void)
{
    // The first statement is okay, the scope of the iter variable is just the body of the while loop.
    // The second statement is not okay, status was declared in the while loop and it's used afterwards in the if statement, which is out of its scope.
}

/********************************************//**
 *  Exercise 5.5
 *
 *  Using an if-else statement, write your own version of the program to generate the letter grade from a numeric grade.
 ***********************************************/
void ExerciseNum5 (void)
{
    const std::vector<std::string> letters = {"F",    // 0 to 59
                                              "D",    // 60 to 69
                                              "C",    // 70 to 79
                                              "B",    // 80 to 89
                                              "A",    // 90 to 99
                                              "A++"
                                             }; // 100
    const std::vector<char> plusminus = {'-',   // 0
                                         '-',   // 1
                                         '-',   // 2
                                         '\0',  // 3
                                         '\0',  // 4
                                         '\0',  // 5
                                         '\0',  // 6
                                         '\0',  // 7
                                         '+',   // 8
                                         '+'
                                        };  // 9
    std::string lettergrade = "";
    int grade = 0;

    // Read value.
    std::cout << "Please input a grade (0 to 100): ";
    std::cin >> grade;

    if (grade < 60)
    {
        lettergrade = letters[0];
    }
    else
    {
        lettergrade = letters[(grade - 50) / 10];
        if (grade != 100)
        {
            lettergrade += plusminus[grade % 10];
        }
    }

    std::cout << "The related grade is the following: " << lettergrade << std::endl;
}

/********************************************//**
 *  Exercise 5.6
 *
 *  Rewrite your grading program to use the conditional operator in place of the if-else statement.
 ***********************************************/
void ExerciseNum6 (void)
{
    const std::vector<std::string> letters = {"F",    // 0 to 59
                                              "D",    // 60 to 69
                                              "C",    // 70 to 79
                                              "B",    // 80 to 89
                                              "A",    // 90 to 99
                                              "A++"
                                             }; // 100
    const std::vector<char> plusminus = {'-',   // 0
                                         '-',   // 1
                                         '-',   // 2
                                         '\0',  // 3
                                         '\0',  // 4
                                         '\0',  // 5
                                         '\0',  // 6
                                         '\0',  // 7
                                         '+',   // 8
                                         '+'
                                        };  // 9
    std::string lettergrade = "";
    int grade = 0;

    // Read value.
    std::cout << "Please input a grade (0 to 100): ";
    std::cin >> grade;

    lettergrade = (grade < 60) ? (letters[0]) : (letters[(grade - 50) / 10]);
    lettergrade += (grade != 100) ? (plusminus[grade % 10]) : ('\0');

    std::cout << "The related grade is the following: " << lettergrade << std::endl;
}

/********************************************//**
 *  Exercise 5.7
 *
 *  Correct the errors in each of the following code fragments:
 *    (a) if (ival1 != ival2)
 *          ival1 = ival2
 *        else ival1 = ival2 = 0;
 *    (b) if (ival < minval)
 *          minval = ival;
 *          occurs = 1;
 *    (c) if (int ival = get_value())
 *          cout << "ival = " << ival << endl;
 *        if (!ival)
 *          cout << "ival = 0\n";
 *    (d) if (ival = 0)
 *          ival = get_value();
 ***********************************************/
void ExerciseNum7 (void)
{
    // (a)
    int a_ival1 = 0, a_ival2 = 2;

    if (a_ival1 != a_ival2)
        a_ival1 = a_ival2;
    else a_ival1 = a_ival2 = 0;

    // (b)
    int b_ival = 0, b_minval = 0, b_occurs = 0;

    if (b_ival < b_minval)
    {
        b_ival < b_minval;
        b_occurs = 1;
    }

    // (c)
    if (int c_ival = 2)
    {
        std::cout << "ival = " << c_ival << std::endl;
    }
    else
    {
        std::cout << "ival = " << c_ival << std::endl;
    }

    // (d)
    int d_ival = 0;

    if (d_ival == 0)
    {
        d_ival = 5;
    }
}

/********************************************//**
 *  Exercise 5.8
 *
 *  What is a "dangling else"? How are else clauses resolved in C++?
 ***********************************************/
void ExerciseNum8 (void)
{
    // A dangling else is for example the one below:
    // if (a)
    //   if (b)
    // else
    // A dangling else occurs when there are more if than else clauses.
    // The way this is resolved in C++ is by matching every else with the closest preceding unmatched if clause.
}

/********************************************//**
 *  Exercise 5.9
 *
 *  Write a program using a series of if statements to count the number of vowels in text read from cin.
 ***********************************************/
void ExerciseNum9 (void)
{
    std::string::iterator str_a, str_e;
    std::string word;
    int vowelCount = 0;

    do
    {
        std::cout << "Input your word: ";
        if (std::cin >> word)
        {
            str_a = word.begin();
            str_e = word.end();
            vowelCount = 0;
            while (str_a < str_e)
            {
                switch (*str_a++)
                {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowelCount++;
                    break;

                default:
                    break;
                }
            }
            std::cout << "The number of vowels in " << word << " is " << vowelCount << "." << std::endl;
        }
        else
        {
            std::cout << "Quitting..." << std::endl;
            break;
        }
    }
    while (true);
}

/********************************************//**
 *  Exercise 5.10
 *
 *  There is one problem with our vowel-counting program as we've implemented it: it doesn't count capital letters as vowels. Write a program that counts both lower - and uppercase letters as the appropriate vowel - that is, your program should count both 'a' and 'A' as part of aCnt, and so forth.
 ***********************************************/
void ExerciseNum10 (void)
{
    std::string::iterator str_a, str_e;
    std::string word;
    int vowelCount = 0;

    do
    {
        std::cout << "Input your word: ";
        if (std::cin >> word)
        {
            str_a = word.begin();
            str_e = word.end();
            vowelCount = 0;
            while (str_a < str_e)
            {
                switch (*str_a++)
                {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowelCount++;
                    break;

                default:
                    break;
                }
            }
            std::cout << "The number of vowels in " << word << " is " << vowelCount << "." << std::endl;
        }
        else
        {
            std::cout << "Quitting..." << std::endl;
            break;
        }
    }
    while (true);
}

/********************************************//**
 *  Exercise 5.11
 *
 *  Modify our vowel-counting program so that it also counts the number of blank spaces, tabs and newlines read.
 ***********************************************/
void ExerciseNum11 (void)
{
    std::string::iterator str_a, str_e;
    std::string line;
    int vowelCount = 0, spaceCount = 0, tabCount = 0, newLineCount = 0;

    do
    {
        std::cout << "Input your word: ";

        if (std::getline(std::cin, line))
        {
            str_a = line.begin();
            str_e = line.end();
            vowelCount = tabCount = spaceCount = newLineCount = 0;
            while (str_a != str_e)
            {
                switch (*str_a++)
                {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowelCount++;
                    break;

                case '\t':
                    tabCount++;
                    break;

                case ' ':
                    spaceCount++;
                    break;

                case '\n':
                    newLineCount++;
                    break;

                default:
                    break;
                }
            }
            std::cout << "The number of vowels in " << line << " is " << vowelCount << "." << std::endl;
            std::cout << "The number of tabs in " << line << " is " << tabCount << "." << std::endl;
            std::cout << "The number of spaces in " << line << " is " << spaceCount << "." << std::endl;
            std::cout << "The number of new lines in " << line << " is " << newLineCount << "." << std::endl;
        }
        else
        {
            std::cout << "Quitting..." << std::endl;
            break;
        }
    }
    while (true);
}

/********************************************//**
 *  Exercise 5.12
 *
 *  Modify our vowel-counting program so that if counts the number of occurrences of the following two-character sequences: ff, fl and fi.
 ***********************************************/
void ExerciseNum12 (void)
{
    std::string::iterator str_a, str_e;
    std::string line;
    int vowelCount = 0, spaceCount = 0, tabCount = 0, newLineCount = 0;
    bool previousf = false;
    int ffCount = 0, flCount = 0, fiCount = 0;

    do
    {
        std::cout << "Input your word: ";

        if (std::getline(std::cin, line))
        {
            str_a = line.begin();
            str_e = line.end();
            vowelCount = tabCount = spaceCount = newLineCount = 0;
            ffCount = flCount = fiCount = newLineCount = 0;
            previousf = false;
            while (str_a != str_e)
            {
                switch (*str_a++)
                {
                case 'a':
                case 'e':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowelCount++;
                    break;

                case 'i':
                    vowelCount++;
                    if (previousf == true)
                    {
                        fiCount++;
                    }
                    previousf = false;
                    break;

                case 'l':
                    if (previousf == true)
                    {
                        flCount++;
                    }
                    previousf = false;
                    break;

                case '\t':
                    tabCount++;
                    previousf = false;
                    break;

                case ' ':
                    spaceCount++;
                    previousf = false;
                    break;

                case '\n':
                    newLineCount++;
                    previousf = false;
                    break;

                case 'f':
                    if (previousf == true)
                    {
                        ffCount++;
                    }
                    previousf = true;
                    break;

                default:
                    break;
                }
            }
            std::cout << "The number of vowels in " << line << " is " << vowelCount << "." << std::endl;
            std::cout << "The number of tabs in " << line << " is " << tabCount << "." << std::endl;
            std::cout << "The number of spaces in " << line << " is " << spaceCount << "." << std::endl;
            std::cout << "The number of new lines in " << line << " is " << newLineCount << "." << std::endl;
            std::cout << "The number of fi in " << line << " is " << fiCount << "." << std::endl;
            std::cout << "The number of ff in " << line << " is " << ffCount << "." << std::endl;
            std::cout << "The number of fl in " << line << " is " << flCount << "." << std::endl;
        }
        else
        {
            std::cout << "Quitting..." << std::endl;
            break;
        }
    }
    while (true);
}

/********************************************//**
 *  Exercise 5.13
 *
 *  Each of the programs below contain a common programming error. Identify and correct each error.
 *    (a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
 *        char chr = next_text();
 *        switch (chr)
 *        {
 *          case 'a':
 *            aCnt++;
 *          case 'e':
 *            eCnt++;
 *          default:
 *            iouCnt++;
 *        }
 *    (b) unsigned index = some_value();
 *        switch (index)
 *        {
 *          case 1:
 *            int ix = get_value();
 *            ivec[ix] = index;
 *            break;
 *          default:
 *            ix = ivec.size() - 1;
 *            ivec[ix] = index;
 *        }
 *    (c) unsigned eventCnt = 0, oddCnt = 0;
 *        int digit = get_num() % 10;
 *        switch (digit)
 *        {
 *          case 1, 3, 5, 7, 9:
 *            oddCnt++;
 *            break;
 *          case 2, 4, 6, 8, 10:
 *            evenCnt++;
 *            break;
 *        }
 *    (d) unsigned ival = 512, jval = 1024, kval = 4096;
 *        unsigned bufsize;
 *        unsigned swt = get_bufCnt();
 *        switch (swt)
 *        {
 *          case ival:
 *            bufsize = ival * sizeof(int);
 *            break;
 *          case jval:
 *            bufsize = jval * sizeof(int);
 *            break;
 *          case kval:
 *            bufsize = kval * sizeof(int);
 *            break;
 *        }
 ***********************************************/
void ExerciseNum13 (void)
{
    // a) Missing the break statement after each case label.
    // b) ix variable is defined in a case label and used in another case label, it should be defined outside the switch, also missing break statement in default (for consistency).
    // c) Can't use commas in case labels like that, there must be different case labels one on top of the other to achieve the same purpose.
    // d) The operators in case labels have to be constant expressions.
}

/********************************************//**
 *  Exercise 5.14
 *
 *  Write a program to read strings from the standard input looking for duplicate words. The program should find places in the input where one word is followed immediately by itself.
 *  Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated.
 *  For example, if the input is:
 *
 *  how now now now brown cow cow
 *
 *  The output should indicate that the word now occurred three times.
 ***********************************************/
void ExerciseNum14 (void)
{
    std::string word, repeatedWord, mostRepeatedWord;
    int repetitions = 0, mostRepetitions = 0;

    while (std::cin >> word)
    {
        std::cout << "User input the following word: " << word << "." << std::endl;
        // Check if the input word is the same as the repeated one.
        if (word == repeatedWord)
        {
            // Words are the same.
            repetitions++;
            std::cout << "Word: " << word << " repeated " << repetitions << " times." << std::endl;

            if (repetitions > mostRepetitions)
            {
                mostRepeatedWord = word;
                mostRepetitions = repetitions;
                std::cout << "Most repeated word: " << word << " repeated " << mostRepetitions << " times." << std::endl;
            }
        }
        else
        {
            // Words are not the same, so reset repetitions and store the word.
            repeatedWord = word;
            repetitions = 0;
        }
    }

    // Check if there were repetitions.
    if (repetitions > 0)
    {
        // The following word was repeated.
        std::cout << "RESULT: " << mostRepeatedWord << " occurred " << mostRepetitions + 1 << " times." << std::endl;
    }
    else
    {
        // There were no repetitions.
        std::cout << "RESULT: No word was repeated." << std::endl;
    }
}

/********************************************//**
 *  Exercise 5.15
 *
 *  Explain each of the following loops. Correct any problems you detect.
 *
 *  a) for (int ix = 0; ix != sz; ++ix) { ... }
 *     if (ix != sz)
 *       // ...
 *  b) int ix;
 *     for (ix != sz; ++ix) { ... }
 *  c) for (int ix = 0; ix != sz; ++ix, ++sz) { ... }
 ***********************************************/
void ExerciseNum15 (void)
{
    // a) The if that follows the for loop will never be executed.
    // b) There is a semicolon missing in the for header, it wont compile.
    // c) sz is never defined, other than that, the for loop would compile fine.
}

/********************************************//**
 *  Exercise 5.16
 *
 *  The while loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file.
 *  The for loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct.
 *  If you could use only one loop, which would you choose? Why?
 ***********************************************/
void ExerciseNum16 (void)
{
    int a = 0;
    std::vector<int> vectorInt = {0, 1, 2, 3, 4};

    // While loop as a for loop.
    while (a < vectorInt.size())
    {
        std::cout << "Element " << a << " is " << vectorInt[a] << "." << std::endl;
        a++;
    }

    // For loop as a while loop.
    for (; a >= 1;)
    {
        std::cout << "Element " << a - 1 << " is " << vectorInt[a - 1] << "." << std::endl;
        a--;
    }

    // I would choose the for loop, because it is more flexible.
}

/********************************************//**
 *  Exercise 5.17
 *
 *  Given two vectors of ints, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the number of elements of the smaller vector.
 *  For example, given the vectors containing 0, 1, 1 and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.
 ***********************************************/
void ExerciseNum17 (void)
{
    int a = 0;
    bool isPrefix = true;
    std::vector<int> vectorInt0;
    std::vector<int> vectorInt1;
    std::vector<int> *smallVector;
    std::vector<int> *bigVector;

    // First vector.
    std::cout << "Please input numbers to add to the first vector: " << std::endl;
    while (std::cin >> a)
    {
        vectorInt0.push_back(a);
        std::cout << "Number " << a << " added to the list." << std::endl;
    }
    std::cout << "The elements of the first vector are:";
    for (a = 0; a < vectorInt0.size(); a++)
    {
        std::cout << " " << vectorInt0[a];
    }
    std::cout << "." << std::endl;
    std::cin.clear();

    // Second vector.
    std::cout << "Please input numbers to add to the second vector: " << std::endl;
    while (std::cin >> a)
    {
        vectorInt1.push_back(a);
        std::cout << "Number " << a << " added to the list." << std::endl;
    }
    std::cout << "The elements of the second vector are:";
    for (a = 0; a < vectorInt1.size(); a++)
    {
        std::cout << " " << vectorInt1[a];
    }
    std::cout << "." << std::endl;
    std::cin.clear();

    // Check which vector is smaller.
    if (vectorInt0.size() > vectorInt1.size())
    {
        smallVector = &vectorInt1;
        bigVector = &vectorInt0;
    }
    else
    {
        smallVector = &vectorInt0;
        bigVector = &vectorInt1;
    }

    // Check if prefix.
    for (a = 0; (a < smallVector->size()) && (isPrefix == true); a++)
    {
        if ((*smallVector)[a] != (*bigVector)[a])
        {
            isPrefix = false;
        }
    }

    // Print data.
    if (isPrefix == true)
    {
        if (smallVector == &vectorInt0)
        {
            std::cout << "The first vector is a prefix of the second vector." << std::endl;
        }
        else
        {
            std::cout << "The second vector is a prefix of the first vector." << std::endl;
        }
    }
    else
    {
        if (smallVector == &vectorInt0)
        {
            std::cout << "The first vector is a NOT prefix of the second vector." << std::endl;
        }
        else
        {
            std::cout << "The second vector is a NOT prefix of the first vector." << std::endl;
        }
    }
}

/********************************************//**
 *  Exercise 5.18
 *
 *  Explain each of the following loops. Correct any problems you detect.
 *  a) do
 *     {
 *       int v1, v2;
 *       cout << "Please enter two numbers to sum:" ;
 *       if (cin >> v1 >> v2)
 *         cout << "Sum is: " << v1 + v2 << endl;
 *     } while (cin);
 *  b) do { } while (int ival = get_response());
 *  c) do { int ival = get_response(); } while (ival);
 ***********************************************/
void ExerciseNum18 (void)
{
    // a) The original program is missing the brackets.
    // b) The scope of the ival variable is limited to just the while statement below.
    // c) The scope of the ival variable is limited to just inside the while loop and not outside.
}

/********************************************//**
 *  Exercise 5.19
 *
 *  Write a program that uses a do while loop to repetitively request two strings from the user and report which string is less than the other.
 ***********************************************/
void ExerciseNum19 (void)
{
    std::string str1, str2;

    do
    {
        std::cout << "Please input the first string: ";
        if (std::cin >> str1)
        {
            std::cout << std::endl << "Please input the second string: ";
            if (std::cin >> str2)
            {
                if (str1 < str2)
                {
                    std::cout << std::endl << "The first string is less than the second string." << std::endl;
                }
                else if (str2 < str1)
                {
                    std::cout << std::endl << "The second string is less than the first string." << std::endl;
                }
                else
                {
                    std::cout << std::endl << "The second string is equal to the first string." << std::endl;
                }
            }
        }
    }
    while (std::cin);
}

/********************************************//**
 *  Exercise 5.20
 *
 *  Write a program to read a sequence of strings from the standard input until either the same word occurs twice in succession or all the words have been read.
 *  Use a while loop to read the text one word at a time. Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession,
 *  or else print a message saying that no word was repeated.
 ***********************************************/
void ExerciseNum20 (void)
{
    std::string lastWord, repeatedWord;
    bool wordRepeated = false;

    while (std::cin >> lastWord)
    {
        if (repeatedWord.empty() == true)
        {
            repeatedWord = lastWord;
        }
        else if (repeatedWord == lastWord)
        {
            wordRepeated = true;
            break;
        }
        else
        {
            repeatedWord = lastWord;
        }
    }

    if (wordRepeated == true)
    {
        std::cout << "The word " << lastWord << " was repeated twice." << std::endl;
    }
    else
    {
        std::cout << "No word was repeated." << std::endl;
    }
}

/********************************************//**
 *  Exercise 5.21
 *
 *  Revise the program from the exercise in 5.5.1 so that it looks only for duplicated words that start with an uppercase letter.
 ***********************************************/
void ExerciseNum21 (void)
{
    std::string lastWord, repeatedWord;
    bool wordRepeated = false;

    while (std::cin >> lastWord)
    {
        if (repeatedWord.empty() == true)
        {
            repeatedWord = lastWord;
        }
        else if ((repeatedWord == lastWord) &&
                 (isupper(repeatedWord[0]) == true) &&
                 (isupper(lastWord[0]) == true))
        {
            wordRepeated = true;
            break;
        }
        else
        {
            repeatedWord = lastWord;
        }
    }

    if (wordRepeated == true)
    {
        std::cout << "The word " << lastWord << " was repeated twice." << std::endl;
    }
    else
    {
        std::cout << "No word was repeated." << std::endl;
    }
}

/********************************************//**
 *  Exercise 5.22
 *
 *  The following example in this section that jumped back to begin could be better written using a loop.
 *  Rewrite the code to eliminate the goto.
 *    begin:
 *      int sz = get_size();
 *      if (sz <= 0)
 *      {
 *        goto begin;
 *      }
 ***********************************************/
void ExerciseNum22 (void)
{
//    int sz;
//
//    do
//    {
//        sz = get_size();
//    } while (sz <= 0);
}

/********************************************//**
 *  Exercise 5.23
 *
 *  Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.
 ***********************************************/
void ExerciseNum23 (void)
{
    int a = 0, b = 0;

    if (std::cin >> a >> b)
    {
        std::cout << "The result of " << a << " split by " << b << " is " << a / b << "." << std::endl;
    }
    else
    {
        std::cout << "Cancelled." << std::endl;
    }
}

/********************************************//**
 *  Exercise 5.24
 *
 *  Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don't catch an exception.
 ***********************************************/
void ExerciseNum24 (void)
{
    int a = 0, b = 0;

    if (std::cin >> a >> b)
    {
        if (b == 0)
        {
            throw std::runtime_error("Divisor can't be zero.");
        }
        else
        {
            std::cout << "The result of " << a << " split by " << b << " is " << a / b << "." << std::endl;
        }
    }
    else
    {
        std::cout << "Cancelled." << std::endl;
    }
}

/********************************************//**
 *  Exercise 5.25
 *
 *  Revise your program from the previous exercise to use a try block to catch the exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.
 ***********************************************/
void ExerciseNum25 (void)
{
    int a = 0, b = 0;

    do
    {
        try
        {
            std::cout << "Please input numbers A and B: ";
            if (std::cin >> a >> b)
            {
                if (b == 0)
                {
                    throw std::runtime_error("Divisor can't be zero.");
                }
                else
                {
                    std::cout << "The result of " << a << " split by " << b << " is " << a / b << "." << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << "cancelled or error." << std::endl;
                break;
            }
        }
        catch (std::runtime_error e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    while (true);
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

