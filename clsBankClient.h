#pragma once
#include <iostream>
#include<string>
#include "clsString.h"
#include "clsPerson.h"
#include <fstream>
#include  "clsDate.h"
using namespace std;
const string FileName = "Clients.txt";
class clsBankClient:public clsPerson 
{
public :
	struct stTransferRecord
	{
		string Date;
		string AccountNumber1;
		string AccountNumber2;
		double AmountOfMoney;
		double Balance1;
		double Balance2;
		string UserName;

	};


	enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewClient=3 };
private :
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	  enMode _Mode;
	  bool MarkForDelete = false;
	//Functions

	  
	static clsBankClient _ConvertLinetoClientObject(string Line,string Speratoer="#//#")
	{
		vector <string>vData;
		vData = clsString::Split(Line, Speratoer);
		clsBankClient client(enMode::UpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stod(vData[6]));
		 return client;
	}
	static vector<clsBankClient> _LoadClientsDataFromFile( string Speratoer = "#//#")
	{
		vector< clsBankClient>clients;
		fstream ClinetsFile(FileName, ios::in);

		if (ClinetsFile.is_open())
		{
			string Line;
			vector<string>Record;
			while(getline(ClinetsFile, Line))
			{

				clients.push_back(_ConvertLinetoClientObject(Line));

			}

			ClinetsFile.close();
		}

		return clients;
	}
	string _ConverClientObjectToLine(clsBankClient Client)
	{
		string Line;
		Line = Client.FirstName + "#//#" + Client.LastName + "#//#" + Client.Email + "#//#" + Client.Phone + "#//#" + Client.GetAccountNumber() + "#//#" + Client.PinCode + "#//#" + to_string(Client.AccountBalance);
		return Line;
	}
    void _SaveCleintsDataToFile(vector< clsBankClient>Clients)
{
		fstream ClientsFile(FileName, ios::out);
		string line;
		if (ClientsFile.is_open())
		{
			for (clsBankClient &c: Clients)
			{
				if (c.MarkForDelete == false) 
				{
					line = _ConverClientObjectToLine(c);
					ClientsFile << line << endl;
				}
			}
			ClientsFile.close();

		}
	
}
	void _Update()
	{
		vector<clsBankClient> Clinets;
		Clinets = _LoadClientsDataFromFile();

		for (clsBankClient &c: Clinets)
		{
			if (c.AccountNumber == AccountNumber)
			{
				c = *this;
				break;
			}


		}
		_SaveCleintsDataToFile(Clinets);


	}
	void _AddLineTofile(string Line)
	{
		fstream ClientsFile(FileName, ios::app);
		
		if (ClientsFile.is_open())
		{
				ClientsFile << Line << endl;
			ClientsFile.close();

		}
	}
	void _AddNew()
	{
		_AddLineTofile(_ConverClientObjectToLine(*this));

	}
	//Register Transfers Record
static 	string _ConverTransferRecordToLine(clsBankClient Client1, clsBankClient Client2,double AmountOfMoney)
	{
		string Line;
		Line = clsDate::GetSystemDateTimeString()
			+ "#//#" + Client1.AccountNumber 
			+ "#//#" + Client2.AccountNumber
			+ "#//#" + to_string(AmountOfMoney)
			+ "#//#" + to_string(Client1.AccountBalance) 
			+ "#//#" + to_string(Client2.AccountBalance)
			+ "#//#" + CurrentUser.UserName;
		return Line;
	}
static 	void _AddLineToTransferfile(string Line)
	{
		fstream ClientsFile("TransferLog", ios::app);

		if (ClientsFile.is_open())
		{
			ClientsFile << Line << endl;
			ClientsFile.close();

		}
	}
static void _RegisterTransferLog(clsBankClient Client1, clsBankClient Client2, double AmountOfMoney)
{
	_AddLineToTransferfile(_ConverTransferRecordToLine(Client1, Client2, AmountOfMoney));

}
static  stTransferRecord _ConvertLineToRecord(string Line,string Speratoer="#//#")
{
	vector <string > vData = clsString::Split(Line, Speratoer);
	stTransferRecord Record;
	Record.Date = vData[0];
	Record.AccountNumber1 = vData[1];
	Record.AccountNumber2 = vData[2];
	Record.AmountOfMoney = stod(vData[3]);
	Record.Balance1 = stod(vData[4]);
	Record.Balance2 = stod(vData[5]);
	Record.UserName = vData[6];
	return Record;

}
 static vector< stTransferRecord>_LoadTransferHistoryFromFile()
 {
	 vector< stTransferRecord> VstTransferRecord;

	 fstream TransferLog;
	 TransferLog.open("TransferLog", ios::in);

	 if (TransferLog.is_open())
	 {

		 string Line;
		 while (getline(TransferLog, Line))
		 {
			 VstTransferRecord.push_back(_ConvertLineToRecord(Line));

		 }

		 TransferLog.close();

	 }

	 return VstTransferRecord;
 }

public:
	clsBankClient(enMode Mode,string FirstName,string LastName, string Email,  string Phone, string AccountNumber,string PinCode, double AccountBalance):
		clsPerson(FirstName, LastName, Phone,Email)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;


	}
	// AcoountNumber You can only get it you cannot set it .
	string GetAccountNumber()
	{
		return _AccountNumber;

	}
	__declspec(property(get = GetAccountNumber))string AccountNumber;
	
	//
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	//
	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))double AccountBalance;

	//
	  bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	static clsBankClient GetEmptyopj()
	{
		clsBankClient c(enMode::EmptyMode, "", "", "", "", "", "", 0);
		return c;
	}

	//
	static clsBankClient Find(string AccountNumber)
	{
		

		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open())
		{
			string line;
			while(getline(MyFile,line))
			{
				clsBankClient c=	_ConvertLinetoClientObject(line);
				if(c.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return c;
				}
			}
			MyFile.close();

		}
		return GetEmptyopj();

	}
	static clsBankClient Find(string AccountNumber,string PinCode)
	{

		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsBankClient c = _ConvertLinetoClientObject(line);
				if (c.AccountNumber == AccountNumber&&c.PinCode==PinCode)
				{
					MyFile.close();
					return c;
				}
			}
			MyFile.close();

		}
		return GetEmptyopj();


	}


	//
	static bool IsClientExist(string AccountNumber)
	{
	
		clsBankClient client = clsBankClient::Find(AccountNumber);
		return (!client.IsEmpty());

	}
	//
	/*void Print()
	{
		cout << "\nCleint's info:\n\n";
		cout << "-----------------------------------------\n";
		cout << "First Name     : " << FirstName << endl;
		cout << "Last Name      : " << LastName << endl;
		cout << "Full Name      : " << FullName() << endl;
		cout << "Email          : " << Email << endl;
		cout << "Phone          : " << Phone << endl;
		cout << "Account Number : " << _AccountNumber << endl;
		cout << "Pin Code       : " << _PinCode << endl;
		cout << "Balance        : " << _AccountBalance << endl;
		cout << "-----------------------------------------\n";


	}*/
	

	//
	static clsBankClient GetAddNewClinet(string AccountNmber)
	{
		return clsBankClient(enMode::AddNewClient, "", "", "", "", AccountNmber, "", 0);
	}


	enum EnSaveResult{UnSuccessfull=0,Successfull=1,svFaildAccountNumberExist=3,Error=4};

	EnSaveResult Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
			return EnSaveResult::UnSuccessfull;
			
			
			
		case enMode::UpdateMode:

			_Update();
			return Successfull;

		case enMode::AddNewClient:

			if(clsBankClient::IsClientExist(_AccountNumber))
			{
				return EnSaveResult::svFaildAccountNumberExist;
			}
			else
			{

				_AddNew();
				_Mode = enMode::UpdateMode;
				return EnSaveResult::Successfull;

			}
		}



	}

	bool Delete()
	{
		vector < clsBankClient> vclinets;

		vclinets = _LoadClientsDataFromFile();
		for (clsBankClient &c: vclinets)
		{
			if (c.AccountNumber==AccountNumber)
			{
				c.MarkForDelete = true;
				break;
			}
		}
		_SaveCleintsDataToFile(vclinets);
		*this = GetEmptyopj();
		return true;

	}

	static vector<clsBankClient>GetClientsLest()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		double Total = 0;

		vector<clsBankClient> vclients = _LoadClientsDataFromFile();

		for (clsBankClient &c: vclients)
		{
			Total = c.AccountBalance + Total;
		}
		return Total;
	}

	EnSaveResult Deposit(double Amount)
{
	AccountBalance = AccountBalance + Amount;

	clsBankClient::EnSaveResult SaveResult;

	SaveResult = Save();

	return SaveResult;

}
	EnSaveResult Withdraw(double Amount)
	{
		AccountBalance = AccountBalance - Amount;

		clsBankClient::EnSaveResult SaveResult;
		if(Amount> AccountBalance)
		{
			return EnSaveResult::UnSuccessfull;
		}
		else 
		{

			SaveResult = Save();

			return SaveResult;

		}


	}

	//Transfer Functions
	static EnSaveResult TransferMoney(clsBankClient &Client1, clsBankClient &Client2,double AmountOfMoney)
	{
		if (Client1.AccountBalance==0)
		{
			return EnSaveResult::Error;
		}

		while (Client1.AccountBalance< AmountOfMoney)
		{
			AmountOfMoney = clsInputValidate<double>::ReadNumber("	Please enter a transfer amount that is equal to or less than your available balance. \nEnter amount of money to transfer\n");
		}
	
		Client1.AccountBalance = Client1.AccountBalance - AmountOfMoney;
		Client2.AccountBalance = Client2.AccountBalance + AmountOfMoney;
	

		if (Client1.Save()== EnSaveResult::Successfull&& Client2.Save() == EnSaveResult::Successfull)
		{
			_RegisterTransferLog(Client1, Client2, AmountOfMoney);
			return EnSaveResult::Successfull;
			//Write this operation in file 
			

		}
		else 
		{
			EnSaveResult::UnSuccessfull;
		}

	}

//Show transfer log 


	static vector< stTransferRecord> GetTransferHistory()
	{

		return _LoadTransferHistoryFromFile();


	}

};

