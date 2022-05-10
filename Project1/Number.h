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
using std::strlen; 


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
    friend ostream& operator << (ostream& out, Number a);
};

class integer : public Number {
public:
    integer() : Number() { this->Integer = true; };
    integer(string a) : Number(a) {};
    integer(const integer& a) : Number(a) {};
    friend std::istream& operator >> (std::istream& in, integer& a);
    integer& operator = (Number& a);
    integer& operator = (const char* cp);
};

class Decimal : public Number {
public:
    Decimal() : Number() { this->Integer = false; };
    Decimal(string a) : Number(a) {};
    Decimal(const Decimal& a) : Number(a) {};
    friend std::istream& operator >> (std::istream& in, Decimal& a);
    Decimal& operator = (Number& a);
    Decimal& operator = (const char* cp);
};