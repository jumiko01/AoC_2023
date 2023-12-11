rm -r build
mkdir build
cd build
call cmake -G "Unix Makefiles" ..
call cmake --build .
call main.exe
