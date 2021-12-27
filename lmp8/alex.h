#ifndef _ALEX_H_IS_INCLUDED_
#define _ALEX_H_IS_INCLUDED_

#include <stdio.h>



typedef enum { ERROR, OTHER, EOFILE, OPEBRA, CLOBRA, IDENT, OPEPAR, CLOPAR } lexem_t;

void    alex_init4file( FILE * );  // zacznij czytać nowy plik
lexem_t alex_nextLexem( void );    // daj kolejny leksem w czytanym pliku
char *  alex_ident( void );        // daj ostatni identyfikator
int     alex_getLN( void );              // daj aktualny nr linii

#endif

