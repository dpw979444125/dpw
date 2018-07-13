#include<iostream>
using namespace std;
//����
class Date {
public:
	//����
	Date(int year, int month, int day)
		: _year(year)
	    , _month(month)
		, _day(day)
	{
		cout << "Date(int, int, int):"<< endl;
	}

	//��������
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout <<_year << endl;
		cout <<_month << endl;
		cout <<_day << endl;
	}

	//����
	~Date()
	{

	}

	//���������
	//=
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//==�ж����������Ƿ����
	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	//!=�ж����������Ƿ񲻵�
	bool operator!=(const Date& d)
	{
		return !(*this == d);  //==�����������
	}

	//��ǰ���ڵ�days�������һ��
	Date operator+(const int days)
	{
		int md = days / 30;
		int m = days % 30;
		if (days + this->_day <= 30)
		{
			this->_day += days;
		}
		
		else if(md + this->_month <= 12)
		{		
			this->_month += md;
			if (this->_day + m < 30)
			{
				this->_day += m;
			}
			else
			{
				this->_day += m;
				++this->_month;
			}
			
		}
		else if (md + this->_month > 12)
		{
			int y = days / 365;
			if (y < 1)
			{
				this->_year++;
			}
			else if (y >= 1)
			{
				this->_year += y;
				int yy = days % 365;
				int xx = yy / 30;
				int x = yy % 30;
				if (yy + this->_day <= 30)
				{
					this->_day += yy;
				}
				else if (xx + this->_month <= 12)
				{
					this->_month += xx;
					if (this->_day + x < 30)
					{
						this->_day += x;
					}
					else
					{
						this->_day += x;
						++this->_month;
					}
				}
			}
		}
		return *this;
	}

	//ǰ��++
	Date& operator++()
	{
		if (_day == 30 && _month == 12)
		{
			_year++;
			_month = 1;
			_day = 1;
		}
		else if (_day == 30)
		{
			_month++;
			_day = 1;
		}
		else
		    _day += 1;
		
		return (*this);
	}

	//����++
	Date& operator++(int)
	{
		Date tmp(*this);
		_day += 1;
		return tmp;
	}

	// ����������֮��Ĳ�ֵ 
	int operator-(const Date& d)
	{
		return abs((_year - d._year) * 365 + (_month - d._month) * 30 + _day - d._day);
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2018, 1, 29);
	Date d1(2017, 1, 1);
	//d.operator=(d1);
	//++d1;
	//d1 = d1 + 450;
	int y = d - d1;
	cout << y;
	system("pause");
	return 0;
}