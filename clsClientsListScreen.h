#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsBankClient.h"
#include "Global.h"

class clsClientsListScreen: protected cslScreen
{

private:

	static void _PrintCleintRecordLine(clsBankClient c)
	{
		cout << "| " << setw(15) << left << c.AccountNumber;
		cout << "| " << setw(15) << left << c.FullName();
		cout << "| " << setw(20) << left << c.Email;
		cout << "| " << setw(14) << left << c.Phone;
		cout << "| " << setw(11) << left << c.PinCode;
		cout << "| " << setw(13) << left << c.AccountBalance;


	}


public:
	static void ShowClientsList()
	{
		if (!cslScreen::CheckAccessRights(clsUser::enPermissions::pShowClients))
			return;

		vector< clsBankClient>vClients = clsBankClient::GetClientsLest();

		string Title = "\n\t\t\t\t\t\tClient List ";
	string Sup=		"\t(" +to_string(vClients.size())+ ") Client(s).";
	           _DraWScreenHeader(Title,Sup);
	

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(15) << "Client Name";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(15) << "phone";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vClients.size() == 0)
			cout << "There is no clients!\n";
		else
		{
			for (clsBankClient& cc : vClients)
			{
				_PrintCleintRecordLine(cc);
				cout << endl;
			}
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}



};

