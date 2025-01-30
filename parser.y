%{

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
%}   

%union {
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
}

%type <oprt> PLUS MINUS MULTIPLY MODULO DIVIDE POW ADDEQUALS SUBEQUALS MULEQUALS DIVEQUALS MODEQUALS LT LTE GT GTE EQ NEQ AND OR NOT
%token AND
%token OR
%token TOKEN_IMPORT
%token TOKEN_FUNC
%token TOKEN_PROC
%token TOKEN_CONST
%token INT_LITERAL
%token STRING_LITERAL
%token FLOAT_LITERAL
%token TRUE_LITERAL
%token FALSE_LITERAL
%token TOKEN_LIST
%token TOKEN_ARRAY
%token TOKEN_LIFO
%token TOKEN_FIFO
%token TOKEN_OF
%token TOKEN_STRUCT
%token TOKEN_IF
%token TOKEN_ELSE
%token TOKEN_REPEAT
%token TOKEN_LOOP
%token TOKEN_RETURN
%token IDENTIFIER
%token TOKEN_INT
%token TOKEN_STRING
%token TOKEN_BOOL
%token TOKEN_FLOAT
%token SEMICOLON
%token COLON
%token DOT
%token COMMA
%token LPAREN
%token RPAREN
%token LBRACE
%token RBRACE
%token TOKEN_LBRACK
%token TOKEN_RBRACK
%token INC
%token DEC
%token NEQ
%token EQ
%token NOT
%token CONTINUE
%token BREAK
%token TOKEN_EMIT
%token TOKEN_RECEIVE
%token INC_TOKEN
%token DEC_TOKEN
%token TOKEN_BEGIN
%token TOKEN_END
%token ADDEQUALS
%token SUBEQUALS
%token MULEQUALS
%token DIVEQUALS
%token MODEQUALS
%token ASSIGN

%type <intval> INT_LITERAL
%type <floatval> FLOAT_LITERAL
%type <strval> STRING_LITERAL IDENTIFIER StructureBody StructureAttribute  StructureType DeclarationSimple
%type <type> SimpleType
%type <expressionTYPE> array_assignment expression dimension_term Dimensions  value    object_member_access

%right ASSIGN              
%right POW                 

%left PLUS MINUS           
%left MULTIPLY DIVIDE MODULO 

%nonassoc LT GT LTE GTE NEQ EQ  
%left AND OR                
%right NOT                  

%nonassoc CONTINUE BREAK    

// non utilise %right INC DEC             

%left DOT TOKEN_LBRACK TOKEN_RBRACK 
%left LPAREN RPAREN         

%nonassoc TOKEN_IF TOKEN_ELSE 
%left TOKEN_FUNC TOKEN_PROC  



%start program


%{
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
%}

%%

program: 
| importations TOKEN_BEGIN bloc TOKEN_END
    | importations DeclarationVariables TOKEN_BEGIN bloc TOKEN_END
    | importations DeclarationVariables DeclarationFonctions TOKEN_BEGIN bloc TOKEN_END 
    | DeclarationVariables TOKEN_BEGIN bloc TOKEN_END
    | DeclarationFonctions TOKEN_BEGIN bloc TOKEN_END 
    | DeclarationVariables DeclarationFonctions TOKEN_BEGIN bloc TOKEN_END
    |importations DeclarationFonctions TOKEN_BEGIN bloc TOKEN_END
    | TOKEN_BEGIN bloc TOKEN_END

    ;

DeclarationFonctions:
    DeclarationFonction
    | DeclarationFonctions DeclarationFonction
    ;

DeclarationFonction:
      TOKEN_FUNC IDENTIFIER LPAREN Parametres RPAREN ReturnType LBRACE bloc ReturnOpt RBRACE
    | TOKEN_PROC IDENTIFIER LPAREN Parametres RPAREN LBRACE bloc RBRACE
    ;

DeclarationVariables:
    DeclarationVariable
    | DeclarationVariables DeclarationVariable
    
DeclarationVariable:
    DeclarationSimple
    | DeclarationStructuree
    | TOKEN_CONST IDENTIFIER ASSIGN expression SEMICOLON {
    desc_identif *existingEntry = lookupSymbol($2); // $2 corresponds to IDENTIFIER
    if (existingEntry != NULL) {
        yyerrorSemantic("La variable est déjà déclarée");
    } else {
        int result = insertSymbol(
            $2,               
            C_CONST,        
            $4.type,         
            yylineno,       
            $4.val,         
            false,           
            0,              
            true,            
            true ,
            NULL  
        );

        if (result == -1) {
            printf("Erreur : Échec de l'insertion du constant '%s'.\n", $2);
        }
    }
    }
    ;

Parametres:
    ParametreFUNC
    | ParametreFUNC COMMA Parametres

    ;

ParametreFUNC:
    Type IDENTIFIER
    ;

    

DeclarationStructuree:
    ArrayDeclaration
    |
    CollectionDeclaration
    |
    StructureDeclaration
    ;

DeclarationSimple:
    SimpleType IDENTIFIER 
    SEMICOLON
     {
        desc_identif* symbol = lookupSymbol($<strval>2);
        if (symbol != NULL) {
               yyerrorSemantic("La variable est déjà déclarée");
        }
        else{
            insertSymbol($2, C_VAR, $1, yylineno,"",false, 0, false, false,NULL );
        }
    }
    | StructureType IDENTIFIER SEMICOLON  {
        desc_identif* symbol = lookupSymbol($<strval>2);
        if (symbol != NULL) {
             yyerrorSemantic("La variable est déjà déclarée");
        } else {
            int result = insertSymbol(
                $<strval>2,    // Nom de la variable
                C_VAR,         // Classe : Variable
                7,            // Type de la variable (structure)
                yylineno,      // Ligne de déclaration
                "",            // Pas de valeur initiale
                false,         // Pas un tableau
                0,             // Taille du tableau (non applicable)
                false,         // Pas initialisé
                false,         // Pas une constante
                $1           //  structure parente
            );

            if (result == -1) {
                printf("Erreur : Échec de l'insertion de la variable '%s' dans la table des symboles.\n", $<strval>2);
            }
        }
    }
    
    ;


StructureType:
    IDENTIFIER
    {
        // Vérifier que la structure existe
        desc_identif* entry = lookupSymbol($1);
        if (entry == NULL || entry->type != T_OBJECT) {
            yyerrorSemantic("La variable est déjà déclarée");
        } else {
             // Retourner le type de la structure
            $$=$1;
        }
    }
    ;
ReturnOpt:
    TOKEN_RETURN expression SEMICOLON

ReturnType:
    COLON Type;

SimpleType: 
      TOKEN_INT  { $$ = T_INT; }
    | TOKEN_FLOAT   { $$ = T_FLOAT; }
    | TOKEN_STRING { $$ = T_STRING; }
    | TOKEN_BOOL   { $$ = T_BOOL; }
    ;


StructuredType:
    TOKEN_ARRAY 
    | TOKEN_FIFO
    | TOKEN_LIFO 
    | TOKEN_LIST 
    | TOKEN_STRUCT 

Type:
    SimpleType
    | StructuredType
    ;



AppelFonction:
//IDENTIFIER LPAREN Parametres RPAREN SEMICOLON
IDENTIFIER LPAREN ExpressionList RPAREN SEMICOLON ;

CollectionDeclaration:
    CollectionType IDENTIFIER SEMICOLON
    | CollectionType IDENTIFIER ASSIGN CollectionInitialization SEMICOLON
    ;

CollectionType:
    TOKEN_LIST TOKEN_OF SimpleType
    | TOKEN_FIFO TOKEN_OF SimpleType
    | TOKEN_LIFO TOKEN_OF SimpleType
    ;



CollectionInitialization:
    LBRACE ExpressionList RBRACE
    ;

ExpressionList:
    expression 
    | expression COMMA ExpressionList
    ;

ArrayDeclaration:
    TOKEN_ARRAY TOKEN_OF SimpleType IDENTIFIER Dimensions SEMICOLON
    {
        desc_identif* entry = lookupSymbol($<strval>4);
        if (entry != NULL) {
            yyerrorSemantic("La variable est déjà déclarée");
        } else {
            int result = insertSymbol(
                $<strval>4,    // Identifier name
                C_VAR,         // Class: Variable
                $3,       // Type: Comes from SimpleType
                yylineno,      // Line number
                "",            // No initial value
                true,          // isArray = true
                atoi($5.val),            // Array size (calculated in Dimensions)
                false,         // isInitialized = false
                false,
                NULL          // isConstant = false
            );

            if (result == -1) {
                printf("Erreur : Échec de l'insertion de l'array '%s' dans la table des symboles.\n", $<strval>4);
            }
        }
    }
;
Dimensions:
    TOKEN_LBRACK dimension_term TOKEN_RBRACK
    {
        if (atoi( $2.val) < 1) {
            yyerrorSemantic("La taille du tableau doit être un entier positif");
            exit(1);
        }
        $$ = $2;  
    }
;

dimension_term:
    IDENTIFIER
    {
        desc_identif *entry = lookupSymbol($1);
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
        strcpy($$.val,entry->valeur );
        $$.type = T_INT;              
    }
|INT_LITERAL
{
  char buffer[20]; 
    sprintf(buffer, "%d", $1);
    strcpy($$.val, buffer);  
    $$.type = T_INT;   
}
| FLOAT_LITERAL
    {
        yyerrorSemantic("Les dimensions des tableaux ne peuvent pas être de type float");
        exit(1);
    }
| STRING_LITERAL
    {
        printf("Les dimensions des tableaux ne peuvent pas être de type string");
        exit(1);
    }
| TRUE_LITERAL
    {
        printf("Les dimensions des tableaux ne peuvent pas être de type bool");
        exit(1);
    }
| FALSE_LITERAL
    {
        printf("Les dimensions des tableaux ne peuvent pas être de type bool");
        exit(1);
    }
;


StructureDeclaration:
    TOKEN_STRUCT IDENTIFIER {
        structureAttributeStartIndex = symbolTable.sommet;
        strcpy(currentStructureName, $2); 
    } LBRACE StructureBody RBRACE SEMICOLON
    {
        int result = insertSymbol(
            $2,           
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
            printf("Erreur : Échec de l'insertion de la structure '%s' dans la table des symboles.\n", $2);
        }
        int endIndex = symbolTable.sommet;
        for (int i = structureAttributeStartIndex; i < endIndex; i++) {
            if (symbolTable.tab[i].classe == C_CHAMP) {
                if (symbolTable.tab[i].parentStructure != NULL) {
                    free(symbolTable.tab[i].parentStructure);
                }
                symbolTable.tab[i].parentStructure = strdup($2);
            }
        }
    };

StructureBody:
    StructureAttribute SEMICOLON StructureBody { $$=$1;}
    |StructureAttribute SEMICOLON { $$=$1;}
    ;

StructureAttribute:
    SimpleType IDENTIFIER
    {
        desc_identif* entry = lookupSymbol($2);
        if (entry != NULL) {
            yyerrorSemantic("Erreur : Attribut déjà déclaré dans la structure");
        } else {
             
            int result = insertSymbol(
                $2,           // Nom de l'attribut
                C_CHAMP,      // Classe : Champ de structure
                $1,           // Type de l'attribut
                yylineno,     // Ligne de déclaration
                "",           // Pas de valeur initiale
                false,        // Pas un tableau
                0,            // Taille du tableau (non applicable)
                true,        // Pas initialisé
                false,        // Pas une constante
                currentStructureName  // Nom de la structure parente
            );

            if (result == -1) {
                printf("Erreur : Échec de l'insertion de l'attribut '%s' dans la table des symboles.\n", $2);
            }
            
        }
       
        $$=$2;
    }
    ;








importations: 
importation 
    | importations importation

importation: TOKEN_IMPORT IDENTIFIER SEMICOLON

bloc:
 | instructions
    ;

instructions:
      instruction
    | instructions instruction
    ;

instruction:
      affectation          
    | control  
    | boucle 
    | entree_sortie 
    |AppelFonction  
    |INCDEC SEMICOLON
    |CollectionDeclaration
    |DeclarationSimple
    
    ;

control:
    IF ELSE
    | IF
    ;

IF: 
TOKEN_IF LPAREN expression RPAREN LBRACE bloc RBRACE ELSE 
;

ELSE: TOKEN_ELSE  LBRACE bloc RBRACE 


boucle:
    REPEAT_boucle
    | LOOP_boucle
    ;



REPEAT_boucle:
   REPEAT_START INSTRUCTIONS_START instructions RBRACE {
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
    };

REPEAT_START: TOKEN_REPEAT LPAREN { 
    empiler(&stack,qc); 
    qc++;
  };

INSTRUCTIONS_START: 
    expression RPAREN LBRACE  { 
    if($1.type == T_BOOL){
        char r[20]; 
        sprintf(r,$1.val,qc-1);	
          strcpy(tab_quad[qc].oprt,"BZ");
            strcpy(tab_quad[qc].op1,"tmp");
            strcpy(tab_quad[qc].op2,"");
            strcpy(tab_quad[qc].result,r);
        empiler(&stack,qc); 
        qc++; 
    }else{
        printf("Semantic error : cannot evaluate non boolean expression as condition");
    }
} ;





LOOP_boucle:
    TOKEN_LOOP LPAREN LOOP_INIT SEMICOLON expression SEMICOLON INCDEC RPAREN LBRACE bloc RBRACE
    ;

LOOP_INIT:
    IDENTIFIER ASSIGN expression
    |SimpleType  IDENTIFIER ASSIGN expression 
    ;

INCDEC:
    IDENTIFIER INC_TOKEN   
    | IDENTIFIER DEC_TOKEN
    ;



affectation:
    IDENTIFIER ASSIGN expression SEMICOLON {     

        desc_identif* symbol = lookupSymbol($1);
        if (symbol == NULL) {
            yyerrorSemantic("Variable non declaree");
            exit(1);
        }
        if (symbol->type == T_FLOAT && $3.type == T_INT) {
            $3.type = T_FLOAT;  
        } else if (symbol->type == T_INT && $3.type == T_FLOAT) {
            symbol->type = T_FLOAT;  
        } else if (symbol->type != $3.type) {
            yyerrorSemantic("Type mismatch in assignment");
        } else {
        
            strcpy(tab_quad[qc].oprt, "=");
            strcpy(tab_quad[qc].op1, $3.val);
            strcpy(tab_quad[qc].op2, "");
            strcpy(tab_quad[qc].result, $1);
            qc++;
            ti++;
            desc_identif* symbol = lookupSymbol($1);
            if (symbol != NULL) {
            symbol->isInitialized = true;
            strcpy( symbol->valeur , $3.val);
         }       
       }
    }
    |
     array_assignment ASSIGN expression SEMICOLON {        
        if ($1.type == T_FLOAT && $3.type == T_INT) {
            $3.type = T_FLOAT;  
        } else if ($1.type == T_INT && $3.type == T_FLOAT) {
            $1.type = T_FLOAT;  
        } else if ($1.type != $3.type) {
            yyerrorSemantic("Type mismatch in assignment");
        } else {
            if ($1.isArrayElement == 1){
                char arrayAccess[20];
                char tempVar[10];
                sprintf(arrayAccess, "%s[%d]", $1.arrayName, $1.index);
                setArrayElement($1.arrayName, $1.index, $3.val);
                    strcpy(tab_quad[qc].oprt, "=");
                    strcpy(tab_quad[qc].op1, $3.val);
                    strcpy(tab_quad[qc].op2, "");
                    strcpy(tab_quad[qc].result, arrayAccess);
                    qc++;
                    ti++;
            }
            else {

            strcpy(tab_quad[qc].oprt, "=");
            strcpy(tab_quad[qc].op1, $1.val);
            strcpy(tab_quad[qc].op2, $3.val);

            char tempVar[10];
            sprintf(tempVar, "T%d", ti);
            strcpy(tab_quad[qc].result, tempVar);
            qc++;
            ti++;
            desc_identif* symbol = lookupSymbol($1.val);
            if (symbol != NULL) {
                symbol->isInitialized = true;
                strcpy( symbol->valeur , $3.val);
            }
        

         }       
       }
    }
    ;
|object_member_access ASSIGN expression SEMICOLON
;
object_member_access:
    IDENTIFIER DOT IDENTIFIER
    {
        // Vérifier que le premier identifiant est une structure
        desc_identif* structure = lookupSymbol($1);
        if (structure == NULL || structure->type != T_OBJECT) {
            yyerrorSemantic("L'identifiant n'est pas une structure.");
        } else {
            // Vérifier que le deuxième identifiant est un attribut de la structure
            desc_identif* attribut = lookupSymbolInStructure($1, $3);
           // printf("attribut est %s",attribut);
            if (attribut == NULL) {
                yyerrorSemantic("L'attribut  n'existe pas dans la structure.");
            } else {
                // Retourner le type et la valeur de l'attribut
                $$.type = attribut->type;                // Type de l'attribut
              snprintf($$.val, sizeof($$.val), "%s.%s", $1, $3);  // Valeur de l'attribut
               int result = insertSymbol(
               $$.val,           // Nom de l'attribut
                C_CHAMP,      // Classe : Champ de structure
                $$.type,           // Type de l'attribut
                yylineno,     // Ligne de déclaration
                "",           // Pas de valeur initiale
                false,        // Pas un tableau
                0,            // Taille du tableau (non applicable)
                true,        // Pas initialisé
                false,        // Pas une constante
                attribut->parentStructure  // Nom de la structure parente
            );

                  strcpy($$.tempVar, "");                  // Variable temporaire (non utilisée ici)
            }
        }
    }
;

array_assignment:
    IDENTIFIER TOKEN_LBRACK expression TOKEN_RBRACK 
    {
        desc_identif* symbol = lookupSymbol($<strval>1);  
        if (symbol == NULL) {
            yyerrorSemantic("Tableau non declare");
            exit(1);
        } else {
            if (!symbol->isArray) {
                yyerrorSemantic("La variable est referencee comme tableau mais elle est d'un type different");
                exit(1);
            } else {
                // Check index bounds
                if (atoi($3.val) > symbol->ArraySize) {
                    yyerrorSemantic("Indice hors des limites du tableau");
                    exit(1);
                }
                else{
                    // insert value in the corresponding index
                    int index = atoi($3.val);
                    $$.index = index;
                    $$.isArrayElement = 1;
                    $$.arrayName = $1;
                    $$.type = symbol->type;
                }

            }
        }
    }
;

 expression:
    expression OR expression   { 
             if($1.type == T_BOOL &&  $3.type == T_BOOL  )
                    {  $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"|");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression AND expression   { 
         printf("\n 1 -> %d  2 -> %d \n",$1.type ,$3.type );
             if($1.type == T_BOOL &&  $3.type == T_BOOL  )
                    {  $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"&");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression EQ expression { 
          printf("\n %d  ==  %d",$1.type,$3.type);
          printf("\n %d",T_INT);
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BNE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                         char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                           }   
                     }
    | expression NEQ expression  { 
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression LT expression { 
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BGE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression GT expression { 
             if($1.type == $3.type  )
                    {  $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BLE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression LTE expression { 
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BG");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression GTE expression { 
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BL");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression PLUS expression  { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {  $$.type = $1.type ; 
                        strcpy(tab_quad[qc].oprt,"+");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression MINUS expression   { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {  $$.type = $1.type ; 
                        strcpy(tab_quad[qc].oprt,"-");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression MULTIPLY expression  { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {  $$.type = $1.type ; 
                        strcpy(tab_quad[qc].oprt,"*");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorSemantic("Type expression incompatible");
                                   }   
                     }
    | expression DIVIDE expression  { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {   if( strcmp($3.val,"0") != 0   ){
                        if( atoi($1.val) % atoi($3.val) == 0){
                           $$.type = T_INT ; 
                        } else {
                            $$.type = T_FLOAT; 
                        }
                        strcpy(tab_quad[qc].oprt,"/");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                    yyerrorSemantic("Division par 0 impossible !");  
                                   }  
                    }else{
                         yyerrorSemantic("Type expression incompatible");
                    } 
                    }
    | expression MODULO expression   { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {   if( strcmp($3.val,"0") != 0   ){
                           $$.type = T_INT ; 
                        strcpy(tab_quad[qc].oprt,"%");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {                        
                             yyerrorSemantic("Division par 0 impossible !");
                                   }  
                    }else{
                          yyerrorSemantic("Type expression incompatible");
                    } 
                    }
| LPAREN expression RPAREN {
    $$ = $2;
}
| IDENTIFIER
    {
    desc_identif* symbol = lookupSymbol($<strval>1);
       if (symbol->isInitialized){
         $$.type = symbol->type; 
        strcpy($$.val,symbol->valeur) ;
       }
     $$.type = symbol->type; 

    }
    | value
;




value:
    INT_LITERAL { 
     $$.type = T_INT ; 
    char buffer[20]; 
    sprintf(buffer, "%d", $1); 
    strcpy($$.val,strdup(buffer)); 
     }   
  | FLOAT_LITERAL { 
    $$.type = T_FLOAT ; 
    char buffer[20]; 
    sprintf(buffer, "%f", $1); 
    strcpy($$.val,strdup(buffer));  
}
  | STRING_LITERAL {  $$.type =  T_STRING ;   
                      char buffer[20] ;
                     sprintf(buffer, "%s", $1);
                     strcpy($$.val,strdup(buffer));  }
 
 
  | TRUE_LITERAL            {  $$.type = T_BOOL;  strcpy($$.val,strdup("true"));  }
  | FALSE_LITERAL           {  $$.type =  T_BOOL; strcpy($$.val,strdup("false"));  }
;




entree_sortie:
    TOKEN_RECEIVE LPAREN STRING_LITERAL COMMA IDENTIFIER RPAREN SEMICOLON {
        char* string_literal = $3;
        char* identifier = $5;

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
    | TOKEN_EMIT LPAREN STRING_LITERAL COMMA IDENTIFIER RPAREN SEMICOLON {
    char* string_literal = $3;
    char* identifier = $5;

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
;



%%

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
