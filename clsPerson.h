#pragma once
#include <iostream>
using namespace std;
#include "InterfaceComunication.h"
class clsPerson : public InterfaceComunication
{
private :
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
	
public:
	//
	clsPerson(string FirstName,string LastName,string Email,string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;

	}

	//Set And Get ::
	//
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;

	}
	string GetFirstName()
	{
		return _FirstName;
	}
	string FullName()
	{
		return _FirstName + " " + LastName;
	}
	//
	void SetLastName(string LastName)
	{
		_LastName = LastName;

	}
	string GetLastName()
	{
		return _LastName;
	}

	//
	void SetPhone(string Phone)
	{
		_Phone = Phone;

	}
	string GetPhone()
	{
		return _Phone;
	}

	//
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}
	//
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
	//
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;
	//
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;
	//
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;
	//

	//Function To Print Person Data : 
	void Print()
	{
		cout << "First Name :" << FirstName << endl;
		cout << "Last Name :" << LastName << endl;
		cout << "Phone :" << Phone << endl;
		cout << "Email :" << Email << endl;


	}


	//Contract
	void SendEmail(string Title,string Body)
	{

	}
	void SendSMS(string Title,string Body)
	{

	}
	void SendFax(string Title,string Body)
	{

	}

};

