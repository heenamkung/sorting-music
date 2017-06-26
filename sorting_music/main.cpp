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
	const int x = 1000;
	char buff[x];
	cout << _getcwd(buff, x);
	cout << _mkdir("folder");
	cout << rmdir("folder2");
	_chdir("C://Users/Hee/Documents");
	cout << _getcwd(buff, x);
	ifstream myfile;
	myfile.open("rock.mp3");
	char c;
	while (myfile.get(c))
		cout << c;

	system("pause");
}