//В массиве удалить все числа,
//содержащие чётные цифры, стоящие после
//минимального элемента данного массива
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
//функция ввода исходного массива
void input(int *array, int k, int size) {
   srand(size);
   if (k==1) {
    		for (int i=0; i<size; i++) {
    			array[i] = rand() % 10;
			}
		}
		if (k==2) {
			for (int i=0; i<size; i++) {
				cin>>array[i];
			}
		}
	}
//функция вывода конечного массива
	void output (int *array, int n) {
		for (int i=0; i<n; i++) {
		cout<<array[i]<<' ';
	}
}
//функция нахождения минимального элемента массива
    void search (int *array, int &m, int size, int &min_pos) {
    	m=array[0];
    	for (int i=0; i<size; i++) {
    	        if (array[i]<m) {
				m=array[i];
				min_pos=i;}
    	    }		
	}

//функция удаления элементов с чётными числами после минимального 
	void func (int *array, int &size, int min, int min_pos) {
	    int  num, rem; bool pr=false;
        for (int i=min_pos+1; i<size; i++) {
                       rem=array[i];                  //запоминаем текущий элемент массива
					   while (array[i] != 0) {
						   num=array[i] % 10;         //выделяем цифру в числе
						   array[i]=array[i] / 10;

						   if (num % 2 == 0) {         //проверяем является ли цифра чётной
							   pr=true;
							   for (int k=i; k<size-1; k++) {
								   array[k]=array[k+1];
							   }
							   size--;
							   i--;
						   }
						if (pr) break;
					   }
					   if (!pr) array[i]=rem;        //если элемент массива не содержит чётных цифр, оставляем 
		                                                         //данное число без изменений
                       pr=false;
				   }
		}


int main () {
	int min=0, n, rand_man, min_pos=0;


	cout<<"Enter array length: ";
	cin>>n;

	int *array = new int [n];
	int choice; 
	while(1) {
    cout << endl;
    cout << "1 input" << endl;
    cout << "2 output" << endl;
    cout << "3 fun" << endl;
    cout << "4 exit" << endl;
    cout << endl;
    cin >> choice;
    switch (choice) {
      case 1:
		cout<<"Enter 1 for a random filling or 2 for a manual filling: ";
	    cin>>rand_man;
        input (array, rand_man, n);
        break;
      case 2:
        output (array, n);
        break;
      case 3:
        search (array, min, n, min_pos);
		func (array, n, min, min_pos);
        break;
      case 4:
	    delete [] array;
        exit(1);
        break;
    }
	}
	system("pause");
}
