#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include "Number.h"

using namespace std;

class Calculator {
	map<string, Number> exist_var;
	int weight(char op);
public:
	void RUN();
	string Input(bool& equal);
	void judgeFormat(string infix); //�P�_�W�r �Y���ܼƫh��������

	Number calculate(string posfix);
	bool isVariable(string str);
	auto is_Var_exist(string name);
	void power_convert(vector<string>& input, int index);

	string InfixtoPosfix(string infix);
	void Output(string ans);
	void test();
};