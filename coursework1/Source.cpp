#include <iostream>
#include <vector>
#include <iomanip>
#include "Loan.h"
#include "SimpleInterest.h"
#include "CompoundInterest.h"
#include "AccruedInterest.h"

int main(void) {
	std::vector<SimpleInterest> Sl;
	std::vector<CompoundInterest> Cl;
	std::vector<AccruedInterest> Al;
	std::vector <Loan*> loans;
	long double check = -1;
	std::cout << "--------------------------------------------------" << std::endl;
	while (check != 0) {
		std::cout << std::endl;
		std::cin >> check;
		std::cout << std::endl;
		if (check == 1) {
			long double sum, percent, months;
			std::cin >> sum >> percent >> months;
			percent = percent / 100.0;
			SimpleInterest interest(sum, percent, months);
			Sl.push_back(interest);
			int num = Sl.size() - 1;
			loans.push_back(&Sl[num]);
		}
		else if (check == 2) {
			long double sum, percent, months;
			std::cin >> sum >> percent >> months;
			percent = percent / 100.0;
			CompoundInterest interest(sum, percent, months);
			Cl.push_back(interest);
			int num = Cl.size() - 1;
			loans.push_back(&Cl[num]);
		}
		else if (check == 3) {
			long double sum, percent, months, periods;
			std::cin >> sum >> percent >> months >> periods;
			percent = percent / 100.0;
			AccruedInterest interest(sum, percent, months, periods);
			Al.push_back(interest);
			int num = Al.size() - 1;
			loans.push_back(&Al[num]);
		}
		else if (check != 0) {
			std::cout << "Wrong number! Try again." << std::endl;
		}
		std::cout << std::endl << "--------------------------------------------------" << std::endl;
	}
	check = -1;
	int num = -1;
	while (check != 0) {
		std::cout << std::endl;
		std::cin >> check;
		std::cout << std::endl;
		std::cin >> num;
		if (num <= (loans.size() - 1)) {
			if (check == 1) {
				std::cout << std::endl << std::fixed << std::setprecision(2) << "Final cost: " << loans[num]->CalculateFinalCost() << "\tDifference: " << loans[num]->CalculateDifference() << std::endl;
			}
			else if (check == 2) {
				std::cout << std::endl;
				long double change;
				std::cin >> change;
				std::cout << std::endl << std::endl << loans[num]->LoanGetSum() << " + " << change;
				*loans[num] + change;
				std::cout << " = " << loans[num]->LoanGetSum() << std::endl;
			}
			else if (check == 3) {
				std::cout << std::endl;
				long double sum;
				std::cin >> sum;
				std::cout << std::endl << std::endl << loans[num]->CalculateFinalCost() << " - " << sum;
				std::cout << " = " << loans[num]->CalculateDifference(sum) << std::endl;
			}
			else {
				std::cout << std::endl << std::endl << "Wrong number! Action can be 1,2 or 3. Try again (with inputing number in massive too)." << std::endl;
			}
		}
		else if (num >= 0) {
			std::cout << std::endl << std::endl << "Wrong number! Massive is not that big. Try again (with inputing action too)." << std::endl;
		}
		else if (num <= -1) {
			std::cout << std::endl << std::endl << "Wrong number! Input must be 0 or above. Try again (with inputing action too)." << std::endl;
		}
	}
	return 0;
}