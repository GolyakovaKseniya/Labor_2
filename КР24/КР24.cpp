/*
Дан циклический двусвязный линейный список и указатель первый
элемент этого списка. Необходимо удалить в списке все элементы, у которых правый и
левый сосед совпадают. Если таких элементов нет, то оставить список без изменений.
Первый и последний элементы считать соседями. В результате вернуть ссылку на
последний элемент полученного списка.

Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен стандартный
набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие
дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include <iostream>
#include "Header.h"
//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    //FIX_ME: непонятное название объекта
    //FCircularDoublyLinkedList spisok;
    FCircularDoublyLinkedList List;

    //FIX_ME: неинформативное название переменных
    //int n, x
    int ElementCount, Value;

    std::cout << "Введите количество чисел, которые необходимо записать в список: ";

    //FIX_ME: нет проверки на корректность ввода целых чисел
    //std::cin >> ElementCount;
    do
    {
        ElementCount = List.SafeInput();
        if (ElementCount <= 0)
        {
            std::cout << "Ошибка." << std::endl;
        }
    } while (ElementCount <= 0);

    //FIX_ME: постфиксный инкремент
    for (int i = 0; i < ElementCount;i++)
    {
        std::cout << "Введите " << i + 1 << " число: ";

        //FIX_ME: нет проверки на корректность ввода целых чисел
        //std::cin >> Value;
        Value = List.SafeInput();

        //FIX_ME: используем метод класса
        //AddLast(List, Value);
        List.PushBack(Value);
    }
    std::cout << "Исходный список: ";

    //FIX_ME: используем метод класса
    //Show(List);
    List.PrintAll();

    //FIX_ME: вызываем метод удаления
    //F(List);
    List.RemoveMatchingNeighbors();

    std::cout << "Изменённый список: ";
    List.PrintAll();

    //FIX_ME: выводим ссылку на последний элемент по условию задачи
    FNode* LastNode = List.GetTail();
    if (LastNode != nullptr)
    {
        std::cout << "\nСсылка на последний элемент: " << LastNode << " " << LastNode->Value << std::endl;
    }

    //FIX_ME: отчистка памяти не нужна, деструктор сделает это автоматически
    //Clear(List);
    return 0;
}