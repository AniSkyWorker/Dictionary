#pragma once
#include <direct.h>
#include <boost/filesystem.hpp>

class CTemporaryFolder
{
public:	
	CTemporaryFolder();
	~CTemporaryFolder();

	std::string GetPath() const;
	void CopyFileToFolder(std::string fileName);

private:
	boost::filesystem::path m_path;
};

