#include "Header.h"

//FIX_ME: отсутствует конструктор для инициализации полей
FNode::FNode(int InValue) : Value(InValue), Next(nullptr) {}

//FIX_ME: отсутствует конструктор для инициализации полей
FLinkedList::FLinkedList() : Head(nullptr), Tail(nullptr) {}

//FIX_ME: отсутствует деструктор, утечка памяти
FLinkedList::~FLinkedList()
{
	while (Head != nullptr)
	{
		FNode* Temp = Head;
		Head = Head->Next;
		delete Temp;
	}
	Tail = nullptr;
}

//FIX_ME: неинформативное название функции
//FIX_ME: функция глобальная
//FIX_ME: неправильное название параметра
//void add(int data, PNode& Head, PNode& LastNode)
void FLinkedList::PushBack(int Value)
{
	//FIX_ME: неициализированная переменная
	//FNode* Temp
	FNode* Temp = new FNode(Value);

	if (Head == nullptr)
	{
		//FIX_ME: излишнее присваивание
		//Head = new FNode;
		Head = Temp;

		//FIX_ME: использование неправильной переменной
		//LastNode = Head;
		Tail = Head;
		//Head->Next = nullptr;
	}
	else
	{
		//FIX_ME: излишнее присваивание
		//Temp = new FNode;

		//FIX_ME: использование неправильной переменной
		//LastNode->Next = Temp;
		Tail->Next = Temp;
		Tail = Temp;
		//LastNode->Next = nullptr;
	}
	//FIX_ME: излишнее присваивание
	//LastNode->Value = Value;
}

//FIX_ME: неинформативное название функции
//FIX_ME: функция глобальная
//void show(PNode& Head)
//FIX_ME: метод должен быть const, так как не изменяет объект
void FLinkedList::PrintAll() const
{
	//FIX_ME: отсутствует проверка на пустой список
	if (Head == nullptr)
	{
		std::cout << "Список пуст" << std::endl;
		return;
	}

	//FIX_ME: неправильное название переменной
	//FNode* Mynode = Head;
	FNode* MyNode = Head;
	std::cout << "Все числа из списка: ";

	while (MyNode != nullptr)
	{
		std::cout << MyNode->Value << " ";
		MyNode = MyNode->Next;
	}
	std::cout << std::endl;
}

//FIX_ME: неинформативное название функции
//FIX_ME: функция глобальная
//FIX_ME: неправильное название параметра
//void addafter(int data, PNode& Head)
void FLinkedList::InsertAfterSecond(int Value)
{
	//FIX_ME: отсутствует проверка на пустой список
	if (Head == nullptr)
	{
		std::cout << "Список пуст. Невозможно вставить элемент" << std::endl;
		return;
	}
	FNode* Temp = Head;
	FNode* MyNode;

	//FIX_ME: неправильное название переменной
	//int count = 1;
	int Position = 1;

	while (Temp != nullptr)
	{
		//FIX_ME: неправильное условие для проверки четности
		//FIX_ME: счетчик увеличивается в самом начале
		/*Position++;
		if (Position == 4)
		{
			MyNode = new FNode;
			MyNode->Value = Value;
			MyNode->Next = Temp->Next;
			Temp->Next = MyNode;
			Position = 0;
		}*/
		if (Position % 2 == 0)
		{
			//FIX_ME: неправильное создание узла
			/*MyNode = new FNode;
			MyNode->Value = Value;*/
			MyNode = new FNode(Value);
			MyNode->Next = Temp->Next;
			Temp->Next = MyNode;

			//FIX_ME: необходимо обновить Tail, если вставили после последнего элемента
			if (MyNode->Next == nullptr)
			{
				Tail = MyNode;
			}

			// FIX_ME: пропускаем вставленный элемент, чтобы не вставлять после него
			Temp = MyNode;
		}
		Temp = Temp->Next;

		//FIX_ME: постфиксный инкремент
		//Position++;
		++Position;
	}
}

//FIX_ME: неинформативное название функции
//FIX_ME: функция глобальная
//void showafter(PNode& Head)
//FIX_ME: метод должен быть const, так как не изменяет объект
void FLinkedList::PrintModified() const
{
	//FIX_ME: отсутствует проверка на пустой список
	if (Head == nullptr)
	{
		std::cout << "Список пуст." << std::endl;
		return;
	}
	//FIX_ME: неправильное название переменной
	//FNode* Mynode = Head;
	FNode* MyNode = Head;
	std::cout << std::endl;
	std::cout << "Все числа из измененного списка: ";
	while (MyNode != nullptr)
	{
		std::cout << MyNode->Value << " ";
		MyNode = MyNode->Next;

	}
	std::cout << std::endl;
}

//FIX_ME: нет проверки на корректность ввода целого числа
int FLinkedList::SafeInput()
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
			bValidInput = false;
		}
		else
		{
			bValidInput = true;
		}

	} while (!bValidInput);

	return Value;
}

//FIX_ME: слишком сложная функция для адреса элемента
//PNode showlast(PNode& Head)
//{
//	PNode Mynode2 = Head;
//	while (Mynode2 != nullptr && Mynode2->Next != nullptr)
//	{
//		Mynode2 = Mynode2->Next;
//	}
//	return Mynode2;
//}
FNode* FLinkedList::GetTail() const
{
	return Tail;
}

//FIX_ME: прописана лишняя функция для поиска элемента, не требующаяся по условию
//PNode Find(PNode Head, int data)
//{
//	PNode q = Head;
//	while (q && q->Value != data)
//		q = q->Next;
//	return q;
//}

//FIX_ME: прописана лишняя функция для удаления элемента, не требующаяся по условию
//void DeleteNode(PNode& Head, PNode OldNode)
//{
//	PNode q = Head;
//	if (Head == OldNode)
//		Head = OldNode->Next;  // удаляем первый элемент 
//	else
//	{
//		while (q->Next != OldNode) // ищем элемент 
//			q = q->Next;
//		q->Next = OldNode->Next;
//	}
//	delete OldNode; // освобождаем память 
//}
