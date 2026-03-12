#pragma once
# include <windows.h>
# include <iostream>
//FIX_ME: запрещено использовать using namespace std глобально 
//using namespace std;

//FIX_ME: неправильное название класса
//class Node
class FNode
{
public:
	//FIX_ME: неинформативное название поля
	//int x;
	int Value;

	//FIX_ME: неправильное название поля
	//FNode* next
	FNode* Next;

	//FIX_ME: отсутствует конструктор для инициализации полей
	FNode(int InValue);
};

//FIX_ME: нет класса списка, все функции глобальные
//FIX_ME: нет инкапсуляции
//typedef FNode* PNode;
class FLinkedList
{
private:
	FNode* Head; //Указатель на начало списка
	FNode* Tail; //Указатель на конец списка
public:

	//FIX_ME: отсутствует конструктор для инициализации полей
	FLinkedList();

	//FIX_ME: отсутствует деструктор, утечка памяти
	~FLinkedList();

	//FIX_ME: неинформативное название функции
	//FIX_ME: функция глобальная
	//FIX_ME: неправильное название параметра
	//void add(int data, PNode& Head, PNode& LastNode)
	void PushBack(int Value);

	//FIX_ME: неинформативное название функции
	//FIX_ME: функция глобальная
	//void show(PNode& Head)
	//FIX_ME: метод должен быть const, так как не изменяет объект
	void PrintAll() const;

	//FIX_ME: неинформативное название функции
	//FIX_ME: функция глобальная
	//FIX_ME: неправильное название параметра
	//void addafter(int data, PNode& Head)
	void InsertAfterSecond(int Value);

	//FIX_ME: неинформативное название функции
	//FIX_ME: функция глобальная
	//void showafter(PNode& Head)
	//FIX_ME: метод должен быть const, так как не изменяет объект
	void PrintModified() const;

	//FIX_ME: нет проверки на корректность ввода целого числа
	int SafeInput();

	//FIX_ME: слишком сложная функция для адреса элемента
	FNode* GetTail() const;
};