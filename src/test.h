#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// 脆弱性を含む関数（ASanで検出される）
void Fun1(void);

#ifdef __cplusplus
}
#endif
