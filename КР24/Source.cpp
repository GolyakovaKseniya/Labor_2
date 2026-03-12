#include "Header.h"

//FIX_ME: неинформативное название параметра конструктора
//FNode(int x) : Value(x)
//FIX_ME: использование NULL
FNode::FNode(int InValue) : Value(InValue), Next(nullptr), Prev(nullptr) {}

//FIX_ME: использование NULL
FCircularDoublyLinkedList::FCircularDoublyLinkedList() : Head(nullptr), Tail(nullptr) {}

//FIX_ME: отстутсвует деструктор
FCircularDoublyLinkedList::~FCircularDoublyLinkedList()
{
    Clear();
}

//FIX_ME: функция должна быть методом класса, а не глобальной
//FIX_ME: неинформативное название функции
//FIX_ME: неинформативное название параметра функции
//void AddLast(FCircularDoublyLinkedList& s, int x)
void FCircularDoublyLinkedList::PushBack(int Value)
{
    FNode* NewNode = new FNode(Value);

    //FIX_ME: излишнее 
    /*NewNode->Next = NULL;
    NewNode->Prev = s.Tail;*/

    //FIX_ME: отсутсвуют фигурные скобки у цикла if-else
    //Список пуст
    if (Tail == nullptr)
    {
        Head = NewNode;
        //FIX_ME: нет образования цикличного списка
        Tail = NewNode;
        NewNode->Next = NewNode; //Замыкаем на себя
        NewNode->Prev = NewNode;
    }
    else
    {
        //FIX_ME: нет образования цикличного списка
        NewNode->Prev = Tail;
        NewNode->Next = Head;
        Tail->Next = NewNode;
        /*Tail = NewNode;
        Tail->Next = Head;*/
        Head->Prev = NewNode;
        Tail = NewNode;
    }
}

//FIX_ME: функция должна быть методом класса, а не глобальной
//FIX_ME: неинформативное название функции
//void F(FCircularDoublyLinkedList& s)
void FCircularDoublyLinkedList::RemoveMatchingNeighbors()
{
    //FIX_ME: использование NULL
    //if (s.Head == NULL)
    //FIX_ME: отсутствуют фигурные скобки у цикла if
    if (Head == nullptr)
    {
        return;
    }

    //FIX_ME: сложная логика с ошибками
    FNode* MyNode = Head;
    bool bListModified = false;
    //FNode* Next1 = nullptr;

    //FIX_ME: неправильное положение фигурной скобки
    do
    {
        //FIX_ME: сохраняем следующий узел заранее, так как MyNode может быть удалё
        FNode* NextNode = MyNode->Next;

        if (MyNode->Prev->Value == MyNode->Next->Value)
        {
            //FIX_ME: удаляем текущий элемент
            bListModified = true;

            if (MyNode == Head && MyNode == Tail)
            {
                //FIX_ME: использование NULL
                /*Head = NULL;
                Tail = NULL;*/
                delete MyNode;
                Head = nullptr;
                Tail = nullptr;
                break;
            }
            else if (MyNode == Head)
            {
                Head = MyNode->Next;
            }
            //FIX_ME: отсутствует удаление последнего элемента
            else if (MyNode == Tail)
            {
                Tail = MyNode->Prev;
            }

            MyNode->Prev->Next = MyNode->Next;
            MyNode->Next->Prev = MyNode->Prev;

            //FIX_ME: неправильная логика удаления
            /*delete MyNode;
            MyNode = Next1->Prev;*/
            FNode* ToDelete = MyNode;
            MyNode = NextNode;

            delete ToDelete;
        }
        else
        {
            MyNode = NextNode;
        }
        //FIX_ME: неполное условие
        // while (MyNode != Head)
    } while (MyNode != Head && Head != nullptr);

    //FIX_ME: отсутствует проверка на отсутствие подходящих элементов
    if (!bListModified)
    {
        std::cout << "Элементы с совпадающими соседями не найдены. Список не изменился." << std::endl;
    }
}

//FIX_ME: функция должна быть методом класса, а не глобальной
//FIX_ME: неинформативное название функции
// void Show(FCircularDoublyLinkedList& s)
void FCircularDoublyLinkedList::PrintAll()
{
    //FIX_ME: использование NULL
    if (Head == nullptr)
    {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    FNode* MyNode = Head;

    do
    {
        std::cout << MyNode->Value << " ";
        MyNode = MyNode->Next;
    } while (MyNode != Head);
    std::cout << std::endl;
}

//FIX_ME: функция должна быть методом класса, а не глобальной
void FCircularDoublyLinkedList::Clear()
{
    //FIX_ME: отсутствуют фигурные скобки у цикла if
    //FIX_ME: использование NULL
    if (Head == nullptr)
    {
        return;
    }

    FNode* MyNode = Head;

    do
    {
        FNode* Temp = MyNode;
        MyNode = MyNode->Next;
        delete Temp;
    } while (MyNode != Head);
    Head = nullptr;
    Tail = nullptr;
}

//FIX_ME: нет вывода указателя на последний элемент
FNode* FCircularDoublyLinkedList::GetTail() const
{
    return Tail;
}

//FIX_ME: нет проверки на корректность ввода целых чисел
int FCircularDoublyLinkedList::SafeInput()
{
    int Value;
    bool bValidInput = false;

    do
    {
        std::cin >> Value;

        if (std::cin.fail())
        {
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl;
            std::cout << "Повторите ввод: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            bValidInput = false;
        }
        else
        {
            bValidInput = true;
        }

    } while (!bValidInput);

    return Value;
}