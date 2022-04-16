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
		accretion = this->accretion;
		years = LoanGetMonths() / 12.0;
		percent = LoanGetPercent();
		sum = LoanGetSum();
		Fcost = sum * std::pow((1 + (percent / accretion)), (years * accretion));
		return Fcost;
	}
};