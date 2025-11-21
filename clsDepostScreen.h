#pragma once
#include <iostream>
#include<iomanip>
using namespace std;
#include "cslScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
class clsDepostScreen:protected cslScreen
{

    static  string _ReadAccountNumber()
    {
        string AccountNumber;
 
        AccountNumber= clsInputValidate<double>::ReadString("Enter Account Number");
        return AccountNumber;
    }
	static void _PrintClientRecord(clsBankClient c)
	{
		cout << "\nCleint's info:\n\n";
		cout << "-----------------------------------------\n";
		cout << "First Name     : " << c.FirstName << endl;
		cout << "Last Name      : " << c.LastName << endl;
		cout << "Full Name      : " << c.FullName() << endl;
		cout << "Email          : " << c.Email << endl;
		cout << "Phone          : " << c.Phone << endl;
		cout << "Account Number : " << c.AccountNumber << endl;
		cout << "Pin Code       : " << c.PinCode << endl;
		cout << "Balance        : " << c.AccountBalance << endl;
		cout << "-----------------------------------------\n";

	}

public:
 static    void ShowDepositScreen()
    {
     cin.ignore(numeric_limits<streamsize>::max(), '\n');

        _DraWScreenHeader("\tDeposit Screen");

        string AccountNumber = "";

        AccountNumber = _ReadAccountNumber();
        char Answer;
        double DepositAmount;
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "There is No Account Number like this " << AccountNumber << " In Our System! Try Again\n";
            AccountNumber = _ReadAccountNumber();
        }  
        clsBankClient c = clsBankClient::Find(AccountNumber);
            _PrintClientRecord(c);
            DepositAmount = clsInputValidate<double>::ReadNumber("\n\nEnter deposit amount?\n");
            while (DepositAmount <= 0)
            {
                cout << "Please Enter amount more than 0!\n";
                DepositAmount = clsInputValidate<double>::ReadNumber("\n\nEnter deposit amount?\n");
            }
            char YorN = ' ';
            cout << "Confirm deposit? (y/n)\n";
            cin >> YorN;
            if (YorN == 'y' || YorN == 'Y')
            {
                clsBankClient::   EnSaveResult SaveResult;
                SaveResult= c.Deposit(DepositAmount);
               
                switch(SaveResult)
                {
                case clsBankClient::EnSaveResult::Successfull:
                    cout << "Done !!\n";
                    cout << "New Balance is :" << c.AccountBalance << endl << endl;
                    break;
                case clsBankClient::EnSaveResult::UnSuccessfull:
                    cout << "Unsuccessful operation \n";
                }
                   
            }
           else
        {
           cout << "Operation Cancelled !\n\n";
        }

            
            
         
    }


};

