/* Example C program for CS2301 Lab 1 */
/* Created by Joe Gallagher, joedgallagher */
#include <stdio.h>
int main()
{
  int i;  // Loop counter

  printf("Hello, World!\n"); //Print a cheery greeting!
  /* This loop prints the numbers from 1 to 15, one per line. */
  for (i = 1; i <=15; i++)
  {
    printf("%d\n", i); // Print the next number
  }
  printf("Goodbye, World!\n");


  int p;
  int j;
  int k;

  p = 0;
  while (p < 5) {
    j = p++;
  }

  printf("%d\n", j); // Print the next number
  p = 0;
  do {
    k = --j;
  } while (j > 0);
  printf("%d\n", j); // Print the next number
  printf("%d\n", k); // Print the next number
}
