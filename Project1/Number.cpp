#include "Number.h"

Number::Number()
{
	num = "";
	decimal = "";
	Integer = true;
	negative = false;
}

Number::Number(string a) : num(a) {};

Number& Number::operator=(Number a) 
{
	num = a.getNum();
	decimal = a.getDecimal();
	return *this;
}

Number Number::operator+(Number a)
{
	return Number();
}

Number Number::operator-(Number a)
{
	return Number();
}

Number Number::operator*(Number a)
{
	return Number();
}

Number Number::operator/(Number a)
{
	return Number();
}

Number Number::operator^(Number a)
{
	//Have pow(?,0.5)
	return Number();
}

Number Number::operator%(Number a)
{
	//¶¥¼h
	int temp = stoi(num);
	long long int ans = 1;
	for (int i = 1; i <= temp; i++) ans *= i;
	return Number(to_string(ans));
}

ostream& operator << (ostream& out, Number a) {
	out << a.getNum();
	if (a.getDecimal() != "") out << '.' << a.getDecimal();
	return out;
}

