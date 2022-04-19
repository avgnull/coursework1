#include <iostream>
#include <vector>
#include <iomanip>
#include "Loan.h"
#include "SimpleInterest.h"
#include "CompoundInterest.h"
#include "AccruedInterest.h"

int main(void) {
	std::cout << "This programm is able to calculate final cost and difference for 3 types of loans" << std::endl;
	std::cout << "To use this programm you should input number 1,2 or 3." << std::endl;
	std::cout << "Number 1 will count final cost and difference for simple interest. Number 2 will do the same for compound interest." << std::endl;
	std::cout << "And number 3 will do the same for accrued inerest." << std::endl;
	std::cout << "After that number you should input 3 values (4 in case of accrued interest)." << std::endl;
	std::cout << "values are: sum of loan, percent (15 for example, not 0,15), loan term (in months) and number of interest periods per year for accrued interest (for example once a month would be 12)" << std::endl;
	short int i;
	std::cin >> i;
	if (i == 1) {
		long double sum, percent, months;
		std::cin >> sum >> percent >> months;
		percent = percent / 100.0;
		SimpleInterest interest(sum, percent, months);
		Loan* l = &interest;
		std::cout << std::fixed << std::setprecision(2) << "Final cost: " << l->CalculateFinalCost() << "\tDifference: " << l->CalculateDifference();
	}
	else if (i == 2) {
		long double sum, percent, months;
		std::cin >> sum >> percent >> months;
		percent = percent / 100.0;
		CompoundInterest interest(sum, percent, months);
		Loan* l = &interest;
		std::cout << std::fixed << std::setprecision(2) << "Final cost: " << l->CalculateFinalCost() << "\tDifference: " << l->CalculateDifference();
	}
	else if (i == 3) {
		long double sum, percent, months, periods;
		std::cin >> sum >> percent >> months >> periods;
		percent = percent / 100.0;
		AccruedInterest interest(sum, percent, months, periods);
		Loan* l = &interest;
		std::cout << std::fixed << std::setprecision(2) << "Final cost: " << l->CalculateFinalCost() << "\tDifference: " << l->CalculateDifference();
	}
	else {
		std::cout << "Wrong number!" << std::endl;
	}
	return 0;
}