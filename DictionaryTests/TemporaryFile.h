#pragma once
#include <direct.h>
#include <boost/filesystem.hpp>

class CTemporaryFile
{
public:	
	CTemporaryFile(std::string const& fileName);
	~CTemporaryFile();
private:
	boost::filesystem::path m_path;
};

