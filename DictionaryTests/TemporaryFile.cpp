#include "stdafx.h"
#include "TemporaryFolder.h"


CTemporaryFile::CTemporaryFile(std::string const& fileName)
{
	m_path = fileName;
}


CTemporaryFile::~CTemporaryFile()
{
	boost::filesystem::remove(m_path);
}