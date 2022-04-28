#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <stack>
#include <map>
#include "Number.h"
using std::cin;
using std::cout;
using std::getline;
using std::endl;
using std::map;
using std::string;
using std::vector;
using std::regex;
using std::stack;

class Calculator {
	int weight(char op);
public:
	static map<string, Number> exist_var;
	string show_exist;
	void RUN();
	Number Input(bool& equal);
	void judgeFormat(string infix); //判斷名字 若有變數則直接替換

	Number calculate(string posfix);
	bool isVariable(string str);
	auto is_Var_exist(string name);

	string InfixtoPosfix(string infix);
	string Output(Number ans);
	void test();
};