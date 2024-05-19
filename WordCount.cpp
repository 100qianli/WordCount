#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;  // 文件指针
    char filename[100];  // 存储文件名的数组
    char ch;  // 用于存储读取的字符
    int charCount = 0, wordCount = 0;  // 字符数和单词数的计数器
    int inword = 0;  // 标记是否在单词中

    // 检查命令行参数数量
    if (argc != 3) {
        printf("使用说明：WordCount [parameter] [input_file_name]\n");
        printf("参数说明：\n");
        printf("  -c 统计字符数\n");
        printf("  -w 统计单词数\n");
        exit(1);
    }

    char *parameter = argv[1];  // 获取参数
    strcpy(filename, argv[2]);  // 获取文件名

    // 打开文件
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件或文件不存在。\n");
        exit(1);
    }

    // 逐字符读取文件内容
    while ((ch = fgetc(file)) != EOF) {
        charCount++;  // 统计字符数
        // 判断是否为单词分隔符
        if (isspace(ch) || ch == ',' || ch == '.') {
            if (inword) {  // 如果之前在单词中
                wordCount++;  // 增加单词计数
                inword = 0;  // 标记不在单词中
            }
        } else {
            inword = 1;  // 标记在单词中
        }
    }

    fclose(file);  // 关闭文件

    // 根据参数输出字符数或单词数
    if (strcmp(parameter, "-c") == 0) {
        printf("字符数：%d\n", charCount);
    } else if (strcmp(parameter, "-w") == 0) {
        printf("单词数：%d\n", wordCount);
    } else {
        printf("无效的参数。\n");
    }

    return 0;  // 返回0表示程序正常结束
}
