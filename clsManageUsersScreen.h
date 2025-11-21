#pragma once
#include<iostream>
#include<iomanip>
#include "cslScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen :protected cslScreen
{
	static short _ReadManageUserMenue()
	{
		short Num;
		Num = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 and 6 ? ");
		return Num;

	}

	enum EnBankManageUsers
	{
		EnListUsers = 1,
		AddUsers = 2, DeleteUsers = 3,
		UpdateUsers = 4, FindUser = 5,
		MainMenue = 6
	};



	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUser();
	}
	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::UpDateUser();
	}
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserNameScreen();
	}
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::AddNewUser();
	}
	static void _GoBackToManageMenue()
	{
		system("pause>0");
		ShowManageUsersScreen();
	}
	static void GoBackTomainMeune()
	{

	}
	static void _ShowScreenListUsers()
	{
		clsListUsersScreen::ShowLitsUserScreen();
	}
	static void _PreformManageUser(EnBankManageUsers option)
	{

		switch(option)
		{
		case EnBankManageUsers::EnListUsers:
			system("cls");
			_ShowScreenListUsers();
			_GoBackToManageMenue();
			break;

		case EnBankManageUsers::AddUsers:
			system("cls");
				_ShowAddNewUserScreen();
			_GoBackToManageMenue();
			break;

		case EnBankManageUsers::DeleteUsers:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageMenue();
			break;
		case EnBankManageUsers::UpdateUsers:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageMenue();
			break;

		case EnBankManageUsers::FindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageMenue();
			break;
		case EnBankManageUsers::MainMenue:
				system("cls");
				GoBackTomainMeune();
				break;
		}

	}
public :


	static void ShowManageUsersScreen()
	{
		if (!cslScreen::CheckAccessRights(clsUser::enPermissions::pManageUsers))
			return;

		system("cls");
		_DraWScreenHeader("\tManage User Menue");
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
		cout << setw(37) << left << "" << "\t\tManage User Menue";
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
		cout << setw(37) << left << "" << "" << "\t[1] Show Users List." << endl;
		cout << setw(37) << left << "" << "" << "\t[2] Add New User." << endl;
		cout << setw(37) << left << "" << "" << "\t[3] Delete User." << endl;
		cout << setw(37) << left << "" << "" << "\t[4] Update User." << endl;
		cout << setw(37) << left << "" << "" << "\t[5] Find User." << endl;
		cout << setw(37) << left << "" << "" << "\t[6] Main Menue.";
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";

		_PreformManageUser((EnBankManageUsers)_ReadManageUserMenue());
	}



};

