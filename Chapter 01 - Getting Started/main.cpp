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

typedef void (*Exercise) (void);
// Fill the array as you add exercises.
Exercise Exercises[] = {
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
		ExerciseNum15
};

#include <stdio.h>
#include <iostream>

/********************************************//**
 *  Exercise 1.1
 *
 *  Compile and run the program from page 2.
 ***********************************************/
int returnValue = 0;

void ExerciseNum1 (void)
{
	returnValue = 0;
}

/********************************************//**
 *  Exercise 1.2
 *
 *  Change the program to return -1. Recompile and rerun your program to see how your system treats a failure indicator from main.
 ***********************************************/

void ExerciseNum2 (void)
{
	returnValue = -1;
}

/********************************************//**
 *  Exercise 1.3
 *
 *  Write a program to print Hello, World on the standard output.
 ***********************************************/

void ExerciseNum3 (void)
{
	std::cout << "Hello, world" << std::endl;
}

/********************************************//**
 *  Exercise 1.4
 *
 *  Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.
 ***********************************************/

void ExerciseNum4 (void)
{
	int v1, v2;

	std::cout << "Please input the first operand: " << std::endl;
	std::cin >> v1;
	std::cout << "Please input the second operand: " << std::endl;
	std::cin >> v2;
	std::cout << "The result is: " << v1 * v2 << std::endl;
}

/********************************************//**
 *  Exercise 1.5
 *
 *  We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.
 ***********************************************/

void ExerciseNum5 (void)
{
	std::cout << "The sum of ";
	std::cout << 1;
	std::cout << " and ";
	std::cout << 10;
	std::cout << " is ";
	std::cout << 1 + 10;
	std::cout << std::endl;
}

/********************************************//**
 *  Exercise 1.6
 *
 *  Explain whether the following program fragment is legal. If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?
 *
 *  std::cout << "The sum of " << v1;
 *  		  << " and " << v2;
 *  		  << " is " << v1 + v2 << std::endl;
 ***********************************************/

void ExerciseNum6 (void)
{
	int v1 = 10, v2 = 20;

	std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
}

/********************************************//**
 *  Exercise 1.7
 *
 *  Compile a program that has incorrectly nested comments.
 ***********************************************/

void ExerciseNum7 (void)
{
	/* Easy to do. */
}

/********************************************//**
 *  Exercise 1.8
 *
 *  Indicate which, if any, of the following output statements are legal:
 *
 *  (statements)
 *
 *  After you've predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.
 ***********************************************/

void ExerciseNum8 (void)
{
	/* This are the correct statements. */
	std::cout << "/*";
	std::cout << "*/";
	std::cout << "/* */ */";
	std::cout << "/* */ /* /* */";
}

/********************************************//**
 *  Exercise 1.9
 *
 *  Write a program that uses a while to sum the numbers from 50 to 100.
 ***********************************************/

void ExerciseNum9 (void)
{
	int sum = 0, i = 50;

	while (i <= 100)
		sum += i++;

	std::cout << "Total sum: " << sum << std::endl;
}

/********************************************//**
 *  Exercise 1.10
 *
 *  In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.
 ***********************************************/
void ExerciseNum10 (void)
{
	int i = 10;

	while (i != 0)
		std::cout << i-- << "\r";
	std::cout << std::endl;
}

/********************************************//**
 *  Exercise 1.11
 *
 *  Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.
 ***********************************************/
void ExerciseNum11 (void)
{
	int i, a;

	std::cin >> i >> a;

	while (++i < a)
		std::cout << i << " ";
	std::cout << std::endl;
}

/********************************************//**
 *  Exercise 1.12
 *
 *  What does the following for loop do? What is the final value of sum?
 ***********************************************/
void ExerciseNum12 (void)
{
	int sum = 0, i;
	for (i = -100; i <= 100; i++)
		sum += i;
	std::cout << i << std::endl;
}

/********************************************//**
 *  Exercise 1.13
 *
 *  Rewrite the previous exercises with the while loop.
 ***********************************************/
void ExerciseNum13 (void)
{
	int sum, i;

	/* First program. */
	for (i = 50, sum = 0; i <= 100; sum += i++);

	std::cout << "Total sum: " << sum << std::endl;

	/* Second program. */
	std::cin >> i >> sum;

	for (; ++i < sum; std::cout << i << " ");
	std::cout << std::endl;
}

/********************************************//**
 *  Exercise 1.14
 *
 *  Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?
 ***********************************************/
void ExerciseNum14 (void)
{

}

/********************************************//**
 *  Exercise 1.15
 *
 *  Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.
 ***********************************************/
void ExerciseNum15 (void)
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
		printf("No exercise executed. ExerciseNum is not a valid value.\n");
	return returnValue;
}

