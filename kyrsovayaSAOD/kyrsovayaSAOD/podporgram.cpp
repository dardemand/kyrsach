#include "stdafx.h"
#include "podporgram.h"
#include <string.h>


podporgram::podporgram(char* title, int quantity)
{
	if (title != nullptr)
	{
		this->title = title;
	}
	else
	{
		return;
	}
	this->quantity = quantity;
	this->Next = NULL;
}
char *podporgram::getTitle()
{
	return this->title;
}

int podporgram::getQuantity()
{
	return-this->quantity;
}

podporgram *podporgram::getNext()
{
	return this->Next;
}
void podporgram::setTitle(char* title)
{
	this->title = title;
}
void podporgram::setQuantity(int quantity)
{
	this->quantity = quantity;
}
void podporgram::setNext(podporgram *podprogram)
{
	this->Next = podprogram;
}
podporgram::podporgram()
{

}
podporgram::~podporgram()
{
	this->title = NULL;
	this->quantity = NULL;
	this->Next = NULL;
}
