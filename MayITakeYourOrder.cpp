/*
Andrew Clemons
C and C++ Programming
May I Take Your Order Assignment
Fall 2019
*/
#include <iostream>

using namespace std;

double Drinks = 1.24;
double Hamburgers = 2.34;
double Fries = 1.23;
double Shakes = 4.00;
double ApplePies = 3.78;
double Salad = 6.78;
double orderTotal = 0;


	void takeMyOrder(){
	
	//number of drinks multiplied by cost and set to orderTotal
	cout<< "How many Drinks do you need" << endl;
	int num;
	cin >> num;
	orderTotal = num * Drinks;  
	cout<<orderTotal<<endl;
	
	//number of Hamburgers multiplied by cost and added to current orderTotal
	cout<< "How many Hamburgers do you need" << endl;
	cin >> num;
	orderTotal += num * Hamburgers;
	cout<<orderTotal<<endl;
	
	//number of Fries multiplied by cost and added to current orderTotal
	cout<< "How many Fries do you need" << endl;
	cin >> num;
	orderTotal += num * Fries;
	cout<<orderTotal<<endl;
	
	//number of Shakes multiplied by cost and added to current orderTotal
	cout<< "How many Shakes do you need" << endl;
	cin >> num;
	orderTotal += num * Shakes;
	cout<<orderTotal<<endl;
	
	//number of ApplePies multiplied by cost and added to current orderTotal
	cout<< "How many Apple pies do you need" << endl;
	cin >> num;
	orderTotal += num * ApplePies;
	cout<<orderTotal<<endl;
	
	//number of Salad multiplied by cost and added to current orderTotal
	cout<< "How many Salad do you need" << endl;
	cin >> num;
	orderTotal += num * Salad;
	cout<<orderTotal<<endl;
	
	//print out order total * tax of 7%
	orderTotal += (orderTotal *.07);
	cout<<"your order total is $";
	printf("%.2f", orderTotal);
}

int main() {
	takeMyOrder();
}