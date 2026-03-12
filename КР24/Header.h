#pragma once
#include <iostream>
//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

//FIX_ME: неправильное название простого класса
//class Node
class FNode
{
public:
    //FIX_ME: неинформативное название поля класса
    //int y;
    int Value;
    FNode* Next;
    FNode* Prev;

    //FIX_ME: неинформативное название параметра конструктора
    //FNode(int x) : Value(x)
    //FIX_ME: использование NULL
    FNode(int InValue);
};

//FIX_ME: неправильное название простого класса
//LinkedList
//FIX_ME: поля должны быть приватными
class FCircularDoublyLinkedList
{
private:
    FNode* Head;
    FNode* Tail;

public:

    //FIX_ME: использование NULL
    FCircularDoublyLinkedList();

    //FIX_ME: отстутсвует деструктор
    ~FCircularDoublyLinkedList();

    //FIX_ME: функция должна быть методом класса, а не глобальной
   //FIX_ME: неинформативное название функции
   //FIX_ME: неинформативное название параметра функции
   //void AddLast(FCircularDoublyLinkedList& s, int x)
    void PushBack(int Value);

    //FIX_ME: функция должна быть методом класса, а не глобальной
   //FIX_ME: неинформативное название функции
   //void F(FCircularDoublyLinkedList& s)
    void RemoveMatchingNeighbors();

    //FIX_ME: функция должна быть методом класса, а не глобальной
    //FIX_ME: неинформативное название функции
    // void Show(FCircularDoublyLinkedList& s)
    void PrintAll();

    //FIX_ME: функция должна быть методом класса, а не глобальной
    void Clear();

    //FIX_ME: нет вывода указателя на последний элемент
    FNode* GetTail() const;

    //FIX_ME: нет проверки на корректность ввода целых чисел
    int SafeInput();

};