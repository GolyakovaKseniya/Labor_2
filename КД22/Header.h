#pragma once
# include <windows.h>
# include <iostream>
//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

//FIX_ME: неправильное название простого класса, должен иметь префикс F
//class Node
class FNode
{
public:
	//FIX_ME: неправильное название полей класса
	/*int data;
	FNode* next;*/
	int Data;
	FNode* Next;

	//FIX_ME: нет конструктора
	FNode(int InData);
};

//FIX_ME: отсутствует моделирование стуктуры "очередь", все функции глобальные
//FIX_ME: отсутствует инкапсуляция

//FIX_ME: непонятный псевдоним
//typedef FNode* PNode;

class FQueue
{
private:
	//FIX_ME: пропишем поля стурктуры 
	FNode* Head; //Начало очереди
	FNode* Tail; //Конец очереди
	int Count; //Количество элементов в очереди

public:
	//FIX_ME: отсутствует конструктор, инициализация рарознена
	FQueue();

	//FIX_ME: происходит утечка памяти
	~FQueue();

	//FIX_ME: функция не является методом класса, не связана с данными
	//void add(int data, PNode& Head, PNode& Tail)
	//FIX_ME: неинформативное название функции
	//void add
	//FIX_ME: неправильное название параметра
	//int data
	void Push(int InData);


	//FIX_ME: функция не является методом класса, не связана с данными
	//void show1(PNode head)
	//FIX_ME: неинформативное название функции
	//void show1
	//FIX_ME: неправильное название параметра
	//FNodePtr head
	void PrintFirst();

	//FIX_ME: функция не является методом класса, не связана с данными
	//FIX_ME: неинформативное название функции
	//FIX_ME: неинформативное название параметра
	//void del(int m, FNodePtr& Head)
	void PopFront(int InCount);

	//FIX_ME: функция не является методом класса, не связана с данными
	//FIX_ME: неинформативное название функции
	//void show2(FNodePtr head)
	void PrintAfterExtraction();

	//FIX_ME: нет отчистки памяти
	void Clear();

	//FIX_ME: нет проверки на корректность ввода целых чисел
	int SafeInput();

};