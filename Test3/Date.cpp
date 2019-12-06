/*
Andrew Clemons
Test 3
*/
#include <iostream>

using namespace std;

class Date
{
private:
    int Month, Day, Year;

public:
    Date(int, int, int);
    //conpy constructor
    Date(const Date &);
    Date();
    Date &operator=(const Date &);
    Date &operator++();
    Date operator++(int);
    friend ostream &operator<<(ostream &out, Date &date);
    friend istream &operator>>(istream &in, Date &date);
    friend Date operator+(Date &, int number);
    friend Date operator-(Date &, int number);
    friend bool operator<(Date &, Date &);
    friend bool operator>(Date &, Date &);
    friend bool operator==(Date &, Date &);
};
Date::Date()
{
    Month = 1;
    Day = 1;
    Year = 2000;
}
Date::Date(int month, int day, int year)
{
    if (day <= 31 && day > 0 && month > 0 && month < 13 && year > 0)
    {
        Month = month;
        Day = day;
        Year = year;
    }
    else
    {
        Month = 1;
        Day = 1;
        Year = 1;
    }
}
//copy constructor
Date::Date(const Date &d1)
{
    Date copy(d1);
}

//assignment
Date &Date::operator=(const Date &date)
{
    Month = date.Month;
    Day = date.Day;
    Year = date.Year;

    return *this;
}
//prefix
Date &Date::operator++()
{
    if (Month == 12 && Day == 31)
    {
        Month = 1;
        Day = 1;
        ++Year;
    }
    else if (Day == 31)
    {
        ++Month;
        Day = 1;
    }
    else
    {
        ++Day;
    }
    return *this;
}
//postfix
Date Date::operator++(int)
{
    Date temp;
    if (temp.Month == 12 && temp.Day == 31)
    {
        temp.Month = 1;
        temp.Day = 1;
        ++temp.Year;
    }
    else if (Day == 31)
    {
        ++temp.Month;
        temp.Day = 1;
    }
    else
    {
        ++temp.Day;
    }
    return temp;
}
//cout
ostream &operator<<(ostream &out, Date &date)
{
    cout << "Month: " << date.Month << endl;
    cout << "Day: " << date.Day << endl;
    cout << "Year: " << date.Year << endl;
    return out;
}
//cin
istream &operator>>(istream &in, Date &date)
{
    cout << "input Month " << endl;
    cin >> date.Month;
    cout << "input Day " << endl;
    cin >> date.Day;
    cout << "input Year " << endl;
    cin >> date.Year;

    return in;
}

//addition
Date operator+(Date &d1, int number)
{
    int temp = d1.Day + number;
    while (temp > 31)
    {
        d1.Month++;
        temp -= 31;
        if (d1.Month > 12)
        {
            d1.Year++;
            d1.Month = 1;
        }
    }
    d1.Day = temp;
    return d1;
}

Date operator-(Date &d1, int number)
{
    int temp = d1.Day - number;
    while (temp < 0)
    {
        --d1.Month;
        temp += 31;
        if (d1.Month == 0)
        {
            --d1.Year;
            d1.Month = 12;
        }
    }
    d1.Day = temp;
    return d1;
}

bool operator<(Date &d1, Date &d2)
{
    if (d1.Year < d2.Year)
    {
        return true;
    }
    else if (d1.Month < d2.Month)
    {
        return true;
    }
    else if (d1.Day < d1.Day)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(Date &d1, Date &d2)
{
    if (d1.Year > d2.Year)
    {
        return true;
    }
    else if (d1.Month > d2.Month)
    {
        return true;
    }
    else if (d1.Day > d1.Day)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(Date &d1, Date &d2)
{
    if (d1.Year == d2.Year && d1.Month == d2.Month && d1.Day == d2.Day)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//datetime class

class dateTime : public Date
{
private:
    int hours;
    int minutes;
    int sec;

public:
    dateTime(int m , int d, int y, int h, int mi, int s) : Date{m, d, y}{
        h = hours;
        minutes = mi;
        sec = s; 
    }
     friend ostream &operator<<(ostream &out, dateTime &date);
     friend istream &operator>>(istream &in, dateTime &date);

};
//constructor
//cout
/*ostream & operator<<(ostream &out, dateTime &date)
{
    cout<<  "Month: ";
    cout << static_cast<Date>(date);
    cout << static_cast<Date>(date);
    cout << static_cast<Date>(date);
    return out;
}
//cin
istream &operator>>(istream &in, dateTime &date)
{
    cout << "input Month " << endl;
    cin >> date.Month;
    cout << "input Day " << endl;
    cin >> date.Day;
    cout << "input Year " << endl;
    cin >> date.Year;

    return in;
}
*/
int main()
{
    Date one(0,0,0);
    Date two(0,0,0); 

    cout << "Test cin operator" << endl;
    cout << "Make object one" << endl;
    cin >> one; 
    cout << "cout operator test " << endl;
    cout<< one; 

    cout << "Test cin operator" << endl;
    cout << "Make object two" << endl;
    cin >> two;     
    cout << "cout operator test" << endl;
    cout << two; 

    cout << "pre increment operator on object 1 " << endl;
    cout <<  ++one << endl;

    cout << "assignment and post increment operator test" << endl;
    cout << "object one " << endl;
    cout << one << endl;
    cout << "object two " << endl;
    cout << two << endl; 
    one = two++;
    cout << "objects after assignment " << endl;
    cout << "object one " << endl;
    cout << one << endl;
    cout << "object two " << endl;
    cout << two << endl; 
    
    cout << "test addition, adding 10 days to object one" << endl;
    one = one+10; 
    cout << "object one is" << endl;
    cout << one << endl;
    
    cout << "test subtraction, subtracting 1 days to object three" << endl;
    Date three(10,10,2010);
    cout << "object three is" << endl;
    cout << three;
    cout << "object after subtraction" << endl;
    three = three -1; 
    cout << three << endl;
    
    cout << "test < operator, comparing one < two" << endl;
    cout <<"Date one" << endl;
    cout << one;
    cout << "Date two" << endl; 
    cout << two;
    cout << (one < two) << endl;

    cout << "test > operator, comparing one > two" << endl;
    cout <<"Date one" << endl;
    cout << one;
    cout << "Date two" << endl; 
    cout << two;
    cout << (one > two)<< endl;

    cout << "Test copy constructor, copying one then adding 100 to one" << endl;
    cout << one;
    Date copy(one);
    cout << "copied" << endl;
    cout << "adding to one" << endl;
    one = one +100;
    cout << one << endl; 
    cout << "print copy" << endl;
    cout << copy << endl;
    cout << "print one" << endl;
    
   cout << "making a dateTime object" << endl;
    dateTime dt(1, 1, 1, 1, 1, 1);


}