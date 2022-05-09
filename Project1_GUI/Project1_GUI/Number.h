#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Number {
	string num;
	string decimal;
	string deNum;
	string deDecimal;
public:
	string name;
	bool Integer;
	bool negative;
	Number();
	Number(string a);
	Number(const Number& a);

	inline string getNum() { return num; }
	inline string getDecimal() { return decimal; }
	inline string getDeNum() { return deNum; }
	inline string getDeDecimal() { return deDecimal; }

	Number& operator = (Number a);
	Number operator + (Number a);
	Number operator - (Number a);
	Number operator * (Number a);
	Number operator / (Number a);
	Number operator ^ (Number a);
	Number operator % (Number a);
	friend std::ostream& operator << (std::ostream& out, Number a);


};