#pragma once
#ifndef __DATAMOVERTM__
#define __DATAMOVERTM__

#include <vector>
#include <string>
#include "PluginSettings.h"

class PLUGIN_API DataMoverTM {
public:
	// writing
	void SetType(int type);
	void AddData(int data);
	void AddData(float data);
	void AddData(std::string data);
	void AppendLine();
	bool WriteFile();

	// reading
	bool ReadFile();
	bool ReadLines();
	int GetNumLines();
	std::string GetLine(int index);

private:
	std::string currentLine;
	std::string currentFile;

	std::string fileName = "saveFile";
	std::string separator = " ";
};

#endif /* defined(__DATAMOVERTM__) */