/*------------------------------------Лабораторная работа №3------------------------------------------------*/
/*Построить класс для работы со стеком. Элемент стека - целое число. Ввести две неубывающие последовательности
чисел в два стека. Использовать третий стек для слияния двух последовательностей в одну неубывающую*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Stack {
	private:
	    int index;
	    int* element;
	    int max_size;
	    
	public:
	
		Stack (int size) {
			element = new int [size];
			index = 0;
			max_size = size;
		}
		
		void push (int elem) {
			if (index < max_size) {
				element[index] = elem;
				++index;
		    }
		}
		
		int top () {
			if (index <= 0) {
			    --index;
			    return -1000;
		    }
		    else {
			    return element[--index];
			}
		}
		
		void pop () {
			if (index >= 0) {
			    index++;
		    }
		}
		
		void print() {
			for (int i = 0; i < max_size; i++) {
				cout << element[i] << ' ';
			}
	    }
	    
	    void show () {
	    	for (int i = (max_size-1); i >= 0; i--) {
				cout << element[i] << ' ';
			}
		}
		
		
};

int main () {
	
	cout << "1-file, 2-console" << endl;
	int n;
	cin >> n;
	switch(n) {
	
	case 1:  {
	
	
	//файл
	char buff_stack1[50];
	char buff_stack2[50];
	ifstream fin("stack.txt");
	if (!fin.is_open()) cout <<"Not open";
	else{
	
	fin.getline(buff_stack1,50);
	fin.getline(buff_stack2,50);
	fin.close();
	cout << buff_stack1 << endl;
	cout << buff_stack2 << endl;
}
char temp[10];
int array1[50];
int array2[50];
int array_size = 0;
int counter = 0;
int j = 0;
    for (int i = 0; i < 50 ; i++) {
    	if (buff_stack1[i] == ' ' || buff_stack1[i] == '\n') {
    		int size = counter;
    		array1[j] = 0;
    		for (int i = 0; i < size; i++) {
    			array1[j] += (temp[i] - '0')*pow(10,counter-1);
    			counter--;
    			
			}
			j++;
			counter = 0;
    	}
		
		else {
			temp[counter] = buff_stack1[i];
			counter++;
		}
	}
	int size1 = j;
    
	Stack stack4(j);
	cout << "FIRST STACK: ";
	for (int i = 0; i < j; i++) {
		stack4.push(array1[i]);
	}
	stack4.print(); cout << endl;

    
	
j = 0; counter = 0;	
 for (int i = 0; i < 50; i++) {
    	if (buff_stack2[i] == ' ' || buff_stack2[i] == '\n') {
    		int size = counter;
    		array2[j] = 0;
    		for (int i = 0; i < size; i++) {
    			array2[j] += (temp[i] - '0')*pow(10,counter-1);
    			counter--;
			}
			j++;
			counter = 0;
    	}
		
		else {
			temp[counter] = buff_stack2[i];
			counter++;
		}
	}
	
	int size2 = j;
	Stack stack5(j);
	cout << "SECOND STACK: ";
	for (int i = 0; i < j; i++) {
		stack5.push(array2[i]);
	}
	stack5.print(); cout << endl;
	
	int size3 = size1 + size2;
	Stack stack6(size3);
	for (int i = size3; i >= 0; i--) {
	    int test3 = stack4.top();
    	int test4 = stack5.top();
        if ( test3 > test4 ) {
        	stack6.push(test3);
            stack5.pop();
        }
        else {
            stack6.push(test4);
            stack4.pop();
        }
    }
    cout << "THIRD STACK: ";
    stack6.show();
    cout << endl;
    break;
}
    
    case 2: {
		
	
//консоль
	int size1, size2;
	cout << "Input dimension of 1-st STACK: "; cin >> size1;
	cout << "Input dimension of 2-nd STACK: "; cin >> size2;
	int size3 = size1 + size2;
	Stack stack1(size1);
	Stack stack2(size2);
	Stack stack3(size3);
	int element;
	cout << "Input 1-st STACK: ";
	for  (int i = 0; i < size1; i++) {
		cin >> element;
		stack1.push(element);
	}
	cout << "Input 2-nd STACK: ";
	for  (int i = 0; i < size2; i++) {
		cin >> element;
		stack2.push(element);
	}
	cout << "FIRST STACK: ";
	stack1.print();
	cout << endl;
	cout << "SECOND STACK: ";
	stack2.print();
	cout << endl;
	
	for (int i = size3; i >= 0; i--) {
	    int test1 = stack1.top();
    	int test2 = stack2.top();
        if ( test1 > test2 ) {
        	stack3.push(test1);
            stack2.pop();
        }
        else {
            stack3.push(test2);
            stack1.pop();
        }
    }
    cout << "THIRD STACK: ";
    stack3.show();
    cout << endl;
    break;
}
}
}
