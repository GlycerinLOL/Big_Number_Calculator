#include "Number.h"
#include "Calculator.h"

Number::Number()
{
	num = "0";
	decimal = "";
	Integer = true;
	negative = false;
}

Number::Number(string a) 
{
	if (isdigit(a[0]) || (isdigit(a[1]) && a[0] == '-')) {
		int numberPart = a.length(), dot = a.length();
		Integer = true;
		if (a[0] == '-') negative = true;
		else negative = false;

		bool findDot = false;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '.') {
				dot = i;
				numberPart = i;
				Integer = false;
				findDot = true;
				break;
			}
		}
		num = a.substr(0, numberPart);
		if (findDot) decimal = a.substr(dot + 1, a.length() - numberPart);
		else decimal = "";

		if (negative) num.erase(num.begin());

		for (int i = decimal.length(); i <= 100; i++) {
			decimal.push_back('0');
		}
	}
	else {
		*this = Calculator::exist_var[a];
	}
}

Number& Number::operator=(Number a) 
{
	num = a.getNum();
	decimal = a.getDecimal();
	Integer = a.Integer;
	negative = a.negative;
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
	//¶¥¼h !
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

