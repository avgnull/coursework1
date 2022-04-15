#include <iostream>
#include <vector>
#include <iomanip>
#include "Loan.h"
#include "SimpleLoan.h"

int main(void) {
	long double sum = 650000.0, percent = 0.15, months;
	months = 96;
	SimpleLoan a(sum, percent, months);
	Loan *a1 = &a;
	long double fin = a1->CalculateFinalCost();
	std::cout << std::fixed << std::setprecision(2) << fin;
	return 0;
}