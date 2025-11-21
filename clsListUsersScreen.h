#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "clsUser.h"
#include "cslScreen.h"
class clsListUsersScreen: protected cslScreen
{

	static void _PrintUserRecordLine(clsUser User)
	{
		cout << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(15) << left << User.FullName();
		cout << "| " << setw(15) << left << User.Phone;
		cout << "| " << setw(15) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(3) << left << User.Permissions;
	}


public:
	static void ShowLitsUserScreen()
	{

		vector< clsUser>Users=clsUser::GetUsersList();

		string Title = "\n\t\t\t\t\t\tUsers List ";
		string Sup = "\t(" + to_string(Users.size()) + ") Users(s).";
		_DraWScreenHeader(Title, Sup);

		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(15) << "Full Name";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(15) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(3) << "Permissions";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (Users.size() == 0)
			cout << "There is no Users!\n";
		else
		{
			for (clsUser& User1 : Users)
			{
				_PrintUserRecordLine(User1);
				cout << endl;
			}
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;




	}



};

