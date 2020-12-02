#include "Wrapper.h"

DataMoverTM dm;

PLUGIN_API void SetType(int type) {
	return dm.SetType(type);
}

PLUGIN_API void AddIntData(int data) {
	return dm.AddIntData(data);
}

PLUGIN_API void AddFloatData(float data) {
	return dm.AddFloatData(data);
}

PLUGIN_API void AddStringData(const char* data) {
	return dm.AddStringData(data);
}

PLUGIN_API void AppendLine() {
	return dm.AppendLine();
}

PLUGIN_API bool WriteFile() {
	return dm.WriteFile();
}

PLUGIN_API bool ReadFile() {
	return dm.ReadFile();
}

PLUGIN_API bool ReadLines() {
	return dm.ReadLines();
}

PLUGIN_API int FindNextLine(std::string fileString, int prevNewline) {
	return dm.FindNextLine(fileString, prevNewline);
}

PLUGIN_API int GetNumLines() {
	return dm.GetNumLines();
}

PLUGIN_API const char* GetLine(int index) {
	return dm.GetLine(index);
}
