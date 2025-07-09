#include "MDK.h"

class MyMod : public ModBase
{
    Logger* logger;

    public:

    // Called when the game start
    void OnPreLoad() override
    {
        // Creating your own logger
        logger = new Logger("MyMod");
        logger->info("Hellooooo");

        // Retrieve the Faraway Iron item from the ModLoader cache
        ItemData item = ModLoader::gameCache->GetItem(MATERIAL_FARAWAY_IRON);

        // Print the item's english name
        logger->info(item.GetName(LANG::ENGLISH));

        // Modify item properties
        item.SetName(LANG::ENGLISH, L"MODIFIED BY MOD");
        item.SetQuality(EItemQualityType::EItemQualityType__Quality4);
    }

    // Called when the game loads the save file
    void OnPostLoad() override
    {
        logger->info("Hellooooo 2");
    }
};

MOD_EXPORT ModBase* CraftMod() { return new MyMod(); }