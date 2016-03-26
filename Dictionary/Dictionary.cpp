#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
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
	std::vector<std::string> splitVec;
	boost::split(splitVec, m_fileName, boost::is_any_of("/"), boost::token_compress_on);

	std::ofstream out(splitVec.back());
	for (auto & pair : m_dict)
	{
		out << pair.first << std::endl << pair.second << std::endl;
	}
	out.close();
}

std::string CDictionary::GetTranslation(std::string const& word) const
{
	auto wordIt = m_dict.find(word);
	if (wordIt == m_dict.end())
	{
		return "";
	}

	return wordIt->second;
}

void CDictionary::DeleteWord(std::string const& word)
{
	m_dict.erase(word);
}