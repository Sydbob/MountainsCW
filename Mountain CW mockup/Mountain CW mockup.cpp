// Mountain CW mockup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Mountain.h"
#include "Climber.h"
#include "Club.h"

using namespace std; 

//typedef unsigned int uint; --> to create a personal name for type e.g unsigned int is now uint
void displaySelectedMountains( vector<Mountain> mountainsSelected)
{
	for (unsigned int i = 0; i < mountainsSelected.size(); i++)
	{
		cout << mountainsSelected[i].GetName() << endl;
	}
}


int main()
{
	
	Club club;

	cout << "Add climber 1: " << endl;
	club.AddClimber();

	cout << "Add climbr 1 mountain1: " << endl;
	Climber& climber1 = club.GetClimbers().back();

	for (int i = 0; i < club.GetClimbers().size(); ++i)
	{
		cout << club.GetClimbers()[i].GetName();
	}
	Mountain m;
	vector<Mountain>& vec = club.GetClimbers()[0].GetMountains();

	vec.push_back(m);
	club.GetClimbers()[0].AddMountain();


	cout << "Displaying all climber 1 mountains" << endl;
	club.GetClimbers()[0].DisplayMountains(club.GetClimbers()[0].GetMountains());

	cout << "Displaying climber with highest average: " << endl;
	club.ClimberWithHighestAverage().DisplayInfo(); 
	club.ClimberWithHighestAverage().HighestMountain(); 

	

    return 0;
}

