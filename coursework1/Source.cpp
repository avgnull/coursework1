#include <iostream>
#include <vector>
#include <iomanip>
#include "Loan.h"
#include "SimpleInterest.h"
#include "CompoundInterest.h"
#include "AccruedInterest.h"

int main(void) {
	long double sum = 4000.0, percent = 0.1, months;
	months = 60;
	long double accretion = 4;
	AccruedInterest a(sum, percent, months, accretion);
	Loan* a1 = &a;
	long double fin = a1->CalculateFinalCost();
	std::cout << std::fixed << std::setprecision(2) << fin;
	return 0;
}