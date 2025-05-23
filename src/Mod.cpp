#include "../include/ModAPI.h"

extern "C" __declspec(dllexport) void InitMod(ModAPI* api, ModMeta meta)
{
    api->Log("Hellow world!!!");
	api->Log(meta.name + " has been initialized!");
}