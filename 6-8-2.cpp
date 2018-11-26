/*-------------------------------������������ ������ 6-8-2----------------------*/
/*������� ������ ������ ����� m/n. ����������� �������� ��������: �����/������, 
��������, ���������, ������� ������.*/

#include <iostream>
using namespace std;

    //�������� ������ � ������� ������
template <class T>
class Fraction {
	private :
	T m;
	T n;
	
	public:
	Fraction () {
		m = 0;
		n = 0;
	}
	
	Fraction(T valueM, T valueN) {
		n = valueN;
		m = valueM;
	}
	
	//������ ������
//����� ������ ��� �������� ����� ������
void Sum (Fraction<T> *object, int size) {
    //����� ������(�������� ��������)
	Fraction<T> sum = object[0];
	for (int i = 1; i < size; i++) {
		sum = sum + object[i];
	}
	cout << "Itogovaya summa: ";
	cout << sum.m << "/" << sum.n << endl;
}

//����� ������ ��� �������� ������������ ������
void Mult (Fraction<T> *object, int size) {
    //��������� ������ (�������� ���������)
	Fraction<T> mult = object[0];
	for (int i = 1; i < size; i++) {
		mult = mult * object[i];
	}
	cout << "Itogovoe proizvedenie: ";
	cout << mult.m << "/" << mult.n <<endl;
}

//����� ������ ��� �������� �������� ������
void Div (Fraction<T> *object, int size) {
	//������� ������ (�������� ������� )
	Fraction<T> div = object[0];
	for (int i = 1; i < size; i++) {
		div = div / object[i];
	}
	cout << "Itogovoe chastnoe: ";
	cout << div.m << "/" << div.n <<endl;
}
	
	
	//���������� ���������� ������
	
//���������� ��������� ������������
	void operator =(const Fraction<T> &other) {
	    this->m = other.m;
     	this->n = other.n;
    }
    
//���������� ��������� ������ ������
friend ostream& operator << (ostream& out, const Fraction<T>& object) {
		out << object.m << "/" << object.n << endl;
		return out;
	}
	
//���������� ��������� ����� ������
friend istream& operator >> (istream& in, Fraction<T>& object) {
	    cout << endl ;
		cout << "Input m: "; in >> object.m; 
	    cout << "Input n: "; in >> object.n; cout << endl;
	    return in;
}
    
//���������� ��������� �������� ������
Fraction operator +(const Fraction<T> &other){
	Fraction<T> temp;
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

//���������� ��������� ��������� ������
Fraction operator *(const Fraction<T> &other) {
	Fraction<T> temp;
	temp.m = this->m * other.m;
	temp.n = this->n * other.n;
	return temp;
}

//���������� ��������� ������� ������
Fraction operator /(const Fraction<T> &other) {
	Fraction<T> temp;
	temp.m = this->m * other.n;
	temp.n = this->n * other.m;
	return temp;
}
};

//-----------------------------------MAIN--------------------------------------

int main () {
	
	//������� ����������� ������� �������� � ������������� ������� �������� ������ Fraction
    int size;
	cout << "Enter a number of Fractions: ";
	cin >> size;
	Fraction<int> *object = new Fraction<int>[size];
	
	//���� ������
	for (int i=0; i < size; i++) {
		cout << "Enter " << i+1 <<" Fraction: ";
		cin >> object[i];
	}
	
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	
	//����� ������
	for (int i = 0; i < size; i++) {
		cout << i+1 << " Fraction: " << object[i] << endl;
	}
	
	//����� ������� ������
	
	//���������� ������� ������
	Fraction<int> test;
	//������� ����� ������
    test.Sum(object, size);
    //������� ������������ ������
	test.Mult(object, size);
	//������� �������� ������
	test.Div(object, size);
}
