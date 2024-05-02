cmake_minimum_required(VERSION 3.25)

set(PROJECT_ID CzarnyJacek)

set(SOURCE_FILES
        src/game/gameRules.cpp
        src/game/gameClasses.cpp
        )

set(SOURCES_FILES_TESTS
        test/test_classes.cpp
        test/test_rules.cpp
        )

include(./SetCommonConfig.cmake)
