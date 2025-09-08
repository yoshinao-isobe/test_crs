#include <stdint.h>
#include <stddef.h>
#include "test.h"

// 入力は使用しません。実行されるたびに Fun1 を呼び出して
// 常にオーバーフローを誘発します（ASan/UBSanで検出されます）。
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    (void)data; (void)size;
    Fun1();
    return 0;
}
