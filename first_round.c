#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//char actions[]={mov,cmp, add, sub, not,clr, lea, inc, dec, jmp, bne, red, prn, jst, hlt};
enum opcode {mov,cmp, add, sub, not,clr, lea, inc, dec, jmp, bne, red,prn, jst, hlt};
enum reg {R0, R1, R2, R3, R4, R5, R6, R7};
int is_action(char *definiton);
int lllegal_directive(char *position_l, int n_lines); 
int main()
{
   char *line="string \"     ";
    int n_lines=1;
    int i=lllegal_directive(line ,n_lines);
    printf("\n%d\n",i);
    return 1; 
}

/*int is_error(char *line, int n_lines)
{
    int flag_there_is_error=0;
    char *temp_line;
    temp_line=line;
    strchr(temp_line,':');
    if (temp_line!=NULL)
    {
     if(temp_line-1==' ')
     {
        printf("error: Incorrect label definition");
        flag_there_is_error=1;
     }
        line=temp_line+1;
        while (isspace(*line))
        {
              
            line++;
        }
    }
    if (is_action(strtok(line,' '))==1)
    {
        if(lllegal_action(strtok(line,' '),line+(strlen(strtok(line,' '))))==1,n_lines)
            printf("error: lllegal operands in opcode");
            flag_there_is_error=1;
    }

    if (strncpy(line,'.',1)==0)
    {
        flag_there_is_error=llegal_directive(line+1, n_lines);
  
    }
    

}

int is_action(char *position_l)
{
    int i=0;
    while (i<15)
    {
        if (strcmp(position_l,actions[i])==0)
        {
            return 1;
        }
        i++;
    }
    return 0;
}*/


int lllegal_directive(char *position_l, int n_lines)
{
    int find_error=0;
     if (strncmp(position_l,"data",4)==0)
        {
             int flag_comma=1;
            if(*(position_l+4)!=' ')
                {
                    printf("\nerror in line %d: The directive data must be followed by a space", n_lines);
                    find_error=1;
                }
         
                position_l+=4;
               if (*position_l=='\0')
               {
                printf("\nError in line %d: The directive data must be followed by a number", n_lines);
                return find_error=1;
               }
                 
        while (*position_l!='\0')
        {
             while (isspace(*position_l))
        {
              
            position_l++;
        }
            if(flag_comma==1 && *position_l==','|| *position_l==',' && *(position_l+1)=='\0')
            {
            printf("\nerror in line %d Incorrect use of the comma character in the data directive", n_lines);
            find_error=1;
            position_l++;
            continue;
            }
            else if (flag_comma==0 && *position_l==',' )
            {
                flag_comma=1;
                position_l++;
                continue;
            }
            
            if (*position_l=='+' && *(position_l+1)!='\0' || *position_l=='-'&& *(position_l+1)!='\0')
            {
                position_l++;
                continue;
            }
            if (!isdigit(*position_l))
            {
                printf("\nError in line %d: The directive data can only contain digits", n_lines);
                find_error=1;
                position_l++;
                flag_comma=0;
                continue;
            }
            
            position_l++;
            flag_comma=0;
        }
        }
        if (strncmp(position_l,"string",6)==0)
        {
            if(*(position_l+6)!=' ')
                {
                    printf("\nerror in line %d: The directive string must be followed by a space", n_lines);
                    find_error=1;
                }
            position_l+=6;
            while (isspace(*position_l))
        {
              
            position_l++;
        }
         if (*position_l=='\0')
            {
                printf("\nError in line %d: The directive string must be followed by a string in quotation marks", n_lines);
                return find_error=1;
            }
            if (*position_l!='"')
            {
                printf("\nError in line %d: The directive string must be followed by a string in quotation marks", n_lines);
                find_error=1;
            }
            position_l++;
           
            
            while (*position_l!='"')
            {
                if (*position_l=='\0')
                {
                    printf("\nError in line %d: No end-of-string quotation marks found", n_lines);
                    find_error=1;
                    break;
                }
                position_l++;
            }
        }
        if (strncmp(position_l,"entry",5)==0)
        {  
          if(*(position_l+5)!=' ')
                {
                    printf("\nerror in line %d: The directive entry must be followed by a space", n_lines);
                    find_error=1;
                }
            position_l+=5;
            while (isspace(*position_l))
            {
            position_l++;
            }
            if(*position_l=='\0')
            {
                printf("\nError in line %d: The directive entry must be followed by a label", n_lines);
                find_error=1;
            }
        }

                return find_error;
    }
