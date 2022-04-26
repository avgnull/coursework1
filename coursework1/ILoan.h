#pragma once

//interface class
class ILoan {
public:
	virtual long double CalculateFinalCost() = 0;
	virtual long double CalculateDifference() = 0;
};