#pragma once 
#include "ModCore.hpp"

#define MODAPI_ENTRYPOINT extern "C" __declspec(dllexport) 

MODAPI_ENTRYPOINT void InitMod(ModAPI* api, ModObject meta);