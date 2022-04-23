#include "Number.h"

string doStrPlus(string a, string b); // only used in ^ overloading
string doStrMinus(string a, string b);// only used in ^ overloading
string doStrTimes(string a, string b);// only used in ^ overloading
string doStrPlus(string a, int b); // only used in ^ overloading
string doStrMinus(string a, int b);// only used in ^ overloading
string doStrTimes(string a, int b);// only used in ^ overloading
int isBigger(string a, string b);// only used in ^ overloading

Number::Number()
{
	num = "0";
	while (decimal.size() < 100)
	{
		decimal.push_back('0');
	}
	Integer = true;
	negative = false;
}

Number::Number(string a) : num(a)
{
	for (int i = 0; i < 100; i++)
	{
		decimal.push_back('0');
	}
	Integer = true;
	negative = false;
};

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
	Number toReturn, subThis = *this, subA = a; // using these variables to do operation
	toReturn.negative = false;
	stringstream ssToRe, ssSubThis, ssSubA;
	if ((a.negative && this->negative) || (!a.negative && !this->negative)) //"*this" and "a" are both positive or negtive
	{
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
				if (carry == 1)
				{
					ssToRe << 1;
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
		if (a.negative)
		{
			subA.negative = false;
			toReturn = subThis - subA;
		}
		else
		{
			subThis.negative = false;
			toReturn = subA - subThis;
		}
	}
	return toReturn;
}

Number Number::operator-(Number a)
{
	Number toReturn, subThis = *this, subA = a; // using these variables to do operation
	toReturn.negative = false;
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
		toReturn = subA - subThis;
	}
	else if (!a.negative && !this->negative) // pos - pos
	{
		//indentify which is bigger (abs), make sure this > a
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
			for (int i = 0; i < this->num.size(); i++)
			{
				if ((this->num[i] - '0') < (a.num[i] - '0'))
				{
					Number temp = subThis;
					subThis = subA;
					subA = temp;
					toReturn.negative = true;
					break;
				}
			}
			if (toReturn.negative == false)
			{
				for (int i = 0; i < 100; i++)
				{
					if ((this->decimal[i] - '0') < (a.decimal[i] - '0'))
					{
						Number temp = subThis;
						subThis = subA;
						subA = temp;
						toReturn.negative = true;
						break;
					}
				}
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
					ssSubThis.clear();
					ssSubA.clear();
					ssToRe.clear();
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
	// 埃计箂盢计崩秈俱计暗猭程崩︳计翴
	Number toReturn, zero, one, subA = a, subThis = *this;
	vector<int> sum;

	toReturn.Integer = true;
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

	int pushPoint = subThis.decimal.size() + subA.decimal.size();
	int pushVector = subA.num.size() + subThis.num.size();
	for (int i = 0; i < pushVector; i++)
	{
		sum.push_back(0);
	}

	for (int i = subA.num.size() - 1; i >= 0; i--)
	{
		for (int j = subThis.num.size() - 1; j >= 0; j--)
		{
			sum[(subA.num.size() - 1 - i) + (subThis.num.size() - 1 - j)] += (subA.num[i] - '0') * (subThis.num[j] - '0');
		}
	}

	int carry = 0;
	for (int i = 0; i < sum.size(); i++)
	{
		int temp = sum[i] + carry;
		if (temp >= 10)
		{
			sum[i] = temp % 10;
			carry = temp / 10;
		}
		else
		{
			sum[i] = temp % 10;
			carry = 0;
		}
	}

	deleZero = 0;
	for (int i = sum.size() - 1; i >= 0; i--)
	{
		if (sum[i] != 0)
		{
			break;
		}
		deleZero++;
	}
	sum.erase(sum.end() - deleZero, sum.end());

	if (carry != 0)
	{
		sum.push_back(carry);
	}

	for (int i = 0; i < sum.size(); i++)
	{
		char temp = sum[i] + '0';
		toReturn.num.push_back(temp);
	}

	// reverse
	for (int i = 0; i < toReturn.num.size() / 2; i++)
	{
		char temp = toReturn.num[i];
		toReturn.num[i] = toReturn.num[(toReturn.num.size() - 1) - i];
		toReturn.num[(toReturn.num.size() - 1) - i] = temp;
	}

	toReturn.decimal = toReturn.num.substr(toReturn.num.size() - pushPoint - 1, pushPoint);
	toReturn.num = toReturn.num.substr(0, toReturn.num.size() - pushPoint - 1);

	for (int i = 0; i < toReturn.decimal.size(); i++)
	{
		if (toReturn.decimal[i] != '0')
		{
			toReturn.Integer = false;
			break;
		}
	}

	while (toReturn.decimal.size() < 100)
	{
		toReturn.decimal.push_back('0');
	}

	return toReturn;
}

Number Number::operator/(Number a)
{
	// 埃计箂盢计崩秈俱计暗猭程崩︳计翴
	Number toReturn, zero, one, subA = a, subThis = *this;

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

	subThis.num += subThis.decimal;
	subThis.num += subThis.decimal;

	for (int i = 0; i < subThis.decimal.size() - subA.decimal.size(); i++)
	{
		subA.num.push_back('0');
	}
	for (int i = 0; i < subA.decimal.size() - subThis.decimal.size(); i++)
	{
		subThis.num.push_back('0');
	}

	vector<int> forOpe, result;
	for (int i = 0; i < subThis.num.size(); i++)
	{
		forOpe.push_back(subThis.num[i] - '0');
		if (forOpe.size() < subA.num.size())
		{
			result.push_back(0);
			continue;
		}
		else // forOpe.size() >= subA.num.size()
		{
			// test whether forOpe > subA.num
			bool toContinue = false;
			for (int j = 0; j < forOpe.size(); j++)
			{
				char temp = forOpe[j] + '0';
				if (temp < subA.num[j])
				{
					toContinue = true;
					result.push_back(0);
					break;
				}
			}
			if (toContinue)
			{
				continue;
			}

			// 干ì计
			if (forOpe.size() > subA.num.size())
			{
				subA.num.insert(0, "0");
			}

			// minus
			bool canDo = true;
			int pushToRe = 0;
			vector<int> sink;
			while (canDo)
			{
				int carry = 0;
				for (int k = 1; ; k++)
				{
					for (int j = subA.num.size() - 1; j >= 0; j--)
					{
						int temp = (subA.num[j] - '0') * k + carry;
						if (temp >= 10)
						{
							carry = temp / 10;
							temp %= 10;
						}
						else
						{
							carry = 0;
						}
						sink.push_back(temp);
					}
					reverse(sink.begin(), sink.end());

					for (int j = 0; j < sink.size(); j++)
					{
						if (sink[j] > forOpe[j])
						{
							canDo = false;
							break;
						}
					}

					if (!canDo)
					{
						break;
					}

					pushToRe = k;
					sink.clear();
				}

				// the biggist sink (multiple of subA)
				carry = 0;
				for (int j = subA.num.size() - 1; j >= 0; j--)
				{
					int temp = (subA.num[j] - '0') * pushToRe + carry;
					if (temp >= 10)
					{
						carry = temp / 10;
						temp %= 10;
					}
					else
					{
						carry = 0;
					}
					sink.push_back(temp);
				}
				reverse(sink.begin(), sink.end());

				// forOpe minus sink
				carry = 0;
				for (int j = forOpe.size() - 1; j >= 0; j--)
				{
					int temp = forOpe[i] - sink[i] + carry;
					if (temp < 0)
					{
						carry = -1;
						temp += 10;
					}
					else
					{
						carry = 0;
					}
					forOpe[i] = temp;
				}

				// delete the leading zero of forOpe
				deleZero = 0;
				while (forOpe[deleZero] == '0')
				{
					deleZero++;
				}
				if (deleZero != 0)
				{
					forOpe.erase(forOpe.begin(), forOpe.begin() + deleZero);
				}

				result.push_back(pushToRe);
				sink.clear();
			}

		}


	}

	deleZero = 0;
	while (result[deleZero] == '0')
	{
		deleZero++;
	}
	if (deleZero != 0)
	{
		result.erase(forOpe.begin(), forOpe.begin() + deleZero);
	}











	return toReturn;
}

Number Number::operator^(Number a)
{ // タ璽耞临⊿暗
	Number one("1"), zero, subA = a, toReturn = *this, subThis = *this;
	subA.Integer = true;
	if (!this->Integer)
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

	// minus operation
	if (isBigger(subA.num, "1") == 1)//subA.num.size() > 1
	{
		for (; subA.num != "1"; subA = subA - one)
		{
			toReturn = toReturn * (*this);
		}

		while (toReturn.decimal.size() < 100)
		{
			toReturn.decimal.push_back('0');
		}
	}
	else if (isBigger(subA.num, "1") == -1)//subA.num.size() < 1
	{
		toReturn.num = "1";
		while (toReturn.decimal.size() < 100)
		{
			toReturn.decimal.push_back('0');
		}
	}

	while (toReturn.decimal.size() < 100)
	{
		toReturn.decimal.push_back('0');
	}

	if (a.decimal == "5000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")
	{
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

		toReturn = toReturn * rootAns;
	}


	return toReturn;
}

Number Number::operator%(Number a)
{
	int temp = stoi(num);
	long long int ans = 1;
	for (int i = 1; i <= temp; i++) ans *= i;
	return Number(to_string(ans));
}

ostream& operator << (ostream& out, Number a) {
	if (a.negative)
	{
		out << "-";
	}
	out << a.getNum();
	if (!a.Integer)
		out << '.' << a.getDecimal();
	return out;
}




/*int carry = 0;
				for (int j = forOpe.size() - 1; j >= 0; j--)
				{
					int temp = (forOpe[j] - '0') - (subA.num[j] - '0') + carry;

					if (temp < 0)
					{
						temp += 10;
						carry = -1;
					}
					else
					{
						carry = 0;
					}
					result.push_back(temp); // need to be reversed
				}
				reverse(result.begin(), result.end());
				forOpe.clear();
				for (int j = 0; j < result.size(); j++)
				{
					forOpe.push_back(result[j]);
				}
				result.clear();*/

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
string doStrMinus(string a, string b) // only when a>b(碞计ㄓ弧)
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

	for (int i = 0; i < a.size() + b.size(); i++)
	{
		result.push_back(0);
	}

	for (int i = b.size() - 1; i >= 0; i--) //3
	{
		for (int j = a.size() - 1; j >= 0; j--) //2
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

	int deleZero = 0;
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
	string toReturn;
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