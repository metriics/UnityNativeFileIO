#pragma once
#ifndef __STATSMANAGER__
#define __STATSMANAGER__

#include <vector>
#include <string>
#include "PluginSettings.h"

class PLUGIN_API StatsManager {
public:
	// 'setters'
	void AddAttack(bool didHit);
	void AddJump();
	void AddDash();

	// getters
	int GetAttacksHit();
	int GetAttacksMissed();
	int GetTotalAttacks();
	int GetTimesJumped();
	int GetTimesDashed();

	// file operations
	bool Load();
	bool Overwrite();
	bool Append();
	bool Erase();

	// application operations
	bool ClearCurrent();

private:
	int attacksHit = 0;
	int attacksMissed = 0;
	int timesAttacked = 0;
	int timesJumped = 0;
	int timesDashed = 0;

	std::string separator = " ";
	std::string statsFileName = "stats.txt";

	// string manipulation
	std::string DataToString();
	std::vector<int> StringToData(std::string data);
};

#endif /* defined(__STATSMANAGER__) */