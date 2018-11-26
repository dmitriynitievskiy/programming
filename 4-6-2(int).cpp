#include <iostream>
#include <cmath>
using namespace std;

class Money {
	public:
	int rub;
	int coin;
    
   Money() {
   	rub = 0;
   	coin = 0;
   }
   
   Money(int valueRub, int valueCoin) {
		rub = valueRub;
		coin = valueCoin;
	}

//перегрузка оператора сложения
Money operator +(const Money &other){
	Money temp;
	temp.rub = this->rub + other.rub;
	temp.coin = this->coin + other.coin;
	return temp;
}

//перегрузка оператора вычитания
Money operator -(const Money &other) {
	Money temp;
	temp.rub = this->rub - other.rub;
	temp.coin = this->coin - other.coin;
	return temp;
}

//перегрузка оператора сравнения ==
bool operator ==(const Money &other) {
	if (this->rub == other.rub && this->coin == other.coin) {
		return true;
	}
	else {
		return false;
	}
}

//перегрузка оператора сравнения <
bool operator <(const Money &other) {
	if (this->rub < other.rub) {
		return true;
	}
	else if (this->rub == other.rub && this->coin < other.coin) {
		return true;
	}
	else {
		return false;
	}
	
}
};

int main () {
	setlocale(LC_ALL, "ru");
	
	//массив объектов
	int size;
	cout << "Enter a number of Sum of Money: ";
	cin >> size;
	Money *object = new Money[size];
	
	for (int i=0; i < size; i++) {
		cout << "Enter " << i+1 <<" Sum of Money: ";
		cout << "Rub: ";
		cin >> object[i].rub; cout << endl;
		cout << "Coins: ";
		cin >> object[i].coin; cout << endl;
	}
	for (int i = 0; i < size; i++) {
		cout << i+1 << " Sum of Money: " << object[i].rub << "," << object[i].coin << endl;
	}
	

	
	//сумма денег (оператор сложения)
	Money itog;
	for (int i = 0; i < size; i++) {
		itog = itog + object[i];
	}
	
	if (itog.coin >= 100) {
		int temp_rub;
		int temp_coin;
		temp_rub = itog.coin / 100;
		temp_coin = itog.coin % 100;
		itog.rub += temp_rub;
		itog.coin = temp_coin;
		
	}
	cout << "Itogovaya summa: ";
	cout << itog.rub << "," << itog.coin << endl;
	
	//разница денег (оператор вычитания)
	Money razn = object[0];
	for (int i = 1; i < size; i++) {
		razn = razn - object[i];
	}
	razn.coin = abs(razn.coin);
	if (razn.coin >= 100) {
		int temp_rub;
		int temp_coin;
		temp_rub = razn.coin / 100;
		temp_coin = razn.coin % 100;
		razn.rub -= temp_rub;
		razn.coin = temp_coin;
	}
	cout << "Itogovaya raznost': ";
	cout << razn.rub << "," <<razn.coin <<endl;
	
	//сравнение денег (оператор ==)
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			cout << i+1 << " Sum equals " << j+1 << " Sum: ";
			bool temp = object[i] == object[j];
			if (temp == 0) {
				cout << "false" << endl;
			}
			else {
				cout << "true" << endl;
			}
		}
	}
	
	//сравнение денег (оператор < )
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			cout << i+1 << " Sum less than " << j+1 << " Sum: ";
			bool temp = object[i] < object[j];
			if (temp == 0) {
				cout << "false" << endl;
			}
			else {
				cout << "true" << endl;
			}
		}
	}
	
	
		
		

	
}
