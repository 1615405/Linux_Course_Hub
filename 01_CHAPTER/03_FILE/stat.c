#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
    struct stat statbuf;
    int ret = stat("hello.txt", &statbuf);
    if (ret == -1) {
        perror("stat");
        return -1;
    }
    printf("size: %ld\n", statbuf.st_size);
    return 0;
}


/*
int stat(const char *pathname, struct stat *statbuf);
    作用:
        获取一个文件相关的一些信息
    参数:
        - pathname:
            操作的文件的路径
        - statbuf:
            结构体变量，传出参数，用于保存获取到的文件的信息
*/
