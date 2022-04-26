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
		long double Fcost;
		Fcost = this->sum * std::pow((1 + this->percent), (this->months / 12.0));
		return Fcost;
	}
};