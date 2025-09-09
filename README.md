# aixcc-test-c (Buttercup / OSS-Fuzz compatible)

- `src/test.c` に stack-buffer-overflow を含む脆弱関数 `Fun1`。
- `fuzz/fuzz_test.c` は `data[0]=='X'` の条件で `Fun1` を呼び出すハーネス。
- `oss-fuzz/` 配下に `build.sh`, `Dockerfile`, `project.yaml`。

## Local quick check (with OSS-Fuzz helper)
