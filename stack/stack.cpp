#include "stdafx.h" 
#include <iostream> 
#include <stdio.h>
#include <fstream>

using namespace std;

struct number {
	int value;		// ������� �����
	number *adr;	// ����� ���������� ��������
};

int main()
{
	number *top = NULL, *p, *tail;
	ifstream file("c:\\temp\\file.txt");
	if (!file.is_open())
		perror("File opening error");
	else
	{
// ���������� ��������� � ����		
		do
		{
			p = new number;		// ������ ����� ������� ������
			p->adr = top;		// ����������� � ����������� ��������
			file >> p->value;	// ��������� ����� �� �����
			cout << "Read value: " << p->value << "\tAddress: " << p << '\n';
			top = p;			// ������� ������� �����
		} while (!file.eof());	// ��������� ���� ���� ���� ��� ���-�� � �����

		file.close();
		tail = top;				// ��������� ����� ������ ������

// ������ �����
		top = tail;				// ��������� � ����� ������
		if (!top) // ������� ��� ������� ���� ����
		{
			puts("Stack is empty!");
		}
		cout << "\nValue\t Address\n";
		while (top != NULL)
		{
			cout << "  " << top->value << '\t' << top << '\n';
			top = top->adr;
		}
		cout << endl;
		top = tail;				// ��������� � ����� ������

// ������� � 5 �� ����� �������� �����




// �������� ������� ���������� ������ ������
		p = top; // ����� �� �������� ������� �����, ����� ������������ �������������� ���������
		while (p->value != 7 && p->adr != NULL) { // ���� �� �� ����� �� ����� 7, � ���� � ���, �� �� ����� ������
			p = p->adr; // ��������� ����
		}
		number *new_el = new number; // ������ ����� ������� ������
		new_el->value = 15; // ��������� � ���� ����� 15
		new_el->adr = p->adr; // ����������� ����� ������� � ��������� � ������ 8
		p->adr = new_el; // ����������� ������� � ������ 7 � ������ ��������

// ������ �����
		top = tail;				// ��������� � ����� ������
		if (!top) // ������� ��� ������� ���� ����
		{
			puts("Stack is empty!");
		}
		cout << "\nValue\t Address\n";
		while (top != NULL)
		{
			cout << "  " << top->value << '\t' << top << '\n';
			top = top->adr;
		}
		cout << endl;
		top = tail;				// ��������� � ����� ������


 // �������� �������� �� �����
		//p = start;
		while (p->adr != NULL) // ���� �� ����� �� ����� ������
		{
			if (p->adr->value != 15) // ���� �� ����� �� ����� 15
				p = p->adr; // ��������� ����
			else
				break;
		}
		number *p2 = p->adr; // ��������� ����� �������� � ����� ���������
		p->adr = p->adr->adr; // ����������� ����� � ���������� �������� ����� ����������
		delete p2; // ������� �������


// ������ �����
		top = tail;				// ��������� � ����� ������
		if (!top) // ������� ��� ������� ���� ����
		{
			puts("Stack is empty!");
		}
		cout << "\nValue\t Address\n";
		while (top != NULL)
		{
			cout << "  " << top->value << '\t' << top << '\n';
			top = top->adr;
		}
		cout << endl;
		top = tail;				// ��������� � ����� ������


	}
	return 0;
}