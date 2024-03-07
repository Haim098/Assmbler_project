
#ifndef types_h
#define types_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    char *name;  // TODO: replace arry into maloc
    char *value; // TODO: replace arry into maloc
} macros2;
typedef struct
{
    macros2 *m;
}macro_tabel; // TODO: replace arry into maloc


void free_macros2(macros2 *m) {
    free(m->name);
    free(m->value);
    free(m);
}

#endif // types_h