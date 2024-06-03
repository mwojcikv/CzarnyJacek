cmake_minimum_required(VERSION 3.22)

set(PROJECT_ID CzarnyJacek)
project(CzarnyJacek)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 11b73743c42cf7ecd7c596ba83fdbf1150ffa96c
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(SFML)

include_directories(include)

include_directories(SFML)

set(SOURCE_FILES
        src/gui/commandLineInterface.cpp
        src/game/gameClasses.cpp
        src/game/gameRules.cpp
)

set(SOURCES_FILES_TESTS
        test/test_classes.cpp
        test/test_rules.cpp
        test/test_gui.cpp
)

include(./SetCommonConfig.cmake)

add_executable(CzarnyJacek main.cpp ${SOURCE_FILES})


target_link_libraries(CzarnyJacek PRIVATE sfml-graphics sfml-window sfml-system)

