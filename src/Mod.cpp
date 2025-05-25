#include "Mod.hpp"

static Logger* logger = nullptr;

MODAPI_ENTRYPOINT void InitMod(ModAPI* api, ModObject meta)
{
    logger = new Logger(meta.name, api->Log);

    // Should output in the loader console something like: "Mod TestMod v1.0.0-ALPHA loaded!"
    logger->warn("Mod", meta.name, " v", meta.version, " loaded!");
}