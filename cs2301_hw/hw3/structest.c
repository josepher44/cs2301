#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"
#include <time.h>

int main(int atgc, char *argv[]) {
	struct Employee *e;
	struct Employee *r;
	struct Employee **company;
	struct Employee **cheapKnockOffBrand;
	struct Employee **wellFundedCompetitor;
	int count = 6;

	srand(time(0));

	e = makeEmployee("Joe", 1991, 2010);
	r = makeRandomEmployee();
	company = makeEmployeeArray(6);
	cheapKnockOffBrand = shallowCopyEmployees(company, count);
	wellFundedCompetitor = deepCopyEmployees(company, count);

	printEmployee(e);
	printEmployee(r);
	printEmployeeStruct(company, count);
	printf("\nShallow copy:\n");
	printEmployeeStruct(cheapKnockOffBrand, count);
	printf("\nDeep copy:\n");
	printEmployeeStruct(wellFundedCompetitor, count);
	//The company has gone belly-up, fire everybody!
	freeEmployees(company, count);

	return 0;
}
