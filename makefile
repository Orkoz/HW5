# This is a Makefile for project
CCC = g++
CXXFLAGS = -g -Wall
CXXLINK = $(CCC)
OBJS = ScriptExceptions.o MySharedPtr.o Variable.o Scalar.o Matrix.o VariablesMap.o main.cpp Commands.o LineParser.o MamatScriptEngine.o Variable.cpp Scalar.cpp Matrix.cpp VariablesMap.cpp main.cpp Commands.cpp LineParser.cpp MamatScriptEngine.cpp


all: MamatScript

MamatScript: $(OBJS) 
	$(CXXLINK) -o students $(OBJS)

ScriptExceptions.o:
MySharedPtr.o:
Variable.o:
Scalar.o:
Matrix.o:
VariablesMap.o:
Commands.o:
LineParser.o:
MamatScriptEngine.o:

ScriptExceptions.h
MySharedPtr.h
Variable.h
Variable.cpp
Scalar.h
Scalar.cpp
Matrix.h
Matrix.cpp
VariablesMap.h
VariablesMap.cpp
main.cpp
Commands.h
Commands.cpp
LineParser.h
LineParser.cpp
MamatScriptEngine.h
MamatScriptEngine.cpp


