#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


struct marks {
	int first_mark;
	int second_mark;
	int third_mark;
	int attestat;
};



class Abiturient {
public:
	char FirstName[30];
	char LastName[30];
	char Patronymic[30];
	marks mark;
	char adress[30];



	Abiturient();
	int getFirst_mark();
	int getSecond_mark();
	int getThird_mark();
	int getAttestat();
	


	void show();
};

Abiturient::Abiturient()

{
	cout << "Input name:"; cin >> FirstName;
	cout << "Input name:"; cin >> LastName;
	cout << "Input name:"; cin >> Patronymic;


	cout << "1st mark:"; cin >> mark.first_mark;
	cout << "2st mark:"; cin >> mark.second_mark;
	cout << "3st mark:"; cin >> mark.third_mark;
	cout << "4st mark:"; cin >> mark.attestat;


	cout << "Input adress:"; cin >> adress;


}

void Abiturient::show()

{

	cout << "Name :" << FirstName << ' ' << LastName << ' ' << Patronymic << endl;


	cout << "1 otm:" << mark.first_mark << endl;
	cout << "2 otm:" << mark.second_mark << endl;
	cout << "3 otm:" << mark.third_mark << endl;
	cout << "4 otm:" << mark.attestat << endl;

	cout << "Address :" << adress << endl;


}

int Abiturient::getFirst_mark() { return mark.first_mark; }
int Abiturient::getSecond_mark() { return mark.second_mark; }
int Abiturient::getThird_mark() { return mark.third_mark; }
int Abiturient::getAttestat() { return mark.attestat; }


//FILE STRUCT
struct file_marks {
	int first_mark;
	int second_mark;
	int third_mark;
	int attestat;
};



class file_Abiturient {
public:
	char FirstName[30];
	char LastName[30];
	char Patronymic[30];
	marks mark;
	char adress[30];



	file_Abiturient();
	int getFirst_mark();
	int getSecond_mark();
	int getThird_mark();
	int getAttestat();



	void show();
};

file_Abiturient::file_Abiturient()

{
	char buff1[10];
	char buff2[10];
	char buff3[10];
	char buff4[10];

	ifstream fin("abiturient.txt");
	if (!fin.is_open()) {
		throw ifstream::failure("Exception opening/reading file");
	}
	else {
		fin.getline(FirstName, 30);
		fin.getline(LastName, 30);
		fin.getline(Patronymic, 30);
		fin.getline(adress, 30);
		fin.getline(buff1,10);
		fin.getline(buff2, 10);
		fin.getline(buff3, 10);
		fin.getline(buff4, 10);
		
		mark.first_mark = atoi(buff1);
		mark.second_mark = atoi(buff2);
		mark.third_mark = atoi(buff3);
		mark.attestat = atoi(buff4);

		cout << FirstName << endl;
		cout << LastName << endl;
		cout << Patronymic << endl;
		cout << adress << endl;
		cout << mark.first_mark << endl;
		cout << mark.second_mark << endl;
		cout << mark.third_mark << endl;
		cout << mark.attestat << endl;
	}



}

void file_Abiturient::show()

{

	cout << "Name :" << FirstName << ' ' << LastName << ' ' << Patronymic << endl;


	cout << "1 otm:" << mark.first_mark << endl;
	cout << "2 otm:" << mark.second_mark << endl;
	cout << "3 otm:" << mark.third_mark << endl;
	cout << "4 otm:" << mark.attestat << endl;

	cout << "Address :" << adress << endl;


}

int file_Abiturient::getFirst_mark() { return mark.first_mark; }
int file_Abiturient::getSecond_mark() { return mark.second_mark; }
int file_Abiturient::getThird_mark() { return mark.third_mark; }
int file_Abiturient::getAttestat() { return mark.attestat; }

void file_BadMarks(file_Abiturient spis[], int n)

{
	for (int i = 0; i < n; i++) {

		if (spis[i].getFirst_mark() < 15 || spis[i].getSecond_mark() < 15 || spis[i].getThird_mark() < 15 || spis[i].getAttestat() < 15)

			spis[i].show();
	}

}


void file_Sum(file_Abiturient spis[], int n) {
	int sum;
	cout << "Vvedite summu ballov: ";
	cin >> sum;
	cout << "=======Summa ballov ne men'she zadanoy=============" << endl;
	cout << "Zadannaya summa ballov: " << sum << endl;
	for (int i = 0; i < n; i++) {
		if (spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat() >= sum)
		{
			spis[i].show();
			cout << "Summa ballov: " << spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat() << endl;
			cout << "================================================" << endl;
		}
	}
}

void file_MostHigherSum(file_Abiturient spis[], int n) {
	int kol;
	cout << "Enter kol abiturients: ";
	cin >> kol;

	char Fam[300];
	int CommonMark[100];

	for (int i = 0; i < n; i++) {
		CommonMark[i] = spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat();
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; j++) {
			if (CommonMark[j] < CommonMark[j + 1]) {
				int temp = CommonMark[j];
				CommonMark[j] = CommonMark[j + 1];
				CommonMark[j + 1] = temp;

			}
		}
	}
	for (int i = 0; i < kol; i++) {
		cout << spis[i].FirstName << endl;
	}

	cout << "---------Spis poluprohod--------" << endl;
	cout << spis[kol - 1].FirstName << endl;
	for (int i = kol - 1; i < n; i++) {
		if (CommonMark[i + 1] == CommonMark[i]) cout << spis[i + 1].FirstName << endl;
		cout << "--------------------------" << endl;
	}
	for (int i = kol - 1; i > 0; i--) {
		if (CommonMark[i - 1] == CommonMark[i]) cout << spis[i - 1].FirstName << endl;
		cout << "--------------------------" << endl;
	}

}


void BadMarks(Abiturient spis[], int n)

{
	for (int i = 0; i < n; i++) {

		if (spis[i].getFirst_mark() < 15 || spis[i].getSecond_mark() < 15 || spis[i].getThird_mark() < 15 || spis[i].getAttestat() < 15)

			spis[i].show();
	}

}


void Sum(Abiturient spis[], int n) {
	int sum;
	cout << "Vvedite summu ballov: ";
	cin >> sum;
	cout << "=======Summa ballov ne men'she zadanoy=============" << endl;
	cout << "Zadannaya summa ballov: " << sum << endl;
	for (int i = 0; i < n; i++) {
		if (spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat() >= sum)
		{
			spis[i].show();
			cout << "Summa ballov: " << spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat() << endl;
			cout << "================================================" << endl;
		}
	}
}

void MostHigherSum(Abiturient spis[], int n) {
	int kol;
	cout << "Enter kol abiturients: ";
	cin >> kol;

	char Fam[300];
	int CommonMark[100];

	for (int i = 0; i < n; i++) {
		CommonMark[i] = spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat();
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; j++) {
			if (CommonMark[j] < CommonMark[j + 1]) {
				int temp = CommonMark[j];
				CommonMark[j] = CommonMark[j + 1];
				CommonMark[j + 1] = temp;

			}
		}
	}
	for (int i = 0; i < kol; i++) {
		cout << spis[i].FirstName << endl;
	}

	cout << "---------Spis poluprohod--------" << endl;
	cout << spis[kol - 1].FirstName << endl;
	for (int i = kol - 1; i < n; i++) {
		if (CommonMark[i + 1] == CommonMark[i]) cout << spis[i + 1].FirstName << endl;
		cout << "--------------------------" << endl;
	}
	for (int i = kol - 1; i > 0; i--) {
		if (CommonMark[i - 1] == CommonMark[i]) cout << spis[i - 1].FirstName << endl;
		cout << "--------------------------" << endl;
	}

}



//========= main ================

int main()

{
	

	int change;
	cout << "1-file, 2-console: ";
	cin >> change;

	switch (change) {
		//file
	case 1: {
		
		try {
			file_Abiturient *spis;
			int n;

			cout << "Input a number of students: "; cin >> n;
			spis = new file_Abiturient[n];
			for (int i = 0; i < n; i++) {

				cout << "==============================" << endl;

				spis[i].show();

			}
			file_BadMarks(spis, n);
			file_Sum(spis, n);
			file_MostHigherSum(spis, n);


			delete[] spis;
		}
		catch (const ifstream::failure& e) {
			cout << e.what() << endl;
			cout << "FILE IS NOT OPEN" << endl;
		}
		break;
		}
			//console
	case 2: {
		Abiturient *spis;
		int n;

		cout << "Input a number of students: "; cin >> n;

		spis = new Abiturient[n];

		for (int i = 0; i < n; i++) {

			cout << "==============================" << endl;

			spis[i].show();

		}
		BadMarks(spis, n);
		Sum(spis, n);
		MostHigherSum(spis, n);


		delete[] spis;
		break;
	}
	}

	



	cout << "press any key!";
	system("pause");
	return 0;


}