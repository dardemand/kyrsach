#include "modul.h"
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
private:
	char *Name_program;
	modul modul[N];
	int count;
};

