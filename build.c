#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

// .c -> .o
int CompileC2O(char *srcDir, char *buildDir) {
    // 打开源目录
    DIR *dir = opendir(srcDir);
    if (dir == NULL) {
        printf("NO DIR: %s\r\n", srcDir);
        return -1;
    }

    // 读取源目录(包括子目录下的所有文件)
    struct dirent *entry;
    do {
        entry = readdir(dir);
        if (entry == NULL) {
            break;
        }
        // 如果是.c文件
        if (strstr(entry->d_name, ".c") != NULL) {
            // 编译成.o文件
            // gcc -c src/Human.c -o build/Human.o
            char cmd[256];
            sprintf(cmd, "gcc -c %s/%s -o %s/%s.o", srcDir, entry->d_name,
                    buildDir, entry->d_name);
            system(cmd);
        }
    } while (entry != NULL);

    closedir(dir);

    return 0;
}

// usage: build.exe ./src/ ./build/ ./bin/
int main(int argc, char *argv[]) {

    char *srcDir = argv[1];
    char *buildDir = argv[2];

    // argv[1] 是源目录, 要找到它的*.c文件
    // argv[2] 是目标目录, 把.o文件放到这里

    CompileC2O(srcDir, buildDir);
    printf("Build All %s.c to %s.o", srcDir, buildDir);
    return 0;
}