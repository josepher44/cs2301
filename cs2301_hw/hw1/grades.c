#include <stdio.h>
#include <stdlib.h>
#include "grades.h"

/*
 * Functions to support printing statistical information about an entered
 * series of grades.
 * Author: Joe Gallagher
 * joedgallagher@wpi.edu
 * Last modified: 5/23/2018
 */


 /** Print the average, minimum, and maximum grades.
  *
  * @param array[] the array of all grades.
  * @param grade_count the number of grades in the array.
  *
  * @author Joe Gallagher
  */
void grades(int array[], int grade_count)
{
    printAverage(array, grade_count);
    printMinMax(array, grade_count);
}

/** Print the average of all grades in an array
 *
 * @param array[] the array of all grades.
 * @param grade_count the number of grades in the array.
 *
 * @author Joe Gallagher
 */
void printAverage(int array[], int grade_count)
{
    // Declare variables
    int average = 0; // Variable in which the average will be computed
    int i; // Loop incrementor

    /*
     * Loop through and sum every grade in the array, with i being the index
     * currently being processed. In the loop, "average" actually represents
     * the sum so far
     */
    for (i = 0; i < grade_count; i++)
    {
        average = average + array[i];
    }

    // Divide by the total grade count to get average, and print to console
    average = average / grade_count;
    printf("The average of all grades entered is %d.\n", average);

}

/** Print the minimum and maximum grade in an arrays.
 *
 * @param array[] the array of all grades.
 * @param grade_count the number of grades in the array.
 *
 * @author Joe Gallagher
 */
void printMinMax(int array[], int grade_count)
{
    // Declare variables
    int min = array[0]; // Stores the minimum value seen so far
    int max = array[0]; // Stores the maximum value seen so far
    int i; // Loop incrementor

    /*
     * Check if each grade is either the lowest or highest seen so far,
     * and overwrite the appropriate variable accordingly
     */
    for (i = 1; i < grade_count; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    // Print result to console after all grades have been processed
    printf("The smallest grade entered is %d.\n", min);
    printf("The largest grade entered is %d.\n", max);

}
