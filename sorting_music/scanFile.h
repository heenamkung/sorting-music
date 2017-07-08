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
#include "sortFile.h"
#include "mp3Tag.h"


bool scanFirstFile(HANDLE& hFind, WIN32_FIND_DATAW FindFileData, wstring all_mp3, wstring mp3_folder, int mode) {
	hFind = FindFirstFile(all_mp3.c_str(), &FindFileData);

	if (hFind != INVALID_HANDLE_VALUE) {
		//_tprintf(TEXT("The first file found is %s\n"),
		//	FindFileData.cFileName); // prints cFileName string

		string temp = return_tag(FindFileData.cFileName, mode);
		sort_file(temp, FindFileData, mp3_folder);
	}
	else {
		cout << "Mp3 file not found" << endl;
		return 0;
	}
}

void scanNextFile(HANDLE& hFind, WIN32_FIND_DATAW FindFileData, wstring mp3_folder, int mode) {
	if (hFind != INVALID_HANDLE_VALUE) {
		//_tprintf(TEXT("The second file found is %s\n"),
		//	FindFileData.cFileName); // prints cFileName string
		//strcpy(artist, return_tag(FindFileData.cFileName, 1));
		string temp = return_tag(FindFileData.cFileName, mode);
		sort_file(temp, FindFileData, mp3_folder);
	}
}