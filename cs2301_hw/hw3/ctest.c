// string.h covers the C-style string functions.
#include <stdio.h>
#include <string.h>
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and  * dynamically-allocated memory.
 * @author Mike Ciaraldi, Blake Nelson
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
  char a1[MAX_CHARS + 1]; 	// Character array--initially empty
  char a2[] = "Hello"; 		// Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; 	// Character array--we will underfill it
  char a4[MAX_CHARS + 1];   // Another empty array for testing
  const char *p1 = "Hello"; // Pointer to constant string
  char *p2;           		// Will be a pointer to dynamically-allocated string
  char* p3 = "Hi"; // Pointer to another constant string
  char* p4 = "17characterstring"; // 17 character string strncat<n
  char* p5 = "18character string"; // 18 character string strncat=n
  int copy_limit;     		// Maximum characters to copy.

  strcpy(a3, "Hello, also"); // Initialize uinderfilled character array
  mystrcpy(a4, "Hello, from Joe now."); // Initialize array using my function


  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Arrays:   a1: %p, a2: %p, a3: %p\n", a1, a2, a3);
  printf("Pointers: p1: %p, p2: %p\n", p1, p2);

  strcpy(a1, "Hi"); 		// Initialize character array a1 with some text

  printf("a1 = %s\n", a1);
  printf("a2 = %s\n", a2);
  printf("a3 = %s\n", a3);
  printf("a4 = %s\n", a4);

  // Print the values of the C-style strings
  printf("C-string values:\n");
  printf("a1: %s\n", a1);
  printf("a2: %s\n", a2);
  printf("a3: %s\n", a3);

  /* Concatenate two character arrays, then print.
  *  Terminator character in the last element of the array as well as after "Hi"
  */
  a1[MAX_CHARS] = '\0';
  mystrcat(a1, a2);
  printf("After concatenating a2 to the end of a1\n");
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); 	// How much space is left?

  printf("Concatenating a2 to the end of a1, with copy_limit = %d\n",
    copy_limit);
  if (copy_limit > 0) {
	mystrncat(a1, a2, copy_limit);
  }
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); 	// How much space is left?
  printf("Concatenating a3 to the end of a1, with copy_limit = %d\n",
	 copy_limit);
  if (copy_limit > 0) {
	mystrncat(a1, a3, copy_limit);
  }
  printf("a1: %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer p2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("Duplicated string: \n");
  printf("Pointer p2: %p, contents: %s\n", p2, p2);

  // Copy a string with character copy_limit
  mystrncpy(a1, "This part gets copied. This does not", 22);
  printf("a1 = %s\n", a1);


  return 0; //Indicate success
}
