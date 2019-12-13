#include "pch.h"
#include <iostream>
#include "math.h"
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

struct node {

	int inf;
	int key;
	node* next;
	node* previous;

};

class LinkList {
private:

	node *head, *root;

public:

	LinkList() {

		root = NULL;
		head = root;

	}

	void Add(int inf, int n)
	{

		node* var = new node;
		var->key = n;
		var->inf = inf;
		var->previous= head;
		var->next = NULL;
		(head != NULL) ? head->next = var : NULL;
		head = var;
		(root == NULL) ? root = head : NULL;

	}

	void Show()
	{

		node* var = new node;
		var = root;
		while (var != NULL)
		{

			cout << var->inf << "--" << var->key << ". ";
			var = var->next;

		}	

	}

	void File()
	{

		ofstream out("List_Out.txt");
		node *var = new node;
		var = root;
		while (var != NULL)
		{

			out << var->inf << " " << var->key << endl;
			var = var->next;

		}

	}

	void AddNum(int num, int inf, int key)
	{

		node *var = new node, *h = new node;
		var = root;
		for (int i = 0; i < num-1; i++)
			if (var != NULL)
				var = var->next;
			else
				return;
		if (num == 0)
		{
			var->previous = h;
			h->next = var;
			h->previous = NULL;
			root = h;
		}
		else
		{
			h->next = var->next;
			(var != NULL) ? var->next = h : NULL;
			(h->next != NULL) ? h->next->previous = h : NULL;
			h->previous = var;
		}

		h->inf = inf;
		h->key = key;		

	}

	void Sort() 
	{

		int checkcount = 1;
		node *var = new node;
		while (checkcount != 0)
		{
			var = root;
			checkcount = 0;
			while (var->next != NULL)
			{
				if (var->key >= var->next->key)
				{
					int vkey = var->key, vinf = var->inf;
					vkey = var->key;
					vinf = var->inf;
					var->key = var->next->key;
					var->inf = var->next->inf;
					var->next->key = vkey;
					var->next->inf = vinf;
					checkcount++;
				}
				var = var->next;
			}
		}

	}

	node *Root()

	{

		return root;

	}

};

int main()
{

	setlocale(LC_ALL, "Russian");
	const int  N= 100;
	int n, t, key;
	int mass[N], m = 0;
	bool exit = false;
	node *k = new node;
	LinkList list;
	int choose, choose1;
	ifstream input("List_In.txt");

	for (int h = 0; h < N; h++)
		mass[h] = NULL;

	while (!exit)
	{

		cout << "1) Создать список (пустой)\n";
		cout << "2) Добавить\n";
		cout << "3) Найти по ключу\n";
		cout << "4) Изменить\n";
		cout << "5) Показать список\n";
		cout << "6) Отсортировать список\n";
		cout << "7) Записать в файл (""List_Out.txt"")\n";
		cout << "8) Ввести данные из файла (""List_In.txt"")\n";
		cout << "9) Завершить\n";
		cin >> choose;

		switch (choose)
		{

		case 1: 
			break;
		case 2:cout << "Способ добавления элемента:\n";
			cout << "1) В конец\n";
			cout << "2) Произвольно\n";
			cin >> choose1;
			switch (choose1)
			{
			case 1: cout << "Пожалуйста, введите информацию и ключ:\n";
				cin >> t >> key;
				list.Add(t, key);
				break;
			case 2:
				cout << "Пожалуйста, введите новую позицию, информацию и ключ:\n";
				cin >> n >> t >> key;
				list.AddNum(n, t, key);
				break;
			default: cout << "Ошибочные данные\n";
			}
			break;
		case 3:
			cout << "Введите ключ\n";
			cin >> n;
			k = list.Root();
			while (k->key != n && k != NULL)
				k = k->next;
			cout << k->inf << ". " << k->key << "\n";
			break;
		case 6:
			list.Sort();
			break;
		case 4:
			cout << "Какой элемент вам нужно изменить (по ключу)?\n";
			cin >> key;
			k = list.Root();
			while (k->key != key && k != NULL)
				k = k->next;
			cout << "Введите новую информацию\n";
			cin >> n;
			k->inf = n;
			break;
		case 5:
			list.Show();
			break;
		case 7:
			list.File();
			break;
		case 8:
			while (input >> mass[m])
				m++;
			for (int z = 0; z < m - m % 2; z += 2)
				list.Add(mass[z], mass[z + 1]);
			break;
		case 9: exit = true;
			break;
		default: cout << "Ошибочные данные\n";

		}

	}

}