#include "Mod.hpp"

MODAPI_ENTRYPOINT void InitMod(ModAPI* api, ModObject meta)
{
    api->Log("Hellow world!!!");
	api->Log(meta.name + " has been initialized!");
}