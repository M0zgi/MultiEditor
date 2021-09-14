#pragma once

#include<iostream>

using namespace std;

class IFile {

public:
	
	IFile() { fname = "NewFile"; }
	IFile(string name) : fname(name) {}
	virtual void SetFileName(string name) = 0;
	virtual void SaveFile() = 0;
	virtual void SaveFile(string name) = 0;
	virtual void printFile() = 0;
	virtual ~IFile() {}

protected:
	string fname;
};

class textFile: public IFile
{
public:
	textFile() : IFile() { cout << "Создан текстовый файл: " << fname << "\n"; }
	textFile(string name) : IFile(name) { cout << "Создан текстовый файл: " << fname << "\n"; }
	~textFile() {};

	void SetFileName(string name) override
	{
		fname = name;
		cout << "Текстовому файлу дано новое имя: " << fname << "\n";;
	}

	void SaveFile() override
	{
		cout << "Сохранен текстовый файл " << fname << "\n";
	}

	void SaveFile(string name) override
	{
		fname = name;
		cout << "Сохранен текстовый файл c новым именем: " << fname << "\n";
	}

	void printFile() override
	{	
		cout << "Печать текстового файла. Имя файла: " << fname << "\n";
	}

private:

};

class graphicFile : public IFile
{
public:
	graphicFile() : IFile() { cout << "Создан графический файл: " << fname << "\n"; }
	graphicFile(string name) : IFile(name) { cout << "Создан графический файл: " << fname << "\n"; };
	~graphicFile() {};

	void SetFileName(string name) override
	{
		fname = name;
		cout << "Графическому файлу дано новое имя: " << fname << "\n";;
	}

	void SaveFile() override
	{
		cout << "Сохранен графический файл: " << fname << "\n";;
	}

	void SaveFile(string name) override
	{
		fname = name;
		cout << "Сохранен графический файл c новым именем: " << fname << "\n";
	}

	void printFile() override
	{
		cout << "Печать графического файла. Имя файла: " << fname << "\n";
	}

private:

};


class MultiEditorFactory
{
public:

	virtual unique_ptr<IFile> runEditor() = 0;

	void Menu();

private:

};

class TextFactory : public MultiEditorFactory
{
public:

	unique_ptr<IFile> runEditor() override
	{		
		cout << "Текстовый редактор запущен\n";
		return make_unique<textFile>();
	}

private:

};

class PictureFactory : public MultiEditorFactory
{
public:

	unique_ptr<IFile> runEditor() override
	{
		cout << "Графический редактор запущен\n"; 
		return make_unique<graphicFile>();
	}

	void ShowPalette()
	{
		cout << "Запущена палитра цветов \n";
	}

private:

};

void MultiEditorFactory::Menu()
{
	unique_ptr<IFile> file;
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
}