#include "stdafx.h"
#include "Club.h"


Club::Club() {};

void Club::AddClimber()
{
	Climber newClimber;
	//ask user for gender, age and name of new climber
	newClimber.GetInfo();
	
	//add new climber to list of climber objects
	climbers.push_back(newClimber);
}


Climber Club::ClimberWithHighestAverage()
{
	Climber highestAverageClimber;
	for (unsigned int i = 0; i < climbers.size(); ++i)
	{
		int highestAverageIndex = 0;
		if (climbers[i].GetAverage() < climbers[highestAverageIndex].GetAverage() )
		{
			highestAverageIndex = i;
			highestAverageClimber = climbers[highestAverageIndex];
		}
	}
	
	return highestAverageClimber;
	
} 

/*
NameAndHeight HighestMountainClimbed()
{
	//loop through cllimbers
	//loop through their mountain climbed
	//get highest mountain climbed by a climber1
	//add it to highestst current
	//got through rest of climber get their highest 
	//and compare to current 
	//if it's higher-replace

}

NameAndHeight AllMountainsHigherThan(int minHeight)
{

} */