#pragma once
#include "constants.h"

extern HMODULE hModule = GetModuleHandle(nullptr);
uintptr_t baseAddress = (uintptr_t)GetModuleHandle(nullptr);
extern Player* localPlayer = *(Player**)(baseAddress + 0x2A2560);