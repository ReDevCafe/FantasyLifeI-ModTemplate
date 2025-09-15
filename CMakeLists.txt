cmake_minimum_required(VERSION 3.10)
project(FLiMod LANGUAGES CXX C)

set(MODLOADER_BUILD_VERSION   "v20250915.2026")

################################################
##   DO NOT TOUCH TO THE FOLLOWING LINES      ##
##    UNLESS YOU KNOW WHAT YOU'RE DOING       ##
##                                            ##
## IF THE MOD FAILS TO COMPILE AFTER CHANGES, ##
##    PLEASE REVERT TO THE ORIGINAL STATES    ##
################################################

set(MODLOADER_URL "https://github.com/AmeliaCute/FantasyLifeI-ModLoader/releases/download/${MODLOADER_BUILD_VERSION}/ModLoader.lib")
set(MODLOADER_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/ModLoader.lib")

message(STATUS "Downloading ModLoader.lib from ${MODLOADER_URL}")
file(DOWNLOAD ${MODLOADER_URL} ${MODLOADER_LIB_PATH} SHOW_PROGRESS STATUS DOWNLOAD_STATUS)

list(GET DOWNLOAD_STATUS 0 DOWNLOAD_RESULT)
if(NOT DOWNLOAD_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to download ModLoader.lib (status ${DOWNLOAD_RESULT})")
endif()

add_library(${PROJECT_NAME} SHARED) 
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "CompiledBin"
    SUFFIX ".bin"
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

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/resource/Mod.json" DESTINATION ".")
install(FILES "$<TARGET_FILE:${PROJECT_NAME}>" DESTINATION ".")

set(CPACK_GENERATOR "ZIP")
set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_BINARY_DIR}/packages")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
include(CPack)
find_program(CPACK_EXECUTABLE NAMES cpack)

find_program(CPACK_EXECUTABLE NAMES cpack)
if (NOT CPACK_EXECUTABLE)
    message(WARNING "cpack not found on PATH - package_mod target will be unavailable")
else()
    add_custom_target(package_mod
        VERBATIM
    )

    add_dependencies(package_mod ${PROJECT_NAME})

    add_custom_command(TARGET package_mod POST_BUILD
        COMMAND "${CPACK_EXECUTABLE}" -G ZIP -C $<CONFIG>
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/packages"
        COMMAND ${CMAKE_COMMAND} -E remove -f "${CMAKE_BINARY_DIR}/packages/${PROJECT_NAME}.fliarchive"
        COMMAND ${CMAKE_COMMAND} -E rename
                "${CMAKE_BINARY_DIR}/packages/${PROJECT_NAME}.zip"
                "${CMAKE_BINARY_DIR}/packages/${PROJECT_NAME}.fliarchive"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        VERBATIM
    )
endif()