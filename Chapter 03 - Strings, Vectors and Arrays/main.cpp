// Exercise to execute. 1 <= ExerciseNum <= NumberOfTotalExercises.
int ExerciseNum = 1;

// Add function prototypes as you add them.
void ExerciseNum1 (void);
void ExerciseNum2 (void);

typedef void (*Exercise) (void);
// Fill the array as you add exercises.
Exercise Exercises[] =
{
    ExerciseNum1,
    ExerciseNum2
};

#include <stdio.h>

/********************************************//**
 *  Exercise 3. 1
 *
 *	Rewrite the exercises 1.9, 1.10, 1.11 with appropriate using declarations.
 ***********************************************/
void ExerciseNum1 (void)
{
    /* This is exercise 1. */
}

/********************************************//**
 *  This is exercise 2 explanation.
 ***********************************************/
void ExerciseNum2 (void)
{
    /* This is exercise 2. */
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

