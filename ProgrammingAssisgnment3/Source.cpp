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
	
	cout << setw(20) << left << "WorkHard Corportation" << endl << endl;

	cout << "Please enter your first and last name. "<< endl;
	cin.getline(employeename, sizeof(employeename) - 1);

	cout << "Please enter your Employee ID number. " << endl;
	cin >> employeeid;

	cout << "Please your Employee Job Classification Number. " << endl;
	cin.ignore();
	cin >> employeeclass;

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

		default:hourlyrate = 5.50;
			cout << "You did not enter one of the five Job Classifications! Hourly Rate set to $5.50." << endl;
			
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


	outfile << right << setw(50) << "WorkHard Corporation Payroll" << endl << endl;
	

	outfile << left << setw(20) << "Employee Name:";
	outfile	<< setw(20) << employeename;
	
	outfile << setw(20) << "Employee ID: ";
	outfile	<< setw(20) << employeeid;
	
	outfile << setw(20) << "Employee Job Classification: " << setw(6) << right << employeeclass << endl;
	cout << endl;
	
	outfile << setw(20) << left << "Hourly Rate: $ " << setw(6) << right << hourlyrate << endl;
	outfile << setw(20) << left << "Total Hours Worked: " << setw(6) << right << hoursworked << endl;
	outfile << setw(20) << left << "Overtime Hours: " << setw(6) << right << overtimehours << endl;
	cout << endl;

	outfile << setw(20) << left << "Regular Pay: $ " << setw(6) << right << regularpay << endl;
	outfile << setw(20) << left << "Overtime Pay: $ " << setw(6) << right << overtimepay << endl;
	cout << endl;

	outfile << setw(20) << left << "Total Earnings: $ " << right << totalamount << endl;
	cout << endl;
	
	if (hoursworked < REGULAR_HOURS)
	{
		outfile << setw(20) << left << "Inadequate Number of Hours Worked!" << right << endl;
	}
	
	if (hoursworked > 60)
	{
		outfile << setw(20) << left << "Excessive Number of Hours Worked!" << right << endl;
	}
	cout << endl;
	
	outfile.close();
	cout << endl << endl;
	system("PAUSE");
	return 0;
}
