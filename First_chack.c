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
    const int MAX_MACROS = 100; // Define constant for the maximum number of macros

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
            if (strncmp(macro[j].name, line_p, strlen(macro[j].name)) == 0)
            {
                                
                line_p = macro[j].value;
                break;
            }
            j++;
        }

        if (flag==true)
        {
           
          
            if (strncmp(line_p, "endmcr", 6) == 0)
            {
                flag = false;
                i++;
                continue;
            }
            strcat(macro[i].value, line_p);
            continue;
        }
        if (*line_p == 'm' && *(line_p + 1) == 'c' && *(line_p + 2) == 'r')
        {
            flag = true;
            line_p += 4;
            strcpy(macro[i].name, line_p);
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
    while ((ch=fgetc(f_pre_ass))!=EOF)//TODO to delte this print
    {
       
        printf("%c",ch);
    }
    fclose(f_pre_ass);

    return f_pre_ass;
}
