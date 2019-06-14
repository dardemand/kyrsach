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
	programma(char *Name_program);
	~programma();
	char *getName();
	void setName(char *Name_program);
	modul *getModul();//f
	void AddElement();
	void DeleteElement();
	void setModule();
	void PushModule();//f
	void PushPodpr();//f
	void PopPodpr();//f
	void PopModule();//f
	void Show();//f
	void LoadFile();
	void SaveFile();
private:
	char *Name_program;
	modul *modul[N];
	int count;
};

