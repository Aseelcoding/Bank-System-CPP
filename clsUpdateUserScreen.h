#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsUpdateUserScreen :protected cslScreen
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
	static 	void ReadUserData(clsUser & User)
	{
		User.FirstName = clsInputValidate<float>::ReadString("Enter First Name");
		User.LastName = clsInputValidate<float>::ReadString("Enter Last Name");
		User.Email = clsInputValidate<float>::ReadString("Enter Email");
		User.Phone = clsInputValidate<float>::ReadString("Enter Phone");
		User.Password = clsInputValidate<float>::ReadString("Enter Password");
		User.SetPermissions(User.Permissions);
	}




public :
	static void UpDateUser()
	{

		_DraWScreenHeader("    Update User Screen");

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string UserName;

		UserName = clsInputValidate<double>::ReadString("Enter User Name");

		while (!clsUser::IsUserExist(UserName))
		{
			UserName = clsInputValidate<double>::ReadString("Try Again please!");
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUserRecord(User);
		cout << "Update User Info\n\n";
		cout << "------------------------------\n";

		ReadUserData(User);
		clsUser::EnSaveResult SaveResult;
		SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::EnSaveResult::Successful:
			cout << "Updated Successfully!\n";
			_PrintUserRecord(User);
			break;
		case clsUser::EnSaveResult::Unsuccessful:
			cout << "unSuccessful Operation!\n";
		}


	}
};

