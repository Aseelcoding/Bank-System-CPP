#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public :
    enum enCharType {
        SamallLetter = 1,    // Represents lowercase letters (ASCII 97 to 122).
        CapitalLetter = 2,   // Represents uppercase letters (ASCII 65 to 90).
        SpecialCharacter = 3,// Represents special characters (ASCII 33 to 47).
        Digit = 4,            // Represents digits (ASCII 48 to 57).
        MixChars = 5
	};


    //// Returns: A positive integer entered by the user.
  static   int ReadPositiveNumber(string Message)
    {
        int Number = 0;  // Variable to store the user's input.
        do
        {
            cout << Message << endl; // Display the prompt message.
            cin >> Number;           // Read the number from the user.
        } while (Number <= 0);       // Continue prompting until a positive number is entered.
        return Number;
    }

    //
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}


// Returns: A random integer between From and To (inclusive).
    static int RandomNumber(int From, int To)
	{
		// Generate a random number between 0 and (To - From) using rand(),
		// then add From to shift the range to [From, To].
		int randNum = rand() % (To - From + 1) + From;
		return randNum;  // Return the generated random number.
	}


// Function: GetRandomCharacter
// Purpose: Returns a random character based on the specified character type.
// Parameters:
//    CharType - an enCharType value indicating which category of character to generate.
// Returns: A random character of the specified type.
     static char GetRandomCharacter(enCharType CharType)
     {
         //if the delevoper chose Mix:
         if (CharType== enCharType::MixChars)
         {
             int Random = RandomNumber(1, 3);
             switch(Random)
             {
             case 1:
                 return char(RandomNumber(65, 90));
                 break;
             case 2:  
                 return char(RandomNumber(97, 122));
                 break;
             case 3:
                 return char(RandomNumber(48, 57));
                 break;
  


             }
         }




         // Use a switch-case to handle the different character types.
         switch (CharType)
         {
         case enCharType::SamallLetter:
         {
             // Generate a random lowercase letter (ASCII codes 97 to 122).
             return char(RandomNumber(97, 122));
             break;  // break is not strictly needed after a return.
         }
         case enCharType::CapitalLetter:
         {
             // Generate a random uppercase letter (ASCII codes 65 to 90).
             return char(RandomNumber(65, 90));
             break;
         }
         case enCharType::SpecialCharacter:
         {
             // Generate a random special character (ASCII codes 33 to 47).
             return char(RandomNumber(33, 47));
             break;
         }
         case enCharType::Digit:
         {
             // Generate a random digit (ASCII codes 48 to 57).
             return char(RandomNumber(48, 57));
             break;
         }
         }
         // If an invalid type is passed, return a null character.
         return '\0';
     }


// Function: GenerateWord
// Purpose: Generates a random word of a specified length using characters from a given type.
// Parameters:
//   - CharType: The type of character to use (e.g., CapitalLetter).
//   - Length: The number of characters in the word.
// Returns: A string containing the generated word.
     static string GenerateWord(enCharType CharType, short Length)
     {
         string Word;  // Initialize an empty string to build the word.

         // Loop for the number of characters specified by Length.
         for (int i = 1; i <= Length; i++)
         {
             // Append a random character of the specified type to the word.
             Word = Word + GetRandomCharacter(CharType);
         }
         return Word;
     }


// Function: GenerateKey
// Purpose: Generates a key string composed of four groups of 4 uppercase letters separated by hyphens.
// Returns: A string representing the generated key.
     static    string GenerateKey(enCharType CharType)
     {
         string Key = "";  // Initialize an empty key string.

         // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
         Key = GenerateWord(CharType,4) + "-";
         Key = Key + GenerateWord(CharType, 4) + "-";
         Key = Key + GenerateWord(CharType, 4) + "-";
         Key = Key + GenerateWord(CharType, 4);

         return Key;
     }


// Function: GenerateKeys
// Purpose: Generates and prints a specified number of keys.
// Parameters:
//   - NumberOfKeys: The total number of keys to generate.
     static  void GenerateKeys(short NumberOfKeys, enCharType CharType)
     {
         // Loop from 1 to NumberOfKeys.
         for (int i = 1; i <= NumberOfKeys; i++)
         {
             // Print the current key number and the generated key.
             cout << "Key [" << i << "] : ";
             cout << GenerateKey(CharType) << endl;
         }
     }

     //
     static void Swap(int &Number1,int &Number2)
     {
         int temp;
         temp = Number1;
         Number1 = Number2;
         Number2 = temp;
     }
     static void Swap(double& Number1, double& Number2)
     {
         double temp;
         temp = Number1;
         Number1 = Number2;
         Number2 = temp;
     }
     static void Swap(string& string1, string& string2)
     {
         string temp;
         temp = string1;
         string1 = string2;
         string2 = temp;
     }
     static void Swap(clsDate &Date1, clsDate &Date2)
     {
         clsDate::SwapDates(Date1, Date2);
         
        
     }


     // Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with a specified number of random numbers between 1 and 100.
// Parameters:
//   arr      - an integer array with a capacity of 100 elements.
//   arrLength - a reference variable that will hold the number of elements to fill.
//             The user specifies this number.
     static void FillArrayWithRandomNumbers(int arr[100], int arrLength,int from,int to)
     {
         // Fill the array with random numbers between 1 and 100.
         for (int i = 0; i < arrLength; i++)
             arr[i] = RandomNumber(from, to);
     }
     static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, int Numberchar)
     {
      for (int i = 0; i < arrLength; i++)
             arr[i] = GenerateWord(CharType, Numberchar);
     }
     
     // Function: ShuffleArray
// Purpose: Randomly shuffles the elements in the array.
// Parameters:
//   - arr: The array to shuffle.
//   - arrLength: The number of elements in the array.
     static void ShuffleArray(int arr[100], int arrLength)
     {
         // Loop through each element of the array.
         // For each iteration, swap two randomly chosen elements.
         for (int i = 0; i < arrLength; i++)
         {
             // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
             // Subtract 1 to convert it to a valid 0-based index.
             int index1 = RandomNumber(1, arrLength) - 1;
             int index2 = RandomNumber(1, arrLength) - 1;
             // Swap the elements at the two randomly chosen indices.
             Swap(arr[index1], arr[index2]);
         }
     }
     static void ShuffleArray(string arr[100], int arrLength)
     {
         // Loop through each element of the array.
         // For each iteration, swap two randomly chosen elements.
         for (int i = 0; i < arrLength; i++)
         {
             // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
             // Subtract 1 to convert it to a valid 0-based index.
             int index1 = RandomNumber(1, arrLength) - 1;
             int index2 = RandomNumber(1, arrLength) - 1;
             // Swap the elements at the two randomly chosen indices.
             Swap(arr[index1], arr[index2]);
         }
     }

     // Function: FillArrayWithKeys
     // Purpose: Fills a string array with generated keys.
     // Parameters:
     //   - arr: The string array to be filled (capacity of 100).
     //   - arrLength: The number of keys to generate and fill in the array.
    static  void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
     {
         // Loop through the array indices and generate a key for each element.
         for (int i = 0; i < arrLength; i++)
             arr[i] = GenerateKey(CharType);
     }


    //Tabs help you to add spaces easily.
  static   void tabs(short tabs)
    {
        for (short i=1;i<=tabs;i++)
        {
            cout << "\t";
        }
    }


    static void PrintArray(int arr[100], int arrLength)
    {
        // Loop through each element of the array and print it.
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << " ";
        cout << "\n";  // Print a newline after printing all elements.
    }


    // Function: EncryptText
// Purpose: Encrypts the given text by shifting each character by a specified encryption key.
// Parameters:
//   Text - the original text to be encrypted.
//   EncryptionKey - a short integer representing the shift value to apply to each character.
// Returns: The encrypted text.
  static   string EncryptText(string Text, short EncryptionKey)
    {
        // Loop through each character of the text.
        // Note: Using "<= Text.length()" iterates one extra time (accessing the null terminator), 
        // which may be unintended. Ideally, use "< Text.length()".
        for (int i = 0; i < Text.length(); i++)
        {
            // Convert the current character to its integer ASCII value,
            // add the encryption key, cast it back to char, and assign it back.
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text; // Return the encrypted text.
    }
  // Function: DecryptText
// Purpose: Decrypts the given text by reversing the encryption process.
//          It shifts each character back by the specified encryption key.
// Parameters:
//   Text - the encrypted text to be decrypted.
//   EncryptionKey - the same short integer key used during encryption.
// Returns: The decrypted (original) text.
  static string DecryptText(string Text, short EncryptionKey)
  {
      // Loop through each character of the text.
      // Note: Using "<= Text.length()" will process one extra character (the null terminator).
      for (int i = 0; i < Text.length(); i++)
      {
          // Convert the current character to its ASCII integer value,
          // subtract the encryption key, cast back to char, and assign it back.
          Text[i] = char((int)Text[i] - EncryptionKey);
      }
      return Text; // Return the decrypted text.
  }

  //Give this function any number and it will convert it into text.
  static string NumberToText(int Number)
  {
      if (Number == 0)
      {
          return "";
      }

      if (Number >= 1 && Number <= 19)
      {
          string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                           "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
                           "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
          return arr[Number] + " ";
      }

      if (Number >= 20 && Number <= 99)
      {
          string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty",
                           "Sixty", "Seventy", "Eighty", "Ninety" };
          return arr[Number / 10] + " " + NumberToText(Number % 10);
      }

      if (Number >= 100 && Number <= 199)
      {
          return "One Hundred " + NumberToText(Number % 100);
      }

      if (Number >= 200 && Number <= 999)
      {
          return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
      }

      if (Number >= 1000 && Number <= 1999)
      {
          return "One Thousand " + NumberToText(Number % 1000);
      }

      if (Number >= 2000 && Number <= 999999)
      {
          return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
      }

      if (Number >= 1000000 && Number <= 1999999)
      {
          return "One Million " + NumberToText(Number % 1000000);
      }

      if (Number >= 2000000 && Number <= 999999999)
      {
          return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
      }

      if (Number >= 1000000000 && Number <= 1999999999)
      {
          return "One Billion " + NumberToText(Number % 1000000000);
      }

      else
      {
          return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
      }
  }
};

