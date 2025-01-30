#include "tabSymbols.h"
#include <stdbool.h>

// Déclaration de la table des symboles globale
table_symbol symbolTable;

// Initialisation de la table des symboles
void initTable() {
    symbolTable.base = 0;
    symbolTable.sommet = 0;
}

// Insertion d'un identifiant dans la table

int insertSymbol(const char *name, int classe, int type, int line, const char *valeur,  bool isArray, int arraySize, bool isInitialized,bool isConstant,const char *parentStructure) {
    if (symbolTable.sommet >= MAX_DICO) {
        fprintf(stderr, "Error: Symbol table overflow\n");
        return -1; // Failure
    }

    desc_identif *entry = &symbolTable.tab[symbolTable.sommet++];
    entry->identif = strdup(name);
    entry->line = line;
    entry->classe = classe;
    entry->type = type;
    entry->valeur = valeur ? strdup(valeur) : NULL;
    entry->isConstant = isConstant;
    entry->isArray = isArray;
    entry->isInitialized = isInitialized;
    entry->ArraySize = arraySize;
    entry->parentStructure = parentStructure ? strdup(parentStructure) : NULL;
    
    if (isArray) {
        entry->arrayValues = malloc(arraySize * sizeof(char *));
        for (int i = 0; i < arraySize; i++) {
            entry->arrayValues[i] = NULL; // Initialize elements as NULL
        }
    } else {
        entry->arrayValues = NULL;
    }
    return symbolTable.sommet - 1; // Return index of inserted symbol
}

// Recherche d'un identifiant dans la table
desc_identif* lookupSymbol(const char *name) {
    for (int i = symbolTable.sommet - 1; i >= symbolTable.base; i--) {
        if (strcmp(symbolTable.tab[i].identif, name) == 0) {
            return &symbolTable.tab[i]; // Retourne un pointeur vers l'objet trouvé
        }
    }
    return NULL; // Retourne NULL si l'identifiant n'existe pas
}


void displayTable() {
    printf("==================================================================================================================================\n");
    printf("| %-10s | %-6s | %-7s | %-5s | %-8s | %-10s | %-8s | %-12s | %-6s |%-6s |\n",
           "Name", "Type", "Class", "Line", "Value", "Constant", "Array", "Initialized", "Size","Parent");
    printf("==================================================================================================================================\n");

    for (int i = 0; i < symbolTable.sommet; i++) {
        desc_identif *entry = &symbolTable.tab[i];

        // Display the main details of each entry
        printf("| %-10s | %-6d | %-7d | %-5d | %-8s | %-10s | %-8s | %-12s | %-6d |%-10s |\n",
       entry->identif,
       entry->type,
       entry->classe,
       entry->line,
       entry->valeur ? entry->valeur : "NULL",
       entry->isConstant ? "Yes" : "No",
       entry->isArray ? "Yes" : "No",
       entry->isInitialized ? "Yes" : "No",
       entry->isArray ? entry->ArraySize : 0,
       entry->parentStructure ? entry->parentStructure : "NULL");
               

        // If the entry is an array, display its elements below
        if (entry->isArray && entry->arrayValues != NULL) {
            printf("  Array Values:\n");
            for (int j = 0; j < entry->ArraySize; j++) {
                printf("    [%d] = %s\n", j, entry->arrayValues[j] ? entry->arrayValues[j] : "NULL");
            }
        }
    }
    printf("===========================================================================================\n");
}


// methods to manipulate array elements

int setArrayElement(const char *name, int index, const char *value) {
    desc_identif *symbol = lookupSymbol(name);
    if (!symbol || !symbol->isArray) {
        fprintf(stderr, "Error: Symbol '%s' is not an array\n", name);
        return -1; // Failure
    }
    if (index < 0 || index >= symbol->ArraySize) {
        fprintf(stderr, "Error: Array index out of bounds\n");
        return -1; // Failure
    }
    if (symbol->arrayValues[index]) {
        free(symbol->arrayValues[index]); // Free old value if exists
    }
    symbol->arrayValues[index] = strdup(value); // Set new value
    return 0; // Success
}

const char *getArrayElement(const char *name, int index) {
    desc_identif *symbol = lookupSymbol(name);
    if (!symbol || !symbol->isArray) {
        fprintf(stderr, "Error: Symbol '%s' is not an array\n", name);
        return NULL; // Failure
    }
    if (index < 0 || index >= symbol->ArraySize) {
        fprintf(stderr, "Error: Array index out of bounds\n");
        return NULL; // Failure
    }
    return symbol->arrayValues[index];
}

bool isAttributeOfStructure(const char *structurePath, const char *attributName) {
    for (int i = 0; i < symbolTable.sommet; i++) {
        if (symbolTable.tab[i].classe == C_CHAMP &&
            strcmp(symbolTable.tab[i].identif, attributName) == 0 &&
            strcmp(symbolTable.tab[i].parentStructure, structurePath) == 0) {
            return true;
        }
    }
    return false;
}


desc_identif* lookupSymbolInStructure(const char *structureName, const char *attributName) {
   desc_identif* structure =lookupSymbol(structureName);
   desc_identif* attribut =lookupSymbol(attributName);
  
  if (strcmp(structure->parentStructure, attribut->parentStructure) == 0) {
    return attribut;
} else {
    return NULL;
}

}
