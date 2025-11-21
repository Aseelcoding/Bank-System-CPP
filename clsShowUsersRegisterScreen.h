#pragma once
#include <iostream>
using namespace std;
#include "cslScreen.h"
#include<iomanip>
#include "clsUser.h"
#include "clsString.h"
class clsShowUsersRegisterScreen : protected cslScreen
{
private :
	static void _PrintUserRecordLine(clsUser::sLoginRecord LoginRecord)
	{
		cout << "| " << setw(20) << left << LoginRecord.DateAndTime;;
		cout << "| " << setw(20) << left << LoginRecord.USerName;
		cout << "| " << setw(20) << left << LoginRecord.Password;
		cout << "| " << setw(5) << left << LoginRecord.Permissions;
	}

public:
	static void ShowLitsUserScreen()
	{
		if (!cslScreen::CheckAccessRights(clsUser::enPermissions::pLoginRegisterScreen))
			return;


		vector <clsUser::sLoginRecord>vLoginRecord = clsUser::GetUsersLoginList();

		string Title = "\n\t\t\t\t\t\tUserslogin List ";
		string Sup = "\t(" + to_string(vLoginRecord.size()) + ") Users(s).";
		_DraWScreenHeader(Title, Sup);
		cout << "| " << left << setw(20) << " Date And Time";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(5) << "Permissions";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vLoginRecord.size() == 0)
			cout << "There is no Userslogin!\n";
		else
		{
			for (clsUser::sLoginRecord& User1 : vLoginRecord)
			{
				_PrintUserRecordLine(User1);
				cout << endl;
			}
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;




	}


};

