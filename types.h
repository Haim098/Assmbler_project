
#ifndef types_h
#define types_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];  // TODO: replace arry into maloc
    char value[100]; // TODO: replace arry into maloc
} macros;
macros macro2[100]; // TODO: replace arry into maloc

typedef struct
{
    char *name;  // TODO: replace arry into maloc
    char *value; // TODO: replace arry into maloc
} macros2;
typedef struct
{
    macros2 *m;
}macro_tabel; // TODO: replace arry into maloc

macros2 *create_macros2(const char *name, const char *value) {
    macros2 *m = malloc(sizeof(macros2));
    if (m == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    m->name = strdup(name);
    m->value = strdup(value);
    return m;
}

void free_macros2(macros2 *m) {
    free(m->name);
    free(m->value);
    free(m);
}




#endif // types_h