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

//retrives artist, album, year information from mp3 file

string return_tag(const wstring file_name, int mode) {
	//mode 1. artist 2. album 3. year
	ifstream mp3File;
	mp3File.open(file_name);
	char temp;
	char tag[4];
	mp3File.seekg(-128, mp3File.end);
	for (int i = 0; i < 3; ++i) {
		mp3File.get(temp);
		tag[i] = temp;
		cout << tag[i];
	}
	tag[3] = '\0';
	if (string(tag) != "TAG") {
		return "";
	}
	mp3File.clear();

	switch (mode) {
	case 1:
		char artist[31];
		mp3File.seekg(-95, mp3File.end);
		for (int i = 0; i < 30; ++i) {
			mp3File.get(temp);
			artist[i] = temp;
			cout << artist[i];

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