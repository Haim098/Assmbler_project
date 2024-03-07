#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
//TODO: to chack if i need to ignore spaces between words
enum //TODO: to put it in a header file
{
    true = 1,
    false = 0
};

FILE *pre_assmbler(FILE *input)
{

    char lint[80];      // TODO: define a constant
    char mcr[100][100]; // TODO: fix the number in array 3
    char *line_p;
    int flag = false;
    int i = 0;
    char ch;
    const int MAX_MACROS = 100;
     size_t size_of_m; // Define constant for the maximum number of macros
macro_tabel *tabel = malloc(sizeof(macro_tabel) + 1);
if (tabel == NULL)
{
    printf("error: cannot allocate memory for macro table\n");
    exit(1);
}
    
   // char size_of_m=sizeof(tabel[i].m->value);
    FILE *f_pre_ass = fopen("pre_assmbler.am", "w");
    if (f_pre_ass == NULL)
    {
        printf("error: cannot create pre_assmbler file\n");
        exit(1);
    }
    while (fgets(lint, 80, input) != NULL)
    {               
        int j = 0;
        line_p = lint;
         while (isspace(*line_p))
        {
              
            line_p++;
        }
        if (*line_p == '\0' || *line_p == ';')
        {
              
            continue;
        }
        while (j < i) // Adjust loop condition to iterate over the correct range of macro elements
        {
            if (strncmp(tabel[j].m->name,line_p,strlen(tabel[j].m->name)) == 0)
            {   
                line_p=(line_p,tabel[j].m->name,tabel[j].m->value);
                break;
            }
            j++;
        }

        if (flag == true)
        {
            if (strncmp(line_p, "endmcr", 6) == 0)
            {
                flag = false;
                i++;
                continue;
            }
            if (tabel[i].m->value == NULL)
            {
                tabel[i].m->value = (char*)malloc(strlen(line_p) + 1);
                if (tabel[i].m->value == NULL)
                {
                    printf("error: cannot allocate memory for macro value\n");
                    exit(1);
                }
            }
            else
            {
                size_t size = strlen(tabel[i].m->value);
                char* temp = realloc(tabel[i].m->value, size + strlen(line_p) + 1);
                if (temp == NULL)
                {
                    printf("error: cannot reallocate memory for macro value\n");
                    exit(1);
                }
                tabel[i].m->value = temp;
            }
            strcat(tabel[i].m->value, line_p);


            
            continue;
        }
       
        if (strncmp(line_p, "mcr ", 4) == 0)        
        {
            flag = true;
            line_p += 4;//TODO check if more spaces
            macro_tabel *temp = realloc(tabel, (sizeof(macro_tabel) * (i + 1)) + 1);
            if (temp==NULL)
            {
                printf("error: cannot create macro2\n");
                exit(1);
            }
            tabel=temp;
        
            tabel[i].m=malloc(sizeof(macros2));
            if (tabel[i].m==NULL)
            {
                printf("error: cannot create macro2\n");
                exit(1);
            }
            tabel[i].m->name = strdup(line_p);
            tabel[i].m->value = NULL;
            continue;
        }
        fprintf(f_pre_ass, "%s", line_p);
    
    }
    

fclose(f_pre_ass);

f_pre_ass = fopen("pre_assmbler.am", "r");
if (f_pre_ass == NULL)
{
    printf("error: cannot open pre_assmbler file\n");
    exit(1);
}
i--;
   while (i>=0)
{
    free_macros2(tabel[i].m);
    i--;  
}

    while ((ch=fgetc(f_pre_ass))!=EOF)//TODO to delte this print
    {
       
        printf("%c",ch);
    }
    fclose(f_pre_ass);

    return f_pre_ass;
}

