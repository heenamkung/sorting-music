#pragma once
using namespace std;

#include <iostream>
#include <Windows.h>
#include <string>
#include <direct.h>
#include <fstream>
#include <algorithm>

/**
*Asks user the path (where mp3 files are stored) and how to sort the mp3 files.
*/

string get_directory() {
	cout << "Enter directory where mp3 files are stored: (e.g: C://Users/Bob/Documents) " << endl;
	string mp3_dir; // Get directory where mp3 files are stored
	cin >> mp3_dir;
	

	_chdir(mp3_dir.c_str()); //change current dir to mp3_dir
	return mp3_dir;
}

int get_sorting_mode() {
	cout << "Sort mp3 file by: 1. Artist 2. Album 3. Year (Enter integer value)" << endl;
	int sorting_mode;
	cin >> sorting_mode;
	return sorting_mode;
}