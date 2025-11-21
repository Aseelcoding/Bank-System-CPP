#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsMainScreen.h"
class clsTotalBalancScreen:protected cslScreen
{
private :
	static void _PrintCleintRecordLineForShowingBalance(clsBankClient c)
	{
		cout << "| " << setw(20) << left << c.AccountNumber;
		cout << "| " << setw(20) << left << c.FullName();
		cout << "| " << setw(20) << left << c.AccountBalance;


	}

public :
	static void ShowTotalBalances()
	{
		vector< clsBankClient>vClients = clsBankClient::GetClientsLest();

		string Title = "\n\t\t\t\t\t\tClient Balanmce ";
		string Sup = "\t(" + to_string(vClients.size()) + ") Client(s).";
		_DraWScreenHeader(Title, Sup);

		cout << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(20) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(20) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vClients.size() == 0)
			cout << "There is no clients!\n";
		else
		{
			for (clsBankClient& c : vClients)
			{
				_PrintCleintRecordLineForShowingBalance(c);
				cout << endl;
			}
		}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double Total = clsBankClient::GetTotalBalances();
		cout << "\t\t\t\tTotal balances are :" << Total << endl;
		cout << "\t\t\t\t" << "(" << clsUtil::NumberToText(Total) << ")" << endl;
	}
};

