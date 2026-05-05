include(${CMAKE_SOURCE_DIR}/CmakeConfigs/Cfg_definitions.cmake)
# message(STATUS "DLL_FILES: ${DLL_FILES}")
# message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "OUTPUT_DIR: ${OUTPUT_DIR}")
if(WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        file(GLOB DLL_FILES "${SFML_DLL_DIR}/*.dll")
        foreach(DLL_FILE ${DLL_FILES})
            add_custom_command(
                TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${DLL_FILE} ${OUTPUT_DIR}
                )
        endforeach()
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")

        file(GLOB DLL_FILES "${SFML_DLL_DIR}/*.dll")
        foreach(DLL_FILE ${DLL_FILES})
            add_custom_command(
                TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${DLL_FILE} ${OUTPUT_DIR}
                )
        endforeach()
    endif()
elseif(LINUX)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        file(GLOB DLL_FILES "${SFML_DLL_DIR}/*.so*")
        foreach(DLL_FILE ${DLL_FILES})
            add_custom_command(
                TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${DLL_FILE} ${OUTPUT_DIR}
                )
        endforeach()
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")

        file(GLOB DLL_FILES "${SFML_DLL_DIR}/*.so*")
        foreach(DLL_FILE ${DLL_FILES})
            add_custom_command(
                TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${DLL_FILE} ${OUTPUT_DIR}
                )
        endforeach()
    endif()
endif()