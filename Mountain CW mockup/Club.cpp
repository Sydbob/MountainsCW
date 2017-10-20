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
	Climber& highestAverageClimber = climbers[0];
	for (unsigned int i = 0; i < climbers.size(); ++i)
	{
		int highestAverageIndex = 0;
		if (climbers[i].GetAverage() > climbers[highestAverageIndex].GetAverage() )
		{
			highestAverageIndex = i;
			highestAverageClimber = climbers[highestAverageIndex];
		}
	}
	
	return highestAverageClimber;
	
} 

Climber& Club::ClimberWithClubsHighestClimbedMountain()
{
	Climber& climberWithClubsHighestMountain = climbers[0];
	for (unsigned int i = 0; i < climbers.size(); ++i)
	{
		int highestClimberIndex = 0;
		if (climbers[highestClimberIndex].HighestMountain().GetHeight() < climbers[i].HighestMountain().GetHeight())
		{
			highestClimberIndex = i;
			climberWithClubsHighestMountain = climbers[highestClimberIndex];
		}
	}
	return climberWithClubsHighestMountain;
}

