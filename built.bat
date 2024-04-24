gcc .\src\main.c -c -o .\build\main.o
gcc .\lib\raylib.dll .\build\main.o -o .\bin\main.exe

xcopy .\Assets\ .\bin\Assets\ /E /I /Q /Y
xcopy .\lib\raylib.dll .\bin\raylib.dll /F /E /I /Q /Y