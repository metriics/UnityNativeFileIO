#pragma once
#ifndef __WRAPPER__
#define __WRAPPER__

#include "PluginSettings.h"
#include "StatsManager.h"

#ifdef __cplusplus
extern "C" {
#endif

	// my functions here
	// 'setters'
	PLUGIN_API void AddAttack(bool didHit);
	PLUGIN_API void AddJump();
	PLUGIN_API void AddDash();

	// getters
	PLUGIN_API int GetAttacksHit();
	PLUGIN_API int GetAttacksMissed();
	PLUGIN_API int GetTotalAttacks();
	PLUGIN_API int GetTimesJumped();
	PLUGIN_API int GetTimesDashed();

	// file operations
	PLUGIN_API bool Load();
	PLUGIN_API bool Overwrite();
	PLUGIN_API bool Append();
	PLUGIN_API bool Erase();

	// application operations
	PLUGIN_API bool ClearCurrent();

#ifdef __cplusplus
}
#endif

#endif /* defined(__WRAPPER__) */