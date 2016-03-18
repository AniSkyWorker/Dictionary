// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"
#include <windows.h>



int main(int argc, char * argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (argc != 2)
	{
		argv[1] = "new_dict.txt";
	}
	Dictionary dict(argv[1]);
	dict.WorkWithDict();

    return 0;
}

