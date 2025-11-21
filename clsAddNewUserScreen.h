#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsAddNewUserScreen : protected cslScreen
{
private :
	
	static void _PrintClientRecord(clsUser User)
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
	static 	void ReadUserData(clsUser& User)
	{
		User.FirstName = clsInputValidate<float>::ReadString("Enter First Name");
		User.LastName = clsInputValidate<float>::ReadString("Enter Last Name");
		User.Email = clsInputValidate<float>::ReadString("Enter Email");
		User.Phone = clsInputValidate<float>::ReadString("Enter Phone");
		User.Password = clsInputValidate<float>::ReadString("Enter Password");
	
	}

public :
	static void AddNewUser()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		_DraWScreenHeader("   Add New User Screen");



		string UserName = " ";

		UserName = clsInputValidate<double>::ReadString("Enter User Name");

		while (clsUser::IsUserExist(UserName))
		{
			UserName = clsInputValidate<double>::ReadString("This User Name is Already Exist! try again");
		}

		clsUser NewUser = clsUser::GetAddNewUser(UserName);
		cout << "\nRead New User\n\n";
		cout << "------------------------------\n";
		ReadUserData(NewUser);
		clsUser::EnSaveResult SaveResult;
		SaveResult = NewUser.Save();
		switch (SaveResult)
		{
		case  clsUser::EnSaveResult::Successful:
			cout << "Add new User done successfuly\n";
			_PrintClientRecord(NewUser);
			break;
		case clsUser::EnSaveResult::Unsuccessful:
			cout << "unSuccessful Operation!\n";
			break;
		case clsUser::EnSaveResult::svFailedAccountNumberExist:
			cout << "unSuccessful Operation Because this User name already exist!\n";
			break;

		}
	}
};

