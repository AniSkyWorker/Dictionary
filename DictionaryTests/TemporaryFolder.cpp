#include "stdafx.h"
#include "TemporaryFolder.h"

using namespace boost::filesystem;

CTemporaryFolder::CTemporaryFolder()
{
	m_path = unique_path();
	create_directory(m_path);
}


CTemporaryFolder::~CTemporaryFolder()
{
	remove(m_path);
}

std::string CTemporaryFolder::GetPath() const
{
	return m_path.string() + "/";
}

void CTemporaryFolder::CopyFileToFolder(std::string fileName)
{
	copy_file(fileName, m_path.string() + "/" + fileName, copy_option::none);
}