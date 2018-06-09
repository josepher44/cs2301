/** file at.c
 * @author: Joe Gallagher
 *
 * Program to demonstrate fixed-size arrays in C.
 */
#include <stdio.h>
#include <stdlib.h>
#include "print_arrays.h"

/** Program for filling an array with arguments from the command line
 * @return 0, Indicating success.
 */

int main(int argc, const char* argv[]) {
  int size = argc-1; // Array size
  int i; // Loop counter
  int a[size]; // Array to fit all arguments, int form
  double b[size]; // Array to fit all arguments, double form

  // Fill the arrays with consecutive values from the arguments entered
  for(i = 1; i <= size; i++)
  {
      a[i-1] = atoi(argv[i]);
      b[i-1] = atof(argv[i]);
  }

  // Now print them out
  print_int_array(a, size);
  print_double_array(b, size);

  return 0; // Success!
}
