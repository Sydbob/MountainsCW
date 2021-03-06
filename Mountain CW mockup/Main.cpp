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
	if (!mountainsSelected.empty())
	{
		cout << "\n\nDisplaying selected mountains: " << endl;
		for (unsigned int i = 0; i < mountainsSelected.size(); i++)
		{
			cout << mountainsSelected[i].GetName();
			cout << " (" << mountainsSelected[i].GetHeight() << " m heigh)" << endl;
		}
	}
	else
	{
		cout << "\nThere are no mountains to display";
	}
}

void displayClimbersWithID(vector<Climber> climbers)
{
	if (!climbers.empty())
	{
		for (int i = 0; i < climbers.size(); ++i)
		{
			cout << "ID: " << i << " Climber name: " << climbers[i].GetName() << endl;
		}
	}
	else
	{
		cout << "\nThere are no climbers to display";
	}
}


int main()
{
	Club club;
	ClubStats clubStats;

	//make a few dummy climbers for testing things
	Climber dummy1 (20, "iri", "f");
	Climber dummy2(30, "ric", "m");
	club.GetClimbers().push_back(dummy1);
	club.GetClimbers().push_back(dummy2);
	//make a few dummy mountains for testing purposes
	Mountain dummyMount1("lowest", 20);
	Mountain dummyMount2("highest", 4000);
	Mountain dummyMount3("mid1", 3000);
	Mountain dummyMount4("mid2", 3500);
	//add dummy mountains to dummy climbers
	club.GetClimbers()[0].GetMountains().push_back(dummyMount1);
	club.GetClimbers()[0].GetMountains().push_back(dummyMount2);
	club.GetClimbers()[1].GetMountains().push_back(dummyMount3);
	club.GetClimbers()[1].GetMountains().push_back(dummyMount4);
	//calculate average height and average mountain for dummy climbers
	club.GetClimbers()[0].AverageHeight();
	club.GetClimbers()[1].AverageHeight();
	club.GetClimbers()[0].HighestMountain();
	club.GetClimbers()[1].HighestMountain();

	//clubStats.WelcomeMessage(); 
	clubStats.SetOne(clubStats.GetExitApplication());
	//add a few dummy entries for testing purposes
	
	do {
		clubStats.DisplayMenu();
		clubStats.AskMenuOption();

		//add climber option
		if (clubStats.GetUserOptionChoice() == 1)
		{
			clubStats.DisplayAddClimberMenu();
			char userResponce;
			//will ask for climber info and create a climber obj
			do
			{
				club.AddClimber();
				userResponce = clubStats.AskYesNo("Would you like to add a mountain to current climber?");
				while (userResponce == 'y') 
				{
					club.GetClimbers()[club.GetClimbers().size() - 1].AddMountain();
					userResponce = clubStats.AskYesNo("Would you like to add a mountain to current climber?");
				}

				userResponce = clubStats.AskYesNo("Add another climber?");
			} while (userResponce == 'y');
				
			
			cout << "Done adding climbers. Going back to main menu.";
			//go back to main menu line
			clubStats.SetOne(clubStats.GetExitApplication());
			

		}
		else if (clubStats.GetUserOptionChoice() == 2)
		{
			char userResponce;
			do {
				cout << "\nDisplaying a list of currently exisiting climbers: " << endl;
				displayClimbersWithID(club.GetClimbers());
				cout << "Which climber would you like to add a mountain  to? [enter ID]: ";
				int id = 0;
				cin >> id;
				//check if id is valid here
				while (cin.fail() || id >= club.GetClimbers().size())
				{
					cout << "\nThat's not a valid ID. Enter valid ID: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> id;
				}
				club.GetClimbers()[id].AddMountain();
				userResponce = clubStats.AskYesNo("Would you like to add another mountain?");
			} while (userResponce == 'y');

			

		}

		//display statistics option
		else if (clubStats.GetUserOptionChoice() == 3)
		{
			clubStats.DisplayStatisticsSubMenu();
			clubStats.AskMenuOption();
			if (clubStats.GetUserOptionChoice() == 1)
			{
				// Display climber with recorded highest average climbed
				cout << "\n\nDisplaying climber with heighest average climbed." << endl;
				cout << "Climber name: " << club.ClimberWithHighestAverage().GetName();
				cout << " (" << club.ClimberWithHighestAverage().AverageHeight() << "m climbed on average)";
			}
			else if (clubStats.GetUserOptionChoice() == 2)
			{
				//Display highest mountain climbed by a club member
				cout << "\n\nDisplaying heighest mountain climbed by a club member: " << endl;
				cout << "Mountain name: " << club.ClimberWithClubsHighestClimbedMountain().HighestMountain().GetName();
				cout << ", mountain height:" << club.ClimberWithClubsHighestClimbedMountain().HighestMountain().GetHeight();
				cout << ", climbed by " << club.ClimberWithClubsHighestClimbedMountain().GetName() << endl;
				cout << "\nReturning to main menu" << endl;
			}
			else if (clubStats.GetUserOptionChoice() == 3)
			{
				//Display all mountains recorded with a height greater than a given level
				club.AllMountainsHigherThanGiven();
				displaySelectedMountains(club.GetAllMountainsHigherThanGiven());
				club.GetAllMountainsHigherThanGiven().clear();
			}
			else
			{
				//go back to main menu
				clubStats.SetOne(clubStats.GetExitApplication());
			}
		}

		//exit the application option
		else if (clubStats.GetUserOptionChoice() == 0)
		{
			clubStats.SetZero(clubStats.GetExitApplication());
		}

	} while (clubStats.GetExitApplication() == 1);

	//exit message
	cout << "\nThank you for using Misty Mountains Club application!" << endl;
	cout << "################ END OF APPLICATION ##############";

return 0;
}

