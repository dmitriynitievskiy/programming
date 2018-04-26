//� ������� ������� ��� �����,
//���������� ������ �����, ������� �����
//������������ �������� ������� �������
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
//������� ����� ��������� �������
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
//������� ������ ��������� �������
	void output (int *array, int n) {
		for (int i=0; i<n; i++) {
		cout<<array[i]<<' ';
	}
}
//������� ���������� ������������ �������� �������
    void search (int *array, int &m, int size, int &min_pos) {
    	m=array[0];
    	for (int i=0; i<size; i++) {
    	        if (array[i]<m) {
				m=array[i];
				min_pos=i;}
    	    }		
	}

//������� �������� ��������� � ������� ������� ����� ������������ 
	void func (int *array, int &size, int min, int min_pos) {
	    int  num, rem; bool pr=false;
        for (int i=min_pos+1; i<size; i++) {
                       rem=array[i];                  //���������� ������� ������� �������
					   while (array[i] != 0) {
						   num=array[i] % 10;         //�������� ����� �����
						   array[i]=array[i] / 10;

						   if (num % 2 == 0) {         //��������� �������� �� ����� ������
							   pr=true;
							   for (int k=i; k<size-1; k++) {
								   array[k]=array[k+1];
							   }
							   size--;
							   i--;
						   }
						if (pr) break;
					   }
					   if (!pr) array[i]=rem;        //���� ������� ������� �� �������� ������ ����, ��������� ������ ����� ��� ���������
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