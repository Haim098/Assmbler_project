#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE* pre_assmbler(FILE* input){
    char lint[80];//TODO: define a constant
    char *line_p;
    FILE* f_pre_ass= fopen("pre_assmbler.am", "w");
      if (f_pre_ass == NULL)
        {
            printf("error: cannot create pre_assmbler file\n");
            exit(1);
        }
    while(fgets(lint, 80, input) != NULL)
    {
        line_p = lint;
        while(isspace(*line_p)){//TODO chack later this function is valid
            line_p++;
        }
        if(*line_p == '\0' || *line_p == ';'){
            continue;
        }    
        fprintf(f_pre_ass, "%s", line_p);
        printf("%s",line_p);
    }
    
    fclose(f_pre_ass);
    return f_pre_ass;
   
        
}
