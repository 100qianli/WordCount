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
        printf("ʹ��˵����WordCount [parameter] [input_file_name]\n");
        printf("����˵����\n");
        printf("  -c ͳ���ַ���\n");
        printf("  -w ͳ�Ƶ�����\n");
        exit(1);
    }

    char *parameter = argv[1];
    strcpy(filename, argv[2]);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("�޷����ļ����ļ������ڡ�\n");
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
        printf("�ַ�����%d\n", charCount);
    } else if (strcmp(parameter, "-w") == 0) {
        printf("��������%d\n", wordCount);
    } else {
        printf("��Ч�Ĳ�����\n");
    }

    return 0;
}

