#include <stdio.h>
#include <stdlib.h>
#include "grades.h"

void grades(int array[], int grade_count)
{
    printAverage(array, grade_count);
    printMinMax(array, grade_count);
}

void printAverage(int array[], int grade_count)
{
    int average = 0; // Variable in which the average will be computed
    int i; // Loop incrementor

    for (i = 0; i < grade_count; i++)
    {
        average = average + array[i];
        printf("Processed a %d\n" , array[i]);
    }
    average = average / grade_count;
    printf("The average of all grades entered is %d.\n", average);

}

void printMinMax(int array[], int grade_count)
{
    int min = array[0]; // Stores the minimum value seen so far
    int max = array[0]; // Stores the maximum value seen so far
    int i; // Loop incrementor

    for (i = 1; i < grade_count; i++)
    {
        printf("Processed a %d\n" , array[i]);
        if (array[i] < min)
        {
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    printf("The smallest grade entered is %d.\n", min);
    printf("The largest grade entered is %d.\n", max);

}
