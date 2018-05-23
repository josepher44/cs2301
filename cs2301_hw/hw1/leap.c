#include <stdio.h>
#include <stdlib.h>
#define CUTOFF_YEAR (1752)

/*
 * Program to determine if an input year is a leap year
 * Only works for years which the modern rule applies to, from 1752 on.
 * Author: Joe Gallagher
 * joedgallagher@wpi.edu
 * Last modified: 5/17/2018
 */
 
int main (int argc, const char* argv[])
{
    //Declare variables
    int year; // Year read from the command line goes here

    // Check that there was an entry, with only one argument
    if (argc != 2)
    {
        printf("Must enter a year on the command line as an argument, "
        "as the only argument. For example: ./leap 2018\n");
        return 1; // Indicate failure -- invalid input format
    }
    year = atoi(argv[1]); // Get string from command line; convert to int

    if (year < CUTOFF_YEAR) // Check if the year is recent enough for checking
    {
        printf("The year entered must be %d or more recent, as the modern "
        "rule for leap years does not apply before this time. You entered "
        "%d.\n", CUTOFF_YEAR, year);
        return 2; // Indicate failure -- year out of range
    }

    //Echo the year
    printf("You entered: %d. ", year);

    /*
     * Check if a year is a leap year, using boolean logic and modulo oparators.
     * The left side checks that the exception for years divisible by 100 unless
     * also by 400 does not apply, the right side checks if the year is
     * divisible by 4. If true, the year is a leap year
     */
    if ((year%100 != 0 || year%400 == 0) && (year%4)==0)
    {
        printf("The year %d is a leap year.\n", year);
    }
    else
    {
        printf("The year %d is not a leap year.\n", year);
    }
    return 0; // Indicate success!
}
