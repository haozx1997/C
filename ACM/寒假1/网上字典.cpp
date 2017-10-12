#include<stdio.h>
#include<string.h>
#include<ctype.h>
char word[5004][204];
char input[204], temp[204];
int main()
{
    int i, j, T = 0, len, count, flag;
    for(i=0; i<5004; ++i)    memset(word[i], '\0', sizeof(char)*204);
    
    memset(input, '\0', sizeof(char)*204);
    memset(temp, '\0', sizeof(char)*204);
    while(fgets(input, 204, stdin) != NULL)
    {
        flag = count = 0;
        len = strlen(input);
        if(input[len-1] != '\n') input[len++] = '\n';
        for(i=0; i<len; ++i)
        {
            if(isalpha(input[i]) && isupper(input[i])) input[i] =  tolower(input[i]);
            
            if(isalpha(input[i])) 
            {
                temp[count++] = input[i];
                flag = 1;
            }
            else if(flag)
            {
                flag = 0;
                if(!T) {strcpy(word[T], temp); memset(temp, '\0', sizeof(char)*204); T++;}
                else 
                {
                    for(j=0; j<T && strcmp(word[j], temp) != 0; ++j); 
                    if(j >= T) strcpy(word[T++], temp);
                    memset(temp, '\0', sizeof(char)*204);    
                }
                count = 0;
            }
        }
        
        memset(input, '\0', sizeof(char)*204);
        memset(temp, '\0', sizeof(char)*204);
    }
    
    for(i=0; i<T-1; ++i)
    {
        flag = 1;
        for(j=0; j<T-1-i; ++j)
        if(strcmp(word[j], word[j+1]) > 0)
        {
            strcpy(temp, word[j]);
            strcpy(word[j], word[j+1]);
            strcpy(word[j+1], temp);
        }
    }
    for(i=0; i<T; ++i)
    printf("%s\n", word[i]);
    return 0;
}
