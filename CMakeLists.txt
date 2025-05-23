CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
PROJECT(Mod LANGUAGES CXX C)


set(MOD_NAME "ANiceMod")
set(MOD_AUTHOR "CuteDev")
set(MOD_MAJOR_VER 1)
set(MOD_MINOR_VER 0)

#########################################
## DO NOT TOUCH TO THE FOLLOWING LINES ##
#########################################
set(DLL_NAME "${MOD_NAME}.dll")
add_library(${PROJECT_NAME} SHARED) 

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Mod.json.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Mod.json"
    @ONLY
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${MOD_NAME}
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB_RECURSE PROJECT_SOURCE "src/*.cpp")

target_sources(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE}
)