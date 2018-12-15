#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
class Money {
	int rub;
	char kop[2];
public:
	void set(int a, int b)
	{
		rub = a; sprintf(kop, "%d", b);
	}
	void operator +(Money A);
	void operator -(Money A);
	bool operator ==(Money A);
	bool operator <(Money A);
	void show()
	{
		cout  << rub << "," << kop ;
	}
};

void Money::operator +(Money A)
{
	int a, b, c;
	this->rub = this->rub + A.rub;
	a = atoi(this->kop);
	b = atoi(A.kop);
	c = a + b;
	if (c >= 100) {
		this->rub++; c -= 100;
	}
	sprintf(this->kop, "%d", c);
}

void Money::operator -(Money A)
{
	int a, b, c;
	int temp = 0;
	this->rub = this->rub - A.rub;
	a = atoi(this->kop);
	b = atoi(A.kop);
	c = a - b;
	
	if (this->rub < 0 && c > 0) {
		c = 100 - c;
		this->rub += 1;
		this->rub = abs(this->rub);
		temp = 1;
	}

	if (c < 0) {
		if (this->rub > 0) {
			this->rub -= 1;
			c = 100 - abs(c);
		}
		else
		{
			if (this->rub == 0) temp = 1;
		c = abs(c);
		}
		
	}
    if (temp == 1) cout << "-";
	sprintf(this->kop, "%d", c);
}

bool Money::operator ==(Money A)
{
	if ((this->rub) == (A.rub))
	{
		if (atoi(this->kop) == atoi(A.kop)) {
			return true;
		}
		else return false;
	}
	else
		return false;
}

bool Money::operator <(Money A)
{
	if ((this->rub) < (A.rub))
		return true;
	if ((this->rub) == (A.rub))
	{
		if (atoi(this->kop) < atoi(A.kop))
			return true;
	}
	else
		return false;
}

int main()
{
	Money A, B;
	int a, a1, b, b1;
	cout << "Enter rub: ";
	cin >> a;
	cout << "Enter kopeiki: ";
	cin >> b;
	cout << "Enter rub: ";
	cin >> a1;
	cout << "Enter kopeiki: ";
	cin >> b1;
	A.set(a, b);
	B.set(a1, b1);

	cout << "A < B ? : ";
	if (A < B)
		cout << "Yes\n";
	else cout << "No\n";

	cout << "A = B ? : ";
	if (A == B)
		cout << "Yes\n";
	else cout << "No\n";

	cout << "SUM:";
	A + B;
	A.show();
	cout << endl;

	A - B;
	
	cout << "DIF:";
    A - B;
	A.show(); 
	cout << endl;

	system("pause");
	return 0;
}