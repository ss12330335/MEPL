#Makefile

OBJECTS = epddlLexer.o epddlParser.o ACDF.o parse.o heuristicHelper.o planner.o

LEXER = lex
PARSER = bison
COMPILER = g++
COMPILE_OPTION = -Wall -std=c++0x

main: ${OBJECTS} main.cpp
	${COMPILER} ${COMPILE_OPTION} ${OBJECTS} main.cpp -o start -O2

planner.o: planner.h planner.cpp
	${COMPILER} ${COMPILE_OPTION} -c planner.cpp -o planner.o -O2

heuristicHelper.o: heuristicHelper.h heuristicHelper.cpp
	${COMPILER} ${COMPILE_OPTION} -c heuristicHelper.cpp -o heuristicHelper.o -O2

parse.o: parse.h parse.cpp
	${COMPILER} ${COMPILE_OPTION} -c parse.cpp -o parse.o -O2

ACDF.o: ACDF.h ACDF.cpp
	${COMPILER} ${COMPILE_OPTION} -c ACDF.cpp -o ACDF.o -O2

epddlLexer.o: lex.yy.c
	${COMPILER} ${COMPILE_OPTION} -c lex.yy.c -o epddlLexer.o -O2

lex.yy.c: epddlLexer.l epddlParser.o
	${LEXER} epddlLexer.l

epddlParser.o: epddlParser.tab.c
	${COMPILER} ${COMPILE_OPTION} -c epddlParser.tab.c -o epddlParser.o -O2

epddlParser.tab.c: epddlParser.y
	${PARSER} --defines=epddlParser.h -d epddlParser.y

.PHONY: clean

clean:
	rm -r *.o *c epddlParser.h start