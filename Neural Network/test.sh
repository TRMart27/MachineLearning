#!/bin/sh

set -e

echo EXCLUSIVE - OR 
clang -I ./include -Wall -Wextra  src/util.c src/matrix.c src/nn.c xor.c -o testRun -lm

./testRun 20000
rm testRun

echo AND 
clang -I ./include -Wall -Wextra  src/util.c src/matrix.c src/nn.c and.c -o testRun -lm

./testRun 20000
rm testRun

echo OR 
clang -I ./include -Wall -Wextra  src/util.c src/matrix.c src/nn.c or.c -o testRun -lm

./testRun 20000
rm testRun

