#pragma once
#include <iostream>
using namespace std;
#include "cslScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
class clsTransferScreen:protected cslScreen
{
	static 	void _PrintClientRecordTransfer(clsBankClient Client)
	{
		cout << "\nCleint's info:\n\n";
		cout << "-----------------------------------------\n";
		cout << "Full Name      : " << Client.FullName() << endl;
		cout << "Account Number : " << Client. AccountNumber << endl;
		cout << "Balance        : " << Client.AccountBalance << endl;
		cout << "-----------------------------------------\n";

	}

public :

	static void ShowTransferScreen()
	{
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		_DraWScreenHeader("Transfer Screen");

		string AccountNumber1 = clsInputValidate<double>::ReadString("Enter Account Number to transfer from ? ");
		clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
		while(Client1.IsEmpty())
		{
			 AccountNumber1 = clsInputValidate<double>::ReadString(" Wrong Account Number PLease try again\nEnter Account Number to transfer from ? ");
			 Client1 = clsBankClient::Find(AccountNumber1);
		}
		_PrintClientRecordTransfer(Client1);
		///////////////////////////////////////////////////////////////////////////////////////////////////
		string AccountNumber2 = clsInputValidate<double>::ReadString("Enter Account Number to transfer to ? ");
		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
		while (Client2.IsEmpty())
		{
			AccountNumber2 = clsInputValidate<double>::ReadString(" Wrong Account Number PLease try again\nEnter Account Number to transfer to ? ");
			 Client2 = clsBankClient::Find(AccountNumber2);
		}

		while(Client1.AccountNumber== Client2.AccountNumber)
		{cout << "you cant transfer from and to , to the same account\n\n";
		AccountNumber2 = clsInputValidate<double>::ReadString("Enter Account Number to transfer to ? ");
		Client2 = clsBankClient::Find(AccountNumber2);
		}
		_PrintClientRecordTransfer(Client2);
	//////////////////////////////////////////////////////////////////////////////////////////////////
		if (Client1.AccountBalance == 0)
		{
			cout << "Client that you want to transfer from has 0 amount of money \n";
			return;
		
		}

		double AmountOfMoney;
		AmountOfMoney = clsInputValidate<double>::ReadNumber("Enter amount of money to transfer\n");

		while (Client1.AccountBalance < AmountOfMoney)
		{
			AmountOfMoney = clsInputValidate<double>::ReadNumber("	Please enter a transfer amount that is equal to or less than your available balance. \nEnter amount of money to transfer\n");
		}
		clsBankClient::EnSaveResult SaveResult=	clsBankClient::TransferMoney(Client1, Client2, AmountOfMoney);

		switch(SaveResult)
		{
		case clsBankClient::EnSaveResult::Error:
			cout << "Client that you want to transfer from has 0 amount of money \n";
			break;
		case clsBankClient::EnSaveResult::UnSuccessfull:
			cout << "UnSuccessfull operation\n";
			break;
		case clsBankClient::EnSaveResult::Successfull:
			cout << "Transfer Done Successfully\n\n";
			_PrintClientRecordTransfer(Client1);
			_PrintClientRecordTransfer(Client2);
			break;
		}

	
	}

};

