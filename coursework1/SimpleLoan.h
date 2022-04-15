#pragma once
#include "Loan.h"

class SimpleLoan : public Loan {
public:
	SimpleLoan() {
	}
	~SimpleLoan() {
	}
	SimpleLoan(long double sum, long double percent, long double months) : Loan(sum, percent, months) {

	}
	long double CalculateFinalCost() {
		long double Fcost, years, percent, sum;
		years = LoanGetMonths() / 12.0;
		percent = LoanGetPercent();
		sum = LoanGetSum();
		Fcost = sum * (1 + (years * percent));
		return Fcost;
	}
};