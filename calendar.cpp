/*
    File Name:  calendar.cpp
   Created by:  Liz Klinger on 7/7/12.
  Description:  Inputs year, first weekday of the year, and month from the user,
                and outputs a formatted month calendar of the user-selected  
                month and year.  
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

int userInputYear();
int userInputFirstWeekday();
int userInputMonth();
int printError();
bool isLeapYear(int year);
string convertMonth(int monthNum);
int numDaysInMonth(int month, int year);
int monthFirstDayNumber(int month, int year);
int firstWeekdayOfMonth(int firstDayOfWeek, int month, int year);
int printCalendar(int startDay, int month, int year);

int main()
{
    int yearNum, firstWeekdayOfYear, monthNum;
    
    // input and validate year
    // allow the user to attempt to input up to three times for each variable.
    // if the user fails to input three times for a given variable, then the
    // program will automatically exit.
    
    yearNum = userInputYear();
    if (yearNum == -1)
    {
        return 0; // if yearNum = -1, then the user has entered 3 invalid inputs
                  // and the program will exit.
    }
    
    // input and validate first weekday of the year
    // allow the user to attempt to input up to three times for each variable.
    // if the user fails to input three times for a given variable, then the
    // program will exit.
    
    firstWeekdayOfYear = userInputFirstWeekday();
    if (firstWeekdayOfYear == -1)
    {
        return 0; // if firstWeekdayOfYear = -1, then the user has entered 3
                  // invalid inputs and the program will exit.
    }
    
    // input and validate month number
    // allow the user to attempt to input up to three times for each variable.
    // if the user fails to input three times for a given variable, then the
    // program will exit.
    
    monthNum = userInputMonth();
    if (monthNum == -1)
    {
        return 0; // if monthNum = -1, then the user has entered 3 invalid
                  // inputs and the program will exit.
    }
    
    // print and format the calendar based on user input specifications
    printCalendar(firstWeekdayOfMonth(firstWeekdayOfYear, monthNum, yearNum), monthNum, yearNum);
    
    return 0;
}

int userInputYear()
{
    // error counter to keep track of the number of errors a user may input
    int errorCount = 1, year;

    // message to prompt user to type in a year
    cout << "Please enter the year (e.g. 2012): " << endl;

    // 
    while (errorCount <= 3)    
    {
        cin.clear();
        cin >> year;
        
        if (year >= 0 && cin.good() != 0)
        {
            return year;
        }
        else if (errorCount < 3)
        {
            cout << "Attempt " << errorCount << "/3: You typed in an invalid year. Please try again: " << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }
        errorCount++;
    }
    
    printError();
    return 0;
}

int userInputFirstWeekday()
{    
    // error counter to keep track of the number of errors a user may input
    int errorCount = 1, weekday;

    // message to prompt user to type in a first weekday of the year, and
    // lists all possible options to make options explicit
    cout << endl << "Please enter the number representing first weekday of the year:" << 
    endl << "(e.g. 1 = Monday, 2 = Tuesday, 3 = Wednesday," <<
    endl << " 4 = Thursday, 5 = Friday, 6 = Saturday, 7 = Sunday)" << endl ;
    
    while (errorCount <= 3)    
    {
        cin.clear();
        cin >> weekday;
        
        if (weekday >= 1 && weekday <=7 && cin.good() != 0)
        {
            return weekday;
        }
        else if (errorCount < 3)
        {
            cout << "Attempt " << errorCount << "/3: You typed in an invalid weekday number. Please try again: " << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }
        errorCount++;
    }
    
    printError();
    return 0;
}

int userInputMonth()
{
    // error counter to keep track of the number of errors a user may input
    int errorCount = 1, month;

    // message to prompt user to type in a month number, and
    // lists all possible options to make options explicit
    cout << endl << "Please enter a month number:" << 
    endl << "(e.g. 1 = January, 2 = February, 3 = March, 4 = April," << 
    endl << "5 = May, 6 = June, 7 = July, 8 = August, 9 = Septemer," <<
    endl << "10 = Octber, 11 = November, 12 = December)" << endl;
    
    while (errorCount <= 3)    
    {
        cin.clear();
        cin >> month;
        
        if (month >= 1 && month <= 12 && cin.good() != 0)
        {
            return month;
        }
        else if (errorCount < 3)
        {
            cout << "Attempt " << errorCount << "/3: You typed in an invalid month. Please try again: " << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }
        errorCount++;
    }
    
    printError();
    return 0;
}

int printError()
{
    cout << "Attempt 3/3: Sorry, you have typed in too many invalid inputs for this session." << endl << "Please restart the program." << endl;
    exit (EXIT_FAILURE); // if errorCount exceeds 3, then program exits
    return 0;
}

bool isLeapYear(int year)
{
    // year is a leap year if year is divisible by 4
    if (year % 4 != 0)
    {
        return false;
    }
    
    // if year is divisible by 100, it also must be divisible by 400 to be considered a leap year
    if (year % 100 == 0 && year % 400 != 0)
    {
        return false;
    }
    
    return true;
}

string convertMonth(int monthNum)
{
    string monthName;
    
    switch (monthNum)
    {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;            
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;    
        case 5:
            monthName = "May";
            break;    
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;            
        case 8:
            monthName = "August";
            break;            
        case 9:
            monthName = "September";
            break;            
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;            
        case 12:
            monthName = "December";
            break;            
    }
    
    return monthName;
}

int numDaysInMonth(int month, int year)
{
    int numOfDays;
    
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            numOfDays = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            numOfDays = 30;
            break;
        case 2:
            if (isLeapYear(year))
            {
                numOfDays = 29;
                break;
            }
            else
            {
                numOfDays = 28;
                break;
            }
    }
    return numOfDays;
}


int monthFirstDayNumber(int month, int year)
{
    int dayNumber = 0, countMonth = 1;
    
    for (countMonth = 1; countMonth < month; countMonth++)
    {
        dayNumber += numDaysInMonth(countMonth, year);  // sum the number of days for all the months preceeding the month in question
    }
    
    return dayNumber;
}


int firstWeekdayOfMonth(int firstDayOfWeek, int month, int year)
{
    // return first day in month, 0 - 6
    int dayNumber = (((monthFirstDayNumber(month, year) % 7) + (firstDayOfWeek - 1)) % 7) + 1;
    
    return dayNumber;
}


int printCalendar(int startDay, int month, int year)
{
    int dayNum = 1, count = 0;
    
    setiosflags(ios::right);
    cout << endl;
    cout << setw(9) << string(10 - convertMonth(month).length(), ' ') << convertMonth(month) << " " << year << endl; // formatted month and year
    
    cout << "_____________________________" << endl; // line separating month and year from weekdays and days
    
    cout << setw(4) << "Sun" << setw(4) << "Mon" << setw(4) << "Tue" << setw(4) << "Wed" << setw(4) << "Thu" << setw(4) << "Fri" << setw(4) << "Sat" << endl; // print days of the week
    
    if (startDay == 7)
    {
        startDay = 0; // convert number for Sunday to 0 to format correctly
    }
    
    cout << string(startDay * 4, ' '); //create spacing for first day
    
    for (count = 0; count < 7 - startDay; count++) // print the first week
    {
        cout << setw(4) << dayNum;
        dayNum++;
    }
    cout << endl;
    count = 0;
    
    while (dayNum <= numDaysInMonth(month, year))
    {   
        if (count < 7) // print the rest of the days in the month
        {
            cout << setw(4) << dayNum;
            count++;
            dayNum++;
        }
        else
        {
            cout << endl;
            cout << setw(4) << dayNum;
            count = 1;
            dayNum++;
        }
    }
    
    cout << endl;
    
    return 0;
}