#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::to_string;
using std::string;
using std::vector;
using std::ostream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;


class Number {
	string num; //Bignum �� vector
	string decimal;
public:
	string name;
	bool Integer;
	bool negative;
	Number();
	Number(string a);

	inline string getNum() { return num; }
	inline string getDecimal() { return decimal; }

	Number& operator = (Number a);
	Number operator + (Number a);
	Number operator - (Number a);
	Number operator * (Number a);
	Number operator / (Number a);
	Number operator ^ (Number a);
	Number operator % (Number a);
	friend std::ostream& operator << (std::ostream& out, Number a);

	
};