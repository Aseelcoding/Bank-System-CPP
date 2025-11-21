#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class ShowUpdateClientScreen :protected cslScreen
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
	static 	void ReadClientData(clsBankClient& c)
	{
		c.FirstName = clsInputValidate<double>::ReadString("Enter First Name");
		c.LastName = clsInputValidate<double>::ReadString("Enter Last Name");
		c.Email = clsInputValidate<double>::ReadString("Enter Email");
		c.Phone = clsInputValidate<double>::ReadString("Enter Phone");
		c.PinCode = clsInputValidate<double>::ReadString("Enter PinCode");
		c.AccountBalance = clsInputValidate<double>::ReadNumber("Enter AccountBalance");
	}

public :
	static void UpDateClient()
	{
		if (!cslScreen::CheckAccessRights(clsUser::enPermissions::pUpdateClient))
			return;
		_DraWScreenHeader("    Update Client Screen");

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string AccounNumber;

		AccounNumber = clsInputValidate<double>::ReadString("Enter Account Number");

		while (!clsBankClient::IsClientExist(AccounNumber))
		{
			AccounNumber = clsInputValidate<double>::ReadString("Try Again please!");
		}

		clsBankClient c = clsBankClient::Find(AccounNumber);
		_PrintClientRecord(c);
		cout << "Update Client Info\n\n";
		cout << "------------------------------\n";

		ReadClientData(c);
		clsBankClient::EnSaveResult SaveResult;
		SaveResult = c.Save();

		switch (SaveResult)
		{
		case clsBankClient::EnSaveResult::Successfull:
			cout << "Updated Successfully!\n";
			_PrintClientRecord(c);
			break;
		case clsBankClient::EnSaveResult::UnSuccessfull:
			cout << "unSuccessful Operation!\n";
		}

	}



};

