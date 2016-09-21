set PROGRAM="%~1"

rem check Invalid arguments count
%PROGRAM% in1.txt %TEMP%\in.txt 
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\in.txt in1.txt 
if %ERRORLEVEL% EQU 0 goto err

rem check Failed to open
%PROGRAM% ini.txt %TEMP%\out.txt "hello" "hi"
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\out.txt ini.txt 
if %ERRORLEVEL% EQU 0 goto err

rem check empty file
%PROGRAM% empty.txt out.txt "hello" "hi"
if %ERRORLEVEL% EQU 1 goto err
fc.exe out.txt empty.txt
if %ERRORLEVEL% EQU 1 goto err

rem check empty line
%PROGRAM% in1.txt out1.txt "" "hi"
if %ERRORLEVEL% EQU 0 goto err
fc.exe out1.txt in1.txt
if %ERRORLEVEL% EQU 0 goto err



echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1