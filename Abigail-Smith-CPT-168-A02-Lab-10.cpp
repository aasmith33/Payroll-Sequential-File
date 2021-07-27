// Abigail-Smith-CPT-168-A02-Lab-10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	cout << fixed << setprecision(2);
	system("color ff");
	ifstream payroll;
	payroll.open("Payroll.txt");
	string fname = "", lname = "", SSN = "", far = "", social = "";
	int num = 0, hours = 0;
	double rate = 0.0, gross = 0.0, deduct = 0.0, netpay = 0.0;

	cout << "\t\t\t\t***************************\t\t" << endl;
	cout << "\t\t\t\t*      Abigail Smith      *\t\t" << endl;
	cout << "\t\t\t\t*      CPT-168-A02S       *\t\t" << endl;
	cout << "\t\t\t\t* Payroll Sequential File *\t\t" << endl;
	cout << "\t\t\t\t***************************\t\t" << endl << endl;
	cout << "\tSSN \tName\t\tHours\tRate\t\tGross\t\tDeductions\tNetPay" << "\n";
	cout << "\t____\t_________\t______\t______\t\t______\t\t__________\t_________" << endl << endl;
	payroll >> fname >> lname >> SSN >> hours >> rate;
	while (payroll.eof() == false)
	{
		num++;
		if (hours <= 40)
			gross = hours * rate;
		else
			gross = (40 * rate) + (hours - 40) * rate *1.5;
		deduct = gross * 0.1;
		netpay = gross - deduct;
		cout << "\t" << setw(4) << SSN.substr(7, 4) << "\t" << setw(4) << fname.substr(0, 1) << "." << lname;
		cout << "\t" << setw(4) << hours << "\t" << setw(4) << rate << "\t\t" << setw(4) << gross;
		cout << "\t\t" << setw(4) << deduct << "\t\t" << setw(4) << netpay << endl;

		payroll >> fname >> lname >> SSN >> hours >> rate;

	}

	cout << endl;
	cout << "\t\tNumber of records: " << num << endl << endl;
	cout << "\t\t\t\t\tT H A N K   Y O U" << endl;
	payroll.close();
	system("pause");
	return 0;
}
