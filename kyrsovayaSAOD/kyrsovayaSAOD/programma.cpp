#include "stdafx.h"
#include "programma.h"
#include "podporgram.h"
#include "modul.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>


programma::programma(char *Name_program)
{
	this->Name_program = Name_program;
	modul[0]->setNext(0);
	this->count = 0;
	for (int i = 1; i < N; i++)
	{
		modul[i]->setNext(-1);
	}
}

programma::~programma()
{
	int j = 0;
	while(j<count)
		{
		modul[0]->setTitleModul(NULL);
		modul[0]->setNext(-1);
		modul[0]->setPodpr(NULL);
		}
	this->Name_program = NULL;
	this->count = 0;
}

char *programma::getName()
{
	return this->Name_program;
}

void programma::setName(char *Name_program)
{
	this->Name_program = Name_program;
}

modul *programma::getModul()
{
	return this->modul[0];
}
void programma::PushModule()//добавление модуля
{
	if(count!=N)
	{ 
		char *titleM = (char*)malloc(256 * sizeof(char));
		std::cout << "Введите название модуля" << std::endl;
		std::cin >> titleM;
	int j = 0;
	 if (modul[0]->setNext == 0)
	 {
		modul[0]->setTitleModul(titleM);
		modul[0]->setNext(0);
		modul[0]->setPodpr(NULL);
		this->count++;
	 }
	 else
	 {
		while (j < this->count)
		{
			if (strcmp(modul[j]->GetTitleModul,titleM)==0)
			{
				std::cout << "Ошибка ,модуль с таким имение есть!" << std::endl;
				system("pause");
				return;
			}
			j++;
		}
		modul[j]->setNext(j + 1);
		modul[j]->setTitleModul(titleM);
		modul[j + 1]->setNext(0);
		modul[j + 1]->setPodpr(NULL);
		this->count++;
	 }
	}
	else
	{
		std::cout << "Память заполнена " << std::endl;
		system("pause");
	}
}

void programma::PushPodpr()
{
	char *titleM = (char*)malloc(256 * sizeof(char));
	std::cout << "Введите название модуля" << std::endl;
	std::cin >> titleM;
	int j = 0;
	int f = -1;
	while (j != count)
	{
		if ((strcmp(modul[j]->GetTitleModul, titleM) == 0))
		{
			f = j;
		}
		j++;
	}
	if (f = -1)
	{
		std::cout << "Такого модуля нет" << std::endl;
		system("pause");
		return;
	}
	char *title = (char*)malloc(256 * sizeof(char));
	int quantity;
	std::cout << "Модуль найден " << std::endl;
	std::cout << "Введите название подпрограммы" << std::endl;
	std::cin >> title;
	std::cout << "Введите количество строк кода" << std::endl;
	while (!(std::cin >> quantity))
	{
		cout << "Ошибка ,вы ввели не правильные данные" << endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Введите количество строк кода" << std::endl;
	}
	podporgram *current = modul[f]->GetPodpr();
	podporgram *ctemp = new podporgram(title, quantity);
	if (current == NULL)
	{
		ctemp->setNext(current);
		current = ctemp;
		modul[f]->Push_Podpr(current);
	}
	else
	{
		while (current != NULL)
		{
			if (strcmp(current->getTitle(),title ) == 0)
			{
				std::cout << "Ошибка ,подпрограммая с таким названием уже есть!" << std::endl;
				system("pause");
				return;
			}
			current = current->getNext();
		}
	}
	podporgram *vurrent = modul[f]->GetPodpr();
	ctemp->setNext(vurrent);
	vurrent = ctemp;
	modul[f]->Push_Podpr(vurrent);
	return;
}

void programma::Show()
{
	int j = 0;
	std::cout << "Название программы : " << this->getName() << std::endl;
	modul[0] = this->getModul();
	if (count == 0)
	{
		std::cout << "\t Нет модулей : " << std::endl;
	}
	else
	{
		while (j != count)
		{
			std::cout << "\tНазвание модуля : " << modul[j]->GetTitleModul() << std::endl;
			if (modul[j]->GetPodpr == NULL)
			{
				std::cout << "\tМодуль пуст : " << std::endl;
			}
			else
			{
				podporgram *pp = modul[j]->GetPodpr();
				while (pp != NULL)
				{
					std::cout << "\t\tНазвание : " << pp->getTitle << ", Количество строк кода : " << pp->getQuantity() << std::endl;
					pp = pp->getNext();
				}
			}
			j++;
		}
	}
	system("pause");
}

void programma::PopModule()
{
	int j = count-1;
	if (count == 0)
	{
		std::cout << "Ошибка , нельзя удалить команду " << std::endl;
		system("pause");
		return;
	}
	while (modul[j]->GetPodpr()!=NULL)
	{
		podporgram *pp = modul[j]->GetPodpr();
		this->modul[j]->setPodpr(pp->getNext());
		delete pp;
	}
	modul[j]->setNext(-1);
	modul[j]->setTitleModul(NULL);
	this->count--;
	std::cout << "Модуль  удален" << std::endl;
	system("pause");
}

void programma::PopPodpr()
{
	char *titleM = (char*)malloc(256 * sizeof(char));
	std::cout << "Введите название модуля" << std::endl;
	std::cin >> titleM;
	int f = -1;
	int j = 0;
	while (j != count)
	{
		if (strcmp(modul[j]->GetTitleModul, titleM) == 0)
		{
			f = j;
		}
	}
	if (f = -1)
	{
		std::cout << "Модуль не найден " << std::endl;
		system("pause");
		return;
	}
	else
	{
		std::cout << "Модуль найден " << std::endl;
		modul[f]->Pop_Podpr();
		std::cout << "Подпрограмма удалена " << std::endl;
		system("pause");
	}
}

void programma::AddElement()
{
	if (this->Name_program == NULL)
	{
		std::cout << "Введите название программы" << std::endl;
		char *Name_programm = (char*)malloc(256 * sizeof(char));
		std::cin >> Name_programm;
		this->Name_program = Name_programm;
		return;
	}
	int key = 0;
	std::cout << "1-Добавить модуль\n2-Добавить подпрограмму" << std::endl;
	while (!(std::cin >> key))
	{
		cout << "Ошибка ,вы ввели не правильные данные" << endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "1-Добавить модуль\n2-Добавить подпрограмму" << std::endl;
	}
	switch (key)
	{
	case 1:
	{
		if (this->count != N)
		{
			char *titleM = (char*)malloc(256 * sizeof(char));
			std::cout << "Введите название модуля" << std::endl;
			std::cin >> titleM;
			if (this->count == 0)
			{
				modul[0]->setTitleModul(titleM);
				modul[0]->setPodpr(NULL);
				this->count++;
			}
			else
			{
				modul[count - 1]->setTitleModul(titleM);
				modul[count - 1]->setPodpr(NULL);
				this->count++;
			}
			break;
		}
		else
		{
			std::cout << "Память заполнена" << std::endl;
			system("pause");
		}
	}
	case 2:
	{
		if (this->count == 0)
		{
			std::cout << "Ошибка, нет модуля.Сначала добавьте модуль " << std::endl;
			system("pause");
			break;
		}
		this->PushPodpr();
		break;
	}
	}
}

void programma::DeleteElement()
{
	if (this->Name_program == NULL)
	{
		cout << "Ошибка , нет элементов для удаления " << endl;
		system("pause");
		return;
	}
	int key = 0;
	std::cout << "1-Удалить модуль\n2-Удалить подпрограмму" << std::endl;
	while (!(std::cin >> key))
	{
		cout << "Ошибка ,вы ввели не правильные данные" << endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "1Удалить модуль\n2-Удалить подпрограмму" << std::endl;
	}
	switch (key)
	{
	case 1:
	{
		this->PopModule();
		break;
	}
	case 2:
	{
		if (this->count == 0)
		{
			std::cout << "Ошибка, нет модуля.С начала добавьте модуль " << std::endl;
			system("pause");
			break;
		}
		this->PopPodpr();
		break;
	}
	}
}