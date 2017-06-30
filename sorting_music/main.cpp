#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <Windows.h>
#include <string>
#include <utility>
#include <direct.h>
#include <fstream>


int main() {
	/* playing around with directories

	const int x = 1000;
	char buff[x];
	cout << _getcwd(buff, x); //retrive current dir
	cout << _mkdir("folder2")<<endl; //make dir
	cout << rmdir("folder") << endl; //remove dir
	
	
	cout << _getcwd(buff, x) << endl; 
	*/
	char header[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	

	_chdir("C://Users/Hee/Documents"); //change current dir
	ifstream myfile;
	myfile.open("rock.mp3");
	myfile.seekg(-128, myfile.end); //go to 128chars before end of file
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
	system("pause");
}