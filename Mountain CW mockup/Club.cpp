#include "stdafx.h"
#include "Club.h"
#include "Climber.h"
#include "Mountain.h"


Club::Club() {};



void Club::AddClimber()
{
	Climber newClimber;
	//ask user for gender, age and name of new climber
	newClimber.GetInfo();
	//check if the name provided is unique
	for (int i = 0; i < climbers.size(); ++i)
	{
		if (climbers[i].GetName() == newClimber.GetName())
		{
			cout << "\nThis name is already taken. Enter a different one";
			newClimber.AskName();
		}
	}
	//add new climber to list of climber objects
	this->climbers.push_back(newClimber);
	
}


Climber& Club::ClimberWithHighestAverage()
{
	Climber highestAverageClimber;
	int highestAverageIndex = 0;
	for (unsigned int i = 0; i < climbers.size(); ++i)
	{
		if (climbers[i].GetAverageHeight() > climbers[highestAverageIndex].GetAverageHeight() )
		{
			highestAverageIndex = i;
			highestAverageClimber = climbers[highestAverageIndex];
		}
	}
	
	return climbers[highestAverageIndex];
} 

Climber& Club::ClimberWithClubsHighestClimbedMountain()
{
	Climber climberWithClubsHighestMountain;
	int highestClimberIndex = 0;

	for (unsigned int i = 0; i < climbers.size(); ++i)
	{
		if (climbers[highestClimberIndex].GetHeighestHeight() < climbers[i].GetHeighestHeight())
		{
			highestClimberIndex = i;
			climberWithClubsHighestMountain = climbers[highestClimberIndex];
		}
	}
	return climbers[highestClimberIndex];
}

vector <Mountain>& Club::AllMountainsHigherThanGiven()
{
	int minHeight;
	vector<Mountain>& selectedMountains= allMountainsHigherThanGiven;
	
	//add all climber mountains to a vector
	for (unsigned int i = 0; i<climbers.size(); ++i )
	{
		for (unsigned int k = 0; k < climbers[i].GetMountains().size(); ++k)
		{
			allDocumentedMountains.push_back(climbers[i].GetMountains()[k]);
		}
	}
	cout << "Enter min Height by which to filter mountains: ";
	cin >> minHeight;

	for (unsigned int i = 0; i < allDocumentedMountains.size(); ++i)
	{
		if (allDocumentedMountains[i].GetHeight() > minHeight)
		{
			selectedMountains.push_back(allDocumentedMountains[i]);
		}
	}
	allDocumentedMountains.clear();
	return selectedMountains;
}
