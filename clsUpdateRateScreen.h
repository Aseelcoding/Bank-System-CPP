#pragma once
#include <iostream>
using namespace std;
#include "cslScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsUpdateRateScreen:protected cslScreen
{

	static void _PrintCurrency(clsCurrency c)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << c.GetCountry();
		cout << "\nCode       : " << c.GetCurrencyCode();
		cout << "\nName       : " << c.GetCurrencyName();
		cout << "\nRate(1$) = : " << c.GetRate();
		cout << "\n_____________________________\n";
	}

public :
	static void ShowUpdatCurrencyRateScreen()
	{
		_DraWScreenHeader("   Update Currnecy Screen");

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string Code = clsInputValidate<float>::ReadString("Please enter currency code :");
		clsCurrency c = clsCurrency::FindByCode(Code);
		while(c.IsEmpty())
		{
			cout << "Wrong Code try again\n\n";
			 Code = clsInputValidate<float>::ReadString("Please enter currency code :");
			 c = clsCurrency::FindByCode(Code);
		}
		_PrintCurrency(c);

		float NewRate = clsInputValidate<float>::ReadNumber("Enter the new rate");;
		c.UpdateRate(NewRate);

		if(c.GetRate()== NewRate)
		{
			cout << "\n\nDone sucessfully\n\n";
			_PrintCurrency(c);
		}
		else 
		{
			cout << "Error,try again later\n\n";

		}

	}


};

