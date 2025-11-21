#pragma once
#include <iostream>
using namespace std;
#include "Global.h"
#include "clsUser.h"
#include <ctime>
#include "clsDate.h"
class cslScreen
{
protected:

	static void _DrawLoginUsernameAndDate()
	{
		cout << "\t\t\t\t\t\t  " << "User:" << CurrentUser.UserName << endl;
		clsDate Date = clsDate::GetSystemDate();
		cout << "\t\t\t\t\t\t  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl << endl;

	}
	static void _DraWScreenHeader(string Title,string Suptitle="")
	{
		

		cout << "\t\t\t\t\t-----------------------------\n";
		cout << "\t\t\t\t\t " << Title << endl;
		if(Suptitle!="")
		{
			cout << "\n\t\t\t\t\t" << Suptitle;
		}
		cout << "\n\n\t\t\t\t\t-----------------------------\n";
		cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";

		_DrawLoginUsernameAndDate();

	}
	static bool CheckAccessRights(clsUser::enPermissions per)
	{
		if (!CurrentUser.CheckAccessPermissions(per))
		{
			cout << "\t\t\t\t\t-----------------------------\n";
			cout << "\t\t\t\t\t Access Denied\n";
			cout << "\n\n\t\t\t\t\t-----------------------------\n";
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
			return false;
		}
		else 
		{
			return true;
		}
	}
};

