set PROGRAM="%~1"

rem check Invalid arguments count
%PROGRAM% in1.txt %TEMP%\in.txt 
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\in.txt in1.txt 
if %ERRORLEVEL% EQU 0 goto err

rem check Failed to open
%PROGRAM% ini.txt %TEMP%\ini.txt "hello" "hi"
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\ini.txt ini.txt 
if %ERRORLEVEL% EQU 0 goto err

rem check empty file
%PROGRAM% empty.txt  %TEMP%\empty.txt "hello" "hi"
if %ERRORLEVEL% EQU 1 goto err1
fc.exe %TEMP%\empty.txt empty.txt
if %ERRORLEVEL% EQU 1 goto err

rem check empty line
%PROGRAM% in1.txt %TEMP%\in1.txt "" "hi"
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\in1.txt in1.txt
if %ERRORLEVEL% EQU 0 goto err

rem check ma mama
%PROGRAM% in1.txt  %TEMP%\in1.txt "ma" "mama"
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\in1.txt in1.txt
if %ERRORLEVEL% EQU 0 goto err


rem check 1231234
%PROGRAM% in2.txt %TEMP%\in2.txt "1231234" "hi"
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\in2.txt in2.txt
if %ERRORLEVEL% EQU 0 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1