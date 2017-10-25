#include "stdafx.h"
#include "Mountain.h"

Mountain::Mountain(){}

Mountain::Mountain(string name, int height)
{
	this->name = name;
	this->height = height;
}

void Mountain::SetHeight()
{
	int height;
	cout << "Enter height in m (valid range is 5 to 8848 m): ";
	cin >> height;
	while (cin.fail() || height <5 || height > 8848)
	{
		cout << "\nThat's not a valid input. Enter a number between 5 and 8848: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> height;
	} 
	//set height to value user provided
	this->height = height; 
}

void Mountain::SetName()
{
	string name; 
	cout << "Enter mountain name: ";
	cin.ignore();
	getline(cin, name);
	//record mountain name
	this->name = name;
}

