/*************************************************************************
	> File Name: shell.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 日  1/20 15:58:08 2019
 ************************************************************************/

#include <stdio.h>
#include "split.h"
#include "data.h"
#include "ls.h"
#include "cd.h"
using namespace std;

char s[1005];   //存储一次的命令
char sp[105][1005]; //分段存储一次命令有效部分
char spcd[105][1005]; //存储cd命令的每次操作的前进后退
char name[15]; //存储用户名
char paths[1005]; //存储路径
char t[15]; //存储时间
int main () {
    getName(name);
    getPath(paths);
    while(1) {
        getTime(t);
        printf("\033[1;32m[%s@%s]\033[0m", name, t);
        printf("\033[1;33m%s\033[0m", paths);
        printf("\033[1;34m$ \033[0m");
        memset(sp, 0, sizeof(sp));
        memset(spcd, 0, sizeof(spcd));
        scanf("%[^\n]s", s);
        getchar();
        int len = split(s, sp, ' ');
        if (len == 1) {
            if (strcmp(sp[0], "exit") == 0) {
                break;
            } else if(strcmp(sp[0], "ls") == 0) {
                getLs(paths, 0);   
            } else {
                printf("Error command\n");
            }
        } else if(len == 2) {
            if(strcmp(sp[0], "ls") == 0){
                if (strcmp(sp[1], "-l") == 0) {
                    getLs(paths, 1);
                } else if(strcmp(sp[1], "-a") == 0) {
                    getLs(paths, 2);
                } else if(strcmp(sp[1], "-al") == 0 || strcmp(sp[1], "-la") == 0) {
                    getLs(paths, 3);
                } else {
                    printf("Error command\n");
                }
            } else if(strcmp(sp[0], "cd") == 0) {
                len = split(sp[1], spcd, '/');
                setCd(paths, spcd, len);
            } else {
                printf("Error command\n");
            }
        } else {
            printf("Error command\n");
        }
    }
    return 0;
}
