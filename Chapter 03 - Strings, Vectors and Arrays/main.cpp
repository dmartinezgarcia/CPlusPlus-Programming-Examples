// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 1;

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
    ExerciseNum20
};

#include <stdio.h>

/********************************************//**
 *  Exercise 3.1
 *
 *  Rewrite the exercises 1.9, 1.10, 1.11 with appropriate using declarations.
 ***********************************************/
void ExerciseNum1 (void)
{
    /* This is exercise 1. */
}

/********************************************//**
 *  Exercise 3.2
 *
 *  Write a program to read the standard input a line at a time. Modify your program to read a word at a time.
 ***********************************************/
void ExerciseNum2 (void)
{
    /* This is exercise 2. */
}

/********************************************//**
 *  Exercise 3.3
 *
 *  Explain how whitespace characters are handled in the string input operator and in the getline function.
 ***********************************************/
void ExerciseNum3 (void)
{
    /* This is exercise 3. */
}

/********************************************//**
 *  Exercise 3.4
 *
 *  Write a program to read two strings and report whether the strings are equal.
 *  If not, report which of the two is larger. Now, change *the program to report whether the strings have the same length, and if not, report which is longer.
 ***********************************************/
void ExerciseNum4 (void)
{
    /* This is exercise 4. */
}

/********************************************//**
 *  Exercise 3.5
 *
 *  Write a program to read strings from the standard input, concatenating what is read into one large string.
 *  Print the concatenated string. Next, change the program to separate adjacent input strings by a space.
 ***********************************************/
void ExerciseNum5 (void)
{
    /* This is exercise 5. */
}

/********************************************//**
 *  Exercise 3.6
 *
 *  Use a range for to change all the characters in a string to X.
 ***********************************************/
void ExerciseNum6 (void)
{
    /* This is exercise 6. */
}

/********************************************//**
 *  Exercise 3.7
 *
 *  What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.
 ***********************************************/
void ExerciseNum7 (void)
{
    /* This is exercise 7. */
}

/********************************************//**
 *  Exercise 3.8
 *
 *  Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?
 ***********************************************/
void ExerciseNum8 (void)
{
    /* This is exercise 8. */
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
    /* This is exercise 9. */
}

/********************************************//**
 *  Exercise 3.10
 *
 *  Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.
 ***********************************************/
void ExerciseNum10 (void)
{
    /* This is exercise 10. */
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
    /* This is exercise 11. */
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
    /* This is exercise 12. */
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
    /* This is exercise 13. */
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
    /* This is exercise 13. */
}

/********************************************//**
 *  Exercise 3.14
 *
 *  Write a program to read a sequence of ints from cin and store those values in a vector.
 ***********************************************/
void ExerciseNum14 (void)
{
    /* This is exercise 14. */
}

/********************************************//**
 *  Exercise 3.15
 *
 *  Repeat the previous program but read strings this time.
 ***********************************************/
void ExerciseNum15 (void)
{
    /* This is exercise 15. */
}

/********************************************//**
 *  Exercise 3.16
 *
 *  Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct.
 ***********************************************/
void ExerciseNum16 (void)
{
    /* This is exercise 16. */
}

/********************************************//**
 *  Exercise 3.17
 *
 *  Read a sequence of words from cin and store the values a vector. After you've read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.
 ***********************************************/
void ExerciseNum17 (void)
{
    /* This is exercise 17. */
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
    /* This is exercise 18. */
}

/********************************************//**
 *  Exercise 3.19
 *
 *  List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.
 ***********************************************/
void ExerciseNum19 (void)
{
    /* This is exercise 19. */
}

/********************************************//**
 *  Exercise 3.20
 *
 *  Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
 ***********************************************/
void ExerciseNum20 (void)
{
    /* This is exercise 20. */
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

