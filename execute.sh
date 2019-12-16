#!/bin/sh
echo Translator C++ to python
bison -d c++2python.y
flex c++2python.l 
gcc c++2python.tab.c lex.yy.c main.c ast.c  check_ast.c print_ast.c translate_ast.c -lfl -lm 
./a.out ./esempio-c++/file.cpp ./python/file_out.py

g++ -o ./esempio-c++/file.out ./esempio-c++/file.cpp
./esempio-c++/file.out
echo ""
python ./python/file_out.py
