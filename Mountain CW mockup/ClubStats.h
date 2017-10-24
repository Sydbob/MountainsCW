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
	int& GetExitApplication() { return exitApplication; }
	char AskYesNo(string question);
	void SetOne(int& integer) {integer = 1; }
	void SetZero(int& integer) { integer = 0; }
	int GetUserOptionChoice() { return userOptionChoice; }

private:
	int userOptionChoice;
	int exitApplication;
	

};