cmake_minimum_required(VERSION 3.22)

set(PROJECT_ID CzarnyJacek)
project(CzarnyJacek)


include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)


include_directories(include)

set(SOURCE_FILES
        src/gui/commandLineInterface.cpp
        src/game/gameClasses.cpp
        src/game/gameRules.cpp
        )

set(SOURCES_FILES_TESTS
        test/test_classes.cpp
        test/test_rules.cpp
        )

include(./SetCommonConfig.cmake)

add_executable(CzarnyJacek main.cpp)

target_link_libraries(CzarnyJacek sfml-graphics)
