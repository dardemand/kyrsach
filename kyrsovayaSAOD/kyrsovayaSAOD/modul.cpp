#include "stdafx.h"
#include "modul.h"
#include "podporgram.h"
#include <fstream>


modul::modul()
{
	this->next = -1;
	this->titleM;
	this->setPodpr(NULL);
}

modul::~modul()
{

}

char *modul::GetTitleModul()
{
	return this->titleM;
}

void modul::setTitleModul(char *titleM)
{
	this->titleM = titleM;
}

int modul::getNext()
{
	return this->next;
}

void modul::setNext(int next)
{
	this->next = next;
}

void modul::Push_Podpr(podporgram *podprogram)
{
	podporgram *current = this->GetPodpr();
	podporgram *temp = podprogram;
	temp->setNext(current);
	current = temp;
	this->setPodpr(current);
}

void modul::Pop_Podpr()
{
	if (this->podprogram == NULL)
	{
		std::cout << "Подпрограмм нет " << std::endl;
		system("pause");
	}
	else
	{
		podporgram *current = this->GetPodpr();
		podporgram *temp = current;
		current = current->getNext();
		delete temp;
		this->setPodpr(current);
		std::cout << "Подпрограмма удалена" << std::endl;
		system("pause");
	}
}

void modul::setPodpr(podporgram *podprogram)
{
	this->podprogram = podprogram;
}

podporgram *modul::GetPodpr()
{
	return this->podprogram;
}