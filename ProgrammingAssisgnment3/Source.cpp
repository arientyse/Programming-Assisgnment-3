#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int REGULAR_HOURS = 40;

int main()
{
	int choice;
	char drive[2], disk_file[15], file[9];
	ofstream outfile;

	char employeename[30];
	char employeeid[10];
	int employeeclass;
	
	int hoursworked;
	int overtimehours;
	
	double hourlyrate;
	double regularpay;
	double overtimepay;
	
	double totalamount;


	//input
	
	system("cls");
	
	cout << setw(20) << left << "WorkHard Corportation Payroll" << endl << endl;

	cout << "Please enter your first and last name. "<< endl;
	cin.getline(employeename, sizeof(employeename) - 1);

	cout << endl;

	cout << "Please enter your Employee ID number. " << endl;
	cin >> employeeid;

	cout << endl;

	cout << "Please your Employee Job Classification Number. " << endl;
	cin.ignore();
	cin >> employeeclass;

	cout << endl;

	cout << "Please enter the number of hours worked. " << endl;
	cin.ignore();
	cin >> hoursworked;

	cout << endl << endl;

	//process

	switch (employeeclass)
	{
		case 1:hourlyrate = 5.50;
			break;

		case 2:hourlyrate = 6.00;
			break;

		case 3:hourlyrate = 7.00;
			break;

		case 4:hourlyrate = 9.00;
			break;

		case 5:hourlyrate = 12.00;
			break;

		default: hourlyrate = 5.50;
					
	}

	if (hoursworked < 40)
	{
		overtimehours = 0;
		regularpay = hoursworked * hourlyrate;
	}
	else
	{
		overtimehours = 0;
		regularpay = REGULAR_HOURS * hourlyrate;
	}

	if (hoursworked > 40)
	{
		overtimehours = hoursworked - REGULAR_HOURS;
		overtimepay = (overtimehours) * 1.5 * hourlyrate;
		totalamount = regularpay + overtimepay;
	}
	else
	{
		overtimepay = 0;
		totalamount = regularpay;
	}
	


	//output

	system("cls");
	cout << "Output to Console (1) or Disk File (2): ";
	cin >> choice;
	if (choice == 1)
	{
		system("cls");
		outfile.open("con");
	}
	else
	{
		cout << "Which drive: A, B, or C? ";
		cin >> drive;
		strcpy(disk_file, drive);
		strcat(disk_file, ":");

		cout << "Enter a Results File Name: ";
		cin >> file;
		strcat(disk_file, file);
		strcat(disk_file, ".txt");
		outfile.open(disk_file);
	}
	outfile << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);


	outfile << right << setw(70) << "WorkHard Corporation Payroll" << endl << endl;



	outfile << left << setw(30) << "Employee Name:";
	outfile	<< setw(30) << employeename;
	
	outfile << left << setw(30) << "Employee ID:";
	outfile	<< setw(30) << employeeid;

	outfile << endl << endl;
	
	outfile << setw(30) << "Employee Job Classification:";
	outfile	<< setw(30) << employeeclass;
	

	
	outfile << setw(30) << "Hourly Rate: $";
	outfile << setw(30) << hourlyrate;

	outfile << endl << endl;
	
	outfile << left << setw(30) << "Total Hours Worked:";
	outfile << setw(30) << hoursworked;

	outfile << left << setw(30) << "Overtime Hours:";
	outfile << setw(30) << overtimehours;
	
	outfile << endl << endl;
	

	outfile << left << setw(30) << "Regular Pay: $"; 
	outfile << setw(30) << regularpay;
	
	outfile << left << setw(30) << "Overtime Pay: $";
	outfile << setw(30) << overtimepay;


	outfile << endl << endl;

	outfile << right << setw(60) << "Total Earnings: $" << totalamount << endl;
	outfile << endl;
	
	if (hoursworked < REGULAR_HOURS)
	{
		outfile << right << setw(72) << "Inadequate Number of Hours Worked!" << endl;
	}
	
	if (hoursworked > 60)
	{
		outfile << right << setw(72) << "Excessive Number of Hours Worked!" << endl;
	}
	
	outfile << endl;
	
	if (hourlyrate > 5)
	{
		outfile << right << setw(70) << "Invalid Job Classification!" << endl;
		outfile << right << setw(68) << " Class set to One: $5.50." << endl;
	}
	
	outfile.close();
	cout << endl << endl;
	system("PAUSE");
	return 0;
}
