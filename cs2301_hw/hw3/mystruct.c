/** mystruct.c
 * @author Joe Gallagher
*/


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

#define EMPLOYEE_NAME_LENGTH 15



/** Allocates an Employee struct and fills in its fields
 * @param name String containing employee's name
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(const char *name, int birth, int start)
{
	char* nameCopy = strdup(name);
	struct Employee* output;
	output = (struct Employee*)malloc(sizeof(struct Employee));
	strcpy(output->employee_name, nameCopy);
	output->birth_year = birth;
	output->start_year = start;
	return output;
}

/** Prints the contents of an employee struct
 * @param e The empolyee to print out
 */
void printEmployee(struct Employee* e)
{
	printf("Name of Employee: %s\nEmployee birth year: %d\nEmployee start year: %d\n"
			"Pointer to employee: %p\n"
			,(*e).employee_name, (*e).birth_year, (*e).start_year, e);
}


/**Returns a random integer from 0 to n, inclusive
 * @param n The maximum value for return
 * @return A random integer value from 0 to n
 */
int randomNumber(int n)
{
	int output = rand()%n;
	return output;
}

/**Returns a random ASCII charater from a to z (numeric values 97-122)
 * @return A random char value from a to z
 */
char randomCharacter()
{
	//+'a' offsets the range of values to the lowercase letters
	char output = (char)randomNumber(25)+'a';
	return output;
}

/**Returns a random four digit year from 1900 to 2018
 * @return A random four digit year from 1900 to 2018
 */
int randomYear()
{
	//+1900 offsets the range to a year range that makes sense
	int output = 1900+randomNumber(118);
	return output;
}

/**Returns a random string between a given size range
 * @param length the number of characters the string should contain
 * @return A string of lowercase letters with length characters
 */
char* randomString(int length)
{
	/*
	 * Declare variables.
	 * string stores the output as it is assembled
	 */
	char* string;
	string=malloc(sizeof(char)*(length+1));
	for (int i=0; i<length; i++)
	{
		/*
		 * At the start of this loop, string, at indices from 0 to i-1, contains
		 * the string as assembled so far. i is the next index to append a
		 * character to.
		 */
		string[i]=randomCharacter();
	}
	//Add null terminator
	string[length]='\0';
	return string;
}

/** Allocates an Employee struct and fills in its fields with random values
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeRandomEmployee()
{
	return makeEmployee(randomString(EMPLOYEE_NAME_LENGTH), randomYear(),
	randomYear());
}

/** Allocates an array of Employee structs, and fills each with random values
 * @param count The number of Employee structs to allocate.
 * @return Pointer to array of filled employee structs
 */
struct Employee** makeEmployeeArray(int count)
{
	/*
	 * Declare variables. i is a loop incrementor. employees is a series of
	 * pointers pointing to employee structs. Buffer stores the next
	 * employee to be appended to the output, and is used for size allocation
	 */
	int i;
	struct Employee **employees;
	struct Employee* buffer;
	employees = malloc(sizeof(buffer)*count);
	for (i=0; i<count; i++)
	{
		/*
		 * At the start of this loop, i is the next index of the array to
		 * append an employee to. Buffer contains the last employee added,
		 * and it will be overwritten during the loop
		 */
		buffer = makeRandomEmployee();
		employees[i]=buffer;
	}
	return employees;

}

void printEmployeeStruct(struct Employee** e, int count)
{
	printf("Printing set of %d employees:\n", count);
	for(int i=0; i<count; i++)
	{
		//i is the next employee index to print
		printEmployee(e[i]);
	}
}

/** Copies an array of pointers to a set of employees, but not the data the
 * pointers point to
 * @param e Employee array to copy
 * @param count Number of employees in array e
 * @return an array of pointers to the input set of employees
 */
struct Employee** shallowCopyEmployees(struct Employee **e, int count)
{
	struct Employee **output;
	output = malloc(count * sizeof(**output));

	for(int i=0; i<count; i++)
	{
		/*
		 * At the start of each loop, i is the index of the pointer to copy next
		 */
		output[i] = e[i];
	}
	return output;
}

/** Frees the memory associated with an array of pointers to employees
 * @param e Employee array to de-allocate
 * @param count Number of employees in array e
 */
void freeEmployees(struct Employee** e, int count)
{
	for (int i=0; i<count; i++)
	{
		/*
		 * At the start of each loop, i represents the next index of e to
		 * de-allocate. All indexes below i have already been freed.
		 */
		free(e[i]);
	}
	//De-allocate the pointer to the complete array
	free(e);
}

/** Copies an array of pointers to a set of employees, by directly copying the
 * data that they point to
 * @param e Employee array to copy
 * @param count Number of employees in array e
 * @return an array of pointers to the input set of employees, deep copied
 */
struct Employee** deepCopyEmployees(struct Employee** e, int count)
{
	struct Employee** output;
	output = malloc(count * sizeof(**output));

	for(int i=0; i<count; i++)
	{
		/*
		 * At the start of each loop, i is the index of the pointer to copy next
		 */
		output[i] = makeEmployee((*e[i]).employee_name, (*e[i]).birth_year,
		 (*e[i]).start_year);
	}
	return output;
}
