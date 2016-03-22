#pragma once
#include <map>

class Dictionary
{
public:
	Dictionary(std::string const& fileName);

	void WorkWithDict();

	bool IsWordInDict(std::string const& word);
	void AddWord(std::string const& word, std::string const& trans);
	std::string GetTranslation(std::string const& word);
	void DeleteWord(std::string const& word);

	void SaveChanges();
	

private:
	std::map<std::string, std::string> InitDictionary();

private:
	std::string fileName;
	std::map<std::string, std::string> dict;
};

