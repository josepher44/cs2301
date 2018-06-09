/** mystring.h
 * @author Mike Ciaraldi, Blake Nelson
 * My own versions of some of the C-style string functions
*/
#ifndef MYSTRING_H		// Remember guard
#define MYSTRING_H

// Function prototype(s):
char* mystrdup(const char* src);
char *mystrcpy(char *dest, const char *src);
size_t mystrlen(const char* str);
char *mystrncpy(char *dest, const char *src, size_t n);
char *mystrcat(char *dest, const char *src);
char *mystrncat(char *dest, const char *src, size_t n);

#endif