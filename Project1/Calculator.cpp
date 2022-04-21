#include "Calculator.h"

void Calculator::RUN()
{
	while (true)
	{
        bool equal = false;
		string infix = Input(equal);
		judgeFormat(infix);
        Number ans = calculate(InfixtoPosfix(infix));
        if(!equal) Output();
	}
}

void judge_Type(string target) {

}

string Calculator::Input(bool& equal)
{
    stringstream input;
    regex NewVar("\w+");
    string inputStr;
    getline(cin, inputStr);
    if (inputStr.find('=')) { 
        input << inputStr;
        string temp;
        vector<string> allstr;
        while (input >> temp) {
            allstr.push_back(temp);
        }
        if (allstr[0] == "Set" && allstr[1] == "Integer" && regex_match(allstr[2], NewVar)) {
            for (int i = 2; i < allstr.size(); i++) {
                judge_Type(allstr[i]);
            }
        }
        else if (allstr[0] == "Set" && allstr[1] == "Decimal" && regex_match(allstr[2], NewVar)) {

        }
        else if (regex_match(allstr[0], NewVar)) {

        }
        else {
            cout << "Input Error!" << endl;
            return;
        }
    }
    else {

    }
}

void Calculator::judgeFormat(string infix)
{
    istringstream in(infix);
    int countLParentheses = 0;
    int countRParentheses = 0;
    string part;
    bool divide = false;
    //for (;in >> part;) {
       // if(isdigit(part[0]))
    //}
}
bool Calculator::isVariable(string str) {
    for (int i = 0; i < exist_var.size(); i++) {
        if (exist_var[i].name == str) {
            return true;
        }
    }
    return false;
}
Number Calculator::calculate(string posfix)
{
    istringstream istr(posfix);
    string str;
    stack<Number> temp;
    for (; istr >> str;)
    {
        Number num(str);
        if (isdigit(str[0]) || isVariable(str)) {
            temp.push(num);
        }
        else {
            switch (str[0])
            {
            case '+': 
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b + a);
                }
                else throw "stack has only one number!\n";
                break;
            case '-': 
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b - a);
                }
                else throw "stack has only one number!\n";
                break;
            case '*': 
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b * a);
                }
                else throw "stack has only one number!\n";
                break;
            case '/':
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b / a);
                }
                else throw "stack has only one number!\n";
                break;
            case '^':
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b ^ a);
                }
                else throw "stack has only one number!\n";
                break;
            case '!':
                if (temp.size() >= 1) {
                    Number a = temp.top();
                    temp.pop();
                    Number b;
                    temp.push(a % b);
                }
                else throw "stack has no number!\n";
                break;
            }
        }
    }
    return temp.top();
}

int Calculator::weight(char op)
{
    switch (op)
    {
    case '(': return -1;
    case '!':  return 3; //push into queue directly
    case '^': return 2;
    case '*': case '/': case '%': return 1;
    case '+': case '-': return 0;
    }
}

string Calculator::InfixtoPosfix(string infix)
{
    istringstream in(infix);
    ostringstream posfix;
    stack<char> saveOperator;

    string temp;
    for (; in >> temp;) {
        if (isdigit(temp[0])) {
            posfix << temp << " ";
        }
        else {
            switch (temp[0])
            {
            case '(': saveOperator.push('('); break;
            case ')': 
                for (; saveOperator.top() != '(';) {
                    if (!saveOperator.empty()) {
                        posfix << saveOperator.top() << " ";
                        saveOperator.pop();
                    }
                }
                saveOperator.pop();
                break;
            case '+': case '-': case '*': case '/': case '^': case '!': case '%':
                for (; !saveOperator.empty() && weight(temp[0]) <= weight(saveOperator.top());) {
                    if (!saveOperator.empty()) {
                        posfix << saveOperator.top() << " ";
                        saveOperator.pop();
                    }
                }
                saveOperator.push(temp[0]);
                break;
            }
        }
    }

    for (; !saveOperator.empty() ;) {
        posfix << saveOperator.top() << " ";
        saveOperator.pop();
    }
    return posfix.str();
}

void Calculator::Output()
{
}

void Calculator::test()
{
	Number A("5");
	Number C("abc");


    int temp;
	std::cout << InfixtoPosfix("( ( 2 + 3 ! ) ! / 5 ^ 3 )") << '\n';
    std::cin >> temp;
}
