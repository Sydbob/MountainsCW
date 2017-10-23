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
	vector<Mountain>& GetAllMountainsHigherThanGiven() { return allMountainsHigherThanGiven; }
	Climber& ClimberWithClubsHighestClimbedMountain();
	vector <Mountain>& AllMountainsHigherThanGiven();

private:
	vector<Climber> climbers;
	vector<Mountain> allMountainsHigherThanGiven;
	vector<Mountain> allDocumentedMountains;

};