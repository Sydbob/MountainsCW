#include "stdafx.h"
#include "Climber.h"
#include "Mountain.h"

Climber::Climber() {};
Climber::Climber(int climberAge, string climberName, char climberGender) 
{
	this->climberAge = climberAge;
	this->climberName = climberName;
	this->climberGender = climberGender;
	
};

void Climber::AddMountain()
{
	Mountain newMountain("Mountain1", 123);
	//newMountain.SetName();
	//newMountain.SetHeight();
	this->mountains.push_back(newMountain);
}

float Climber::AverageHeight()
{
	averageHeight = 0;
	//loop through array and add all heights togther
	for (unsigned int i = 0; i < mountains.size(); ++i)
	{
		averageHeight += mountains[i].GetHeight();
	}
	//devide the total sum of heighs by amount of heights i.e. get average value
	averageHeight = averageHeight / mountains.size();
	return averageHeight;
}


void Climber::HighestMountain()
{
	int highestPosIndex = 0;
	for (unsigned int i = 0; i < mountains.size(); ++i)
	{
		//check if height of element in position highestPos is > height of the element in position i
		if (mountains[highestPosIndex].GetHeight() < mountains[i].GetHeight() )
		{
			//if it is higher, then replace highestPos with current one
			highestPosIndex = i;
		}
	}
	

	//display the highest mountain
	cout << mountains[highestPosIndex].GetName();
	cout << " (" << mountains[highestPosIndex].GetHeight() << " m heigh)";
}

//This method will ask the user for its gender and then it will assign it to the instance of the object
char Climber::AskGender()
{
	//ask climber gender
	char climberGender = 'f';
	cout << "Enter gender('f' = female, 'm' = male, 'o' = other, 'r' = refuse to answer): ";
//	cin >> climberGender;
	//keep asking while gender is not valid
	while (climberGender != 'f' && climberGender != 'm' && climberGender != 'o' && climberGender != 'r')
	{
		cout << "Enter gender ('f' = female, 'm' = male, 'o'= other, 'r' = refuse to answer): " << endl;
		cin >> climberGender;
	}
	//finally set climbers gender to one provided
	this->climberGender = climberGender;
	return climberGender;
}

string Climber::AskName()
{
	string climberName = "JOrge";
	cout << "Enter your name: ";
	//cin >> climberName;
	//set name to one user provided
	this->climberName = climberName;
	return climberName;
}

int Climber::AskAge()
{
	int climberAge = 12;
	cout << "Enter age (valid range is from 1 to 120): ";
	//cin >> climberAge;
	//keep asking while age is not valid
	while (climberAge < 1 || climberAge >120)
	{
		cout << "Enter age (valid range is from 1 to 120): ";
		cin >> climberAge;
	}
	//set climber age to user's provided one
	this->climberAge = climberAge;
	return climberAge;
}

Info Climber::GetInfo()
{
	string name = AskName();
	int age = AskAge();
	char gender = AskGender();
	Info newInfo;
	newInfo.name = name;
	newInfo.age = age;
	newInfo.gender = gender;
	return newInfo;
}

void Climber::DisplayInfo()
{
	cout << climberName << endl;
	cout << climberAge << endl;
	cout << climberGender << endl;
}


void Climber::DisplayMountains(vector<Mountain> mountains)
{
	//loop through list of mountain objects and siplay name and height
	for (unsigned int i = 0; i < mountains.size(); ++i)
	{
		cout << "Mountain name: " << mountains[i].GetName();
		cout << " Mountain height: " << mountains[i].GetHeight() << endl;
	}
}

//filter and return mountains greater than provided height
vector<Mountain> Climber::mountainsGreaterThan(int minHeight)
{
	vector<Mountain> mountainsSelected;
	for (unsigned int i = 0; i < mountains.size(); ++i)
	{
		if (mountains[i].GetHeight() > minHeight)
		{
			mountainsSelected.push_back(mountains[i]);
		}
	}
	return mountainsSelected;

}