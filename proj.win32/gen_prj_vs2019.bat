@echo off
call mkdir vs2019
call cd vs2019
call cmake ../.. -G "Visual Studio 16 2019" -AWin32
call cd ..