#include <stdio.h>
#include "bfd.h"

int main()
{
    const char** t = bfd_target_list();
    while (*t) {
        printf("%s\n", *t);
        t++;
    }
}

// sudo apt-get update
// sudo apt-get install binutils
// sudo apt-get install binutils-dev
// gcc -o target target.c -lbfd
