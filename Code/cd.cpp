/*************************************************************************
	> File Name: cd.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 一  1/21 10:35:26 2019
 ************************************************************************/

#include "../Head/cd.h"

void setCd(char *paths, char (*spcd)[1005], int len) {
    char newpaths[1005];
    strcpy(newpaths, paths);
    for (int i = 0; i < len; i++) {
        if (strcmp(spcd[i], ".") == 0) {
            continue;
        } else if (strcmp(spcd[i], "..") == 0) {
            if (strcmp(newpaths, "/") == 0) {
                continue;
            } else {
                int j;
                for (j = strlen(newpaths) - 2; j >= 0 && newpaths[j] != '/'; j--);
                newpaths[j + 1] = '\0';
            }
        } else {
            int flag = 0;
            DIR *dir;
            dirent *ptr;
            if ((dir = opendir(newpaths)) == NULL) {
                printf("Error\n");
                return;
            }
            while((ptr = readdir(dir)) != NULL) {
                if (strcmp(ptr -> d_name, spcd[i]) == 0) {
                    flag = 1;
                    strcat(newpaths, spcd[i]);
                    strcat(newpaths, "/");
                    break;
                }
            }
            if (!flag) {
                printf("Error paths\n");
                return;
            }
        }
    }
    strcpy(paths, newpaths);
}
