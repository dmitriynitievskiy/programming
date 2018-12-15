#include <iostream>

using namespace std;
class Node
{
public:
	int numer;
	Node* next;
	Node();
};

class List
{
private:
	Node* head;
	int Length;
public:
	List();
	~List();
	List(const List &c);
	void Show();
	void Add();
	void Add(int buf);
	void Sort();
	List Split(List c);
};


Node::Node()
{
	numer = 0;
	next = NULL;
}

List::List()
{
	head = NULL;
	Length = 0;
}

List::~List()
{
	Node* ptr = head, *tmp = NULL;
	if (head)
	{
		while (ptr->next)
		{
			tmp = ptr->next;
			delete[] ptr;
			ptr = tmp;
		}
		delete[] ptr;
	}

}

List::List(const List &c)
{
	head = NULL;
	Node *ptr = c.head;
	while (ptr)
	{
		Add(ptr->numer);
		ptr = ptr->next;
	}
}

void List::Add()
{
	int buf;
	cout << "Введите цифру: ";
	cin >> buf;
	if (head == NULL)
	{
		Node* ptr = NULL;
		ptr = new Node;
		ptr->numer = buf;
		ptr->next = NULL;
		head = ptr;
	}
	else
	{
		Node* ptr = NULL;
		ptr = new Node;
		ptr->numer = buf;
		ptr->next = head;
		head = ptr;
	}
	Length++;
	cout << "Число " << buf << " добавлено" << endl;
}

void List::Add(int buf)
{
	if (head == NULL)
	{
		Node* ptr = NULL;
		ptr = new Node;
		ptr->numer = buf;
		ptr->next = NULL;
		head = ptr;
	}
	else
	{
		Node* ptr = NULL;
		ptr = new Node;
		ptr->numer = buf;
		ptr->next = head;
		head = ptr;
	}
	Length++;
}

void List::Sort()
{
	Node* ptr = head, *tmp = NULL, *prev = NULL;
	bool flag = false;
	if (head)
	{
		do
		{
			flag = false;
			ptr = head;
			while (ptr->next)
			{
				if (ptr->numer > ptr->next->numer)
				{
					if (ptr == head)
					{
						tmp = ptr;
						ptr = tmp->next;
						tmp->next = ptr->next;
						ptr->next = tmp;
						head = ptr;
						flag = true;
					}
					else
					{
						tmp = ptr;
						ptr = tmp->next;
						tmp->next = ptr->next;
						ptr->next = tmp;
						prev->next = ptr;
						flag = true;
					}
				}
				prev = ptr;
				ptr = ptr->next;
			}
		} while (flag);
		cout << "Список отсортирован." << endl;
	}
	else
		cout << "Список пуст. Сортировать нечего." << endl;
	cout << endl;
}


void List::Show()
{
	Node* ptr = head;
	if (head == NULL)
		cout << "Список пуст." << endl;
	else
	{
		cout << "Текущий список:" << endl;
		int i = 1;
		while (ptr)
		{
			cout << i << ") ";
			cout << ptr->numer << endl;
			ptr = ptr->next;
			i++;
		}
	}
}

List List::Split(List c)
{
	List result;
	Node *ptr = head;
	while (ptr)
	{
		result.Add(ptr->numer);
		ptr = ptr->next;
	}
	ptr = c.head;
	while (ptr)
	{
		result.Add(ptr->numer);
		ptr = ptr->next;
	}
	return result;
}

int main()
{
	setlocale(0, "Russian");
	cout << endl << "Ввод списка 1 и его сортировка" << endl;
	List element;
	element.Add(6);
	element.Add(-8);
	element.Add(4);
	element.Add(9);
	element.Add(1);
	element.Add(-12);

	element.Sort();
	cout << endl << endl << "Вывод списка 1" << endl;
	element.Show();

	cout << endl << "Ввод списка 2 и его сортировка" << endl;
	List element2;
	element2.Add(57);
	element2.Add(1);
	element2.Add(3);
	element2.Add(-16);

	element2.Sort();
	cout << endl << "Вывод списка 2" << endl;
	element2.Show();

	cout << endl << "Объединение списков" << endl;
	List full = element.Split(element2);
	full.Show();

	cout << endl << "Сортируем" << endl;
	full.Sort();
	full.Show();
	system("pause");
	return 0;
}