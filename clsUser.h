#pragma once
#include <iostream>
#include<string>
#include "clsString.h"
#include "clsPerson.h"
#include <fstream>
#include "clsUtil.h"
#include "clsDate.h"
using namespace std;

class clsUser :public clsPerson
{
private:
	static  	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;
	string DateAndTime;
	static clsUser _ConvertLineToClientObject(string Line, string Separator = "#//#")

	{
	vector <string>vData;
	vData = clsString::Split(Line, Separator);

string Password=	clsUtil::DecryptText(vData[5], 1);

		clsUser User(enMode::UpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], Password, stoi(vData[6]));
		return User;

	}
	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector< clsUser>Users;
		fstream UsersFile("Users.txt", ios::in);

		if (UsersFile.is_open())
		{
			string Line;
			while (getline(UsersFile, Line))
			{

				Users.push_back(_ConvertLineToClientObject(Line));

			}

			UsersFile.close();
		}

		return Users;
	}
	string _ConvertUserObjectToLine(clsUser User)
	{
	string Password=	clsUtil::EncryptText(User.Password, 1);

		string Line;

		Line = User.FirstName + "#//#" + User.LastName + "#//#" + User.Email + "#//#" + User.Phone + "#//#" + User.UserName + "#//#" + Password + "#//#" + to_string(User.Permissions);

		return Line;
	}
	void _SaveUsersDataToFile(vector< clsUser>Users)
	{
		fstream UserFile("Users.txt", ios::out);
		string line;
		if (UserFile.is_open())
		{
			for (clsUser& User1 : Users)
			{
				if ((User1._MarkedForDelete == false))
				{
					line = _ConvertUserObjectToLine(User1);
					UserFile << line << endl;
				}
			}
			UserFile.close();

		}

	}
	void _Update()
	{
		vector<clsUser> Users;
		Users = _LoadUsersDataFromFile();

		for (clsUser& Users1 : Users)
		{
			if (Users1._UserName == _UserName)
			{
				Users1 = *this;
				break;
			}


		}
		_SaveUsersDataToFile(Users);


	}
	 
	void AddLineToFile(string Line)
	{
		fstream UsersFile("Users.txt", ios::app);

		if (UsersFile.is_open())
		{
			UsersFile << Line << endl;
			UsersFile.close();

		}
	}
	void _AddNew()
	{
		AddLineToFile(_ConvertUserObjectToLine(*this));

	}
	/////////////////////
	string  _PrepareLogInRecord()
	{
		string Line;
		Password= clsUtil::EncryptText(Password, 1);
		Line = clsDate::GetSystemDateTimeString()+"#//#" +UserName + "#//#" + Password + "#//#" + to_string(_Permissions);
		return Line;

	}
	struct sLoginRecord;
	static sLoginRecord _ConvertLoginRegisterLineToRecord(string Line)
	{
		sLoginRecord LoginRecord;
		vector <string>vData = clsString::Split(Line, "#//#");
		vData[2] = clsUtil::DecryptText(vData[2], 1);

		LoginRecord.DateAndTime = vData[0];
		LoginRecord.USerName = vData[1];
		LoginRecord.Password = vData[2];
		LoginRecord.Permissions = stoi(vData[3]);
		return LoginRecord;
	}
public:
	struct sLoginRecord
	{
		string DateAndTime;
		string USerName;
		string Password;
		int Permissions;

	};

	void SetDateAndTime(string newDateTime)
	{
		DateAndTime = newDateTime;
	}
	string GetDateAndTime()
	{
		return DateAndTime;
	}

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions = -1 ) :clsPerson
	(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions=Permissions;
	
	}

	//Set And Get UserName
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	//Set And Get Password
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	//Set and Get for Permissions
	void SetPermissions(int Permissions)
	{
		char Answer;
		int Per = 0;
		cout << "Do You Want To Give This User Full Access ? \n"; cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Per = -1;
			this->_Permissions = Per;
			return;

		}
		else {
			cout << "Show Client List ? y/n\n"; cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Per = 1 + Per;
			}
			cout << "Add Client  ? y/n\n"; cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Per = 2 + Per;
			}
			cout << "Delete Client  ? y/n\n"; cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Per = 4 + Per;
			}
			cout << "Update Client  ? y/n\n"; cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Per = 8 + Per;
			}
			cout << "Find Client  ? y/n\n"; cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Per = 16 + Per;
			}
			cout << "Transactions ? y/n\n"; cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Per = 32 + Per;
			}
			cout << "ManageUsers ? y/n\n"; cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Per = 64 + Per;
			}
			cout << "Show Login Register ? y/n\n"; cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				Per = 128 + Per;
			}
			this->_Permissions = Per;

		}
	}
		int GetPermission()
		{
			return _Permissions;
		}
		__declspec(property(get = GetPermission, put = SetPermissions))int Permissions;


		//
		string FullName()
		{
			return FirstName + " " + LastName;
		}


		//
		bool IsEmpty()
		{
			return (_Mode == enMode::EmptyMode);
		}
		static clsUser GetEmptyObj()
		{
			clsUser c(enMode::EmptyMode, "", "", "", "", "", "", -1);
			return c;
		}

		//
		static clsUser Find(string UserName)
		{


			fstream UserFile;
			UserFile.open("Users.txt", ios::in);


			if (UserFile.is_open())
			{
				string line;
				while (getline(UserFile, line))
				{
					clsUser User = _ConvertLineToClientObject(line);
					if (User.UserName == UserName)
					{
						UserFile.close();
						return User;
					}
				}
				UserFile.close();
			}

			else
			{
				cout << "Problem during opening the file\n";
				system("pause>0");

			}
			return GetEmptyObj();

		}
		static clsUser Find(string UserName, string Password)
		{

			fstream MyFile;
			MyFile.open("Users.txt", ios::in);
			if (MyFile.is_open())
			{
				string line;
				while (getline(MyFile, line))
				{
					clsUser User = _ConvertLineToClientObject(line);
					if (User.UserName == UserName && User.Password == Password)
					{
						MyFile.close();
						return User;
					}
				}
				MyFile.close();

			}
			return GetEmptyObj();


		}

		//
		static bool IsUserExist(string UserName)
		{

			clsUser client = clsUser::Find(UserName);
			return (!client.IsEmpty());

		}

		//
		static clsUser GetAddNewUser(string UserName)
		{
			return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", -1);
		}

		enum EnSaveResult { Unsuccessful = 0, Successful = 1, svFailedAccountNumberExist = 3 };

		EnSaveResult Save()
		{

			switch (_Mode)
			{
			case enMode::EmptyMode:
				return EnSaveResult::Unsuccessful;

			case enMode::UpdateMode:

				_Update();
				return Successful;

			case enMode::AddNewMode:

				if (clsUser::IsUserExist(UserName))
				{
					return EnSaveResult::svFailedAccountNumberExist;
				}
				else
				{

					_AddNew();
					_Mode = enMode::UpdateMode;
					return EnSaveResult::Successful;

				}
			}



		}

		bool Delete()
		{
			vector < clsUser> Users;

			Users = _LoadUsersDataFromFile();
			for (clsUser& UserTemp : Users)
			{
				if (UserTemp.UserName == GetUserName() && UserTemp.FirstName == FirstName)
				{
					UserTemp._MarkedForDelete = true;
					break;
				}
			}
			_SaveUsersDataToFile(Users);
			*this = GetEmptyObj();
			return true;

		}

		static vector<clsUser>GetUsersList()
		{
			return _LoadUsersDataFromFile();
		}
		static vector<sLoginRecord>GetUsersLoginList()
		{
			vector<sLoginRecord> vsLoginRecord;

			fstream  MyFile;
			MyFile.open("LogFile.txt", ios::in);
	if (MyFile.is_open())
	{
		string Line;
		sLoginRecord LoginRecord;
		while(getline(MyFile,Line))
		{
			LoginRecord = _ConvertLoginRegisterLineToRecord(Line);

			vsLoginRecord.push_back(LoginRecord);
		}

	}
	return vsLoginRecord;
		}

		enum enPermissions
		{
			pAll = -1,
			pShowClients = 1,
			pAddNewClients = 2,
			pDeleteClients = 4,
			pUpdateClient = 8,
			pFindClient = 16,
			pTransactions = 32,
			pManageUsers = 64,
			pLoginRegisterScreen = 128

		};

		bool CheckAccessPermissions(enPermissions ePermissions)
		{
			if (ePermissions == enPermissions::pAll)
				return true;

			if ((this->_Permissions & ePermissions) == ePermissions)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		 void WriteUserLog()
		{
			string Line= _PrepareLogInRecord();
			 fstream UsersFile("LogFile.txt",ios::out | ios::app);

			 if (UsersFile.is_open())
			 {
				 UsersFile << Line << endl;
				 UsersFile.close();

			 }
			 
		}
		


	};
