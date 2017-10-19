#include "stdafx.h"
#include "Mountain.h"

//Constructor

Mountain::Mountain(){}

Mountain::Mountain(string name, int height)
{
	this->name = name;
	this->height = height;
}

void Mountain::SetHeight()

{
	int height;
	cout << "Enter height in m (valid range is 5 to 8848 m): " << endl;
	cin >> height;
	//check if height is valid
	while (height < 5 || height > 8848)
	{
		cout << "Enter height in m (valid range is 5 to 8848 m): " << endl;
		cin >> height;
	}
	//set height to value user provided
	this->height = height;
	
}

void Mountain::SetName()
{
	string name; 
	cout << "Enter mountain name: ";
	cin >> name;
	//record mountain name
	this->name = name;
	
}

