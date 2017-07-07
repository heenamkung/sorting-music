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

//https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring?page=1&tab=votes#tab-top trim string function
static inline std::string &rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}


string get_directory() {
	cout << "Enter directory where mp3 files are stored: (e.g: C://Users/Bob/Documents) " << endl;
	string mp3_dir; // Get directory where mp3 files are stored
	//cin >> mp3_dir;
	mp3_dir = "C://Users/Hee/Documents/temp";

	_chdir(mp3_dir.c_str()); //change current dir to mp3_dir
	return mp3_dir;
}

int get_sorting_mode() {
	cout << "Sort mp3 file by: 1. Artist 2. Album 3. Year (Enter integer value)" << endl;
	int sorting_mode;
	cin >> sorting_mode;
	return sorting_mode;
}

string return_tag(const wstring file_name, int mode) {
	//mode 1. artist 2. album 3. year
	ifstream mp3File;
	mp3File.open(file_name);
	char temp;
	switch (mode) {
	case 1:
		char artist[31];
		mp3File.seekg(-95, mp3File.end);
		for (int i = 0; i < 30; ++i) {
			mp3File.get(temp);
			if (temp == '0') {
				break;
			}
			artist[i] = temp;
			cout << artist[i] ;
			
		}
		artist[30] = '\0';
		cout << endl;
		mp3File.close();
		return string(artist);

	case 2:
		char album[31];
		mp3File.seekg(-65, mp3File.end);
		for (int i = 0; i < 30; ++i) {
			mp3File.get(temp);
			album[i] = temp;
			cout << album[i];
			
		}
		album[30] = '\0';
		cout << endl;
		mp3File.close();
		return string(album);

	default:
		char year[5];
		mp3File.seekg(-35, mp3File.end);
		for (int i = 0; i < 4; ++i) {
			mp3File.get(temp);
			year[i] = temp;
			cout << year[i];
			
		}
		year[4] = '\0';
		cout << endl;
		mp3File.close();
		return string(year);
	}

}

std::string GetLastErrorAsString() //https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror answer by jamin grey
{
	//Get the error message, if any.
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0)
		return std::string(); //No error message has been recorded

	LPSTR messageBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	std::string message(messageBuffer, size);

	//Free the buffer.
	LocalFree(messageBuffer);

	return message;
}


wstring conv(string str) {
	wstring str2(str.length(), L' '); // Make room for characters
									  // Copy string to wstring.
	copy(str.begin(), str.end(), str2.begin());
	return str2;
}

void sort_file(string sort_by, WIN32_FIND_DATA FindFileData) {
	rtrim(sort_by);
	_mkdir(sort_by.c_str()); //create folder named sort_by
	cout << sort_by.c_str() << endl;
	wstring loc = conv("C:\\Users\\Hee\\Documents\\temp\\");
	wstring x = loc + FindFileData.cFileName;
	wstring y = loc + conv(sort_by.c_str()) + L"\\" + FindFileData.cFileName;


	if (MoveFile(x.c_str(), y.c_str()) == 0) {
		cout << GetLastErrorAsString() << endl;
		cout << "error" << endl;
	}

}

bool scanFirstFile(HANDLE& hFind, WIN32_FIND_DATAW FindFileData, wstring all_mp3, int mode) {
	hFind = FindFirstFile(all_mp3.c_str(), &FindFileData);

	if (hFind != INVALID_HANDLE_VALUE) {
		//_tprintf(TEXT("The first file found is %s\n"),
		//	FindFileData.cFileName); // prints cFileName string

		string temp = return_tag(FindFileData.cFileName, mode);
		sort_file(temp, FindFileData);
	}
	else {
		cout << "Mp3 file not found" << endl;
		return 0;
	}
}

void scanNextFile(HANDLE& hFind, WIN32_FIND_DATAW FindFileData, int mode) {
	if (hFind != INVALID_HANDLE_VALUE) {
		//_tprintf(TEXT("The second file found is %s\n"),
		//	FindFileData.cFileName); // prints cFileName string
									 //strcpy(artist, return_tag(FindFileData.cFileName, 1));
		string temp = return_tag(FindFileData.cFileName, mode);
		sort_file(temp, FindFileData);
	}
}
