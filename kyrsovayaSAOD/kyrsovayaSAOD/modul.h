#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <string>
#include "podporgram.h"
#pragma once

class modul
{
public:
	modul();
	~modul();
	char *GetTitleModul();
	void setTitleModul(char *TitleM);
	int getNext();
	void setNext(int next);
	void Push_Podpr(podporgram *podprogram);
	void Pop_Podpr();
	void setPodpr(podporgram *podprogram);
	podporgram *GetPodpr();

private:
	char *titleM;//имя модуля
	int next; 
	podporgram *podprogram;
};

