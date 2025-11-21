#pragma once
#include <iostream>
using namespace std;
#include "cslScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include"Global.h"
#include "GlobalCountre.h"

class clsLoginScreen:protected cslScreen
{
protected :



private :

	
	static bool _Login()
	{
		Countre = 3;
		bool LoginFaild = false;

		string UserName, Password;
		do 
		{
			UserName = clsInputValidate<short>::ReadString("Enter User Name");
			Password= clsInputValidate<short>::ReadString("Enter Password");

			 CurrentUser = clsUser::Find(UserName, Password);
			 
				if(CurrentUser.IsEmpty())
				{
					LoginFaild = true;

				}
				else 
				{
					LoginFaild = false;
				}
				if (LoginFaild)
				{
		 		cout << "Login Faild try again\n\n";
				}
				if(LoginFaild)
				{
					Countre = Countre -1;
				}
				cout << "You Have " << Countre << " Tries to login\n\n";

				if (Countre==0)
				{
					return false;
				
				}

		} while (LoginFaild);

		CurrentUser.WriteUserLog();
		clsMainScreen::ShowMainMenue();


	}

public:
	static bool ShowLogingScreen()
	{
		system("cls");
		_DraWScreenHeader("\t  Login Screen");
		return	_Login();
	}

};

