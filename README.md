# DataStruct Libs
Easy to use most popular data structures implemented in C/C++. Library build ready files. 

You can clone and include my data structures code into your projects. Scripts to build each data structure is included in the directories of with the corresponding data structure name

Usage
---
- After cloning the code, open the project with location in a terminal window. 

- Switch directory to the desired data structure folder, for example to build the library for linked list cd into the `linkedlist` directory.
```bash
cd ./linkedlist
```
- **Optional for (linux and mac users)**, Give execute rights to the build and run script.
```bash
chmod +x build.sh run.sh
```
- Run `./build.sh` to build the library. The static library file, it will be available in the `lib` directory in the root.
- Checkout the snippets in the `example.c` file for reference. Run `./run.sh` see it in action.

Link to your project
---
- Copy the header files for the data structure into the include folder of your project.
- Copy the `.a` (Static Libray) file to a directory in your project `ex: bin/` (Install feature to be implemented)
- Link and compile your program with the library name `ex: list, stack`