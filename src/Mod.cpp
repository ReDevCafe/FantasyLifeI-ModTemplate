#include "MDK.h"

class MyMod : public ModBase
{
    Logger* logger;

    public:
    void OnPreLoad() override
    {
        logger = new Logger("MyMod");
        logger->info("Hellooooo");

        ItemData item = ModLoader::gameCache->GetItem(MATERIAL_FARAWAY_IRON);
        logger->info(item.GetName(LANG::ENGLISH));
    }

    void OnPostLoad() override
    {
        logger->info("Hellooooo 2");
    }
};

MOD_EXPORT ModBase* CraftMod() { return new MyMod(); }