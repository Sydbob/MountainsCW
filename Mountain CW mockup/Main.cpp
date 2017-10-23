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
		cout << mountainsSelected[i].GetName();
		cout << " (" << mountainsSelected[i].GetHeight() << " m heigh)" << endl;
	}
}

int main()
{
	Club club;
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
	cout << club.ClimberWithHighestAverage().GetAverage();
	cout << " m climbed on average" << endl;


	cout << "Displaying climber who climbed highest muntain: " << endl;
	cout << club.ClimberWithClubsHighestClimbedMountain().GetName() << endl;
	cout << club.ClimberWithClubsHighestClimbedMountain().HighestMountain().GetName() << endl;
	cout << club.ClimberWithClubsHighestClimbedMountain().GetHeighestHeight() << endl;

	club.AllMountainsHigherThanGiven();
	cout << "Displaying selected mountains: " << endl;
	displaySelectedMountains(club.GetAllMountainsHigherThanGiven());

	return 0;
}

