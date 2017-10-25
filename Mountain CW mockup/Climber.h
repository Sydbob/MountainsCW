#pragma once

#include "Mountain.h"

//custom structure that can return 3 types of data for GetInfo method
struct Info {
	string name;
	int age;
	string gender;
};


class Climber 
{

public:
	Climber();
	Climber(int climberAge, string climberName, string climberGender);

	string AskGender();
	string AskName();
	int AskAge();

	Mountain& HighestMountain(); 
	float AverageHeight();	
	vector<Mountain> mountainsGreaterThan(int minHeight);
	void AddMountain();

	void DisplayInfo();
	void DisplayMountains(vector<Mountain> mountains);

	Info GetInfo();
	int& GetHeighestHeight() { return highestMountainHeight; }
	float& GetAverageHeight() { return averageHeight; }
	vector<Mountain>& GetMountains() { return mountains; }
	string GetName() { return climberName; }
	string GetGender() { return climberGender; }
	int GetAge() { return climberAge; }
	

private:
	vector<Mountain> mountains;
	int climberAge;
	float averageHeight; 
	string climberName;
	string climberGender;
	int highestMountainHeight;
};