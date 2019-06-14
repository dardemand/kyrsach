#include "stdafx.h"
#include "modul.h"
#include "podporgram.h"
#include <fstream>


modul::modul()
{
	this->titleM=nullptr;
	this->setPodpr(NULL);
}

modul::~modul()
{
	while (this->GetPodpr() != nullptr)
	{
		podporgram *temp = this->GetPodpr();
		this->setPodpr(this->podprogram->getNext());
		delete(temp);
	}
}

char *modul::GetTitleModul()
{
	return this->titleM;
}

void modul::setTitleModul(char *titleM)
{
	this->titleM = titleM;
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