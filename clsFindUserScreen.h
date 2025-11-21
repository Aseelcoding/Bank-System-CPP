#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsFindUserScreen:protected cslScreen
{

private:	
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
	static void ShowFindUser()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		_DraWScreenHeader("     Find Username Screen");

		string UserName = "";
		UserName = clsInputValidate<float>::ReadString("Enter User Name ? ");
		while (!clsUser::IsUserExist(UserName))
		{

			UserName = clsInputValidate<float>::ReadString("this User Name not exist try again!");
		}

		clsUser User = clsUser::Find(UserName);

		if (User.IsEmpty())
		{
			cout << "User was not found";
		}
		else
		{
			cout << "\n\nWe found the Username successfully!\n";
			_PrintUserRecord(User);
		}





	}


};

