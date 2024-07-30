1. 预编译过程主要处理那些源代码文件中的以#开始的预编译指令。比如#include，#define等，主要处理规则如下：
    - 将所有的#define删除，并且展开所有的宏定义
    - 处理所有条件预编译指令，比如#if，#ifdef，#elif，#else，#endif
    - 处理#include预编译指令，将被包含的文件插入到该预编译指令的位置。注意，这个过程是递归进行的，也就是说被包含的文件可能还包含其他文件。
    - 删除所有的注释//和/* */
    - 添加行号和文件名标识，以便于编译时编译器产生调试用的行号信息及用于编译时产生编译错误或警告时能够显示行号
    - 保留所有的#pragma编译器指令，因为编译器须要使用它们


2. 编译命令
    - 预编译：gcc -E hello.c -o hello.i  或者  cpp hello.c > hello.i
    - 编译: gcc -S hello.i -o hello.s
    - 汇编: as helloc.s -o hello.o  或者  gcc -c hello.s -o hello.c

ld -static \
  /usr/lib/x86_64-linux-gnu/crt1.o \
  /usr/lib/x86_64-linux-gnu/crti.o \
  /usr/lib/gcc/x86_64-linux-gnu/11/crtbeginT.o \
  hello.o \
  -L/usr/lib/gcc/x86_64-linux-gnu/11 \
  -L/usr/lib/x86_64-linux-gnu \
  -start-group \
  -lgcc \
  -lgcc_eh \
  -lc \
  -end-group \
  /usr/lib/gcc/x86_64-linux-gnu/11/crtend.o \
  /usr/lib/x86_64-linux-gnu/crtn.o


3. 静态库制作
    - gcc -c *.c -I ../include
    - ar rcs libcalc.a *.o
    - gcc main.c -o app -I ./include -lcalc -L ./lib