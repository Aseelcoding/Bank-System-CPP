
#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsDeleteUserScreen:protected cslScreen
{
private :
	static void _PrintUserRecord(clsUser User)
	{
		cout << "\tUser's info:\n\n";
		cout << "-----------------------------------------\n";
		cout << "First Name     : " << User.FirstName << endl;
		cout << "Last Name      : " << User.LastName << endl;
		cout << "Full Name      : " << User.FullName() << endl;
		cout << "Email          : " << User.Email << endl;
		cout << "Phone          : " << User.Phone << endl;
		cout << "User Name      : " << User.UserName << endl;
		cout << "Password       : " << User.Password << endl;
		cout << "Permissions    : " << User.Permissions << endl;
		cout << "-----------------------------------------\n";

	}


public :
	static void ShowDeleteUserNameScreen()
	{

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string UserName;

		_DraWScreenHeader("   Detele User Screen");


		UserName = clsInputValidate<double>::ReadString("Enter User Name");

		while (!clsUser::IsUserExist(UserName))
		{
			UserName = clsInputValidate<double>::ReadString("there is no User Name like this,try again please ");
		}
		clsUser User = clsUser::Find(UserName);

		_PrintUserRecord(User);
		char answer;
		cout << "Are You sure that you want to delete this User? enter y/n\n";
		cin >> answer;
		if (answer == 'n' || answer == 'N')
		{
			return;
		}
		
		switch (User.Delete())
		{
		case true:

			cout << "Delete User done successfully\n";
			_PrintUserRecord(User);
			system("pause");
			break;
		case false:
			cout << "Unsucessful operation\n";
			break;
		}

	}

};

