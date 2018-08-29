/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     K = 259,
     DK = 260,
     AND = 261,
     OR = 262,
     NOT = 263,
     IMPLY = 264,
     ONEOF = 265,
     TRUETERM = 266,
     FALSETERM = 267,
     LEFT_PAREN = 268,
     RIGHT_PAREN = 269,
     LEFT_BRACE = 270,
     RIGHT_BRACE = 271,
     LEFT_BRACKET = 272,
     RIGHT_BRACKET = 273,
     COMMA = 274,
     COLON = 275,
     CONNECTOR = 276,
     DEFINE = 277,
     LDOMAIN = 278,
     TYPES = 279,
     PREDICATES = 280,
     PRECONDITION = 281,
     ACTION = 282,
     CATEGORY = 283,
     PARAMETERS = 284,
     OBSERVE_POS = 285,
     OBSERVE_NEG = 286,
     EFFECT = 287,
     PROBLEM = 288,
     OBJECTS = 289,
     AGENTS = 290,
     INIT = 291,
     CONSTRAINT = 292,
     GOAL = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 81 "epddlParser.y"

	bool *defaultType;
	std::string *str;
	std::map<std::string, std::vector<std::string> > *stringToStringVector;
	std::vector<std::string> *stringVector;
	std::map<int, std::string> *intToString;
	std::map<std::string, int> *stringToInt;
	std::vector<std::vector<std::string> > *stringVectorVector;
	KLDNF *kldnf;
	std::vector<KLDNF> *kldnfVector;
	std::vector<std::vector<KLDNF> > *kldnfVectorVector;
	std::vector<std::vector<std::vector<KLDNF> > > *kldnfVectorVectorVector;
	PropDNF *pdnf;
	std::vector<PropDNF> *pdnfVector;
	std::map<std::string, std::string> *stringToString;



/* Line 2068 of yacc.c  */
#line 107 "epddlParser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


