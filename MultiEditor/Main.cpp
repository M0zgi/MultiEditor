#include<iostream>
#include<Windows.h>
#include"Editor.h"

using namespace std;


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unique_ptr<MultiEditorFactory> m;

	m->Menu();
	

	cout << endl;
	system("pause");
}