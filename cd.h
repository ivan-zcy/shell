/*************************************************************************
	> File Name: cd.h
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 一  1/21 10:34:54 2019
 ************************************************************************/

#ifndef _CD_H
#define _CD_H

#include <stdio.h>
#include <string.h>
#include <dirent.h> //获取文件信息

void setCd(char *paths, char (*spcd)[1005], int len);

#endif
