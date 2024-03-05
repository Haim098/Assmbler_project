#ifndef Fuction_h
#define Fuction_h

#include <string.h>
#include <stdio.h>
void paste(char *i, char *j);
int main()
{
    char *i;
    char *j;
    i="hello";
    j=" world";
    paste(i,j);
    printf("%s",i);
    return 0;
}

void paste(char *i, char *j)
{
   while(*j != '\0' ||*j!= '\n')
    {
        if (*j==' ' && *(j+1)==' ')
        {
            j++;
            continue;
        }
    *i = *j;
    i++;
    j++;
}
}


#endif