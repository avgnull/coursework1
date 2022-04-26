#pragma once
#include "ILoan.h"

//base class
class Loan : public ILoan {
protected:
	long double sum, percent, months;
public:
	Loan() {
	}
	~Loan() {
	}
	Loan(long double sum, long double percent, long double months) {
		this->sum = sum;
		this->percent = percent;
		this->months = months;
	}
	void LoanSetSum(long double sum) {
		this->sum = sum;
	}
	void LoanSetPercent(long double percent) {
		this->percent = percent;
	}
	long double LoanGetSum() {
		return this->sum;
	}
	long double LoanGetPercent() {
		return this->percent;
	}
	void LoanSetMonths(long double months) {
		this->months = months;
	}

	long double LoanGetMonths() {
		return this->months;
	}
	void operator +(long double sum) {
		this->sum += sum;
	}
	long double CalculateDifference() {
		long double Diff, Fcost = this->CalculateFinalCost();
		Diff = Fcost - this->sum;
		return Diff;
	}
	long double CalculateDifference(long double sum) {
		long double Diff, Fcost = this->CalculateFinalCost();
		Diff = Fcost - sum;
		if (Diff < 0) {
			Diff = Diff * (-1);
		}
		return Diff;
	}
};