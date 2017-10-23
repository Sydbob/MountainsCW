#pragma once
#include "stdafx.h"
#include "Mountain.h"
#include "Climber.h"
#include "Club.h"

class ClubStats {
public:
	ClubStats();

	//void WelcomeMessage();
	void DisplayMenu();
	void DisplayStatisticsSubMenu();
	void DisplayAddClimberMenu();
	void AskMenuOption();
	char AskYesNo(string question);
	int GetUserOptionChoice() { return userOptionChoice; }

private:
	int userOptionChoice;
	

};