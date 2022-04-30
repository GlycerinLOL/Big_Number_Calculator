#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Number {
	string num; // ���l���
	string decimal; // ���l�p��
	string deNum; // �������
	string deDecimal; // ���l�p��
public:
	string name;
	bool Integer;
	bool negative;
	Number();
	Number(string a);

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