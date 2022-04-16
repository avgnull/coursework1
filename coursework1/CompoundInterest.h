#pragma once
#include "Loan.h"
#include <cmath>

class CompoundInterest : public Loan {
public:
	CompoundInterest() {
	}
	~CompoundInterest() {
	}
	CompoundInterest(long double sum, long double percent, long double months) : Loan(sum, percent, months) {

	}
	long double CalculateFinalCost() {
		long double Fcost, years, percent, sum;
		years = LoanGetMonths() / 12.0;
		percent = LoanGetPercent();
		sum = LoanGetSum();
		Fcost = sum * std::pow((1 + percent), years);
		return Fcost;
	}
};