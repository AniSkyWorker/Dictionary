#pragma once
#include <map>

class CDictionary
{
public:
	CDictionary(std::string const& fileName);

	void AddWord(std::string const& word, std::string const& trans);
	std::string GetTranslation(std::string const& word) const;
	void DeleteWord(std::string const& word);

	void SaveChanges() const;
	

private:
	std::map<std::string, std::string> InitDictionary();

private:
	std::string m_fileName;
	std::map<std::string, std::string> m_dict;
};

