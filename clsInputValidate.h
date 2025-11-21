#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;


template <typename T> 
class clsInputValidate
{
   



public:

    static string ReadString(string Message)
    {
        string st;
        cout << Message << endl;
        getline(cin, st);
        return st;
    }


   static  bool IsNumberBetween(T number, T from, T to)
    {
        return number >= from && number <= to;

    }
  
   // سواء كان التاريخ الاول اكير من او اصغر من التاريخ الثاني الكود هذا يتعامل مع الحاله هذي 
   static  bool IsDateBetween(clsDate date, clsDate dateFrom, clsDate dateTo)
   {
     
       if (!(clsDate::IsDate1BeforeDate2(dateFrom, dateTo)))
       {
           clsDate::SwapDates(dateFrom, dateTo);
          if (clsDate::IsDate1AfterDate2(date,dateFrom)||clsDate::IsDate1EqualDate2(date, dateFrom))
          {
           if(clsDate::IsDate1BeforeDate2(date,dateTo)||clsDate::IsDate1EqualDate2(date,dateTo))
           {
               clsDate::SwapDates(dateFrom, dateTo);
               return true;
           }

          }
          else 
          {
              clsDate::SwapDates(dateFrom, dateTo);
              return false;
          }
         
       }
       if (clsDate::IsDate1AfterDate2(date, dateFrom) || clsDate::IsDate1EqualDate2(date, dateFrom))
       {
           if (clsDate::IsDate1BeforeDate2(date, dateTo) || clsDate::IsDate1EqualDate2(date, dateTo))
           {

               return true;
           }
       }
       return false;
   }


   //Read number and return it.
   static  T ReadNumber(string message)
   {
       T number;
       do
       {
           cout << message << endl;
           cin >> number;

           while (cin.fail())
           {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << "Invalid number please try again!\n";
               cin >> number;
           }


       } while (number < 0);

       return number;
   }
  //Raed number within range.
 static  T ReadNumberBetween(T from, T to, string message)
  {
     T number;

     do 
     {
  
         do
         {
           
             number = ReadNumber(message);

             while (cin.fail())
             {
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 cout << "Invalid number please try again!\n";
                 cin >> number;
             }


         } while (number < 0);

     

     } while (number<from || number>to);
     return number;

  }
 
 
 //this function make sure that the date is correct and vaild.
static    bool IsValidateDate(clsDate date)
  {
      return clsDate::IsValidDate(date);
  }



};

