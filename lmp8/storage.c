#include "storage.h"  

typedef struct e{
    int poczatekWywolania;
    int koniecWywolania;
    struct e * next;
} *wywolania;

typedef struct d{
    char* nazwa;
    int poczatekDeklaracji;
    int koniecDeklaracji;
    int liniaPrototyp;
    wywolania uzycia;
    struct d * next;
} *funkcje;

// funkcjie storage = NULL;

void store_add_def(char * fun_name, int lineNumber, char *fileName){
    // if(storage->nazwa != )

    
}
void store_add_proto(char * fun_name, int lineNumber, char *fileName){



}
void store_add_call(char * fun_name, int lineNumber, char *fileName){



}