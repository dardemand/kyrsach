// kyrsovayaSAOD.cpp: определяет точку входа для консольного приложения.
//
#pragma once
#include "stdafx.h"
#include <string.h>
#include <cstdlib>
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <string>
#include <fstream>
#include "modul.h"
#include "podporgram.h"
#include "programma.h"

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	programma *Progr = new programma();
	programma *P = new programma();
	int key = 0;
	while (key != 6)
	{
		system("cls");
		cout << "1-Добавить информацию\n2-Удалить информацию\n3-Вывод данных на консоль\n4-Загрузить информацию из файла\n5-Сохранить информацию в файл\n6-Выход" << endl;
		while (!(cin >> key))
		{
			system("cls");
			cout << "Вы ввели не правильные данные" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "1-Добавить информацию\n2-Удалить информацию\n3-Вывод данных на консоль\n4-Загрузить информацию из файла\n5-Сохранить информацию в файл\n6-Выход" << endl;
		}

		switch (key)
		{
		case 1:
		{
			Progr->AddElement();
			break;
		}
		case 2:
		{
			Progr->DeleteElement();
			break;
		}
		case 3:
		{
			if (Progr->getName() == NULL)
			{
				cout << "Ошибка , введите программы" << endl;
				system("pause");
				break;
			}
			Progr->Show();
			break;
		}
		case 4:
		{
			
		}
		case 5:
		{
		}
		case 6:
		{
			delete Progr;
			exit(0);
			break;
		}
		}
	}
	system("pause");
	return 0;
}

