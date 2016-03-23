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

	std::cout << "Добро пожаловать в ваш личный англо-русский словарь" << std::endl
		<< "Введите слово перевод которого вас интересует" << std::endl
		<< "Введите ... чтобы закончить работу со словарем" << std::endl;

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
			std::cout << "Неизвестное слово " << '"' << userString << '"' << '.' <<
				"Введите перевод или пустую строку для отказа." << std::endl;

			std::string trans;
			std::getline(std::cin, trans);

			if (!trans.empty())
			{
				dict.AddWord(userString, trans);

				std::cout << "Слово " << '"' << userString << '"' <<
					" сохранено в словаре как " <<
					'"' << trans << '"' << '.' << std::endl;

				changes = true;
			}
			else
			{
				std::cout << "Слово " << '"' << userString << '"' << " проигнорировано." << std::endl;
			}
		}
	}


	if (changes)
	{
		std::cout << "В словарь были внесены изменения, сохранить?" << std::endl
			<< "(Введите пустую строку для отказа)" << std::endl;

		std::cin >> userString;
		if (!userString.empty())
		{
			dict.SaveChanges();
			std::cout << "Изменения были сохранены." << std::endl;
		}
		else
		{
			std::cout << "Изменения НЕ были сохранены." << std::endl;
		}
	}

    return 0;
}

