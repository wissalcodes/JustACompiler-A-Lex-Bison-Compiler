/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define YYDEBUG 1 
#include "tabSymbols.h"
#include "pile.h"
extern table_symbol symbolTable;

extern char* yytext;
extern char lastIdentifier[50];

extern int lineNumber;
extern int columnNumber;

typedef struct quadruplet quadruplet;
struct quadruplet
{   
    char oprt[30];
	char op1[30];
	char op2[30];   
	char result[30]; 
};

quadruplet tab_quad[1000];

pile  stack;

int qc = 1 ; 
int ti = 0 ; 
char currentStructureName[256]; 
int structureAttributeStartIndex = 0;

#line 108 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MULTIPLY = 5,                   /* MULTIPLY  */
  YYSYMBOL_MODULO = 6,                     /* MODULO  */
  YYSYMBOL_DIVIDE = 7,                     /* DIVIDE  */
  YYSYMBOL_POW = 8,                        /* POW  */
  YYSYMBOL_LT = 9,                         /* LT  */
  YYSYMBOL_LTE = 10,                       /* LTE  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_GTE = 12,                       /* GTE  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_TOKEN_IMPORT = 15,              /* TOKEN_IMPORT  */
  YYSYMBOL_TOKEN_FUNC = 16,                /* TOKEN_FUNC  */
  YYSYMBOL_TOKEN_PROC = 17,                /* TOKEN_PROC  */
  YYSYMBOL_TOKEN_CONST = 18,               /* TOKEN_CONST  */
  YYSYMBOL_INT_LITERAL = 19,               /* INT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 20,            /* STRING_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 21,             /* FLOAT_LITERAL  */
  YYSYMBOL_TRUE_LITERAL = 22,              /* TRUE_LITERAL  */
  YYSYMBOL_FALSE_LITERAL = 23,             /* FALSE_LITERAL  */
  YYSYMBOL_TOKEN_LIST = 24,                /* TOKEN_LIST  */
  YYSYMBOL_TOKEN_ARRAY = 25,               /* TOKEN_ARRAY  */
  YYSYMBOL_TOKEN_LIFO = 26,                /* TOKEN_LIFO  */
  YYSYMBOL_TOKEN_FIFO = 27,                /* TOKEN_FIFO  */
  YYSYMBOL_TOKEN_OF = 28,                  /* TOKEN_OF  */
  YYSYMBOL_TOKEN_STRUCT = 29,              /* TOKEN_STRUCT  */
  YYSYMBOL_TOKEN_IF = 30,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 31,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_REPEAT = 32,              /* TOKEN_REPEAT  */
  YYSYMBOL_TOKEN_LOOP = 33,                /* TOKEN_LOOP  */
  YYSYMBOL_TOKEN_RETURN = 34,              /* TOKEN_RETURN  */
  YYSYMBOL_IDENTIFIER = 35,                /* IDENTIFIER  */
  YYSYMBOL_TOKEN_INT = 36,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_STRING = 37,              /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_BOOL = 38,                /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_FLOAT = 39,               /* TOKEN_FLOAT  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_DOT = 42,                       /* DOT  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_LPAREN = 44,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 45,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 46,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 47,                    /* RBRACE  */
  YYSYMBOL_TOKEN_LBRACK = 48,              /* TOKEN_LBRACK  */
  YYSYMBOL_TOKEN_RBRACK = 49,              /* TOKEN_RBRACK  */
  YYSYMBOL_INC = 50,                       /* INC  */
  YYSYMBOL_DEC = 51,                       /* DEC  */
  YYSYMBOL_NEQ = 52,                       /* NEQ  */
  YYSYMBOL_EQ = 53,                        /* EQ  */
  YYSYMBOL_NOT = 54,                       /* NOT  */
  YYSYMBOL_CONTINUE = 55,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 56,                     /* BREAK  */
  YYSYMBOL_TOKEN_EMIT = 57,                /* TOKEN_EMIT  */
  YYSYMBOL_TOKEN_RECEIVE = 58,             /* TOKEN_RECEIVE  */
  YYSYMBOL_INC_TOKEN = 59,                 /* INC_TOKEN  */
  YYSYMBOL_DEC_TOKEN = 60,                 /* DEC_TOKEN  */
  YYSYMBOL_TOKEN_BEGIN = 61,               /* TOKEN_BEGIN  */
  YYSYMBOL_TOKEN_END = 62,                 /* TOKEN_END  */
  YYSYMBOL_ADDEQUALS = 63,                 /* ADDEQUALS  */
  YYSYMBOL_SUBEQUALS = 64,                 /* SUBEQUALS  */
  YYSYMBOL_MULEQUALS = 65,                 /* MULEQUALS  */
  YYSYMBOL_DIVEQUALS = 66,                 /* DIVEQUALS  */
  YYSYMBOL_MODEQUALS = 67,                 /* MODEQUALS  */
  YYSYMBOL_ASSIGN = 68,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_program = 70,                   /* program  */
  YYSYMBOL_DeclarationFonctions = 71,      /* DeclarationFonctions  */
  YYSYMBOL_DeclarationFonction = 72,       /* DeclarationFonction  */
  YYSYMBOL_DeclarationVariables = 73,      /* DeclarationVariables  */
  YYSYMBOL_DeclarationVariable = 74,       /* DeclarationVariable  */
  YYSYMBOL_Parametres = 75,                /* Parametres  */
  YYSYMBOL_ParametreFUNC = 76,             /* ParametreFUNC  */
  YYSYMBOL_DeclarationStructuree = 77,     /* DeclarationStructuree  */
  YYSYMBOL_DeclarationSimple = 78,         /* DeclarationSimple  */
  YYSYMBOL_StructureType = 79,             /* StructureType  */
  YYSYMBOL_ReturnOpt = 80,                 /* ReturnOpt  */
  YYSYMBOL_ReturnType = 81,                /* ReturnType  */
  YYSYMBOL_SimpleType = 82,                /* SimpleType  */
  YYSYMBOL_StructuredType = 83,            /* StructuredType  */
  YYSYMBOL_Type = 84,                      /* Type  */
  YYSYMBOL_AppelFonction = 85,             /* AppelFonction  */
  YYSYMBOL_CollectionDeclaration = 86,     /* CollectionDeclaration  */
  YYSYMBOL_CollectionType = 87,            /* CollectionType  */
  YYSYMBOL_CollectionInitialization = 88,  /* CollectionInitialization  */
  YYSYMBOL_ExpressionList = 89,            /* ExpressionList  */
  YYSYMBOL_ArrayDeclaration = 90,          /* ArrayDeclaration  */
  YYSYMBOL_Dimensions = 91,                /* Dimensions  */
  YYSYMBOL_dimension_term = 92,            /* dimension_term  */
  YYSYMBOL_StructureDeclaration = 93,      /* StructureDeclaration  */
  YYSYMBOL_94_1 = 94,                      /* $@1  */
  YYSYMBOL_StructureBody = 95,             /* StructureBody  */
  YYSYMBOL_StructureAttribute = 96,        /* StructureAttribute  */
  YYSYMBOL_importations = 97,              /* importations  */
  YYSYMBOL_importation = 98,               /* importation  */
  YYSYMBOL_bloc = 99,                      /* bloc  */
  YYSYMBOL_instructions = 100,             /* instructions  */
  YYSYMBOL_instruction = 101,              /* instruction  */
  YYSYMBOL_control = 102,                  /* control  */
  YYSYMBOL_IF = 103,                       /* IF  */
  YYSYMBOL_ELSE = 104,                     /* ELSE  */
  YYSYMBOL_boucle = 105,                   /* boucle  */
  YYSYMBOL_REPEAT_boucle = 106,            /* REPEAT_boucle  */
  YYSYMBOL_REPEAT_START = 107,             /* REPEAT_START  */
  YYSYMBOL_INSTRUCTIONS_START = 108,       /* INSTRUCTIONS_START  */
  YYSYMBOL_LOOP_boucle = 109,              /* LOOP_boucle  */
  YYSYMBOL_LOOP_INIT = 110,                /* LOOP_INIT  */
  YYSYMBOL_INCDEC = 111,                   /* INCDEC  */
  YYSYMBOL_affectation = 112,              /* affectation  */
  YYSYMBOL_object_member_access = 113,     /* object_member_access  */
  YYSYMBOL_array_assignment = 114,         /* array_assignment  */
  YYSYMBOL_expression = 115,               /* expression  */
  YYSYMBOL_value = 116,                    /* value  */
  YYSYMBOL_entree_sortie = 117             /* entree_sortie  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 144 "parser.y"

/* Déclarations externes pour les variables et fonctions utilisées par l'analyseur lexical */
extern FILE *yyin;          /* Pointeur de fichier pour l'entrée */
extern int yylineno;        /* Ligne actuelle (fournie par Flex) */
extern int yyleng;          /* Longueur du dernier lexème (fournie par Flex) */
extern char *yytext;        /* Texte du dernier lexème (fournie par Flex) */
extern int yylex();        /* Fonction générée par Flex pour analyser les lexèmes */

/* Nom du fichier d'entrée */
char* file = "input.txt";

/* Colonne actuelle pour le suivi des erreurs */
int currentColumn = 1;

/* Prototypes de fonctions */
void yysuccess(char *s);    /* Fonction pour afficher un message de succès */
void yyerror(const char *s);/* Fonction pour afficher un message d'erreur syntaxique */
void yyerrorSemantic(const char *s);/* Fonction pour afficher un message d'erreur semantique */
//void LexicalError();    /* Fonction pour afficher un message d'erreur lexicale */

#line 280 "parser.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   605

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  278

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   167,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   180,   181,   185,   186,   190,   191,   194,   195,   196,
     222,   223,   228,   234,   236,   238,   242,   253,   281,   294,
     297,   300,   301,   302,   303,   308,   309,   310,   311,   312,
     315,   316,   323,   326,   327,   331,   332,   333,   339,   343,
     344,   348,   374,   385,   403,   410,   415,   420,   425,   434,
     434,   467,   468,   472,   510,   511,   513,   515,   516,   520,
     521,   525,   526,   527,   528,   529,   530,   531,   532,   537,
     538,   542,   545,   549,   550,   556,   572,   578,   598,   602,
     603,   607,   608,   614,   641,   683,   686,   722,   753,   775,
     798,   822,   845,   868,   890,   912,   934,   963,   992,  1008,
    1051,  1080,  1098,  1101,  1111,  1118,  1124,  1130,  1136,  1137,
    1144,  1189
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULTIPLY", "MODULO", "DIVIDE", "POW", "LT", "LTE", "GT", "GTE", "AND",
  "OR", "TOKEN_IMPORT", "TOKEN_FUNC", "TOKEN_PROC", "TOKEN_CONST",
  "INT_LITERAL", "STRING_LITERAL", "FLOAT_LITERAL", "TRUE_LITERAL",
  "FALSE_LITERAL", "TOKEN_LIST", "TOKEN_ARRAY", "TOKEN_LIFO", "TOKEN_FIFO",
  "TOKEN_OF", "TOKEN_STRUCT", "TOKEN_IF", "TOKEN_ELSE", "TOKEN_REPEAT",
  "TOKEN_LOOP", "TOKEN_RETURN", "IDENTIFIER", "TOKEN_INT", "TOKEN_STRING",
  "TOKEN_BOOL", "TOKEN_FLOAT", "SEMICOLON", "COLON", "DOT", "COMMA",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "TOKEN_LBRACK", "TOKEN_RBRACK",
  "INC", "DEC", "NEQ", "EQ", "NOT", "CONTINUE", "BREAK", "TOKEN_EMIT",
  "TOKEN_RECEIVE", "INC_TOKEN", "DEC_TOKEN", "TOKEN_BEGIN", "TOKEN_END",
  "ADDEQUALS", "SUBEQUALS", "MULEQUALS", "DIVEQUALS", "MODEQUALS",
  "ASSIGN", "$accept", "program", "DeclarationFonctions",
  "DeclarationFonction", "DeclarationVariables", "DeclarationVariable",
  "Parametres", "ParametreFUNC", "DeclarationStructuree",
  "DeclarationSimple", "StructureType", "ReturnOpt", "ReturnType",
  "SimpleType", "StructuredType", "Type", "AppelFonction",
  "CollectionDeclaration", "CollectionType", "CollectionInitialization",
  "ExpressionList", "ArrayDeclaration", "Dimensions", "dimension_term",
  "StructureDeclaration", "$@1", "StructureBody", "StructureAttribute",
  "importations", "importation", "bloc", "instructions", "instruction",
  "control", "IF", "ELSE", "boucle", "REPEAT_boucle", "REPEAT_START",
  "INSTRUCTIONS_START", "LOOP_boucle", "LOOP_INIT", "INCDEC",
  "affectation", "object_member_access", "array_assignment", "expression",
  "value", "entree_sortie", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     397,   -30,   -27,   -22,   -18,    -6,     0,     3,     7,    29,
    -159,  -159,  -159,  -159,  -159,   547,    49,     2,  -159,   453,
    -159,  -159,  -159,    33,    34,  -159,    35,  -159,  -159,   426,
    -159,    44,    50,    51,    28,    53,    53,    53,    53,  -159,
      72,    74,    75,   491,    91,    98,  -159,  -159,  -159,    31,
     547,  -159,  -159,    66,  -159,  -159,   130,  -159,   120,  -159,
      93,    94,  -159,  -159,   547,  -159,   547,     4,  -159,   123,
     126,   -36,   547,    22,   480,  -159,  -159,   306,   306,   130,
    -159,    77,  -159,  -159,   121,   130,  -159,     9,   133,   130,
     130,  -159,  -159,   130,   153,   155,  -159,  -159,   131,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,   130,   130,   547,   134,
    -159,  -159,   130,   130,   116,   118,   547,  -159,  -159,  -159,
     136,   132,   547,   547,    25,  -159,  -159,  -159,  -159,  -159,
     138,   158,  -159,  -159,   146,   157,   119,   156,    53,   186,
     137,   168,   166,  -159,   162,   211,    68,   237,   165,   167,
     547,   262,  -159,   510,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   163,   130,   130,   288,   313,
    -159,  -159,   164,   130,   179,  -159,   170,   171,   547,   187,
     306,  -159,   183,  -159,   135,   190,   199,   188,   196,   191,
     130,   177,   130,   212,   130,  -159,  -159,   218,   220,   209,
    -159,  -159,   511,   511,   396,   396,   396,   517,   517,   517,
     517,  -159,  -159,  -159,   517,   517,  -159,  -159,  -159,   210,
    -159,  -159,  -159,   197,   306,   214,  -159,   547,  -159,  -159,
    -159,  -159,  -159,  -159,   213,  -159,  -159,   221,    53,   547,
     377,   130,   345,  -159,  -159,   225,   233,  -159,  -159,  -159,
    -159,   547,   232,  -159,  -159,  -159,   234,   377,   223,   240,
     242,   249,  -159,    66,    -5,   239,  -159,  -159,   130,   238,
    -159,   241,   364,  -159,   547,  -159,   256,  -159
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    31,    33,    34,    32,    67,     0,     0,    11,     0,
      15,    18,    17,     0,     0,    24,     0,    23,    25,     0,
      64,     0,     0,     0,     0,     0,     0,     0,     0,    59,
       0,     0,     0,    28,     0,     0,    78,    75,    77,     0,
      68,    69,    72,    80,    73,    83,     0,    84,     0,    71,
       0,     0,    74,     1,    67,    12,    67,     0,    16,     0,
       0,     0,    67,     0,     0,    65,    66,     0,     0,     0,
      45,     0,    47,    46,     0,     0,    86,     0,     0,     0,
       0,    91,    92,     0,     0,     0,    10,    70,     0,    79,
     115,   117,   116,   118,   119,   113,     0,     0,     0,     0,
     114,    76,     0,     0,     0,     0,    67,    27,    26,    43,
       0,     0,    67,    67,     0,    38,    35,    37,    36,    39,
       0,    20,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,    49,     0,     0,     0,     0,
      67,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     6,     0,     0,     0,     3,     0,     0,    67,     0,
       0,    22,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    93,     0,     0,     0,
     112,    85,   106,   107,   108,   110,   109,   102,   104,   105,
     103,    99,    98,    87,   101,   100,    95,    94,     8,     0,
      44,     9,     4,     0,     0,     0,    21,    67,    54,    56,
      55,    57,    58,    53,     0,    51,    63,     0,    62,    67,
      89,     0,     0,    42,    50,     0,     0,    82,    48,     5,
      30,    67,     0,    52,    60,    61,     0,    90,     0,     0,
       0,     0,    14,     0,     0,     0,   121,   120,     0,     0,
      81,     0,     0,    13,    67,    29,     0,    88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,   -13,   -15,   257,   -12,   -66,  -159,  -159,    11,
    -159,  -159,  -159,   -11,  -159,    64,  -159,    14,  -159,  -159,
    -158,  -159,  -159,  -159,  -159,  -159,    58,  -159,  -159,   275,
     -63,   198,   -40,  -159,  -159,    42,  -159,  -159,  -159,  -159,
    -159,  -159,    52,  -159,  -159,  -159,   -56,  -159,  -159
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    16,    17,    18,    19,    20,   130,   131,    21,    46,
      23,   269,   225,    24,   133,   134,    47,    48,    26,   174,
     144,    27,   185,   234,    28,    84,   187,   188,    29,    30,
      49,    50,    51,    52,    53,    99,    54,    55,    56,   108,
      57,   142,    58,    59,    60,    61,   145,   110,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,   114,    65,   115,   119,    31,    67,    68,    32,   121,
      97,    22,   135,    33,    25,   219,    73,    34,     2,     3,
       2,     3,    35,   136,    80,    81,    82,    83,    36,   139,
      22,    37,   120,    25,   146,    38,   244,   147,     2,     3,
      22,     2,     3,    25,   140,    11,    12,    13,    14,    63,
     151,   152,    65,   172,    91,    92,   168,   169,    65,   176,
     177,   124,    68,    64,    39,   116,   132,   132,    69,    70,
      71,   154,   155,   156,   157,   158,   141,   159,   160,   161,
     162,   163,   164,   122,    76,    22,   178,   199,    25,    11,
      12,    13,    14,    96,    77,    78,    79,    98,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    65,
     214,   215,   137,    97,   226,   223,    85,   195,    86,    87,
     166,   167,   154,   155,   156,   157,   158,   186,   159,   160,
     161,   162,   163,   164,   240,    94,   242,   154,   155,   156,
     157,   158,    95,   159,   160,   161,   162,   163,   164,   100,
     101,   102,   103,   104,   228,   229,   230,   231,   232,   183,
     111,   112,   113,   117,   252,   105,   118,   138,   143,   132,
     233,   166,   167,   148,   106,   149,   256,   150,   170,   165,
     171,   181,   173,   179,   107,   257,   166,   167,   261,   154,
     155,   156,   157,   158,   175,   159,   160,   161,   162,   163,
     164,   180,   182,   191,   184,   190,   192,   193,   197,   213,
     198,   276,   272,   132,   154,   155,   156,   157,   158,   220,
     159,   160,   161,   162,   163,   164,   218,   186,   224,   227,
     235,   189,   221,   222,   236,   237,   238,   239,   166,   167,
     154,   155,   156,   157,   158,   241,   159,   160,   161,   162,
     163,   164,   243,   245,   194,   246,   247,   248,   264,   249,
     251,   254,   253,   166,   167,   154,   155,   156,   157,   158,
     259,   159,   160,   161,   162,   163,   164,   196,   260,   262,
     266,   263,   267,   268,   271,   273,    74,   274,   250,   166,
     167,   154,   155,   156,   157,   158,   255,   159,   160,   161,
     162,   163,   164,   277,    75,   270,   153,   200,     0,     0,
     265,     0,     0,     0,   166,   167,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   216,     0,
     125,   126,   127,   128,     0,   129,     0,     0,     0,     0,
     166,   167,    11,    12,    13,    14,     0,     0,   154,   155,
     156,   157,   158,   217,   159,   160,   161,   162,   163,   164,
       0,     0,     0,     0,     0,   166,   167,   154,   155,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,     0,
     154,   155,   156,   157,   158,   258,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,     0,   166,   167,   154,
     155,     0,     0,     0,   275,   159,   160,   161,   162,   163,
     164,     0,     1,     2,     3,     4,   166,   167,     0,     0,
       0,     5,     6,     7,     8,     0,     9,     0,     0,   166,
     167,     0,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     1,     2,     3,     4,     0,     0,     0,   166,   167,
       5,     6,     7,     8,     0,     9,     0,     0,    15,     0,
       0,    10,    11,    12,    13,    14,     0,     0,     0,     2,
       3,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,    72,    10,    11,
      12,    13,    14,     0,     0,     0,     2,     3,     4,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,    66,    10,    11,    12,    13,    14,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     163,   164,     0,    88,     5,    89,     7,     8,     0,    90,
      40,   123,    41,    42,     0,    43,    11,    12,    13,    14,
      91,    92,     0,     0,     0,     0,     0,   201,     0,    93,
       0,     0,     0,   166,   167,     0,     0,    44,    45,    -1,
      -1,     5,     0,     7,     8,     0,     0,    40,     0,    41,
      42,     0,    43,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45
};

static const yytype_int16 yycheck[] =
{
      56,    64,    17,    66,    40,    35,    19,    19,    35,    72,
      50,     0,    78,    35,     0,   173,    29,    35,    16,    17,
      16,    17,    28,    79,    35,    36,    37,    38,    28,    85,
      19,    28,    68,    19,    90,    28,   194,    93,    16,    17,
      29,    16,    17,    29,    35,    36,    37,    38,    39,     0,
     106,   107,    67,   116,    59,    60,   112,   113,    73,   122,
     123,    74,    74,    61,    35,    61,    77,    78,    35,    35,
      35,     3,     4,     5,     6,     7,    87,     9,    10,    11,
      12,    13,    14,    61,    40,    74,    61,   150,    74,    36,
      37,    38,    39,    62,    44,    44,    68,    31,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   124,
     166,   167,    35,   153,   180,   178,    44,    49,    44,    44,
      52,    53,     3,     4,     5,     6,     7,   138,     9,    10,
      11,    12,    13,    14,   190,    44,   192,     3,     4,     5,
       6,     7,    44,     9,    10,    11,    12,    13,    14,    19,
      20,    21,    22,    23,    19,    20,    21,    22,    23,    40,
      40,    68,    68,    40,   227,    35,    40,    46,    35,   180,
      35,    52,    53,    20,    44,    20,   239,    46,    62,    45,
      62,    35,    46,    45,    54,   241,    52,    53,   251,     3,
       4,     5,     6,     7,    62,     9,    10,    11,    12,    13,
      14,    43,    45,    35,    48,    68,    40,    45,    43,    46,
      43,   274,   268,   224,     3,     4,     5,     6,     7,    40,
       9,    10,    11,    12,    13,    14,    62,   238,    41,    46,
      40,    45,    62,    62,    35,    47,    40,    46,    52,    53,
       3,     4,     5,     6,     7,    68,     9,    10,    11,    12,
      13,    14,    40,    35,    43,    35,    47,    47,    35,    62,
      46,    40,    49,    52,    53,     3,     4,     5,     6,     7,
      45,     9,    10,    11,    12,    13,    14,    40,    45,    47,
      40,    47,    40,    34,    45,    47,    29,    46,   224,    52,
      53,     3,     4,     5,     6,     7,   238,     9,    10,    11,
      12,    13,    14,    47,    29,   263,   108,    45,    -1,    -1,
     258,    -1,    -1,    -1,    52,    53,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    40,    -1,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    -1,
      52,    53,    36,    37,    38,    39,    -1,    -1,     3,     4,
       5,     6,     7,    40,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    52,    53,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    -1,
       3,     4,     5,     6,     7,    40,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    52,    53,     3,
       4,    -1,    -1,    -1,    40,     9,    10,    11,    12,    13,
      14,    -1,    15,    16,    17,    18,    52,    53,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    29,    -1,    -1,    52,
      53,    -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    52,    53,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    61,    -1,
      -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    -1,    61,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    -1,    61,    35,    36,    37,    38,    39,
       9,    10,    11,    12,    13,    14,     9,    10,    11,    12,
      13,    14,    -1,    42,    24,    44,    26,    27,    -1,    48,
      30,    61,    32,    33,    -1,    35,    36,    37,    38,    39,
      59,    60,    -1,    -1,    -1,    -1,    -1,    47,    -1,    68,
      -1,    -1,    -1,    52,    53,    -1,    -1,    57,    58,    52,
      53,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    16,    17,    18,    24,    25,    26,    27,    29,
      35,    36,    37,    38,    39,    61,    70,    71,    72,    73,
      74,    77,    78,    79,    82,    86,    87,    90,    93,    97,
      98,    35,    35,    35,    35,    28,    28,    28,    28,    35,
      30,    32,    33,    35,    57,    58,    78,    85,    86,    99,
     100,   101,   102,   103,   105,   106,   107,   109,   111,   112,
     113,   114,   117,     0,    61,    72,    61,    71,    74,    35,
      35,    35,    61,    71,    73,    98,    40,    44,    44,    68,
      82,    82,    82,    82,    94,    44,    44,    44,    42,    44,
      48,    59,    60,    68,    44,    44,    62,   101,    31,   104,
      19,    20,    21,    22,    23,    35,    44,    54,   108,   115,
     116,    40,    68,    68,    99,    99,    61,    40,    40,    40,
      68,    99,    61,    61,    71,    24,    25,    26,    27,    29,
      75,    76,    82,    83,    84,    75,   115,    35,    46,   115,
      35,    82,   110,    35,    89,   115,   115,   115,    20,    20,
      46,   115,   115,   100,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    45,    52,    53,   115,   115,
      62,    62,    99,    46,    88,    62,    99,    99,    61,    45,
      43,    35,    45,    40,    48,    91,    82,    95,    96,    45,
      68,    35,    40,    45,    43,    49,    40,    43,    43,    99,
      45,    47,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,    46,   115,   115,    40,    40,    62,    89,
      40,    62,    62,    99,    41,    81,    75,    46,    19,    20,
      21,    22,    23,    35,    92,    40,    35,    47,    40,    46,
     115,    68,   115,    40,    89,    35,    35,    47,    47,    62,
      84,    46,    99,    49,    40,    95,    99,   115,    40,    45,
      45,    99,    47,    47,    35,   111,    40,    40,    34,    80,
     104,    45,   115,    47,    46,    40,    99,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    75,    76,    77,    77,    77,    78,    78,    79,    80,
      81,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      84,    84,    85,    86,    86,    87,    87,    87,    88,    89,
      89,    90,    91,    92,    92,    92,    92,    92,    92,    94,
      93,    95,    95,    96,    97,    97,    98,    99,    99,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   104,   105,   105,   106,   107,   108,   109,   110,
     110,   111,   111,   112,   112,   112,   113,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   116,   116,   116,   116,   116,
     117,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     5,     6,     4,     4,     5,     5,
       3,     1,     2,    10,     8,     1,     2,     1,     1,     5,
       1,     3,     2,     1,     1,     1,     3,     3,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     3,     5,     3,     3,     3,     3,     1,
       3,     6,     3,     1,     1,     1,     1,     1,     1,     0,
       7,     3,     2,     2,     1,     2,     3,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       1,     8,     4,     1,     1,     4,     2,     3,    11,     3,
       4,     2,     2,     4,     4,     4,     3,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       7,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 19: /* DeclarationVariable: TOKEN_CONST IDENTIFIER ASSIGN expression SEMICOLON  */
#line 196 "parser.y"
                                                         {
    desc_identif *existingEntry = lookupSymbol((yyvsp[-3].strval)); // $2 corresponds to IDENTIFIER
    if (existingEntry != NULL) {
        yyerrorSemantic("La variable est déjà déclarée");
    } else {
        int result = insertSymbol(
            (yyvsp[-3].strval),               
            C_CONST,        
            (yyvsp[-1].expressionTYPE).type,         
            yylineno,       
            (yyvsp[-1].expressionTYPE).val,         
            false,           
            0,              
            true,            
            true ,
            NULL  
        );

        if (result == -1) {
            printf("Erreur : Échec de l'insertion du constant '%s'.\n", (yyvsp[-3].strval));
        }
    }
    }
#line 1518 "parser.tab.c"
    break;

  case 26: /* DeclarationSimple: SimpleType IDENTIFIER SEMICOLON  */
#line 244 "parser.y"
     {
        desc_identif* symbol = lookupSymbol((yyvsp[-1].strval));
        if (symbol != NULL) {
               yyerrorSemantic("La variable est déjà déclarée");
        }
        else{
            insertSymbol((yyvsp[-1].strval), C_VAR, (yyvsp[-2].type), yylineno,"",false, 0, false, false,NULL );
        }
    }
#line 1532 "parser.tab.c"
    break;

  case 27: /* DeclarationSimple: StructureType IDENTIFIER SEMICOLON  */
#line 253 "parser.y"
                                          {
        desc_identif* symbol = lookupSymbol((yyvsp[-1].strval));
        if (symbol != NULL) {
             yyerrorSemantic("La variable est déjà déclarée");
        } else {
            int result = insertSymbol(
                (yyvsp[-1].strval),    // Nom de la variable
                C_VAR,         // Classe : Variable
                7,            // Type de la variable (structure)
                yylineno,      // Ligne de déclaration
                "",            // Pas de valeur initiale
                false,         // Pas un tableau
                0,             // Taille du tableau (non applicable)
                false,         // Pas initialisé
                false,         // Pas une constante
                (yyvsp[-2].strval)           //  structure parente
            );

            if (result == -1) {
                printf("Erreur : Échec de l'insertion de la variable '%s' dans la table des symboles.\n", (yyvsp[-1].strval));
            }
        }
    }
#line 1560 "parser.tab.c"
    break;

  case 28: /* StructureType: IDENTIFIER  */
#line 282 "parser.y"
    {
        // Vérifier que la structure existe
        desc_identif* entry = lookupSymbol((yyvsp[0].strval));
        if (entry == NULL || entry->type != T_OBJECT) {
            yyerrorSemantic("La variable est déjà déclarée");
        } else {
             // Retourner le type de la structure
            (yyval.strval)=(yyvsp[0].strval);
        }
    }
#line 1575 "parser.tab.c"
    break;

  case 31: /* SimpleType: TOKEN_INT  */
#line 300 "parser.y"
                 { (yyval.type) = T_INT; }
#line 1581 "parser.tab.c"
    break;

  case 32: /* SimpleType: TOKEN_FLOAT  */
#line 301 "parser.y"
                    { (yyval.type) = T_FLOAT; }
#line 1587 "parser.tab.c"
    break;

  case 33: /* SimpleType: TOKEN_STRING  */
#line 302 "parser.y"
                   { (yyval.type) = T_STRING; }
#line 1593 "parser.tab.c"
    break;

  case 34: /* SimpleType: TOKEN_BOOL  */
#line 303 "parser.y"
                   { (yyval.type) = T_BOOL; }
#line 1599 "parser.tab.c"
    break;

  case 51: /* ArrayDeclaration: TOKEN_ARRAY TOKEN_OF SimpleType IDENTIFIER Dimensions SEMICOLON  */
#line 349 "parser.y"
    {
        desc_identif* entry = lookupSymbol((yyvsp[-2].strval));
        if (entry != NULL) {
            yyerrorSemantic("La variable est déjà déclarée");
        } else {
            int result = insertSymbol(
                (yyvsp[-2].strval),    // Identifier name
                C_VAR,         // Class: Variable
                (yyvsp[-3].type),       // Type: Comes from SimpleType
                yylineno,      // Line number
                "",            // No initial value
                true,          // isArray = true
                atoi((yyvsp[-1].expressionTYPE).val),            // Array size (calculated in Dimensions)
                false,         // isInitialized = false
                false,
                NULL          // isConstant = false
            );

            if (result == -1) {
                printf("Erreur : Échec de l'insertion de l'array '%s' dans la table des symboles.\n", (yyvsp[-2].strval));
            }
        }
    }
#line 1627 "parser.tab.c"
    break;

  case 52: /* Dimensions: TOKEN_LBRACK dimension_term TOKEN_RBRACK  */
#line 375 "parser.y"
    {
        if (atoi( (yyvsp[-1].expressionTYPE).val) < 1) {
            yyerrorSemantic("La taille du tableau doit être un entier positif");
            exit(1);
        }
        (yyval.expressionTYPE) = (yyvsp[-1].expressionTYPE);  
    }
#line 1639 "parser.tab.c"
    break;

  case 53: /* dimension_term: IDENTIFIER  */
#line 386 "parser.y"
    {
        desc_identif *entry = lookupSymbol((yyvsp[0].strval));
        if (entry == NULL) {
            yyerrorSemantic("Variable utilisée mais non déclarée");
            exit(1);
        }
        if (!entry->isInitialized) {
            yyerrorSemantic("Variable utilisée sans être initialisée");
            exit(1);
        }
        if (entry->type != T_INT) {
            yyerrorSemantic("Les dimensions des tableaux doivent être des entiers");
            exit(1);
        }
        strcpy((yyval.expressionTYPE).val,entry->valeur );
        (yyval.expressionTYPE).type = T_INT;              
    }
#line 1661 "parser.tab.c"
    break;

  case 54: /* dimension_term: INT_LITERAL  */
#line 404 "parser.y"
{
  char buffer[20]; 
    sprintf(buffer, "%d", (yyvsp[0].intval));
    strcpy((yyval.expressionTYPE).val, buffer);  
    (yyval.expressionTYPE).type = T_INT;   
}
#line 1672 "parser.tab.c"
    break;

  case 55: /* dimension_term: FLOAT_LITERAL  */
#line 411 "parser.y"
    {
        yyerrorSemantic("Les dimensions des tableaux ne peuvent pas être de type float");
        exit(1);
    }
#line 1681 "parser.tab.c"
    break;

  case 56: /* dimension_term: STRING_LITERAL  */
#line 416 "parser.y"
    {
        printf("Les dimensions des tableaux ne peuvent pas être de type string");
        exit(1);
    }
#line 1690 "parser.tab.c"
    break;

  case 57: /* dimension_term: TRUE_LITERAL  */
#line 421 "parser.y"
    {
        printf("Les dimensions des tableaux ne peuvent pas être de type bool");
        exit(1);
    }
#line 1699 "parser.tab.c"
    break;

  case 58: /* dimension_term: FALSE_LITERAL  */
#line 426 "parser.y"
    {
        printf("Les dimensions des tableaux ne peuvent pas être de type bool");
        exit(1);
    }
#line 1708 "parser.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 434 "parser.y"
                            {
        structureAttributeStartIndex = symbolTable.sommet;
        strcpy(currentStructureName, (yyvsp[0].strval)); 
    }
#line 1717 "parser.tab.c"
    break;

  case 60: /* StructureDeclaration: TOKEN_STRUCT IDENTIFIER $@1 LBRACE StructureBody RBRACE SEMICOLON  */
#line 438 "parser.y"
    {
        int result = insertSymbol(
            (yyvsp[-5].strval),           
            C_TYPE,       
            T_OBJECT,     
            yylineno,     
            "",           
            false,        
            0,            
            false,        
            false,        
            NULL          
        );
       
        if (result == -1) {
            printf("Erreur : Échec de l'insertion de la structure '%s' dans la table des symboles.\n", (yyvsp[-5].strval));
        }
        int endIndex = symbolTable.sommet;
        for (int i = structureAttributeStartIndex; i < endIndex; i++) {
            if (symbolTable.tab[i].classe == C_CHAMP) {
                if (symbolTable.tab[i].parentStructure != NULL) {
                    free(symbolTable.tab[i].parentStructure);
                }
                symbolTable.tab[i].parentStructure = strdup((yyvsp[-5].strval));
            }
        }
    }
#line 1749 "parser.tab.c"
    break;

  case 61: /* StructureBody: StructureAttribute SEMICOLON StructureBody  */
#line 467 "parser.y"
                                               { (yyval.strval)=(yyvsp[-2].strval);}
#line 1755 "parser.tab.c"
    break;

  case 62: /* StructureBody: StructureAttribute SEMICOLON  */
#line 468 "parser.y"
                                  { (yyval.strval)=(yyvsp[-1].strval);}
#line 1761 "parser.tab.c"
    break;

  case 63: /* StructureAttribute: SimpleType IDENTIFIER  */
#line 473 "parser.y"
    {
        desc_identif* entry = lookupSymbol((yyvsp[0].strval));
        if (entry != NULL) {
            yyerrorSemantic("Erreur : Attribut déjà déclaré dans la structure");
        } else {
             
            int result = insertSymbol(
                (yyvsp[0].strval),           // Nom de l'attribut
                C_CHAMP,      // Classe : Champ de structure
                (yyvsp[-1].type),           // Type de l'attribut
                yylineno,     // Ligne de déclaration
                "",           // Pas de valeur initiale
                false,        // Pas un tableau
                0,            // Taille du tableau (non applicable)
                true,        // Pas initialisé
                false,        // Pas une constante
                currentStructureName  // Nom de la structure parente
            );

            if (result == -1) {
                printf("Erreur : Échec de l'insertion de l'attribut '%s' dans la table des symboles.\n", (yyvsp[0].strval));
            }
            
        }
       
        (yyval.strval)=(yyvsp[0].strval);
    }
#line 1793 "parser.tab.c"
    break;

  case 85: /* REPEAT_boucle: REPEAT_START INSTRUCTIONS_START instructions RBRACE  */
#line 556 "parser.y"
                                                       {
    char adresse[10];
    char adresseCondWhile [10];

     int sauvAdrDebutWhile = depiler(&stack);  
    int sauvAdrCondWhile = depiler(&stack);  
    sprintf(adresseCondWhile,"%d",sauvAdrCondWhile);
    strcpy(tab_quad[qc].oprt,"BR");
    strcpy(tab_quad[qc].op1,adresseCondWhile);
    strcpy(tab_quad[qc].op2,"");
    strcpy(tab_quad[qc].result,"");
    qc++;
    sprintf(adresse,"%d",qc);
    strcpy(tab_quad[sauvAdrCondWhile+1].op1,adresse);
    }
#line 1813 "parser.tab.c"
    break;

  case 86: /* REPEAT_START: TOKEN_REPEAT LPAREN  */
#line 572 "parser.y"
                                  { 
    empiler(&stack,qc); 
    qc++;
  }
#line 1822 "parser.tab.c"
    break;

  case 87: /* INSTRUCTIONS_START: expression RPAREN LBRACE  */
#line 578 "parser.y"
                              { 
    if((yyvsp[-2].expressionTYPE).type == T_BOOL){
        char r[20]; 
        sprintf(r,(yyvsp[-2].expressionTYPE).val,qc-1);	
          strcpy(tab_quad[qc].oprt,"BZ");
            strcpy(tab_quad[qc].op1,"tmp");
            strcpy(tab_quad[qc].op2,"");
            strcpy(tab_quad[qc].result,r);
        empiler(&stack,qc); 
        qc++; 
    }else{
        printf("Semantic error : cannot evaluate non boolean expression as condition");
    }
}
#line 1841 "parser.tab.c"
    break;

  case 93: /* affectation: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 614 "parser.y"
                                           {     

        desc_identif* symbol = lookupSymbol((yyvsp[-3].strval));
        if (symbol == NULL) {
            yyerrorSemantic("Variable non declaree");
            exit(1);
        }
        if (symbol->type == T_FLOAT && (yyvsp[-1].expressionTYPE).type == T_INT) {
            (yyvsp[-1].expressionTYPE).type = T_FLOAT;  
        } else if (symbol->type == T_INT && (yyvsp[-1].expressionTYPE).type == T_FLOAT) {
            symbol->type = T_FLOAT;  
        } else if (symbol->type != (yyvsp[-1].expressionTYPE).type) {
            yyerrorSemantic("Type mismatch in assignment");
        } else {
            strcpy(tab_quad[qc].oprt, "=");
            strcpy(tab_quad[qc].op1, (yyvsp[-1].expressionTYPE).val);
            strcpy(tab_quad[qc].op2, "");
            strcpy(tab_quad[qc].result, (yyvsp[-3].strval));
            qc++;
            desc_identif* symbol = lookupSymbol((yyvsp[-3].strval));
            if (symbol != NULL) {
            symbol->isInitialized = true;
            strcpy( symbol->valeur , (yyvsp[-1].expressionTYPE).val);
         }       
       }
    }
#line 1872 "parser.tab.c"
    break;

  case 94: /* affectation: array_assignment ASSIGN expression SEMICOLON  */
#line 641 "parser.y"
                                                  {        
        if ((yyvsp[-3].expressionTYPE).type == T_FLOAT && (yyvsp[-1].expressionTYPE).type == T_INT) {
            (yyvsp[-1].expressionTYPE).type = T_FLOAT;  
        } else if ((yyvsp[-3].expressionTYPE).type == T_INT && (yyvsp[-1].expressionTYPE).type == T_FLOAT) {
            (yyvsp[-3].expressionTYPE).type = T_FLOAT;  
        } else if ((yyvsp[-3].expressionTYPE).type != (yyvsp[-1].expressionTYPE).type) {
            yyerrorSemantic("Type mismatch in assignment");
        } else {
            if ((yyvsp[-3].expressionTYPE).isArrayElement == 1){
                char arrayAccess[20];
                sprintf(arrayAccess, "%s[%d]", (yyvsp[-3].expressionTYPE).arrayName, (yyvsp[-3].expressionTYPE).index);
                setArrayElement((yyvsp[-3].expressionTYPE).arrayName, (yyvsp[-3].expressionTYPE).index, (yyvsp[-1].expressionTYPE).val);
                    strcpy(tab_quad[qc].oprt, "=");
                    strcpy(tab_quad[qc].op1,(yyvsp[-1].expressionTYPE).val );
                    strcpy(tab_quad[qc].op2, "");

                    char tempVar[10];
                    strcpy(tab_quad[qc].result,arrayAccess);
                    qc++;
            }
            else {

            strcpy(tab_quad[qc].oprt, "=");
            strcpy(tab_quad[qc].op1, (yyvsp[-3].expressionTYPE).val);
            strcpy(tab_quad[qc].op2, (yyvsp[-1].expressionTYPE).val);

            char tempVar[10];
            sprintf(tempVar, "T%d", ti);
            strcpy(tab_quad[qc].result, tempVar);
            qc++;
            ti++;
            desc_identif* symbol = lookupSymbol((yyvsp[-3].expressionTYPE).val);
            if (symbol != NULL) {
                symbol->isInitialized = true;
                strcpy( symbol->valeur , (yyvsp[-1].expressionTYPE).val);
            }
        

         }       
       }
    }
#line 1918 "parser.tab.c"
    break;

  case 96: /* object_member_access: IDENTIFIER DOT IDENTIFIER  */
#line 687 "parser.y"
    {
        // Vérifier que le premier identifiant est une structure
        desc_identif* structure = lookupSymbol((yyvsp[-2].strval));
        if (structure == NULL || structure->type != T_OBJECT) {
            yyerrorSemantic("L'identifiant n'est pas une structure.");
        } else {
            // Vérifier que le deuxième identifiant est un attribut de la structure
            desc_identif* attribut = lookupSymbolInStructure((yyvsp[-2].strval), (yyvsp[0].strval));
           // printf("attribut est %s",attribut);
            if (attribut == NULL) {
                yyerrorSemantic("L'attribut  n'existe pas dans la structure.");
            } else {
                // Retourner le type et la valeur de l'attribut
                (yyval.expressionTYPE).type = attribut->type;                // Type de l'attribut
              snprintf((yyval.expressionTYPE).val, sizeof((yyval.expressionTYPE).val), "%s.%s", (yyvsp[-2].strval), (yyvsp[0].strval));  // Valeur de l'attribut
               int result = insertSymbol(
               (yyval.expressionTYPE).val,           // Nom de l'attribut
                C_CHAMP,      // Classe : Champ de structure
                (yyval.expressionTYPE).type,           // Type de l'attribut
                yylineno,     // Ligne de déclaration
                "",           // Pas de valeur initiale
                false,        // Pas un tableau
                0,            // Taille du tableau (non applicable)
                true,        // Pas initialisé
                false,        // Pas une constante
                attribut->parentStructure  // Nom de la structure parente
            );

                  strcpy((yyval.expressionTYPE).tempVar, "");                  // Variable temporaire (non utilisée ici)
            }
        }
    }
#line 1955 "parser.tab.c"
    break;

  case 97: /* array_assignment: IDENTIFIER TOKEN_LBRACK expression TOKEN_RBRACK  */
#line 723 "parser.y"
    {
        desc_identif* symbol = lookupSymbol((yyvsp[-3].strval));  
        if (symbol == NULL) {
            yyerrorSemantic("Tableau non declare");
            exit(1);
        } else {
            if (!symbol->isArray) {
                yyerrorSemantic("La variable est referencee comme tableau mais elle est d'un type different");
                exit(1);
            } else {
                // Check index bounds
                if (atoi((yyvsp[-1].expressionTYPE).val) > symbol->ArraySize) {
                    yyerrorSemantic("Indice hors des limites du tableau");
                    exit(1);
                }
                else{
                    // insert value in the corresponding index
                    int index = atoi((yyvsp[-1].expressionTYPE).val);
                    (yyval.expressionTYPE).index = index;
                    (yyval.expressionTYPE).isArrayElement = 1;
                    (yyval.expressionTYPE).arrayName = (yyvsp[-3].strval);
                    (yyval.expressionTYPE).type = symbol->type;
                }

            }
        }
    }
#line 1987 "parser.tab.c"
    break;

  case 98: /* expression: expression OR expression  */
#line 753 "parser.y"
                           { 
   // OR operator
if ((yyvsp[-2].expressionTYPE).type == T_BOOL && (yyvsp[0].expressionTYPE).type == T_BOOL) {
    int val1 = strcmp((yyvsp[-2].expressionTYPE).val, "true") == 0 ? 1 : 0;
    int val2 = strcmp((yyvsp[0].expressionTYPE).val, "true") == 0 ? 1 : 0;
    int result = val1 || val2;
    char res[10];
    sprintf(res, "T%d", ti);
    strcpy(tab_quad[qc].oprt, "|");
    strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
    strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);
    strcpy(tab_quad[qc].result, res);
    strcpy((yyval.expressionTYPE).val, result ? "true" : "false");

    (yyval.expressionTYPE).type = T_BOOL;

    ti++;
    qc++;
} else {
    yyerrorSemantic("Type expression incompatible");
}}
#line 2013 "parser.tab.c"
    break;

  case 99: /* expression: expression AND expression  */
#line 775 "parser.y"
                                  { 
if ((yyvsp[-2].expressionTYPE).type == T_BOOL && (yyvsp[0].expressionTYPE).type == T_BOOL) {
    int val1 = strcmp((yyvsp[-2].expressionTYPE).val, "true") == 0 ? 1 : 0;
    int val2 = strcmp((yyvsp[0].expressionTYPE).val, "true") == 0 ? 1 : 0;

    int result = val1 && val2;

    char res[10];
    sprintf(res, "T%d", ti);
    strcpy(tab_quad[qc].oprt, "&");
    strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
    strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);
    strcpy(tab_quad[qc].result, res);
        strcpy((yyval.expressionTYPE).val, result ? "true" : "false");

    (yyval.expressionTYPE).type = T_BOOL;

    ti++;
    qc++;
} else {
    yyerrorSemantic("Type expression incompatible");
}
    }
#line 2041 "parser.tab.c"
    break;

  case 100: /* expression: expression EQ expression  */
#line 798 "parser.y"
                             { 
         
          if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type) {
    int result = strcmp((yyvsp[-2].expressionTYPE).val, (yyvsp[0].expressionTYPE).val) == 0;

    (yyval.expressionTYPE).type = T_BOOL;
    strcpy(tab_quad[qc].oprt, "BE");
    strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
    strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);

    char res[10];
    sprintf(res, "T%d", ti);
    strcpy(tab_quad[qc].result, res);

        strcpy((yyval.expressionTYPE).val, result ? "true" : "false");


    ti++;
    qc++;
} else {
    yyerrorSemantic("Type expression incompatible");
}

                     }
#line 2070 "parser.tab.c"
    break;

  case 101: /* expression: expression NEQ expression  */
#line 822 "parser.y"
                                 { 
           if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type) {
    int result = strcmp((yyvsp[-2].expressionTYPE).val, (yyvsp[0].expressionTYPE).val) == 0;

    (yyval.expressionTYPE).type = T_BOOL;
    strcpy(tab_quad[qc].oprt, "BE");
    strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
    strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);

    char res[10];
    sprintf(res, "T%d", ti);
    strcpy(tab_quad[qc].result, res);

        strcpy((yyval.expressionTYPE).val, result ? "true" : "false");


    ti++;
    qc++;
} else {
    yyerrorSemantic("Type expression incompatible");
}
  
                     }
#line 2098 "parser.tab.c"
    break;

  case 102: /* expression: expression LT expression  */
#line 845 "parser.y"
                               { 
          if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type) {
    int result = atof((yyvsp[-2].expressionTYPE).val) < atof((yyvsp[0].expressionTYPE).val);

    (yyval.expressionTYPE).type = T_BOOL;
    strcpy(tab_quad[qc].oprt, "BL");
    strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
    strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);

    char res[10];
    sprintf(res, "T%d", ti);
    strcpy(tab_quad[qc].result, res);

        strcpy((yyval.expressionTYPE).val, result ? "true" : "false");


    ti++;
    qc++;
} else {
    yyerrorSemantic("Type expression incompatible");
}
    }
#line 2125 "parser.tab.c"
    break;

  case 103: /* expression: expression GTE expression  */
#line 868 "parser.y"
                                { 
           if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type) {
    int result = atof((yyvsp[-2].expressionTYPE).val) >= atof((yyvsp[0].expressionTYPE).val);

    (yyval.expressionTYPE).type = T_BOOL;
    strcpy(tab_quad[qc].oprt, "BGE");
    strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
    strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);

    char res[10];
    sprintf(res, "T%d", ti);
    strcpy(tab_quad[qc].result, res);

        strcpy((yyval.expressionTYPE).val, result ? "true" : "false");


    ti++;
    qc++;
} else {
    yyerrorSemantic("Type expression incompatible");
}
    }
#line 2152 "parser.tab.c"
    break;

  case 104: /* expression: expression LTE expression  */
#line 890 "parser.y"
                                { 
            if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type) {
    int result = atof((yyvsp[-2].expressionTYPE).val) >= atof((yyvsp[0].expressionTYPE).val);

    (yyval.expressionTYPE).type = T_BOOL;
    strcpy(tab_quad[qc].oprt, "BGE");
    strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
    strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);

    char res[10];
    sprintf(res, "T%d", ti);
    strcpy(tab_quad[qc].result, res);

        strcpy((yyval.expressionTYPE).val, result ? "true" : "false");


    ti++;
    qc++;
} else {
    yyerrorSemantic("Type expression incompatible");
}
    }
#line 2179 "parser.tab.c"
    break;

  case 105: /* expression: expression GT expression  */
#line 912 "parser.y"
                               { 
           if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type) {
    int result = atof((yyvsp[-2].expressionTYPE).val) <= atof((yyvsp[0].expressionTYPE).val);

    (yyval.expressionTYPE).type = T_BOOL;
    strcpy(tab_quad[qc].oprt, "BLE");
    strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
    strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);

    char res[10];
    sprintf(res, "T%d", ti);
    strcpy(tab_quad[qc].result, res);

        strcpy((yyval.expressionTYPE).val, result ? "true" : "false");


    ti++;
    qc++;
} else {
    yyerrorSemantic("Type expression incompatible");
}
    }
#line 2206 "parser.tab.c"
    break;

  case 106: /* expression: expression PLUS expression  */
#line 934 "parser.y"
                                { 
    if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type && ((yyvsp[-2].expressionTYPE).type == T_INT || (yyvsp[-2].expressionTYPE).type == T_FLOAT)) {
        (yyval.expressionTYPE).type = (yyvsp[-2].expressionTYPE).type; 

        if ((yyvsp[-2].expressionTYPE).type == T_INT) {
            int val1 = atoi((yyvsp[-2].expressionTYPE).val); 
            int val2 = atoi((yyvsp[0].expressionTYPE).val); 
            int result = val1 + val2; 
            sprintf((yyval.expressionTYPE).val, "%d", result); 
        } else if ((yyvsp[-2].expressionTYPE).type == T_FLOAT) {
            float val1 = atof((yyvsp[-2].expressionTYPE).val); 
            float val2 = atof((yyvsp[0].expressionTYPE).val); 
            float result = val1 + val2;
            sprintf((yyval.expressionTYPE).val, "%f", result);
        }

        strcpy(tab_quad[qc].oprt, "+");
        strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
        strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);
        char res[10];
        sprintf(res, "T%d", ti);
        strcpy(tab_quad[qc].result, res);
        ti++; 
        qc++;  
    } else {
        yyerrorSemantic("Type expression incompatible");
    }   
}
#line 2239 "parser.tab.c"
    break;

  case 107: /* expression: expression MINUS expression  */
#line 963 "parser.y"
                                  { 
    if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type && ((yyvsp[-2].expressionTYPE).type == T_INT || (yyvsp[-2].expressionTYPE).type == T_FLOAT)) {
        (yyval.expressionTYPE).type = (yyvsp[-2].expressionTYPE).type;

        if ((yyvsp[-2].expressionTYPE).type == T_INT) {
            int val1 = atoi((yyvsp[-2].expressionTYPE).val); 
            int val2 = atoi((yyvsp[0].expressionTYPE).val); 
            int result = val1 - val2; 
            sprintf((yyval.expressionTYPE).val, "%d", result); 
        } else if ((yyvsp[-2].expressionTYPE).type == T_FLOAT) {
            float val1 = atof((yyvsp[-2].expressionTYPE).val); 
            float val2 = atof((yyvsp[0].expressionTYPE).val); 
            float result = val1 - val2; 
            sprintf((yyval.expressionTYPE).val, "%f", result); 
        }

        strcpy(tab_quad[qc].oprt, "-");
        strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
        strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);
        char res[10];
        sprintf(res, "T%d", ti);
        strcpy(tab_quad[qc].result, res);
        ti++;
        qc++;
    } else {
        yyerrorSemantic("Type expression incompatible");
    }   
}
#line 2272 "parser.tab.c"
    break;

  case 108: /* expression: expression MULTIPLY expression  */
#line 992 "parser.y"
                                      { 
             if((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type &&  ( (yyvsp[-2].expressionTYPE).type == T_INT  | (yyvsp[-2].expressionTYPE).type == T_FLOAT ))
                    {  (yyval.expressionTYPE).type = (yyvsp[-2].expressionTYPE).type ; 
                        strcpy(tab_quad[qc].oprt,"*");
                        strcpy(tab_quad[qc].op1,(yyvsp[-2].expressionTYPE).val);
                        strcpy(tab_quad[qc].op2,(yyvsp[0].expressionTYPE).val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
#line 2293 "parser.tab.c"
    break;

  case 109: /* expression: expression DIVIDE expression  */
#line 1008 "parser.y"
                                  {
    if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type && ((yyvsp[-2].expressionTYPE).type == T_INT || (yyvsp[-2].expressionTYPE).type == T_FLOAT)) {
        if (strcmp((yyvsp[0].expressionTYPE).val, "0") != 0 && strcmp((yyvsp[0].expressionTYPE).val, "0.0") != 0) {
            if ((yyvsp[-2].expressionTYPE).type == T_INT) {
                int val1 = atoi((yyvsp[-2].expressionTYPE).val); 
                int val2 = atoi((yyvsp[0].expressionTYPE).val); 

                if (val1 % val2 == 0) {
                    (yyval.expressionTYPE).type = T_INT;
                    int result = val1 / val2; 
                    sprintf((yyval.expressionTYPE).val, "%d", result); 
                } else {
                    (yyval.expressionTYPE).type = T_FLOAT;
                    float result = (float)val1 / val2; 
                    sprintf((yyval.expressionTYPE).val, "%f", result); 
                }
            } else if ((yyvsp[-2].expressionTYPE).type == T_FLOAT) {
                float val1 = atof((yyvsp[-2].expressionTYPE).val); 
                float val2 = atof((yyvsp[0].expressionTYPE).val); 

                (yyval.expressionTYPE).type = T_FLOAT;
                float result = val1 / val2; 
                sprintf((yyval.expressionTYPE).val, "%f", result);
            }

            strcpy(tab_quad[qc].oprt, "/");
            strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
            strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);
            char res[10];
            sprintf(res, "T%d", ti);
            strcpy(tab_quad[qc].result, res);
            strcpy((yyval.expressionTYPE).val, res);
            ti++;
            qc++;

        } else {
            yyerrorSemantic("Division by zero is not allowed!");
        }
    } else {
        yyerrorSemantic("Type expression incompatible");
    }
}
#line 2340 "parser.tab.c"
    break;

  case 110: /* expression: expression MODULO expression  */
#line 1051 "parser.y"
                                   {
    if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type && (yyvsp[-2].expressionTYPE).type == T_INT) {
        if (strcmp((yyvsp[0].expressionTYPE).val, "0") != 0) {
            int val1 = atoi((yyvsp[-2].expressionTYPE).val); 
            int val2 = atoi((yyvsp[0].expressionTYPE).val); 
            int result = val1 % val2;
            (yyval.expressionTYPE).type = T_INT;
            sprintf((yyval.expressionTYPE).val, "%d", result); 

            strcpy(tab_quad[qc].oprt, "%");
            strcpy(tab_quad[qc].op1, (yyvsp[-2].expressionTYPE).val);
            strcpy(tab_quad[qc].op2, (yyvsp[0].expressionTYPE).val);
            char res[10];
            sprintf(res, "T%d", ti);
            strcpy(tab_quad[qc].result, res);
            strcpy((yyval.expressionTYPE).val, res);
            ti++;
            qc++;

        } else {
            yyerrorSemantic("Division by zero is not allowed for modulo!");
        }
    } else if ((yyvsp[-2].expressionTYPE).type == (yyvsp[0].expressionTYPE).type && (yyvsp[-2].expressionTYPE).type == T_FLOAT) {
        yyerrorSemantic("Modulo operation is only applicable for integers!");
    } else {
        yyerrorSemantic("Type expression incompatible for modulo operation!");
    }
}
#line 2373 "parser.tab.c"
    break;

  case 111: /* expression: NOT expression  */
#line 1080 "parser.y"
                    {
    if ((yyvsp[0].expressionTYPE).type == T_BOOL) { 
        (yyval.expressionTYPE).type = T_BOOL;
strcpy((yyval.expressionTYPE).val, (strcmp((yyvsp[0].expressionTYPE).val, "true") == 0) ? "false" : "true");

        strcpy(tab_quad[qc].oprt, "NOT");
        strcpy(tab_quad[qc].op1, (yyvsp[0].expressionTYPE).val);
        strcpy(tab_quad[qc].op2, "");
        char res[10];
        sprintf(res, "T%d", ti);
        strcpy(tab_quad[qc].result, res);
        strcpy((yyval.expressionTYPE).val, res);
        ti++;
        qc++;
    } else {
        yyerrorSemantic("NOT operation can only be applied to boolean expressions!");
    }
}
#line 2396 "parser.tab.c"
    break;

  case 112: /* expression: LPAREN expression RPAREN  */
#line 1098 "parser.y"
                           {
    (yyval.expressionTYPE) = (yyvsp[-1].expressionTYPE);
}
#line 2404 "parser.tab.c"
    break;

  case 113: /* expression: IDENTIFIER  */
#line 1102 "parser.y"
    {
    desc_identif* symbol = lookupSymbol((yyvsp[0].strval));
       if (symbol->isInitialized){
         (yyval.expressionTYPE).type = symbol->type; 
        strcpy((yyval.expressionTYPE).val,symbol->valeur) ;
       }
     (yyval.expressionTYPE).type = symbol->type; 

    }
#line 2418 "parser.tab.c"
    break;

  case 115: /* value: INT_LITERAL  */
#line 1118 "parser.y"
                { 
     (yyval.expressionTYPE).type = T_INT ; 
    char buffer[20]; 
    sprintf(buffer, "%d", (yyvsp[0].intval)); 
    strcpy((yyval.expressionTYPE).val,strdup(buffer)); 
     }
#line 2429 "parser.tab.c"
    break;

  case 116: /* value: FLOAT_LITERAL  */
#line 1124 "parser.y"
                  { 
    (yyval.expressionTYPE).type = T_FLOAT ; 
    char buffer[20]; 
    sprintf(buffer, "%f", (yyvsp[0].floatval)); 
    strcpy((yyval.expressionTYPE).val,strdup(buffer));  
}
#line 2440 "parser.tab.c"
    break;

  case 117: /* value: STRING_LITERAL  */
#line 1130 "parser.y"
                   {  (yyval.expressionTYPE).type =  T_STRING ;   
                      char buffer[20] ;
                     sprintf(buffer, "%s", (yyvsp[0].strval));
                     strcpy((yyval.expressionTYPE).val,strdup(buffer));  }
#line 2449 "parser.tab.c"
    break;

  case 118: /* value: TRUE_LITERAL  */
#line 1136 "parser.y"
                            {  (yyval.expressionTYPE).type = T_BOOL;  strcpy((yyval.expressionTYPE).val,strdup("true"));  }
#line 2455 "parser.tab.c"
    break;

  case 119: /* value: FALSE_LITERAL  */
#line 1137 "parser.y"
                            {  (yyval.expressionTYPE).type =  T_BOOL; strcpy((yyval.expressionTYPE).val,strdup("false"));  }
#line 2461 "parser.tab.c"
    break;

  case 120: /* entree_sortie: TOKEN_RECEIVE LPAREN STRING_LITERAL COMMA IDENTIFIER RPAREN SEMICOLON  */
#line 1144 "parser.y"
                                                                          {
        char* string_literal = (yyvsp[-4].strval);
        char* identifier = (yyvsp[-2].strval);

        char typeSpecifier = '\0';

        for (int i = 0; i < strlen(string_literal); i++) {
            if (string_literal[i] == '%') {
                typeSpecifier = string_literal[i + 1];
                break;
            }
        }

        int varType = -1;
        char* value;
        desc_identif* symbol = lookupSymbol(identifier);
        if (symbol != NULL) {
            if (!symbol->isInitialized) {
                yyerrorSemantic("La variable n'a pas été initialisée");
            } else {
                varType = symbol->type;
                
            }
        } else {
            yyerrorSemantic("Variable non déclarée");
        }

        if (typeSpecifier != '\0' && varType != -1) {
            bool typeMatch = false;
            switch (typeSpecifier) {
                case 'I': typeMatch = varType == T_INT; break;
                case 'F': typeMatch = varType == T_FLOAT; break;
                case 'S': typeMatch = varType == T_STRING; break;
                case 'B': typeMatch = varType == T_BOOL; break;
            }
            if (!typeMatch) {
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "Incompatibilité de type : Attendu %c", typeSpecifier);
                yyerrorSemantic(buffer);
            }
            
        } else {
            yyerrorSemantic("Spécificateur de type invalide");
        }
    }
#line 2511 "parser.tab.c"
    break;

  case 121: /* entree_sortie: TOKEN_EMIT LPAREN STRING_LITERAL COMMA IDENTIFIER RPAREN SEMICOLON  */
#line 1189 "parser.y"
                                                                         {
    char* string_literal = (yyvsp[-4].strval);
    char* identifier = (yyvsp[-2].strval);

    char typeSpecifier = '\0';

    for (int i = 0; i < strlen(string_literal); i++) {
        if (string_literal[i] == '%') {
            typeSpecifier = string_literal[i + 1]; 
            break;
        }
    }

    char* value;
    int varType = -1;
    desc_identif* symbol = lookupSymbol(identifier);
    if (symbol != NULL) {
        if (!symbol->isInitialized) {
            yyerrorSemantic("La variable n'a pas été initialisée");
        } else {
            varType = symbol->type;
            value = symbol->valeur;
        }
    } else {
        yyerrorSemantic("Variable non déclarée");
    }

    if (typeSpecifier != '\0' && varType != -1) {
        bool typeMatch = false;
        switch (typeSpecifier) {
            case 'I': typeMatch = varType == T_INT; break;
            case 'F': typeMatch = varType == T_FLOAT; break;
            case 'S': typeMatch = varType == T_STRING; break;
            case 'B': typeMatch = varType == T_BOOL; break;
        }

        if (!typeMatch) {
            char buffer[100];
            snprintf(buffer, sizeof(buffer), "Incompatibilité de type : Attendu %c", typeSpecifier);
            yyerrorSemantic(buffer);
        } else {
            if (string_literal[0] == '"' && string_literal[strlen(string_literal) - 1] == '"') {
                string_literal[strlen(string_literal) - 1] = '\0'; 
                string_literal++;  
            }

            char result[1024] = {0}; 
            char* pos = strstr(string_literal, "%"); 

            if (pos != NULL) {
                strncpy(result, string_literal, pos - string_literal);
                strcat(result, value);

                strcat(result, pos + 2); 
            } else {
                strcpy(result, string_literal); 
            }

           
            printf("\n%s\n", result);
        }
    } else {
        yyerrorSemantic("Spécificateur de type invalide");
    }
}
#line 2581 "parser.tab.c"
    break;


#line 2585 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1258 "parser.y"


void yysuccess(char *s) {
    currentColumn += yyleng;
}

void yyerror(const char *s) {
    if (yytext && strlen(yytext) > 0) {
        fprintf(stdout, "Erreur syntaxique dans le fichier '%s', ligne %d, colonne %d : %s. Token problématique : '%s'.\n", 
                file, yylineno, currentColumn, s, yytext);
    } else {
        fprintf(stdout, "Erreur syntaxique dans le fichier '%s', ligne %d, colonne %d : %s.\n", 
                file, yylineno, currentColumn, s);
    }
    currentColumn += yyleng;
}

void yyerrorSemantic(const char *s) {
        fprintf(stdout, "Erreur semantique dans le fichier '%s', ligne %d, colonne %d : %s.\n", 
        file, yylineno, currentColumn, s);

    currentColumn += yyleng;
}

int main(void) {
    yyin = fopen(file, "r");
    if (yyin == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }
    initPile(&stack); 
    yyparse();
    displayTable();  
    for (int i = 1; i < qc; i++) {
    printf("[%d] - ( %s , %s , %s , %s )\n",  i, tab_quad[i].oprt, tab_quad[i].op1, tab_quad[i].op2, tab_quad[i].result);
   }
    return 0;
}
