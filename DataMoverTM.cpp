#include "DataMoverTM.h"

#include <fstream>
#include <streambuf>

/// <summary>
/// This will erase all data in the line (if any) since the line starts with the type int.
/// Use this function before adding data to the line.
/// </summary>
/// <param name="type"></param>
void DataMoverTM::SetType(int type) {
	currentLine = std::to_string(type);
}

/// <summary>
/// This appends the param to the current line. 
/// Make sure to set the line type first.
/// </summary>
/// <param name="data"></param>
void DataMoverTM::AddIntData(int data) {
	currentLine += (separator + std::to_string(data));
}

/// <summary>
/// This appends the param to the current line. 
/// Make sure to set the line type first.
/// </summary>
/// <param name="data"></param>
void DataMoverTM::AddFloatData(float data) {
	currentLine += (separator + std::to_string(data));
}

/// <summary>
/// This appends the param to the current line. 
/// Make sure to set the line type first.
/// </summary>
/// <param name="data"></param>
void DataMoverTM::AddStringData(const char* data) {
	currentLine += (separator + data);
}

/// <summary>
/// Writes the current line to the file string. 
/// It will ignore empty lines.
/// </summary>
void DataMoverTM::AppendLine() {
	if (currentLine == "" || currentLine == " " || currentLine == "'\n'" || currentLine == "'\r\n'" || currentLine == separator) {
		return;
	}
	else {
		currentFile += (currentLine + '\n');
	}
}

/// <summary>
/// Writes the file string to the file.
/// </summary>
bool DataMoverTM::WriteFile() {
	std::ofstream out(fileName, std::ofstream::trunc);
	if (out) {
		out << currentFile;
		out.close();
		return true;
	}

	return false;
}

/// <summary>
/// Reads all characters from file into current file string.
/// Use this before calling ReadLines()
/// </summary>
/// <returns></returns>
bool DataMoverTM::ReadFile() {
	std::ifstream in(fileName);
	if (in) {
		currentFile = std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		in.close();
	}
	else {
		return false;
	}
}

/// <summary>
/// Stores all lines from the previously read file in a vector.
/// Use this after calling ReadFile()
/// </summary>
/// <returns></returns>
bool DataMoverTM::ReadLines() {
	// find all newline indices
	bool allNewlinesFound = false;
	std::vector<int> newlineIndices = { -1 };
	int prevNewline = -1;

	while (!allNewlinesFound) {
		int curNewline = FindNextLine(currentFile, prevNewline);
		if (curNewline == -1) {
			allNewlinesFound = true;
		}
		else {
			newlineIndices.push_back(curNewline);
			prevNewline = curNewline;
		}
	}

	// store all lines stripped of newline characters
	for (int i = 0; i < newlineIndices.size(); i++) {
		std::string curLine;
		if (i == newlineIndices.size() - 1) { // last newline
			curLine = "";
		}
		else {
			if (i == newlineIndices.size() - 1) {
				curLine = currentFile.substr(newlineIndices[i] + 1, std::string::npos);
			}
			else {
				int lineLen = GetLineLength(newlineIndices[i], newlineIndices[i + 1]);
				curLine = currentFile.substr(newlineIndices[i] + 1, lineLen);
			}
		}
		lines.push_back(curLine);
	}

	return true;
}

/// <summary>
/// Returns the position of the next newline character in the string.
/// Works with \n and \r\n
/// </summary>
/// <returns></returns>
int DataMoverTM::FindNextLine(std::string fileString, int startAt) {
	// UNIX newline
	if (fileString.find('\n', startAt + 1) != -1) {
		return fileString.find('\n', startAt + 1);
	}
	// DOS newline
	else if (fileString.find('\r\n', startAt + 1) != -1) {
		return fileString.find('\r\n', startAt + 1);
	}

	// if we find nothing, return -1
	return -1;
}

/// <summary>
/// Returns the number of lines read from the file.
/// If the result is 0, you haven't called ReadFile() then ReadLines() yet, or the file was empty.
/// </summary>
/// <returns></returns>
int DataMoverTM::GetNumLines() {
	return lines.size();
}

const char* DataMoverTM::GetLine(int index) {
	if (index >= lines.size()) {
		return std::string("").c_str();
	}

	const char* cstr = lines.at(index).c_str();
	return cstr;
}

int DataMoverTM::GetLineLength(int prevNewline, int curNewline) {
	if (prevNewline == -1) {
		return curNewline;
	}
	else {
		return (curNewline - prevNewline - 1);
	}
}
