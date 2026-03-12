#include "Header.h"

//FIX_ME: отсутствует проверка на корректность ввода челых чисел
int SafeInput()
{
    int Value;
    bool ValidInput = false;

    do
    {
        std::cin >> Value;

        if (std::cin.fail())
        {
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl;
            std::cout << "Повторите ввод: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ValidInput = false;
        }
        else
        {
            ValidInput = true;
        }

    } while (!ValidInput);

    return Value;
}

//FIX_ME: неинформативное название функции
//FIX_ME: неинформативное название параметров
//void Input(Container& N, int n)
template <typename Container>
void FillContainer(Container& OutContainer, int InSize)//Заполнение контейнеров
{
    using namespace std;
    //FIX_ME: неинформативное название переменных
    //int m, x
    int Choice, Value;
    cout << "Выберете способ заполнения контейнера: " << endl;
    cout << "1)Ввод с клавиатуры." << endl;
    cout << "2)Ввод с помощью рандомайзера." << endl;
    cout << "3)Ввод данных из текстового файла." << endl;

    //FIX_ME: отсутствует проверка на корректность ввода челых чисел
    //cin >> Choice;
    Choice = SafeInput();
    while (Choice < 1 || Choice > 3)
    {
        cout << "Ошибка! Выберите 1, 2 или 3: ";
        Choice = SafeInput();
    }

    if (InSize < 5)
    {
        cout << "Ошибка. Недопустимый размер." << endl;
        return;
    }

    switch (Choice)
    {
    case 1:
    {
        //FIX_ME: постфиксный инкремент
        //i++
        for (int i = 0; i < InSize; ++i)
        {
            cout << "Введите " << i + 1 << " элемент: ";

            //FIX_ME: отсутствует проверка на корректность ввода челых чисел
            //cin >> Value;
            Value = SafeInput();
            OutContainer.insert(OutContainer.end(), Value);
        }
        break;
    }
    case 2:
    {
        srand(time(0));
        //FIX_ME: нет фигурных скобок у цикла for
        //FIX_ME: постфиксный инкремент
        //i++
        for (int i = 0;i < InSize; ++i)
        {
            OutContainer.insert(OutContainer.end(), rand() % 101 - 50);
        }
        break;
    }
    case 3:
    {
        //FIX_ME: неинформативное название переменной
        //ifstream file("a.txt", ios::in)
        ifstream File("a.txt", ios::in); // a.txt {9 3 -44-82 75 2 5 9 -43 74 927 94 -27 3 57 1 0 74 473 84}
        // FIX_ME: использовать is_open()
        //if (file)
        if (!File.is_open())
        {
            cout << "Ошибка. Файл не был открыт.";
            return;
        }
        //FIX_ME: постфиксный инкремент
        //i++
        for (int i = 0; i < InSize; ++i)
        {
            File >> Value;
            // FIX_ME: добавить проверку на успешность чтения
            if (File.fail())
            {
                cout << "Ошибка чтения из файла." << endl;
                break;
            }
            OutContainer.insert(OutContainer.end(), Value);
        }
        File.close();
        break;
    }
    default:
    {
        cout << "Ошибка ввода." << endl;
        break;
    }
    }
}

//FIX_ME: непонятное название функции
//FIX_ME: неинформативное название параметра
//void Print(const Container& N)
//FIX_ME: добавить возможность вывода в обратном порядке
template <typename Container>
void PrintContainer(const Container& InContainer, bool bReverse = false)//Вывод содержимого контейнеров
{

    if (!bReverse)
    {
        //FIX_ME: нет фигурных скобок у цикла for
        //FIX_ME: постфиксный инкремент
        //it++
        for (auto it = InContainer.begin(); it != InContainer.end(); ++it)
        {
            cout << *it << " ";
        }
    }
    else
    {
        for (auto it = InContainer.rbegin(); it != InContainer.rend(); ++it)
        {
            cout << *it << " ";
        }
    }
    cout << endl;
}

//Вставка перед 5 с конца элемента списка последних 5 элементов дека в обратном порядке
//FIX_ME: используется два цикла, хотя в условии требуется один вызов insert
//FIX_ME: непонятное название функции
//FIX_ME: неинформативное название параметров
//void Insert(deque<int>& D, list<int>& L)
void InsertLastFiveReversed(std::deque<int>& InDeque, std::list<int>& InList)
{
    using namespace std;
    //FIX_ME: добавить проверки на размер контейнеров
    if (InDeque.size() < 5 || InList.size() < 5)
    {
        cout << "Ошибка: контейнеры должны содержать не менее 5 элементов." << endl;
        return;
    }

    //FIX_ME: неинформативное название переменной
    // std::list<int>::iterator it = InList.end();
    std::list<int>::iterator InsertPosition = InList.end();

    //FIX_ME: нет фигурных скобок у цикла for
    //FIX_ME: постфиксный инкремент
    //i++
    for (int i = 0; i < 5; ++i)
    {
        --InsertPosition;
    }

    // FIX_ME: должен быть один вызов insert с обратными итераторами
   /* for (int i = 4; i >= 0; ++i)
    {
        it = L.insert(it, D[D.size() - 1 - i]);
    }*/
    InList.insert(InsertPosition, InDeque.rbegin(), InDeque.rbegin() + 5);
}
