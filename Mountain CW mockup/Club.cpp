#include "stdafx.h"
#include "Club.h"


Club::Club() {};

void Club::AddClimber()
{
	Climber newClimber;
	//ask user for gender, age and name of new climber
	newClimber.GetInfo();
	
	//add new climber to list of climber objects
	this->climbers.push_back(newClimber);
	
}


Climber& Club::ClimberWithHighestAverage()
{
	Climber highestAverageClimber;
	int highestAverageIndex = 0;
	for (unsigned int i = 0; i < climbers.size(); ++i)
	{
		if (climbers[i].GetAverage() > climbers[highestAverageIndex].GetAverage() )
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

