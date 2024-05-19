#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0;
    int inword = 0;

    if (argc != 3) {
        printf("使用说明：WordCount [parameter] [input_file_name]\n");
        printf("参数说明：\n");
        printf("  -c 统计字符数\n");
        printf("  -w 统计单词数\n");
        exit(1);
    }

    char *parameter = argv[1];
    strcpy(filename, argv[2]);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("无法打开文件或文件不存在。\n");
        exit(1);
    }

    while ((ch = fgetc(file)) != EOF) {
        charCount++;

        if (isspace(ch) || ch == ',' || ch == '.') {
            if (inword) {
                wordCount++;
                inword = 0;
            }
        } else {
            inword = 1;
        }
    }

    fclose(file);

    if (strcmp(parameter, "-c") == 0) {
        printf("字符数：%d\n", charCount);
    } else if (strcmp(parameter, "-w") == 0) {
        printf("单词数：%d\n", wordCount);
    } else {
        printf("无效的参数。\n");
    }

    return 0;
}

