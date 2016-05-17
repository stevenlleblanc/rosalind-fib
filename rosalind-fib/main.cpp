/* Solution to rosalind.info/problems/fib, "Rabbits and Recurrence Relations"
* Given positive integers n <= 40 and k <= 5, return the number of rabbit
* pairs present after n months if we begin with 1 pair, and in each generation,
* each pair produces a litter of k rabbit pairs.
*/

#include <iostream>
using namespace std;

unsigned long long rabbit_reccurence(const unsigned int offspring, unsigned int & curr_month, 
	const unsigned int total_months, const unsigned long long f2, const unsigned long long f1) {
	/* Recursive loop, calculating next total size from the previous month's size and running
	* until the desired month is reached
	*/

	unsigned long long f0;

	f0 = (offspring * f2) + f1;
	curr_month++;

	if (curr_month == total_months) {
		cout << "It is now month #" << curr_month << ", the final month." << endl;
		cout << "Final number of rabbit pairs: " << f0 << endl;
		return f0;
	}
	else {
		cout << "It is currently month #" << curr_month << endl;
		cout << "Current number of rabbit pairs: " << f0 << endl;
		rabbit_reccurence(offspring, curr_month, total_months, f1, f0);
	}
}

int main() {

	unsigned int curr_month = 1;
	unsigned int months;
	unsigned int offspring;

	cout << "Please provide the number of months: " << endl;
	cin >> months;
	cout << "Please provide the number of pairs produced by each pair of rabbits: " << endl;
	cin >> offspring;

	cout << "It is currently month #1" << endl;
	cout << "Current number of rabbit pairs: 1" << endl;

	rabbit_reccurence(offspring, curr_month, months, 0, 1);

	return 0;
}