#!/bin/bash -eu
# 環境変数（OSS-Fuzzが設定）:
#   CC, CXX, CFLAGS, CXXFLAGS, OUT, SRC, LIB_FUZZING_ENGINE

# ビルドディレクトリ
mkdir -p "$SRC/build"
cd "$SRC/build"

# ライブラリ化（Fun1 を含む）
$CC $CFLAGS -c "$SRC/src/test.c" -o test.o
ar rcs libtest.a test.o

# fuzz ターゲット
$CC $CFLAGS "$SRC/fuzz/fuzz_test.c" -I"$SRC/src" \
    libtest.a $LIB_FUZZING_ENGINE -o "$OUT/test_fuzzer"
