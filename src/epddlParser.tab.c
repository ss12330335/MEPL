/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "epddlParser.y"

#include "define.h"

int yylex(void);
int yyerror(char* s);

using namespace std;

extern std::string domainName;
extern vector<std::string> atoms;
extern map<string, vector<string> > objects;
extern vector<string> agents;
extern map<int, string> findAtomsByIndex;
extern map<string, int> findAtomsByName;
extern map<string, int> findSensingActionByName;
extern map<string, int> findOnticActionByName;
extern vector<SensingAction> sActions;
extern vector<OnticAction> oActions;
extern int atomNum;
extern KLDNF init;
extern KLDNF posGoal;
extern KLDNF goal;
extern PropDNF constraint;

void atomGround(vector<string>& ga, int pos,  string cur, map<string, vector<char> >& visited) {
	if(pos == (int)ga.size()) {
		cur = "(" + ga[0] + cur + ")";
		int index = findAtomsByName.size();
		findAtomsByName[cur] = index;
		findAtomsByIndex[index] = cur;
		atomNum++;
		return ;
	}
	string cType = ga[pos];
	for(size_t i = 0;i < visited[cType].size();i++) {
		if(visited[cType][i] == '0') {
			visited[cType][i] = '1';
			string nc = cur + " " + ((cType=="agent") ? agents[i] : objects[cType][i]);
			atomGround(ga, pos+1, nc, visited);
			visited[cType][i] = '0';
		}
	}
}

vector<map<string, string>> actionVar;
vector<string> actionVarSeq;

void actionVarGround(map<string, string>& table, map<string, string> cur, map<string, string>::iterator ite, map<string, vector<char>> visited) {
	if(ite == table.end()) {
		actionVar.push_back(cur);
		return ;
	}
	string varType = ite->second;
	if(varType == "agent") {
		for(size_t i = 0;i < agents.size();i++) {
			if(visited["agent"][i] == '0') {
				visited["agent"][i] = '1';
				map<string, string> temp(cur);
				temp[ite->first] = agents[i];
				map<string, string>::iterator tempIte = ite;
				actionVarGround(table, temp, ++tempIte, visited);
				visited["agent"][i] = '0';
			}
		}
	}
	else {
		for(size_t i = 0;i < objects[varType].size();i++) {
			if(visited[varType][i] == '0') {
				visited[varType][i] = '1';
				map<string, string> temp(cur);
				temp[ite->first] = objects[varType][i];
				map<string, string>::iterator tempIte = ite;
				actionVarGround(table, temp, ++tempIte, visited);
				visited[varType][i] = '0';
			}
		}
	}
}


/* Line 268 of yacc.c  */
#line 152 "epddlParser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
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



/* Line 293 of yacc.c  */
#line 245 "epddlParser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 257 "epddlParser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  255

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    15,    20,    26,    31,    33,    36,    39,
      42,    45,    51,    53,    56,    62,    64,    67,    71,    76,
      80,    85,    91,    93,    98,   103,   108,   113,   118,   121,
     124,   128,   130,   133,   139,   141,   146,   151,   156,   159,
     162,   166,   172,   174,   179,   184,   189,   194,   199,   202,
     205,   209,   211,   213,   216,   219,   240,   264,   270,   274,
     279,   281,   286,   291,   296,   301,   306,   309,   312,   316,
     318,   321,   341,   364,   366,   369,   378,   380,   383,   392,
     394,   399,   404,   409,   414,   419,   422,   425
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    13,    22,    41,    42,    46,    48,    65,
      52,    57,    61,    14,    -1,    13,    23,     3,    14,    -1,
      13,    20,    34,    43,    14,    -1,    13,    20,    34,    14,
      -1,    44,    -1,    43,    44,    -1,     3,    45,    -1,     3,
      44,    -1,    21,     3,    -1,    13,    20,    35,    47,    14,
      -1,     3,    -1,    47,     3,    -1,    13,    20,    25,    49,
      14,    -1,    50,    -1,    49,    50,    -1,    13,     3,    14,
      -1,    13,     3,    51,    14,    -1,     3,    21,     3,    -1,
      51,     3,    21,     3,    -1,    13,    20,    36,    53,    14,
      -1,    55,    -1,    13,     4,    53,    14,    -1,    13,     5,
      53,    14,    -1,    13,     8,    53,    14,    -1,    13,     6,
      54,    14,    -1,    13,     7,    54,    14,    -1,    53,    53,
      -1,    54,    53,    -1,    13,    56,    14,    -1,     3,    -1,
      56,     3,    -1,    13,    20,    37,    58,    14,    -1,    60,
      -1,    13,     8,    58,    14,    -1,    13,     6,    59,    14,
      -1,    13,     7,    59,    14,    -1,    58,    58,    -1,    59,
      58,    -1,    13,    56,    14,    -1,    13,    20,    38,    62,
      14,    -1,    64,    -1,    13,     4,    62,    14,    -1,    13,
       5,    62,    14,    -1,    13,     8,    62,    14,    -1,    13,
       6,    63,    14,    -1,    13,     7,    63,    14,    -1,    62,
      62,    -1,    63,    62,    -1,    13,    56,    14,    -1,    66,
      -1,    73,    -1,    65,    73,    -1,    65,    66,    -1,    13,
      20,    27,     3,    20,    28,    13,     3,    14,    67,    20,
      26,    78,    20,    30,    69,    20,    31,    69,    14,    -1,
      13,    20,    27,     3,    20,    28,    13,     3,    14,    20,
      29,    13,    14,    20,    26,    62,    20,    30,    53,    20,
      31,    53,    14,    -1,    20,    29,    13,    68,    14,    -1,
       3,    21,     3,    -1,    68,     3,    21,     3,    -1,    71,
      -1,    13,     4,    69,    14,    -1,    13,     5,    69,    14,
      -1,    13,     8,    69,    14,    -1,    13,     6,    70,    14,
      -1,    13,     7,    70,    14,    -1,    69,    69,    -1,    70,
      69,    -1,    13,    72,    14,    -1,     3,    -1,    72,     3,
      -1,    13,    20,    27,     3,    20,    28,    13,     3,    14,
      67,    20,    26,    78,    20,    32,    13,    74,    14,    14,
      -1,    13,    20,    27,     3,    20,    28,    13,     3,    14,
      20,    29,    13,    14,    20,    26,    62,    20,    32,    13,
      76,    14,    14,    -1,    75,    -1,    74,    75,    -1,    17,
      15,    78,    16,    15,    69,    16,    18,    -1,    77,    -1,
      76,    77,    -1,    17,    15,    62,    16,    15,    53,    16,
      18,    -1,    80,    -1,    13,     4,    78,    14,    -1,    13,
       5,    78,    14,    -1,    13,     8,    78,    14,    -1,    13,
       6,    79,    14,    -1,    13,     7,    79,    14,    -1,    78,
      78,    -1,    79,    78,    -1,    13,    72,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   184,   184,   198,   203,   207,   212,   216,   222,   227,
     233,   238,   243,   248,   254,   268,   273,   279,   284,   290,
     295,   301,   306,   311,   319,   327,   334,   341,   349,   355,
     361,   374,   379,   384,   389,   394,   399,   406,   414,   420,
     426,   437,   443,   448,   458,   468,   476,   484,   493,   501,
     508,   530,   534,   538,   542,   547,   571,   589,   611,   616,
     622,   627,   641,   655,   664,   676,   689,   695,   701,   718,
     726,   735,   762,   783,   788,   794,   808,   813,   819,   829,
     834,   848,   862,   871,   883,   896,   902,   908
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "K", "DK", "AND", "OR", "NOT",
  "IMPLY", "ONEOF", "TRUETERM", "FALSETERM", "LEFT_PAREN", "RIGHT_PAREN",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "COMMA",
  "COLON", "CONNECTOR", "DEFINE", "LDOMAIN", "TYPES", "PREDICATES",
  "PRECONDITION", "ACTION", "CATEGORY", "PARAMETERS", "OBSERVE_POS",
  "OBSERVE_NEG", "EFFECT", "PROBLEM", "OBJECTS", "AGENTS", "INIT",
  "CONSTRAINT", "GOAL", "$accept", "domain", "DomainName", "ObjectPart",
  "ObjectList", "DetailObjectList", "TypeName", "AgentPart", "AgentList",
  "PredicatePart", "GeneralAtomList", "GeneralAtom", "VarList", "InitPart",
  "Formula", "FormulaList", "FormulaAtom", "NameList", "ConstraintPart",
  "ConFormula", "ConFormulaList", "ConFormulaAtom", "GoalPart",
  "NegFormula", "NegFormulaList", "NegFormulaAtom", "ActionPart",
  "SensingAction", "ActionVar", "ActionVarList", "GeneralFormula",
  "GeneralFormulaList", "GeneralFormulaAtom", "GeneralNameList",
  "OnticAction", "OnticResList", "OnticRes", "SingleOnticResList",
  "SingleOnticRes", "NegGeneralFormula", "NegGeneralFormulaList",
  "NegGeneralFormulaAtom", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    42,    42,    43,    43,    44,    44,
      45,    46,    47,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    56,    56,    57,    58,    58,    58,    58,    59,    59,
      60,    61,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    65,    65,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    70,    70,    71,    72,
      72,    73,    73,    74,    74,    75,    76,    76,    77,    78,
      78,    78,    78,    78,    78,    79,    79,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     4,     5,     4,     1,     2,     2,     2,
       2,     5,     1,     2,     5,     1,     2,     3,     4,     3,
       4,     5,     1,     4,     4,     4,     4,     4,     2,     2,
       3,     1,     2,     5,     1,     4,     4,     4,     2,     2,
       3,     5,     1,     4,     4,     4,     4,     4,     2,     2,
       3,     1,     1,     2,     2,    20,    23,     5,     3,     4,
       1,     4,     4,     4,     4,     4,     2,     2,     3,     1,
       2,    19,    22,     1,     2,     8,     1,     2,     8,     1,
       4,     4,     4,     4,     4,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       5,     0,     6,     0,     0,     0,     0,    51,    52,     0,
       9,     8,     4,     7,    12,     0,     0,     0,     0,     0,
      54,    53,    10,    13,    11,     0,     0,    15,     0,     0,
       0,     0,     0,    14,    16,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,    22,     0,     0,     2,
       0,     0,    18,     0,    31,     0,     0,     0,     0,     0,
       0,    21,     0,     0,    34,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    30,     0,     0,     0,
       0,    33,     0,     0,    42,    20,     0,    23,    24,    28,
      26,    29,    27,    25,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,    41,     0,    38,    36,    39,
      37,    35,     0,     0,     0,     0,     0,     0,    50,     0,
       0,    43,    44,    48,    46,    49,    47,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,    57,    69,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      87,     0,     0,     0,    59,    80,    81,    85,    83,    86,
      84,    82,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,    74,
       0,     0,    61,    62,    66,    64,    67,    65,    63,     0,
       0,    71,     0,     0,     0,    76,    55,     0,     0,     0,
       0,    77,     0,     0,     0,    72,     0,    56,     0,     0,
       0,    75,     0,     0,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     9,    21,    22,    31,    13,    35,    18,
      46,    47,    62,    39,    91,    92,    66,    80,    51,   114,
     115,    84,    59,   134,   135,   104,    26,    27,   140,   154,
     211,   212,   194,   168,    28,   205,   206,   234,   235,   175,
     176,   157
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -154
static const yytype_int16 yypact[] =
{
      -1,    18,    24,    34,  -154,    33,    39,    75,    99,    74,
     122,   104,   120,   124,  -154,     2,   108,   125,   126,     0,
    -154,     4,  -154,   138,   123,   127,   129,  -154,  -154,   141,
    -154,  -154,  -154,  -154,  -154,     8,   133,   128,   130,   136,
    -154,  -154,  -154,  -154,  -154,   149,    56,  -154,   150,   -21,
     134,   143,    27,  -154,  -154,   137,   146,   131,   140,   147,
     142,  -154,    29,   139,    77,   148,  -154,   151,   132,  -154,
     162,   145,  -154,   156,  -154,   146,   146,   146,   146,   146,
      43,  -154,   106,   157,  -154,   159,  -154,   170,   171,   161,
     163,   146,    97,   103,   164,  -154,  -154,   151,   151,   151,
      58,  -154,    88,   165,  -154,  -154,   166,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,   151,   107,   109,   167,  -154,   159,
     159,   159,   159,   159,    59,  -154,   168,  -154,  -154,  -154,
    -154,  -154,   169,   172,   159,   111,   113,   173,  -154,   155,
     175,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   176,   174,
      61,   177,   178,   181,    62,    94,   182,  -154,   188,   179,
     183,  -154,  -154,   177,   177,   177,   177,   177,    63,   -22,
    -154,   159,   189,   184,   192,   177,   115,   117,   193,  -154,
    -154,   180,   190,   191,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,   100,   194,  -154,   195,     1,   180,   180,   180,
     180,   180,    65,   154,   198,    57,  -154,   146,   196,   201,
     202,   180,   119,   121,   203,  -154,   180,   177,   204,  -154,
     199,   205,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   206,
     160,  -154,   197,   208,   101,  -154,  -154,   209,   146,   159,
     207,  -154,   180,   211,   210,  -154,   213,  -154,   212,   214,
     146,  -154,   215,   216,  -154
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,  -154,  -154,    67,  -154,  -154,  -154,  -154,
    -154,   187,  -154,  -154,   -56,   118,  -154,   -73,  -154,   -65,
     110,  -154,  -154,   -81,   114,  -154,  -154,   217,  -154,  -154,
    -153,    -3,  -154,    38,   218,  -154,     5,  -154,     3,  -150,
      69,  -154
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      65,   156,    83,    19,   103,    19,    48,    19,   181,   100,
     182,    43,     1,   173,   174,    56,    20,   178,    32,    89,
      90,    29,    44,    94,     4,   187,   189,   189,   193,   124,
      60,   207,    71,   208,   117,   109,   111,   111,   132,   133,
       3,    61,   137,    72,   209,   210,    95,     5,   214,   127,
     129,   129,     8,   143,   145,   145,     7,    96,   224,   226,
     226,    95,    95,   229,   152,   160,   179,   230,   179,    45,
      53,   218,   118,   138,   204,   153,   161,   180,    10,   215,
      74,    75,    76,    77,    78,    79,    30,    12,    33,   246,
     183,    74,   119,   120,   121,   122,   123,   162,   163,   164,
     165,   166,   167,   162,   197,   198,   199,   200,   201,    74,
      64,   110,    97,    98,    99,   240,    64,   112,   233,    11,
      82,   128,    82,   130,   102,   144,   102,   146,   155,   188,
     155,   190,   192,   225,   192,   227,    14,    17,    15,    25,
      16,    34,    38,    23,    42,    24,    45,    37,    36,    50,
      49,   220,    52,    55,    57,    48,    58,    63,   244,    64,
      68,    69,    81,    70,    82,    86,    87,    73,    67,    88,
      85,   101,   102,   105,   106,   107,   237,   108,   113,   125,
     126,   131,   243,   141,   148,   216,   142,   147,   139,   150,
     155,   170,   184,   192,   252,   149,    93,   213,   185,   158,
     151,   159,   169,   195,   172,   171,   186,   191,   116,   221,
     219,   196,   204,   217,   203,   222,   223,   228,   231,   232,
     236,   245,   233,   239,   242,   247,   248,   250,   238,   249,
     202,   253,   251,    54,   254,   177,   136,   241,     0,     0,
       0,     0,     0,    40,    41
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-154))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      56,   151,    67,     3,    85,     3,    27,     3,    30,    82,
      32,     3,    13,   163,   164,    36,    14,   167,    14,    75,
      76,    21,    14,    79,     0,   175,   176,   177,   181,   102,
       3,    30,     3,    32,    99,    91,    92,    93,   119,   120,
      22,    14,   123,    14,   197,   198,     3,    13,   201,   114,
     115,   116,    13,   134,   135,   136,    23,    14,   211,   212,
     213,     3,     3,   216,     3,     3,     3,   217,     3,    13,
      14,    14,    14,    14,    17,    14,    14,    14,     3,    14,
       3,     4,     5,     6,     7,     8,    19,    13,    21,   242,
     171,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,     3,
      13,    14,     6,     7,     8,    14,    13,    14,    17,    20,
      13,    14,    13,    14,    13,    14,    13,    14,    13,    14,
      13,    14,    13,    14,    13,    14,    14,    13,    34,    13,
      20,     3,    13,    35,     3,    20,    13,    20,    25,    13,
      20,   207,     3,     3,    20,    27,    13,    20,   239,    13,
      20,    14,    14,    21,    13,     3,    21,    28,    37,    13,
      38,    14,    13,     3,     3,    14,    16,    14,    14,    14,
      14,    14,   238,    14,    29,    31,    14,    14,    20,    13,
      13,     3,     3,    13,   250,    20,    78,   200,    14,    21,
      26,    20,    20,    13,    21,    26,    14,    14,    98,    13,
     205,    20,    17,    15,    20,    14,    14,    14,    14,    20,
      14,    14,    17,    15,    15,    14,    16,    15,    31,    16,
     192,    16,    18,    46,    18,   166,   122,   234,    -1,    -1,
      -1,    -1,    -1,    26,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    40,    22,     0,    13,    41,    23,    13,    42,
       3,    20,    13,    46,    14,    34,    20,    13,    48,     3,
      14,    43,    44,    35,    20,    13,    65,    66,    73,    21,
      44,    45,    14,    44,     3,    47,    25,    20,    13,    52,
      66,    73,     3,     3,    14,    13,    49,    50,    27,    20,
      13,    57,     3,    14,    50,     3,    36,    20,    13,    61,
       3,    14,    51,    20,    13,    53,    55,    37,    20,    14,
      21,     3,    14,    28,     3,     4,     5,     6,     7,     8,
      56,    14,    13,    58,    60,    38,     3,    21,    13,    53,
      53,    53,    54,    54,    53,     3,    14,     6,     7,     8,
      56,    14,    13,    62,    64,     3,     3,    14,    14,    53,
      14,    53,    14,    14,    58,    59,    59,    58,    14,     4,
       5,     6,     7,     8,    56,    14,    14,    58,    14,    58,
      14,    14,    62,    62,    62,    63,    63,    62,    14,    20,
      67,    14,    14,    62,    14,    62,    14,    14,    29,    20,
      13,    26,     3,    14,    68,    13,    78,    80,    21,    20,
       3,    14,     3,     4,     5,     6,     7,     8,    72,    20,
       3,    26,    21,    78,    78,    78,    79,    79,    78,     3,
      14,    30,    32,    62,     3,    14,    14,    78,    14,    78,
      14,    14,    13,    69,    71,    13,    20,     4,     5,     6,
       7,     8,    72,    20,    17,    74,    75,    30,    32,    69,
      69,    69,    70,    70,    69,    14,    31,    15,    14,    75,
      53,    13,    14,    14,    69,    14,    69,    14,    14,    69,
      78,    14,    20,    17,    76,    77,    14,    16,    31,    15,
      14,    77,    15,    53,    62,    14,    69,    14,    16,    16,
      15,    18,    53,    16,    18
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 194 "epddlParser.y"
    {
		domainName = *(yyvsp[(3) - (11)].str);
	}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 199 "epddlParser.y"
    {
		(yyval.str) = (yyvsp[(3) - (4)].str);
	}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 204 "epddlParser.y"
    {
		objects = *(yyvsp[(4) - (5)].stringToStringVector);
	}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 208 "epddlParser.y"
    {

	}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 213 "epddlParser.y"
    {
		(yyval.stringToStringVector) = (yyvsp[(1) - (1)].stringToStringVector);
	}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 217 "epddlParser.y"
    {
		(yyval.stringToStringVector) = (yyvsp[(1) - (2)].stringToStringVector);
		(*(yyval.stringToStringVector))[(*(yyvsp[(2) - (2)].stringToStringVector)).begin()->first] = (*(yyvsp[(2) - (2)].stringToStringVector)).begin()->second;
	}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 223 "epddlParser.y"
    {
		(yyval.stringToStringVector) = new (map<string, vector<string> >);
		(yyval.stringToStringVector)->insert(make_pair(*(yyvsp[(2) - (2)].str), vector<string>(1, *(yyvsp[(1) - (2)].str))));
	}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 228 "epddlParser.y"
    {
		(yyval.stringToStringVector) = (yyvsp[(2) - (2)].stringToStringVector);
		(*(yyval.stringToStringVector))[(*(yyval.stringToStringVector)).begin()->first].push_back(*(yyvsp[(1) - (2)].str));
	}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 234 "epddlParser.y"
    {
		(yyval.str) = (yyvsp[(2) - (2)].str);
	}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 239 "epddlParser.y"
    {
		agents = *(yyvsp[(4) - (5)].stringVector);
	}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 244 "epddlParser.y"
    {
		(yyval.stringVector) = new vector<string>;
		(*(yyval.stringVector)).push_back(*(yyvsp[(1) - (1)].str));
	}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 249 "epddlParser.y"
    {
		(yyval.stringVector) = (yyvsp[(1) - (2)].stringVector);
		(*(yyval.stringVector)).push_back(*(yyvsp[(2) - (2)].str));
	}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 255 "epddlParser.y"
    {
		atomNum = 0;
		map<string, vector<char> > visited;
		for(map<string, vector<string> >::iterator ite = objects.begin(); ite != objects.end();ite++) {
			visited.insert(make_pair(ite->first, vector<char>(ite->second.size(), '0')));
		}
		visited.insert(make_pair("agent", vector<char>(agents.size(), '0')));
		vector<vector<string> > tgal(*(yyvsp[(4) - (5)].stringVectorVector));
		for(size_t i = 0;i < tgal.size();i++) {
			atomGround(tgal[i], 1, "", visited);
		}
	}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 269 "epddlParser.y"
    {
		(yyval.stringVectorVector) = new vector<vector<string> >;
		(*(yyval.stringVectorVector)).push_back(*(yyvsp[(1) - (1)].stringVector));
	}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 274 "epddlParser.y"
    {
		(yyval.stringVectorVector) = (yyvsp[(1) - (2)].stringVectorVector);
		(*(yyval.stringVectorVector)).push_back(*(yyvsp[(2) - (2)].stringVector));
	}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 280 "epddlParser.y"
    {
		(yyval.stringVector) = new vector<string>;
		(*(yyval.stringVector)).push_back(*(yyvsp[(2) - (3)].str));
	}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 285 "epddlParser.y"
    {
		(yyval.stringVector) = (yyvsp[(3) - (4)].stringVector);
		(*(yyval.stringVector)).insert((*(yyval.stringVector)).begin(), *(yyvsp[(2) - (4)].str));
	}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 291 "epddlParser.y"
    {
		(yyval.stringVector) = new vector<string>;
		(*(yyval.stringVector)).push_back(*(yyvsp[(3) - (3)].str));
	}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 296 "epddlParser.y"
    {
		(yyval.stringVector) = (yyvsp[(1) - (4)].stringVector);
		(*(yyval.stringVector)).push_back(*(yyvsp[(4) - (4)].str));
	}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 302 "epddlParser.y"
    {
		init = *(yyvsp[(4) - (5)].kldnf);
	}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 307 "epddlParser.y"
    {
		(yyval.kldnf) = new KLDNF;
		*(yyval.kldnf) = *(yyvsp[(1) - (1)].kldnf);
	}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 312 "epddlParser.y"
    {
		string agentName = (yyvsp[(2) - (4)].str)->substr(2, (yyvsp[(2) - (4)].str)->length()-2);
		(yyval.kldnf) = new KLDNF;
		KLTerm klt;
		klt.KPart[agentName] = *(yyvsp[(3) - (4)].kldnf);
		(yyval.kldnf)->dnf.push_back(klt);
	}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 320 "epddlParser.y"
    {
		string agentName = (yyvsp[(2) - (4)].str)->substr(3, (yyvsp[(2) - (4)].str)->length()-3);
		(yyval.kldnf) = new KLDNF;
		KLTerm klt;
		klt.LPart[agentName].push_back(*(yyvsp[(3) - (4)].kldnf));
		(yyval.kldnf)->dnf.push_back(klt);
	}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 328 "epddlParser.y"
    {
		PropDNF preConstraint;
		preConstraint.dnf.push_back(PropTerm(atomNum));
		(yyval.kldnf) = new KLDNF;
		*(yyval.kldnf) = (yyvsp[(3) - (4)].kldnf)->negation(preConstraint);
	}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 335 "epddlParser.y"
    {
		(yyval.kldnf) = new KLDNF;
		for(size_t i = 0;i < (yyvsp[(3) - (4)].kldnfVector)->size();i++) {
			*(yyval.kldnf) = (yyval.kldnf)->conjunction((*(yyvsp[(3) - (4)].kldnfVector))[i]);
		}
	}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 342 "epddlParser.y"
    {
		(yyval.kldnf) = new KLDNF;
		for(size_t i = 0;i < (yyvsp[(3) - (4)].kldnfVector)->size();i++) {
			*(yyval.kldnf) = (yyval.kldnf)->disjunction((*(yyvsp[(3) - (4)].kldnfVector))[i]);
		}
	}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 350 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		(yyval.kldnfVector)->push_back(*(yyvsp[(1) - (2)].kldnf));
		(yyval.kldnfVector)->push_back(*(yyvsp[(2) - (2)].kldnf));
	}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 356 "epddlParser.y"
    {
		(yyval.kldnfVector) = (yyvsp[(1) - (2)].kldnfVector);
		(yyval.kldnfVector)->push_back(*(yyvsp[(2) - (2)].kldnf));
	}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 362 "epddlParser.y"
    {
		(yyval.kldnf) = new KLDNF;
		PropTerm pt(atomNum);
		KLTerm klt;
		string atomName = "(" + *(yyvsp[(2) - (3)].str) + ")";
		if(atomName != "(True)") {
			pt.literal[findAtomsByName[atomName]] = TRUE;
		}
		klt.PPart.dnf.push_back(pt);
		(yyval.kldnf)->dnf.push_back(klt);
	}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 375 "epddlParser.y"
    {
		(yyval.str) = new std::string;
		(yyval.str) = (yyvsp[(1) - (1)].str);
	}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 380 "epddlParser.y"
    {
		*(yyval.str) = *(yyval.str) + " " + *(yyvsp[(2) - (2)].str);
	}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 385 "epddlParser.y"
    {
		constraint = *(yyvsp[(4) - (5)].pdnf);
	}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 390 "epddlParser.y"
    {
		(yyval.pdnf) = new PropDNF;
		(yyval.pdnf) = (yyvsp[(1) - (1)].pdnf);
	}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 395 "epddlParser.y"
    {
		(yyval.pdnf) = new PropDNF;
		*(yyval.pdnf) = (yyvsp[(3) - (4)].pdnf)->negation();
	}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 400 "epddlParser.y"
    {
		(yyval.pdnf) = new PropDNF;
		for(size_t i = 0; i < (yyvsp[(3) - (4)].pdnfVector)->size();i++) {
			*(yyval.pdnf) = (yyval.pdnf)->conjunction((*(yyvsp[(3) - (4)].pdnfVector))[i]);
		}
	}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 407 "epddlParser.y"
    {
		(yyval.pdnf) = new PropDNF;
		for(size_t i = 0; i < (yyvsp[(3) - (4)].pdnfVector)->size();i++) {
			*(yyval.pdnf) = (yyval.pdnf)->disjunction((*(yyvsp[(3) - (4)].pdnfVector))[i]);
		}
	}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 415 "epddlParser.y"
    {
		(yyval.pdnfVector) = new vector<PropDNF>;
		(yyval.pdnfVector)->push_back(*(yyvsp[(1) - (2)].pdnf));
		(yyval.pdnfVector)->push_back(*(yyvsp[(2) - (2)].pdnf));
	}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 421 "epddlParser.y"
    {
		(yyval.pdnfVector) = (yyvsp[(1) - (2)].pdnfVector);
		(yyval.pdnfVector)->push_back(*(yyvsp[(2) - (2)].pdnf));
	}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 427 "epddlParser.y"
    {
		(yyval.pdnf) = new PropDNF;
		PropTerm pt(atomNum);
		string atomName = "(" + *(yyvsp[(2) - (3)].str) + ")";
		if(atomName != "(True)") {
			pt.literal[findAtomsByName[atomName]] = TRUE;
		}
		(yyval.pdnf)->dnf.push_back(pt);
	}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 438 "epddlParser.y"
    {
		goal = (*(yyvsp[(4) - (5)].kldnfVector))[0];
		posGoal = (*(yyvsp[(4) - (5)].kldnfVector))[1];
	}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 444 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		*(yyval.kldnfVector) = *(yyvsp[(1) - (1)].kldnfVector);
	}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 449 "epddlParser.y"
    {
		string agentName = (yyvsp[(2) - (4)].str)->substr(2, (yyvsp[(2) - (4)].str)->length()-2);
		(yyval.kldnfVector) = new vector<KLDNF>(2);
		KLTerm klt1, klt2;
		klt1.LPart[agentName].push_back((*(yyvsp[(3) - (4)].kldnfVector))[0]);
		klt2.KPart[agentName] = (*(yyvsp[(3) - (4)].kldnfVector))[1];
		(*(yyval.kldnfVector))[0].dnf.push_back(klt1);
		(*(yyval.kldnfVector))[1].dnf.push_back(klt2);
	}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 459 "epddlParser.y"
    {
		string agentName = (yyvsp[(2) - (4)].str)->substr(3, (yyvsp[(2) - (4)].str)->length()-3);
		(yyval.kldnfVector) = new vector<KLDNF>(2);
		KLTerm klt1, klt2;
		klt2.LPart[agentName].push_back((*(yyvsp[(3) - (4)].kldnfVector))[1]);
		klt1.KPart[agentName] = (*(yyvsp[(3) - (4)].kldnfVector))[0];
		(*(yyval.kldnfVector))[0].dnf.push_back(klt1);
		(*(yyval.kldnfVector))[1].dnf.push_back(klt2);
	}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 469 "epddlParser.y"
    {
		PropDNF preConstraint;
		preConstraint.dnf.push_back(PropTerm(atomNum));
		(yyval.kldnfVector) = new vector<KLDNF>(2);
		(*(yyval.kldnfVector))[0] = (*(yyvsp[(3) - (4)].kldnfVector))[1];
		(*(yyval.kldnfVector))[1] = (*(yyvsp[(3) - (4)].kldnfVector))[0];
	}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 477 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>(2);
		for(size_t i = 0;i < (*(yyvsp[(3) - (4)].kldnfVectorVector))[0].size();i++) {
			(*(yyval.kldnfVector))[0] = (*(yyval.kldnfVector))[0].disjunction((*(yyvsp[(3) - (4)].kldnfVectorVector))[0][i]);
			(*(yyval.kldnfVector))[1] = (*(yyval.kldnfVector))[1].conjunction((*(yyvsp[(3) - (4)].kldnfVectorVector))[1][i]);
		}
	}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 485 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>(2);
		for(size_t i = 0;i < (*(yyvsp[(3) - (4)].kldnfVectorVector))[0].size();i++) {
			(*(yyval.kldnfVector))[0] = (*(yyval.kldnfVector))[0].conjunction((*(yyvsp[(3) - (4)].kldnfVectorVector))[0][i]);
			(*(yyval.kldnfVector))[1] = (*(yyval.kldnfVector))[1].disjunction((*(yyvsp[(3) - (4)].kldnfVectorVector))[1][i]);
		}
	}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 494 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = new vector<vector<KLDNF>>(2);
		(*(yyval.kldnfVectorVector))[0].push_back((*(yyvsp[(1) - (2)].kldnfVector))[0]);
		(*(yyval.kldnfVectorVector))[0].push_back((*(yyvsp[(2) - (2)].kldnfVector))[0]);
		(*(yyval.kldnfVectorVector))[1].push_back((*(yyvsp[(1) - (2)].kldnfVector))[1]);
		(*(yyval.kldnfVectorVector))[1].push_back((*(yyvsp[(2) - (2)].kldnfVector))[1]);
	}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 502 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = (yyvsp[(1) - (2)].kldnfVectorVector);
		(*(yyval.kldnfVectorVector))[0].push_back((*(yyvsp[(2) - (2)].kldnfVector))[0]);
		(*(yyval.kldnfVectorVector))[1].push_back((*(yyvsp[(2) - (2)].kldnfVector))[1]);
	}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 509 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		KLDNF kld1, kld2;
		PropTerm pt1(atomNum), pt2(atomNum);
		KLTerm klt1, klt2;
		string atomName = "(" + *(yyvsp[(2) - (3)].str) + ")";
		if(atomName == "(True)") {
			pt1.literal[0] = UNSAT;
		}
		else {
			pt1.literal[findAtomsByName[atomName]] = FALSE;
			pt2.literal[findAtomsByName[atomName]] = TRUE;
		}
		klt1.PPart.dnf.push_back(pt1);
		klt2.PPart.dnf.push_back(pt2);
		kld1.dnf.push_back(klt1);
		kld2.dnf.push_back(klt2);
		(yyval.kldnfVector)->push_back(kld1);
		(yyval.kldnfVector)->push_back(kld2);
	}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 531 "epddlParser.y"
    {

	}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 535 "epddlParser.y"
    {

	}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 539 "epddlParser.y"
    {

	}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 543 "epddlParser.y"
    {

	}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 554 "epddlParser.y"
    {
		string actionNamePre = *(yyvsp[(4) - (20)].str);
		string actionType = *(yyvsp[(8) - (20)].str);
		for(size_t i = 0;i < actionVar.size();i++) {
			string actionName = actionNamePre + "(";
			for(size_t j = 0;j < actionVarSeq.size();j++) {
				actionName += (((j == 0) ? "" : ", ") + actionVar[i][actionVarSeq[j]]);
			}
			actionName += ")";
			SensingAction sa;
			sa.name = actionName;
			sa.preCon = (*(yyvsp[(13) - (20)].kldnfVector))[i];
			sa.posRes = (*(yyvsp[(16) - (20)].kldnfVector))[i];
			sa.negRes = (*(yyvsp[(19) - (20)].kldnfVector))[i];
			sActions.push_back(sa);
		}
	}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 578 "epddlParser.y"
    {
		string actionName = *(yyvsp[(4) - (23)].str);
		string actionType = *(yyvsp[(8) - (23)].str);
		SensingAction sa;
		sa.name = actionName;
		sa.preCon = (*(yyvsp[(16) - (23)].kldnfVector))[0];
		sa.posRes = (*(yyvsp[(19) - (23)].kldnf));
		sa.negRes = (*(yyvsp[(22) - (23)].kldnf));
		sActions.push_back(sa);
	}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 590 "epddlParser.y"
    {	
		actionVar.clear();
		actionVarSeq.clear();
		if((yyvsp[(4) - (5)].stringToString)->empty()) {
			actionVar.push_back(map<string, string>());
		}
		else {
			for(map<string, string>::iterator ite = (yyvsp[(4) - (5)].stringToString)->begin();
				ite != (yyvsp[(4) - (5)].stringToString)->end();ite++) {
				actionVarSeq.push_back(ite->first);
			}
			map<string, vector<char> > visited;
			for(map<string, vector<string> >::iterator ite = objects.begin();
				ite != objects.end();ite++) {
				visited.insert(make_pair(ite->first, vector<char>(ite->second.size(), '0')));
			}
			visited.insert(make_pair("agent", vector<char>(agents.size(), '0')));
			actionVarGround(*(yyvsp[(4) - (5)].stringToString), map<string, string>(), (yyvsp[(4) - (5)].stringToString)->begin(), visited);
		}
	}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 612 "epddlParser.y"
    {
		(yyval.stringToString) = new map<string, string>;
		(*(yyval.stringToString))[*(yyvsp[(1) - (3)].str)] = *(yyvsp[(3) - (3)].str);
	}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 617 "epddlParser.y"
    {
		(yyval.stringToString) = (yyvsp[(1) - (4)].stringToString);
		(*(yyval.stringToString))[*(yyvsp[(2) - (4)].str)] = *(yyvsp[(4) - (4)].str);
	}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 623 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		*(yyval.kldnfVector) = *(yyvsp[(1) - (1)].kldnfVector);
	}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 628 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		string generalAgentName = (yyvsp[(2) - (4)].str)->substr(2, (yyvsp[(2) - (4)].str)->length()-2);
		for(size_t i = 0;i < (yyvsp[(3) - (4)].kldnfVector)->size();i++) {
			string agentName = ((actionVar.empty() || actionVar[i].find(generalAgentName)
				== actionVar[i].end()) ? generalAgentName : actionVar[i][generalAgentName]);
			KLDNF kld;
			KLTerm klt;
			klt.KPart[agentName] = (*(yyvsp[(3) - (4)].kldnfVector))[i];
			kld.dnf.push_back(klt);
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 642 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		string generalAgentName = (yyvsp[(2) - (4)].str)->substr(3, (yyvsp[(2) - (4)].str)->length()-3);
		for(size_t i = 0;i < (yyvsp[(3) - (4)].kldnfVector)->size();i++) {
			string agentName = ((actionVar.empty() || actionVar[i].find(generalAgentName)
				== actionVar[i].end()) ? generalAgentName : actionVar[i][generalAgentName]);
			KLDNF kld;
			KLTerm klt;
			klt.LPart[agentName].push_back((*(yyvsp[(3) - (4)].kldnfVector))[i]);
			kld.dnf.push_back(klt);
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 656 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		PropDNF preConstraint;
		preConstraint.dnf.push_back(PropTerm(atomNum));
		for(size_t i = 0;i < (yyvsp[(3) - (4)].kldnfVector)->size();i++) {
			(yyval.kldnfVector)->push_back((*(yyvsp[(3) - (4)].kldnfVector))[i].negation(preConstraint));
		}
	}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 665 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		size_t row = (yyvsp[(3) - (4)].kldnfVectorVector)->size(), col = (*(yyvsp[(3) - (4)].kldnfVectorVector))[0].size();
		for(size_t j = 0;j < col;j++) {
			KLDNF kld;
			for(size_t i = 0;i < row;i++) {
				kld = kld.conjunction((*(yyvsp[(3) - (4)].kldnfVectorVector))[i][j]);
			}
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 677 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		size_t row = (yyvsp[(3) - (4)].kldnfVectorVector)->size(), col = (*(yyvsp[(3) - (4)].kldnfVectorVector))[0].size();
		for(size_t j = 0;j < col;j++) {
			KLDNF kld;
			for(size_t i = 0;i < row;i++) {
				kld = kld.disjunction((*(yyvsp[(3) - (4)].kldnfVectorVector))[i][j]);
			}
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 690 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = new vector<vector<KLDNF> >;
		(yyval.kldnfVectorVector)->push_back(*(yyvsp[(1) - (2)].kldnfVector));
		(yyval.kldnfVectorVector)->push_back(*(yyvsp[(2) - (2)].kldnfVector));
	}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 696 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = (yyvsp[(1) - (2)].kldnfVectorVector);
		(yyval.kldnfVectorVector)->push_back(*(yyvsp[(2) - (2)].kldnfVector));
	}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 702 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		for(size_t i = 0;i < (yyvsp[(2) - (3)].stringVector)->size();i++) {
			PropTerm pt(atomNum);
			KLDNF kld;
			KLTerm klt;
			string atomName = "(" + (*(yyvsp[(2) - (3)].stringVector))[i] + ")";
			if(atomName != "(True)") {
				pt.literal[findAtomsByName[atomName]] = TRUE;
			}
			klt.PPart.dnf.push_back(pt);
			kld.dnf.push_back(klt);
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 719 "epddlParser.y"
    {
		(yyval.stringVector) = new vector<string>;
		for(size_t i = 0;i < actionVar.size();i++) {
			(yyval.stringVector)->push_back((actionVar[i].find(*(yyvsp[(1) - (1)].str)) == actionVar[i].end()) ?
				*(yyvsp[(1) - (1)].str) : actionVar[i][*(yyvsp[(1) - (1)].str)]);
		}
	}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 727 "epddlParser.y"
    {
		(yyval.stringVector) = (yyvsp[(1) - (2)].stringVector);
		for(size_t i = 0;i < actionVar.size();i++) {
			(*(yyval.stringVector))[i] += (" " + ((actionVar[i].find(*(yyvsp[(2) - (2)].str)) == actionVar[i].end()) ?
				*(yyvsp[(2) - (2)].str) : actionVar[i][*(yyvsp[(2) - (2)].str)]));
		}
	}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 741 "epddlParser.y"
    {
		string actionNamePre = *(yyvsp[(4) - (19)].str);
		string actionType = *(yyvsp[(8) - (19)].str);
		for(size_t i = 0;i < actionVar.size();i++) {
			string actionName = actionNamePre + "(";
			for(size_t j = 0;j < actionVarSeq.size();j++) {
				actionName += (((j == 0) ? "" : ", ") + actionVar[i][actionVarSeq[j]]);
			}
			actionName += ")";
			OnticAction oa;
			oa.name = actionName;
			oa.preCon = (*(yyvsp[(13) - (19)].kldnfVector))[i];
			for(size_t j = 0;j < (yyvsp[(17) - (19)].kldnfVectorVectorVector)->size();j++) {
				ConditionalEffect ce;
				ce.condition = (*(yyvsp[(17) - (19)].kldnfVectorVectorVector))[j][i][0];
				ce.effect = (*(yyvsp[(17) - (19)].kldnfVectorVectorVector))[j][i][1];
				oa.eff.push_back(ce);
			}
			oActions.push_back(oa);
		}
	}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 768 "epddlParser.y"
    {
		string actionName = *(yyvsp[(4) - (22)].str);
		string actionType = *(yyvsp[(8) - (22)].str);
		OnticAction oa;
		oa.name = actionName;
		oa.preCon = (*(yyvsp[(16) - (22)].kldnfVector))[0];
		for(size_t i = 0;i < (*(yyvsp[(20) - (22)].kldnfVectorVector)).size();i++) {
			ConditionalEffect ce;
			ce.condition = (*(yyvsp[(20) - (22)].kldnfVectorVector))[i][0];
			ce.effect = (*(yyvsp[(20) - (22)].kldnfVectorVector))[i][1];
			oa.eff.push_back(ce);
		}
		oActions.push_back(oa);
	}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 784 "epddlParser.y"
    {
		(yyval.kldnfVectorVectorVector) = new vector<vector<vector<KLDNF>>>;
		(yyval.kldnfVectorVectorVector)->push_back(*(yyvsp[(1) - (1)].kldnfVectorVector));
	}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 789 "epddlParser.y"
    {
		(yyval.kldnfVectorVectorVector) = (yyvsp[(1) - (2)].kldnfVectorVectorVector);
		(yyval.kldnfVectorVectorVector)->push_back(*(yyvsp[(2) - (2)].kldnfVectorVector));
	}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 798 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = new vector<vector<KLDNF>>;
		for(size_t i = 0;i < actionVar.size();i++) {
			vector<KLDNF> temp;
			temp.push_back((*(yyvsp[(3) - (8)].kldnfVector))[i]);
			temp.push_back((*(yyvsp[(6) - (8)].kldnfVector))[i]);
			(yyval.kldnfVectorVector)->push_back(temp);
		}
	}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 809 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = new vector<vector<KLDNF>>;
		(yyval.kldnfVectorVector)->push_back(*(yyvsp[(1) - (1)].kldnfVector));
	}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 814 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = (yyvsp[(1) - (2)].kldnfVectorVector);
		(yyval.kldnfVectorVector)->push_back(*(yyvsp[(2) - (2)].kldnfVector));
	}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 823 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		(yyval.kldnfVector)->push_back((*(yyvsp[(3) - (8)].kldnfVector))[0]);
		(yyval.kldnfVector)->push_back(*(yyvsp[(6) - (8)].kldnf));
	}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 830 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		*(yyval.kldnfVector) = *(yyvsp[(1) - (1)].kldnfVector);
	}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 835 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		string generalAgentName = (yyvsp[(2) - (4)].str)->substr(2, (yyvsp[(2) - (4)].str)->length()-2);
		for(size_t i = 0;i < (yyvsp[(3) - (4)].kldnfVector)->size();i++) {
			string agentName = ((actionVar[i].find(generalAgentName)
				== actionVar[i].end()) ? generalAgentName : actionVar[i][generalAgentName]);
			KLDNF kld;
			KLTerm klt;
			klt.LPart[agentName].push_back((*(yyvsp[(3) - (4)].kldnfVector))[i]);
			kld.dnf.push_back(klt);
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 849 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		string generalAgentName = (yyvsp[(2) - (4)].str)->substr(3, (yyvsp[(2) - (4)].str)->length()-3);
		for(size_t i = 0;i < (yyvsp[(3) - (4)].kldnfVector)->size();i++) {
			string agentName = ((actionVar[i].find(generalAgentName)
				== actionVar[i].end()) ? generalAgentName : actionVar[i][generalAgentName]);
			KLDNF kld;
			KLTerm klt;
			klt.KPart[agentName] = (*(yyvsp[(3) - (4)].kldnfVector))[i];
			kld.dnf.push_back(klt);
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 863 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		PropDNF preConstraint;
		preConstraint.dnf.push_back(PropTerm(atomNum));
		for(size_t i = 0;i < (yyvsp[(3) - (4)].kldnfVector)->size();i++) {
			(yyval.kldnfVector)->push_back((*(yyvsp[(3) - (4)].kldnfVector))[i].negation(preConstraint));
		}
	}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 872 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		size_t row = (yyvsp[(3) - (4)].kldnfVectorVector)->size(), col = (*(yyvsp[(3) - (4)].kldnfVectorVector))[0].size();
		for(size_t j = 0;j < col;j++) {
			KLDNF kld;
			for(size_t i = 0;i < row;i++) {
				kld = kld.disjunction((*(yyvsp[(3) - (4)].kldnfVectorVector))[i][j]);
			}
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 884 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		size_t row = (yyvsp[(3) - (4)].kldnfVectorVector)->size(), col = (*(yyvsp[(3) - (4)].kldnfVectorVector))[0].size();
		for(size_t j = 0;j < col;j++) {
			KLDNF kld;
			for(size_t i = 0;i < row;i++) {
				kld = kld.conjunction((*(yyvsp[(3) - (4)].kldnfVectorVector))[i][j]);
			}
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 897 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = new vector<vector<KLDNF> >;
		(yyval.kldnfVectorVector)->push_back(*(yyvsp[(1) - (2)].kldnfVector));
		(yyval.kldnfVectorVector)->push_back(*(yyvsp[(2) - (2)].kldnfVector));
	}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 903 "epddlParser.y"
    {
		(yyval.kldnfVectorVector) = (yyvsp[(1) - (2)].kldnfVectorVector);
		(yyval.kldnfVectorVector)->push_back(*(yyvsp[(2) - (2)].kldnfVector));
	}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 909 "epddlParser.y"
    {
		(yyval.kldnfVector) = new vector<KLDNF>;
		for(size_t i = 0;i < (yyvsp[(2) - (3)].stringVector)->size();i++) {
			PropTerm pt(atomNum);
			KLDNF kld;
			KLTerm klt;
			string atomName = "(" + (*(yyvsp[(2) - (3)].stringVector))[i] + ")";
			if(atomName != "(True)") {
				pt.literal[findAtomsByName[atomName]] = FALSE;
			}
			else {
				pt.literal[0] = UNSAT;
			}
			klt.PPart.dnf.push_back(pt);
			kld.dnf.push_back(klt);
			(yyval.kldnfVector)->push_back(kld);
		}
	}
    break;



/* Line 1806 of yacc.c  */
#line 2789 "epddlParser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 927 "epddlParser.y"


int yyerror(char* s) {
	return 0;
}

int yyerror(std::string s) {
	return 0;
}
