@echo off
call mkdir vs2022
call cd vs2022
call cmake ../.. -G "Visual Studio 17 2022" -AWin32
call cd ..