#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include<algorithm>

#include "Sring.h"
#include "Stack.h"

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::boolalpha);
	String txt("�� �������? ��� �� ������ ���. {��� ��������.} ����� ����� ����� ����� ��������, "
		"��� ������� � ������, � ���� � �� � ���, ��� �������, [����� ��� ����.] "
		"� ���� ��� ������� �������� ����� �������� � ����� ����� ���. (�� ��� ����. "
		"���������?] [��� ����!!!];");

	Stack<char, 500> stack;
	if (stack.Skobochki(txt)) 
	{
		cout << "��� ������� �� ��������" << endl;
	}
	else 
	{
		cout << "������ ����������� �����������" << endl;
	}
	
	

}