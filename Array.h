#pragma once
#include <iostream>
#include <cassert>

#include "String.h"

using namespace std;

template<class T>
class Array
{
	T* arr;
	int size;

public:

	Array()
	{
		size = 0;
		arr = nullptr;
	}

	explicit Array(int s)
	{
		size = s;
		if (size != 0)
			arr = new T[size];
		else
			arr = nullptr;
	}

	Array(const Array& obj)
	{
		size = obj.size;
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	~Array()
	{
		delete[] arr;
	}

	void FreeExtra();
	void RemoveAll();
	bool IsEmpty();
	T GetAt(int index) const;
	void SetAt(int index, T number);
	void RemoveAt(int index);
	void InsertAt(int index, T number);
	void Add(T number);
	void Append(const Array& other);
	void SetSize(int size, int grow = 1);
	int GetUpperBound() const;


	










	void set() const;

	void set(int min, int max) const
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;
		}
	}

	void print() const
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void add(T value)
	{
		T* temp = new T[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = value;
		delete[] arr;
		size++;
		arr = temp;
	}

	void insert(T value, int index)
	{
		T* temp = new T[size + 1];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		temp[index] = value;
		for (size_t i = index; i < size; i++)
		{
			temp[i + 1] = arr[i];
		}
		delete[] arr;
		size++;
		arr = temp;
	}

	void remove(int index)
	{
		T* temp = new T[size - 1];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		for (size_t i = index; i < size - 1; i++)
		{
			temp[i] = arr[i + 1];
		}
		delete[] arr;
		size--;
		arr = temp;
	}

	int sum() const
	{
		int sum = 0;
		for (size_t i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}
		
	T max() const
	{
		T max = arr[0];
		for (size_t i = 1; i < size; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}

	T min() const
	{
		T min = arr[0];
		for (size_t i = 1; i < size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}

	int count(T value) const
	{
		int count = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == value)
			{
				count++;
			}
		}
		return count;
	}

	double average() const
	{
		return (double)sum() / size;
	}

	int getSize() const
	{
		return size;
	}

	T at(int index)
	{
		assert(index >= 0 && index < size);

		return arr[index];
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < size);

		return arr[index];
	}

	T& operator[](const char* index)
	{
		if (strcmp(index, "one") == 0)
			return arr[1];
	}


	void operator()(int value)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] += value;
		}
	}

	operator int()
	{
		return sum();
	}

	operator String ()
	{
		String s("");
		char buff[10];
		for (size_t i = 0; i < size; i++)
		{
			_itoa_s(arr[i], buff, 10);
			s += buff;
			s += " ";
		}
		return s;
	}
	////////-%-//
	void SetSize(int size, int grow = 1)
	{
		int Capacity = 0;
		if (size > this->size)
		{
			T* newArr = new T[size + grow];
			for (size_t i = 0; i < this->size; i++)
			{
				newArr[i] = arr[i];
				Capacity += 1;
			}
		}
		else
		{
			delete[] arr;
		}
		cout << Capacity << endl;
	}

	int GetUpperBound() const
	{
		return size - 1;
	}
	bool IsEmpty()
	{
		if (arr == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void FreeExtra()
	{
		if (size > 0)
		{
			T* temp = new T[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
	}

	void RemoveAll()
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
	}

	template<class T>
	T GetAt(int index) const
	{
		if (index >= 0 && index < size)
		{
			return arr[index];
		}
		else
		{
			cout << "индекс не найден" << endl;
		}
	}

	void SetAt(int index, T number)
	{
		if (index >= 0 && index < size)
		{
			arr[index] = number;
		}
		else
		{
			cout << "индкс не найден!" << endl;
		}
	}

	void Add(number)
	{
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = number;
		delete[] arr;
		arr = temp;
		size++;
	}



	void InsertAt(int index, T number)
	{
		T* temp = new T[size + 1];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		temp[index] = number;
		for (size_t i = index; i < size; i++)
		{
			temp[i + 1] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size++;
	}

	void RemoveAt(int index)
	{
		T* temp = new T[size - 1];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		for (size_t i = index+1; i < size; i++)
		{
			temp[i-1] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size--;
	}


	void Append(const Array& other)
	{
		int newSize = size + other.size;
		T* temp = new T[newSize];


		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		for (int i = 0; i < other.size; i++)
		{
			temp[size + i] = other.arr[i];
		}
		delete[] arr;
		arr = temp;
		size = newSize;
	}

	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] arr;
			size = other.size;
			arr = new T[size];
			for (int i = 0; i < size; i++)
			{
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	T* GetData() const
	{
		return arr;
	}
};


template<class T>
void Array<T>::set() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = T();
	}
}

template<>
void Array<int>::set() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

template<>
void Array<double>::set() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 9.9999;
	}
	
}
