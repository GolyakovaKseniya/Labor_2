#include "Header.h"

//FIX_ME: нет конструктора
FNode::FNode(int InData) : Data(InData), Next(nullptr) {}

//FIX_ME: отсутствует конструктор, инициализация рарознена
FQueue::FQueue() : Head(nullptr), Tail(nullptr), Count(0) {}

//FIX_ME: происходит утечка памяти
FQueue::~FQueue()
{
	Clear();
}

//FIX_ME: функция не является методом класса, не связана с данными
//void add(int data, PNode& Head, PNode& Tail)
//FIX_ME: неинформативное название функции
//void add
//FIX_ME: неправильное название параметра
//int data
void FQueue::Push(int InData)
{
	//FIX_ME: неинициализированная переменная
	//PNode Temp;
	FNode* Temp = new FNode(InData);

	//FIX_ME: необъодимо использовать nullptr
	if (Head == nullptr)
	{
		//FIX_ME: излишнее присваивание
		//Head = new Node;
		Head = Temp;
		Tail = Head;
		/*Head->Next = nullptr;*/

	}
	else
	{
		//FIX_ME: излишнее присваивание
		/*Temp = new FNode;*/
		Tail->Next = Temp;
		Tail = Temp;
		/*Tail->Next = nullptr;*/
	}
	/*Tail->Data = InData;*/

	//FIX_ME: отсутствует счетчик для количества элементов в очереди
	++Count;
}

//FIX_ME: функция не является методом класса, не связана с данными
//void show1(PNode head)
//FIX_ME: неинформативное название функции
//void show1
//FIX_ME: неправильное название параметра
//FNodePtr head
void FQueue::PrintFirst()
{
	//FIX_ME: нет проверки на пустую очередь
	if (Head == nullptr)
	{
		std::cout << "Очередь пуста" << std::endl;
		std::cout << "Начало очереди (head): " << Head << std::endl;
		std::cout << "Конец очереди (tail): " << Tail << std::endl;
	}
	else
	{
		//FIX_ME: неправильное название переменной
		//FIX_ME: неиспользуемая переменная temp
		//FNodePt temp
		FNode* Temp = Head;
		std::cout << std::endl << "Исходный адрес первого элемента: " << Temp << " " << Temp->Data;

		std::cout << std::endl << "Исходная очередь: ";
		while (Temp != nullptr)
		{
			std::cout << Temp->Data << " ";
			Temp = Temp->Next;
		}

		//FIX_ME: неправильное название переменной
		//FNodePtr last
		FNode* Last = Head;
		while (Last->Next != nullptr)
		{
			Last = Last->Next;
		}

		std::cout << std::endl << "Исходный адрес последнего элемента: " << Last << " " << Last->Data << std::endl;
	}
}

//FIX_ME: функция не является методом класса, не связана с данными
//FIX_ME: неинформативное название функции
//FIX_ME: неинформативное название параметра
//void del(int m, FNodePtr& Head)
void FQueue::PopFront(int InCount)
{
	//FIX_ME: нет проверки на корректность числа извлекаемых элементов
	if (InCount <= 0)
	{
		std::cout << "Количество извлекаемых элементов должно быть больше 0" << std::endl;
		return;
	}

	//FIX_ME: нет проверки на пустую очередь
	if (Head == nullptr)
	{
		std::cout << "Очередь пуста. Нет элементов для извлечения." << std::endl;
		return;
	}

	//FIX_ME: нет проверки на возможное количество элементов для извлечения
	int ItemsToExtract;
	if (InCount > Count)
	{
		ItemsToExtract = Count;
	}
	else
	{
		ItemsToExtract = InCount;
	}

	//FIX_ME: постфиксный инкремент
	//i++
	for (int i = 0; i < ItemsToExtract; ++i)
	{
		//FIX_ME: неправильное название переменной
		//FNode* temp;
		FNode* Temp = Head;

		//FIX_ME: ненужный вывод адреса
		//<< Temp->Next << " "
		std::cout << Temp->Data << " ";
		Head = Head->Next;
		delete Temp;
		--Count;

		//FIX_ME: нет проверки на пустоту
		if (Head == nullptr)
		{
			Tail = nullptr;
		}
		//std::cout << std::endl;
	}
	std::cout << std::endl;

	if (InCount > ItemsToExtract)
	{
		std::cout << "Запрошено извлечение " << InCount << " элементов, ";
		std::cout << "но в очереди было только " << ItemsToExtract << ". ";
		std::cout << "Извлечены все элементы." << std::endl;
	}
	std::cout << std::endl;
}

//FIX_ME: функция не является методом класса, не связана с данными
//FIX_ME: неинформативное название функции
//void show2(FNodePtr head)
void FQueue::PrintAfterExtraction()
{
	//FIX_ME: неправильное название переменных
	//FNode* temp = nullptr; FNode* temp2
	FNode* Temp = Head;
	if (Head == nullptr)
	{
		//FIX_ME: неправильный вывод nullptr
		std::cout << "Очередь после удаления элементов оказалась пустой" << std::endl;
		/*int* ptr = nullptr;*/
		std::cout << "Начало очереди: " << Head << std::endl;
		std::cout << "Конец очереди: " << Tail << std::endl;
	}
	else
	{
		std::cout << "Новое начало очереди: " << Temp << " " << Temp->Data << std::endl;
		std::cout << "Оставшиеся элементы очереди: ";
		while (Temp != nullptr)
		{
			//FIX_ME: непонятная отчистка памяти
			/*temp = head;*/
			std::cout << Temp->Data << " ";
			Temp = Temp->Next;
			/*head = head->Next;*/
			//delete temp;
		}
		/*std::cout << std::endl << "Новый конец очереди: " << temp << " " << temp->Data << std::endl;*/
		std::cout << std::endl << "Новый конец очереди: " << Tail << " " << Tail->Data << std::endl;

	}
}

//FIX_ME: нет отчистки памяти
void FQueue::Clear()
{
	while (Head != nullptr)
	{
		FNode* Temp = Head;
		Head = Head->Next;
		delete Temp;
	}
	Tail = nullptr;
}

//FIX_ME: нет проверки на корректность ввода целых чисел
int FQueue::SafeInput()
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
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			ValidInput = false;
		}
		else
		{
			bValidInput = true;
		}

	} while (!bValidInput);

	return Value;

}
