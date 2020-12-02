#pragma once
#ifndef __WRAPPER__
#define __WRAPPER__

#include "PluginSettings.h"
#include "DataMoverTM.h"

#ifdef __cplusplus
extern "C" {
#endif

	// writing
	PLUGIN_API void SetType(int type);
	PLUGIN_API void AddIntData(int data);
	PLUGIN_API void AddFloatData(float data);
	PLUGIN_API void AddStringData(const char* data);
	PLUGIN_API void AppendLine();
	PLUGIN_API bool WriteFile();

	// reading
	PLUGIN_API bool ReadFile();
	PLUGIN_API bool ReadLines();
	PLUGIN_API int FindNextLine(std::string fileString, int prevNewline);
	PLUGIN_API int GetNumLines();
	PLUGIN_API const char* GetLine(int index);

#ifdef __cplusplus
}
#endif

#endif /* defined(__WRAPPER__) */