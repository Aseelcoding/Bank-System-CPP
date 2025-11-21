#pragma once
#include <iostream>
using namespace std;
#include "cslScreen.h"
#include<iomanip>
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsCurrenciesList.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyScreen:protected cslScreen
{
	enum enCurrencyOptions
	{
		eListCurrencies=1,
		eFindCurrency=2,
		eUpdateCurrency=3,
		eCurrencyCalculator=4,
		eMainMenue=5
	};

	//
	static void _GoBackToMainMeue()
	{


	}
	static void _GoBackToCurrencyScreen()
	{
		system("pause>0");
		ShowCurrneciesExcgangeScreen();
	}
	static short _ReadMainMenueOption()
	{
		short Num;
		Num = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 and 5 ? ");
		return Num;

	}
	//done
	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesList::ShowCurrenciesListScreen();
	}
	//done
	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	//done
	static void _ShowUpdateCurrencyScreen()
	{
		clsUpdateRateScreen::ShowUpdatCurrencyRateScreen();
	}
	//
	static void _ShowCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	//
	static void _PerformMainMenueOption(enCurrencyOptions CurrencyOptions)
	{
		switch(CurrencyOptions)
		{
		case enCurrencyOptions::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyScreen();
			break;
		case enCurrencyOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyScreen();
			break;
		case enCurrencyOptions::eUpdateCurrency:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyScreen();
			break;
		case enCurrencyOptions::eCurrencyCalculator:
			system("cls");
			_ShowCalculatorScreen();
			_GoBackToCurrencyScreen();
			break;
			case enCurrencyOptions::eMainMenue:
			system("cls");
			_GoBackToMainMeue();
			break;
		}
	}
public :
	static void ShowCurrneciesExcgangeScreen()
	{
		system("cls");
		cslScreen::_DraWScreenHeader("Currency Exchange Main Screen");
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
		cout << setw(37) << left << "" << "\t    Currency Exchange Menue";
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";
		cout << setw(37) << left << "" << "" << "\t[1] List Currnecies." << endl;
		cout << setw(37) << left << "" << "" << "\t[2] Find Currency." << endl;
		cout << setw(37) << left << "" << "" << "\t[3] Update Rate." << endl;
		cout << setw(37) << left << "" << "" << "\t[4] Currency Calculator." << endl;
		cout << setw(37) << left << "" << "" << "\t[5] Main Menue.";
		cout << setw(37) << left << "" << "\n\t\t\t\t\t=============================\n";

		cout << "\t\t\t\t\t";	_PerformMainMenueOption((enCurrencyOptions)_ReadMainMenueOption());


	}


};

