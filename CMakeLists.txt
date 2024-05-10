cmake_minimum_required(VERSION 3.25)

set(PROJECT_ID CzarnyJacek)
project(CzarnyJacek)

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

