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

}


podporgram::~podporgram()
{
}
