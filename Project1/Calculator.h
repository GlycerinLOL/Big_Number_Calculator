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
	void judgeFormat(string infix); //判斷名字 若有變數則直接替換

	Number calculate(string posfix);
	bool isVariable(string str);

	string InfixtoPosfix(string infix);
	void Output();
	void test();
};