#include "stdafx.h"
#include "programma.h"
#include "podporgram.h"
#include "modul.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>


programma::programma()
{
	this->Name_program=NULL;
	this->count = 0;
	this->setModule(NULL);
}

programma::~programma()
{

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
	return this->modul[N];
}

void programma::PushModule(modul *mod)
{

}