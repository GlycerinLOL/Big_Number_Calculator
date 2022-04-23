#include "Calculator.h"

void Calculator::RUN()
{
	while (true)
	{
        bool equal = false;
		string ans = Input(equal);
        if(!equal) Output(ans);
	}
}

auto Calculator::is_Var_exist(string name) 
{
    auto it = exist_var.find(name);
    if (it == exist_var.end()) {
        throw "Error: Variable doesn't exist.";
    }
    else {
        return it;
    }
}

string process_Power(string front, string back) {

    //對前後字串做一樣的事後 再把處理過的字串回傳 -> front + "^ " + back
    istringstream fin(front), bin(back);
    string tmp;
    ostringstream ans;
    for (; fin >> tmp;) {
        if (tmp == "Power") {
            bool comma = false;
            int power = 0;
            ostringstream osfront, osback;
            int Lcount = 0;
            string temp;
            fin >> temp;
            do
            {
                if (temp == "Power") {
                    power++;
                }
                if (temp[0] == ',' && power != 0) power--;
                else if (temp[0] == ',' && comma == false) {
                    comma = true;
                    continue;
                }

                if (temp[0] == '(') Lcount++;
                else if (temp[0] == ')') Lcount--;

                if (comma) osback << temp << " ";
                else osfront << temp << " ";

            } while (Lcount != 0 && fin >> temp);
            ans << process_Power(osfront.str(), osback.str()) << " ";
        }
        else ans << tmp << " ";
    }
    ans << ") ";

    ostringstream ans2;
    ans2 << "( ";
    for (; bin >> tmp;) {
        if (tmp == "Power") {
            bool comma = false;
            int power = 0;
            ostringstream osfront, osback;
            int Lcount = 0;
            string temp;
            bin >> temp;
            do
            {
                if (temp == "Power") {
                    power++;
                }
                if (temp[0] == ',' && power != 0) power--;
                else if (temp[0] == ',' && comma == false) {
                    comma = true;
                    continue;
                }

                if (temp[0] == '(') Lcount++;
                else if (temp[0] == ')') Lcount--;

                if (comma) osback << temp << " ";
                else osfront << temp << " ";

            } while (Lcount != 0 && bin >> temp);
            ans2 << process_Power(osfront.str(), osback.str()) << " ";
        }
        else ans2 << tmp << " ";
    }
    return ans.str() + "^ " + ans2.str();
}

string Calculator::Input(bool& equal)
{
    stringstream input;
    regex NewVar("\w+");
    string inputStr;
    getline(cin, inputStr);
    if (inputStr.find('=')) { 
        equal = true;
        input << inputStr;
        string temp;
        string returnSTR;
        vector<string> allstr;
        while (input >> temp) {
            allstr.push_back(temp); //將輸入字串拆分為component方便處理
        }
        if (allstr[0] == "Set" && allstr[1] == "Integer" && regex_match(allstr[2], NewVar) || allstr[3] == "=") { //Set Integer [Var] = formula
            Number temp;
            temp.name = allstr[2];
            temp.Integer = true;
            for (int i = 4; i < allstr.size(); i++) {
                returnSTR += allstr[i];
                if (i != allstr.size() - 1) {
                    returnSTR += " ";
                }
            }
            judgeFormat(returnSTR);
            temp = calculate(InfixtoPosfix(returnSTR));
            exist_var.emplace(temp.name, temp);
        }
        else if (allstr[0] == "Set" && allstr[1] == "Decimal" && regex_match(allstr[2], NewVar) || allstr[3] == "=") { //Set Decimal [Var] = formula
            Number temp;
            temp.name = allstr[2];
            temp.Integer = false;
            for (int i = 4; i < allstr.size(); i++) {
                returnSTR += allstr[i];
                if (i != allstr.size() - 1) {
                    returnSTR += " ";
                }
            }
            judgeFormat(returnSTR);
            temp = calculate(InfixtoPosfix(returnSTR));
            exist_var.emplace(temp.name, temp);
        }
        else if (regex_match(allstr[0], NewVar) || allstr[1] == "=") { // [var] = formula
            auto it = is_Var_exist(allstr[0]);
            for (int i = 2; i < allstr.size(); i++) {
                returnSTR += allstr[i];
                if (i != allstr.size() - 1) {
                    returnSTR += " ";
                }
            }
            judgeFormat(returnSTR);
            it->second = calculate(InfixtoPosfix(returnSTR));
        }
        else {
            throw "Input Error!";
        }
    }
    else {
        Number temp;
        equal = false;
        judgeFormat(inputStr);
        temp = calculate(InfixtoPosfix(inputStr));
        return temp.getNum() + temp.getDecimal();
    }
}

void Calculator::judgeFormat(string infix)
{
    istringstream in(infix);
    int countLParentheses = 0;
    int countRParentheses = 0;
    string part;
    bool divide = false;
    bool sign = true;
    bool number = false;
    bool Integer = false;
    for (; in >> part;) {
        if (isdigit(part[0])) {
            for (int i = 0; i < part.length(); i++) {
                if (part[i] == '.') {
                    Integer = false;
                    break;
                }
            }
            int digit = stoi(part);
            if (divide && digit == 0) throw "Error: Can't divide zero.";
            if (number) throw "Error: Two numbers connect.";

            divide = false;
            sign = false;
            number = true;
        }
        else if (part[0] == '(' || part[0] == ')' || part[0] == '+' || part[0] == '-' ||
            part[0] == '*' || part[0] == '/' || part[0] == '!' || part[0] == '^') {

            if (sign) throw "Error: Two mathmatical symbols connect.";
            if (part[0] == '!' && (Integer == false || negative)) throw "Wrong factorial type.";
            switch (part[0])
            {
            case '(': countLParentheses++; divide = false; sign = true; number = false; break;
            case ')': countRParentheses++; divide = false; sign = true; number = false; break;
            case '/': divide = true; sign = true; number = false; break;
            default:
                divide = false; sign = true; number = false; break;
            }
        }
        else {
            if (!isVariable(part)) throw "Error: Variable doesn't exist.";
        }
    }
}
bool Calculator::isVariable(string str) {
    for (auto i:exist_var) {
        if (i.first == str) {
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

void Calculator::Output(string ans)
{
    cout << ans << endl;
}

void Calculator::test()
{
	Number A("5");
	Number C("abc");


    int temp;
	std::cout << InfixtoPosfix("( ( 2 + 3 ! ) ! / 5 ^ 3 )") << '\n';
    std::cin >> temp;
}
