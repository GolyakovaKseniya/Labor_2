#pragma once
#include <ctime>
#include <deque>
#include <list>
#include <fstream>
#include <iostream>
//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

//FIX_ME: отсутствует проверка на корректность ввода челых чисел
int SafeInput();

//FIX_ME: неинформативное название функции
//FIX_ME: неинформативное название параметров
//void Input(Container& N, int n)
template <typename Container>
void FillContainer(Container& OutContainer, int InSize);//Заполнение контейнеров

//FIX_ME: непонятное название функции
//FIX_ME: неинформативное название параметра
//void Print(const Container& N)
//FIX_ME: добавить возможность вывода в обратном порядке
template <typename Container>
void PrintContainer(const Container& InContainer, bool bReverse = false);//Вывод содержимого контейнеров

//Вставка перед 5 с конца элемента списка последних 5 элементов дека в обратном порядке
//FIX_ME: используется два цикла, хотя в условии требуется один вызов insert
//FIX_ME: непонятное название функции
//FIX_ME: неинформативное название параметров
//void Insert(deque<int>& D, list<int>& L)
void InsertLastFiveReversed(std::deque<int>& InDeque, std::list<int>& InList);



