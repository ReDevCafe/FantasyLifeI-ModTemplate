# Fantasy Life I  ModTemplate
A template for creating mods for Fantasy Life I using C++

## Requirements
- CMake 
- MSVC or CLang
- x64 build configuration

## Building the mod
1. Clone or download this repository
```bash
$ git clone --recurse-submodules https://github.com/ReDevCafe/FantasyLifeI-ModTemplate MyMod
``` 

2. Use CMake to configure and generate project files
```bash
$ mkdir build
$ cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

## Configuring Mod Info
> [!TIP]
> You can customize your mod's metadata directly in the `CMakeLists.txt` file by editing the following variables:
> ```cmake
> set(MOD_NAME    "MyMod")
> set(MOD_AUTHOR  "Me")
> set(MOD_VERSION "1.0.0-REL")
>```

## Installing the mod
1. Build the project
```bash
$ cmake --build build --config Release --target package_mod
```
2. After building place the .fliarchive inside Game/Content/Mods

> [!NOTE]  
> ```mathematica
> Fantasy Life I/
> ├── Mods/
> |   └── MyMod.fliarchive
> ```

## Troubleshooting
1. ModLoader returns `Missing CraftMod in 'mymod'`
    > this means you forgot to add the following lines at the ned of your code:
    > ```cpp
    > MOD_EXPORT ModBase* CraftMod() { return new MyMod(); }
    > ```
    > Here's how your code should look:
    > ```cpp
    > class MyMod : public ModBase
    > {
    >   public:
    >   void OnPreLoad()  override {}
    >   void OnPostLoad() override {}
    >   // Your additional code here
    > }
    > 
    > MOD_EXPORT ModBase* CraftMod() { return new MyMod(); }
    > ```

2. ModLoader returns `Failed to load: 'mymod'`
    > This usually means the program was not compiled correctly. If you made changes to the `CMakeLists.txt` file, try reverting them to the original state.