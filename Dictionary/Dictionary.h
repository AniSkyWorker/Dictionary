#pragma once
#include <map>

class Dictionary
{
public:
	Dictionary(std::string const& fileName);
	void WorkWithDict();

private:
	std::map<std::string, std::string> InitDictionary();
	bool AddWord(std::string const& word);
	void SaveChanges();

private:
	std::string fileName;
	std::map<std::string, std::string> dict;
};

