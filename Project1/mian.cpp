#include <iostream>
#include "Calculator.h"
#include "Number.h"

int main() {

	
	integer x("123456789");
	Decimal y("3.1415926");

	//cin >> x; // ��J 123456789
	//cin >> y; // ��J 3.1415926

	cout << x + y << endl;
	cout << x - y << endl;
	cout << x * y << endl;
	cout << x / y << endl;
	cout << endl;
	 x = "123 * 8 + 456";
	 y = "-1.0 / 3 - 45 / 13.0";

	 cout << x << endl;
	 cout << y << endl;

	vector<Number*> nums;
	nums.push_back(&x);
	nums.push_back(&y);
	for (const auto& num : nums)
		cout << *num << endl;

	return 0;
}