/** mystring.c
 * @author Mike Ciaraldi, Blake Nelson
 * Custom versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; 	// Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  		// Leave space for the terminator
  newstr = (char*) malloc(length); 	// Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) {
	return (char *) 0;
  }

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Provides the length of a C-style string, not including the null terminator
 @param str Pointer to string to be evaluated
 @return size_t integer value representing the number of characters in the
 	 	 string, not including the null terminator
*/
size_t mystrlen(const char* str)
{
	//Declare values. returnValue stores the value to be returned
	size_t returnValue;

	returnValue = 0;
	while(str[returnValue]!='\0')
	{
		/*
		 * At the start of this loop, returnValue has the total character count
		 * of the string evaluated so far
		 */
		returnValue++;
	}
	/*
	 * At the end of this loop, returnValue has the total character count of the
	 * string, without the null terminator, which breaks out of the loop
	 */
	return returnValue;
}

/** Copies a string from one pointer to another
 @param *src Pointer to the string to be copied
 @param *dest Pointer to the destination of the copied string
 @return A pointer to the destination string
*/
char *mystrcpy(char *dest, const char *src)
{
	/*
	 * Declare variables. srcIndex stores the index of the source array
	 * currently being copied, so that it can be incremented without changing
	 * src. destIndex stores the index of the start of the destination array,
	 * which does not change throughout the program loop so that it can be
	 * reset at the end.
	 */
	const char* srcIndex;
	char* destIndex;

	srcIndex = src;
	destIndex = dest;
	while(*srcIndex !='\0')
	{
		/*
		 * At the start of this loop, dest points to the memory which should
		 * store the next character in the array to be copied. *srcIndex
		 * represents the value of the next character to be copied
		 */
		*dest = *srcIndex;
		dest++;
		srcIndex++;
	}
	/*
	 * At the end of this loop, destIndex contains the original pointer to the
	 * start of the destination array, dest points to the next memory index
	 * beyond the end of the destination array
	 */
	*dest = '\0'; // Append null terminator to end of destination array
	dest = destIndex; // Reset the destination array index to the start value
	return dest;
}

/** Concatenates one string to another, removing the null terminator from the
 * first string
 @param *dest Pointer to the first string, where the output will be written
 @param *src Pointer to the second string
 @return A pointer to the concatenated string

*/
char *mystrcat(char *dest, const char *src)
{
	const char* srcIndex;
	char* destIndex;

	/*
	 * Initialize variables. srcIndex is initialized as a duplicate to prevent
	 * errors in the case where you are concatinating a string to itself
	 */

	srcIndex = mystrdup(src);
	destIndex = dest;
	size_t destLength;

	destLength = mystrlen(dest);
	dest = dest+destLength; /*
							 * Offset pointer dest by the length of dest,
							 * minus the null terminator
							 */
	while(*srcIndex !='\0')
	{
		/*
		 * At the start of this loop, dest points to the memory which should
		 * store the next character in the array to be copied. *srcIndex
		 * represents the value of the next character to be copied
		 */
		*dest = *srcIndex;
		dest++;
		srcIndex++;
	}
	*dest = '\0'; // Append null terminator to end of destination array
	dest = destIndex; // Reset the destination array index to the start value
	return dest;
}

/** Concatenates one string to another, removing the null terminator from the
 * first string, with n being the limit of characters to add. Always null
 * terminates the finished string.
 @param *dest Pointer to the first string, where the output will be written
 @param *src Pointer to the second string
 @param n The maximum size of the concatenated string
 @return A pointer to the concatenated string

*/
char *mystrncat(char *dest, const char *src, size_t n)
{
	/*
	 * Declare variables.
	 */
	char* srcIndex;
	char* destIndex;
	int i;

	/*
	 * Initialize variables. srcIndex stores the index of the source array
	 * currently being concatinated, so that it can be incremented without
	 * changing src. destIndex stores the index of the start of the destination
	 * array, which does not change throughout the program loop so that it can
	 * be reset at the end.
	 */
	srcIndex = mystrdup(src);
	destIndex = dest;
	size_t destLength;
	i=0;

	destLength = mystrlen(dest);
	dest = dest+destLength; /*
							 * Offset pointer dest by the length of dest,
							 * minus the null terminator
							 */
	while(*srcIndex !='\0')
	{
		/*
		 * At the start of this loop, dest points to the memory which should
		 * store the next character in the array to be copied. *srcIndex
		 * represents the value of the next character to be copied
		 */
		*dest = *srcIndex;
		dest++;
		srcIndex++;
		i++;
		if (i>n-1)
		{
			break;
		}
	}
	*dest = '\0'; // Append null terminator to end of destination array
	dest = destIndex; // Reset the destination array index to the start value
	return dest;
}

/** Copies a string from one pointer to another
 @param *src Pointer to the string to be copied
 @param *dest Pointer to the destination of the copied string
 @param n The maximum number of characters to copy
 @return A pointer to the destination string

*/
char *mystrncpy(char *dest, const char *src, size_t n)
{
	/*
	 * Declare variables. srcIndex stores the index of the source array
	 * currently being copied, so that it can be incremented without changing
	 * src. destIndex stores the index of the start of the destination array,
	 * which does not change throughout the program loop so that it can be
	 * reset at the end. i counts the characters copied to ensure the functions
     * does not copy more than specified by the parameters
	 */
	const char* srcIndex;
	char* destIndex;
    int i;

	srcIndex = src;
	destIndex = dest;
    i = 0;
	while(*srcIndex !='\0')
	{
		/*
		 * At the start of this loop, dest points to the memory which should
		 * store the next character in the array to be copied. *srcIndex
		 * represents the value of the next character to be copied
		 */
		*dest = *srcIndex;
		dest++;
		srcIndex++;
        i++;
        if (i>n-1)
        {
            // Exit the loop if the maximum character count has been exceeded
            break;
        }
	}
	/*
	 * At the end of this loop, destIndex contains the original pointer to the
	 * start of the destination array, dest points to the next memory index
	 * beyond the end of the destination array
	 */
	*dest = '\0'; // Append null terminator to end of destination array
	dest = destIndex; // Reset the destination array index to the start value
	return dest;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src)
{
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}
