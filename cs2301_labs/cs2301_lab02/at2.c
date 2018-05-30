/** file at.c
 * @author
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include "print_arrays.h"

/** Program for filling an array with arguments from the command line
 * @return 0, Indicating success.
 */

int main(int argc, const char* argv[]) {
  int size = argc-1; // Array size
  int i; // Loop counter
  int a[size]; // Array to fit all arguments

  // Fill the array with consecutive integers from the arguments entered
  for(i = 1; i <= size; i++)
  {
      a[i-1] = atoi(argv[i]);
  }

  // Now print it out
  print_int_array(a, size);

  return 0; // Success!
}
