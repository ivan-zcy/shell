/*************************************************************************
	> File Name: ls.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 日  1/20 20:53:04 2019
 ************************************************************************/
#include "ls.h"

void rwx(int mode, char *zt) {
    if (S_ISDIR(mode)) zt[0] = 'd';
    if (S_ISCHR(mode)) zt[0] = 'c';
    if (S_ISBLK(mode)) zt[0] = 'b';
    if ((mode & S_IRUSR)) zt[1] = 'r';
    if ((mode & S_IWUSR)) zt[2] = 'w';
    if ((mode & S_IXUSR)) zt[3] = 'x';
    if ((mode & S_IRGRP)) zt[4] = 'r';
    if ((mode & S_IWGRP)) zt[5] = 'w';
    if ((mode & S_IXGRP)) zt[6] = 'x';
    if ((mode & S_IROTH)) zt[7] = 'r';
    if ((mode & S_IWOTH)) zt[8] = 'w';
    if ((mode & S_IXOTH)) zt[9] = 'x';
}

void getLs(char *paths, int flag) {
    char newpaths[1005] = {0};
    strcpy(newpaths, paths);
    DIR *dir;
    dirent *ptr;
    struct stat dirfileinfo;
    if((dir = opendir(newpaths)) == NULL) {
        printf("Error\n");
        return;
    }
    if (flag & 1) {
        printf("\033[1;31m%-12s %-8s  %-8s  %-6s %-15s %-18s %-10s\n\033[0m", "权限", "文件数", "拥有者", "group", "文件大小", "建档日期", "文件名");
    }
    while((ptr = readdir(dir)) != NULL) {
        if (ptr -> d_name[0] == '.' && (flag & 2) == 0) {
            continue;
        }
        if (flag & 1) {
            strcpy(newpaths, paths);
            strcat(newpaths, ptr -> d_name);
            char zt[15] = "----------";
            stat(newpaths, &dirfileinfo); //得到指定文件名的描述信息
            rwx(dirfileinfo.st_mode, zt); //确定文件权限信息
            printf("%-12s ", zt);
            printf("%-7d ", dirfileinfo.st_nlink);
            printf("%-5s ", getpwuid(dirfileinfo.st_uid) -> pw_name);
            printf("%-7s ", getgrgid(dirfileinfo.st_gid) -> gr_name);
            printf("%-8d ", (int)dirfileinfo.st_size);
            printf("%-15.12s ", 4 + ctime(&dirfileinfo.st_mtime));
            printf("%-10s\n", ptr -> d_name);
        } else {
            if (ptr -> d_type == 8) {
                printf("\033[1;33m%-10s  \033[0m", ptr -> d_name);
            } else if(ptr -> d_type == 10) {
                printf("\033[1;32m%-10s  \033[0m", ptr -> d_name);
            } else if(ptr -> d_type == 4) {
                printf("\033[1;31m%-10s  \033[0m", ptr -> d_name);
            }
        }
    }
    if ((flag & 1) == 0) printf("\n");
    closedir(dir);
}
