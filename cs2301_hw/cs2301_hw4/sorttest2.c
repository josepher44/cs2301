#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define VALUE_RANGE (10000)

/* Program which generates a number of random values equal to a count entered
 * on the command line, outputs them, sorts them in descending order,
 * and outputs the sorted list. By default sorts using pointers. Specify
 * 'a' to sort by array, 'p' explicitly to use pointers. Flag "s" to seed
 * the random number generator
 *
 * Usage:
 *         ./sorttest some_number sort_type_flag seed_flag
 * Example:
 *         ./sorttest 5000 a s
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[])
{

  int *nums; // space to store numbers entered from the command line.
  int count; // How many numbers actually entered on the command line.
  int i; // Loop incrementor
  char flag; // Sort type flag


  if (argc < 2)
  {
    printf("Must enter a number of values to process. Exiting.\n");
    return 1; // Indicate failure
  }

  // Assign the count variable to the value from the command line
  count = atoi(argv[1]);

  // Assign the flag variable to the character enterd from the command line
  flag = argv[2][0];

  // Reseed the RNG if flagged to do so
  if (argc == 4 && argv[3][0] == 's')
  {
    srand(time(0));
  }
  printf("Flag character is %c\n", flag);

  // Allocate an array big enough to hold the numbers
  nums = (int*) calloc(count, sizeof(int));
  if (nums == NULL)
  {
    fprintf(stderr, "Unable to allocate enougn memory to hold the numbers.\n");
  }

  /* Generate a random value for each array index */
  for (i = 0; i < count; i++) {
    nums[i] = randomNumber(VALUE_RANGE);
  }

  // Now print, sort, and print the array, and time how long the sorting took.
  // Check if the program should use array or pointer sort
  if (flag == 'a')
  {
    timesort(nums, count, 0);
  }
  else
  {
    timesort(nums, count, 1);
  }


  return 0; // Indicate success!
}
