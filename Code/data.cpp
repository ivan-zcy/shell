/*************************************************************************
	> File Name: data.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 日  1/20 17:50:50 2019
 ************************************************************************/

#include "../Head/data.h"

void getName(char *name) {
    uid_t userid = getuid();
    passwd* pwd = getpwuid(userid);
    strcpy(name, pwd->pw_name);
}

void getTime(char *t) {
    time_t timep;
    time(&timep);
    strftime(t, sizeof(t), "%H:%M:%S", localtime(&timep));
}

void getPath(char *paths) {
    getcwd(paths, 1005);
    strcat(paths, "/");
}
