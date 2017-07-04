#include <iostream>
#include <Windows.h>
#include <string>
#include <utility>
#include <direct.h>
#include <fstream>
#include <tchar.h>
#include <algorithm>
#include "mp3_sort.h"

using namespace std;





/* playing around with directories

const int x = 1000;
char buff[x];
cout << _getcwd(buff, x); //retrive current dir
cout << _mkdir("folder2")<<endl; //make dir
cout << rmdir("folder") << endl; //remove dir

*/

int main() {

	string mp3_folder;
	int mode;

	mp3_folder = get_directory();
	mode = get_sorting_mode();


	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	wstring all_mp3 = conv(mp3_folder) + L"/*.mp3"; // adds "\\*.mp3" to the end of path. Used to search all mp3 files in dir.  e.g C:\\Users\\Hee\\Documents\\*.mp3

	hFind = FindFirstFile(all_mp3.c_str(), &FindFileData);
	
	if (hFind != INVALID_HANDLE_VALUE) {
		_tprintf(TEXT("The first file found is %s\n"),
			FindFileData.cFileName); // prints cFileName string
		string temp = return_tag(FindFileData.cFileName, mode);
		sort_file(temp , FindFileData);
	}
	else {
		cout << "Mp3 file not found" << endl;
		return 0;
	}


	if (FindNextFile(hFind, &FindFileData)) {
		if (hFind != INVALID_HANDLE_VALUE) {
			_tprintf(TEXT("The second file found is %s\n"),
				FindFileData.cFileName); // prints cFileName string
			//strcpy(artist, return_tag(FindFileData.cFileName, 1));
			string temp = return_tag(FindFileData.cFileName, mode);
			sort_file(temp, FindFileData);
		}
			}
	else {
		cout << "Sorting finished" << endl;
	}


	
		

	system("pause");
}