/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MULTIPLY = 260,                /* MULTIPLY  */
    MODULO = 261,                  /* MODULO  */
    DIVIDE = 262,                  /* DIVIDE  */
    POW = 263,                     /* POW  */
    LT = 264,                      /* LT  */
    LTE = 265,                     /* LTE  */
    GT = 266,                      /* GT  */
    GTE = 267,                     /* GTE  */
    AND = 268,                     /* AND  */
    OR = 269,                      /* OR  */
    TOKEN_IMPORT = 270,            /* TOKEN_IMPORT  */
    TOKEN_FUNC = 271,              /* TOKEN_FUNC  */
    TOKEN_PROC = 272,              /* TOKEN_PROC  */
    TOKEN_CONST = 273,             /* TOKEN_CONST  */
    INT_LITERAL = 274,             /* INT_LITERAL  */
    STRING_LITERAL = 275,          /* STRING_LITERAL  */
    FLOAT_LITERAL = 276,           /* FLOAT_LITERAL  */
    TRUE_LITERAL = 277,            /* TRUE_LITERAL  */
    FALSE_LITERAL = 278,           /* FALSE_LITERAL  */
    TOKEN_LIST = 279,              /* TOKEN_LIST  */
    TOKEN_ARRAY = 280,             /* TOKEN_ARRAY  */
    TOKEN_LIFO = 281,              /* TOKEN_LIFO  */
    TOKEN_FIFO = 282,              /* TOKEN_FIFO  */
    TOKEN_OF = 283,                /* TOKEN_OF  */
    TOKEN_STRUCT = 284,            /* TOKEN_STRUCT  */
    TOKEN_IF = 285,                /* TOKEN_IF  */
    TOKEN_ELSE = 286,              /* TOKEN_ELSE  */
    TOKEN_REPEAT = 287,            /* TOKEN_REPEAT  */
    TOKEN_LOOP = 288,              /* TOKEN_LOOP  */
    TOKEN_RETURN = 289,            /* TOKEN_RETURN  */
    IDENTIFIER = 290,              /* IDENTIFIER  */
    TOKEN_INT = 291,               /* TOKEN_INT  */
    TOKEN_STRING = 292,            /* TOKEN_STRING  */
    TOKEN_BOOL = 293,              /* TOKEN_BOOL  */
    TOKEN_FLOAT = 294,             /* TOKEN_FLOAT  */
    SEMICOLON = 295,               /* SEMICOLON  */
    COLON = 296,                   /* COLON  */
    DOT = 297,                     /* DOT  */
    COMMA = 298,                   /* COMMA  */
    LPAREN = 299,                  /* LPAREN  */
    RPAREN = 300,                  /* RPAREN  */
    LBRACE = 301,                  /* LBRACE  */
    RBRACE = 302,                  /* RBRACE  */
    TOKEN_LBRACK = 303,            /* TOKEN_LBRACK  */
    TOKEN_RBRACK = 304,            /* TOKEN_RBRACK  */
    INC = 305,                     /* INC  */
    DEC = 306,                     /* DEC  */
    NEQ = 307,                     /* NEQ  */
    EQ = 308,                      /* EQ  */
    NOT = 309,                     /* NOT  */
    CONTINUE = 310,                /* CONTINUE  */
    BREAK = 311,                   /* BREAK  */
    TOKEN_EMIT = 312,              /* TOKEN_EMIT  */
    TOKEN_RECEIVE = 313,           /* TOKEN_RECEIVE  */
    INC_TOKEN = 314,               /* INC_TOKEN  */
    DEC_TOKEN = 315,               /* DEC_TOKEN  */
    TOKEN_BEGIN = 316,             /* TOKEN_BEGIN  */
    TOKEN_END = 317,               /* TOKEN_END  */
    ADDEQUALS = 318,               /* ADDEQUALS  */
    SUBEQUALS = 319,               /* SUBEQUALS  */
    MULEQUALS = 320,               /* MULEQUALS  */
    DIVEQUALS = 321,               /* DIVEQUALS  */
    MODEQUALS = 322,               /* MODEQUALS  */
    ASSIGN = 323                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "parser.y"

    int intval;         // Pour INTEGER_LITERAL
    float floatval;     // Pour FLOAT_LITERAL
    char charval;       // Pour CHAR_LITERAL
    char* strval;       // Pour STRING_LITERAL et IDENTIFIER
    int type;           // Pour les types (INT, FLOAT, etc.) 
    char* oprt;        // For single-character operators like +, -, *, /
    struct expressionTYPE {
    int type ;
    char val[256];
    char tempVar[256];    
    int isArrayElement;
    char *arrayName;
    int index;
    } expressionTYPE;

#line 149 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
