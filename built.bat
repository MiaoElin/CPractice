gcc ./src/main.c -c -o ./bin/main.o
gcc ./lib/raylib.dll ./bin/main.o -o ./bin/main.exe
