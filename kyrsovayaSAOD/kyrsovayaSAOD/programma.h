#include "modul.h"
#include "podporgram.h"
#include <iostream>
#include<string>
#pragma once
using namespace std;
const int N = 20;
class programma
{
public:
	programma();
	~programma();
	char *getName();
	void setName(char *Name_program);
	modul *getModul();
	void AddElement();
	void DeleteElement();
	void setModule(modul *modul);
	void PushModule(modul *modul);
	void PushPodpr();
	void PopPodpr();
	void PopMOdule();
	void Show();
	void LoadFile();
	void SaveFile();
	void PushModul(modul *modul);
private:
	char *Name_program;
	modul *modul[N];
	int count;
};

