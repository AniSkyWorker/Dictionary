#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Dictionary.h"

Dictionary::Dictionary(std::string const& fileName)
	:fileName(fileName)
	,dict(InitDictionary())
{
}

std::map<std::string, std::string> Dictionary::InitDictionary()
{
	std::ifstream in(fileName);
	std::string first, second;
	std::map<std::string, std::string> fileDict;

	while (std::getline(in, first) && std::getline(in, second))
	{
		if(!in.fail())
			fileDict.emplace(std::move(first), std::move(second));
	}
	return fileDict;
}

void Dictionary::WorkWithDict()
{
	std::cout << "Добро пожаловать в ваш личный англо-русский словарь" << std::endl
		<< "Введите слово перевод которого вас интересует" << std::endl
		<< "Введите ... чтобы закончить работу со словарем" << std::endl;

	std::string userString;
	bool changes = false;

	while(std::getline(std::cin, userString) && userString != "...")
	{
		if(dict.find(userString) != dict.end())
		{
			std::cout << dict.at(userString) << std::endl;
		}
		else
		{
			std::cout << "Неизвестное слово " << '"' << userString << '"' << '.' <<
				"Введите перевод или пустую строку для отказа." << std::endl;
			if (AddWord(userString))
				changes = true;
		}
	}

	std::cout << "В словарь были внесены изменения, сохранить?" << std::endl;
	
	if (changes)
	{
		std::cin >> userString;
		if (userString == "да")
		{
			SaveChanges();
			std::cout << "Изменения были сохранены." << std::endl;
		}
		else
		{
			std::cout << "Изменения НЕ были сохранены." << std::endl;
		}
	}
}

bool Dictionary::AddWord(std::string const& word)
{
	std::string trans;
	std::getline(std::cin, trans);
	if (!trans.empty())
	{
		std::cout << "Слово " << '"' << word << '"' << " сохранено в словаре как " << '"' << trans << '"' << '.' << std::endl;
		dict.emplace(std::move(word), std::move(trans));
	}
	else 
	{
		std::cout << "Слово " << '"' << word << '"' << " проигнорировано." << std::endl;
		return false;
	}

	return true;
}

void Dictionary::SaveChanges()
{
	std::ofstream out(fileName);
	for (auto & pair : dict)
	{
		out << pair.first << std::endl << pair.second << std::endl;
	}
	out.close();
}