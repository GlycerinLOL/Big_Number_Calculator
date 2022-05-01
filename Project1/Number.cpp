#include "Number.h"
#include "Calculator.h"

string doStrPlus(string a, string b);
string doStrMinus(string a, string b);// only big - small
string doStrTimes(string a, string b);
string doStrDevide(string a, string b);
string doStrMode(string a, string b);

string doStrPlus(string a, int b);
string doStrMinus(string a, int b);// only big - small
string doStrTimes(string a, int b);
int isBigger(string a, string b);

Number::Number()
{
	num = "0";
	while (decimal.size() < 100)
	{
		decimal.push_back('0');
	}
	deNum = "1"; 
	while (deDecimal.size() < 100)
	{
		deDecimal.push_back('0');
	}
	Integer = true;
	negative = false;
}

//
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

		for (int i = decimal.length(); i < 100; i++) {
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
	deNum = a.getDeNum();
	deDecimal = a.getDeDecimal();
	negative = a.negative;
	return *this;
}

Number Number::operator+(Number a)
{
	Number toReturn, subThis = *this, subA = a; // using these variables to do operation
	stringstream ssToRe, ssSubThis, ssSubA;
	if ((a.negative && this->negative) || (!a.negative && !this->negative)) //"*this" and "a" are both positive or negtive
	{
		if (isBigger(deNum + deDecimal, a.deNum + a.deDecimal) != 0)
		{
			string subNum, subDe, subANum, subADe;
			
			subNum = doStrTimes(num + decimal, a.deNum + a.deDecimal);
			subANum = doStrTimes(a.num + a.decimal, deNum + deDecimal);
			subDe = doStrTimes(deNum + deDecimal, a.deNum + a.deDecimal);
			subADe = doStrTimes(a.deNum + a.deDecimal, deNum + deDecimal);

			subThis.decimal = subNum.substr(subNum.size() - (decimal.size() + a.deDecimal.size()), (decimal.size() + a.deDecimal.size()));
			subThis.num = subNum.substr(0, subNum.size() - (decimal.size() + a.deDecimal.size()));
			subThis.deDecimal = subDe.substr(subDe.size() - (decimal.size() + a.deDecimal.size()), (decimal.size() + a.deDecimal.size()));
			subThis.deNum = subDe.substr(0, subDe.size() - (decimal.size() + a.deDecimal.size()));

			subA.decimal = subANum.substr(subANum.size() - (a.decimal.size() + deDecimal.size()), (decimal.size() + a.deDecimal.size()));
			subA.num = subANum.substr(0, subANum.size() - (a.decimal.size() + deDecimal.size()));
			subA.deDecimal = subADe.substr(subADe.size() - (a.decimal.size() + deDecimal.size()), (decimal.size() + a.deDecimal.size()));
			subA.deNum = subADe.substr(0, subADe.size() - (a.decimal.size() + deDecimal.size()));
		}

		toReturn.deNum = subThis.deNum;
		toReturn.deDecimal = subThis.deDecimal.substr(0, 100);

		while (toReturn.deDecimal.size() < 100)
		{
			toReturn.deDecimal.push_back('0');
		}

		// tell whether the return is + or -
		if (a.negative) // -
		{
			toReturn.negative = true;
		}
		else // +
		{
			toReturn.negative = false;
		}

		// operating begins
		int timesToDo;

		// identifing type1 + type2 
		if (a.Integer && this->Integer) // int + int
		{
			timesToDo = 1;
			toReturn.Integer = true; // else
		}
		else
		{
			timesToDo = 2;
			toReturn.Integer = false;
		}

		if (a.num.size() > this->num.size())
		{
			while (subA.num.size() > subThis.num.size())
			{
				subThis.num.insert(subThis.num.begin(), '0');
			}
		}
		if (a.num.size() < subThis.num.size())
		{
			while (subA.num.size() < this->num.size())
			{
				subA.num.insert(subA.num.begin(), '0');
			}
		}

		// format
		for (int i = 1; i < subThis.num.size(); i += 2)
		{
			subThis.num.insert(subThis.num.begin() + i, ' ');
		}
		for (int i = 1; i < subA.num.size(); i += 2)
		{
			subA.num.insert(subA.num.begin() + i, ' ');
		}
		if (timesToDo == 2)
		{
			for (int i = 1; i < subThis.decimal.size(); i += 2)
			{
				subThis.decimal.insert(subThis.decimal.begin() + i, ' ');
			}
			for (int i = 1; i < subA.decimal.size(); i += 2)
			{
				subA.decimal.insert(subA.decimal.begin() + i, ' ');
			}
		}

		//operation

		for (int i = 0; i < (subA.num.size() / 2); i++) //reverse
		{
			char b = subThis.num[i];
			subThis.num[i] = subThis.num[subThis.num.size() - 1 - i];
			subThis.num[subThis.num.size() - 1 - i] = b;

			b = subA.num[i];
			subA.num[i] = subA.num[subA.num.size() - 1 - i];
			subA.num[subA.num.size() - 1 - i] = b;
		}

		if (timesToDo == 2)
		{
			for (int i = 0; i < 50; i++) //reverse
			{
				char b = subThis.decimal[i];
				subThis.decimal[i] = subThis.decimal[subThis.decimal.size() - 1 - i];
				subThis.decimal[subThis.decimal.size() - 1 - i] = b;

				b = subA.decimal[i];
				subA.decimal[i] = subA.decimal[subA.decimal.size() - 1 - i];
				subA.decimal[subA.decimal.size() - 1 - i] = b;
			}
		}

		int carry = 0;
		for (int i = 0; i < timesToDo; i++)
		{
			ssSubThis.clear(); 
			ssSubA.clear();
			ssToRe.clear();

			if (timesToDo == 1) // int
			{
				ssSubThis << subThis.num;
				ssSubA << subA.num;
			}
			else // dec
			{
				if (i == 0)
				{
					ssSubThis << subThis.decimal;
					ssSubA << subA.decimal;
				}
				else
				{
					ssSubThis << subThis.num;
					ssSubA << subA.num;
				}
			}

			int firNum = 0;
			int SecNum = 0;
			while (1)
			{
				ssSubThis >> firNum;
				ssSubA >> SecNum;

				int sum = firNum + SecNum + carry;
				if (sum >= 10)
				{
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				ssToRe << sum % 10; // need to be reversed
				if (ssSubThis.eof())
				{
					break;
				}
			}

			if (timesToDo == 1 || i == 1) // only when doing with "num" can do this
			{
				if (carry != 0)
				{
					ssToRe << carry;
				}
			}

			string temp;
			ssToRe >> temp;
			for (int i = 0; i < (temp.size() / 2); i++) //reverse
			{
				char b = temp[i];
				temp[i] = temp[temp.size() - 1 - i];
				temp[temp.size() - 1 - i] = b;
			}

			if (timesToDo == 1) // int
			{
				toReturn.num = temp;
				for (int j = 0; j < 100; j++)
				{
					toReturn.decimal.push_back('0');
				}
			}
			else // dec
			{
				if (i == 0)
				{
					toReturn.decimal = temp;
				}
				else
				{
					toReturn.num = temp;
				}
			}
		}
	}
	else // one of "*this" or "a" is negtive
	{
		if (a.negative) // pos + neg
		{
			subA.negative = false;
			toReturn = subThis - subA;
		}
		else // neg + pos
		{
			subThis.negative = false;

			toReturn = subA - subThis;
		}
	}

	toReturn.decimal = toReturn.decimal.substr(0, 100);
	toReturn.deDecimal = toReturn.deDecimal.substr(0, 100);

	while (toReturn.decimal.size() < 100)
	{
		toReturn.decimal.push_back('0');
	}
	
	return toReturn;
}

Number Number::operator-(Number a)
{
	Number toReturn, subThis = *this, subA = a; // using these variables to do operation
	stringstream ssToRe, ssSubThis, ssSubA;

	if (a.negative && !this->negative) // pos - neg
	{
		subA.negative = false;
		toReturn = subThis + subA;
	}
	else if (!a.negative && this->negative) // neg - pos
	{
		subA.negative = true;
		toReturn = subThis + subA;
	}
	else if (a.negative && this->negative) // neg - neg
	{
		subA.negative = false;
		toReturn = subA + subThis;
	}
	else if (!a.negative && !this->negative) // pos - pos
	{
		//indentify which is bigger (abs), make sure *this > a
		if (isBigger(deNum + deDecimal, a.deNum + a.deDecimal) != 0)
		{
			string subNum, subDe, subANum, subADe;

			subNum = doStrTimes(num + decimal, a.deNum + a.deDecimal);
			subANum = doStrTimes(a.num + a.decimal, deNum + deDecimal);
			subDe = doStrTimes(deNum + deDecimal, a.deNum + a.deDecimal);
			subADe = doStrTimes(a.deNum + a.deDecimal, deNum + deDecimal);

			subThis.decimal = subNum.substr(subNum.size() - (decimal.size() + a.deDecimal.size()), (decimal.size() + a.deDecimal.size()));
			subThis.num = subNum.substr(0, subNum.size() - (decimal.size() + a.deDecimal.size()));
			subThis.deDecimal = subDe.substr(subDe.size() - (decimal.size() + a.deDecimal.size()), (decimal.size() + a.deDecimal.size()));
			subThis.deNum = subDe.substr(0, subDe.size() - (decimal.size() + a.deDecimal.size()));

			subA.decimal = subANum.substr(subANum.size() - (a.decimal.size() + deDecimal.size()), (decimal.size() + a.deDecimal.size()));
			subA.num = subANum.substr(0, subANum.size() - (a.decimal.size() + deDecimal.size()));
			subA.deDecimal = subADe.substr(subADe.size() - (a.decimal.size() + deDecimal.size()), (decimal.size() + a.deDecimal.size()));
			subA.deNum = subADe.substr(0, subADe.size() - (a.decimal.size() + deDecimal.size()));
		}

		toReturn.deNum = subThis.deNum;
		int deleNum = 0;
		while (toReturn.deNum[deleNum] == '0')
		{
			deleNum++;
		}
		if (deleNum != 0)
		{
			toReturn.deNum.erase(0, deleNum);
		}
		toReturn.deDecimal = subThis.deDecimal.substr(0, 100);

		if (this->num.size() < a.num.size())
		{
			while (subA.num.size() > subThis.num.size())
			{
				subThis.num.insert(subThis.num.begin(), '0');
			}
			Number temp = subThis;
			subThis = subA;
			subA = temp;
			toReturn.negative = true;
		}
		else if (this->num.size() == a.num.size())
		{
			if (isBigger(this->num, a.num) == -1)
			{
				Number temp = subThis;
				subThis = subA;
				subA = temp;
				toReturn.negative = true;
			}
		}
		else
		{
			while (subA.num.size() < subThis.num.size())
			{
				subA.num.insert(subA.num.begin(), '0');
			}
		}

		int timesToDo;

		// identifing type1 + type2 
		if (a.Integer && this->Integer) // int + int
		{
			timesToDo = 1;
			toReturn.Integer = true; // else
		}
		else
		{
			timesToDo = 2;
			toReturn.Integer = false;
		}

		for (int i = 0; i < (subA.num.size() / 2); i++) //reverse
		{
			char b = subThis.num[i];
			subThis.num[i] = subThis.num[subThis.num.size() - 1 - i];
			subThis.num[subThis.num.size() - 1 - i] = b;

			b = subA.num[i];
			subA.num[i] = subA.num[subA.num.size() - 1 - i];
			subA.num[subA.num.size() - 1 - i] = b;
		}
		if (timesToDo == 2)
		{
			for (int i = 0; i < 50; i++) //reverse
			{
				char b = subThis.decimal[i];
				subThis.decimal[i] = subThis.decimal[subThis.decimal.size() - 1 - i];
				subThis.decimal[subThis.decimal.size() - 1 - i] = b;

				b = subA.decimal[i];
				subA.decimal[i] = subA.decimal[subA.decimal.size() - 1 - i];
				subA.decimal[subA.decimal.size() - 1 - i] = b;
			}
		}

		// format
		for (int i = 1; i < subThis.num.size(); i += 2)
		{
			subThis.num.insert(subThis.num.begin() + i, ' ');
		}
		for (int i = 1; i < subA.num.size(); i += 2)
		{
			subA.num.insert(subA.num.begin() + i, ' ');
		}
		if (timesToDo == 2)
		{
			for (int i = 1; i < subThis.decimal.size(); i += 2)
			{
				subThis.decimal.insert(subThis.decimal.begin() + i, ' ');
			}
			for (int i = 1; i < subA.decimal.size(); i += 2)
			{
				subA.decimal.insert(subA.decimal.begin() + i, ' ');
			}
		}

		//operation
		int carry = 0;
		for (int i = 0; i < timesToDo; i++)
		{
			ssSubThis.clear();
			ssSubA.clear();
			ssToRe.clear();
			if (timesToDo == 1) // int
			{
				ssSubThis << subThis.num;
				ssSubA << subA.num;
			}
			else // dec
			{
				if (i == 0)
				{
					ssSubThis << subThis.decimal;
					ssSubA << subA.decimal;
				}
				else
				{
					ssSubThis << subThis.num;
					ssSubA << subA.num;
				}
			}

			int firNum = 0;
			int SecNum = 0;
			while (ssSubThis >> firNum)
			{
				ssSubA >> SecNum;
				if (firNum - SecNum + carry < 0)
				{
					firNum = 10 + (firNum - SecNum + carry);
					carry = -1;
				}
				else
				{
					firNum = (firNum - SecNum + carry);
					carry = 0;
				}
				ssToRe << firNum; // need to be reversed
			}

			string temp;
			ssToRe >> temp;
			for (int j = 0; j < (temp.size() / 2); j++) //reverse
			{
				char b = temp[j];
				temp[j] = temp[temp.size() - 1 - j];
				temp[temp.size() - 1 - j] = b;
			}

			int leadingZeroAmount = 0;
			while (temp[leadingZeroAmount] == '0')  // count the leading 0
			{
				leadingZeroAmount++;
			}

			if (leadingZeroAmount != 0) // erase the leading 0
			{
				temp.erase(temp.begin(), temp.begin() + leadingZeroAmount);
			}

			if (temp.empty())
			{
				temp.push_back('0');
			}

			if (timesToDo == 1) // int
			{
				toReturn.num = temp;
				for (int j = 0; j < 100; j++)
				{
					toReturn.decimal.push_back('0');
				}
			}
			else // dec
			{
				if (i == 0)
				{
					toReturn.decimal = temp;
					while (toReturn.decimal.size() < 100)
					{
						toReturn.decimal.push_back('0');
					}
				}
				else
				{
					toReturn.num = temp;
				}
			}
		}
	}
	return toReturn;
}

Number Number::operator*(Number a)
{
	Number toReturn, subA = a, subThis = *this;
	string sum;

	if (!this->negative && a.negative)
	{
		toReturn.negative = true;
	}
	else if (this->negative && !a.negative)
	{
		toReturn.negative = true;
	}
	else
	{
		toReturn.negative = false;
	}

	// 分子乘分子
	int deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subA.decimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}

	subA.decimal.erase(subA.decimal.end() - deleZero, subA.decimal.end());
	subA.num += subA.decimal;

	deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subThis.decimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}
	subThis.decimal.erase(subThis.decimal.end() - deleZero, subThis.decimal.end());
	subThis.num += subThis.decimal;

	int pushPoint = subThis.decimal.size() + subA.decimal.size();
	
	sum = doStrTimes(subThis.num, subA.num);

	toReturn.decimal = sum.substr(sum.size() - pushPoint, pushPoint);
	sum.erase(sum.size() - pushPoint, pushPoint);
	toReturn.num = sum;

	while (toReturn.decimal.size() < 100)
	{
		toReturn.decimal.push_back('0');
	}

	// 分母乘分母
	deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subA.deDecimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}

	subA.deDecimal.erase(subA.deDecimal.end() - deleZero, subA.deDecimal.end());
	subA.deNum += subA.deDecimal;

	deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subThis.deDecimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}
	subThis.deDecimal.erase(subThis.deDecimal.end() - deleZero, subThis.deDecimal.end());
	subThis.deNum += subThis.deDecimal;

	pushPoint = subThis.deDecimal.size() + subA.deDecimal.size();

	sum.clear();
	sum = "";
	sum = doStrTimes(subThis.deNum, subA.deNum);

	toReturn.deDecimal = sum.substr(sum.size() - pushPoint, pushPoint);
	sum.erase(sum.size() - pushPoint, pushPoint);
	toReturn.deNum = sum;

	while (toReturn.deDecimal.size() < 100)
	{
		toReturn.deDecimal.push_back('0');
	}
	

	bool mayEqualZero = false;
	if (toReturn.num.empty())
	{
		toReturn.num = "0";
		mayEqualZero = true;
	}

	if (this->Integer && a.Integer)
	{
		toReturn.Integer = true;
	}
	else
	{
		toReturn.Integer = false;
	}

	while (toReturn.decimal.size() < 100)
	{
		toReturn.decimal.push_back('0');
	}
	
	if (mayEqualZero)
	{
		for (int i = 0; i < 100; i++)
		{
			if (toReturn.decimal[i] != '0')
			{
				mayEqualZero = false;
				break;
			}
		}
	}

	if (mayEqualZero)
	{
		toReturn.negative = false;
	}
	//cout << toReturn.num << endl << toReturn.decimal << endl << toReturn.deNum << endl << toReturn.deDecimal << endl;
	return toReturn;
}

Number Number::operator/(Number a)
{
	Number toReturn, subA = a, subThis = *this;
	string sum;

	if (!this->negative && a.negative)
	{
		toReturn.negative = true;
	}
	else if (this->negative && !a.negative)
	{
		toReturn.negative = true;
	}
	else
	{
		toReturn.negative = false;
	}

	// 分母乘分子
	int deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subA.decimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}

	subA.decimal.erase(subA.decimal.end() - deleZero, subA.decimal.end());
	subA.num += subA.decimal;

	deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subThis.deDecimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}
	subThis.deDecimal.erase(subThis.deDecimal.end() - deleZero, subThis.deDecimal.end());
	subThis.deNum += subThis.deDecimal;

	int pushPoint = subThis.deDecimal.size() + subA.decimal.size();
	sum = doStrTimes(subThis.deNum, subA.num);
	toReturn.deDecimal = sum.substr(sum.size() - pushPoint, pushPoint);
	sum.erase(sum.size() - pushPoint, pushPoint);
	toReturn.deNum = sum;

	while (toReturn.deDecimal.size() < 100)
	{
		toReturn.deDecimal.push_back('0');
	}

	// 分子乘分母
	deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subA.deDecimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}

	subA.deDecimal.erase(subA.deDecimal.end() - deleZero, subA.deDecimal.end());
	subA.deNum += subA.deDecimal;

	deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subThis.decimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}
	subThis.decimal.erase(subThis.decimal.end() - deleZero, subThis.decimal.end());
	subThis.num += subThis.decimal;
	
	pushPoint = subThis.decimal.size() + subA.deDecimal.size();

	sum.clear();
	sum = "";
	sum = doStrTimes(subThis.num, subA.deNum);

	toReturn.decimal = sum.substr(sum.size() - pushPoint, pushPoint);
	sum.erase(sum.size() - pushPoint, pushPoint);
	toReturn.num = sum;

	while (toReturn.decimal.size() < 100)
	{
		toReturn.decimal.push_back('0');
	}


	bool mayEqualZero = false;
	if (toReturn.num.empty())
	{
		toReturn.num = "0";
		mayEqualZero = true;
	}

	if (this->Integer && a.Integer)
	{
		toReturn.Integer = true;
	}
	else
	{
		toReturn.Integer = false;
	}

	while (toReturn.decimal.size() < 100)
	{
		toReturn.decimal.push_back('0');
	}

	if (mayEqualZero)
	{
		for (int i = 0; i < 100; i++)
		{
			if (toReturn.decimal[i] != '0')
			{
				mayEqualZero = false;
				break;
			}
		}
	}

	if (mayEqualZero)
	{
		toReturn.negative = false;
	}

	//cout << toReturn.num << endl << toReturn.decimal << endl << toReturn.deNum << endl << toReturn.deDecimal << endl;

	return toReturn;
}

Number Number::operator^(Number a)
{ 
	Number one, subA = a, toReturn = *this, subThis = *this;
	one.num = "1";
	subA.Integer = true;
	subA.negative = false;
	stringstream ss;
	
	// minus operation
	if (isBigger(subA.num + subA.decimal, subA.deNum + subA.deDecimal) == 1)//subA.num.size() > 1
	{
		string times;
		ss << a;
		ss >> times;

		for (; isBigger(times, "1") > 0; times = doStrMinus(times, "1"))
		{
			toReturn = toReturn * (*this);
		}
	}
	else if (isBigger(subA.num + subA.decimal, subA.deNum + subA.deDecimal) == -1)//subA.num.size() < 1
	{
		toReturn.num = "1";
		toReturn.deNum = "1";
		toReturn.decimal.clear();
		toReturn.deDecimal.clear();

		while (toReturn.decimal.size() < 100)
		{
			toReturn.decimal.push_back('0');
		}
		while (toReturn.deDecimal.size() < 100)
		{
			toReturn.deDecimal.push_back('0');
		}
	}
	else
	{
		return *this;
	}

	stringstream ssDevision;
	ssDevision << subA;
	string devision;
	devision = ssDevision.str();

	int index = 0;
	while (devision[index] != '.' && index < devision.size() - 1)
	{
		index++;
	}

	if (index != 0 && index < devision.size() - 1)
	{
		devision.erase(0, index + 1);
	}

	devision = devision.substr(0, 100);
	
	if (devision == "5000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")
	{
		// 分子
		Number rootAns = toReturn;
		vector<string> result;
		if ((subThis.num.size() % 2) != 0)
		{
			subThis.num.insert(0, "0");
		}

		string usedForCal = subThis.num + subThis.decimal;
		for (int i = 0; i < 100; i++)
		{
			usedForCal.push_back('0');
		}

		string temp = "0";
		string last = "0";
		for (int i = 0; i < usedForCal.size(); i += 2)
		{
			temp = doStrPlus(temp, usedForCal.substr(i, 2));
			string index = "0";
			while (isBigger(doStrTimes(doStrPlus(last, index), index), temp) != 1) // (last * 10 + index) * index <= temp
			{
				if (index == "10")
				{
					break;
				}
				index = doStrPlus(index, "1");
			}
			last = doStrPlus(last, doStrMinus(index, "1"));
			result.push_back(doStrMinus(index, "1"));
			temp = doStrMinus(temp, doStrTimes(last, doStrMinus(index, "1"))); //temp = temp - (last * 10 + (index - 1)) * (index - 1)
			temp = doStrTimes(temp, "100"); //temp *= 100
			last = doStrTimes(doStrPlus(last, doStrMinus(index, "1")), "10");
		}

		//(toReturn.num.size()+1)/2 . else

		rootAns.num.clear();
		rootAns.num = "";
		for (int i = 0; i < (subThis.num.size() + 1) / 2; i++)
		{
			rootAns.num += result[i];
		}
		rootAns.decimal.clear();
		rootAns.decimal = "";
		for (int i = (subThis.num.size() + 1) / 2; i < ((subThis.num.size() + 1) / 2) + 100; i++)
		{
			rootAns.decimal += result[i];
		}

		//分母
		result.clear();
		if ((subThis.deNum.size() % 2) != 0)
		{
			subThis.deNum.insert(0, "0");
		}

		usedForCal.clear();
		usedForCal = subThis.deNum + subThis.deDecimal;
		for (int i = 0; i < 100; i++)
		{
			usedForCal.push_back('0');
		}

		temp = "0";
		last = "0";
		for (int i = 0; i < usedForCal.size(); i += 2)
		{
			temp = doStrPlus(temp, usedForCal.substr(i, 2));
			string index = "0";
			while (isBigger(doStrTimes(doStrPlus(last, index), index), temp) != 1) // (last * 10 + index) * index <= temp
			{
				if (index == "10")
				{
					break;
				}
				index = doStrPlus(index, "1");
			}
			last = doStrPlus(last, doStrMinus(index, "1"));
			result.push_back(doStrMinus(index, "1"));
			temp = doStrMinus(temp, doStrTimes(last, doStrMinus(index, "1"))); //temp = temp - (last * 10 + (index - 1)) * (index - 1)
			temp = doStrTimes(temp, "100"); //temp *= 100
			last = doStrTimes(doStrPlus(last, doStrMinus(index, "1")), "10");
		}

		//(toReturn.num.size()+1)/2 . else

		rootAns.deNum.clear();
		rootAns.deNum = "";
		for (int i = 0; i < (subThis.num.size() + 1) / 2; i++)
		{
			rootAns.deNum += result[i];
		}
		rootAns.deDecimal.clear();
		rootAns.deDecimal = "";
		for (int i = (subThis.deNum.size() + 1) / 2; i < ((subThis.deNum.size() + 1) / 2) + 100; i++)
		{
			rootAns.deDecimal += result[i];
		}

		toReturn = toReturn * rootAns;
	}

	if (!this->Integer || !a.Integer)
	{
		toReturn.Integer = false;
	}

	if (this->negative)
	{
		if ((a.num[a.num.size() - 1] - '0') % 2 == 0)
		{
			toReturn.negative = false;
		}
		else
		{
			toReturn.negative = true;
		}
	}

	if (a.negative)
	{
		return one / toReturn;
	}

	toReturn.decimal = toReturn.decimal.substr(0, 100);
	toReturn.deDecimal = toReturn.deDecimal.substr(0, 100);

	return toReturn;
}

Number Number::operator%(Number a)
{	// *this is an integer
	string num = "1";
	string count = "1";
	Number toReturn = *this;
	stringstream ss;
	string time;
	ss << toReturn;
	ss >> time;

	while (isBigger(time, count) != -1)
	{
		num = doStrTimes(num, count);
		count = doStrPlus(count, "1");
	}

	toReturn.num = num;
	return toReturn;
}

ostream& operator << (ostream& out, Number a)
{
	Number subA = a; //subA.num+subA.decimal 分子

	//cout << a.num << endl << a.decimal << endl << a.deNum << endl << a.deDecimal << endl << endl;

	int deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subA.decimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}
	subA.decimal.erase(subA.decimal.end() - deleZero, subA.decimal.end());
	subA.num += subA.decimal;

	deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subA.deDecimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}
	subA.deDecimal.erase(subA.deDecimal.end() - deleZero, subA.deDecimal.end());
	subA.deNum += subA.deDecimal;
	
	int subADecSize = subA.decimal.size();
	int subAdeDecimalSize = subA.deDecimal.size();
	for (int i = 0; i < subADecSize - subAdeDecimalSize; i++)
	{
		subA.deNum.push_back('0');
	}
	for (int i = 0; i < subAdeDecimalSize - subADecSize; i++)
	{
		subA.num.push_back('0');
	}

	string temp = "0";
	vector<int> result;
	int index = 0;
	while (1)
	{
		if (index < subA.num.size())
		{
			int a = subA.num[index] - '0';
			temp = doStrPlus(temp, a);
		}

		result.push_back(stoi(doStrDevide(temp, subA.deNum)));
		temp = doStrTimes(doStrMode(temp, subA.deNum), "10");

		if (result.size() >= subA.num.size() + 110)
		{
			break;
		}
		index++;
	}

	string ansNum;
	string ansDec;
	for (int i = 0; i < subA.num.size(); i++)
	{
		char c = (result[i] + '0');
		ansNum += c;
	}
	for (int i = subA.num.size(); i < subA.num.size() + 100; i++)
	{
		if (i >= result.size())
		{
			ansDec += "0";
		}
		else
		{
			char c = (result[i] + '0');
			ansDec += c;
		}
	}
	
	deleZero = 0;
	while (ansNum[deleZero] == '0')
	{
		deleZero++;
	}
	if (deleZero != 0)
	{
		ansNum.erase(0, deleZero);
	}
	bool mayEqualZero = false;

	if (ansNum.empty())
	{
		ansNum = "0";
		mayEqualZero = true;
	}
	if (mayEqualZero)
	{
		for (int i = 0; i < 100; i++)
		{
			if (ansDec[i] != '0')
			{
				mayEqualZero = false;
				break;
			}
		}
	}

	if (mayEqualZero)
	{
		a.negative = false;
	}
	//

	if (a.negative)
	{
		out << "-";
	}
	out << ansNum;
	if (!a.Integer)
		out << '.' << ansDec;
	return out;
}

string doStrPlus(string a, string b) 
{
	string toReturn;

	while (a.size() > b.size())
	{
		b.insert(0, "0");
	}
	while (a.size() < b.size())
	{
		a.insert(0, "0");
	}

	int carry = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		int temp = (a[i] - '0') + (b[i] - '0') + carry;
		if (temp >= 10)
		{
			carry = 1;
			temp -= 10;
		}
		else
		{
			carry = 0;
		}

		toReturn.push_back(temp + '0');
	}

	if (carry != 0)
	{
		toReturn.push_back('1');
	}

	for (int i = 0; i < toReturn.size() / 2; i++)
	{
		char temp = toReturn[i];
		toReturn[i] = toReturn[toReturn.size() - 1 - i];
		toReturn[toReturn.size() - 1 - i] = temp;
	}

	bool allZero = true;
	for (int i = 0; i < toReturn.size(); i++)
	{
		if (toReturn[i] != '0')
		{
			allZero = false;
			break;
		}
	}

	if (allZero)
	{
		toReturn = "0";
	}

	return toReturn;
}
string doStrMinus(string a, string b) // only when a>b(´N¼Æ¦r¤W¨Ó»¡)
{
	string toReturn;

	while (a.size() > b.size())
	{
		b.insert(0, "0");
	}
	while (a.size() < b.size())
	{
		a.insert(0, "0");
	}

	int carry = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		int temp = (a[i] - '0') - (b[i] - '0') + carry;
		if (temp < 0)
		{
			temp += 10;
			carry = -1;
		}
		else
		{
			carry = 0;
		}
		toReturn.push_back(temp + '0');
	}

	for (int i = 0; i < toReturn.size() / 2; i++)
	{
		char temp = toReturn[i];
		toReturn[i] = toReturn[toReturn.size() - 1 - i];
		toReturn[toReturn.size() - 1 - i] = temp;
	}

	int deleZero = 0;
	while (toReturn[deleZero] == '0')
	{
		deleZero++;
	}
	if (deleZero != 0)
	{
		toReturn.erase(0, deleZero);
	}

	bool allZero = true;
	for (int i = 0; i < toReturn.size(); i++)
	{
		if (toReturn[i] != '0')
		{
			allZero = false;
			break;
		}
	}

	if (allZero)
	{
		toReturn = "0";
	}

	return toReturn;
}
string doStrTimes(string a, string b)
{
	vector<int> result;
	string toReturn;

	if (a == "0" || b == "0")
	{
		return "0";
	}

	int deleZero = 0;
	while (a[deleZero] == '0')
	{
		deleZero++;
	}
	if (deleZero != 0)
	{
		a.erase(0,deleZero);
	}

	deleZero = 0;
	while (b[deleZero] == '0')
	{
		deleZero++;
	}
	if (deleZero != 0)
	{
		b.erase(0, deleZero);
	}

	for (int i = 0; i < a.size() + b.size(); i++)
	{
		result.push_back(0);
	}

	for (int i = b.size() - 1; i >= 0; i--)
	{
		for (int j = a.size() - 1; j >= 0; j--)
		{
			result[(b.size() - 1) - i + (a.size() - 1) - j] += (a[j] - '0') * (b[i] - '0');
		}
	}

	int carry = 0;
	for (int i = 0; i < result.size(); i++)
	{
		int temp = result[i] + carry;
		if (temp >= 10)
		{
			result[i] = temp % 10;
			carry = temp / 10;
		}
		else
		{
			result[i] = temp;
			carry = 0;
		}
	}

	deleZero = 0;
	for (int i = result.size() - 1; i >= 0; i--)
	{
		if (result[i] != 0)
		{
			break;
		}
		deleZero++;
	}
	result.erase(result.end() - deleZero, result.end());

	if (carry != 0)
	{
		result.push_back(carry);
	}

	// reverse
	for (int i = 0; i < result.size() / 2; i++)
	{
		char temp = result[i];
		result[i] = result[(result.size() - 1) - i];
		result[(result.size() - 1) - i] = temp;
	}

	for (int i = 0; i < result.size(); i++)
	{
		toReturn.push_back(result[i] + '0');
	}

	bool allZero = true;
	for (int i = 0; i < toReturn.size(); i++)
	{
		if (toReturn[i] != '0')
		{
			allZero = false;
			break;
		}
	}

	if (allZero)
	{
		toReturn = "0";
	}

	return toReturn;
}
string doStrDevide(string a, string b) // only for int / int
{
	int pushPoint = 0;
	if (isBigger(a, b) == -1)
	{
		return "0";
	}
	else if (isBigger(a, b) == 0)
	{
		return "1";
	}
	else
	{
		string subB = b;
		int num = 1;
		while (isBigger(a, b) != -1)
		{
			num++;
			b = doStrPlus(b, subB);
		}

		return to_string(num - 1);
	}

	return "0";
}
string doStrMode(string a, string b)
{
	int pushPoint = 0;
	if (isBigger(a, b) == -1)
	{
		return a;
	}
	else if (isBigger(a, b) == 0)
	{
		return "0";
	}
	else
	{
		string subB = b;
		int num = 1;
		while (isBigger(a, b) != -1)
		{
			num++;
			b = doStrPlus(b, subB);
		}

		for (int i = 0; i < num - 1; i++)
		{
			a = doStrMinus(a, subB);
		}

		return a;
	}

	return "0";
}

string doStrPlus(string a, int b)
{
	string toReturn;
	string c = to_string(b);
	return doStrPlus(a, c);
}
string doStrMinus(string a, int b)
{
	string toReturn;
	string c = to_string(b);
	return doStrPlus(a, c);
}
string doStrTimes(string a, int b)
{
	string c = to_string(b);
	return doStrPlus(a, c);
}

int isBigger(string a, string b)
{
	while (a.size() > b.size())
	{
		b.insert(0, "0");
	}
	while (a.size() < b.size())
	{
		a.insert(0, "0");
	}

	for (int i = 0; i < a.size(); i++)
	{
		if ((a[i] - '0') > (b[i] - '0'))
		{
			return 1;
		}
		else if ((a[i] - '0') < (b[i] - '0'))
		{
			return -1;
		}
	}

	return 0;
}

/*
Number toReturn, subA = a, subThis = *this;

	if (!this->negative && a.negative)
	{
		toReturn.negative = true;
	}
	else if (this->negative && !a.negative)
	{
		toReturn.negative = true;
	}
	else
	{
		toReturn.negative = false;
	}

	int deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subA.decimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}
	subA.decimal.erase(subA.decimal.end() - deleZero, subA.decimal.end());
	subA.num += subA.decimal;

	deleZero = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (subThis.decimal[i] != '0')
		{
			break;
		}
		deleZero++;
	}
	subThis.decimal.erase(subThis.decimal.end() - deleZero, subThis.decimal.end());
	subThis.num += subThis.decimal;

	int subADecSize = subA.decimal.size();
	int subThisDecSize = subThis.decimal.size();
	for (int i = 0; i < subThisDecSize - subADecSize; i++)
	{
		subA.num.push_back('0');
	}
	for (int i = 0; i < subADecSize - subThisDecSize; i++)
	{
		subThis.num.push_back('0');
	}
	string temp = "0";
	vector<int> result;
	int index = 0;
	while(1)
	{
		if (index >= subThis.num.size())
		{
			temp = doStrPlus(temp, "0");
		}
		else
		{
			int a = subThis.num[index] - '0';
			temp = doStrPlus(temp, a);
		}
		result.push_back(stoi(doStrDevide(temp,subA.num)));
		temp = doStrTimes(doStrMode(temp, subA.num) ,"10");
		if (result.size() >= this->num.size() + 110)
		{
			break;
		}
		index++;
	}

	toReturn.num.clear();
	toReturn.decimal.clear();

	for (int i = 0; i < subThis.num.size(); i++)
	{
		toReturn.num.push_back(result[i] + '0');
	}
	for (int i = subThis.num.size(); i < subThis.num.size() + 100; i++)
	{
		if (i >= result.size())
		{
			toReturn.decimal.push_back('0');
		}
		else
		{
			toReturn.decimal.push_back(result[i] + '0');
		}
	}

	deleZero = 0;
	while (toReturn.num[deleZero] == '0')
	{
		deleZero++;
	}
	if (deleZero != 0)
	{
		toReturn.num.erase(0, deleZero);
	}
	bool mayEqualZero = false;
	if (toReturn.num.empty())
	{
		toReturn.num = "0";
		mayEqualZero = true;
	}

	if (this->Integer && a.Integer)
	{
		toReturn.Integer = true;
	}
	else
	{
		toReturn.Integer = false;
	}

	if (mayEqualZero)
	{
		for (int i = 0; i < 100; i++)
		{
			if (toReturn.decimal[i] != '0')
			{
				mayEqualZero = false;
				break;
			}
		}
	}

	if (mayEqualZero)
	{
		toReturn.negative = false;
	}

	return toReturn;*/