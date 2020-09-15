#include <iostream>
#include <time.h>
#include <cstring>
#include <string>
#include <locale.h>
#include <Windows.h>
using namespace std;

class schoolboy {
	int id;
	string name;
	int missed;
public:
	schoolboy() { // конструктор по умолчанию
		cout << "Класс школьник создан\n";
		missed = 0;
		id = 0;
		name = " - ";
	}
	schoolboy(int id1,string name1,int missed1) { // конструктор инициализации
		cout << "Класс школьник создан\n";
		id = id1;
		name = name1;
		missed = missed1;
	}
	void set() {	// функция 
		bool k = true;
		cout << "Введите ФИО:\n";
		rewind(stdin); // очистка буфера, чтобы не было проблем с русским языком 
		getline(cin, name);

		do
		{
			cout << "Введите ид:\n";
			cin >> id;
			if (cin.fail())
				cout << "Ошибка ввода.\n";
			else
				k = false;
			
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		} while (k);
		
	}


	~schoolboy() {
		cout << "Класс школьник удалён\n";
	}
	friend class teacher;
	friend void fpr(schoolboy& sh);
};
void fpr(schoolboy& sh) { // дружественная функция вывода
	cout << "ФИО: " << sh.name << endl;
	cout << "Ид: " << sh.id << endl;
	cout << "Пропуски: " << sh.missed << endl << endl;
};


class teacher {
public:
	teacher() {
		cout << "Класс учитель создан\n";
	}
	void setnewmissed(schoolboy& sh, int newmissed) { // конструктор для измен. пропусков
		sh.missed = newmissed;
	}

	~teacher() {
		cout << "Класс учитель удалён\n";
	}
};


int main() {
	system("chcp 1251");
	system("CLS");
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int i, id, newmissed;

	schoolboy sh[3] = { // инициализация
		schoolboy(1, "Rusin Nikita Alexandrovich",0),
		schoolboy(2, "Ivanov Ivan Ivanovich",10),
		schoolboy(3, "Alexander Salash Sergeevich",0),
	};

	for (i = 0; i < 3; i++) // вывод 
	{
		fpr(sh[i]); // функция вывода
	}


	for (i = 0; i < 3; i++) // новые школьники
	{

		sh[i].set(); // функция установить id и ввода
	}

	for (i = 0; i < 3; i++) // вывод школьников до измен. пропусков
	{

		fpr(sh[i]); // функция вывода
	}



	teacher tch; // конструктор для измен. пропусков
	for (i = 0; i < 3; i++)
	{
		newmissed = rand() % 31; // случайные новые пропуски от 0 до 30
		tch.setnewmissed(sh[i], newmissed);
	}


	for (i = 0; i < 3; i++) // вывод школьников после измен. пропусков
	{

		fpr(sh[i]); // функция вывода
	}
}
