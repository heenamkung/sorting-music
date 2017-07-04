#pragma once
using namespace std;

#include <iostream>
#include <Windows.h>
#include <string>
#include <direct.h>
#include <fstream>
#include <algorithm>
#include <tchar.h>

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
	int sorting_mode = 1;
	//cin >> sorting_mode;
	return sorting_mode;
}

string return_tag(const wstring file_name, int mode) {
	//mode 1. artist 2. album 3. year
	ifstream mp3File;
	mp3File.open(file_name);
	char temp;
	switch (mode) {
	case 1:
		char artist[30];
		mp3File.seekg(-95, mp3File.end);
		for (int i = 0; i < 30; ++i) {
			mp3File.get(temp);
			artist[i] = temp;
		}
		mp3File.close();
		return string(artist);

	case 2:
		char album[30];
		mp3File.seekg(-65, mp3File.end);
		for (int i = 0; i < 30; ++i) {
			mp3File.get(temp);
			album[i] = temp;
		}
		mp3File.close();
		return string(album);

	default:
		char year[4];
		mp3File.seekg(-35, mp3File.end);
		for (int i = 0; i < 4; ++i) {
			mp3File.get(temp);
			year[i] = temp;
		}
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
	_mkdir(sort_by.c_str()); //create folder named sort_by
	cout << sort_by.c_str() << endl;
	wstring loc = conv("C:\\Users\\Hee\\Documents\\temp\\");
	wstring x = loc + FindFileData.cFileName;
	wstring y = loc + conv(sort_by) + L"\\" + FindFileData.cFileName;


	if (MoveFile(x.c_str(), y.c_str()) == 0) {
		cout << GetLastErrorAsString() << endl;
		cout << "error" << endl;
	}

}

