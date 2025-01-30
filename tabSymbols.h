#ifndef TAB_SYMBOLS_H
#define TAB_SYMBOLS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Définitions des classes
#define T_UNKNOWN 0         // Inconnu
#define C_CONST 1       // Constante
#define C_VAR 2         // Variable
#define C_TYPE 3        // Type utilisateur (enum, object, ARRAY.)
#define C_LOCAL 4       // Variable locale
#define C_ARGUMENT 5    // Argument d'une fonction
#define C_CHAMP 6    // Argument d'une fonction
#define C_ARRAY 7      // Tableau
// Définitions des types
#define T_INT 1         // Type entier
#define T_FLOAT 2       // Type flottant
#define T_BOOL 3        // Type booléen
#define T_STRING 4      // Type chaîne de caractères
#define T_OBJECT 7      // Objet (structure utilisateur)
#define T_ENUM 8        // Enumération
#define T_FUNCTION 9    // Fonction

// Taille maximale de la table
#define MAX_DICO 1000

typedef struct {
    char *identif;      // Name of the identifier
    int line;           // Line number
    int classe;         // Class (local, argument, etc.)
    int type;           // Data type (int, float, etc.)
    char *valeur;       // Value for scalar variables
    bool isConstant;    // Indicates if it is a constant
    bool isArray;       // Indicates if it is an array
    bool isInitialized; // Indicates if initialized
    int ArraySize;      // Number of elements in the array
    char **arrayValues; // NEW: Values for array elements (pointer to an array of strings)
     char *parentStructure;
} desc_identif;

// Structure de la table des symboles
typedef struct {
    desc_identif tab[MAX_DICO]; // Tableau des identifiants
    int base;                   
    int sommet;                 // Indice du sommet de la pile
} table_symbol;

extern table_symbol symbolTable;

void initTable();

int insertSymbol(const char *name, int classe, int type, int line, const char *valeur,  bool isArray, int arraySize, bool isInitialized,bool isConstant,const char *parentStructure);

desc_identif* lookupSymbol(const char *name);

void displayTable();

int setArrayElement(const char *name, int index, const char *value) ;

const char *getArrayElement(const char *name, int index) ;
bool isAttributeOfStructure(const char *structurePath, const char *attributName);
desc_identif* lookupSymbolInStructure(const char *structureName, const char *attributName);


#endif // TAB_SYMBOLS_H
