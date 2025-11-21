#pragma once
#include <iostream> 
#include <vector>
#include "clsString.h"
#include <string>
#include <fstream>
using namespace std;


class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	//
	static clsCurrency _ConvertLineToCurrencyOpject(string Line)
	{
		vector <string >vData;
		vData = clsString::Split(Line, "#//#");

		clsCurrency C(enMode::UpdateMode, vData[0], vData[1], vData[2], stof(vData[3]));
		return C;
	}
	static string _ConvertCurrencyOpjectToLine(clsCurrency C)
	{
		string Line;
		Line = C._Country + "#//#" + C._CurrencyCode + "#//#" + C._CurrencyName + "#//#" + to_string(C._Rate);
		return Line;
	}
	static vector< clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector< clsCurrency> vclsCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				vclsCurrency.push_back(_ConvertLineToCurrencyOpject(Line));

			}
			MyFile.close();
		}

		return vclsCurrency;
	}
	static void  _SafeCurrencyDataToFile(vector< clsCurrency> vclsCurrency)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency& c : vclsCurrency)
			{
				string Line;
				Line = _ConvertCurrencyOpjectToLine(c);
				MyFile << Line << endl;

			}
			MyFile.close();

		}


	}
	void _Update()
	{
		vector< clsCurrency>_VclsCurrenc = _LoadCurrencyDataFromFile();

		for (clsCurrency& c : _VclsCurrenc)
		{

			if (c.GetCurrencyCode() == GetCurrencyCode())
			{
				c = *this;
				break;
			}

		}
		_SafeCurrencyDataToFile(_VclsCurrenc);



	}

public:
	//
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}
	//
	bool IsEmpty()
	{
		return (this->_Mode == enMode::EmptyMode);
	}
	static clsCurrency GetEmptyOpject()
	{
		clsCurrency c(enMode::EmptyMode, "", "", "", 0);
		return c;

	}
	//
	string GetCountry()
	{
		return _Country;
	}
	//
	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}
	//
	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	//`
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	float GetRate()
	{
		return _Rate;
	}
	//
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);


		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{

			string Line;
			while(getline(MyFile,Line))
			{
				clsCurrency c = _ConvertLineToCurrencyOpject(Line);

				if (c.GetCurrencyCode()== CurrencyCode)
				{
					MyFile.close();
					return c;
				}

			}
			MyFile.close();

		}
		
		return GetEmptyOpject();


	}
	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		string CountryTemp;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{

			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency c = _ConvertLineToCurrencyOpject(Line);
				CountryTemp= clsString::UpperAllString(c.GetCountry());
				if (CountryTemp == Country)
				{
					MyFile.close();
					return c;
				}

			}
			MyFile.close();

		}

		return GetEmptyOpject();
	};
	//
	static bool IsCurrnecyExist(string CurrencyCode)
	{
		clsCurrency c = FindByCode(CurrencyCode);
		return (!(c.IsEmpty()));


	}
	//
	static vector< clsCurrency> GetCurrneciesList()
	{
		vector< clsCurrency> vclsCurrency = _LoadCurrencyDataFromFile();
		return vclsCurrency;



	}
	//


	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / GetRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.GetRate());

	}




};
