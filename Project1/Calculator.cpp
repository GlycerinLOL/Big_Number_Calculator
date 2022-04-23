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
    /*
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
    */
    return "";
}

void Calculator::judgeFormat(string infix)
{
    istringstream in(infix);
    int countLParentheses = 0;  //計算左右括號數量是否相符
    int countRParentheses = 0;
    string part;
    bool divide = false;  // judging divide 0 or not
    bool sign = true;     // judging two mathmatical symbols connect or not. ex: 2 * * 2 、 2 + + 2 (x)
    bool number = false;  // judging two numbers connect or not. ex: 2 2 + 3 1 2 (x) -> should be 22 + 312 (o)
    Number var_temp;
    for (; in >> part;) {
        if (isdigit(part[0]) || (isdigit(part[1]) && part[0] == '-')) {
            var_temp = Number(part);
            if (divide && (var_temp.Integer && var_temp.getNum() == "0")) throw "Error: Can't divide zero.";
            if (number) throw "Error: Two numbers connect.";

            divide = false;
            sign = false;
            number = true;
        }
        else if (part[0] == '(' || part[0] == ')') {
            if (part[0] == '(') countLParentheses++;
            else countRParentheses++;

            divide = false;
            sign = false;
            number = false;
        }
        else if (part[0] == '+' || part[0] == '-' ||  
            part[0] == '*' || part[0] == '/' || part[0] == '!' || part[0] == '^') {

            if (sign) {
                throw "Error: Two mathmatical symbols connect or begin with mathmatical symbol.";
            }
            if (part[0] == '!' && (var_temp.Integer == false || var_temp.negative)) throw "Wrong factorial type.";
            switch (part[0])
            {
            case '/': 
                divide = true; sign = true; number = false; break;
            default:
                divide = false; sign = true; number = false; break;
            }
        }
        else { //if it's not digit or symbol, judging whether it is variable.
            bool find = false;
            for (int i = 0; i < exist_var.size(); i++) {
                if (part == exist_var[i].name) {
                    find = true;
                    break;
                }
            }
            if (!find) throw "Error: Variable doesn't exist.";
        }
    }

    if (countLParentheses != countRParentheses) throw "Incomplete parentheses.";
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
    return -2;
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
	Number A("-123.16543");
	Number C("abc");
    string temp;
    getline(std::cin,temp);

    judgeFormat(temp);
	//std::cout << A.getNum() << ' ' << A.getDecimal() << ' ' << A.Integer << ' ' << A.negative << '\n';
}
