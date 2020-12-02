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
void DataMoverTM::AddData(int data) {
	currentLine += (separator + std::to_string(data));
}

/// <summary>
/// This appends the param to the current line. 
/// Make sure to set the line type first.
/// </summary>
/// <param name="data"></param>
void DataMoverTM::AddData(float data) {
	currentLine += (separator + std::to_string(data));
}

/// <summary>
/// This appends the param to the current line. 
/// Make sure to set the line type first.
/// </summary>
/// <param name="data"></param>
void DataMoverTM::AddData(std::string data) {
	currentLine += (separator + data);
}

/// <summary>
/// Writes the current line to the file string. 
/// It will ignore empty lines.
/// </summary>
void DataMoverTM::AppendLine() {
	if (currentLine == "" || currentLine == " " || currentLine == "\n" || currentLine == "\r\n" || currentLine == separator) {
		return;
	}
	else {
		currentFile += (currentLine + "\n");
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
		in >> currentFile;
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
	return false;
}

/// <summary>
/// Returns the number of lines read from the file.
/// If the result is 0, you haven't called ReadFile() then ReadLines() yet, or the file was empty.
/// </summary>
/// <returns></returns>
int DataMoverTM::GetNumLines() {
	return 0;
}

std::string DataMoverTM::GetLine(int index) {
	return std::string();
}
