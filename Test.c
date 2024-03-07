#include <stdio.h>
FILE* pre_assmbler(FILE*);
int main(int argc, char *argv[]) 
{
    int i=1;
    if(argc < 2) 
    {
        printf("error: no input file\n");
        return 1;
    }
    while (i < argc)
    {
        printf("%d\n",i);
        FILE *new_file = fopen(argv[i], "r");
        if(new_file == NULL) 
        {
            printf("error: file not found\n");
            return 1;
        }
        pre_assmbler(new_file);
        i++;
        fclose(new_file);
    }
    return 0;
}
