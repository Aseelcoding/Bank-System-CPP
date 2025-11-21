#pragma once
#include <iostream>
#include<vector>
using namespace std;
class clsString
{
private :
	string _Value;
public :
	clsString()
	{
		_Value = "";
	
	}
	clsString(string Value)
	{
		_Value = Value;
	
	}

	//Set and Get For The Vaule:
	void SetValue(string _Value)
	{
		this->_Value = _Value;
	}
	string GetValue()
	{
		return this->_Value;
	}


	
	static short  Length(string S1)
	{
		return S1.length();
	}
	short Length()
	{
		return this->_Value.length();
	}

	//Function counts the number of the words in the value.And you can call it without opject because of the static.
	static  short CountWords(string S1)
	{
		string delim = " "; // delimiter
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable

		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				Counter++;
			}

			// erase until position and move to next word
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++; // count the last word
		}

		return Counter;
	}
	//The same function above but this function take or count the word in the opject directly.
	short CountWords( )
	{
		return CountWords(this->_Value);
	}

	//Function Print the first letter for each word and it is static because maybe we will need to use it without an opject.
	static  void PrintFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		cout << "\nFirst letters of this string:\n";

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				cout << S1[i] << endl;
			}

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}
	//The same function above but this funtion take or print the letter of each word from the vaule in the currnn opject.
	void PrintFirstLetterOfEachWord()
	{
		 PrintFirstLetterOfEachWord(this->_Value);
	}

	//This function make all first letters of each word in uppercase and we can use it witout make an opject because of the static.
    static 	string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}
    //The same function above but it take the value from the current opject directly
     void UpperFirstLetterOfEachWord( )
{
	 this->_Value=UpperFirstLetterOfEachWord(this->_Value);
}
 

//This function make all first letters of each word in lowercase and we can use it witout make an opject because of the static.
static string LowerFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}

		isFirstLetter = (S1[i] == ' ' ? true : false);
	}

	return S1;
}
//The same function above but it take the value from the current opject directly
void LowerFirstLetterOfEachWord()
{
	this->_Value= LowerFirstLetterOfEachWord(this->_Value);

}

// This function make all letters of the value cabital.use static to useit without an opject.
static string UpperAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
	return S1;
}
// This function same above but it takes the vaule from the current opject directly.
void UpperAllString( )
{
	this->_Value= UpperAllString(this->_Value);

}

// This function make all letters of the value small.use static to useit without an opject.
static string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}
void LowerAllString( )
{
	this->_Value= LowerAllString(this->_Value);
}

//This function cinvert the char from cabital to small and from small to capital.
static char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}

//This function Invert all the letters of the string and it use the previous function with loop.
static string InvertLetters(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
	}
	return S1;
}
void InvertLetters()
{
	this->_Value= InvertLetters(this->_Value);
}

//This function only count the capital letters.
static short CountCapitalLetters(string S1)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			Counter++;
	}
	return Counter;
}
short CountCapitalLetters()
{
	return  CountCapitalLetters(this->_Value);
}

//This function only count the small letters.
static short CountSmallLetters(string S1)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
			Counter++;
	}
	return Counter;
}
short CountSmallLetters()
{
	return CountSmallLetters(this->_Value);
}

static short CountLetter(string S1, char Letter, bool MatchCase = true)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (MatchCase)
		{
			if (S1[i] == Letter)
				Counter++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(Letter))
				Counter++;
		}
	}

	return Counter;
}
short CountLetter(char Letter, bool MatchCase = true)
{
	return  CountLetter(this->_Value, Letter, MatchCase);
	}

//يتأكد من ان الحرف من حروف العلة او لا 
static bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

//This function count the vowel letters using the previous function .
static short CountVowels(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			Counter++;
	}

	return Counter;
}
short CountVowels()
{
	return CountVowels(this->_Value);
}

//This function Print all the vowel letters.
static void PrintVowels(string S1)
{
	cout << "\nVowels in string are: ";
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			cout << S1[i] << " ";
	}
}
void PrintVowels()
{
	PrintVowels(this->_Value);
}

//This function Print All each word in string
static void PrintEachWordInString(string S1)
{
	string delim = " "; // delimiter
	cout << "\nYour string words are:\n\n";

	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word

		if (sWord != "")
		{
			cout << sWord << endl;
		}

		// erase() until position and move to next word
		S1.erase(0, pos + delim.length());
	}

	if (S1 != "")
	{
		cout << S1 << endl; // print the last word
	}
}
void  PrintEachWordInString()
{
	  PrintEachWordInString(this->_Value);
}

//This function split the string and sotre it in vector.
static vector<string> Split(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		/*if (sWord != "")*/
		/*{*/
			vString.push_back(sWord);
		/*}*/

		// erase() until position and move to next word
		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1); // add the last word
	}

	return vString;
}
vector<string> Split(string Delim)
{
	return Split(this->_Value,Delim);
}

//This Function Delete the spaces from the left side.
static string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - i);
		}
	}
	return "";
}
void TrimLeft()
{
	this->_Value= TrimLeft(this->_Value);
}

//This Function Delete the spaces from the right side.
static string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}
	return "";
}
void TrimRight()
{
	this->_Value = TrimRight(this->_Value);
}

//This Function delete all spacse from both sides.
static string Trim(string S1)
{
	return TrimLeft(TrimRight(S1));
}
void Trim()
{
	this->_Value = Trim(this->_Value);
}

//تجمع عناصر السترينج وتجطهم بسترنج واحد فقط Vector
static string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";

	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}
//تجمع عناصر السترينج وتجطهم بسترنج واحد فقط Array
static string JoinString(string arrString[], short Length, string Delim)
{
	string S1 = "";

	for (short i = 0; i < Length; i++)
	{
		S1 = S1 + arrString[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

//This Function Reverse Words in the string.
static string ReverseWords(string S1)
{
	vector<string> vString;
	string S2 = "";

	vString = Split(S1, " ");

	// declare iterator
	vector<string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;
		S2 += *iter + " ";
	}

	// remove last space
	S2 = S2.substr(0, S2.length() - 1);

	return S2;
}
void ReverseWords()
{
	this->_Value= ReverseWords(this->_Value);
}

//This function You can use it to replace certin words and put any word you want.
static string ReplaceWord(string S1, string StringToReplace, string sReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = S1.find(StringToReplace); // find next
	}

	return S1;
}
void ReplaceWord(string StringToReplace, string sReplaceTo)
{
	this->_Value = ReplaceWord(this->_Value, StringToReplace, sReplaceTo);
}

//This function Remove alll The nonchar.
static string RemovePunctuations(string S1)
{
	string S2 = "";

	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}

	return S2;
}
void RemovePunctuations()
{
	this->_Value = RemovePunctuations(this->_Value);
}
	// Property Set and Get to make it easier to use!
	__declspec(property(get = GetValue, put = SetValue)) string Value;
	

};

