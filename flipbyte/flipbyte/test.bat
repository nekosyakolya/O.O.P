set PROGRAM="%~1"

rem check the number of arguments
%PROGRAM%            > %TEMP%\testValue1.txt
if %ERRORLEVEL% EQU 0 goto err

rem value validation         
%PROGRAM% 340 output > %TEMP%\testValue2.txt
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\testValue2.txt value2.txt 
if %ERRORLEVEL% EQU 1 goto err  


rem successful test          
%PROGRAM% 34 %TEMP%\testValue3.txt
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\testValue3.txt value3.txt 
if %ERRORLEVEL% EQU 1 goto err
 


rem failled test          
%PROGRAM% hi output > %TEMP%\testValue4.txt
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\testValue4.txt value4.txt 
if %ERRORLEVEL% EQU 1 goto err 


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1