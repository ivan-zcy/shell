/*************************************************************************
	> File Name: split.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 日  1/20 16:15:41 2019
 ************************************************************************/
#include "../Head/split.h"

int split(char *s, char (*sp)[1005], char c) {
    int tot = 0, j = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == c) {
            if(!j) continue;
            tot++;
            j = 0;
            continue;
        }
        sp[tot][j++] = s[i];
    }
    if(j) {
        return tot + 1;
    } 
    return tot;
}
