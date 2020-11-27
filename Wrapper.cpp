#include "Wrapper.h"

StatsManager manager;

PLUGIN_API void AddAttack(bool didHit) {
	return manager.AddAttack(didHit);
}

PLUGIN_API void AddJump() {
	return manager.AddJump();
}

PLUGIN_API void AddDash() {
	return manager.AddDash();
}

PLUGIN_API int GetAttacksHit() {
	return manager.GetAttacksHit();
}

PLUGIN_API int GetAttacksMissed() {
	return manager.GetAttacksMissed();
}

PLUGIN_API int GetTotalAttacks() {
	return manager.GetTotalAttacks();
}

PLUGIN_API int GetTimesJumped() {
	return manager.GetTimesJumped();
}

PLUGIN_API int GetTimesDashed() {
	return manager.GetTimesDashed();
}

PLUGIN_API bool Load() {
	return manager.Load();
}

PLUGIN_API bool Overwrite() {
	return manager.Overwrite();
}

PLUGIN_API bool Append() {
	return manager.Append();
}

PLUGIN_API bool Erase() {
	return manager.Erase();
}

PLUGIN_API bool ClearCurrent() {
	return manager.ClearCurrent();
}
