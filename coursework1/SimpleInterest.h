#pragma once
#include "Loan.h"

class SimpleInterest : public Loan {
public:
	SimpleInterest() {
	}
	~SimpleInterest() {
	}
	SimpleInterest(long double sum, long double percent, long double months) : Loan(sum, percent, months) {

	}
	long double CalculateFinalCost() {
		long double Fcost;
		Fcost = this->sum * (1 + ((this->months / 12.0) * this->percent));
		return Fcost;
	}
	void operator +(long double sum) {
		this->sum += sum;
	}
};