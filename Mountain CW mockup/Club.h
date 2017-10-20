#pragma once
#include "Mountain.h"
#include "Climber.h"
#include "stdafx.h"

struct NameAndHeight
{
	string name;
	int height;
};

class Club {
public: 
	Club();

	vector<Climber>& GetClimbers(){ return climbers; }

	void AddClimber();
	Climber& ClimberWithHighestAverage();
	Climber& ClimberWithClubsHighestClimbedMountain();

private:
	vector<Climber> climbers;

};