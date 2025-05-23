# Fantasy Life I  ModTemplate
A template for creating mods for Fantasy Life I using C++

## Requirements
- Cmake 
- MSVC (recommended)
- x64 build configuration

## Building the mod
1. Clone or download this repository
```bash
$ git clone https://github.com/ReDevCafe/FantasyLifeI-ModTemplate MyMod
``` 

2. Use CMake to configure and generate project files
```bash
$ mkdir build
$ cd build
$ cmake .. -A x64
```

## Configuring Mod Info
> [!TIP]
> You can customize youuur mod's metadata directly in the `CMakeLists.txt` file by editing the following variables:
> ```cmake
> set(MOD_NAME "ANiceMod")
> set(MOD_AUTHOR "CuteDev")
> set(MOD_MAJOR_VER 1)
> set(MOD_MINOR_VER 0)
>```

## Installing the mod
1. Build the project
```bash
$ cmake --build . --config Release
```
2. After building, create a new folder inside the Mods directory of your game
3. Name the folder as you like 
4. Place **both** of thee following filees inside that folder:
- `Mod.json`
- And the compiled Mod DLL

> [!WARNING] 
> Both files are required for the mod to be recognized and initialized by the mod loader

> [!NOTE]  
> ```mathematica
> Fantasy Life I/
> ├── Mods/
> |   └── MyCuteModUwU/
> |       ├── Mod.json
> |       └── MyCuteModUwU.dll
> ```