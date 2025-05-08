#pragma once
#include<iostream>

#include "Node.h"

using namespace std;


template<class T, size_t maxSize>
class Stack
{
	Node<T>* first = nullptr;
	size_t   size = 0;

public:
	Stack();
	
	~Stack();
	
	Stack(const Stack& obj);
	
	Stack& operator=(const Stack& obj);

	void push(T value);

	void pop();

	T& peek();

	void clear();

	bool isEmpty() const;

	void print() const;

	size_t length() const;

	bool Skobochki(const String& txt) const;   ///
};

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack()
{
}

template<class T, size_t maxSize>
Stack<T, maxSize>::~Stack()
{
	this->clear();
}

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack(const Stack& obj)
{
	Node<T>* temp1 = obj.first;
	first = new Node<T>(temp1->value);
	Node<T>* temp2 = first;

	while (temp1->next)
	{
		temp1 = temp1->next;
		temp2->next = new Node<T>(temp1->value);
		temp2 = temp2->next;
	}
	size = obj.size;
}

template<class T, size_t maxSize>
Stack<T, maxSize>& Stack<T, maxSize>::operator=(const Stack& obj)
{
	// TODO: �������� ����� �������� return
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::push(T value)
{
	if (size < maxSize)
	{
		if (size == 0)
		{
			first = new Node<T>(value);
		}
		else
		{
			Node<T>* newNode = new Node<T>(value);
			newNode->next = first;
			first = newNode;
		}
		size++;
	}
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T, size_t maxSize>
T& Stack<T, maxSize>::peek()
{
	return first->value;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::isEmpty() const
{
	return size == 0;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T, size_t maxSize>
size_t Stack<T, maxSize>::length() const
{
	return size;
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::Skobochki(const String& txt) const
{
	Stack<char, maxSize> stack; 
	const char* str = txt.get(); 
	int size = txt.length();    


	for (int i = 0; i < size; i++) 
	{
		char ch = str[i];


		if (ch == '(' || ch == '{' || ch == '[') 
		{
			stack.push(ch);
		}

//////////////////////////////////////////////////
		else if (ch == ')' || ch == '}' || ch == ']') 
		{
			if (stack.isEmpty()) 
			{
				for (int j = 0; j <= i; j++) 
				{
					cout << str[j];
				}
				cout << endl;
				return false; 
			}

			char top = stack.peek();
			if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) 
			{
				for (int j = 0; j <= i; j++) 
				{
					cout << str[j];
				}
				cout << endl;
				return false; 
			}
			stack.pop(); 
		}
	}

	return stack.isEmpty();
}
