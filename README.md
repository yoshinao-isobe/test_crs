# aixcc-test-c (Buttercup/OSS-Fuzz compatible)

Small C project with a stack buffer overflow for Buttercup (AIxCC) / OSS-Fuzz.

## Layout
- `src/test.c`: vulnerable code (`Fun1`)
- `fuzz/fuzz_test.c`: libFuzzer harness calling `Fun1`
- `oss-fuzz/`: OSS-Fuzz build files (`build.sh`, `Dockerfile`, `project.yaml`)

## Local (optional): Test with OSS-Fuzz helper
- Clone `google/oss-fuzz` and run:
