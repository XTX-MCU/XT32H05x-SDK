set target=%1

if %target%=="" set target=progimage

echo %target%

fromelf.exe --bin -o ..\Release\%target%.bin .\Objects\%target%.axf
