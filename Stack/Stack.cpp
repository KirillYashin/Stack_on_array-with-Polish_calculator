#include <iostream>
#include <locale.h>
#include <stdio.h>
#include "Stack.h"
#include "Exception.h"
#include "Polish.h"

const int MaxLen = 255;

int  main()
{
	setlocale(LC_ALL, "Russian");
	Polish test_polish;
	char infix[MaxLen], postfix[MaxLen];
	std::cout << ("Введите математическое выражение ");
	gets_s(infix);
	if (test_polish.checker(infix) == 0) {
		std::cout << "Постфиксная форма:" << std::endl;
		test_polish.infix_to_postfix(infix, postfix);
		std::cout << "Результат:" << std::endl;
		std::cout << test_polish.Calculator(postfix) << std::endl;
	}
	else {
		std::cout << "Ошибок: " << test_polish.checker(infix) << std::endl;
	}
	std::cout << "Введите размер стека: ";
	int len;
	std::cin >> len;
	try
	{
		TStack<int> st(len);
		for (int i = 0; i < len; i++)
		{
			st.Push(std::rand() % 100);
		}
		if (st.IsFull())
		{
			std::cout << "Стек длиной " << len << ":" << std::endl;
			st.PrintStack();
		}
		std::cout << std::endl;
		TStack<int> Copy(st);
		std::cout << "Скопируем стек и выведем на экран копию:" << std::endl;
		Copy.PrintStack();
		std::cout << std::endl;
		if (Copy == st) {
			std::cout << "Копия и оригинал равны, что не удивительно" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Создадим стек длиной 1, чтобы убедиться в работе исключений" << std::endl;
		int len1 = 1, mode = 0;
		TStack<int> test(len1);
		TStack<int> copy_test(len1);
		test.Push(std::rand() % 100);
		std::cout << std::endl;
		std::cout << "Введите 1, если хотите проверить оператор неравенста." << std::endl;
		std::cout << "Введите 2, если хотите проверить исключение для Push." << std::endl;
		std::cout << "Введите 3, если хотите проверить исключение для Pop." << std::endl;
		std::cout << "Введите 4, если хотите проверить оператор присваивания." << std::endl;
		std::cin >> mode;
		std::cout << std::endl;
		switch (mode)
		{
		case 1:
			std::cout << "Заберем теперь элемент " << st.Pop() << " из первого стека, чтобы проверить оператор неравенства:" << std::endl;
			if (Copy != st) {
				std::cout << "И теперь оригинал и копия различны" << std::endl;
			}
			break;
		case 2:
			std::cout << "Положим элемент в стек - получим ошибку: " << std::endl;
			test.Push(std::rand() % 100);
			break;
		case 3:
			std::cout << "Возьмем элемент из тестового стека: " << test.Pop() << std::endl;
			std::cout << std::endl;
			std::cout << "Возьмем еще элемент из тестового стека - получим ошибку: " << test.Pop() << std::endl;
			break;
		case 4:
			std::cout << "Создадим копию тестового стека из одного элемента"<< std::endl;
			std::cout << std::endl;
			copy_test = test;
			std::cout << "Тестовый стек:" << std::endl;
			copy_test.PrintStack();
			std::cout << std::endl;
			std::cout << "Скопированный стек:" << std::endl;
			copy_test.PrintStack();
			break;
		default:
			break;
		}
	}
	catch (Exception exc)
	{
		exc.Print();
	}
	return 0;
}
