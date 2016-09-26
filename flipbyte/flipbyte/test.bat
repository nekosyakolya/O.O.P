set PROGRAM="%~1"

rem check the number of arguments
%PROGRAM% 
if %ERRORLEVEL% EQU 0 goto err                             


rem value validation         
%PROGRAM% 340
if %ERRORLEVEL% EQU 0 goto err


rem successful test          
%PROGRAM% 34
if %ERRORLEVEL% EQU 1 goto err 

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1