#pragma once
#include<iostream>
#include<iomanip>
#include "cslScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientsListScreen.h"
#include "clsAddNewScreen.h"
#include "clsDeleteClientScreen.h"
#include "ShowUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsShowUsersRegisterScreen.h"
#include "clsCurrencyScreen.h"

using namespace std;
class clsMainScreen:protected cslScreen
{
	
private :
	private :
	enum enMainMenueOptions{enShowClients=1
		,enAddNewClient=2,enDeleteNew=3
		,enUpdateClient=4,enFindClient=5
		,enTransaction=6,ManageUsers=7
		,LoginRegister=8,enCurrencies=9,
		enExit=10
	
	};

	static short _ReadMainMenueOption()
	{
		short Num;
		Num = clsInputValidate<short>::ReadNumberBetween(1, 10, "Enter Number between 1 and 10 ? ");
		return Num;

	}
	static void _ShowClientsListScreen()
	{
		clsClientsListScreen::ShowClientsList();
	
	}
	static void _ShowAddNewScreen()
	{
		clsAddNewScreen::AddNewClient();

	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteCleintScreen();
	}
	static void _ShowUpdateScreen()
	{
		ShowUpdateClientScreen::UpDateClient();
	}
	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClient();
	}
	static void _ShowTransactionMenue()
	{
		clsTransactionsScreen::ShowTrasactionsScreen();
	}
	static void _ShowManageUserMenue()
	{
		clsManageUsersScreen::ShowManageUsersScreen();
	}
	static void _ShowEndScreen()
	{
		CurrentUser.Find(" ", " ");
	}
	static void _GoBackToMainMeue()
	{
		system("pause>0");
		ShowMainMenue();
	}
	static void _ShowLogingRegister()
	{
		clsShowUsersRegisterScreen::ShowLitsUserScreen();

	}
	static void _ShowCurrneciesExchangeScreen()
	{
		clsCurrencyScreen::ShowCurrneciesExcgangeScreen();

	}
	static void _PerformMainMenueOption(enMainMenueOptions MainMenueOptions)
	{
		switch(MainMenueOptions)
		{
		case enMainMenueOptions::enShowClients:
			system("cls");
			_ShowClientsListScreen();
			_GoBackToMainMeue();
			break;
		case enMainMenueOptions::enAddNewClient:
			system("cls");
			_ShowAddNewScreen();
			_GoBackToMainMeue();
			break;
		case enMainMenueOptions::enDeleteNew:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMeue();
			break;
			case enMainMenueOptions::enUpdateClient:
			system("cls");
			_ShowUpdateScreen();
			_GoBackToMainMeue();
			break;
			case enMainMenueOptions::enFindClient:
				system("cls");
				_ShowFindClientScreen();
				_GoBackToMainMeue();
				break;
			case enMainMenueOptions::enTransaction:
				system("cls");
				_ShowTransactionMenue();
				_GoBackToMainMeue();
				break;
				case enMainMenueOptions::ManageUsers:
				system("cls");
				_ShowManageUserMenue();
				_GoBackToMainMeue();
				break;
				case enMainMenueOptions::LoginRegister:
					system("cls");
					_ShowLogingRegister();
					_GoBackToMainMeue();
					break;
				case enMainMenueOptions::enCurrencies:
					system("cls");
					_ShowCurrneciesExchangeScreen();
					_GoBackToMainMeue();
					break;

				case enMainMenueOptions::enExit:
					system("cls");
					_ShowEndScreen();
					break;

		}
	}

public:
	static void ShowMainMenue()
	{
		system("cls");
		_DraWScreenHeader("\t  Main Menue");
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
		cout << setw(37) << left << "" << "\t\t  Main Menue";
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
		cout << setw(37) << left << "" << "" << "\t[1] Show Clints List." << endl;
		cout << setw(37) << left << "" << "" << "\t[2] Add New Clints." << endl;
		cout << setw(37) << left << "" << "" << "\t[3] Delete Clints." << endl;
		cout << setw(37) << left << "" << "" << "\t[4] Update Clints." << endl;
		cout << setw(37) << left << "" << "" << "\t[5] Find Clints." << endl;
		cout << setw(37) << left << "" << "" << "\t[6] Transaction." << endl;
		cout << setw(37) << left << "" << "" << "\t[7] Manage Users." << endl;
		cout << setw(37) << left << "" << "" << "\t[8] Loging Register." << endl;
		cout << setw(37) << left << "" << "" << "\t[9] Currency Exchange." << endl;
		cout << setw(37) << left << "" << "" << "\t[10] Logout.";
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
		cout << "\t\t\t\t\t"; _PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
	
};

