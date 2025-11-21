#pragma once
#include <iostream>
#include "cslScreen.h"
#include "clsBankClient.h"
#include <vector>
#include<iomanip>
#include "Global.h"
using namespace std;

class clsTransferLogScreen:protected cslScreen
{

	static void _PrintTransferRecord(clsBankClient::stTransferRecord &Record)
	{


		cout << "| " << setw(21) << left << Record.Date;;
		cout << "| " << setw(6) << left << Record.AccountNumber1;
		cout << "| " << setw(6) << left << Record.AccountNumber2;
		cout << "| " << setw(6) << left << Record.AmountOfMoney;
		cout << "| " << setw(9) << left << Record.Balance1;
		cout << "| " << setw(9) << left << Record.Balance2;
		cout << "| " << setw(7) << left << Record.UserName;


	}

public :
	static void ShowTansferLogScreen()
	{
		vector< clsBankClient::stTransferRecord> VstTransferRecord = clsBankClient::GetTransferHistory();

		_DraWScreenHeader("   Transfer History");
		string Title = "\n\t\t\t\t\t\tTransfer History ";
		string Sup = "\t(" + to_string(VstTransferRecord.size()) + ") Record(s).";

		cout << "| " << left << setw(21) << " Date And Time";
		cout << "| " << left << setw(6) << "1.Acct";
		cout << "| " << left << setw(6) << "2.Acct";
		cout << "| " << left << setw(6) << "Amount";
		cout << "| " << left << setw(9) << "1.Balance";
		cout << "| " << left << setw(9) << "2.Balance";
		cout << "| " << left << setw(7) << "User";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	for (clsBankClient::stTransferRecord &Record: VstTransferRecord)
	{

		_PrintTransferRecord(Record);
		cout << endl;
	}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}


};

