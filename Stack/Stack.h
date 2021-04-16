#pragma once
#include <iostream>
#include "Exception.h"

template <class T>
class TStack
{
protected:
	int length;// Длина стека
	T* elem;// Элементы стека
	int top;// Вершина стека

public:
	TStack(int len = 0);
	TStack(TStack& st);
	virtual ~TStack();
	void Push(T el); // Положить элемент
	T Top();
	T Pop();// Взять элемент
	int GetLength();// Получить длину стека
	bool IsFull();// Проверка на полноту
	bool IsEmpty();// Проверка на пустоту
	void PrintStack(); //Вывод стека на экран
	TStack& operator=(const TStack<T>& st); //Присваивание стека
	int operator==(const TStack<T>& st) const; //Проверка на равенство
	int operator!=(const TStack<T>& st) const; // Проверка на неравенство
};

template <class T>
TStack<T>::TStack(int len)
{
	if (len < 0)
		throw Exception("I think length should be more than 0");
	if (len == 0) {
		length = 0;
		elem = 0;
		top = 0;
	}
	if (len > 0) {
		elem = new T[len];
		length = len;
		top = 0;
	}
}

template <class T>
TStack<T>::TStack(TStack<T>& st)
{
	length = st.length;
	top = st.top;
	if (length == 0)
		elem = 0;
	else {
		elem = new T[length];
		for (int i = 0; i < length; i++)
			elem[i] = st.elem[i];
	}
}

template <class T>
TStack<T> :: ~TStack()
{
	if (elem != 0)
		delete[] elem;
	top = 0;
	length = 0;
}

template <class T>
void TStack<T>::Push(T el)
{
	if (IsFull())
		throw Exception("Stack is already full");
	elem[top++] = el;
}

template<class T>
T TStack<T>::Top()
{
	if (IsEmpty())
		throw Exception("Stack is already empty");
	return elem[top - 1];
}

template <class T>
T TStack<T>::Pop()
{
	if (IsEmpty())
		throw Exception("Stack is already empty");
	return elem[--top];
}

template <class T>
int TStack<T>::GetLength()
{
	return length;
}

template <class T>
bool TStack<T>::IsEmpty()
{
	return (top == 0);
}

template <class T>
bool TStack<T>::IsFull()
{
	return (top >= length);
}

template <class T>
void TStack<T>::PrintStack()
{
	for (int i = top - 1; i >= 0; i--)
		std::cout << " " << elem[i] << std::endl;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& st)
{
	if (this != &st)
	{
		delete[] elem;
		top = st.top;
		length = st.length;
		elem = new T[length];
		for (int i = 0; i < length; i++)
			elem[i] = st.elem[i];
	}
	return *this;
}

template <class T>
int TStack<T>::operator==(const TStack<T>& st) const
{
	if (top != st.top)
		return 0;
	if (length != st.length)
		return 0;
	for (int i = 0; i < top; i++)
		if (elem[i] != st.elem[i])
			return 0;
	return 1;
}

template <class T>
int TStack<T>::operator!=(const TStack<T>& st) const
{
	return !(*this == st);
}
