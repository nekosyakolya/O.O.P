set PROGRAM="%~1"

rem check determinant = 0
%PROGRAM% in1.txt %TEMP%\out.txt
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\out.txt in1.txt
if %ERRORLEVEL% EQU 0 goto err

rem check Invalid arguments count
%PROGRAM% in1.txt %TEMP%\in1.txt out.txt
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\out.txt in1.txt 
if %ERRORLEVEL% EQU 0 goto err

rem check Failed to open
%PROGRAM% ini.txt %TEMP%\out.txt
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\out.txt ini.txt 
if %ERRORLEVEL% EQU 0 goto err

rem check finding the inverse matrix
%PROGRAM% in.txt %TEMP%\out.txt
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\out.txt in.txt
if %ERRORLEVEL% EQU 0 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1