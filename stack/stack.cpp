// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "stdafx.h" 
#include <iostream> 
#include <stdio.h>
#include <fstream>

using namespace std;

struct number {
	int value;		// Элемент стека
	number *adr;	// Адрес следующего элемента
};

int main()
{
	number *top = NULL, *p, *tail;
	ifstream file("c:\\temp\\file.txt");
	if (!file.is_open())
		perror("File opening error");
	else
	{
// Добавление элементов в стэк		
		do
		{
			p = new number;		// Создаём новый элемент списка
			p->adr = top;		// Привязываем к предыдущему элементу
			file >> p->value;	// Считываем цифру из файла
			cout << "Read value: " << p->value << "\tAddress: " << p << '\n';
			top = p;			// Смещаем вершину стека
		} while (!file.eof());	// Повторяем цикл пока есть еще что-то в файле

		file.close();
		tail = top;				// сохраняем адрес начала списка

// Печать стека
		top = tail;				// переходим в конец списка
		if (!top) // Условие при котором стек пуст
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
		top = tail;				// переходим в конец списка

// Перейти к 5 по счёту элементу стека




// вставить элемент посередине нашего списка
		p = top; // Чтобы не потерять вершину стека, будем использовать дополнительный указатель
		while (p->value != 7 && p->adr != NULL) { // Пока мы не дошли до цифры 7, и если её нет, то до конца списка
			p = p->adr; // Смещаемся вниз
		}
		number *new_el = new number; // Создаём новый элемент списка
		new_el->value = 15; // Сохраняем в него число 15
		new_el->adr = p->adr; // Привязываем новый элемент с элементов с цифрой 8
		p->adr = new_el; // Привязываем элемент с цифрой 7 к новому элементу

// Печать стека
		top = tail;				// переходим в конец списка
		if (!top) // Условие при котором стек пуст
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
		top = tail;				// переходим в конец списка


 // удаление элемента из стека
		//p = start;
		while (p->adr != NULL) // Пока не дошли до конца списка
		{
			if (p->adr->value != 15) // Пока не дошли до числа 15
				p = p->adr; // Смещаемся вниз
			else
				break;
		}
		number *p2 = p->adr; // Сохраняем адрес элемента в новый указатель
		p->adr = p->adr->adr; // Привязываем адрес к следующему элементу после удаляемого
		delete p2; // Удаляем элемент


// Печать стека
		top = tail;				// переходим в конец списка
		if (!top) // Условие при котором стек пуст
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
		top = tail;				// переходим в конец списка


	}
	return 0;
}
