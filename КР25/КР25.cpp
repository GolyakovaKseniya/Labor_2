/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)

Даны дек D и список L. Каждый исходный контейнер содержит не менее 5
элементов. Вставить перед пятым с конца элементом списка последние 5 элементов дека в
обратном порядке. Использовать один вызов функции-члена insert.

*/

#include "Header.h"
#include <ctime>
#include <deque>
#include <list>
#include <fstream>
#include <iostream>
//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    using namespace std;
    //FIX_ME: неинформативное название переменных
    //int n1, n2;
    int DequeSize, ListSize;

    //FIX_ME: неинформативное название объектов
   /* deque <int> D;
    list <int> L;*/

    deque <int> Deque;
    list <int> List;

    cout << "Введите размерность дека n1 (n1 >= 5): ";

    //FIX_ME: отсутствует проверка на корректность ввода челых чисел
    //cin >> DequeSize;
    //FIX_ME: добавлена проверка на минимальный размер
    do
    {
        DequeSize = SafeInput();
        if (DequeSize < 5)
        {
            cout << "Ошибка: размер дека должен быть не менее 5. Введите еще раз: ";
        }
    } while (DequeSize < 5);

    FillContainer(Deque, DequeSize);

    cout << "Введите размерность списка n2 (n2 >= 5): ";
    //FIX_ME: отсутствует проверка на корректность ввода челых чисел
    //cin >> ListSize;
    //FIX_ME: добавлена проверка на минимальный размер
    do
    {
        ListSize = SafeInput();

        if (ListSize < 5)
        {
            cout << "Ошибка: размер списка должен быть не менее 5. Введите еще раз: ";
        }
    } while (ListSize < 5);

    FillContainer(List, ListSize);

    cout << "Изначальное содержимое контейнеров." << endl;

    cout << "Дек: ";
    PrintContainer(Deque);

    cout << "Список: ";
    PrintContainer(List);

    InsertLastFiveReversed(Deque, List);

    cout << "Изменённое содержание контейнеров." << endl;
    cout << "Дек: ";
    PrintContainer(Deque);

    cout << "Список: ";
    PrintContainer(List);
    return 0;
}