#define _CRT_SECURE_NO_WARNINGS 
#include "modul.h"
#include "podporgram.h"
#include <iostream>
#include <string>
#include "tinyxml.h"
#pragma once
using namespace std;
const int N =5;
class programma
{
public:
	programma();
	~programma();
	char *getName();
	void setName(char *Name_program);
	void AddElement();
	void DeleteElement();
	void PushPodpr();
	void PopPodpr();
	void PopModule();
	void Show();
	void LoadFile();
	void SaveFile();
private:
	char *Name_program;
	modul *modl[N];
	int count;
};

