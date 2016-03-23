#include "stdafx.h"
#include "Dictionary.h"
#include <windows.h>
#include <iostream>
#include <string>

int main(int argc, char * argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string fileName;
	fileName = (argc != 2) ? "new_dict.txt" : argv[1];

	CDictionary dict(fileName);

	std::cout << "����� ���������� � ��� ������ �����-������� �������" << std::endl
		<< "������� ����� ������� �������� ��� ����������" << std::endl
		<< "������� ... ����� ��������� ������ �� ��������" << std::endl;

	std::string userString;
	bool changes = false;

	while (std::getline(std::cin, userString) && userString != "...")
	{
		if (dict.IsWordInDict(userString))
		{
			std::cout << dict.GetTranslation(userString) << std::endl;
		}
		else
		{
			std::cout << "����������� ����� " << '"' << userString << '"' << '.' <<
				"������� ������� ��� ������ ������ ��� ������." << std::endl;

			std::string trans;
			std::getline(std::cin, trans);

			if (!trans.empty())
			{
				dict.AddWord(userString, trans);

				std::cout << "����� " << '"' << userString << '"' <<
					" ��������� � ������� ��� " <<
					'"' << trans << '"' << '.' << std::endl;

				changes = true;
			}
			else
			{
				std::cout << "����� " << '"' << userString << '"' << " ���������������." << std::endl;
			}
		}
	}


	if (changes)
	{
		std::cout << "� ������� ���� ������� ���������, ���������?" << std::endl
			<< "(������� ������ ������ ��� ������)" << std::endl;

		std::cin >> userString;
		if (!userString.empty())
		{
			dict.SaveChanges();
			std::cout << "��������� ���� ���������." << std::endl;
		}
		else
		{
			std::cout << "��������� �� ���� ���������." << std::endl;
		}
	}

    return 0;
}

