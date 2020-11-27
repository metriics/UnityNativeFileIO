#include "StatsManager.h"

#include <fstream>
#include <streambuf>

void StatsManager::AddAttack(bool didHit) {
	if (didHit) {
		this->attacksHit++;
	}
	else {
		this->attacksMissed++;
	}
}

void StatsManager::AddJump() {
	this->timesJumped++;
}

void StatsManager::AddDash() {
	this->timesDashed++;
}

int StatsManager::GetAttacksHit() {
	return this->attacksHit;
}

int StatsManager::GetAttacksMissed() {
	return this->attacksMissed;
}

int StatsManager::GetTotalAttacks() {
	return (this->attacksHit + this->attacksMissed);
}

int StatsManager::GetTimesJumped() {
	return this->timesJumped;
}

int StatsManager::GetTimesDashed() {
	return this->timesDashed;
}

std::string StatsManager::DataToString() {
	std::string data;
	data = std::to_string(GetAttacksHit()) + separator + std::to_string(GetAttacksMissed()) + separator + std::to_string(GetTotalAttacks()) + separator + std::to_string(GetTimesJumped()) + separator + std::to_string(GetTimesDashed());

	return data;
}

std::vector<int> StatsManager::StringToData(std::string data) {
	std::vector<int> dataFromString;

	std::vector<int> separatorIndices;
	int prevSeparator = 0;

	for (int i = 0; i < 4; i++) {
		int curSeparator = data.find(separator, prevSeparator + 1);
		separatorIndices.push_back(curSeparator);
		prevSeparator = curSeparator;
	}

	dataFromString.push_back(std::stoi(data.substr(0, separatorIndices[0])));
	dataFromString.push_back(std::stoi(data.substr(separatorIndices[0] + 1, separatorIndices[1] - separatorIndices[0] - 1)));
	dataFromString.push_back(std::stoi(data.substr(separatorIndices[1] + 1, separatorIndices[2] - separatorIndices[1] - 1)));
	dataFromString.push_back(std::stoi(data.substr(separatorIndices[2] + 1, separatorIndices[3] - separatorIndices[2] - 1)));
	dataFromString.push_back(std::stoi(data.substr(separatorIndices[3] + 1, std::string::npos)));

	return dataFromString;
}

bool StatsManager::Load() {
	std::ifstream in(statsFileName);
	if (!in) {
		// load failure
		return false;
	}

	std::string dataString((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	std::vector<int> dataFromString = StringToData(dataString);

	attacksHit = dataFromString[0];
	attacksMissed = dataFromString[1];
	timesAttacked = dataFromString[2];
	timesJumped = dataFromString[3];
	timesDashed = dataFromString[4];

	return true;
}

bool StatsManager::Overwrite() {
	std::string dataString(DataToString());

	std::ofstream out(statsFileName, std::ofstream::trunc);
	if (out) {
		out << dataString;
		out.close();
		return true;
	}

	return false;
}

bool StatsManager::Append() {
	bool existingFile = false;

	std::ifstream in(statsFileName);
	if (in) {
		// load failure
		existingFile = true;
	}

	if (existingFile) {
		std::string oldDataString((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		std::vector<int> oldData = StringToData(oldDataString);

		attacksHit += oldData[0];
		attacksMissed += oldData[1];
		timesAttacked += oldData[2];
		timesJumped += oldData[3];
		timesDashed += oldData[4];
	}

	std::string dataString(DataToString());

	std::ofstream out(statsFileName, std::ofstream::trunc);
	if (out) {
		out << dataString;
		out.close();
		return true;
	}

	return false;
}

bool StatsManager::Erase() {
	std::ofstream out(statsFileName, std::ofstream::trunc);
	if (out) {
		out.close();
		return true;
	}

	return false;
}

bool StatsManager::ClearCurrent() {
	this->attacksHit = 0;
	this->attacksMissed = 0;
	this->timesAttacked = 0;
	this->timesJumped = 0;
	this->timesDashed = 0;

	return true;
}
