#pragma once
//FIX_ME: излишнее количество пробелов
#include <iostream>
//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

//FIX_ME: неправильное название класса, должен иметь префикс F
//class stack
//FIX_ME: нерпавильное положение фигурных скобок
class FStack
{
private:
    //FIX_ME: неправильное название структуры, должен иметь префикс F
    //struct Node 
    struct FNode
    {
        //FIX_ME: неинформативное название поля стурктуры
        //int d
        int Data;

        //FIX_ME: неправильное название поля стурктуры
        // FNode* next
        FNode* Next;

        //FIX_ME: неправильное название параметра
        //FNode(int val) :Data(val)
        FNode(int Value);
    };
    //FIX_ME: неинформативное название полей класса
    //FNode* p1;
    //int cnt;
    FNode* Top; //вершина

    //FIX_ME: прописано неиспользуемое поле
    /*int Count;*/

public:
    //FIX_ME: прописано неиспользуемое поле
   //FStack() : Top(nullptr), Count(0) {}
    FStack();

    //FIX_ME: добавлен деструктор
    ~FStack();

    //FIX_ME: неправильное название функции
    //FIX_ME: неинформативное название параметра 
    //void add(int x)
    void Push(int InValue);

    //FIX_ME: неправильное название функции
    //void topdel()
    //извлечение 1 элемента и его удаление
    void PopAndPrintTop();

    //FIX_ME: неправильное название функции
   //void show()
    void PrintAll();

    //FIX_ME: нет проверки на корректность ввода целых чисел
    int SafeInput();

};
