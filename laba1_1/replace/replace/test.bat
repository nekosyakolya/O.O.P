set PROGRAM="%~1"

rem check the number of arguments
%PROGRAM% in1.txt %TEMP%\in.txt 
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\in.txt in1.txt 
if %ERRORLEVEL% EQU 0 goto err

rem check opening a nonexistent file 
%PROGRAM% ini.txt %TEMP%\ini.txt "hello" "hi"
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\ini.txt ini.txt 
if %ERRORLEVEL% EQU 0 goto err

rem check opening an empty file
%PROGRAM% empty.txt  %TEMP%\empty.txt "hello" "hi"
if %ERRORLEVEL% EQU 1 goto err1
fc.exe %TEMP%\empty.txt empty.txt
if %ERRORLEVEL% EQU 1 goto err

rem check an empty string
%PROGRAM% numTest.txt %TEMP%\numTest.txt "" "hi"
if %ERRORLEVEL% EQU 0 goto err
fc.exe %TEMP%\numTest.txt numTest.txt
if %ERRORLEVEL% EQU 0 goto err

rem check lo lolo
%PROGRAM% haplology.txt  %TEMP%\haplology.txt "lo" "lolo"
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\haplology.txt haplology.txt
if %ERRORLEVEL% EQU 0 goto err

rem check 1231234
%PROGRAM% numTest.txt %TEMP%\numTest.txt "1231234" "perfect"
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\numTest.txt numTest.txt
if %ERRORLEVEL% EQU 0 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1