Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(
  tests
  #sources
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/buffer.h
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/helpers.h
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/buffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/helpers.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests-helpers.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests-buffer.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)


# automatic discovery of unit tests
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/contrib)
include(Catch)
catch_discover_tests(tests)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})