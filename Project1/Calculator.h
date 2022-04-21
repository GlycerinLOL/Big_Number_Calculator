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

typedef struct formula {
	vector<Number> oprandRecord;
	stack<string> operatorRecord;
}formula;

class Calculator {
	formula record;
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