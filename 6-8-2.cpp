/*-------------------------------Лабораторная работа 6-8-2----------------------*/
/*Создать шаблон класса дробь m/n. Перегрузить основные операции: ввода/вывода, 
сложения, умножения, деления дробей.*/

#include <iostream>
using namespace std;

    //СОЗДАНИЕ КЛАССА И ШАБЛОНА КЛАССА
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
	
	//МЕТОДЫ КЛАССА
//метод класса для подсчета суммы дробей
void Sum (Fraction<T> *object, int size) {
    //сумма дробей(оператор сложения)
	Fraction<T> sum = object[0];
	for (int i = 1; i < size; i++) {
		sum = sum + object[i];
	}
	cout << "Itogovaya summa: ";
	cout << sum.m << "/" << sum.n << endl;
}

//метод класса для подсчета произведения дробей
void Mult (Fraction<T> *object, int size) {
    //умножение дробей (оператор умножения)
	Fraction<T> mult = object[0];
	for (int i = 1; i < size; i++) {
		mult = mult * object[i];
	}
	cout << "Itogovoe proizvedenie: ";
	cout << mult.m << "/" << mult.n <<endl;
}

//метод класса для подсчета частного дробей
void Div (Fraction<T> *object, int size) {
	//деление дробей (оператор деления )
	Fraction<T> div = object[0];
	for (int i = 1; i < size; i++) {
		div = div / object[i];
	}
	cout << "Itogovoe chastnoe: ";
	cout << div.m << "/" << div.n <<endl;
}
	
	
	//ПЕРЕГРУЗКА ОПЕРАТОРОВ КЛАССА
	
//перегрузка оператора присваивания
	void operator =(const Fraction<T> &other) {
	    this->m = other.m;
     	this->n = other.n;
    }
    
//перегрузка оператора вывода дробей
friend ostream& operator << (ostream& out, const Fraction<T>& object) {
		out << object.m << "/" << object.n << endl;
		return out;
	}
	
//перегрузка оператора ввода дробей
friend istream& operator >> (istream& in, Fraction<T>& object) {
	    cout << endl ;
		cout << "Input m: "; in >> object.m; 
	    cout << "Input n: "; in >> object.n; cout << endl;
	    return in;
}
    
//перегрузка оператора сложения дробей
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

//перегрузка оператора умножения дробей
Fraction operator *(const Fraction<T> &other) {
	Fraction<T> temp;
	temp.m = this->m * other.m;
	temp.n = this->n * other.n;
	return temp;
}

//перегрузка оператора деления дробей
Fraction operator /(const Fraction<T> &other) {
	Fraction<T> temp;
	temp.m = this->m * other.n;
	temp.n = this->n * other.m;
	return temp;
}
};

//-----------------------------------MAIN--------------------------------------

int main () {
	
	//задание размерности массива объектов и инициализация массива объектов класса Fraction
    int size;
	cout << "Enter a number of Fractions: ";
	cin >> size;
	Fraction<int> *object = new Fraction<int>[size];
	
	//ввод дробей
	for (int i=0; i < size; i++) {
		cout << "Enter " << i+1 <<" Fraction: ";
		cin >> object[i];
	}
	
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	
	//вывод дробей
	for (int i = 0; i < size; i++) {
		cout << i+1 << " Fraction: " << object[i] << endl;
	}
	
	//ВЫЗОВ МЕТОДОВ КЛАССА
	
	//объявление объекта класса
	Fraction<int> test;
	//подсчёт суммы дробей
    test.Sum(object, size);
    //подсчёт произведения дробей
	test.Mult(object, size);
	//подсчёт частного дробей
	test.Div(object, size);
}
