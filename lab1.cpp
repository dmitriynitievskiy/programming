//============================ЛАБОРАТОРНАЯ РАБОТА №1==============================================//
/*Abiturient. Фамилия, Имя, Отчество, Адрес, Оценки. Создать массив объектов. Вывести:
а)список абитуриентов, имеющих неудовлетворительные оценки;
б)список абитуриентов, сумма баллов у которых не меньше заданной;
в)выбрать N абитуриентов, имеющих самую высокую сумму баллов, и список абитуриентов, 
имеющих полупроходной балл */
 
#include <string.h>
#include <iostream>
using namespace std;

//структура, содержащая переменные оценок абитуриента
struct marks {
 int first_mark;
 int second_mark;
 int third_mark;
 int attestat;
};

//======= class Abiturient =================

//класс, содержащий информацию об абитуриенте (фамилия, имя, отчество, адрес, оценки)
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
   char getFam();
  

   void show();
};

Abiturient::Abiturient()

{cout<<"Input name:"; cin>>FirstName;
cout<<"Input name:"; cin>>LastName;
cout<<"Input name:"; cin>>Patronymic;


cout<<"1st mark:"; cin>>mark.first_mark;
cout<<"2st mark:"; cin>>mark.second_mark;
cout<<"3st mark:"; cin>>mark.third_mark;
cout<<"4st mark:"; cin>>mark.attestat;


cout<<"Input adress:"; cin>>adress;


}

void Abiturient::show()

{

cout<<"Name :"<<FirstName<<' '<<LastName<<' '<<Patronymic<<endl;
 

cout<<"1 otm:"<<mark.first_mark<<endl;
cout<<"2 otm:"<<mark.second_mark<<endl;
cout<<"3 otm:"<<mark.third_mark<<endl;
cout<<"4 otm:"<<mark.attestat<<endl;

cout<<"Address :"<<adress<<endl;


}

int Abiturient::getFirst_mark() { return mark.first_mark; }
int Abiturient::getSecond_mark() { return mark.second_mark; }
int Abiturient::getThird_mark() { return mark.third_mark; }
int Abiturient::getAttestat() { return mark.attestat; }



//функция, выводящая список абитуриентов, имеющих неудовлетворительные оценки
void BadMarks(Abiturient spis[],int n)
   
{  for(int i=0; i<n; i++) {

if (spis[i].getFirst_mark() < 15 || spis[i].getSecond_mark() < 15 || spis[i].getThird_mark() < 15 || spis[i].getAttestat() < 15)

   spis[i].show();
}

}

//функция, выводящая список абитуриентов, сумма баллов у которых не меньше заданной суммы
void Sum (Abiturient spis[], int n) {
	int sum;
	cout<<"Vvedite summu ballov: ";
    cin >> sum;
    cout<<"=======Summa ballov ne men'she zadanoy============="<<endl;
    cout<<"Zadannaya summa ballov: "<<sum<<endl;
	for (int i=0; i<n; i++) {
		if (spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat() >= sum) 
		{
		spis[i].show();
		cout<<"Summa ballov: "<<spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat()<<endl;
        cout<<"================================================"<<endl;
	}
}
}

//функция, выводящая N абитуриентов, имеющих самую высокую сумму баллов и  выводящая список абитуриентов, имеющих полупроходной балл
void MostHigherSum (Abiturient spis[], int n) {
	int kol;
	cout << "Enter kol abiturients: ";
	cin >> kol;
	//пузырьковая сортировка суммы баллов с созданием нового массива суммы баллов
	char Fam[300];
	int CommonMark[100];
	
	for (int i=0; i < n; i++) {
		CommonMark[i] = spis[i].getFirst_mark() + spis[i].getSecond_mark() + spis[i].getThird_mark() + spis[i].getAttestat();
	}
	for (int i=1; i < n; ++i) {
		for (int j=0; j <n-i; j++) {
			if (CommonMark[j] < CommonMark[j+1]) {
				int temp = CommonMark[j];
				CommonMark[j] = CommonMark[j+1];
				CommonMark[j+1] = temp;
				
			}
		}
	} 
	for (int i=0; i < kol; i++) {
		cout<<spis[i].FirstName<<endl;
	}
	//список студентов, имеющих полупроходной балл (их фамилии)
	cout<<"---------Spis poluprohod--------"<<endl;
	cout<<spis[kol-1].FirstName<<endl;
	for (int i=kol-1; i < n; i++) {
		if (CommonMark[i+1] == CommonMark[i]) cout<<spis[i+1].FirstName<<endl;
		cout<<"--------------------------"<<endl;
	}
	for (int i=kol-1; i > 0; i--) {
		if (CommonMark[i-1] == CommonMark[i]) cout<<spis[i-1].FirstName<<endl;
		cout<<"--------------------------"<<endl;
	}
	
}



//========= main ================

int main()

{ Abiturient *spis;

int n;

cout<<"Input a number of students: "; cin>>n;

spis=new Abiturient [n];

for(int i=0;i<n;i++) {

cout<<"=============================="<<endl;

spis[i].show();

}

BadMarks (spis,n);
Sum (spis,n);
MostHigherSum (spis,n);


delete [] spis;

cout<<"press any key!";

}
