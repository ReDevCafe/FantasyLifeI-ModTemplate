CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
PROJECT(MyMod LANGUAGES CXX C)


set(MOD_NAME    "MyMod")
set(MOD_AUTHOR  "Me")
set(MOD_VERSION "1.0.0-REL")

#########################################
## DO NOT TOUCH TO THE FOLLOWING LINES ##
#########################################
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

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/ModLoader.dll"
)