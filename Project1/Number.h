#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::to_string;
using std::string;
using std::vector;
using std::ostream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;


class Number {
public:
    string num;
    string decimal;
    string deNum;
    string deDecimal;

    string name;
    bool Integer;
    bool negative;
    Number();
    Number(string a);
    Number(const Number& a);

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

class Integer : public Number {
public:
    Integer() : Number() {};
    Integer(string a) : Number(a) {};
    Integer(const Integer& a) : Number(a) {};

};

class Decimal : public Number {
public:
    Decimal() : Number() {};
    Decimal(string a) : Number(a) {};
    Decimal(const Decimal& a) : Number(a) {};

};