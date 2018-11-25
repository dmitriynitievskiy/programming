/*-------------------------------������������ ������ � 2---------------*/
/*���������� ����� "�����" � ���� ���� (m,n). ����� ������ ��������� ���������
�������������. ����������� ������ ��� ��������, ���������, ��������� � �������
������. ����������� �������� ��������, ���������, ���������, �������, ������������
� �������� ���������. ������� ������ �������� � �������� ��� � �������, �������
�������� ������ ������� ������� � ������ �������� ����� ���������� ����������
�� ��� �������� �������*/
#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
	private:
		int m;
		int n;
	
    public:
   Fraction() {
   	m = 0;
   	n = 0;
   }
   
  Fraction(int valueM, int valueN) {
		m = valueM;
		n = valueN;
	} 

//������ ������
void Sum (Fraction *object, int size) {
    //����� ������(�������� ��������)
	Fraction sum = object[0];
	for (int i = 1; i < size; i++) {
		sum = sum + object[i];
	}
	cout << "Itogovaya summa: ";
	cout << sum.m << "/" << sum.n << endl;
}

void Sub (Fraction *object, int size) {
	//������� ������ (�������� ���������)
	Fraction razn = object[0];
	for (int i = 1; i < size; i++) {
		razn = razn - object[i];
	}
	cout << "Itogovaya raznost': ";
	cout << razn.m << "/" <<razn.n <<endl;
}

void Mult (Fraction *object, int size) {
    //��������� ������ (�������� ���������)
	Fraction mult = object[0];
	for (int i = 1; i < size; i++) {
		mult = mult * object[i];
	}
	cout << "Itogovoe proizvedenie: ";
	cout << mult.m << "/" << mult.n <<endl;
}

void Div (Fraction *object, int size) {
	//������� ������ (�������� ������� )
	Fraction div = object[0];
	for (int i = 1; i < size; i++) {
		div = div / object[i];
	}
	cout << "Itogovoe chastnoe: ";
	cout << div.m << "/" << div.n <<endl;
}

//���������� ��������� ��������
Fraction operator +(const Fraction &other){
	Fraction temp;
	if (this->n == other.n ) {
		 temp.m = this->m + other.m;
		 temp.n = other.n;
	}
	else {
		temp.n = this->n * other.n;
		temp.m = this->m * other.n + other.m * this->n;
	}
	return temp;
	  
}

//���������� ��������� ���������
Fraction operator -(const Fraction &other){
	Fraction temp;
	if (this->n == other.n ) {
		 temp.m = this->m - other.m;
		 temp.n = other.n;
	}
	else {
		temp.n = this->n * other.n;
		temp.m = this->m * other.n - other.m * this->n;
	}
	return temp;
	  
}

//���������� ��������� ���������
Fraction operator *(const Fraction &other) {
	Fraction temp;
	temp.m = this->m * other.m;
	temp.n = this->n * other.n;
	return temp;
	  
}

//���������� ��������� �������
Fraction operator /(const Fraction &other) {
	Fraction temp;
	temp.m = this->m * other.n;
	temp.n = this->n * other.m;
	return temp;
}

//���������� ��������� ������������
void operator =(const Fraction &other) {
	this->m = other.m;
	this->n = other.n;
}
//���������� ��������� ��������� ==
bool operator ==(const Fraction &other) {
	if (this->m == other.m && this->n == other.n) {
		return true;
	}
	else {
		return false;
	}
}
//���������� ��������� ��������� <
bool operator <(const Fraction &other) {
	if (this->n == other.n) {
		if (this->m < other.m) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->m * other.n < other.m * this->n) {
			return true;
		}
		else {
			return false;
		}
	}
}
//���������� ��������� ��������� >
bool operator >(const Fraction &other) {
	if (this->n == other.n) {
		if (this->m > other.m) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->m * other.n > other.m * this->n) {
			return true;
		}
		else {
			return false;
		}
	}
}
//���������� ��������� ��������� <=
bool operator <=(const Fraction &other) {
	if (this->n == other.n) {
		if (this->m <= other.m) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->m * other.n <= other.m * this->n) {
			return true;
		}
		else {
			return false;
		}
	}
}
//���������� ��������� ��������� >=
bool operator >=(const Fraction &other) {
	if (this->n == other.n) {
		if (this->m >= other.m) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->m * other.n >= other.m * this->n) {
			return true;
		}
		else {
			return false;
		}
	}
}
//���������� ��������� ��������� !=
bool operator !=(const Fraction &other) {
	if (this->n == other.n) {
		if (this->m != other.m) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->m * other.n != other.m * this->n) {
			return true;
		}
		else {
			return false;
		}
	}
}

//���������� ��������� ������ ������
friend ostream& operator << (ostream& out, const Fraction &object) {
		out << object.m << "/" << object.n ;
		return out;
	}
	
//���������� ��������� ����� ������
friend istream& operator >> (istream& in, Fraction &object) {
	    cout << endl << "Input m: "; in >> object.m; 
	    cout << "Input n: "; in >> object.n; cout << endl;
	    return in;
}

};


//�������, ������������ � �������� ������� � ������ �������� ��������� ������� �������
void Function (Fraction *object, int size) {
	for (int i = 0; i < size-1; i++) {
		if (i % 2 == 0) {
			object[i] = object[i] + object[i+1];
		}
	}
	cout << "Posledovatel'nost': ";
	for (int i = 0; i < size; i++) {
		cout << object[i] << ", ";
	}
	cout << endl;
}


int main () {
	
	
	//������ ��������
	int size;
	cout << "Enter a number of Fractions: ";
	cin >> size;
	Fraction *object = new Fraction[size];
	
	for (int i=0; i < size; i++) {
		cout << "Enter " << i+1 <<" Fraction: "; cout << endl;
	    cin >> object[i];
	}
for (int i = 0; i < size; i++) {
		cout << i+1 << " Fraction: " << object[i] << endl;
	}
	
	//����� ������� ������ 
    Fraction test;
    test.Sum(object, size);
	test.Sub(object, size);
	test.Mult(object, size);
	test.Div(object, size); 


	//�������, ������������ � �������� ������� � ������ �������� ��������� ������� �������
	Function (object, size);
}
