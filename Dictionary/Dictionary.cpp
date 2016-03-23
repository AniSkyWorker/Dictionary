#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Dictionary.h"

CDictionary::CDictionary(std::string const& fileName)
	:m_fileName(fileName)
	,m_dict(InitDictionary())
{
}

std::map<std::string, std::string> CDictionary::InitDictionary()
{
	std::ifstream in(m_fileName);
	std::string first, second;
	std::map<std::string, std::string> fileDict;

	while (std::getline(in, first) && std::getline(in, second))
	{
		if(!in.fail())
			fileDict.emplace(std::move(first), std::move(second));
	}
	return fileDict;
}

void CDictionary::AddWord(std::string const& word, std::string const& trans)
{
	m_dict.emplace(word, trans);
}

void CDictionary::SaveChanges() const
{
	std::ofstream out(m_fileName);
	for (auto & pair : m_dict)
	{
		out << pair.first << std::endl << pair.second << std::endl;
	}
	out.close();
}

bool CDictionary::IsWordInDict(std::string const& word) const
{
	return m_dict.find(word) != m_dict.end();
}

std::string CDictionary::GetTranslation(std::string const& word) const
{
	return m_dict.at(word);
}

void CDictionary::DeleteWord(std::string const& word)
{
	if (IsWordInDict(word))
	{
		m_dict.erase(word);
	}
}