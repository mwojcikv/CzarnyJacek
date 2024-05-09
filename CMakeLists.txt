cmake_minimum_required(VERSION 3.25)

set(PROJECT_ID CzarnyJacek)
project(CzarnyJacek)

include_directories(include)

set(SOURCE_FILES
        src/gui
        src/game
        )

set(SOURCES_FILES_TESTS
        test/main_gtest.cpp
        test/test_classes.cpp
        test/test_rules.cpp
        )

include(./SetCommonConfig.cmake)
