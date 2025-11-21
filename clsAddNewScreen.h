#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsAddNewScreen: protected cslScreen
{
	static void _PrintClientRecord(clsBankClient c)
	{
		cout << "\nCleint's info:\n\n";
		cout << "-----------------------------------------\n";
		cout << "First Name     : " << c.FirstName << endl;
		cout << "Last Name      : " <<c. LastName << endl;
		cout << "Full Name      : " << c.FullName() << endl;
		cout << "Email          : " <<c. Email << endl;
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
	static void AddNewClient()
	{
		if (!cslScreen::CheckAccessRights(clsUser::enPermissions::pAddNewClients))
			return;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		_DraWScreenHeader("   Add New Client Screen");

	

		string AccounNumber = " ";

		AccounNumber = clsInputValidate<double>::ReadString("Enter Account Number");

		while (clsBankClient::IsClientExist(AccounNumber))
		{
			AccounNumber = clsInputValidate<double>::ReadString("This Account Number is Already Exist! try again");
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClinet(AccounNumber);
		cout << "\nRead New Client\n\n";
		cout << "------------------------------\n";
		ReadClientData(NewClient);
		clsBankClient::EnSaveResult SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case  clsBankClient::EnSaveResult::Successfull:
			cout << "Add new client done successfuly\n";
			_PrintClientRecord(NewClient);
				break;
		case clsBankClient::EnSaveResult::UnSuccessfull:
			cout << "unSuccessful Operation!\n";
			break;
		case clsBankClient::EnSaveResult::svFaildAccountNumberExist:
			cout << "unSuccessful Operation Because this account number already exist!\n";
			break;

		}

	}


};

