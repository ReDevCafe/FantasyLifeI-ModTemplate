cmake_minimum_required(VERSION 3.10)
project(FLiMod LANGUAGES CXX C)

set(MOD_NAME            "MyMod")
set(MOD_AUTHOR          "Me")
set(MOD_VERSION         "1.0.0-REL")
set(MODLOADER_VERSION   "v20250827.1611")

################################################
##   DO NOT TOUCH TO THE FOLLOWING LINES      ##
##    UNLESS YOU KNOW WHAT YOU'RE DOING       ##
##                                            ##
## IF THE MOD FAILS TO COMPILE AFTER CHANGES, ##
##    PLEASE REVERT TO THE ORIGINAL STATES    ##
################################################

set(MODLOADER_URL "https://github.com/AmeliaCute/FantasyLifeI-ModLoader/releases/download/${MODLOADER_VERSION}/ModLoader.lib")
set(MODLOADER_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/ModLoader.lib")

message(STATUS "Downloading ModLoader.lib from ${MODLOADER_URL}")
file(DOWNLOAD ${MODLOADER_URL} ${MODLOADER_LIB_PATH} SHOW_PROGRESS STATUS DOWNLOAD_STATUS)

list(GET DOWNLOAD_STATUS 0 DOWNLOAD_RESULT)
if(NOT DOWNLOAD_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to download ModLoader.lib (status ${DOWNLOAD_RESULT})")
endif()

add_library(${PROJECT_NAME} SHARED) 
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Mod.json.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Mod.json"
    @ONLY
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${MOD_NAME}
    SUFFIX ".mod"
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ModLoader/include
)

file(GLOB_RECURSE PROJECT_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE}
)

add_library(ModLoader STATIC IMPORTED)
set_target_properties(ModLoader PROPERTIES
    IMPORTED_LOCATION ${MODLOADER_LIB_PATH}    
)

target_link_libraries(${PROJECT_NAME} PRIVATE ModLoader)