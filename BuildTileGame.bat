@echo off
REM Batch file to handle different build options

REM Check if argument is provided
if "%1"=="" (
    echo No argument provided. Please use one of the following:
    echo - release
    echo - debug
    echo - test
    echo - clean
    exit /b 1
)

REM Handle the different arguments
if "%1"=="release" (
    echo Running release build...
    cmake -DCMAKE_BUILD_TYPE:String=Release -DCMAKE_VERBOSE_MAKEFILE=ON -B build
    cmake --build build
    exit /b 0
)

if "%1"=="debug" (
    echo Running debug build...
    cmake -DCMAKE_BUILD_TYPE:String=Debug -DCMAKE_VERBOSE_MAKEFILE=ON -B build
    cmake --build build
    exit /b 0
)

if "%1"=="test" (
    echo Running tests...
    REM Add your test commands here
    echo Executing unit tests...
    REM Example: vstest.console.exe YourProjectTests.dll
    exit /b 0
)

if "%1"=="clean" (
    echo Cleaning build directories...
    cmake --build build --target clean
    exit /b 0
)

REM Handle unknown arguments
echo Invalid argument provided: %1
echo Please use one of the following: release, debug, test, clean
exit /b 1