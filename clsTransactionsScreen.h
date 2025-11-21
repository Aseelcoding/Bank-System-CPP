#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepostScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsTransactionsScreen:protected cslScreen
{
private :
	enum enTransactionsMenueOptions
	{
		eDeposit=1,eWithdraw=2,
		eShowTotalBalances=3,
		eShowTransferScreen=4,
		eShowTransferLog=5,
		eShowMainMenue=6
	};
	static short _ReadTransActionsMenueOption()
	{
		short Num;
		Num = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 and 6 ? ");
		return Num;

	}
	static void _ShowDepositScreen()
	{
		clsDepostScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalances()
	{
		clsTotalBalancScreen::ShowTotalBalances();
	}
	static void ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}
	static void  _ShowTransferLog()
	{
		clsTransferLogScreen::ShowTansferLogScreen();
	}
	static void _GobackToTransactionsMenue()
	{
		cout << endl;
		system("pause");
		ShowTrasactionsScreen();
	}
	static void _PerformTransactionsMenue(enTransactionsMenueOptions o)
	{
		switch (o)
		{
		case enTransactionsMenueOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GobackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GobackToTransactionsMenue();
			break;

		case enTransactionsMenueOptions::eShowTotalBalances:
			system("cls");
			_ShowTotalBalances();
			_GobackToTransactionsMenue();
			break;

		case enTransactionsMenueOptions::eShowTransferScreen:
			system("cls");
			ShowTransferScreen();
			_GobackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eShowTransferLog:
			system("cls");
			_ShowTransferLog();
			_GobackToTransactionsMenue();
			break;


		case enTransactionsMenueOptions::eShowMainMenue:
			break;


		}


	}
public:

	static void ShowTrasactionsScreen()
	{
		if (!cslScreen::CheckAccessRights(clsUser::enPermissions::pTransactions))
			return;
	_DraWScreenHeader("Transactions Screen");

	system("cls");
	cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
	cout << setw(37) << left << "" << "\t     Transactions  Menue";
	cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
	cout << setw(37) << left << "" << "" << "\t[1] Deposit." << endl;
	cout << setw(37) << left << "" << "" << "\t[2] Withdraw." << endl;
	cout << setw(37) << left << "" << "" << "\t[3] Show Total Balances." << endl;
	cout << setw(37) << left << "" << "" << "\t[4] Transfer." << endl;
	cout << setw(37) << left << "" << "" << "\t[5] Transfer Log." << endl;
	cout << setw(37) << left << "" << "" << "\t[6] Show Main Menue." << endl;
	cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";

	cout << "\t\t\t\t\t"; _PerformTransactionsMenue((enTransactionsMenueOptions)_ReadTransActionsMenueOption());


	}
};

