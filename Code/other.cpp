/*************************************************************************
	> File Name: cd.cpp
	> Author: Zcy
	> Mail: 296763002@qq.com
	> Created Time: 一  1/21 10:35:26 2019
 ************************************************************************/

#include "../Head/other.h"

void runOther (char *cmd, char *k) {
	int flag = 0;
	if (strcmp(k, "&") == 0) {
		flag = 1;
		int len = strlen(cmd);
		for (int i = len - 1; i >= 0; i--) {
			if(cmd[i] == '&') {
				cmd[i] = '\0';
				break;
			}
		}
	}
	int pid = fork();
	if (pid != 0) {
		if(flag) {
			return;
		}
		int status;
		int result = wait(&status);
	} else {
		FILE *fp = popen(cmd, "r");
		char buf[1005];
		while(fgets(buf, sizeof(buf), fp)) {
			printf("%s", buf);
		}
		pclose(fp);	
	}
}
