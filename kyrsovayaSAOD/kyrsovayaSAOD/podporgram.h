#pragma once
class podporgram
{
public:
	podporgram();
	~podporgram();
	podporgram(char* title, int quantity);
	int getQuantity();
	char* getTitle();
	void setQuantity(int quantity);
	void setTitle(char* title);
	void setNext(podporgram *podprogram);
	podporgram *getNext();

private:
	int quantity;//���������� �����
	char *title;//�������� ������������
	podporgram *Next;//��������� �� ��������� �������
};

