#pragma once
#include <iostream>
using namespace std;
#include "cslScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen :protected cslScreen
{
private:
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
	enum FindBy
	{
		CurrencyCode = 1,
		Country = 2
	};
	static FindBy ReadOption()
	{
		short Number = clsInputValidate<short>::ReadNumberBetween(1, 2, "Find By:[1] Code or [2] Country ?");
		return (FindBy)Number;

	}


public:

	static void ShowFindCurrencyScreen()
	{
		_DraWScreenHeader("Find Currency Screen");

		FindBy Op = ReadOption();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (Op)
		{
		case FindBy::CurrencyCode:
		{
			string Code = clsInputValidate<float>::ReadString("Enter The Code ?");
			clsCurrency c = clsCurrency::FindByCode(Code);
			if (c.IsEmpty())
			{
				cout << "We Could not find the code try again\n";
				break;
			}
			else
			{
				_PrintCurrency(c);
				break;
			}
		}
			break;
		case FindBy::Country:
		{
			string Country = clsInputValidate<float>::ReadString("Enter The Country ?");
			clsCurrency c = clsCurrency::FindByCountry(Country);
			if (c.IsEmpty())
			{
				cout << "We Could not find the Country try again\n";
				break;
			}
			else
			{
				_PrintCurrency(c);
				break;
			}
		}
		}
	}
};

