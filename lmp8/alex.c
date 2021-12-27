#include "alex.h"

#include <ctype.h>
#include <string.h>

static int  ln= 0;
static char ident[256];
static FILE *ci= NULL;
static char* keywords[] = {"if","while","else","strcmp","strcpy","qsort","fopen","printf","case","switch","scanf","fscanf","fgetc","getc","isalpha","for","isalnum"};

void    alex_init4file( FILE *in ) {
  ln= 0;        // (.Y.)
  ci= in;
}

int isKeyword(char *inword){
  int result;
  int length = sizeof(keywords)/sizeof(keywords[0]);
  for(int i = 0; i < length; i++){
    if( strcmp(inword,keywords[i]) == 0){
      result = 1;
      break;
    }
    else
      result = 0;
  }
  return result;
}

lexem_t alex_nextLexem( void ) {
  int c;
  while( (c= fgetc(ci)) != EOF ) {
    if( isspace( c ) )
                        continue;
    else if( c == '\n' )
                        ln++;
    else if( c == '(' )
                        return OPEPAR;
    else if( c == ')' )
                        return CLOPAR;
    else if( c == '{' )
                        return OPEBRA;
    else if( c == '}' )
                        return CLOBRA;
    else if( isalpha( c ) ) {
      int i= 1;
      ident[0] = c;
      while( isalnum(c = fgetc(ci)) || c == '_')
                                ident[i++] = c;
                        ident[i] = '\0';
                        ungetc(c, ci);
      return isKeyword(ident) ? OTHER : IDENT;
                } 
    else if( c == '"' ) {
      /* Uwaga: tu trzeba jeszcze poprawic obsluge nowej linii w trakcie napisu
         i \\ w napisie 
      */
      int cp = c;
                        while( (c= fgetc(ci)) != EOF && c != '"') {
                                if( c == '\n' )
                                  ln++;
                                cp = c;
      }
      return c==EOF ? EOFILE : OTHER; 
    } 
    // else if( c == '/' ) {
    //   /* moze byc komentarz */
    //             } if( isdigit( c ) || c == '.' ) {
    //   /* liczba */
    //             } else {
    //   return OTHER;
    //             }
        }       
  return EOFILE;
}



char *  alex_ident( void ) {
   return ident;
}

int     alex_getLN() {
        return ln;
}

