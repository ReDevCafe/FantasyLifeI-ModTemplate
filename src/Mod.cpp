#include "Mod.hpp"

static Logger* logger = nullptr;

MODAPI_ENTRYPOINT void InitMod(ModAPI* api, ModObject meta)
{
    logger = new Logger(meta.name, api->Log);

    // Should output in the loader console something like: "Mod TestMod v1.0.0-ALPHA loaded!"
    logger->warn("Mod", meta.name, " v", meta.version, " loaded!");

    while(api->GetRecipeData() == nullptr)
        Sleep(1);

    TArray<TSetElement<TPair<FName, FGDRecipeData>>> test = api->GetRecipeData()->m_dataMap.Data;
    for (int i = 0; i < test.Count; ++i) 
    {
        try 
        {    
            // Put all recipes level to level 5 instantly
            test.Data[i].Value.Second.rarity = ERarityType::Rarity6;
        } 
        catch (std::exception &exception) 
        {
            logger->error(exception.what());
        }
    }
}