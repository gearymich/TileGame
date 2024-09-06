cmake_minimum_required(VERSION 3.16)

project(TileGame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/inc)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB TILEGAME_SOURCE ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB TILEGAME_HEADERS ${CMAKE_SOURCE_DIR}/inc/*.h)
file(GLOB TILEGAME_FORMS ${CMAKE_SOURCE_DIR}/inc/*.ui)
file(GLOB TILEGAME_TESTS ${CMAKE_SOURCE_DIR}/test/*)

add_library(${PROJECT_NAME}
    ${TILEGAME_SOURCE}
)

add_executable(${PROJECT_NAME}_exe
    ${TILEGAME_HEADERS}
    ${TILEGAME_FORMS}
    main.cpp
)

set_property(TARGET ${PROJECT_NAME}_exe PROPERTY OUTPUT_NAME ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/inc>
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME})

####### Test #######
include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests
    ${TILEGAME_TESTS}
)

target_link_libraries(tests
    GTest::gtest_main
    ${PROJECT_NAME}
)

include(GoogleTest)
gtest_discover_tests(tests)