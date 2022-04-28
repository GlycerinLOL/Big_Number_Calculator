#include "Calculator.h"

map<string, Number> Calculator::exist_var;

void Calculator::RUN()
{
    while (true)
    {
        bool equal = false;
        Number ans = Input(equal);
        if (!equal) Output(ans);
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

    //撠�敺�銝脣�銝璅��鈭� ������摮葡� -> front + "^ " + back
    istringstream fin(front), bin(back);
    string tmp;
    ostringstream ans;
    //ans << "( ";
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
    if (back != "") ans << ") ";

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

    if (back == "") return ans.str();
    return ans.str() + "^ " + ans2.str();
}

Number Calculator::Input(bool& equal)
{
    stringstream input;
    regex NewVar("\w+");
    string inputStr;
    getline(cin, inputStr);

    std::size_t found = inputStr.find('=');
    if (found != std::string::npos) {

        equal = true;
        input << inputStr;
        string temp;
        string returnSTR;
        vector<string> allstr;
        while (input >> temp) {
            allstr.push_back(temp); //撠撓�亙�銝脫��component�嫣噶��
        }
        if ((allstr[0] == "Set" && allstr[1] == "Integer") && (regex_match(allstr[2], NewVar) || allstr[3] == "=")) { //Set Integer [Var] = formula
            Number temp;
            temp.name = allstr[2];
            temp.Integer = true;
            for (int i = 4; i < allstr.size(); i++) {
                returnSTR += allstr[i];
                if (i != allstr.size() - 1) {
                    returnSTR += " ";
                }
            }
            returnSTR = process_Power(returnSTR, "");
            judgeFormat(returnSTR);
            temp = calculate(InfixtoPosfix(returnSTR));
            exist_var.emplace(temp.name, temp);
        }
        else if ((allstr[0] == "Set" && allstr[1] == "Decimal") && (regex_match(allstr[2], NewVar) || allstr[3] == "=")) { //Set Decimal [Var] = formula
            Number temp;
            temp.name = allstr[2];
            for (int i = 4; i < allstr.size(); i++) {
                returnSTR += allstr[i];
                if (i != allstr.size() - 1) {
                    returnSTR += " ";
                }
            }
            returnSTR = process_Power(returnSTR, "");
            judgeFormat(returnSTR);
            temp = calculate(InfixtoPosfix(returnSTR));
            temp.Integer = false;
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
            returnSTR = process_Power(returnSTR, "");
            judgeFormat(returnSTR);
            it->second = calculate(InfixtoPosfix(returnSTR));
        }
        else {
            throw "Input Error!";
        }
    }
    else {
        equal = false;
        inputStr = process_Power(inputStr, "");
        judgeFormat(inputStr);
        return calculate(InfixtoPosfix(inputStr));
    }
}

void Calculator::judgeFormat(string infix)
{
    istringstream in(infix);
    int countLParentheses = 0;  //閮�撌血�祈��賊��臬�貊泵
    int countRParentheses = 0;
    string part;
    bool divide = false;  // judging divide 0 or not
    bool sign = true;     // judging two mathmatical symbols connect or not. ex: 2 * * 2 �� 2 + + 2 (x)
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
        else if (part[0] == '!') {
            if (var_temp.Integer == false || var_temp.negative)
                throw "Error: Wrong factorial type.";
            if (sign) {
                throw "Error: Two mathmatical symbols connect or begin with mathmatical symbol.";
            }
            divide = false;
            sign = false;
            number = false;
        }
        else if (part[0] == '+' || part[0] == '-' ||
            part[0] == '*' || part[0] == '/' || part[0] == '^') {

            if (sign) {
                throw "Error: Two mathmatical symbols connect or begin with mathmatical symbol.";
            }
            switch (part[0])
            {
            case '/':
                divide = true; sign = true; number = false; break;
            default:
                divide = false; sign = true; number = false; break;
            }
        }
        else { //if it's not digit or symbol, judging whether it is variable.
            if (!isVariable(part)) throw "Error: Variable doesn't exist.";
            else {
                divide = false;
                sign = false;
                number = true;
            }
        }
    }

    if (countLParentheses != countRParentheses) throw "Incomplete parentheses.";
}
bool Calculator::isVariable(string str) {
    for (auto i : exist_var) {
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
        //cout << str << '\n';
        if (isdigit(str[0]) || (isdigit(str[1]) && str[0] == '-') || isVariable(str)) {
            temp.push(Number(str));
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
                else throw "Can't a + b, for stack has only one number!\n";
                break;
            case '-':
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b - a);
                }
                else throw "Can't a - b, for stack has only one number!\n";
                break;
            case '*':
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b * a);
                }
                else throw "Can't a * b, for stack has only one number!\n";
                break;
            case '/':
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b / a);
                }
                else throw "Can't a / b, for stack has only one number!\n";
                break;
            case '^':
                if (temp.size() >= 2) {
                    Number a = temp.top();
                    temp.pop();
                    Number b = temp.top();
                    temp.pop();

                    temp.push(b ^ a);
                }
                else throw "Can't a ^ b, for stack has only one number!\n";
                break;
            case '!':
                if (temp.size() >= 1) {
                    Number a = temp.top();
                    temp.pop();
                    Number b;
                    temp.push(a % b);
                }
                else throw "Can't a !, for stack has no number!\n";
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
        if (isdigit(temp[0]) || (isdigit(temp[1]) && temp[0] == '-') || isVariable(temp)) {
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

    for (; !saveOperator.empty();) {
        posfix << saveOperator.top() << " ";
        saveOperator.pop();
    }
    return posfix.str();
}

string Calculator::Output(Number ans)
{
    string toReturn = "";
    if (ans.negative)
    {
        toReturn += "-";
    }
    toReturn += ans.getNum();
    if (!ans.Integer)
        toReturn += '.' + ans.getDecimal();

    return toReturn;
}

void Calculator::test()
{
    /*
    Number A("-123.16543");
    Number C("abc");
    string temp;
    getline(std::cin,temp);
    judgeFormat(temp);
    //std::cout << A.getNum() << ' ' << A.getDecimal() << ' ' << A.Integer << ' ' << A.negative << '\n';
    */
    while (true)
    {
        bool equal = false;
        Number ans = Input(equal);
        if (!equal) Output(ans);
    }
}