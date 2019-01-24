/*************************************************************************
	> File Name: ls.h
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 日  1/20 18:50:46 2019
 ************************************************************************/

#ifndef _LS_H
#define _LS_H

#include <pwd.h> //获取拥有者
#include <grp.h> //获取所属组
#include <sys/stat.h> //获取文件权限
#include <stdio.h>
#include <dirent.h> //获取文件信息
#include <string.h>
#include <time.h>

void getLs(char *paths, int flag);

#endif
