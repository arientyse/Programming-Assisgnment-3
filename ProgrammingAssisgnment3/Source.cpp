#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
	int choice;
	char drive[2], disk_file[15], file[9];
	ofstream outfile;

	//input


	//process


	//output

	system("cls");
	cout << "Output choice: Enter 1 for file, 2 for screen";
	cin >> choice;

	system("cls");
	cout << "Output to console (1) or disk file (2): ";
	cin >> choice;
	if (choice == 1)
	{
		system("cls");
		outfile.open("con");
	}
	else
	{
		cout << "Which drive: a, b, or c? ";
		cin >> drive;
		strcpy(disk_file, drive);
		strcat(disk_file, ":");

		cout << "Enter a results file name: ";
		cin >> file;
		strcat(disk_file, file);
		strcat(disk_file, ".txt");
		outfile.open(disk_file);
	}
	outfile << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);

	outfile.close();
	cout << endl << endl;
	system("PAUSE");
	return 0;
}
