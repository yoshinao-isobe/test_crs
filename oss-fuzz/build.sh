#!/bin/bash -eux
# CC, CXX, CFLAGS, CXXFLAGS, OUT, SRC, LIB_FUZZING_ENGINE を OSS-Fuzz が注入

mkdir -p "$SRC/build"
cd "$SRC/build"

# 脆弱コードのビルド（ASan/UBSan 等の計測を必ず適用）
$CC $CFLAGS -O1 -g -fno-omit-frame-pointer -c "$SRC/src/test.c" -o test.o
ar rcs libtest.a test.o

# fuzz ターゲットのリンク（libFuzzer は $LIB_FUZZING_ENGINE）
$CC $CFLAGS -O1 -g -fno-omit-frame-pointer \
  "$SRC/fuzz/fuzz_test.c" -I"$SRC/src" \
  libtest.a $LIB_FUZZING_ENGINE -o "$OUT/test_fuzzer"

