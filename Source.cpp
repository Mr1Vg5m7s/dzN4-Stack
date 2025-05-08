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
	String txt("Ты слышишь? Это не просто дом. {Это приговор.} Здесь стены дышат моими страхами, "
		"пол скрипит её именем, а тень — я… я тот, кто остался, [когда все ушли.] "
		"И если мне суждено остаться здесь навсегда — пусть будет так. (Но она уйдёт. "
		"Понимаешь?] [Она уйдёт!!!];");

	Stack<char, 500> stack;
	if (stack.Skobochki(txt)) 
	{
		cout << "Все нормулёк со скобками" << endl;
	}
	else 
	{
		cout << "Скобки расположены неправильно" << endl;
	}
	
	

}