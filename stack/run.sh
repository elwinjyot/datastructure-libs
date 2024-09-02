#!/bin/bash
echo "Building"
if [ ! -d "../build" ]; then
  mkdir "../build"
fi
gcc -I../include -o ../build/stack example.c -L../lib/ -lstack

if [ $? -eq 0 ]; then
  echo -e "Build complete\n"
else
  echo -e "Build failed\n"
  exit 1
fi

echo -e "Running\n"
../build/stack
