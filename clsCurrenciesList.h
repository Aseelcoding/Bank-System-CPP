#pragma once
#include <iostream>
using namespace std;
#include "cslScreen.h"
#include<iomanip>
#include "clsCurrency.h"
#include <vector>
class clsCurrenciesList:protected cslScreen
{
	static void _PrintCurrenciesList(clsCurrency Currency)
	{
		cout << "| " << setw(30) << left << Currency.GetCountry();
		cout << "| " << setw(5) << left << Currency.GetCurrencyCode();
		cout << "| " << setw(30) << left << Currency.GetCurrencyName();
		cout << "| " << setw(6) << left << Currency.GetRate();
	}

public :
	static void ShowCurrenciesListScreen()
	{
	vector< clsCurrency>vclsCurrency=   clsCurrency::GetCurrneciesList();

	string Title = "\n\t\t\t\t\t    Currencies List Screen ";
	string Sup = "\t(" + to_string(vclsCurrency.size()) + ") Currnecy(s).";
	_DraWScreenHeader(Title, Sup);
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(30) << "Country";
	cout << "| " << left << setw(5) << "Code";
	cout << "| " << left << setw(30) << "Name";
	cout << "| " << left << setw(6) << "Rate/(1$)";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (clsCurrency &c: vclsCurrency)
	{
		_PrintCurrenciesList(c);
		cout << endl;
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	}


};

