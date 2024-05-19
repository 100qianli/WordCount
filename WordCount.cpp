#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;  // �ļ�ָ��
    char filename[100];  // �洢�ļ���������
    char ch;  // ���ڴ洢��ȡ���ַ�
    int charCount = 0, wordCount = 0;  // �ַ����͵������ļ�����
    int inword = 0;  // ����Ƿ��ڵ�����

    // ��������в�������
    if (argc != 3) {
        printf("ʹ��˵����WordCount [parameter] [input_file_name]\n");
        printf("����˵����\n");
        printf("  -c ͳ���ַ���\n");
        printf("  -w ͳ�Ƶ�����\n");
        exit(1);
    }

    char *parameter = argv[1];  // ��ȡ����
    strcpy(filename, argv[2]);  // ��ȡ�ļ���

    // ���ļ�
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("�޷����ļ����ļ������ڡ�\n");
        exit(1);
    }

    // ���ַ���ȡ�ļ�����
    while ((ch = fgetc(file)) != EOF) {
        charCount++;  // ͳ���ַ���
        // �ж��Ƿ�Ϊ���ʷָ���
        if (isspace(ch) || ch == ',' || ch == '.') {
            if (inword) {  // ���֮ǰ�ڵ�����
                wordCount++;  // ���ӵ��ʼ���
                inword = 0;  // ��ǲ��ڵ�����
            }
        } else {
            inword = 1;  // ����ڵ�����
        }
    }

    fclose(file);  // �ر��ļ�

    // ���ݲ�������ַ����򵥴���
    if (strcmp(parameter, "-c") == 0) {
        printf("�ַ�����%d\n", charCount);
    } else if (strcmp(parameter, "-w") == 0) {
        printf("��������%d\n", wordCount);
    } else {
        printf("��Ч�Ĳ�����\n");
    }

    return 0;  // ����0��ʾ������������
}
