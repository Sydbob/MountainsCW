// Mountain CW mockup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Mountain.h"
#include "Climber.h"
#include "Club.h"
#include "ClubStats.h"

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
	ClubStats clubStats;

	//clubStats.WelcomeMessage(); 
	clubStats.DisplayMenu();
	clubStats.AskMenuOption();
	
	if (clubStats.GetUserOptionChoice() == 1)
	{
		clubStats.DisplayAddClimberMenu();
		club.AddClimber();
		char userResponce = clubStats.AskYesNo("Add another climber?");
		
		if (userResponce == 'y')
		{
			do
			{
				club.AddClimber();
				userResponce = clubStats.AskYesNo("Add another climber?");
			} while (userResponce == 'y');
		}
		else 
		{
			cout << "Done adding climbers. Going back to main menu.";

		}
		
		
	}
	else if (clubStats.GetUserOptionChoice() == 2)
	{ 
		cout << "2";
	}
	else if (clubStats.GetUserOptionChoice() == 3 )
	{
		clubStats.DisplayStatisticsSubMenu();
		clubStats.AskMenuOption();
	}
	else
	{   
		clubStats.DisplayMenu();
	}



return 0;
}

