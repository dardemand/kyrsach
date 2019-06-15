#define _CRT_SECURE_NO_WARNINGS 
#include "stdafx.h"
#include "programma.h"
#include "podporgram.h"
#include "modul.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <C:\Users\������\source\SAOD\Kyrsovaya SAOD\Kyrsovaya SAOD\tinyxml2.h>

using namespace std;
programma::programma()
{
	this->Name_program = NULL;
	this->count = 0;
	for (int i = 0; i < N; i++)
	{
		modl[i] = new modul();
		modl[i]->setTitleModul(nullptr);
		modl[i]->setPodpr(NULL);
	}
}

programma::~programma()
{
	int j = 0;
	while(j<count)
		{
		modl[j]->setTitleModul(nullptr);
		modl[j]->setPodpr(NULL);
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

void programma::PushPodpr()
{
	char *titleM = (char*)malloc(256 * sizeof(char));
	std::cout << "������� �������� ������" << std::endl;
	std::cin >> titleM;
	int j = 0;
	int f = -1;
	while (j != count)
	{
		if ((strcmp(modl[j]->GetTitleModul(), titleM) == 0))
		{
			f = j;
			char *title = (char*)malloc(256 * sizeof(char));
			int quantity;
			std::cout << "������ ������ " << std::endl;
			std::cout << "������� �������� ������������" << std::endl;
			std::cin >> title;
			std::cout << "������� ���������� ����� ����" << std::endl;
			while (!(std::cin >> quantity))
			{
				cout << "������ ,�� ����� �� ���������� ������" << endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "������� ���������� ����� ����" << std::endl;
			}
			podporgram *current = modl[f]->GetPodpr();
			podporgram *ctemp = new podporgram(title, -quantity);
			if (current == NULL)
			{
				ctemp->setNext(current);
				current = ctemp;
				modl[f]->Push_Podpr(current);
			}
			else
			{
				while (current != NULL)
				{
					if (strcmp(current->getTitle(), title) == 0)
					{
						std::cout << "������ ,������������� � ����� ��������� ��� ����!" << std::endl;
						system("pause");
						return;
					}
					current = current->getNext();
				}
				ctemp->setNext(current);
				current = ctemp;
				modl[f]->Push_Podpr(current);
			}

			return;
		}
		j++;
	}
	if (f = -1)
	{
		std::cout << "������ ������ ���" << std::endl;
		system("pause");
		return;
	}
	return;
}

void programma::Show()
{
	int j = 0;
	std::cout << "�������� ��������� : " << this->getName() << std::endl;
	if (this->count == 0)
	{
		std::cout << "\t ��� ������� : " << std::endl;
	}
	else
	{
		while (j < count)
		{
			std::cout << "\t�������� ������ : " << modl[j]->GetTitleModul() << std::endl;
			if (modl[j]->GetPodpr() == NULL)
			{
				std::cout << "\t������ ���� : " << std::endl;
			}
			else
			{
				podporgram *pp = modl[j]->GetPodpr();
				while (pp != NULL)
				{
					std::cout << "\t\t�������� : " << pp->getTitle() << ", ���������� ����� ���� : " << pp->getQuantity() << std::endl;
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
		std::cout << "������ , ������ ������� ������� " << std::endl;
		system("pause");
		return;
	}
	while (modl[j]->GetPodpr()!=NULL)
	{
		podporgram *pp = modl[j]->GetPodpr();
		this->modl[j]->setPodpr(pp->getNext());
		delete pp;
	}
	modl[j]->setTitleModul(NULL);
	this->count--;
	std::cout << "������  ������" << std::endl;
	system("pause");
}

void programma::PopPodpr()
{
	char *titleM = (char*)malloc(256 * sizeof(char));
	std::cout << "������� �������� ������" << std::endl;
	std::cin >> titleM;
	int f = -1;
	int j = 0;
	while (j < this->count)
	{
		if (strcmp(modl[j]->GetTitleModul(), titleM) == 0)
		{
			f = j;
			std::cout << "������ ������ " << std::endl;
			modl[f]->Pop_Podpr();
			system("pause");
			return;
		}
	}
	if (f = -1)
	{
		std::cout << "������ �� ������ " << std::endl;
		system("pause");
		return;
	}
}

void programma::AddElement()
{
	if (this->Name_program == NULL)
	{
		std::cout << "������� �������� ���������" << std::endl;
		char *Name_programm = (char*)malloc(256 * sizeof(char));
		std::cin >> Name_programm;
		this->Name_program = Name_programm;
		return;
	}
	int key = 0;
	std::cout << "1-�������� ������\n2-�������� ������������" << std::endl;
	while (!(std::cin >> key))
	{
		cout << "������ ,�� ����� �� ���������� ������" << endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "1-�������� ������\n2-�������� ������������" << std::endl;
	}
	switch (key)
	{
	case 1:
	{
		if (this->count != N)
		{
			
			char *titleM = (char*)malloc(256 * sizeof(char));
			std::cout << "������� �������� ������" << std::endl;
			std::cin >> titleM;
			int i = 0;
			while (i<this->count)
			{
				if (strcmp(modl[i]->GetTitleModul(), titleM) == 0)
				{
					std::cout << "������ ,������ � ����� ������ ����!" << std::endl;
					system("pause");
					break;
				}
				i++;
			}
				if (this->count == 0)
				{
					modl[0]->setTitleModul(titleM);
					modl[0]->setPodpr(NULL);
					this->count++;
				}
			else
			{
				modl[i]->setTitleModul(titleM);
				modl[i]->setPodpr(NULL);
				this->count++;
			}
			break;
		}
		else
		{
			std::cout << "������ ���������" << std::endl;
			system("pause");
			break;
		}
	}
	case 2:
	{
		if (this->count == 0)
		{
			std::cout << "������, ��� ������.������� �������� ������ " << std::endl;
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
		cout << "������ , ��� ��������� ��� �������� " << endl;
		system("pause");
		return;
	}
	int key = 0;
	std::cout << "1-������� ������\n2-������� ������������" << std::endl;
	while (!(std::cin >> key))
	{
		cout << "������ ,�� ����� �� ���������� ������" << endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "1������� ������\n2-������� ������������" << std::endl;
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
			std::cout << "������, ��� ������.� ������ �������� ������ " << std::endl;
			system("pause");
			break;
		}
		this->PopPodpr();
		break;
	}
	}
}

void programma::SaveFile()
{
	int i = 0;
	tinyxml2::XMLDocument file;
	tinyxml2::XMLNode *proot = file.NewElement("Programma");
	file.InsertFirstChild(proot);
	tinyxml2::XMLElement *pName = file.NewElement("Name_programm");
	if (this->getName() != nullptr) {
		char* msg = (char*)malloc(256 * sizeof(char));
		strcpy(string, msg, this->getName());
		pName->SetText(msg);
		proot->InsertEndChild(pName);
		while (i<this->count )
		{
			tinyxml2::XMLElement *pEl = file.NewElement("Modul");
			tinyxml2::XMLElement *pElement = file.NewElement("TitleM");
			char* msg = (char*)malloc(256 * sizeof(char));
			strcpy(msg, modl[i]->GetTitleModul());
			pElement->SetText(msg);
			pEl->InsertEndChild(pElement);
			proot->InsertEndChild(pEl);
			podporgram *p = modl[i]->GetPodpr();
			while (p != NULL)
			{
				tinyxml2::XMLElement *pTitle = file.NewElement("Title");
				tinyxml2::XMLElement *pQuantity = file.NewElement("Quantity");
				char* msg = (char*)malloc(256 * sizeof(char));
				strcpy(msg, p->getTitle());
				pTitle->SetText(msg);
				pQuantity->SetText(p->getQuantity());
				pEl->InsertEndChild(pTitle);
				pEl->InsertEndChild(pQuantity);
				p = p->getNext();
			}
			
		}
		tinyxml2::XMLError eResult = file.SaveFile("file.xml");
		std::cout << "���������� ������� ������" << std::endl;
		system("pause");
	}
	else
	{
		std::cout << "������ , ������ ���������. ���� �������� ����" << std::endl;
		system("pause");
		return;
	}
}
