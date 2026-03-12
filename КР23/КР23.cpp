/*Дан односвязный линейный список и указатель на голову списка P1. Необходимо
вставить значение M после каждого второго элемента списка, и вывести ссылку на последний
элемент полученного списка P2.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

*/



# include <windows.h>
# include <iostream>
#include "Header.h"
//FIX_ME: запрещено использовать using namespace std глобально 
//using namespace std;


int main()
{
	using namespace std;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//FIX_ME: не используется стуктура списка
	/*PNode H1 = NULL;
	PNode LastNode = NULL;*/
	FLinkedList List;
	cout << "Добро пожаловать!" << endl;
	cout << "Перед нами задача: " << endl;
	cout << "Дан односвязный линейный список" << endl;
	cout << "Необходимо вставить значение M после каждого второго элемента списка," << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Вам необходимо ввести два значения: " << endl;
	cout << "1. n(n>=2) - количество элементов в списке" << endl;
	cout << "2. m - число, которое мы будем вставлять. " << endl;
	cout << "Затем через пробел ввести элементы списка, количество которых будет совпадать с тем, что вы ввели ранее," << endl;
	cout << "После мы выведем полученный результат на экран и ссылку на последний элемент. " << endl;
	cout << "--------------------------------------------------------" << endl;
	
	cout << "Введите число(БОЛЬШЕ 2) - количество элементов в массиве: ";

	//FIX_ME: неинформативные названия переменных
	//FIX_ME: дважды проставлена ;
	//int n, x, m;;
	int ElementCount, Value, InsertValue;

	//FIX_ME: нет проверки на корректность ввода целого числа
	//cin >> ElementCount;
	do
	{
		ElementCount = List.SafeInput();

		if (ElementCount < 2)
		{
			std::cout << "Ошибка! Количество элементов должно быть не меньше 2." << std::endl;
		}
	} while (ElementCount < 2);

	cout << "Введите " << ElementCount << " элементов списка ";

	for (int i = 1; i <= ElementCount; i++)
	{
		//FIX_ME: нет проверки на корректность ввода целого числа
		//cin >> Value;
		Value = List.SafeInput();

		//FIX_ME: использовать метод класса, а не глобальную функцию
		//add(Value, H1, LastNode);
		List.PushBack(Value);
	}
	cout << endl;

	//FIX_ME: вывести исходный список для наглядности
	cout << "Исходный список: " << endl;
	List.PrintAll();

	cout << "Введите значение m для вставки после каждого второго элемента: ";

	//FIX_ME: нет проверки на корректность ввода целого числа
	//cin >> InsertValue;
	InsertValue = List.SafeInput();

	cout << endl;

	//FIX_ME: вызвать метод вставки
	//addafter(InsertValue, H1);
	List.InsertAfterSecond(InsertValue);

	//FIX_ME: вызвать метод вставки
	//showafter(H1);
	List.PrintModified();

	cout << endl;
	// FIX_ME: получить и вывести ссылку на последний элемент
	//PNode last = showlast(H1);
	FNode* Last = List.GetTail();
	cout << "Ссылка на последний элемент: " << Last << " " << Last->Value;

	// FIX_ME: прописано удаление элемента списка, но в задаче такого условия не прописано
	/*int choice;
	cout << endl << "Хотите удалить какой-нибудь элемент?" << endl;
	cout << "Если да, то напишите 1" << endl;
	cout << "Если нет, то напишите 2" << endl;
	cout << "Ваш выбор: ";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
	{
		cout << "Введите число - количество элементов которое вы хотите удалить: ";
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cout << "Введите значение элемента, который вы хотите удалить: ";
			int x;
			cin >> x;
			PNode p = Find(H1, x);
			cout << endl;
			cout << "Удаление...." << endl;
			DeleteNode(H1, p);
		}
		show(H1);
	}break;

	case 2:
	{
		{
			cout << "Спасибо за терпение!!!" << endl;
			cout << "До свидания!!!" << endl;
		}
	}
	default:
	{
		cout << "Введено неверное число"; break;
	}
	}*/
	return 0;
}
