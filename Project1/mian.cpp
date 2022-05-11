#include <iostream>
#include "Calculator.h"
#include "Number.h"

int main() {

	integer x = "123 * 8 + 456";
	Decimal y = "-1.0 / 3 - 45 / 13.0";

	vector<Number*> nums;
	nums.push_back(&x);
	nums.push_back(&y);
	for (const auto& num : nums)
		cout << *num << endl;
	
	
	return 0;
}