#include <string.h>
#include "test.h"

void Fun1(void)
{
    char data[10];
    char source[11] = "AAAAAAAAAA";  // 10個の 'A' + '\0' で 11 バイト
    // strlen(source) + 1 = 11 を data[10] に memcpy → stack-buffer-overflow
    memcpy(data, source, strlen(source) + 1);
    (void)data; // 最適化抑制
}
