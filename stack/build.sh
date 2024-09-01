#!/bin/bash
current_dir=$(basename "$PWD")

if [[ "$current_dir" != "stack" ]]; then
  echo "Change to root directory of the library. Quiting.."
  exit -1
fi

echo "Building library..."

if [ ! -d "./build" ]; then
  mkdir "./build"
fi

if [ ! -d "../lib" ]; then
  mkdir "../lib"
fi

gcc -I../include -c ./src/stack.c -o ./build/stack.o
if [ $? -ne 0 ]; then
  echo "Failed: At generating object file"
  exit -1
fi

ar rcs ../lib/libstack.a ./build/stack.o
if [ $? -ne 0 ]; then
  echo "Failed: At create static library file"
  exit -1
fi

echo "Cleaning up"
rm -rf ./build

echo "Library built successfully"
echo -e "\nCompleted. Library stored in lib directory"
