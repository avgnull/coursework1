#pragma once
#include "Loan.h"
#include <cmath>

class AccruedInterest : public Loan {
private:
	long double accretion;
public:
	AccruedInterest() {
	}
	~AccruedInterest() {
	}
	AccruedInterest(long double sum, long double percent, long double months, long double accretion) : Loan(sum, percent, months) {
		this->accretion = accretion;
	}
	long double CalculateFinalCost() {
		long double Fcost, years, percent, sum, accretion;
		Fcost = this->sum * std::pow((1 + (this->percent / this->accretion)), ((this->months / 12) * this->accretion));
		return Fcost;
	}
	void operator +(long double sum) {
		this->sum += sum;
	}
};