﻿#include <iostream>
#include "Calculator.h"
#include "Number.h"

int main() {
	Number x("123456789");
	Number y("3.1415926");

	cin >> x; // ¿é¤J 123456789
	cin >> y; // ¿é¤J 3.1415926

	cout << x + y << endl;
	cout << x - y << endl;
	cout << x * y << endl;
	cout << x / y << endl;

	//Integer x = "123 * 8 + 456";
	//Decimal y = "-1.0 / 3 - 45 / 13.0";

	//vector<NumberObject> nums;
	//nums.push_back(&x);
	//nums.push_back(&y);
	//for (const auto& num : nums)
	//cout << num << endl;


	//¾­¦¸ + ÅÜ¼Æ
	-B ^ 0.5
		//¤p¼Æ + ¾­¦¸
		(3.1415926 ^ 0.5) ^ (3 * 8.5)
		//¤p¼Æ + ¶¥­¼
		(8.5 / 0.25)!


		return 0;
}