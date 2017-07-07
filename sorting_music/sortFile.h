#pragma once
using namespace std;

#include <iostream>
#include <Windows.h>
#include <string>
#include <direct.h>
#include <fstream>
#include <algorithm>
#include <tchar.h> 
#include <functional> 
#include <cctype>
#include <locale>
#include "stringHandling.h"

void sort_file(string sort_by, WIN32_FIND_DATA FindFileData) {
	rtrim(sort_by);
	_mkdir(sort_by.c_str()); //create folder named sort_by
	cout << GetLastErrorAsString() << endl;
	cout << sort_by.c_str() << endl;
	wstring loc = conv("C:\\Users\\Hee\\Documents\\temp\\");
	wstring x = loc + FindFileData.cFileName;
	wstring y = loc + conv(sort_by.c_str()) + L"\\" + FindFileData.cFileName;


	if (MoveFile(x.c_str(), y.c_str()) == 0) {
		cout << GetLastErrorAsString() << endl;
		cout << "error" << endl;
	}

}