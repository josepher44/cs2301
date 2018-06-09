/** mystruct.h
 * @author Joe Gallagher
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char employee_name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(const char* name, int birth, int start);
void printEmployee(struct Employee *e);
int randomNumber(int n);
char randomCharacter();
int randomYear();
char* randomString(int length);
struct Employee* makeRandomEmployee();
struct Employee** makeEmployeeArray(int count);
void printEmployeeStruct(struct Employee **e, int count);
struct Employee** shallowCopyEmployees(struct Employee **e, int count);
void freeEmployees(struct Employee** e, int count);
struct Employee** deepCopyEmployees(struct Employee** e, int count);
