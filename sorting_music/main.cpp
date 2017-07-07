#include <iostream>
#include <Windows.h>
#include <string>
#include <utility>
#include <direct.h>
#include <fstream>
#include <tchar.h>
#include <algorithm>
#include "userInput.h"
#include "stringHandling.h"
#include "scanFile.h"

using namespace std;



int main() {

	string mp3_folder;
	int mode;

	mp3_folder = get_directory();
	mode = get_sorting_mode();
	//file handlers 
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	wstring all_mp3 = conv(mp3_folder) + L"/*.mp3"; // adds "/*.mp3" to the end of path. Used to search all mp3 files in dir.  e.g C:\\Users\\Hee\\Documents\\*.mp3
	

	if (scanFirstFile(hFind, FindFileData, all_mp3, mode)==0) {
		cout << "mp3 file not found" << endl;
		return 0;
	}

	while (FindNextFile(hFind, &FindFileData)) {
		scanNextFile(hFind, FindFileData, mode);
	}
	cout << "Sorting finished" << endl;

	
		

	system("pause");
}