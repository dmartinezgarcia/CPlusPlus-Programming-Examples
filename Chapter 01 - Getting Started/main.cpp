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
#include "Sales_item.h"

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
 *  Exercise 1.16
 *
 *	Write your version of a program that prints the sum of a set of integers read from cin.
 ***********************************************/
void ExerciseNum16 (void)
{
	int a, sum = 0;

	while (std::cin >> a)
		sum += a;
	std::cout << "Total sum: " << sum << std::endl;
}

/********************************************//**
 *  Exercise 1.17
 *
 *	What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?
 ***********************************************/
void ExerciseNum17 (void)
{
	int currVal = 0, val = 0;
	if (std::cin >> currVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == currVal)
				++cnt;
			else {
				std::cout << currVal << " occurs " << cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs " << cnt << " times" << std::endl;
	}
}

/********************************************//**
 *  Exercise 1.18
 *
 *	Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.
 ***********************************************/
void ExerciseNum18 (void)
{
	int currVal = 0, val = 0;
	if (std::cin >> currVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == currVal)
				++cnt;
			else {
				std::cout << currVal << " occurs " << cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs " << cnt << " times" << std::endl;
	}
}

/********************************************//**
 *  Exercise 1.19
 *
 *  Revise the program you wrote for the exercises in $ 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.
 ***********************************************/
void ExerciseNum19 (void)
{
	int a, b;

	/* Second program. */
	std::cin >> a >> b;
	if (a > b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	for (; ++a < b; std::cout << a << " ");
	std::cout << std::endl;
}

/********************************************//**
 *  Exercise 1.20
 *
 *  http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.
 ***********************************************/
void ExerciseNum20 (void)
{
	Sales_item book;

	std::cout << "Enter sale items in the following format: <ISBN - string> <Units - int> <Value - float>\r\n" << std::endl;
	while (std::cin >> book)
		std::cout << book << std::endl;
}

/********************************************//**
 *  Exercise 1.21
 *
 *  Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.
 ***********************************************/
void ExerciseNum21 (void)
{
	Sales_item book1, book2;

	std::cout << "Enter two books that have the same ISBN: ";
	std::cin >> book1 >> book2;
	if (book1.isbn() == book2.isbn())
		std::cout << "\nThe books sum is " << book1 + book2;
	else
		std::cout << "\nThe books don't have the same ISBN";
	std::cout << std::endl;
}

/********************************************//**
 *  Exercise 1.22
 *
 *  Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.
 ***********************************************/
void ExerciseNum22 (void)
{
	Sales_item book1, book2;

	while (std::cin >> book1)
	{
		if (book2.isbn() == "")
			book2 = book1;
		else if (book2.isbn() != book1.isbn()) {
			std::cout << "Transaction details: " << book2 << std::endl;
			book2 = book1;
		} else
			book2 += book1;
	}
}

/********************************************//**
 *  Exercise 1.23
 *
 *  Write a program that reads several transactions and counts how many transactions occur for each ISBN.
 ***********************************************/
void ExerciseNum23 (void)
{
	int nTransactions = 0;
	Sales_item book1, book2;

	while (std::cin >> book1) {
		if ((book2.isbn() != book1.isbn()) && (book2.isbn() != "")) {
			std::cout << nTransactions << " transactions for ISBN: " << book1.isbn() << std::endl;
			nTransactions = 0;
		}
		book2 = book1;
		nTransactions++;
	}
}

/********************************************//**
 *  Exercise 1.24
 *
 *  Test the previous program by giving multiple transactions representing multiple ISBNS. The records for each ISBN should be grouped together.
 ***********************************************/
void ExerciseNum24 (void)
{
	int nTransactions = 0;
	Sales_item book1, book2;

	while (std::cin >> book1) {
		if ((book2.isbn() != book1.isbn()) && (book2.isbn() != "")) {
			std::cout << nTransactions << " transactions for ISBN: " << book1.isbn() << std::endl;
			nTransactions = 0;
		}
		book2 = book1;
		nTransactions++;
	}
}

/********************************************//**
 *  Exercise 1.25
 *
 *  Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.
 ***********************************************/
void ExerciseNum25 (void)
{
	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			} else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
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
		printf("No exercise executed. ExerciseNum is not a valid value.\n");
	return returnValue;
}

