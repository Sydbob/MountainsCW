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
	Climber newClimber(12, "Pablo", 'M');
	cout << "Add climber 1: " << endl;
	club.AddClimber();
	club.AddClimber();
	//club.GetClimbers().push_back(newClimber);
	cout << "Add climbr 1 mountain1: " << endl;

	club.GetClimbers()[0].AddMountain();
	club.GetClimbers()[0].AddMountain();
	club.GetClimbers()[1].AddMountain();
	club.GetClimbers()[1].AddMountain();

	cout << "Displaying climber with highest average: " << endl;
	club.ClimberWithHighestAverage().DisplayInfo(); 
	club.ClimberWithHighestAverage().HighestMountain(); 
    
	return 0;
}

