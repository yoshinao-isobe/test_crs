#include <string.h>
#include "test.h"

/* 最適化で消えないように noinline、かつ stack 上のバッファは volatile に */
__attribute__((noinline)) void Fun1(void) {
    volatile char data[10];
    const char source[11] = "AAAAAAAAAA";  // 10 'A' + '\0' = 11 bytes
    /* strlen(source) + 1 = 11 を data[10] にコピー → stack-buffer-overflow */
    memcpy((char *)data, source, strlen(source) + 1);
}
