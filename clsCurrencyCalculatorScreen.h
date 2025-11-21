#pragma once
#include <iostream>
#include "cslScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen :protected cslScreen

{
private:

    static float _ReadAmount()
    {
     
        float Amount = 0;

        Amount = clsInputValidate<float>::ReadNumber("\nEnter Amount to Exchange: ");
        return Amount;
    }

    static clsCurrency _GetCurrency(string Message)
    {

        string CurrencyCode;
        CurrencyCode = clsInputValidate<short>::ReadString(Message);
        while (!clsCurrency::IsCurrnecyExist(CurrencyCode))
        {

            CurrencyCode = clsInputValidate<short>::ReadString("\nCurrency is not found, choose another one: ");
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;

    }


    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
    {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.GetCountry();
        cout << "\nCode          : " << Currency.GetCurrencyCode();
        cout << "\nName          : " << Currency.GetCurrencyName();
        cout << "\nRate(1$) =    : " << Currency.GetRate();
        cout << "\n_____________________________\n\n";

    }

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.GetCurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.GetCurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.GetCurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.GetCurrencyCode();

    }


public:
  
    static void ShowCurrencyCalculatorScreen()
    {
 
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");

            _DraWScreenHeader("\Exchange Currency Screen");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            float Amount = _ReadAmount();

            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;

        }


    }
};

