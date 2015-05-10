// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 6;

// Add function prototypes as you add them.
void ExerciseNum1 (void);
void ExerciseNum2 (void);
void ExerciseNum3 (void);
void ExerciseNum4 (void);
void ExerciseNum5 (void);
void ExerciseNum6 (void);

typedef void (*Exercise) (void);
// Fill the array as you add exercises.
Exercise Exercises[] = {
		ExerciseNum1,
		ExerciseNum2,
		ExerciseNum3,
		ExerciseNum4,
		ExerciseNum5,
		ExerciseNum6
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

