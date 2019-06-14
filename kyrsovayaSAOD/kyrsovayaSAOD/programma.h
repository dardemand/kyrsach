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
	void AddElement();
	void DeleteElement();
	void PushModule();//f
	void PushPodpr();//f
	void PopPodpr();//f
	void PopModule();//f
	void Show();//f
	void LoadFile();
	void SaveFile();
private:
	char *Name_program;
	modul *modl[N];
	int count;
};

