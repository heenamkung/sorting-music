#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <utility>
#include <direct.h>
#include <fstream>
#include <tchar.h>

using namespace std;

int main() {
	/* playing around with directories

	const int x = 1000;
	char buff[x];
	cout << _getcwd(buff, x); //retrive current dir
	cout << _mkdir("folder2")<<endl; //make dir
	cout << rmdir("folder") << endl; //remove dir
	
	
	cout << _getcwd(buff, x) << endl; 
	*/

	cout << "Enter directory where mp3 files are stored: (e.g: C://Users/Bob/Documents) " << endl;
	cout << "Sort mp3 file by: 1. Artist 2. Album 3. Year " << endl;

	char header[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	

	_chdir("C://Users/Hee/Documents/temp"); //change current dir
	ifstream myfile;
	myfile.open("rock.mp3");
	myfile.seekg(-128, myfile.end); //go to 128chars before end of file where id3 tag infos are stored.
	char c;

	cout << "Header:";
	for (int i = 0; i < 3; ++i) {
		myfile.get(c);
		cout << c;
	}
	cout << endl;

	cout << "Title:";
	for (int i = 0; i < 30; ++i) {
		myfile.get(c);
		cout << c;
	}
	cout << endl;

	cout << "Artist:";
	for (int i = 0; i < 30; ++i) {
		myfile.get(c);
		cout << c;
	}
	cout << endl;

	cout << "Album:";
	for (int i = 0; i < 30; ++i) {
		myfile.get(c);
		cout << c;
	}
	cout << endl;

	cout << "Year:";
	for (int i = 0; i < 4; ++i) {
		myfile.get(c);
		cout << c;
	}
	cout << endl;

	cout << "Comment:";
	for (int i = 0; i < 28; ++i) {
		myfile.get(c);
		cout << c;
	}
	cout << endl;

	cout << "zero-byte:";
	for (int i = 0; i < 1; ++i) {
		myfile.get(c);
		int genre_index = static_cast<int>(c);
		cout << genre_index;
	}
	cout << endl;

	cout << "track:";
	for (int i = 0; i < 1; ++i) {
		myfile.get(c);
		int genre_index = static_cast<int>(c);
		cout << genre_index;
	}
	cout << endl;


	//while (myfile.get(c))
	//	cout << c;
	
	myfile.close();

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	hFind = FindFirstFile(L"C:\\Users\\Hee\\Documents\\*.mp3", &FindFileData);
	cout << FindFileData.cFileName;
	if (hFind != INVALID_HANDLE_VALUE) {
		cout << "First file" << endl;
		_tprintf(TEXT("The first file found is %s\n"),
			FindFileData.cFileName); // prints cFileName string
	}

	FindNextFile(hFind, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		cout << "Second file" << endl;
		_tprintf(TEXT("The second file found is %s\n"),
			FindFileData.cFileName); // prints cFileName string
	}

	FindNextFile(hFind, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		cout << "Third file" << endl;
		_tprintf(TEXT("The third file found is %s\n"),
			FindFileData.cFileName); // prints cFileName string
	}




	myfile.open(FindFileData.cFileName);
	myfile.seekg(-128, myfile.end); //go to 128chars before end of file
	char d;

	cout << "Header:";
	for (int i = 0; i < 3; ++i) {
		myfile.get(d);
		cout << d;
	}
	cout << endl;
	cout << "Title:";
	for (int i = 0; i < 30; ++i) {
		myfile.get(d);
		cout << d;
	}
	cout << endl;

	cout << "Artist:";
	for (int i = 0; i < 30; ++i) {
		myfile.get(d);
		cout << d;
	}
	cout << endl;
	if (MoveFile(L"C:\\Users\\Hee\\Documents\\rock.mp3", L"C:\\Users\\Hee\\Documents\\temp\\rock.mp3") == 0) {
		GetLastError();
		cout << "error" << endl;

	}
	



	system("pause");
}