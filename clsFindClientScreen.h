#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindClientScreen :protected cslScreen
{
	static void _PrintClientRecord(clsBankClient c)
	{
		cout << "\nCleint's info:\n\n";
		cout << "-----------------------------------------\n";
		cout << "First Name     : " << c.FirstName << endl;
		cout << "Last Name      : " << c.LastName << endl;
		cout << "Full Name      : " << c.FullName() << endl;
		cout << "Email          : " << c.Email << endl;
		cout << "Phone          : " << c.Phone << endl;
		cout << "Account Number : " << c.AccountNumber << endl;
		cout << "Pin Code       : " << c.PinCode << endl;
		cout << "Balance        : " << c.AccountBalance << endl;
		cout << "-----------------------------------------\n";

	}

public:

	static void ShowFindClient()
	{
		if (!cslScreen::CheckAccessRights(clsUser::enPermissions::pFindClient))
			return;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		_DraWScreenHeader("     Find Client Screen");

		string AccountNumber = "";
		AccountNumber=clsInputValidate<double>::ReadString("Enter Account Number ? ");
		while(!clsBankClient::IsClientExist(AccountNumber))
		{

			AccountNumber = clsInputValidate<double>::ReadString("this account number not exist try again!");
		}

		clsBankClient c = clsBankClient::Find(AccountNumber);

		if (c.IsEmpty())
		{
			cout << "Client was not found";
		}
		else 
		{
			cout << "\n\nWe found the account successfully!\n";
			_PrintClientRecord(c);
		}





	}




};

