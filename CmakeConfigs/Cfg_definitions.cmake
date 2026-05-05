if(WIN32)
    set(SFML_DLL_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/bin/")
    set(SFML_MAIN_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/lib/cmake/SFML")
elseif(LINUX)
    set(SFML_DLL_DIR "${CMAKE_SOURCE_DIR}/libs/SFML_linux/bin/")
    set(SFML_MAIN_DIR "${CMAKE_SOURCE_DIR}/libs/SFML_linux/")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML_linux/lib/cmake/SFML")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/Debug)
    set(SFML_LIBRARIES
        sfml-graphics-d
        sfml-window-d
        sfml-system-d
)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/Release)
    set(SFML_LIBRARIES
        sfml-graphics
        sfml-window
        sfml-system
)
endif()

set(ALL_LIBRARIES)
# set(ALL_LIBRARIES ${SFML_LIBRARIES})

if(WIN32)
elseif(LINUX)
set(ALL_LIBRARIES ${ALL_LIBRARIES} stdc++)
endif()