#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#define MAX_GRADES (20)

/*
 * Program to determine if an input year is a leap year
 * Only works for years which the modern rule applies to, from 1752 on.
 * Author: Joe Gallagher
 * joedgallagher@wpi.edu
 * Last modified: 5/17/2018
 */
int main (int argc, const char* argv[])
{
    // Declare variables
    int all_grades[MAX_GRADES]; // Array to store all input arguments
    int grade_count; // Number of grades to be processed
    int i; // Loop incrementor

    grade_count = argc - 1; // Set grade count to number of numeric args
    if (argc < 2) // Check that there was an entry
    {
        printf("Must enter a number on the command line!\n");
        return 1; // Indicate failure
    }

    // Cut off grade count at MAX_GRADES and alert the user if this is done
    if (argc > MAX_GRADES+1)
    {
        printf("WARNING: Too many arguments. Maximum grade count is %d. Grades "
               "after %d will not be processed.\n", MAX_GRADES, MAX_GRADES);
        grade_count = MAX_GRADES; //Truncate grade count at MAX_Grades
    }

    // Sequentially store each argument into the array, in order
    for(i = 1; i <= grade_count; i++)
    {
        all_grades[i-1] = atoi(argv[i]);
    }

    // Call function to print average, minimum, and maximum values
    grades(all_grades, grade_count);
    return 0; // Indicate success!
}
