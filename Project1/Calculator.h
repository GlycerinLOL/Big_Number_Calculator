#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <queue>
#include <stack>
#include <cmath>
#include "Number.h"

using namespace std;

class Calculator {
	vector<Number> exist_var;
	int weight(char op);
public:
	void RUN();
	string Input(bool& equal);
	void judgeFormat(string infix); //�P�_�W�r �Y���ܼƫh��������

	Number calculate(string posfix);
	bool isVariable(string str);

	string InfixtoPosfix(string infix);
	void Output();
	void test();
};