#include "Header.h"

//FIX_ME: неправильное название параметра
//FNode(int val) :Data(val)
FStack::FNode::FNode(int Value) : Data(Value), Next(nullptr) {}

//FIX_ME: прописано неиспользуемое поле
//FStack() : Top(nullptr), Count(0) {}
FStack::FStack() : Top(nullptr) {}

//FIX_ME: добавлен деструктор
FStack::~FStack()
{
    while (Top != nullptr)
    {
        FNode* Temp = Top;
        Top = Top->Next;
        delete Temp;
    }
}

//FIX_ME: неправильное название функции
//FIX_ME: неинформативное название параметра 
//void add(int x)
void FStack::Push(int InValue)
{
    //FIX_ME: неправильное название переменной
    //FNode* newnode = new FNode(InValue)
    FNode* NewNode = new FNode(InValue);
    NewNode->Next = Top;
    Top = NewNode;
    //FIX_ME: постфиксный инкремент
    //Count++;
    //FIX_ME: прописано неиспользуемое поле
    //++Count;
}

//FIX_ME: неправильное название функции
//void topdel()
//извлечение 1 элемента и его удаление
void FStack::PopAndPrintTop()
{
    //FIX_ME: нет проверки на пустой стек
    if (Top == nullptr)
    {
        std::cout << "Стек пуст. Невозможно извлечь элемент." << std::endl;
        return;
    }
    //FIX_ME: неправильное название переменной
    //FIX_ME: неиспользуемая переменная temp
    //FNode* temp = p1
    FNode* Temp = Top;
    int Value = Temp->Data;
    Top = Top->Next;

    std::cout << "Первый элемент стека:" << std::endl;
    std::cout << Value << std::endl;
    //FIX_ME: бессмысленные присваивания
   /* if (Top->Next == nullptr)
    {
        Top = nullptr;
    }
    else
    {
        Top = Top->Next;
    }*/
    std::cout << "Адрес новой вершины p1 после извлечения 1 элемента: " << Top << std::endl; // Вывод адреса новой вершины
    if (Top != nullptr)
    {
        std::cout << "Значение новой вершины p1: " << Top->Data << std::endl; // Вывод значения новой вершины
    }

    //FIX_ME: неполноценное удаление
    delete Temp;

    //FIX_ME: постфиксный инкремент
    //Count--;
     //FIX_ME: прописано неиспользуемое поле
    //--Count;
}

//FIX_ME: неправильное название функции
//void show()
void FStack::PrintAll()
{
    //FIX_ME: нет проверки на пустой стек
    if (Top == nullptr)
    {
        std::cout << "Стек пуст." << std::endl;
        return;
    }
    //FIX_ME: неправильное название переменной
    //FNode* temp
    //FIX_ME: неудобвный вывод элементов стека
    //std::cout << Temp->Data << std::endl;
    FNode* Temp = Top;
    while (Temp != nullptr)
    {
        std::cout << Temp->Data << " ";
        Temp = Temp->Next;
    }
    std::cout << std::endl;
}

//FIX_ME: нет проверки на корректность ввода целых чисел
int FStack::SafeInput()
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

