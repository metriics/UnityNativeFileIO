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
	void AddIntData(int data);
	void AddFloatData(float data);
	void AddStringData(const char* data);
	void AppendLine();
	bool WriteFile();

	// reading
	bool ReadFile();
	bool ReadLines();
	int FindNextLine(std::string fileString, int prevNewline);
	int GetNumLines();
	const char* GetLine(int index);

private:
	int GetLineLength(int prevNewline, int curNewline);

	std::string currentLine;
	std::string currentFile;

	std::string fileName = "saveFile";
	std::string separator = " ";

	std::vector<std::string> lines;
};

#endif /* defined(__DATAMOVERTM__) */