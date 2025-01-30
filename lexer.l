%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"


extern void yysuccess(char *s);
extern void yyerror(const char *s);
void LexicalError();
extern int currentColumn;

%}
%option yylineno 
%option noyywrap 
LINEBREAK "\n"|"\r"

%%

"if"          { return TOKEN_IF; }
"else"        { return TOKEN_ELSE; }
"loop"        { return TOKEN_LOOP; }
"repeat"      { return TOKEN_REPEAT; }
"BEGIN"       { return TOKEN_BEGIN; }
"END"         { return TOKEN_END; }
"FUNC"        { return TOKEN_FUNC; }
"PROC"        { return TOKEN_PROC; }
"IMPORT"      { return TOKEN_IMPORT;}
"return"      { return TOKEN_RETURN; }
"receive"     { return TOKEN_RECEIVE; }
"emit"        { return TOKEN_EMIT; }
"false" { return FALSE_LITERAL;}
"true"  { return TRUE_LITERAL;}


"//".*                  { /* Ignorer les commentaires sur une seule ligne */ }
"/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/" { /* Ignorer les commentaires multi-lignes */ }
"/*".* { printf("ERREUR LEXICALE: Commentaire multi-ligne non fermé\n");exit(EXIT_FAILURE); }


"{"       { return LBRACE; }
"}"       { return RBRACE; }

"="     { yylval.oprt = strdup(yytext); return ASSIGN; }
"++"          { return INC_TOKEN ; }
"--"          { return DEC_TOKEN ; }
"+"     { yylval.oprt = strdup(yytext); return PLUS; }
"-"     { yylval.oprt = strdup(yytext); return MINUS; }
"*"     { yylval.oprt = strdup(yytext); return MULTIPLY; }
"/"     { yylval.oprt = strdup(yytext); return DIVIDE; }
"|"     { yylval.oprt = strdup(yytext); return OR; }
"&"     { yylval.oprt = strdup(yytext); return AND; }
"."          {return DOT;}

[+-]?[0-9]+  { yylval.intval = atoi(yytext); return INT_LITERAL; }

[+-]?[0-9]*\.[0-9]+([eE][+-]?[0-9]+)?|[0-9]+([eE][+-]?[0-9]+)? {yylval.floatval = atof(yytext); return FLOAT_LITERAL; }




"CONST"       { return TOKEN_CONST; }
"INT"         { return TOKEN_INT; }
"FLOAT"       { return TOKEN_FLOAT; }
"STRING"      { return TOKEN_STRING; }
"BOOL"        { return TOKEN_BOOL; }

"ARRAY"       { return TOKEN_ARRAY; }
"LIST"        { return TOKEN_LIST; }
"FIFO"        { return TOKEN_FIFO; }
"LIFO"        { return TOKEN_LIFO; }
"STRUCT"      { return TOKEN_STRUCT; }

"OF"          { return TOKEN_OF; }
"["               { return TOKEN_LBRACK; }
"]"               { return TOKEN_RBRACK; }


\"([^\"\\]|\\["nrt\\])*\" {
     yylval.strval = strdup(yytext);
    return STRING_LITERAL;
}

\"([^\"\\]|\\.)* { printf("ERREUR LEXICALE: Chaîne de caractères mal fermée :'%s' à la ligne %d.\n", yytext, yylineno);exit(EXIT_FAILURE); }
[a-zA-Z_][a-zA-Z0-9_]{33,} { printf("ERREUR LEXICALE: Identifiant trop long (%s)\n", yytext); exit(EXIT_FAILURE);}
[a-zA-Z_][a-zA-Z0-9_]*  { 
    yylval.strval = strdup(yytext);
    return IDENTIFIER; 
}
\\(n|t|b|r|\\|0|\") { /* Séquence d'échappement valide : rien à faire */ }
\\[^ntrb0"\\]       { printf("ERREUR LEXICALE: Séquence d'échappement invalide : %s\n", yytext);exit(EXIT_FAILURE); }

{LINEBREAK} {
    currentColumn =1;
}

[ \t]+ {
    currentColumn+=yyleng;
}


"/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*$ {
    fprintf(stderr, "ERREUR LEXICALE : Commentaire non terminé à la ligne %d.\n", yylineno);
    exit(EXIT_FAILURE);
}

\"[^\"]*$ {
    fprintf(stderr, "ERREUR LEXICALE : Chaîne de caractères non terminée à la ligne %d.\n", yylineno);
    exit(EXIT_FAILURE);
}

[0-9]+[a-zA-Z_]+ {
    fprintf(stderr, "ERREUR LEXICALE : Identifiant commençant par un chiffre '%s' à la ligne %d.\n", yytext, yylineno);
    exit(EXIT_FAILURE);
}

[0-9]*\.[0-9]*\.[0-9]* {
    fprintf(stderr, "ERREUR LEXICALE : Nombre flottant mal formé '%s' à la ligne %d.\n", yytext, yylineno);
    exit(EXIT_FAILURE);
}


"=="      { return EQ; }

"!="      { return NEQ; }
"<="      { return LTE; }
">="      { return GTE; }
";"       { return SEMICOLON; }
","       { return COMMA; }
"("       { return LPAREN; }
")"       { return RPAREN; }
">"       { return GT; }
"<"       { return LT; }
":" {return COLON ;}
"+=" { return ADDEQUALS ;}
"*=" {return MULEQUALS ;}
"-=" { return SUBEQUALS ;}
"/=" {return DIVEQUALS ;}
"%=" {return MODEQUALS ;}
. { 
     yyerror("Unexpected token");
    LexicalError();
    yyterminate();
}

%%

void LexicalError() {

    char line[256], introError[80]; 

    fseek(yyin, 0, SEEK_SET);
    
    int i = 0; 

    while (fgets(line, sizeof(line), yyin)) { 
        i++; 
        if(i == yylineno) break;  
    } 
        
    sprintf(introError, "Lexical error in Line %d : Unrecognized character : ", yylineno);
    printf("%s%s", introError, line);  
    int j=1;
    while(j<currentColumn+strlen(introError)) { printf(" "); j++; }
    printf("^\n");
    exit(EXIT_FAILURE);

}