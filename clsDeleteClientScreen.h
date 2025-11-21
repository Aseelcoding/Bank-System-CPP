#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeleteClientScreen :protected cslScreen
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


public :

	static void ShowDeleteCleintScreen()
	{
		if (!cslScreen::CheckAccessRights(clsUser::enPermissions::pDeleteClients))
			return;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string AccounNumber;

		_DraWScreenHeader("   Detele Client Screen");


		AccounNumber = clsInputValidate<double>::ReadString("Enter Account Number");

		while (!clsBankClient::IsClientExist(AccounNumber))
		{
			AccounNumber = clsInputValidate<double>::ReadString("there is no Account number like this,try again please ");
		}
		clsBankClient c = clsBankClient::Find(AccounNumber);
		_PrintClientRecord(c);


		char answer;
		cout << "Are You sure that you want to delete this client? enter y/n\n";
		cin >> answer;
		if (answer == 'n' || answer == 'N')
		{
			return;
		}

		switch (c.Delete())
		{
		case true:
			cout << "Delete client done successfully\n";
			_PrintClientRecord(c);
			system("pause");
			break;
		case false:
			cout << "Unsucessful operation\n";
			break;
		}

	}


};

