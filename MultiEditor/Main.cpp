#include<iostream>
#include<Windows.h>
#include"Editor.h"

using namespace std;


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	unique_ptr<IFile> file;

	//unique_ptr<MultiEditorFactory> meditor; - Почему так нельзя?

	MultiEditorFactory* meditor;

	
	cout << "1. Текстовый редактор \n2. Графический редактор \n0. Выход\n";


	while (true)
	{
		
		int i;
		cin >> i;

		switch (i)
		{	
		case 1:
		{
			TextFactory tf;

			meditor = &tf;

			file = meditor->runEditor();

			file->printFile();

			file->SaveFile("Дано новое имя для текстового файла при сохранении\n");

			file->printFile();

			cout << endl;
			break;
		}
		case 2:
		{
			PictureFactory gf;

			meditor = &gf;

			file = meditor->runEditor();

			file->SetFileName("Graphic File");

			file->SaveFile();

			file->printFile();

			gf.ShowPalette();

			cout << endl;
			break;
		}

		case 0:
		{
			cout << "Выход..." << endl; 
			exit(0);
		}

		default:
			break;
		}
	}
	

	cout << endl;
	system("pause");
}