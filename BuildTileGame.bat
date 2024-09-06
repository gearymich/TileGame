REM Script to support build of TileGame project

cmake -DCMAKE_BUILD_TYPE:String=Debug -DCMAKE_VERBOSE_MAKEFILE=ON -B build
cmake --build build