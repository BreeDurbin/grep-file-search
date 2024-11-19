add_executable(
    ${PROJECT_NAME}
    #sources
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/helpers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/helpers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/buffer.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)